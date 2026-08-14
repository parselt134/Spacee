#include "Simulation/Space.hpp"
#include "Core/Constants.hpp"
#include "Core/BaseFunctions.hpp"
#include <iostream>

Space::Space(double timeAcceleration) {
    BackgroundStars stars = BackgroundStars();
    this->timeAcceleration = timeAcceleration;
}

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
    // Sun
    std::unique_ptr<CelestialBody> sun = std::make_unique<Star>(Config::CB::Sun::name,
                                                                Config::CB::Sun::pixelRadius,
                                                                Config::CB::Sun::minPixelRadius,
                                                                Config::CB::Sun::mass,
                                                                Config::CB::Sun::longitude,
                                                                Config::CB::Sun::distance,
                                                                Config::CB::Sun::realV,
                                                                Config::CB::Sun::color,
                                                                CoordinateType::Ecliptic);
    bodies.push_back(std::move(sun));

    // Mercury
    std::unique_ptr<CelestialBody> mercury = std::make_unique<Planet>(Config::CB::Mercury::name,
                                                                      Config::CB::Mercury::pixelRadius,
                                                                      Config::CB::Mercury::minPixelRadius,
                                                                      Config::CB::Mercury::mass,
                                                                      Config::CB::Mercury::longitudeAphelion,
                                                                      Config::CB::Mercury::aphelion,
                                                                      Config::CB::Mercury::aphelionVelocity,
                                                                      Config::CB::Mercury::color,
                                                                      CoordinateType::Ecliptic);
    bodies.push_back(std::move(mercury));

    // Venus
    std::unique_ptr<CelestialBody> venus = std::make_unique<Planet>(Config::CB::Venus::name,
                                                                    Config::CB::Venus::pixelRadius,
                                                                    Config::CB::Venus::minPixelRadius,
                                                                    Config::CB::Venus::mass,
                                                                    Config::CB::Venus::longitudeAphelion,
                                                                    Config::CB::Venus::aphelion,
                                                                    Config::CB::Venus::aphelionVelocity,
                                                                    Config::CB::Venus::color,
                                                                    CoordinateType::Ecliptic);
    bodies.push_back(std::move(venus));

    // Earth
    std::unique_ptr<CelestialBody> earth = std::make_unique<Planet>(Config::CB::Earth::name,
                                                                    Config::CB::Earth::pixelRadius,
                                                                    Config::CB::Earth::minPixelRadius,
                                                                    Config::CB::Earth::mass,
                                                                    Config::CB::Earth::longitudeAphelion,
                                                                    Config::CB::Earth::aphelion,
                                                                    Config::CB::Earth::aphelionVelocity,
                                                                    Config::CB::Earth::color,
                                                                    CoordinateType::Ecliptic);
    bodies.push_back(std::move(earth));

    // Mars
    std::unique_ptr<CelestialBody> mars = std::make_unique<Planet>(Config::CB::Mars::name,
                                                                   Config::CB::Mars::pixelRadius,
                                                                   Config::CB::Mars::minPixelRadius,
                                                                   Config::CB::Mars::mass,
                                                                   Config::CB::Mars::longitudeAphelion,
                                                                   Config::CB::Mars::aphelion,
                                                                   Config::CB::Mars::aphelionVelocity,
                                                                   Config::CB::Mars::color,
                                                                   CoordinateType::Ecliptic);
    bodies.push_back(std::move(mars));
}

void Space::drawSpace(sf::RenderWindow& window, Camera& camera, float deltaTime) {
    float safeDeltaTime = std::min(deltaTime, Config::Window::maxDt);  // clamping
    
    double acceleratedDt = static_cast<double>(safeDeltaTime) * this->timeAcceleration;

    // sub-stepping
    int steps = static_cast<int>(std::ceil(acceleratedDt / Config::Window::maxSubDt));
    steps = std::min(steps, Config::Window::maxSteps);

    float subDt = static_cast<float>(acceleratedDt) / static_cast<float>(steps);

    for (size_t i = 0; i < steps; ++i) {
        changeVelocities(subDt);
        drawBackground(window);

        // CBs
        for (std::unique_ptr<CelestialBody>& body : bodies)
            body->update(subDt);

        for (std::unique_ptr<CelestialBody>& body : bodies)
            body->draw(window, camera);

        if (camera.getIsFollowing()) {
            int targetInd = camera.getTargetInd();
            const CelestialBody& targetBody = *(bodies.at(targetInd));
            camera.follow(targetBody.getX(), targetBody.getY());
        }
    }
}



const double Space::getTimeAcceleration() const { return timeAcceleration; }
const std::vector<std::unique_ptr<CelestialBody>>& Space::getBodies() const { return bodies; };

void Space::setTimeAcceleration(double timeAcceleration) { this->timeAcceleration = timeAcceleration; }