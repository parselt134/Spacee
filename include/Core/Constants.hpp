#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

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

	namespace Coefs {
		inline constexpr double G = 6.67E-11; // N*m^2/kg^2
		double velocity();
		double aveDist();
	}

	namespace CB {
		namespace Sun {
			inline constexpr float startX = static_cast<float>(Window::height) / 2.f;
			inline const float startY = static_cast<float>(Window::width) / 2.f;
			inline const sf::Vector2f realV = sf::Vector2f(0.f, sf::Angle(sf::degrees(0.f)));
			inline constexpr double mass = 332950.;  // Earth masses
			inline constexpr float realR = 695500.f;  // km
			inline constexpr float pixelRadius = 25.f;  // ???
			inline const sf::Color color(243, 159, 24);
		}
		namespace Mercury {
			inline const float pixelV = 1.5f;  // reference!
			inline const sf::Vector2f realV = sf::Vector2f(47.36f, sf::Angle(sf::degrees(0.f))); /// {km per s, degrees}
			inline constexpr double mass = 0.055;  // Earth masses
			inline constexpr float pixelRadius = 10.f;  // ???
			inline constexpr float circularOrbitRadius = 0.38709821f;  // au (circular orbit)
			inline constexpr float realR = 2440.f;  // km
			inline constexpr float pixelAveDist = 100.f;  // reference!
			inline constexpr float startX = Sun::startX;
			inline const float startY = Sun::startY + Mercury::pixelAveDist + Mercury::pixelRadius;
			inline const sf::Color color(125, 81, 45);  // ???
		}
		namespace Venus {
			//inline constexpr float pixelV = 1.0f;  // ???
			inline const sf::Vector2f realV = sf::Vector2f( 35.02f, sf::Angle(sf::degrees(0.f)) ); /// {km per s, degrees}
			inline constexpr double mass = 0.815;  // Earth masses
			inline constexpr float pixelRadius = 15.f;  // ???
			inline constexpr float circularOrbitRadius = 0.723332f;  // au (circular orbit)
			inline constexpr float realR = 6052.f;  // km
			//inline constexpr float pixelAveDist = 200.f;  // ???
			inline constexpr float startX = Sun::startX;
			inline const float startY = Sun::startY + (Venus::circularOrbitRadius * Config::Coefs::aveDist()) + Venus::pixelRadius;
			inline const sf::Color color(236, 124, 38);
		}
	}
}