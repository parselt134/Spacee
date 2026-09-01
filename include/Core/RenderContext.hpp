#pragma once
#include <SFML/Graphics.hpp>
//#include "imgui.h"
//#include "imgui-SFML.h"

class Camera;
class Space;
struct mouseStates;

struct RenderContext {
	sf::RenderWindow& window;
	Camera& camera;
	Space& space;
	mouseStates& mouseStates;
};