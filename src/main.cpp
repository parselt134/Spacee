#include "Simulation/Space.hpp"
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode({Config::Window::height, Config::Window::width}), "Spacee");
    window.setFramerateLimit(Config::Window::fps);

    sf::Clock clock{};

    Space space = Space();

    space.initializeSolarSystem();

    space.drawSpace(window);
    window.display();

    while (window.isOpen()) {
        float dt = clock.getElapsedTime().asSeconds();
        if (dt >= 1.f / Config::Window::fps) {
            clock.restart();

            while (auto event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>()) {
                    window.close();
                }
                else if (event->is<sf::Event::Resized>()) {
                    //sf::View view(sf::FloatRect({0.f, 0.f}, sf::Vector2f(window.getSize())));
                    //sf::View view({Config::Window::width, Config::Resolution::height}, sf::Vector2f(window.getSize()));
                    //window.setView(view);
                }
            }

            space.drawSpace(window);
            window.display();
        }
    }
}