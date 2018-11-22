#ifndef ANTS_H
#define ANTS_H
#include <iostream>
#include <cstdlib>
#include <string>
#include "critters.h"
using namespace std;

class ants: public critters{
	public:
		ants();
		void move(int&, int&, critters**);
		void breed(int, int, int, int, critters**);
		bool eat(int, int, critters**);
		void die(bool, int, int, critters**);
};

#endif