#include "World/MapGenerator.hpp"
#include <cstdlib>

#include "Tasks/DestroyTask.hpp"

Map *MapGenerator::generate(TileSet *tileset, std::uint32_t seed) {
    int chunks = 6;

    if(seed == 0) {
        seed = time(0);
    }
    siv::PerlinNoise noise(seed);
    Map *map = new Map(chunks, chunks, tileset);

    for(int x = 0; x < CHUNK_WIDTH * chunks; x++) {
        for(int y = 0; y < CHUNK_HEIGHT * chunks; y++) {
            double n = noise.noise2D((x+8)/8.0, (y+8)/8.0);
            if(n > 0) {
                int n = rand() % 20;
                if(n == 0) {
                    map->setTile(x, y, tileset->getTile(2), false);
                // } else if(n < 5) {
                    // map->setTile(x, y, tileset->getTile(3), false);
                } else {
                    map->setTile(x, y, tileset->getTile(1), false);
                }
            } else {
                map->setTile(x, y, tileset->getTile(4), false);
                if(rand() % 2) {
                    Object *o = new Object(tileset->getTile(5), sf::Vector2i(x, y));
                    map->addObject(o);
                } //else {
                    // map->setTile(x, y, tileset->getTile(5), false);
                //}
            }
        }
    }

    map->updateChunks();
    return map;
}

Map *MapGenerator::generate_from_py(TileSet *tileset) {
    Map *out_map = new Map(6, 6, tileset);

    Py_Initialize();

    char filename[] = "../res/scripts/generation/mapgen.py";
    FILE *fp;
    fp = _Py_fopen(filename, "r");

    // Get Main thread
    PyObject *main = PyImport_AddModule("__main__");

    // Set world size
    PyObject_SetAttrString(main, "MAP_SIZE", PyLong_FromLong(CHUNK_WIDTH*6));

    PyRun_SimpleFile(fp, filename);
    PyObject *mapdata = PyObject_GetAttrString(main,"world_map");

    for(int x = 0; x < CHUNK_WIDTH*6; x++) {
        PyObject *mapcol = PyList_GetItem(mapdata, x);
        for(int y = 0; y < CHUNK_HEIGHT*6; y++) {
            PyObject *mapitem = PyList_GetItem(mapcol, y);;
            int f = PyLong_AsLong(mapitem);
            out_map->setTile(x, y, tileset->getTile(f), false);
        }
    }
    Py_DECREF(mapdata);

    PyObject *objectdata = PyObject_GetAttrString(main, "object_list");
    for(int i = 0; i < PyList_Size(objectdata); i++) {
        PyObject *obj = PyList_GetItem(objectdata, i);
        PyObject *obj_x = PyList_GetItem(obj, 1);
        PyObject *obj_y = PyList_GetItem(obj, 2);
        sf::Vector2i pos = sf::Vector2i(PyLong_AsLong(obj_x), PyLong_AsLong(obj_y));
        out_map->addObject(new Object(tileset->getTile(5), pos));
    }

    Py_Finalize();

    out_map->updateChunks();
    return out_map;
}