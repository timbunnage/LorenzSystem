#pragma once
#include <functional>

// 3D position coordinates
struct Position {
	long x, y, z;
};

class Particle {
private:
	// intialise position of the particle (incase we need it)
	Position initialPos;

	// d/dt functions
	std::function<double(double)> dx;
	std::function<double(double)> dy;
	std::function<double(double)> dz;

	// current position
	Position currPos;

public:
	// constructor
	Particle(
		Position initialPos,
		std::function<double(double)> dx,
		std::function<double(double)> dy,
		std::function<double(double)> dz);

	// updates the current position based on the functions
	void UpdatePos();

	// draws the particle on the screen
	void draw();
};