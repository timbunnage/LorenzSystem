#include <iostream>
#include "Particle.h"

// constructor, intialises data
Particle::Particle(
	Position initialPos
) : initialPos(initialPos), currPos(initialPos)
{
}


void Particle::UpdatePos() {
	std::cout << lorenzX(currPos.x, currPos.y, currPos.z) << std::endl;
	std::cout << lorenzY(currPos.x, currPos.y, currPos.z) << std::endl;
	std::cout << lorenzZ(currPos.x, currPos.y, currPos.z) << std::endl;

}

void Particle::draw() {

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