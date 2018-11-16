#include "robot.h"
#include <string>
#include <cstdlib>
// for testing
#include <iostream>
using namespace std;


// origin for each robot, which is 0,0
const int originX = 0;
const int originY = 0;

// robot positoin
int x = originX;
int y = originY;

// counter for travelled()
int travelledCounter = 0;

// constructor
robot::robot(const string &n) : n(n) {
};


void robot::move_north() {
	y += 1;
	++travelledCounter;
	// for testing
	cout << name() << " " << "moved north \n";
}

void robot::move_east() {
	x += 1;
	++travelledCounter;
	// for testing
	cout << name() << " " << "moved east \n";
}

void robot::move_south() {
	y -= 1;
	++travelledCounter;
	// for testing
	cout << name() << " " << "moved south \n";
}

void robot::move_west() {
	x -= 1;
	++travelledCounter;
	// for testing
	cout << name() << " " << "moved west \n";
}

int robot::north() const {
	return y - originY;
}

int robot::east() const {
	return x - originX;
}

int robot::travelled() const {
	return travelledCounter;
}

int distance(const robot &r) {
	return abs(r.north()) + abs(r.east());
}


