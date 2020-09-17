#pragma once

#include <vector>
#include <map>
#include <queue>
#include <SFML/Graphics.hpp>
#include "World/Map.hpp"
#include <utility>

typedef std::pair<int, int> Coords;

struct Node {
    float value = -1;
};

inline float calc_heuristic(Coords p1, Coords p2) {
    return std::abs(p1.first - p2.first) + std::abs(p1.second - p2.second);
}

class Pathfinding {
    public:
        static std::queue<sf::Vector2i> pathfind_astar(sf::Vector2i s, sf::Vector2i e, Map *map);
    private:
        static std::vector<Coords> calc_neighbors(Coords pos, Map *map);
        static std::queue<sf::Vector2i> generate_path(std::map<Coords, Coords> cameFrom, Coords start,  Coords current);
};