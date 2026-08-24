#include "Simulation/Space.hpp"

typedef struct {
    bool isCbSelected;
    bool isPressed;
    bool onPress;
    bool onRelease;
} mouseStates;

int main() {
    sf::RenderWindow window(sf::VideoMode({ Config::Window::width, Config::Window::height }), "Spacee", sf::Style::Default);
    bool isFullscreen = false;
    window.setFramerateLimit(Config::Window::fps);

    Space space = Space(Config::Coefs::timeAcceleration);
    space.initializeSolarSystem();

    Camera camera = Camera();

    sf::Clock clock{};

    mouseStates mouseStates{};
    mouseStates.isCbSelected = false;
    mouseStates.isPressed = false;
    mouseStates.onPress = false;
    mouseStates.onRelease = false;

    sf::Vector2<double> startPosition{}; // mouse
    sf::Vector2<double> endPosition{};   // mouse
    sf::Vector2<double> offset{};        // mouse

    while (window.isOpen()) {
        if (clock.getElapsedTime().asSeconds() >= 1.f / Config::Window::fps) {
            float dt = clock.restart().asSeconds();

            while (auto event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>()) {
                    window.close();
                }
                if (auto* resize = event->getIf<sf::Event::Resized>()) {
                    sf::FloatRect visibleArea(sf::Vector2f( 0.f, 0.f ), sf::Vector2f( resize->size.x, resize->size.y ));
                    window.setView(sf::View(visibleArea));
                }
                if (auto* mouse = event->getIf<sf::Event::MouseWheelScrolled>()) {
                    camera.zoom(mouse->delta, mouse->position, window);
                }
                if (auto* mouse = event->getIf<sf::Event::MouseButtonPressed>()) {
                    if (mouse->button == sf::Mouse::Button::Left) {
                        mouseStates.isCbSelected = false;

                        sf::Vector2i mousePixelCoords = mouse->position;

                        sf::Vector2f mouseWorldCoords = window.mapPixelToCoords(mousePixelCoords);
                    
                        int ind = 0;
                        for (const std::unique_ptr<CelestialBody>& body : space.getBodies()) {
                            if (body->isClicked(mouseWorldCoords)) {
                                camera.setTargetInd(ind);
                                camera.setIsFollowing(true);
                                mouseStates.isCbSelected = true;
                                break;
                            }
                            ++ind;
                        }
                    }
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
                int ind = 0;
                for (const std::unique_ptr<CelestialBody>& body : space.getBodies()) {
                    if (body->getName() == Config::CB::Sun::name) {
                        camera.setTargetInd(ind);
                        camera.setIsFollowing(true);
                        mouseStates.isCbSelected = true;
                        break;
                    }
                    ++ind;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F11)) {
                if (isFullscreen) {
                    window.create(sf::VideoMode::getDesktopMode(), "Spacee", sf::Style::None);
                }
                else {
                    window.create(sf::VideoMode({ Config::Window::width, Config::Window::height }), "Spacee", sf::Style::Default);
                }
                isFullscreen = !isFullscreen;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
                window.close();
                return 0;
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                
                endPosition = camera.screenToWorld(sf::Vector2f(sf::Mouse::getPosition(window)), window);

                if (not mouseStates.isPressed) {
                    startPosition = endPosition;
                }

                offset = startPosition - endPosition;

                if (not mouseStates.isCbSelected) {
                    camera.setTargetInd(-1);
                    camera.setIsFollowing(false);
                }


                camera.move(offset.x, offset.y);

                mouseStates.isPressed = true;
                mouseStates.onRelease = false;
            }
            else {
                mouseStates.isPressed = false;
                mouseStates.onRelease = true;
            }

            //

            space.drawSpace(window, camera, dt);
            window.display();
        }
    }
}