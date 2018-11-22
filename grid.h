#ifndef GRID_H
#define GRID_H
#include <iostream>
#include "Critter.h"
#include "Ant.h"
#include "Doodlebug.h"

class grid{
protected:
	char **environment;
public:
	int count_A=5;
	int count_DB=5;
	grid();
	void clearEnviron();
	void printEnviron();
	void updateEnviron();
	Critter actions;
	Ant array_a[400];
	Doodlebug array_db[400];
};

#endif