#pragma once
#include <memory>
#include <algorithm>
#include <cmath>

inline static bool areEqual(float a, float b, float epsilon = 0.0001);

float degreesToRadians(float degrees);

//float findAngleDegrees(float x1, float y1, float x2, float y2);  // polar system