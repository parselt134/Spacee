#pragma once
#include "Entities/CelestialBody.hpp"
#include "Core/BaseFunctions.hpp"

class Planet : public CelestialBody {
private:
    sf::CircleShape shape;

    void setShape();

public:
    Planet(double radius, double mass, double x, double y, sf::Vector2<double> realV, sf::Color color);

    virtual void update(float deltaTime) override {
        double offsetX = realV.x * static_cast<double>(deltaTime) * 100.; // time is accelerated 100-fold
        double offsetY = realV.y * static_cast<double>(deltaTime) * 100.; // time is accelerated 100-fold
        this->x += offsetX;
        this->y += offsetY;
        //double R = 
        //realV.length = sqrt(Config::Coefs::G * (Config::CB::Mercury::mass / Config::CB::Mercury::));
    }

    virtual void draw(sf::RenderWindow& window, const Camera& camera) override {
        sf::Vector2f pixelPos = camera.worldToScreen(this->x, this->y);
        shape.move(pixelPos);
        window.draw(shape);
    }

    virtual sf::Color getColor() const { return shape.getFillColor(); }
    virtual void setColor(sf::Color color) { shape.setFillColor(color); }

    void burst();  // TODO
};