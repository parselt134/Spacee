#include <iostream>
#include <numbers>
#include "Core/BaseFunctions.hpp"

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