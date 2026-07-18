#include "Core/Camera.hpp"

Camera::Camera() {
	position = { 0., 0. };
	scale = Config::Camera::scale;
}

sf::Vector2f Camera::worldToScreen(double realX, double realY) const {
	float screenX = static_cast<float>((realX - position.x) * scale) + Config::Window::width / 2.f;
	float screenY = static_cast<float>((realY - position.y) * scale) + Config::Window::height / 2.f;
	return sf::Vector2f{ screenX, screenY };
}

sf::Vector2<double> Camera::screenToWorld(float pixelX, float pixelY) const {
	double realX = (pixelX - Config::Window::width) / scale + position.x;
	double realY = (pixelY - Config::Window::height) / scale + position.y;
	return sf::Vector2<double>{realX, realY};
}

void Camera::zoom(float delta) {
	if (delta > 0)
		scale *= 1.;
	else if (delta < 0)
		scale /= 1.;
}