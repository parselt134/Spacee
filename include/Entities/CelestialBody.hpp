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
	sf::Vector2f realV;  // Velocity
	sf::Color color;

public:
	CelestialBody(float radius, double mass, float x, float y, sf::Vector2f realV, sf::Color color) : 
		radius(radius),
		mass(mass),
		x(x),
		y(y),
		realV(realV),
		color(color)
	{ }
	virtual ~CelestialBody() = default;
	virtual void draw(sf::RenderWindow& window) const = 0;
	virtual void update() = 0;

	const float getRadius() const;
	const uint64_t getMass() const;
	const float getX() const;
	const float getY() const;
	const sf::Vector2f getRealV() const;
	const sf::Color getColor() const;

	void setRadius(float mass);
	void setMass(uint64_t mass);
	void setX(float x);
	void setY(float y);
	void setRealV(sf::Vector2f realV);
	void setColor(sf::Color color);
};