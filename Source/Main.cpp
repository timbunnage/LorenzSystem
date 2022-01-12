#include <iostream>
#include <SFML/Graphics.hpp>
#include "Particle.h"

double func(double x);

int main() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);


    // Create a single particle
    Particle p = Particle({2,3,4}, &func, &func, &func);

    // Test the functions (print the output)
    p.UpdatePos();

    while (window.isOpen())
    {

        // check for events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // close the window event
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}

// TEST FUNCTION
double func(double x) {
    return x * x;
}