#include <SFML/Graphics.hpp>
#include "Core/Constants.hpp"

class Camera {
private:
	sf::Vector2<double> position;  // meters
	double scale;

public:
	Camera();

	sf::Vector2f worldToScreen(sf::Vector2<double> realCoords) const;

	sf::Vector2<double> screenToWorld(sf::Vector2f pixelCoords) const;

	void zoom(float delta);
	void zoom(float delta, sf::Vector2i mousePizelCoords);

	void follow(double targetX, double targetY);

	void move(double deltaX, double deltaY);

	const sf::Vector2<double> getPosition() const;
	const double getScale() const;
	const float getRelScale() const;  // relative scale is the scale relative to the initial scale (Config::Camera::scale)
};