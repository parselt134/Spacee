#include "Core/BaseFunctions.hpp"

inline static bool areEqual(float a, float b, float epsilon) {
    return static_cast<bool>(abs(a - b) < epsilon);
}

float degreesToRadians(float degrees) {
    return static_cast<float>(degrees * 3.1415f / 180.f);
}