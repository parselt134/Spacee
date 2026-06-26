#include "Simulation/Space.hpp"
#include "Core/Constants.hpp"
#include "Core/BaseFunctions.hpp"
#include <iostream>

Space::Space() {
    BackgroundStars stars = BackgroundStars();
}

//float Space::calcGravityForce() {
//
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
        1.f,
        1.f,
        Config::CB::Sun::realV,
        1.f,
        1.f,
        Config::CB::Sun::color);
    // Sun
    bodies.push_back(std::move(sun));

    // Mercury
    std::unique_ptr<CelestialBody> mercury = std::make_unique<Planet>(Config::CB::Mercury::pixelRadius,
        Config::CB::Mercury::mass,
        Config::CB::Mercury::startX,
        Config::CB::Mercury::startY,
        1.f,
        1.f,
        Config::CB::Mercury::realV,
        1.f,
        1.f,
        Config::CB::Mercury::color);
    bodies.push_back(std::move(mercury));

    // Venus
    //std::unique_ptr<CelestialBody> venus = std::make_unique<Planet>(Config::CB::Venus::pixelRadius,
    //                                                                Config::CB::Venus::mass,
    //                                                                Config::CB::Venus::startX,
    //                                                                Config::CB::Venus::startY,
    //                                                                1.f,
    //                                                                1.f,
    //                                                                Config::CB::Venus::realV,
    //                                                                1.f,
    //                                                                1.f,
    //                                                                Config::CB::Venus::color);
    //bodies.push_back(std::move(venus));
}

void Space::drawSpace(sf::RenderWindow& window) {
    drawBackground(window);

    // CBs
    for (const std::unique_ptr<CelestialBody>& body : bodies) {  // std::unique_ptr<CelestialBody>
        body->draw(window);
        body->update();
    }
}