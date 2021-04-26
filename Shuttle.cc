#include "Shuttle.h"
using namespace std;


Shuttle::Shuttle() {
	cache.resize(DESTINATION - HOME + 1);
	cache[0] = FUEL_STORAGE;
}


vector<int> Shuttle::getCache() const {
	return cache;
}


int Shuttle::getFuel() const {
	return fuel;
}


void Shuttle::refuel(int fuel) {
	this->fuel += fuel;
	cache[pos] -= fuel;
	return;
}


void Shuttle::vent(int fuel) {
	this->fuel -= fuel;
	cache[pos] += fuel;
	return;
}


int Shuttle::getPos() const {
	return pos;
}


void Shuttle::forward(int distance) {
	pos += distance;
	fuel -= distance * USAGE_RATE;
	return;
}


void Shuttle::backward(int distance) {
	pos -= distance;
	fuel -= distance * USAGE_RATE;
	return;
}


ostream &operator<<(ostream &out, const Shuttle &s) {
	out << "SHUTTLE:" << endl;
	out << "DISTANCE FROM HOME BASE: " << s.getPos() << endl;
	out << "DISTANCE TO DESTINATION: " << DESTINATION - s.getPos()<< endl;
	out << "FUEL REMAINING IN TANK: " << s.getFuel() << endl;
	out << "AMOUNT OF FUEL AT CACHE: " << s.getCache()[s.getPos()] << endl;
	return out;
}
