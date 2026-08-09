#include "Core/Camera.hpp"

Camera::Camera() {
	position = { 0., 0. };
	scale = Config::Camera::scale;
	isFollowing = false;
	targetInd = 0;  // the first celestial object in space
}

sf::Vector2f Camera::worldToScreen(sf::Vector2<double> realCoords) const {
	double realX = realCoords.x;
	double realY = realCoords.y;

	float screenX = static_cast<float>((realX - position.x) * scale) + Config::Window::width / 2.f;
	float screenY = static_cast<float>((position.y - realY) * scale) + Config::Window::height / 2.f;
	return sf::Vector2f{ screenX, screenY };
}

sf::Vector2<double> Camera::screenToWorld(sf::Vector2f pixelCoords) const {
	float pixelX = pixelCoords.x;
	float pixelY = pixelCoords.y;

	double realX = (pixelX - Config::Window::width / 2.f) / scale + position.x;
	double realY =  position.y - (pixelY - Config::Window::height / 2.f) / scale;
	return sf::Vector2<double>{realX, realY};
}

void Camera::zoom(float delta) {

	float relativeScale = getRelScale();
	if ((relativeScale < Config::Camera::minRelScale && delta < 0) ||
		(relativeScale > Config::Camera::maxRelScale && delta > 0))
		return;

	if (delta > 0)
		scale *= 1.15;
	else if (delta < 0)
		scale /= 1.15;
}

void Camera::zoom(float delta, sf::Vector2i mousePizelCoords) {

	float relativeScale = getRelScale();
	if ((relativeScale < Config::Camera::minRelScale && delta < 0) ||
		(relativeScale > Config::Camera::maxRelScale && delta > 0))
		return;

	sf::Vector2<double> cursorPosBefore = screenToWorld(sf::Vector2f(mousePizelCoords));

	double oldScale = scale;

	if (delta > 0)
		scale *= 1.15;
	else if (delta < 0)
		scale /= 1.15;

	sf::Vector2<double> cursorPosAfter = screenToWorld(sf::Vector2f(mousePizelCoords));

	position += (cursorPosBefore - cursorPosAfter);
}

void Camera::follow(double targetX, double targetY) {
	position.x = targetX;
	position.y = targetY;
}

void Camera::move(double deltaX, double deltaY) {
	position.x += deltaX;
	position.y += deltaY;
}



const sf::Vector2<double> Camera::getPosition() const { return position; }
const double Camera::getScale() const { return scale; }
const float Camera::getRelScale() const { return static_cast<float>(scale / Config::Camera::scale); }
const bool Camera::getIsFollowing() const { return isFollowing; }
const int Camera::getTargetInd() const { return targetInd; }

void Camera::setIsFollowing(bool isFollowing) { this->isFollowing = isFollowing; }
void Camera::setTargetInd(int targetInd) { this->targetInd = targetInd; }