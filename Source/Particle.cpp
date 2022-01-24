#include <iostream>
#include "Particle.h"

// constructor, intialises data
Particle::Particle(
	Position initialPos, 
	sf::Color colour) 
	: initialPos(initialPos), currPos(1), theta(0), point(0.8f)
{
	for (int i = 0; i < TAIL_LENGTH; i++)
	{
		posList[i] = initialPos;
	}
	point.setFillColor(colour);
}



void Particle::UpdatePos() {
	
	for (int i = 0; i < 100; i++)
	{
		posList[currPos].x += 1.0e-4 * lorenzX(posList[currPos].x, posList[currPos].y, posList[currPos].z);
		posList[currPos].y += 1.0e-4 * lorenzY(posList[currPos].x, posList[currPos].y, posList[currPos].z);
		posList[currPos].z += 1.0e-4 * lorenzZ(posList[currPos].x, posList[currPos].y, posList[currPos].z);
	}

	if (currPos > TAIL_LENGTH-1)
	{
		posList[0].x = posList[currPos].x;
		posList[0].y = posList[currPos].y;
		posList[0].z = posList[currPos].z;

		currPos = 0;
	}
	else
	{
		posList[currPos + 1].x = posList[currPos].x;
		posList[currPos + 1].y = posList[currPos].y;
		posList[currPos + 1].z = posList[currPos].z;
		currPos++;
	}
}

void Particle::draw(sf::RenderWindow& window) {
	// Print particle coordinates
	// printf("(%f,%f,%f)\n", currPos.x, currPos.y, currPos.z);
	for (int i = 0; i < TAIL_LENGTH; i++)
	{
		double hPos = posList[i].x * cos(theta) - posList[i].y * sin(theta);
		point.setPosition(15 * hPos + 800, -15 * posList[i].z + 772);
		window.draw(point);
	}
	theta += 0.001;
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