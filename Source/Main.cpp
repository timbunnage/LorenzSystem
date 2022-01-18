#include <iostream>
#include <SFML/Graphics.hpp>
#include "Particle.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(1600, 900), "LorenzAttractor");
    sf::CircleShape point(100.f);
    point.setFillColor(sf::Color::Green);

    // Create random initial condition
    srand(time(NULL));

    double initx = 30.0 * rand() / RAND_MAX; - 15;
    double inity = 30.0 * rand() / RAND_MAX; - 15;
    double initz = 30.0 * rand() / RAND_MAX; - 15;

    printf("Initial position: (%f, %f, %f)\n", initx, inity, initz);

    // Create a single particle
    Particle p1 = Particle({ initx - 0.02, inity - 0.02 , initz - 0.02 }, sf::Color::Magenta);
    Particle p2 = Particle({ initx - 0.01, inity - 0.01 , initz - 0.01 }, sf::Color::Cyan);
    Particle p3 = Particle({ initx       , inity        ,  initz       }, sf::Color::Red);
    Particle p4 = Particle({ initx + 0.01, inity + 0.01 , initz + 0.01 }, sf::Color::Green);
    Particle p5 = Particle({ initx + 0.02, inity + 0.02 , initz + 0.02 }, sf::Color::Blue);

    
    // Test Loop
    // p.draw();
    // for (int i = 0; i < 100; i++) {
    //     p.UpdatePos();
    //     p.draw();
    // }


    while (window.isOpen())
    {

        // check for events
        sf::Event event;

        while (window.pollEvent(event))
        {
            // close the window event
            // if (event.type == sf::Event::Closed)
            //     window.close();
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }

        p1.UpdatePos();
        p2.UpdatePos();
        p3.UpdatePos();
        p4.UpdatePos();
        p5.UpdatePos();

        p1.draw(window);
        p2.draw(window);
        p3.draw(window);
        p4.draw(window);
        p5.draw(window);
        window.display();
    }

    return 0;
}

// TEST FUNCTION
