#include "Entities/CelestialBody.hpp"

const float CelestialBody::getRadius() const { return radius; }
const float CelestialBody::getMass() const { return mass; }
const float CelestialBody::getX() const { return x; }
const float CelestialBody::getY() const { return y; }
const sf::Vector2f CelestialBody::getRealV() const { return realV; };
const sf::Color CelestialBody::getColor() const { return color; }

void CelestialBody::setRadius(float mass) { this->radius = radius; }
void CelestialBody::setMass(float mass) { this->mass = mass; }
void CelestialBody::setRealV(sf::Vector2f realV) { this->realV = realV; };
void CelestialBody::setColor(sf::Color color) { this->color = color; }