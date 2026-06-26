#include "Entities/CelestialBody.hpp"

const float CelestialBody::getRadius() const { return radius; }
const uint64_t CelestialBody::getMass() const { return mass; }
const float CelestialBody::getX() const { return x; }
const float CelestialBody::getY() const { return y; }
const float CelestialBody::getVx() const { return vx; };
const float CelestialBody::getVy() const { return vy; };
const v CelestialBody::getRealV() const { return realV; };
const float CelestialBody::getRealVx() const { return realVx; };
const float CelestialBody::getRealVy() const { return realVy; };
const sf::Color CelestialBody::getColor() const { return color; }

void CelestialBody::setRadius(float mass) { this->radius = radius; }
void CelestialBody::setMass(uint64_t mass) { this->mass = mass; }
void CelestialBody::setX(float x) { this->x = x; }
void CelestialBody::setY(float y) { this->y = x; }
void CelestialBody::setVx(float vx) { this->vx = vx; };
void CelestialBody::setVy(float vy) { this->vy = vy; };
void CelestialBody::setRealV(v realV) { this->realV = realV; };
void CelestialBody::setRealVx(float realVx) { this->realVx = realVx; };
void CelestialBody::setRealVy(float realVy) { this->realVy = realVy; };
void CelestialBody::setColor(sf::Color color) { this->color = color; }