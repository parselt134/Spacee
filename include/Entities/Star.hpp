#pragma once
#include "Entities/CelestialBody.hpp"
#include "Core/BaseFunctions.hpp"

class Star : public CelestialBody {
private:
    sf::CircleShape shape;

	void setShape();

public:
    Star(std::string name, float radius, float minRadius, double mass,
         double a, double b, sf::Vector2<double> realV, sf::Color color,
         CoordinateType type = CoordinateType::Ecliptic);

	virtual void update(double acceleratedDt) override {  // TODO: trail
        double offsetX = realV.x * acceleratedDt;
        double offsetY = realV.y * acceleratedDt;
        this->x += offsetX;
        this->y += offsetY;
	}

    virtual void draw(sf::RenderWindow& window, const Camera& camera) override {
        sf::Vector2f pixelPos = camera.worldToScreen(sf::Vector2<double>(this->x, this->y), window);

        float relativeScale = camera.getRelScale();

        float pixelRadius = this->getRadius() * relativeScale;
        pixelRadius = std::max(pixelRadius, this->minRadius);

        shape.setRadius(pixelRadius);
        shape.setOrigin({ pixelRadius, pixelRadius });
        shape.setPosition(pixelPos);
        window.draw(shape);
    }

    virtual bool isClicked(sf::Vector2f mouseCoords) override {
        sf::Vector2f center = shape.getPosition();
        sf::Vector2f delta = mouseCoords - center;

        float distanceSquare = delta.x * delta.x + delta.y * delta.y;
        float radiusSquare = shape.getRadius() * shape.getRadius();

        return distanceSquare <= radiusSquare;
    }

    virtual sf::Color getColor() const { return shape.getFillColor(); }
    virtual void setColor(sf::Color color) { shape.setFillColor(color); }

    void pulse();  // TODO
};