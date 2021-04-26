#ifndef SHUTTLE_H
#define SHUTTLE_H


#include <iostream>
#include <vector>


const int DESTINATION = 23;
const int EMPTY = 0;
const int FUEL_CAPACITY = 15;
const int FUEL_STORAGE = 45;
const int HOME = 0;
const int USAGE_RATE = 1;


class Shuttle {
	std::vector<int> cache;
	int fuel = EMPTY;
	int pos = HOME;
public:
	Shuttle();
	std::vector<int> getCache() const;
	int getFuel() const;
	void refuel(int fuel);
	void vent(int fuel);
	int getPos() const;
	void forward(int distance);
	void backward(int distance);
};


std::ostream &operator<<(std::ostream &out, const Shuttle &s);


#endif
