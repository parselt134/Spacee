#include <SFML/Graphics.hpp>
#include "Core/Constants.hpp"

class Camera {
private:
	sf::Vector2<double> position;
	double scale;

public:
	Camera();

	sf::Vector2f worldToScreen(double realX, double realY) const;

	sf::Vector2<double> screenToWorld(float pixelX, float pixelY) const;

	void zoom(float delta);
};