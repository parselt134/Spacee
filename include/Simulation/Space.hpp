#pragma once
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Simulation/BackgroundStars.hpp"
#include "Entities/CelestialBody.hpp"
#include "Entities/Star.hpp"
#include "Entities/Planet.hpp"

class Space {
private:
	// 0 - Sun, 1 - Mercury, 2 - Venus, etc.
	std::vector<std::unique_ptr<CelestialBody>> bodies;
	BackgroundStars stars;
	double timeAcceleration;

	void changeVelocities(double acceleratedDt);
	void drawBackground(sf::RenderWindow& window);

public:
	Space(double timeAcceleration);

	void initializeSolarSystem();
	void drawSpace(sf::RenderWindow& window, const Camera& camera, float deltaTime);

	const double getTimeAcceleration() const;
	void setTimeAcceleration(double timeAcceleration);
};