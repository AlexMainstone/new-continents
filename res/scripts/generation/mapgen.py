import random
import time
import noise

# Define map size to a default value
if 'MAP_SIZE' not in locals(): MAP_SIZE = 16*6
if 'SEED' not in locals(): SEED = time.time()

# Define the size of the world, this should be consistent with the world size set in C++
print("Map Size: " + str(MAP_SIZE) + "x" + str(MAP_SIZE))

# Create word data array, this is fetched by C++
world_map = [[0]*MAP_SIZE for _ in range(MAP_SIZE)]

# Create Object list, this is also fetched by C++
object_list = []

# Generate map
print("Generating map...")

# Generate Random Transform & Scale
random.seed(SEED)
tx = random.randint(-10000, 10000)
ty = random.randint(-10000, 10000)
scale = random.random() % 0.1 + 0.15

print("tx: {}, ty: {} \nscale: {}".format(tx, ty, scale))

for x in range(MAP_SIZE):
    for y in range(MAP_SIZE):
        n = noise.pnoise2(x*scale+tx, y*scale+ty)
        if n > 0:
            if random.randint(0, 3):
                world_map[x][y] = 1
            else:
                world_map[x][y] = 2

        else:
            world_map[x][y] = 4
            if random.randint(0, 1):
                object_list.append([0, x, y])

print("Generated {} objects".format(len(object_list)))
print("Done!")