#include "Core/BaseFunctions.hpp"

#include "Entities/CelestialBody.hpp"
#include "Entities/Star.hpp"
#include "Entities/Planet.hpp"

inline static bool areEqual(float a, float b, float epsilon) {
    return static_cast<bool>(abs(a - b) < epsilon);
}

float degToRad(float degrees) {
    return static_cast<float>(degrees * std::numbers::pi / 180.);
}

float radToDeg(float radians) {
    return static_cast<float>(radians * (180. / std::numbers::pi));
}

double normalizeDegrees(double degrees) {
    if (degrees > 360.)
        return degrees - 360.;
    if (degrees < 0.)
        return degrees + 360.;
    return degrees;
}

sf::Angle argumentOfVelocityAtTrueAnomaly(double l, double e, double varpi) {
    double nu = l - varpi;

    double vx = -(sin(degToRad(varpi + nu)));
    double vy = e + cos(degToRad(varpi + nu));

    double alpha = atan2(vy, vx);

    return sf::Angle(sf::radians(alpha));
}

std::string formatDouble(double number, Unit unit) {
    std::ostringstream oss;
    oss.imbue(std::locale("en_US.UTF-8"));

    // distance
    if (unit == Unit::Meter || unit == Unit::Kilometer || unit == Unit::Au) {
        oss << std::fixed << std::setprecision(2) << number;
    }

    // velocity
    if (unit == Unit::Mps) {
        oss << std::fixed << std::setprecision(2) << number;
    }
    if (unit == Unit::Aps) {
        oss << std::fixed << std::setprecision(10) << number;
    }

    // mass
    if (unit == Unit::Kilogram) {
        oss << std::fixed << std::setprecision(2) << number;
    }
    if (unit == Unit::Em) {
        oss << std::fixed << std::setprecision(5) << number;
    }

    return oss.str();
}

double distanseFromStar(const CelestialBody& star, const CelestialBody& anotherCb) {
    double dx = abs(star.getX() - anotherCb.getX());
    double dy = abs(star.getY() - anotherCb.getY());
    return std::sqrt(dx * dx + dy * dy);
}