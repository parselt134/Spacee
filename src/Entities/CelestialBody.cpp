#include "Entities/CelestialBody.hpp"

#include "Core/Constants.hpp"

CelestialBody::CelestialBody(std::string name, float radius, float minRadius, double mass,
                             double a, double b, sf::Vector2<double> realV, sf::Color color,
                             CoordinateType type) :
        name(name),
        radius(radius),
        minRadius(minRadius),
        mass(mass),
        x(type == CoordinateType::Rectangular ? a * Config::Coefs::AU_TO_M : (b * Config::Coefs::AU_TO_M) * cos(degToRad(a))),
        y(type == CoordinateType::Rectangular ? b * Config::Coefs::AU_TO_M : (b * Config::Coefs::AU_TO_M) * sin(degToRad(a))),
        realV(realV),
        color(color)
    { }

const std::string CelestialBody::getName() const { return name; }
const float CelestialBody::getRadius() const { return radius; }
const float CelestialBody::getMinRadius() const { return minRadius; }
const double CelestialBody::getMass() const { return mass; }
const double CelestialBody::getX() const { return x; }
const double CelestialBody::getY() const { return y; }
const sf::Vector2<double> CelestialBody::getRealV() const { return realV; };
const sf::Color CelestialBody::getColor() const { return color; }

void CelestialBody::setName(std::string name) { this->name = name; }
void CelestialBody::setRadius(float raidus) { this->radius = radius; }
void CelestialBody::setMinRadius(float minRadius) { this->minRadius = minRadius; }
void CelestialBody::setMass(double mass) { this->mass = mass; }
void CelestialBody::setX(double x) { this->x = x; }
void CelestialBody::setY(double y) { this->y = y; }
void CelestialBody::setRealV(sf::Vector2<double> realV) { this->realV = realV; };
void CelestialBody::setColor(sf::Color color) { this->color = color; }