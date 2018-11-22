/*********************************************************************  
** Program Filename: doodle.cpp
** Author: Cassidy Bullock    
** Date: 7/10/2016  
** Description: This contains functions for the interactions of doodle objects
**				with their environments
** Input: takes in array for the environment and object locations
** Output:  changes the environment array
*********************************************************************/
#include <iostream>
#include "critters.h"
#include "doodle.h"
using namespace std;

/*********************************************************************  
** Function: doodle()  
** Description: constructor to initialize object data
** Parameters: none
** Pre-Conditions: object being created 
** Post-Conditions: new object is filled
*********************************************************************/
doodle::doodle(){
	eat_ctr=1;
	breed_ctr=1;
	type="doodle";
}

/*********************************************************************  
** Function: move  
** Description: moves doodlebug in random direction 
** Parameters: x and y location of object, environment 2d array
** Pre-Conditions: has initial position of object 
** Post-Conditions: moves object in directon if there is nothing in the
**					way and it won't go off the board, also iterates the 
**					counters
*********************************************************************/
void doodle::move(int& x, int& y, critters **environment){
	if(!environment[x][y].getMovement()){
	int direction=rand()%4;
	int temp_x, temp_y;
	if(direction==0){
		temp_x=x;
		temp_y=y-1;
	}
	else if(direction==1){
		temp_x=x+1;
		temp_y=y;
	}
	else if(direction==2){
		temp_x=x;
		temp_y=y+1;
	}
	else if(direction==3){
		temp_x=x-1;
		temp_y=y;
	}
	if(temp_x<0 || temp_x>19 || temp_y<0 || temp_y>19){
		return;
	}
	else if(environment[temp_x][temp_y].getType()=="doodle"){
		return;
	}
	else{
		if(environment[temp_x][temp_y].getType()=="ant"){
			cout<<"I ate"<<endl;
			environment[temp_x][temp_y].setEat(1);
		}
		else{
			environment[temp_x][temp_y].setEat((environment[x][y].getEat()+1));
		}
		environment[temp_x][temp_y].setMovement(1);
		environment[temp_x][temp_y].setType("doodle");
		environment[temp_x][temp_y].setBreed((environment[x][y].getBreed()+1));
		environment[x][y].setType("");
		x=temp_x;
		y=temp_y;
	}
	}
}

/*********************************************************************  
** Function: eat 
** Description: checks where eat counter is.
** Parameters: x and y location of object, 2d array of environment
** Pre-Conditions: object is counting time steps since it has eaten 
** Post-Conditions: returns true if the maximum timesteps have been 
**					taken without eating
*********************************************************************/
bool doodle::eat(int x, int y, critters **environment){
	if(environment[x][y].getEat()==3){
		return 1;
	}
	else{
		return 0;
	}
}

/*********************************************************************  
** Function: breed 
** Description: checks where breed counter is.
** Parameters: x and y location of object and previous location, 
**				2d array of environment
** Pre-Conditions: object is counting time steps since it has bred 
** Post-Conditions: creates new object in previous space and sets data
*********************************************************************/
void doodle::breed(int i, int j, int x, int y, critters **environment){
	if(environment[i][j].getBreed()==8){
		environment[i][j].setType("doodle");
		environment[i][j].setBreed(1);
		environment[x][y].setBreed(1);
		environment[i][j].setEat(1);
	}
}

/*********************************************************************  
** Function: die 
** Description: checks whether object is dead and removes it from board
** Parameters: x and y location of object, and boolean stillAlive 
**				2d array of environment
** Pre-Conditions: object is not alive 
** Post-Conditions: removes object from board
*********************************************************************/
void doodle::die(bool stillAlive, int x, int y, critters** environment){
	if(stillAlive==1){
		environment[x][y].setType("");
	}
}