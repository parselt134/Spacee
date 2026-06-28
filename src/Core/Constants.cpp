#include "Core/Constants.hpp"

float Config::Coefs::velocity() {  // px per sec To km per sec
	static float value = Config::CB::Mercury::pixelV / Config::CB::Mercury::realV.length();  // 1.5 pixel/sec is 47.36 km/sec  (CB::Mercury::pixelV / CB::Mercury::realV.length())
	return value;
}
float Config::Coefs::auToPixels() {  // multiply to get in pixels
	static float value = Config::CB::Mercury::pixelAveDist / Config::CB::Mercury::circularOrbitRadius;  // 100 pixels is distance from the center of the Sun to the center of Mercury (CB::Mercury::pixelAveDist / CB::Mercury::circularOrbitRadius)
	return value;
}

float Config::Coefs::pixelsToAu() {
	static float value = Config::CB::Mercury::circularOrbitRadius / Config::CB::Mercury::pixelAveDist;  // distance from the center of the Sun to the center of Mercury is 100 pixels (CB::Mercury::circularOrbitRadius / CB::Mercury::pixelAveDist)
	return value;
}

float Config::Coefs::kmToPixels() {
	static float value = Config::Coefs::kmToAu() * Config::Coefs::auToPixels();  // 100 pixels is distance from the center of the Sun to the center of Mercury (CB::Mercury::pixelAveDist / CB::Mercury::circularOrbitRadius)
	return value;
}

float Config::Coefs::pixelsToKm() {
	static float value = pixelsToAu() * auToKm();
	return value;
}

float Config::Coefs::auToKm() {
	static float value = 149597870.7f;
	return value;
}

float Config::Coefs::kmToAu() {
	static float value = 6.6845871226706E-09f;
	return value;
}

float Config::Coefs::emToKg() {
	static float value = 5.972E24f;
	return value;
}

float Config::Coefs::kgToEm() {
	static float value = 1.67E-25f;
	return value;
}