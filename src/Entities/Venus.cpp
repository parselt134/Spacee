//#include "Entities/Venus.hpp"
//
//Venus::Venus(float x,
//	float y,
//	v realV,
//	float radius,
//	double mass,
//	sf::Color color)
//{
//	this->radius = radius;
//	this->mass = mass;
//	this->realV = realV;
//	shapeVenus = sf::CircleShape(radius);
//	shapeVenus.setFillColor(color);
//	shapeVenus.setOrigin(sf::Vector2f(radius, radius));
//	shapeVenus.setPosition(sf::Vector2f(x, y));
//}
//
//const sf::CircleShape Venus::getShape() { return this->shapeVenus; }
//
//void Venus::update() {
//	float offsetX = sinf(degreesToRadians(realV.direction)) * (realV.length * Config::Coefs::velocity);
//	float offsetY = cosf(degreesToRadians(realV.direction)) * (realV.length * Config::Coefs::velocity);
//	shapeVenus.update(sf::Vector2f(offsetX, -offsetY));
//}