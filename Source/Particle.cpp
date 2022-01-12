#include <iostream>
#include "Particle.h"

// constructor, intialises data
Particle::Particle(
	Position initialPos,
	std::function<double(double)> dx,
	std::function<double(double)> dy,
	std::function<double(double)> dz
) : initialPos(initialPos), dx(dx), dy(dy), dz(dz), currPos(initialPos)
{
	
}


void Particle::UpdatePos() {
	std::cout << dx(currPos.x) << std::endl;
	std::cout << dy(currPos.y) << std::endl;
	std::cout << dz(currPos.z) << std::endl;

}

void Particle::draw() {

}
