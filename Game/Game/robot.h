#ifndef ROBOT_H
#define ROBOT_H

// includes to be used in the function declarations
#include <string>


class robot {
	// the robot name stored in a string
	std::string n;

// public methods
public:
	explicit robot(const std::string &n);
	void move_north();
	void move_east();
	void move_south();
	void move_west();
	const std::string &name() const { return n; } // returns the name of the robot, defined directly in the header
	int north() const;
	int east() const;
	int travelled() const;
};

// external functions
int distance(const robot &r); // const as doesn't change any of the object's data


#endif // !ROBOT_H
