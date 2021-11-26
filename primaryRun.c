#include <stdio.h>
#include <math.h>

#include <stdlib.h>
#include <time.h>

#include <unistd.h>


void run_neural (float array[20][10], int networkInputs, int neuronCount, int dayMemory, int neuronTypes[20], int neuronActivations[20], int inputNeurons[20][5], int inputDays[20][5], float inputWeights[20][5]) {

	int count = 0;
	
	while (count < 1 && array[20][0] == 0) { //mulling
		
		for (int neuron = networkInputs; neuron < neuronCount; neuron++) {
		
			float tempNeuronValue = 0;
		
			for (int input = 0; input < 5; input++) {
		
				//process inputs
				
				int inputNeuron = inputNeurons[neuron][input];
				
				int inputDay = inputDays[neuron][input];
				
				float inputWeight = inputWeights[neuron][input];
				
				tempNeuronValue += array[inputNeuron][inputDay] * inputWeight;
			
			}
			
			if (neuronTypes[neuron] == 1) {tempNeuronValue *= 0.2;}
			
			//apply activation function
			
			int activationFunction = neuronActivations[neuron];
			
			//0 identity, 1 binary step, 2 logistic, 3 tanh, 4 relu, 5 gelu, 6 softplus, 7 leaky relu, 8 silu, 9 mish, 10 gaussian
			
			if (activationFunction == 1) {
			
				if (tempNeuronValue < 0) {tempNeuronValue = 0;}
				else {tempNeuronValue = 1;}
			
			} else if (activationFunction == 2) { // standard
			
				tempNeuronValue = 1/(1+expf(-tempNeuronValue));
			
			} else if (activationFunction == 3) {
			
				tempNeuronValue = 1;
			
			} else if (activationFunction == 4) {
			
			
			
			} else if (activationFunction == 5) {
			
			
			
			} else if (activationFunction == 6) {
			
			
			
			} else if (activationFunction == 7) {
			
			
			
			} else if (activationFunction == 8) {
			
			
			
			} else if (activationFunction == 9) {
			
			
			
			} else {
			
			}
			
			array[neuron][0] = tempNeuronValue;
		
		}
		
		count += 1;
	}
	
	//printf("%d\n", count);
}
