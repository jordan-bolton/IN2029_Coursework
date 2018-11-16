#include "robot.h"
#include <string>
#include <cstdlib>
using namespace std;


// constructor for a robot that initialises the values of how far the robot has travelled, and it's current x and y position
robot::robot(const string &n) : n(n) {
	robot::_travelled = 0;
	robot::_x = robot::_originX;
	robot::_y = robot::_originY;
};


void robot::move_north() {
	_y += 1;
	++_travelled;
}

void robot::move_east() {
	_x += 1;
	++_travelled;
}

void robot::move_south() {
	_y -= 1;
	++_travelled;
}

void robot::move_west() {
	_x -= 1;
	++_travelled;
}

// returns how far north or south (represented by a negative number) the robot has moved
int robot::north() const {
	return _y - _originY;
}

// returns how far east or west (represented by a negative number) the robot has moved
int robot::east() const {
	return _x - _originX;
}

// returns the total number of times the robot has moved
int robot::travelled() const{
	return _travelled;
}

// returns how far the robot is from the origin
int distance(const robot &r) {
	return abs(r.north()) + abs(r.east());
}


