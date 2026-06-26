#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

typedef struct  {
	float length;
	float direction;  // angle between axis X and vector itself (degrees)
} v;

namespace Config {
	namespace Window {
		inline constexpr uint64_t height = 800;
		inline constexpr uint64_t width = 800;
		inline constexpr sf::Color backgroundColor(51, 31, 61);
		inline constexpr float fps = 60.f;

		inline constexpr uint64_t starsSeed = 42;
		inline constexpr uint64_t starsCount = 500;
		inline constexpr uint64_t maxStarsRadius = 2;  // px
		inline const std::vector<sf::Color> startStarsColor{ sf::Color(255, 255, 255) };
	}

	namespace Resolution {
		inline constexpr float height = 1080.f;
		inline constexpr float width = 1920.f;
	}

	namespace CB {
		namespace Sun {
			inline constexpr float startX = static_cast<float>(Window::height) / 2.f;
			inline constexpr float startY = static_cast<float>(Window::width) / 2.f;
			inline const sf::Vector2f realV = sf::Vector2f(0.f, sf::Angle(sf::degrees(0.f)));
			inline constexpr double mass = 332950.;  // Earth masses
			inline constexpr float  pixelRadius = 25.f;  // ???
			inline const sf::Color color(243, 159, 24);
		}
		namespace Mercury {
			inline constexpr float pixelV = 1.5f;  // ???
			inline const sf::Vector2f realV = sf::Vector2f(47.36f, sf::Angle(sf::degrees(0.f))); /// {km per s, degrees}
			inline constexpr double mass = 0.055;  // Earth masses
			inline constexpr float pixelRadius = 10.f;  // ???
			inline constexpr float aveDist = 0.378f;  // au
			inline constexpr float pixelAveDist = 100.f;  // ???
			inline constexpr float startX = Sun::startX;
			inline constexpr float startY = Sun::startY + Mercury::pixelAveDist + Mercury::pixelRadius;
			inline const sf::Color color(125, 81, 45);  // ???
		}
		//namespace Venus {
		//	inline constexpr float pixelV = 1.0f;  // ???
		//	inline constexpr v realV = { 35.02f, 45.f }; /// {km per s, degrees}
		//	inline constexpr double mass = 0.815;  // Earth masses
		//	inline constexpr float pixelRadius = 15.f;  // ???
		//	inline constexpr float aveDist = 0.723332f;  // au
		//	inline constexpr float pixelAveDist = 200.f;  // ???
		//	inline constexpr float startX = Sun::startX;
		//	inline constexpr float startY = Sun::startY + Venus::pixelAveDist + Venus::pixelRadius;
		//	inline const sf::Color color(236, 124, 38);
		//}
	}

	namespace Coefs {
		inline constexpr double G = 6.67E-11; // N*m^2/kg^2
		inline const double velocity = CB::Mercury::pixelV / CB::Mercury::realV.length();  // 1.5 pixel/sec is 47.36 km/sec  (CB::Mercury::pixelV / CB::Mercury::realV.length)
		inline constexpr double aveDist = CB::Mercury::pixelAveDist / CB::Mercury::aveDist;
	}
}