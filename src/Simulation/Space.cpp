#include "Simulation/Space.hpp"
#include "Core/Constants.hpp"
#include "Core/BaseFunctions.hpp"
#include <iostream>

Space::Space() {
    BackgroundStars stars = BackgroundStars();
}

//float Space::calcForceGravity(size_t pos) {
//    for (size_t i = pos+1; i < )
//}

//void Space::changeVelocities() {
//    std::vector<sf::Vector2f> forcesGravity(bodies.size());
//    std::vector<sf::Vector2f> accelerations(bodies.size());
//
//    for (size_t i = 0; i < bodies.size(); ++i) {
//        for (size_t j = 0; j < bodies.size(); ++j) {
//            if (i == j)
//                continue;
//            
//            float forceGravity = 
//        }
//    }
//}

void Space::drawBackground(sf::RenderWindow& window) {
    window.clear(Config::Window::backgroundColor);

    // stars
    const auto& starsVertex = this->stars.getStarsAsShapesVertex();
    window.draw(starsVertex);
}

void Space::initializeSolarSystem() {
    std::unique_ptr<CelestialBody> sun = std::make_unique<Star>(Config::CB::Sun::pixelRadius,
        Config::CB::Sun::mass,
        Config::CB::Sun::startX,
        Config::CB::Sun::startY,
        Config::CB::Sun::realV,
        Config::CB::Sun::color);
    // Sun
    bodies.push_back(std::move(sun));

    // Mercury
    std::unique_ptr<CelestialBody> mercury = std::make_unique<Planet>(Config::CB::Mercury::pixelRadius,
        Config::CB::Mercury::mass,
        Config::CB::Mercury::startX,
        Config::CB::Mercury::startY,
        Config::CB::Mercury::realV,
        Config::CB::Mercury::color);
    bodies.push_back(std::move(mercury));

    // Venus
    std::unique_ptr<CelestialBody> venus = std::make_unique<Planet>(Config::CB::Venus::pixelRadius,
                                                                    Config::CB::Venus::mass,
                                                                    Config::CB::Venus::startX,
                                                                    Config::CB::Venus::startY,
                                                                    Config::CB::Venus::realV,
                                                                    Config::CB::Venus::color);
    bodies.push_back(std::move(venus));
}

void Space::drawSpace(sf::RenderWindow& window) {
    drawBackground(window);

    // CBs
    for (std::unique_ptr<CelestialBody>& body : bodies) {  // std::unique_ptr<CelestialBody>
        body->draw(window);
        //changeVelocities();
        body->update();
    }
}