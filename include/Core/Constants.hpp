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
		inline constexpr double G = 6.67430E-11; // N*m^2/kg^2   or   m^3/(kg*s^2)
		inline constexpr double Au = 149597870.7  * 1000.  ;  // m     (1.496E-11)
		float velocity();
		float auToPixels();
		float pixelsToAu();
		float pixelsToKm();
		float kmToPixels();
		float auToKm();
		float kmToAu();
		float emToKg();
		float kgToEm();
	}

	namespace CB {
		namespace Sun {
			inline constexpr float startX = static_cast<float>(Window::height) / 2.f;
			inline const float startY = static_cast<float>(Window::width) / 2.f;
			
			inline constexpr double startRealX = 0.;
			inline constexpr double startRealY = 0.;
			
			inline const sf::Vector2<double> realV = sf::Vector2<double>(0., sf::Angle(sf::degrees(0.f)));  // {km per s, degrees}
			inline constexpr double mass = 332950.f;  // Earth masses
			inline constexpr double realR = 695500.f;  // km
			inline constexpr float pixelRadius = 25.f;  // ???
			inline const sf::Color color(243, 159, 24);
		}
		namespace Mercury {
			inline const float pixelV = 1.5f;  // reference!
			inline const sf::Vector2<double> realV = sf::Vector2<double>(47.36, sf::Angle(sf::degrees(0.f)));  // {km per s, degrees}
			inline constexpr double mass = 0.055f;  // Earth masses
			inline constexpr float pixelRadius = 10.f;  // ???
			inline constexpr double circularOrbitRadius = 0.38709821f;  // au (circular orbit)
			inline constexpr double realR = 2440.f;  // km
			//inline constexpr float pixelAveDist = Camera::targetPixels;  // reference!
			//inline constexpr float startX = Sun::startX;
			//inline const float startY = Sun::startY + Mercury::pixelAveDist + Mercury::pixelRadius;

			inline constexpr double startRealX = 0.;
			inline constexpr double startRealY = circularOrbitRadius * Coefs::Au;  // m

			inline const sf::Color color(125, 81, 45);  // ???
		}

		namespace Venus {
			//inline constexpr float pixelV = 1.0f;  // ???
			inline const sf::Vector2<double> realV = sf::Vector2<double>( 35.02, sf::Angle(sf::degrees(0.f)) ); /// {km per s, degrees}
			inline constexpr double mass = 0.815f;  // Earth masses
			inline constexpr float pixelRadius = 15.f;  // ???
			inline constexpr double circularOrbitRadius = 0.723332;  // au (circular orbit)
			inline constexpr double realR = 6052.f;  // km
			//inline constexpr float pixelAveDist = 200.f;  // ???
			inline constexpr float startX = Sun::startX;
			inline const float startY = Sun::startY + (Venus::circularOrbitRadius * Config::Coefs::auToPixels()) + Venus::pixelRadius;

			inline constexpr double startRealX = 0.;
			inline constexpr double startRealY = circularOrbitRadius * Coefs::Au; // m

			inline const sf::Color color(236, 124, 38);
		}
	}

	namespace Camera {
		inline constexpr double targetPixels = 100.f;  // between Sun and Mercury
		inline const double scale = targetPixels / (Config::CB::Mercury::circularOrbitRadius * Config::Coefs::Au);  //  px/m
	}
}