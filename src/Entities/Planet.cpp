#include "Entities/Planet.hpp"

Planet::Planet(std::string name, double radius, double mass, double x, double y, sf::Vector2<double> realV, sf::Color color) :
    CelestialBody(name, radius, mass, x, y, realV, color)
{
    setShape();
}

void Planet::setShape() {
    shape = sf::CircleShape(radius);
    shape.setFillColor(color);
    shape.setOrigin(sf::Vector2f(radius, radius));
    shape.setPosition(sf::Vector2f(x, y));
}