#pragma once
#include "Entities/CelestialBody.hpp"
#include "Core/BaseFunctions.hpp"

class Star : public CelestialBody {
private:
    sf::CircleShape shape;

	void setShape();

public:
    Star(float radius, double mass, float x, float y, sf::Vector2f realV, sf::Color color);

	void update() override {  // TODO: trail
        //float offsetX = sinf(degreesToRadians(this->realV.direction)) * (realV.length * Config::Coefs::velocity);
        //float offsetY = cosf(degreesToRadians(this->realV.direction)) * (realV.length * Config::Coefs::velocity);
        float offsetX = realV.x * Config::Coefs::velocity;
        float offsetY = realV.y * Config::Coefs::velocity;
        //double R = 
        //realV.length = sqrt(Config::Coefs::G * (Config::CB::Mercury::mass / Config::CB::Mercury::));
        shape.move(sf::Vector2f(offsetX, -offsetY));
	}

	virtual void draw(sf::RenderWindow& window) const {
		window.draw(shape);
	}

    void pulse();  // TODO
};