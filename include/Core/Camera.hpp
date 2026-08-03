#include <SFML/Graphics.hpp>
#include "Core/Constants.hpp"

class Camera {
private:
	sf::Vector2<double> position;  // meters
	double scale;

public:
	Camera();

	sf::Vector2f worldToScreen(double realX, double realY) const;

	sf::Vector2<double> screenToWorld(float pixelX, float pixelY) const;

	void zoom(float delta);

	void follow(double targetX, double targetY);

	void move(double deltaX, double deltaY);

	double getScale() const;
	float getRelScale() const;
};