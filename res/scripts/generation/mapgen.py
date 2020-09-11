import random
import time
import noise

# Define the size of the world, this should be consistent with the world size set in C++
world_size = 16*6
print("World Size: " + str(world_size) + "x" + str(world_size))

# Create word data array, this is fetched by C++
world_map = [[0]*world_size for _ in range(world_size)]

# Create Object list, this is also fetched by C++
object_list = []

# Generate map
print("Generating map...")

# Generate Random Transform & Scale
random.seed(time.time())
tx = random.randint(-10000, 10000)
ty = random.randint(-10000, 10000)
scale = random.random() % 0.1 + 0.15

print("tx: {}, ty: {} \nscale: {}".format(tx, ty, scale))

for x in range(world_size):
    for y in range(world_size):
        n = noise.pnoise2(x*scale+tx, y*scale+ty)
        if n > 0:
            if random.randint(0, 4):
                world_map[x][y] = 1
            else:
                world_map[x][y] = 2

        else:
            world_map[x][y] = 4
            if random.randint(0, 1):
                object_list.append([0, x, y])

print("Generated {} objects".format(len(object_list)))
print("Done!")