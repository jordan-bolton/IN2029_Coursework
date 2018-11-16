#include "robot.h"
#include "game.h"
#include <iostream>

using namespace std;

int main() {

	/*
	robot r  ("Test Robot");

	
	// move north +2
	r.move_north();
	r.move_north();
	// move south -3;
	r.move_south();
	r.move_south();
	r.move_south();
	// should return -1

	// move east +3
	r.move_east();
	r.move_east();
	r.move_east();
	// move west -1
	r.move_west();
	// should return 2

	cout << "north value distance from origin (0,0) " << r.north() << '\n';
	cout << "east value distance from origin (0,0) " << r.east() << '\n';
	// should return 9
	cout << "total travelled distance: " << r.travelled() << '\n';
	cout << "distance back to origin: " << distance(r) << '\n';
	cout << "Robot name: " << r.name() << '\n';
	*/

	/*
	robot r("Robbie");
	r.move_north();
	r.move_east();
	r.move_south();
	r.move_south();
	cout << r.north() << "N, " << r.east() << "E, dist = " << distance(r) << '\n';
	*/

	// teating for game.cpp

	game g;
	g.add_robot("robot1");

	cout << "Number of robots before move: " << g.num_robots() << '\n';

	g.move("robot1", 0); // move north
	g.move("robot1", 2); // move south
	
	// move a robot that doesn't exist yet
	g.add_robot("robot2");
	g.move("robot2", 0);

	cout << "Number of robots after move: " << g.num_robots() << '\n';

	g.print_all();

	return 0;
}