#include "Entities/CelestialBody.hpp"

const double CelestialBody::getRadius() const { return radius; }
const double CelestialBody::getMass() const { return mass; }
const double CelestialBody::getX() const { return x; }
const double CelestialBody::getY() const { return y; }
const sf::Vector2<double> CelestialBody::getRealV() const { return realV; };
const sf::Color CelestialBody::getColor() const { return color; }

void CelestialBody::setRadius(double mass) { this->radius = radius; }
void CelestialBody::setMass(double mass) { this->mass = mass; }
void CelestialBody::setX(double x) { this->x = x; }
void CelestialBody::setY(double y) { this->y = y; }
void CelestialBody::setRealV(sf::Vector2<double> realV) { this->realV = realV; };
void CelestialBody::setColor(sf::Color color) { this->color = color; }