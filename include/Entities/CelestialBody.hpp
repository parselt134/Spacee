#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "Core/Constants.hpp"
#include "Core/BaseFunctions.hpp"

class CelestialBody {
protected:
	float radius;
	double mass;
	float x;
	float y;
	float vx;
	float vy;
	v realV;
	float realVx;
	float realVy;
	sf::Color color;

public:
	CelestialBody(float radius, double mass, float x, float y, float vx, float vy, v realV, float realVx, float realVy, sf::Color color) : 
		radius(radius),
		mass(mass),
		x(x),
		y(y),
		vx(vx),
		vy(vy),
		realV(realV),
		realVx(realVx),
		realVy(realVy),
		color(color)
	{ }
	virtual ~CelestialBody() = default;
	virtual void draw(sf::RenderWindow& window) const = 0;
	virtual void update() = 0;

	const float getRadius() const;
	const uint64_t getMass() const;
	const float getX() const;
	const float getY() const;
	const float getVx() const;
	const float getVy() const;
	const v getRealV() const;
	const float getRealVx() const;
	const float getRealVy() const;
	const sf::Color getColor() const;

	void setRadius(float mass);
	void setMass(uint64_t mass);
	void setX(float x);
	void setY(float y);
	void setVx(float vx);
	void setVy(float vy);
	void setRealV(v realV);
	void setRealVx(float realVx);
	void setRealVy(float realVy);
	void setColor(sf::Color color);
};