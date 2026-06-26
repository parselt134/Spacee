//#include "Entities/Sun.hpp"
//
//Sun::Sun(float x,
//		 float y,
//	     v realV,
//		 float radius,
//		 double mass,
//		 sf::Color color)
//{
//	this->radius = radius;
//	this->mass = mass;
//	this->realV = realV;
//	shapeSun = sf::CircleShape(radius);
//	shapeSun.setFillColor(color);
//	shapeSun.setOrigin(sf::Vector2f(radius, radius));
//	shapeSun.setPosition(sf::Vector2f(x, y));
//}
//
//const sf::CircleShape Sun::getShape() { return shapeSun; }
//
//void Sun::update() {
//	float offsetX = sinf(degreesToRadians(this->realV.direction)) * (realV.length * Config::Coefs::velocity);
//	float offsetY = cosf(degreesToRadians(this->realV.direction)) * (realV.length * Config::Coefs::velocity);
//	//double R = 
//	//realV.length = sqrt(Config::Coefs::G * (Config::CB::Mercury::mass / Config::CB::Mercury::));
//	shapeSun.update(sf::Vector2f(offsetX, -offsetY));
//}