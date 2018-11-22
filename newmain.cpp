/*********************************************************************  
** Program Filename: newmain.cpp 
** Author: Cassidy Bullock    
** Date: 7/10/2016  
** Description: runs a predator prey simulation on a 20 by 20 grid
** Input: none
** Output:  none
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include "critters.h"
#include "ants.h"
#include "doodle.h"
using namespace std;

/*********************************************************************  
** Function: create_ant  
** Description: creates and returns new ant
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: new ant is created
*********************************************************************/
ants create_ant(){
	ants x;
	return x;
}

/*********************************************************************  
** Function: create_doodle  
** Description: creates and returns new doodlebug
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: new doodlebug is created
*********************************************************************/
doodle create_doodle(){
	doodle x;
	return x;
}

/*********************************************************************  
** Function: init_board  
** Description: generates all of the original ant and doodlebug objects
** Parameters: 2d environment
** Pre-Conditions: none
** Post-Conditions: board is filled with all initial objects
*********************************************************************/
void init_board(critters **environment){
	for(int i=0; i<200; i++){				//number of starting ants
		int x;
		int y;
		bool flag=0;
		while(!flag){
			x=rand()%20;
			y=rand()%20;
			if(environment[x][y].getType()==""){
				environment[x][y]=create_ant();
				flag=1;
			}
		}
	}
	for(int i=0; i<10; i++){			//number of starting doodlebugs
		int x;
		int y;
		bool flag=0;
		while(!flag){
			x=rand()%20;
			y=rand()%20;
			if(environment[x][y].getType()==""){
				environment[x][y]=create_doodle();
				flag=1;
			}
		}
	}
}

/*********************************************************************  
** Function: print_board  
** Description: displays current positions of all objects
** Parameters: 2d environment
** Pre-Conditions: none
** Post-Conditions: prints the board
*********************************************************************/
void print_board(critters **environment){
	for(int i=0; i<20; i++){
		for(int j=0; j<20; j++){
			if(environment[i][j].getType()=="ant"){
				cout<<"* ";
			}
			else if(environment[i][j].getType()=="doodle"){
				cout<<"# ";
			}
			else{
				cout<<"  ";
			}
		}
		cout<<endl;
	}
}

/*********************************************************************  
** Function: resetMove
** Description: resets whether or not all objects have moved to false
**				between time steps
** Parameters: 2d environment
** Pre-Conditions: objects have been moved and have movement as true
** Post-Conditions: all objects are reset to having not been moved
*********************************************************************/
void resetMove(critters **environment){
	for(int i=0; i<20; i++){
		for(int j=0; j<20; j++){
			environment[i][j].setMovement(0);
		}
	}
}

int main(){
	srand(time(NULL));
	critters **environment = new critters*[20];
	for(int i=0; i<20; i++){
		environment[i]= new critters[20];
	}
	ants A_action;
	doodle D_action;
	int x=-1;
	int y;
	init_board(environment);
	resetMove(environment);
	print_board(environment);
	for(int k=0; k<100; k++){ 				//number of time steps
		resetMove(environment);
		for(int i=0; i<20; i++){
			for(int j=0; j<20; j++){
				x=i;
				y=j;
				if(environment[i][j].getType()=="ant"){
					A_action.move(x, y, environment);
				//cout<<"I have finished moving, I will now check my eat status"<<endl;
					bool stillAlive=A_action.eat(x, y, environment);
				//cout<<"My eat counter is at "<<environment[x][y].getEat()<<endl;
				//cout<<"My breed counter is at "<<environment[i][j].getBreed()<<endl;
					A_action.breed(i, j, x, y, environment);
					A_action.die(stillAlive, x, y, environment);
				}
				else if(environment[i][j].getType()=="doodle"){					D_action.move(x, y, environment);
					bool stillAlive=D_action.eat(x, y, environment);
					D_action.breed(i, j, x, y, environment);
					D_action.die(stillAlive, x, y, environment);
				}
			}
		}
		cout<<"New configuration: "<<endl;
		print_board(environment);
	}
	return 0;
}