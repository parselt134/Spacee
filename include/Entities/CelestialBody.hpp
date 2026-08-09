#pragma once
#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Core/Constants.hpp"
#include "Core/BaseFunctions.hpp"
#include "Core/Camera.hpp"

class CelestialBody {
protected:
	std::string name;
	float radius;
	float minRadius;
	double mass;
	double x;  // real
	double y;  // real
	sf::Vector2<double> realV;  // velocity
	sf::Color color;

public:
	// heliocentric rectangular coordinate system
	CelestialBody(std::string name, float radius, float minRadius, double mass, double x, double y, sf::Vector2<double> realV, sf::Color color) :
		name(name),
		radius(radius),
		minRadius(minRadius),
		mass(mass),
		x(x),
		y(y),
		realV(realV),
		color(color)
	{ }

	// heliocentric ecliptic coordinate system
	//CelestialBody(std::string name, float radius, float minRadius, double mass, double longitude, double distance, sf::Vector2<double> realV, sf::Color color) {
	//	this->name = name;
	//	this->radius = radius;
	//	this->minRadius = minRadius;
	//	this->mass = mass;
	//	this->x = -distance * sin(longitude);
	//	this->y = -distance * cos(longitude);
	//	this->
	//}

	virtual ~CelestialBody() = default;
	virtual void update(double acceleratedDt) = 0;
	virtual void draw(sf::RenderWindow& window, const Camera& camera) = 0;
	virtual bool isClicked(sf::Vector2f mouseCoords) = 0;

	const std::string getName() const;
	const float getRadius() const;
	const float getMinRadius() const;
	const double getMass() const;
	const double getX() const;
	const double getY() const;
	const sf::Vector2<double> getRealV() const;
	const sf::Color getColor() const;

	void setName(std::string name);
	void setRadius(float radius);
	void setMinRadius(float minRadius);
	void setMass(double mass);
	void setX(double x);
	void setY(double y);
	void setRealV(sf::Vector2<double> realV);
	void setColor(sf::Color color);
};