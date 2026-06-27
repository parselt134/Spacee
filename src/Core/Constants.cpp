#include "Core/Constants.hpp"

double Config::Coefs::velocity() {
	static double value = Config::CB::Mercury::pixelV / Config::CB::Mercury::realV.length();  // 1.5 pixel/sec is 47.36 km/sec  (CB::Mercury::pixelV / CB::Mercury::realV.length())
	return value;
}
double Config::Coefs::aveDist() {
	static double value = Config::CB::Mercury::pixelAveDist / Config::CB::Mercury::circularOrbitRadius;  // 100 pixels is distance from the center of the Sun to the center of Mercury (CB::Mercury::pixelAveDist / CB::Mercury::circularOrbitRadius)
	return value;
}