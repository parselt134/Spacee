#include "Entities/Planet.hpp"

Planet::Planet(float radius, double mass, float x, float y, float vx, float vy, v realV, float realVx, float realVy, sf::Color color) :
    CelestialBody(radius, mass, x, y, vx, vy, realV, realVx, realVy, color)
{
    setShape();
}

void Planet::setShape() {
    shape = sf::CircleShape(radius);
    shape.setFillColor(color);
    shape.setOrigin(sf::Vector2f(radius, radius));
    shape.setPosition(sf::Vector2f(x, y));
}