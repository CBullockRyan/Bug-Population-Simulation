#ifndef DOODLE_H
#define DOODLE_H
#include <iostream>
#include "critters.h"
using namespace std;

class doodle: public critters{
	public:
		doodle();
		void move(int&, int&, critters**);
		void breed(int, int, int, int, critters**);
		bool eat(int, int, critters**);
		void die(bool, int, int, critters**);
};

#endif