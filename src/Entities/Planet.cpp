#include "Entities/Planet.hpp"

Planet::Planet(std::string name, float radius, float minRadius, double mass,
               double a, double b, sf::Vector2<double> realV, sf::Color color,
               CoordinateType type) :
    CelestialBody(name, radius, minRadius, mass, a, b, realV, color, type)
{
    setShape();
}

void Planet::setShape() {
    shape = sf::CircleShape(radius);
    shape.setFillColor(color);
    shape.setOrigin(sf::Vector2f(radius, radius));
    shape.setPosition(sf::Vector2f(x, y));
}