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


void Space::changeVelocities(double acceleratedDt) {
    std::vector<sf::Vector2<double>> accelerations(bodies.size(), {0.f, 0.f});

    for (size_t i = 0; i < bodies.size(); ++i) {
        for (size_t j = 0; j < bodies.size(); ++j) {
            if (i == j)
                continue;
            
            double dx = bodies[j]->getX() - bodies[i]->getX();
            double dy = bodies[j]->getY() - bodies[i]->getY();
            
            double distanceSqr = dx * dx + dy * dy;
            double distance = std::sqrt(distanceSqr);

            if (distance < 1000.)
                continue;  // TODO: burst

            //double m1 = bodies[i]->getMass() * Config::Coefs::EM_TO_KG;  // kg
            double m2 = bodies[j]->getMass() * Config::Coefs::EM_TO_KG;  // kg

            double accelerationMagnitude = (Config::Coefs::G * m2) / distanceSqr;

            sf::Vector2<double> normalizedVector{dx/distance, dy/distance};
            sf::Vector2<double> accelerationVector = normalizedVector * accelerationMagnitude;

            accelerations[i] += accelerationVector;
        }
    }

    for (size_t i = 0; i < bodies.size(); ++i) {
        sf::Vector2<double> newVelocity = bodies[i]->getRealV() + accelerations[i] * acceleratedDt;
        bodies[i]->setRealV(newVelocity);
    }
}


void Space::drawBackground(sf::RenderWindow& window) {
    window.clear(Config::Window::backgroundColor);

    // stars
    const auto& starsVertex = this->stars.getStarsAsShapesVertex();
    window.draw(starsVertex);
}

void Space::initializeSolarSystem() {
    std::unique_ptr<CelestialBody> sun = std::make_unique<Star>(Config::CB::Sun::pixelRadius,
                                                                Config::CB::Sun::mass,
                                                                Config::CB::Sun::startRealX,
                                                                Config::CB::Sun::startRealY,
                                                                Config::CB::Sun::realV,
                                                                Config::CB::Sun::color);
    // Sun
    bodies.push_back(std::move(sun));

    // Mercury
    std::unique_ptr<CelestialBody> mercury = std::make_unique<Planet>(Config::CB::Mercury::pixelRadius,
                                                                      Config::CB::Mercury::mass,
                                                                      Config::CB::Mercury::startRealX,
                                                                      Config::CB::Mercury::startRealY,
                                                                      Config::CB::Mercury::realV,
                                                                      Config::CB::Mercury::color);
    bodies.push_back(std::move(mercury));

    // Venus
    std::unique_ptr<CelestialBody> venus = std::make_unique<Planet>(Config::CB::Venus::pixelRadius,
                                                                    Config::CB::Venus::mass,
                                                                    Config::CB::Venus::startRealX,
                                                                    Config::CB::Venus::startRealY,
                                                                    Config::CB::Venus::realV,
                                                                    Config::CB::Venus::color);
    bodies.push_back(std::move(venus));
}

void Space::drawSpace(sf::RenderWindow& window, const Camera& camera, float deltaTime) {
    double acceleratedDt = static_cast<double>(deltaTime) * Config::Coefs::timeAcceleration;

    changeVelocities(acceleratedDt);
    drawBackground(window);

    // CBs
    for (std::unique_ptr<CelestialBody>& body : bodies)
        body->update(acceleratedDt);

    for (std::unique_ptr<CelestialBody>& body : bodies)
        body->draw(window, camera);
}