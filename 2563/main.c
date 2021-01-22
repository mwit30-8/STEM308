#include "reader.h" // This module must be able to read the id of RFID in the hand
// int read(int hand); // read and wait for id

#include "arm.h" // This module must be able to grab and place the clothes to the curtain direction
// void pick(int hand, int dir); // pick object from hand at dir and wait (dir 0:front,1:right,2:back,3:left)
// void place(int hand, int dir); // place object from hand at dir and wait
// bool is_hand_done(int hand); // check if hand is avaliable (not useful since it was waited)

#include "wheel.h" // This module must be able to walk to whatever coordinate it was ordered
// void walk(int x); // walk forward x unit and wait
// void turn(int dir); // turn to dir and wait and remember the alias of position then calibate on each move in that axis
// bool is_arrived(); // check if current destination reached (not useful since it was waited)

#include "server.h" // This module must be able to connect the robot to the server with some error correction embed
// void send(int id, int key, int value); // send package from id using key and value
// int recieve(int id, int key); // request and wait for value of key

#define ID 1 // this parameter might be setted in setup with serial port later

void setup(){
	// whatever you want to initiate, do it here
}

void loop(){ // this is server based, since I was too lazy to program all (1) robot(s) each time I change the algorithm.
	int inst=recieve(ID, 0); // find command
	int order=inst%6; // 
	inst/=6; // 
	switch(order){
		case 0:
			break; // nop
		case 1:
			send(ID,1,read(inst));
			break; // read
		case 2:
			pick(inst/4,inst%4);
			break; // pick
		case 3:
			place(inst/4,inst%4);
			break; // place
		case 4:
			turn(inst%4);
			break; // turn
		case 5:
			move(inst);
			break; // move
		default:
			break;
	}
}
