#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "Core/Constants.hpp"
#include "Core/BaseFunctions.hpp"
#include "Core/Camera.hpp"

class CelestialBody {
protected:
	std::string name;
	double radius;
	double mass;
	double x;  // real
	double y;  // real
	sf::Vector2<double> realV;  // Velocity
	sf::Color color;

public:
	CelestialBody(std::string name, double radius, double mass, double x, double y, sf::Vector2<double> realV, sf::Color color) : 
		name(name),
		radius(radius),
		mass(mass),
		x(x),
		y(y),
		realV(realV),
		color(color)
	{ }
	virtual ~CelestialBody() = default;
	virtual void draw(sf::RenderWindow& window, const Camera& camera) = 0;
	virtual void update(double acceleratedDt) = 0;

	const std::string getName() const;
	const double getRadius() const;
	const double getMass() const;
	const double getX() const;
	const double getY() const;
	const sf::Vector2<double> getRealV() const;
	const sf::Color getColor() const;

	void setName(std::string name);
	void setRadius(double mass);
	void setMass(double mass);
	void setX(double x);
	void setY(double y);
	void setRealV(sf::Vector2<double> realV);
	void setColor(sf::Color color);
};