#include "game.h"
#include "robot.h"
#include <map>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

// a map holding all the robots created
map<const string, robot> robots;

// default constructor with no paramaters
game::game() {};

// returns the total number of robots in the map
int game::num_robots() const {
	return robots.size();
}

// dir = direction to move
void game::move(const string &name, int dir) {
	// if the robot with the specified name exists in the map
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
		robots.emplace(name, newRobot); // store the new robot in the map using the name as the key and the robot object as the value
		// move the new robot after it has been created
		move(name, dir);
	}


}
// returns the number of robots within a 10 space radius of the origin
int game::num_close() const {
	int close_count = 0;
	for (auto elem : robots) {
		if (abs(elem.second.east()) <= 10) {
			if (abs(elem.second.north()) <= 10) {
				++close_count;
			}
		}
	}
	return close_count;
}

// returns the furthest distance a robot is from the origin
int game::max_distance() const {
	int maximum_distance = 0;
	for (auto elem : robots) {
		if (distance(elem.second) > maximum_distance) {
			maximum_distance = distance(elem.second);
		}
	}
	return maximum_distance;
}

// returns the name of the robot that is furthest from the origin
string game::furthest() const {
	int maximum_distance = 0;
	string furthest_robot;
	for (auto elem : robots) {
		if (distance(elem.second) > maximum_distance) {
			maximum_distance = distance(elem.second);
			furthest_robot = elem.second.name();
		}
	}
	return furthest_robot;
}

// sorts the robots in the game in to order of lowest to highest spaces moved
vector<robot> game::robots_by_travelled() const{
	// a new vector to store the sorted robots
	vector<robot> sorted_robots;

	// add each robot in the map to a new vector of robots
	for (auto elem : robots) {
		sorted_robots.push_back(elem.second);
	}

	// sort the robots in to ascending distance travelled by comparing each of their travelled distances
	sort(sorted_robots.begin(), sorted_robots.end(), [](robot& lhs, robot& rhs) {
		return lhs.travelled() < rhs.travelled();
	});

	return sorted_robots;	
}