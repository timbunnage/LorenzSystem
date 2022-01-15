#include <iostream>
#include "Particle.h"

// constructor, intialises data
Particle::Particle(
	Position initialPos
) : initialPos(initialPos), currPos(initialPos)
{
}


void Particle::UpdatePos() {
	currPos.x += 1.0e-4 * lorenzX(currPos.x, currPos.y, currPos.z);
	currPos.y += 1.0e-4 * lorenzY(currPos.x, currPos.y, currPos.z);
	currPos.z += 1.0e-4 * lorenzZ(currPos.x, currPos.y, currPos.z);
}

void Particle::draw() {
	std::cout << currPos.x << ", " << currPos.y << ", " << currPos.z << std::endl;
	// std::cout << lorenzX(currPos.x, currPos.y, currPos.z) << std::endl;
	// std::cout << lorenzY(currPos.x, currPos.y, currPos.z) << std::endl;
	// std::cout << lorenzZ(currPos.x, currPos.y, currPos.z) << std::endl;


}

double Particle::lorenzX(double x, double y, double z) {
	return 10.0 * (y - x);
}
double Particle::lorenzY(double x, double y, double z) {
	return x * (28.0 - z) - y;
}
double Particle::lorenzZ(double x, double y, double z) {
	return x * y;
}