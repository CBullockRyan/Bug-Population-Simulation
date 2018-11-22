#ifndef CRITTERS_H
#define CRITTERS_H
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class critters{
	protected:
		bool movement;
		int eat_ctr;
		int breed_ctr;
		string type;
	public:
		void setEat(int);
		void setBreed(int);
		void setType(string);
		void setMovement(bool);
		bool getMovement() const {return movement;};
		int getEat() const {return eat_ctr;};
		int getBreed() const {return breed_ctr;};
		string getType() const {return type;};
};

#endif