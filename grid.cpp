#include <iostream>
#include "grid.h"
#include "Critter.h"
#include "Ant.h"
#include "Doodlebug.h"
using namespace std;

void grid::clearEnviron(){
	for(int i=0; i<20; i++){
		for(int j=0; j<20; j++){
			environment[i][j]=' ';
		}
	}
}

void grid::printEnviron(){
	cout<<"Updated environment:"<<endl;
	
	for(int i=0; i<20; i++){
		for(int j=0; j<20; j++){
			cout<<environment[i][j]<<"  ";
		}
		cout<<endl;
	}
}

void grid::updateEnviron(){
	clearEnviron();
	for(int i=0; i<count_A; i++){
		environment[array_a[i].x_loc][array_a[i].y_loc]='*';
	}
	for(int i=0; i<count_DB; i++){
		environment[array_db[i].x_loc][array_db[i].y_loc]='#';
	}
}

grid::grid(){
	environment = new char*[20];
		for(int i=0; i<20; i++){
			environment[i]= new char[20];
		}
	clearEnviron();
}