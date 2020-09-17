#include "Maths/Pathfinding.hpp"

std::vector<Coords> Pathfinding::calc_neighbors(Coords pos, Map *map) {
    std::vector<Coords> out;
    for(int dx = -1; dx <= 1; dx++) {
        for(int dy = -1; dy <= 1; dy++) {
            int fx = pos.first+dx;
            int fy = pos.second+dy;
            if(fx < 0 || fx > CHUNK_WIDTH*6 || fy < 0 || fy > CHUNK_HEIGHT*6) { continue; }
            if(dx == 0 && dy == 0) { continue; }
            if(map->getObject(fx, fy) != nullptr) { continue; }
            if(map->getTile(fx, fy)->collision) { continue; }
            out.push_back(std::make_pair(fx, fy));
        }
    }
    return out;
}

std::queue<sf::Vector2i> Pathfinding::generate_path(std::map<Coords, Coords> cameFrom, Coords start,  Coords current) {
    std::queue<sf::Vector2i> out;
    while(!(current.first == start.first && current.second == start.second)) {
        Coords from = cameFrom[current];
        out.push(sf::Vector2i(from.first - current.first, from.second - current.second));
        current = from;
    }

    return out;

}

std::queue<sf::Vector2i> Pathfinding::pathfind_astar(sf::Vector2i s, sf::Vector2i e, Map *map) {
    Coords start = std::make_pair(s.x, s.y);
    Coords end = std::make_pair(e.x, e.y);
    std::vector<Coords> openset;
    openset.push_back(start);

    std::map<Coords, Coords> cameFrom;
    
    std::map<Coords, Node> gScore;
    gScore[start].value = 0;

    std::map<Coords, Node> fScore;
    fScore[start].value = calc_heuristic(start, end);

    while(!openset.empty()) {
        Coords current = openset[0];
        std::vector<Coords >::iterator final_pos = openset.begin();
        for(auto it = openset.begin(); it < openset.end(); it++) {
            if(fScore[*it].value < fScore[current].value || fScore[current].value == -1) {
                current = *it;
                final_pos = it;
            }
        }
        openset.erase(final_pos);

        if(current.first == end.first && current.second == end.second) {
            return generate_path(cameFrom, start, current);
        }

        for(Coords n : calc_neighbors(current, map)) {
            float tenative_gscore = gScore[current].value + 1;
            if(tenative_gscore < gScore[n].value || gScore[n].value == -1) {
                cameFrom[n] = current;
                gScore[n].value = tenative_gscore;
                fScore[n].value = gScore[n].value + calc_heuristic(n, end);
                
                bool inset = false;
                for(auto o : openset) {
                    if(n == o) {
                        inset = true;
                        break;
                    }
                }

                if(!inset) {
                    openset.push_back(n);
                }
            }
        }

    }

    return std::queue<sf::Vector2i>();
}