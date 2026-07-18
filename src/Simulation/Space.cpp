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

/*
void Space::changeVelocities() {
    std::vector<sf::Vector2f> forcesGravity(bodies.size());
    std::vector<sf::Vector2f> accelerations(bodies.size(), {0.f, 0.f});

    for (size_t i = 0; i < bodies.size(); ++i) {
        sf::Vector2f resultForceGravityVector = { 0.f, 0.f };
        sf::Vector2f resultAccelerationVector = { 0.f, 0.f };
        for (size_t j = 0; j < bodies.size(); ++j) {
            if (i == j)
                continue;
            
            //std::cout << "bodies[j]->getX()=" << bodies[j]->getX() << ", bodies[i]->getX()=" << bodies[i]->getX() << std::endl;
            float dx = bodies[j]->getX() - bodies[i]->getX();
            float dy = bodies[j]->getY() - bodies[i]->getY();
            sf::Vector2f pixelDistanceVector{dx, dy};
            //float realDx = dx * Config::Coefs::pixelsToKm();  // converted!
            //float realDy = dy * Config::Coefs::pixelsToKm();  // converted!
            //float realDistanceLength = sqrt(pow(realDx, 2.f) + pow(realDx, 2.f));
            //sf::Vector2f realDistanceVector{ realDx, realDy };
            //std::cout << "realDistanceVector.length()=" << realDistanceVector.length() << std::endl;

            float m1 = bodies[i]->getMass();  // em
            float m2 = bodies[j]->getMass();  // em

            std::cout << "m1*m2=" << m1*m2 << std::endl;
            std::cout << "pixelDistanceVector.length()=" << pixelDistanceVector.length() << std::endl;
            std::cout << "pow(pixelDistanceVector.length(), 2.f)=" << pow(pixelDistanceVector.length(), 2.f) << std::endl;
            std::cout << "((m1 * m2) / pow(pixelDistanceVector.length(), 2.f))=" << ((m1 * m2) / pow(pixelDistanceVector.length(), 2.f)) << std::endl;

            //float convertedG = Config::Coefs::G / (pow(1000.f, 2.f)) * (pow(Config::Coefs::kmToPixels(), 2.f)) * ( 1.f / pow(Config::Coefs::kgToEm(), 2.f));  // N*px^2/em^2
            //std::cout << "convertedG=" << convertedG << std::endl;

            //float neededG = ;
            
            float forceGravityLength = ((m1 * m2) / pow(pixelDistanceVector.length(), 2.f));  // convertedG * 
            std::cout << "forceGravityLength=" << forceGravityLength << std::endl;
            sf::Vector2f forceGravityVector = forceGravityLength * (pixelDistanceVector / pixelDistanceVector.length());  // N
            forceGravityVector *= (1.f / 1000.f);  // kg*km/sec^2
            //sf::Vector2f pixelForceGravityVector{ forceGravityVector.length(), forceGravityVector.angle() };
            resultForceGravityVector += forceGravityVector;


            sf::Vector2f accelerationVector = forceGravityVector * (100000000000000000000000.f / (bodies[i]->getMass() * Config::Coefs::emToKg()));
            std::cout << "accelerationVector=" << accelerationVector.x << ", " << accelerationVector.y << std::endl;
            //sf::Vector2f pixelAccelerationVector{ accelerationVector.length(), accelerationVector.angle() };
            resultAccelerationVector += accelerationVector;
        }
        forcesGravity.push_back(resultForceGravityVector);
        accelerations.push_back(resultAccelerationVector);
    }

    for (size_t i = 0; i < bodies.size(); ++i) {


        //std::cout << "acceleration=" << accelerations[i].x << ", " << accelerations[i].y << std::endl;
        //std::cout << "acceleration=" << accelerations[i].x << ", " << accelerations[i].y << std::endl;

        sf::Vector2f resultVelocity = bodies[i]->getRealV() + accelerations[i];
        bodies[i]->setRealV(resultVelocity);
    }
}
*/

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
    drawBackground(window);

    // CBs
    for (std::unique_ptr<CelestialBody>& body : bodies) {  // std::unique_ptr<CelestialBody>
        body->draw(window, camera);
        // body->update(deltaTime);
        // changeVelocities();
    }
}