#ifndef GAME_H
#define GAME_H

// includes to be used in function declarations
#include "robot.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <map>

class game {
public:
	int num_robots() const;
	void move(const std::string &name, int dir);
	int num_close() const;
	int max_distance() const;
	std::string furthest() const;
	std::vector<robot> robots_by_travelled() const;
};


#endif // !GAME_H
