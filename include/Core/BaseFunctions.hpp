#pragma once
#include "SFML/Graphics.hpp"
#include <memory>
#include <algorithm>
#include <cmath>

inline static bool areEqual(float a, float b, float epsilon = 0.0001);

float degToRad(float degrees);
float radToDeg(float radians);

double normalizeDegrees(double degrees);

sf::Angle argumentOfVelocityAtTrueAnomaly(double longitude, double eccentricity, double longitudePerihelion);