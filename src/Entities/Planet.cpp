#include "Entities/Planet.hpp"

Planet::Planet(float radius, double mass, float x, float y, sf::Vector2f realV, sf::Color color) :
    CelestialBody(radius, mass, x, y, realV, color)
{
    setShape();
}

void Planet::setShape() {
    shape = sf::CircleShape(radius);
    shape.setFillColor(color);
    shape.setOrigin(sf::Vector2f(radius, radius));
    shape.setPosition(sf::Vector2f(x, y));
}