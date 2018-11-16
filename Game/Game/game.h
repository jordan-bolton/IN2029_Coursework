#ifndef GAME_H
#define GAME_H

// includes to be used in function declarations
#include "robot.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <map>

// the game class
class game {
public:
	explicit game();
	// for testing
	void add_robot(std::string name);
	void print_all() const;

	int num_robots() const;
	void move(const std::string &name, int dir);
	int num_close() const;
	int max_distance() const;
	std::string furthest() const;
	std::vector<robot> robots_by_travelled() const;
};


#endif // !GAME_H
