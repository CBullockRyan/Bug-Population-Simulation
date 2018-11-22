/*********************************************************************  
** Program Filename: critters.cpp 
** Author: Cassidy Bullock    
** Date: 7/10/2016  
** Description: This contains counters and functions to get and set them
** Input: none
** Output:  none
*********************************************************************/
#include <iostream>
#include "critters.h"
using namespace std;

/*********************************************************************  
** Function: setEat
** Description: sets eat_ctr
** Parameters: integer
** Pre-Conditions: none
** Post-Conditions: sets eat_ctr
*********************************************************************/
void critters::setEat(int eat){
	eat_ctr=eat;
}

/*********************************************************************  
** Function: setBreed
** Description: sets breed_ctr
** Parameters: integer
** Pre-Conditions: none
** Post-Conditions: sets breed_ctr
*********************************************************************/
void critters::setBreed(int breed){
	breed_ctr=breed;
}

/*********************************************************************  
** Function: setEat
** Description: sets type of critter, ant or doodlebug
** Parameters: string
** Pre-Conditions: none
** Post-Conditions: sets type
*********************************************************************/
void critters::setType(string name){
	type=name;
}

/*********************************************************************  
** Function: setMovement
** Description: sets whether or not object has already moved
** Parameters: boolean
** Pre-Conditions: none
** Post-Conditions: sets movement
*********************************************************************/
void critters::setMovement(bool move){
	movement=move;
}