#pragma once
#include <functional>
#include <SFML/Graphics.hpp>


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

	sf::CircleShape point;


	double lorenzX(double x, double y, double z);
	double lorenzY(double x, double y, double z);
	double lorenzZ(double x, double y, double z);



public:
	// constructor
	Particle( Position initialPos, sf::Color colour);

	// updates the current position based on the functions
	void UpdatePos();

	// draws the particle on the screen
	void draw(sf::RenderWindow &window);

};