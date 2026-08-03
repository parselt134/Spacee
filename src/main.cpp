#include "Simulation/Space.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode({Config::Window::height, Config::Window::width}), "Spacee");
    window.setFramerateLimit(Config::Window::fps);

    sf::Clock clock{};

    Camera camera = Camera();

    Space space = Space(Config::Coefs::timeAcceleration);

    space.initializeSolarSystem();

    while (window.isOpen()) {
        if (clock.getElapsedTime().asSeconds() >= 1.f / Config::Window::fps) {
            float dt = clock.restart().asSeconds();

            while (auto event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>()) {
                    window.close();
                }
                else if (auto* mouse = event->getIf<sf::Event::MouseWheelScrolled>()) {
                    camera.zoom(mouse->delta);
                    std::cout << "scale=" << camera.getScale() / Config::Camera::scale << std::endl;
                }
            }

            space.drawSpace(window, camera, dt);
            window.display();
        }
    }
}