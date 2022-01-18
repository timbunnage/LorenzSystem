#include <iostream>
#include "Particle.h"

// constructor, intialises data
Particle::Particle(
	Position initialPos, 
	sf::Color colour) 
	: initialPos(initialPos), currPos(initialPos), point(0.8f)
{
	point.setFillColor(colour);
}


void Particle::UpdatePos() {
	currPos.x += 1.0e-4 * lorenzX(currPos.x, currPos.y, currPos.z);
	currPos.y += 1.0e-4 * lorenzY(currPos.x, currPos.y, currPos.z);
	currPos.z += 1.0e-4 * lorenzZ(currPos.x, currPos.y, currPos.z);
	point.setPosition(15 * currPos.x + 800, -15 * currPos.z + 772);
}

void Particle::draw(sf::RenderWindow& window) {
	// Print particle coordinates
	// printf("(%f,%f,%f)\n", currPos.x, currPos.y, currPos.z);
	
	window.draw(point);
}

double Particle::lorenzX(double x, double y, double z) {
	return 10.0 * (y - x);
}
double Particle::lorenzY(double x, double y, double z) {
	return x * (28.0 - z) - y;
}
double Particle::lorenzZ(double x, double y, double z) {
	return x * y - 8.0/3.0 * z;
}