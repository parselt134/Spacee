#pragma once
#include <SFML/Graphics.hpp>
#include "CelestialBody.hpp"
#include "Core/BaseFunctions.hpp"
#include <iostream>

class Planet : public CelestialBody {
private:
    sf::CircleShape shape;

    void setShape();

public:
    Planet(float radius, double mass, float x, float y, sf::Vector2f realV, sf::Color color);

    void update() override {
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

    virtual sf::Color getColor() const { return shape.getFillColor(); }
    virtual void setColor(sf::Color color) { shape.setFillColor(color); }

    void burst();  // TODO
};