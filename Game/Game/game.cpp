#include "game.h"
#include "robot.h"
#include <map>
#include <string>
#include <algorithm>
// for testing
#include <iostream>

using namespace std;

// a map holding all the robots created
map<string, robot> robots;

// default constructor
game::game() {};

// TESTING FUNCTIONS
void game::add_robot(string name) {
	//robot temp(name);
	//robots.emplace(make_pair(name, temp));

	// manual
	robot robot1("robot1");
	robot robot2("robot2");
	robots.emplace(name, robot1);
	robots.emplace(name, robot2);
}

void game::print_all() const {
	for (auto elem : robots)
	{
		cout << elem.first << " " << elem.second.north() << " " << elem.second.travelled() << "\n";
	}
	
}


int game::num_robots() const {
	return robots.size();
}

// dir = direction to move
void game::move(const string &name, int dir) {
	if (robots.count(name) >= 1) {
		// move north
		if (dir == 0) {
			robots.at(name).move_north();
		}
		// move east
		else if (dir == 1) {
			robots.at(name).move_east();
		}
		// move south
		else if (dir == 2) {
			robots.at(name).move_south();
		}
		// move west
		else if (dir == 3) {
			robots.at(name).move_west();
		}
	}
	// robot doesn't exist, so create robot and add to the map using the name as the key
	else {
		robot newRobot(name);
		robots.emplace(name, newRobot);
		// move the new robot
		move(name, dir);
	}


}

int game::num_close() const {
	return 0;
}