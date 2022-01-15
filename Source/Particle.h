#pragma once
#include <functional>

// 3D position coordinates
struct Position {
	double x, y, z;
};

class Particle {
private:
	// intialise position of the particle (incase we need it)
	Position initialPos;

	// current position
	Position currPos;

	double lorenzX(double x, double y, double z);
	double lorenzY(double x, double y, double z);
	double lorenzZ(double x, double y, double z);

public:
	// constructor
	Particle( Position initialPos );

	// updates the current position based on the functions
	void UpdatePos();

	// draws the particle on the screen
	void draw();

};