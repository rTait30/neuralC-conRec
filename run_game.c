#include <stdio.h>
#include <math.h>

#include <stdlib.h>
#include <time.h>

#include <unistd.h>



void print3D (float array[6][6][6], int neuronCount, int convCount, int dayMemory) {

//manually change array size (fix if possible)

	for (int neuron = 0; neuron < neuronCount; neuron++) {
	
		for (int conv = 0; conv < convCount; conv++) {
		
			for (int day = 0; day < dayMemory; day++) {
			
				printf("%lf, ", array[neuron][conv][day]);
			}	
			printf("\n");
		}
		printf("\n");
	}
}

void newDay (float array[6][6][6], int neuronCount, int convCount, int dayMemory) { 

//manually change array size (fix if possible)

	for (int neuron = neuronCount - 1; neuron > -1; neuron--) {
	
		for (int conv = convCount - 1; conv > -1; conv--) {
		
			for (int day = dayMemory - 1; day > 0; day--) {
			
				array[neuron][conv][day] = array[neuron][conv][day-1];
			}	
		}
	}
	
	for (int neuron = 0; neuron < neuronCount; neuron++) {
	
		for (int conv = 0; conv < convCount; conv++) {
		
			array[neuron][conv][0] = 0;
		}
	}
}

int main(void)
{

	//const int dayMemP = 3;

	
	
	int neuronCount = 6;
	int convCount = 6;
	int dayMemory = 6;
	
	float god[neuronCount][convCount][dayMemory]; //neuron, convolution, day
	
	//{{{1,2,3},{4,5,6},{7,8,9}},{{10,11,6},{13,14,15},{16,17,18}},{{19,20,21},{22,23,24},{25,26,27}},{{28,29,30},{31,32,33},{34,35,36}}};
	
	int count = 0;

	for (int neuron = 0; neuron < neuronCount; neuron++) {
	
		for (int conv = 0; conv < convCount; conv++) {
		
			for (int day = 0; day < dayMemory; day++) {
			
				god[neuron][conv][day] = count;
				
				count += 1;
			}
		}	
	}	
	
	print3D(god,neuronCount, convCount, dayMemory);
	
	newDay(god,neuronCount, convCount, dayMemory);
	
	print3D(god,neuronCount, convCount, dayMemory);
	

	return EXIT_SUCCESS;
}
