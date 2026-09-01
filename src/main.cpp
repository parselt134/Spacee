#include "Simulation/Space.hpp"
#include "imgui.h"
#include "imgui-SFML.h"

#include "Core/Constants.hpp"
#include "Core/Camera.hpp"
#include "Entities/CelestialBody.hpp"
#include "Core/InputState.hpp"
#include "Core/GuiManager.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode({ Config::Window::width, Config::Window::height }), "Spacee", sf::Style::Default);
    window.setMinimumSize(sf::Vector2u( Config::Window::minWidth, Config::Window::minHeight ));
    bool isFullscreen = false;
    window.setFramerateLimit(Config::Window::fps);

    double elapsedSimulationTime = 0.;

    ImGui::SFML::Init(window);

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
        ImGuiIO io = ImGui::GetIO();

        if (clock.getElapsedTime().asSeconds() >= 1.f / Config::Window::fps) {
            sf::Time deltaTimeSfml = clock.restart();
            float dt = deltaTimeSfml.asSeconds();
            elapsedSimulationTime += dt * space.getTimeAcceleration();

            while (auto event = window.pollEvent()) {
                ImGui::SFML::ProcessEvent(window, *event);

                if (event->is<sf::Event::Closed>()) {
                    window.close();
                }
                if (auto* resize = event->getIf<sf::Event::Resized>()) {
                    sf::FloatRect visibleArea(sf::Vector2f( 0.f, 0.f ), sf::Vector2f( static_cast<float>(resize->size.x), static_cast<float>(resize->size.y) ));
                    window.setView(sf::View(visibleArea));
                }
                if ( auto* mouse = event->getIf<sf::Event::MouseWheelScrolled>()) {
                    if (!(io.WantCaptureMouse)) {
                        camera.zoom(mouse->delta, mouse->position, window);
                    }
                }

                // event-driven (discrete action)
                if (auto* mouse = event->getIf<sf::Event::MouseButtonPressed>()) {

                    if (!(io.WantCaptureMouse) && mouse->button == sf::Mouse::Button::Left) {
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

                // event-driven keystroke handling
                if (auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                    
                    if (keyPressed->scancode == sf::Keyboard::Scancode::S) {
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

                    if (keyPressed->scancode == sf::Keyboard::Scancode::F11) {
                        if (!isFullscreen) {
                            window.create(sf::VideoMode::getDesktopMode(), "Spacee", sf::Style::None);
                        }
                        else {
                            window.create(sf::VideoMode({ Config::Window::width, Config::Window::height }), "Spacee", sf::Style::Default);
                        }
                        isFullscreen = !isFullscreen;
                    }

                    if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                        ImGui::SFML::Shutdown();
                        window.close();
                        return 0;
                    }

                }

            }


            // real-time state polling (continuous action)
            if (!(io.WantCaptureMouse) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {

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

            space.drawSpace(window, camera, dt);

            // ImGui
            ImGui::SFML::Update(window, deltaTimeSfml);
            //

            RenderContext ctx{window, camera, space, mouseStates};
            GuiManager::render(ctx);


            /*ImGui::SetNextWindowSize(ImVec2(450.f, 300.f), ImGuiCond_Always);

            ImVec2 pos = ImVec2(window.getSize().x, 0.0f);
            ImVec2 pivot = ImVec2(1.0f, 0.0f);
            ImGui::SetNextWindowPos(pos, ImGuiCond_Always, pivot);

            ImGuiWindowFlags windowFlags = 0;
            windowFlags |= ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar;
            
            ImGui::Begin("Info", nullptr, windowFlags);

            ImGui::GetIO().FontGlobalScale = 1.4f;

            ImGui::StyleColorsClassic;

            ImGui::SeparatorText("Control Panel");


            ImGui::SeparatorText("Info");
                if (mouseStates.isCbSelected) {
                    const int targetInd = camera.getTargetInd();
                    const int starInd = space.getSunInd();

                    std::string description = "Type:";
                    ImGui::Text(description.c_str());
                    ImGui::SameLine();
                    std::string type = typeid(*space.getBodies().at(targetInd)).name();
                    type = type.substr(6);
                    ImGui::Text(type.c_str());  // type of Cb

                    description = "Name:";
                    ImGui::Text(description.c_str());
                    ImGui::SameLine();
                    std::string name = space.getBodies().at(targetInd)->getName();
                    ImGui::Text(name.c_str());  // name of Cb

                    ImGui::Separator();

                    description = "Mass:";
                    ImGui::Text(description.c_str());
                    ImGui::SameLine();
                    double massInEm = space.getBodies().at(targetInd)->getMass();
                    std::string massInEmStr = formatDouble(massInEm, Unit::Em);
                    ImGui::Text(massInEmStr.c_str());  // mass of Cb
                    ImGui::SameLine();
                    ImGui::Text("Earth masses");

                    ImGui::Separator();

                    if (targetInd != starInd) {
                        description = "Distance from the Sun:";
                        ImGui::Text(description.c_str());

                        double distanceInMeters = distanseFromStar(*(space.getBodies().at(starInd)), *(space.getBodies().at(targetInd)));  // distance from the Sun of Cb, meters
                        std::string distanceInMetersStr = "\t" + formatDouble(distanceInMeters, Unit::Meter);
                        ImGui::Text(distanceInMetersStr.c_str());
                        ImGui::SameLine();
                        ImGui::Text("m");

                        double distanceInAu = distanceInMeters * Config::Coefs::M_TO_AU;
                        std::string distanceInAuStr = "\t" + formatDouble(distanceInAu, Unit::Au);
                        ImGui::Text(distanceInAuStr.c_str());
                        ImGui::SameLine();
                        ImGui::Text("au");

                        description = "Velocity:";
                        ImGui::Text(description.c_str());

                        double velocityInMps = space.getBodies().at(targetInd)->getRealV().length();
                        std::string velocityInMpsStr = "\t" + formatDouble(velocityInMps, Unit::Mps);
                        ImGui::Text(velocityInMpsStr.c_str());
                        ImGui::SameLine();
                        ImGui::Text("m/s");
                    }
                }
                else {
                    ImGui::Text("Click on a celestial body to get information");
                }

            ImGui::End();
            */

            //
            ImGui::SFML::Render(window);

            window.display();
        }
    }

    ImGui::SFML::Shutdown();
    window.close();
    return 0;
}