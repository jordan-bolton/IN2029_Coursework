#ifndef ROBOT_H
#define ROBOT_H

// includes to be used in the function declarations
#include <string>

// the robot class
class robot {
	// the robot name stored in a string and the variables used to hold the robot's position and distance travelled
	std::string n;
	int _travelled;
	int _originX = 0;
	int _originY = 0;
	int _x;
	int _y;
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
