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
		inline constexpr double AU_TO_M = 149597870.7 * 1000.  ;  // m     (1.496E-11)
		inline constexpr double EM_TO_KG = 5.972E24;
		inline constexpr double timeAcceleration = 1E6;
		// deprecated functions
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
			inline const std::string name = "Sun";
			
			inline constexpr double startRealX = 0.;
			inline constexpr double startRealY = 0.;
			
			inline const sf::Vector2<double> realV = sf::Vector2<double>(0., sf::Angle(sf::degrees(0.f)));  // {km per s, degrees}

			inline constexpr double mass = 332950.;  // Earth masses

			inline constexpr double realR = 695500.;  // km
			inline constexpr float pixelRadius = 25.f;
			inline constexpr float minPixelRadius = 9.f;

			inline const sf::Color color(243, 159, 24);
		}
		namespace Mercury {
			inline const std::string name = "Mercury";
			
			inline constexpr double aphelion = 0.466697;  // au
			inline constexpr double perihelion = 0.307499;  // au
			inline constexpr double semiMajorAxis = 0.38709821f;  // au (circular orbit)

			inline constexpr double startRealX = 0.;
			inline constexpr double startRealY = semiMajorAxis * Coefs::AU_TO_M;  // m

			inline const sf::Vector2<double> aphelionVelocity = sf::Vector2<double>(38.7 * 1000., sf::Angle(sf::degrees(0.f)));  // {m per s, degrees}
			inline const sf::Vector2<double> perihelionVelocity = sf::Vector2<double>(56.6 * 1000., sf::Angle(sf::degrees(0.f)));  // {m per s, degrees}
			inline const sf::Vector2<double> semiMajorAxisVelocity = sf::Vector2<double>(47.36 * 1000., sf::Angle(sf::degrees(0.f)));  // {m per s, degrees}

			inline constexpr double mass = 0.055;  // Earth masses

			inline constexpr double realR = 2440.f;  // km
			inline constexpr float pixelRadius = 10.f;
			inline constexpr float minPixelRadius = 3.f;

			inline const sf::Color color(125, 81, 45);
		}
		namespace Venus {
			inline const std::string name = "Venus";

			inline constexpr double aphelion = 0.728213;  // au
			inline constexpr double perihelion = 0.718440;  // au
			inline constexpr double semiMajorAxis = 0.723332;  // au (circular orbit)

			inline constexpr double startRealX = 0.;
			inline constexpr double startRealY = semiMajorAxis * Coefs::AU_TO_M;  // m

			inline const sf::Vector2<double> aphelionVelocity = sf::Vector2<double>(35.78 * 1000., sf::Angle(sf::degrees(0.f)));  // {m per s, degrees}
			inline const sf::Vector2<double> perihelionVelocity = sf::Vector2<double>(35.26 * 1000., sf::Angle(sf::degrees(0.f)));  // {m per s, degrees}
			inline const sf::Vector2<double> semiMajorAxisVelocity = sf::Vector2<double>(35.02 * 1000., sf::Angle(sf::degrees(0.f)) );  // {m per s, degrees}
			
			inline constexpr double mass = 0.815;  // Earth masses

			inline constexpr double realR = 6052.;  // km
			inline constexpr float pixelRadius = 15.f;
			inline constexpr float minPixelRadius = 4.f;

			inline const sf::Color color(236, 124, 38);
		}
		namespace Earth {
			inline const std::string name = "Earth";

			inline constexpr double aphelion = 1.0167;  // au
			inline constexpr double perihelion = 0.9833;  // au
			inline constexpr double semiMajorAxis = 1.;  // au (circular orbit)

			inline constexpr double startRealX = 0.;
			inline constexpr double startRealY = semiMajorAxis * Coefs::AU_TO_M;  // m

			inline const sf::Vector2<double> aphelionVelocity = sf::Vector2<double>(29.29 * 1000., sf::Angle(sf::degrees(0.f)));  // {m per s, degrees}
			inline const sf::Vector2<double> perihelionVelocity = sf::Vector2<double>(30.29 * 1000., sf::Angle(sf::degrees(0.f)));  // {m per s, degrees}
			inline const sf::Vector2<double> semiMajorAxisVelocity = sf::Vector2<double>(29.76 * 1000., sf::Angle(sf::degrees(0.f)));  // {m per s, degrees}
			
			inline constexpr double mass = 1.;  // Earth masses

			inline constexpr double realR = 6371.0;  // km
			inline constexpr float pixelRadius = 15.f;
			inline constexpr float minPixelRadius = 4.f;

			inline constexpr sf::Color color(107, 147, 214);
		}

		namespace Mars {
			inline const std::string name = "Mars";

			inline constexpr double aphelion = 1.666;  // au
			inline constexpr double perihelion = 1.381;  // au
			inline constexpr double semiMajorAxis = 1.52;  // au (circular orbit)

			inline constexpr double startRealX = 0.;
			inline constexpr double startRealY = semiMajorAxis * Coefs::AU_TO_M;  // m

			inline const sf::Vector2<double> aphelionVelocity = sf::Vector2<double>(22.0 * 1000., sf::Angle(sf::degrees(0.f)));  // {m per s, degrees}
			inline const sf::Vector2<double> perihelionVelocity = sf::Vector2<double>(26.5 * 1000., sf::Angle(sf::degrees(0.f)));  // {m per s, degrees}
			inline const sf::Vector2<double> semiMajorAxisVelocity = sf::Vector2<double>(24.13 * 1000., sf::Angle(sf::degrees(0.f)));  // {m per s, degrees}

			inline constexpr double mass = 0.107;  // Earth masses

			inline constexpr double realR = 3389.5;  // km
			inline constexpr float pixelRadius = 12.f;
			inline constexpr float minPixelRadius = 4.f;

			inline constexpr sf::Color color(193, 68, 14);
		}
	}

	namespace Camera {
		inline constexpr double targetPixels = 100.;  // between Sun and Mercury
		inline const double scale = targetPixels / (Config::CB::Mercury::semiMajorAxis * Config::Coefs::AU_TO_M);  //  px/m
		inline constexpr float minRelScale = 0.4f;
		inline constexpr float maxRelScale = 35.f;
	}
}