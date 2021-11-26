#include <stdio.h>
#include <math.h>

#include <stdlib.h>
#include <time.h>

#include <unistd.h>



int scoreNetwork(int startDay, int endDay, data, network parameters) {

	float state[PRIMARYNETWORKS][PRIMARYCONVOLUTIONS][PRIMARYNEURONS][DAYSMEMORY];
	
	for (int day = startDay; day < endDay; day++) {
	

		fullNet(PRIMARYNETWORKS,PRIMARYCONVOLUTIONS,PRIMARYNEURONS,DAYSMEMORY,state, data);
		
		runGame();
		
		newDay()
		
	}
	
	return score
	
}

void main(void) {

	//specify network paramaters
	
	scoreNetwork(

}
