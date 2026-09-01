#pragma once
#include <SFML/Graphics.hpp>

class CelestialBody;

#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <numbers>

inline static bool areEqual(float a, float b, float epsilon = 0.0001);

float degToRad(float degrees);
float radToDeg(float radians);

double normalizeDegrees(double degrees);

sf::Angle argumentOfVelocityAtTrueAnomaly(double longitude, double eccentricity, double longitudePerihelion);


enum class Unit { Meter, Kilometer, Au, Kilogram, Em, Mps, Aps};
std::string formatDouble(double number, Unit unit);

double distanseFromStar(const CelestialBody& star, const CelestialBody& anotherCb);