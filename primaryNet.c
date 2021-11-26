#include <stdio.h>
#include <math.h>

#include <stdlib.h>
#include <time.h>

#include <unistd.h>

void run_neural (float array[20][10], int networkInputs, int neuronCount, int dayMemory, int neuronTypes[20], int neuronActivations[20], int inputNeurons[20][5], int inputDays[20][5], float inputWeights[20][5]);

void getAllData(float data[100][5]);

void print2D (float array[20][10], int neuronCount, int dayMemory) {

//manually change array size (fix if possible)

	printf("\n");

	for (int neuron = 0; neuron < neuronCount; neuron++) {
		
		for (int day = 0; day < dayMemory; day++) {
			
			printf("%.2f, ", array[neuron][day]);
		}
		printf("\n");
	}
}

void newDay (int day, float data[100][5], int networkInputs, float array[20][10], int neuronCount, int dayMemory) { 

//manually change array size (fix if possible)

	for (int neuron = neuronCount - 1; neuron > -1; neuron--) {
		
		for (int day = dayMemory - 1; day > 0; day--) {
			
			array[neuron][day] = array[neuron][day-1];
		}
	}
	
	for (int neuron = 0; neuron < neuronCount; neuron++) {
		
		array[neuron][0] = 0;
		
		if (neuron < networkInputs) {
		
			for (int dataIt = 0; dataIt < networkInputs; dataIt++) {
			
				array[dataIt][0] = data[day][dataIt];
			
			}
			
		}
	}
}

int main(void) //primaryConv
{

	//const int dayMemP = 3;

	
	
	int neuronCount = 20;
	int dayMemory = 10;
	
	float god[neuronCount][dayMemory]; //neuron, convolution, day
	
	//{{{1,2,3},{4,5,20},{7,8,9}},{{10,11,20},{13,14,15},{120,17,18}},{{19,20,21},{22,23,24},{25,220,27}},{{28,29,30},{31,32,33},{34,35,320}}};
	
	int count = 0;

	for (int neuron = 0; neuron < neuronCount; neuron++) {
		
		for (int day = 0; day < dayMemory; day++) {
			
			god[neuron][day] = count;
				
			count += 1;
		}	
	}
	
	int networkInputs = 5;
	
	int neuronTypes[20] = {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1};
	//0 add, 1 average
	
	int neuronActivations[20] = {0,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9};
	//0 identity, 1 binary step, 2 logistic, 3 tanh, 4 relu, 5 gelu, 6 softplus, 7 leaky relu, 8 silu, 9 mish, 10 gaussian
	
	int inputNeurons[20][5];
	
	int inputDays[20][5];
	
	float inputWeights[20][5];
	
	for (int neuron = 0; neuron < neuronCount; neuron++) {
		
		for (int input = 0; input < 5; input++) {
			
			inputNeurons[neuron][input] = 1;
			inputDays[neuron][input] = 1;
			inputWeights[neuron][input] = 1;
		}	
	}
	
	inputNeurons[4][0] = 4;
	
	inputWeights[4][0] = -1;
	inputWeights[4][1] = 0;
	inputWeights[4][2] = 0;
	inputWeights[4][3] = 0;
	inputWeights[4][4] = 0;
	
	
	
	print2D(god,neuronCount, dayMemory);
	
	int dayData = 0;
	
	float data[100][5];
	
	getAllData(data);
	
	for (int day = 0; day < 10; day++) {
	
		newDay(dayData, data, networkInputs, god,neuronCount, dayMemory);
		
		run_neural(god, networkInputs, neuronCount, dayMemory,neuronTypes,neuronActivations,inputNeurons,inputDays,inputWeights);
		
		//mutate_neural
		
		print2D(god,neuronCount, dayMemory);
		
		dayData += 1;
		
	}
	

	return EXIT_SUCCESS;
}
