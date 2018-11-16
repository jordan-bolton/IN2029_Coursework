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

	g.move("robot1", 2);
	g.move("robot1", 2);
	g.move("robot1", 3);
	for (int i = 0; i < 5; ++i) {
		g.move("robot1", 0);
	}

	
	// move a robot that doesn't exist yet
	g.move("robot2", 2);
	for (int i = 0; i < 10; ++i) {
		g.move("robot2", 2);
	}



	g.add_robot("robot3");
	g.move("robot3", 3);
	g.move("robot3", 3);
	
	g.move("robot4", 0);
	g.move("robot4", 1);
	g.move("robot4", 2);
	g.move("robot4", 3);
	g.move("robot4", 0);
	g.move("robot4", 0);
	g.move("robot4", 0);

	g.add_robot("robot5");


	cout << "Number of robots after move: " << g.num_robots() << '\n';

	g.print_all();

	cout << "num close: " << g.num_close() << '\n';
	cout << "maximum distance: " << g.max_distance() << '\n';
	cout << "furthest robot name: " << g.furthest() << '\n';

	vector<robot> sortedRobots = g.robots_by_travelled();

	
	for (auto i = sortedRobots.begin(); i != sortedRobots.end(); ++i) {
		cout << i->name() << '\n';
	}
	


	return 0;
}