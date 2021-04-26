#include <iostream>
#include "Shuttle.h"
using namespace std;


const string REFUEL = "refuel";
const string VENT = "vent";
const string FORWARD = "forward";
const string BACKWARD = "backward";
const string QUIT = "quit";


void intro() {
	cout << "You are embroiled in an intergalactic race to get to ";
	cout << "an abandoned alien base, located " << DESTINATION;
	cout << " parsecs from home base, with only empty space ";
	cout << "between home base and the alien base." << endl;
	cout << endl;
	cout << "Your space shuttle consumes " << USAGE_RATE;
	cout << " unit(s) of dark matter fuel per parsec, and can only ";
	cout << "hold up to ";
	cout << FUEL_CAPACITY << " unit(s) of fuel." << endl;
	cout << endl;
	cout << "However, dark matter fuel is stable in deep space, ";
	cout << "so you can vent a cache of any whole number of units of ";
	cout << "fuel anywhere (including home base) and pick it up ";
	cout << "later." << endl;
	cout << endl;
	cout << "You have been granted access to all " << FUEL_STORAGE;
	cout << " unit(s) of fuel in your location." << endl;
	cout << endl;
	cout << "Your goal is to get to the alien base." << endl;
	cout << endl;
	cout << "You may travel any whole number of parsecs in one run.";
	cout << endl;
	cout << endl;
	cout << "You must stay between home base and the alien base." << endl;
	cout << endl;
	return;
}


int main() {
	intro();
	Shuttle s;
	cout << s;
	bool quit = false;
	while (true) {
		cout << "Enter one of the following commands." << endl;
		cout << REFUEL << " n: add n units of fuel to your tank";
		cout << endl;
		cout << VENT << " n: vent n units of fuel from your tank";
		cout << endl;
		cout << FORWARD << " n: move n units towards the alien base";
		cout << endl;
		cout << BACKWARD << " n: move n units towards home base";
		cout << endl;
		cout << QUIT << ": quit the game" << endl;
		string cmd = "";
		int num = 0;
		cin >> cmd;
		if (cmd == REFUEL) {
			cin >> num;
			if (s.getFuel() + num > FUEL_CAPACITY) {
				cout << "Your fuel tank does not have ";
				cout << "enough space for that much fuel.";
				cout << endl;
			} else if (num > s.getCache()[s.getPos()]) {
				cout << "There is not enough fuel at ";
				cout << " this cache site." << endl;
			} else {
				// valid move
				s.refuel(num);
			}
		} else if (cmd == VENT) {
			cin >> num;
			if (s.getFuel() - num < EMPTY) {
				cout << "You may not vent more fuel than ";
				cout << " is left in your tank." << endl;
			} else {
				// valid move
				s.vent(num);
			}
		} else if (cmd == FORWARD) {
			cin >> num;
			if (s.getPos() + num > DESTINATION) {
				cout << "You are visiting an invalid ";
				cout << "location." << endl;
			} else if (num > s.getFuel()) {
				cout << "You do not have enough fuel to ";
				cout << "go that far." << endl;
			} else {
				// valid move
				s.forward(num);
			}
		} else if (cmd == BACKWARD) {
			cin >> num;
			if (s.getPos() - num < HOME) {
				cout << "You are visiting an invalid ";
				cout << "location." << endl;
			} else if (num > s.getFuel()) {
				cout << "You do not have enough fuel to ";
				cout << "go that far." << endl;
			} else {
				// valid move
				s.backward(num);
			}
		} else if (cmd == QUIT) {
			quit = true;
			break;
		} else {
			cout << "Invalid Command" << endl;
		}
		cout << s;
		if (s.getPos() == DESTINATION || 
				(s.getFuel() == EMPTY && 
				 s.getCache()[s.getPos()] == EMPTY)) {
			break;
		}
	}
	if (!quit && s.getPos() == DESTINATION) {
		cout << "CONGRATULATIONS! You made it to the alien base!";
		cout << endl;
	} else if (!quit && s.getPos() != DESTINATION) {
		cout << "OH NO! You ran out of fuel!" << endl;
	}
	return 0;
}
