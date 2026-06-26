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

	float calcGravityForce();
	float calcAcceleration();
	void drawBackground(sf::RenderWindow& window);

public:
	Space();
	//~Space() {
	//	for (auto body = bodies.begin(); body != bodies.end(); ++body) {
	//		delete *body;
	//	}
	//}

	void initializeSolarSystem();
	void drawSpace(sf::RenderWindow& window);
};