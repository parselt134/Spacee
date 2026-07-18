#include "Entities/Star.hpp"

Star::Star(double radius, double mass, double x, double y, sf::Vector2<double> realV, sf::Color color) :
    CelestialBody(radius, mass, x, y, realV, color)
{
    setShape();
}

void Star::setShape() {
    shape = sf::CircleShape(radius);
    shape.setFillColor(color);
    shape.setOrigin(sf::Vector2f(radius, radius));
    shape.setPosition(sf::Vector2f(x, y));
}