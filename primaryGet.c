#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getSingleData(float data[100][5], int startDay, endDay) {

    char str[128];
    int result;
    FILE* f = fopen("LIT.csv", "r");

    //int record = 0;

    //static double data[500];

    int dataIt = 0;
    
    
    do {      

        //record += 1;  

        result = fscanf(f, "%127[^;\n]", str);
        
        if(result == 0)
        {
            result = fscanf(f, "%*c");
        }
        else
        {

            //whatever you want to do with your value

            //if (record > (start+1) && record < (end*2+1)) {

            if (1) {

                //printf("\n%s\n\n", str);

                const char s[2] = ",";
                char *token;
               
                /* get the first token */
                token = strtok(str, s);

                int first = 1;
               
                /* walk through other tokens */
                while( token != NULL ) {

                    if (first == 0) {

                        float value = atof(token);

                        data[99 - (int) dataIt/5][dataIt%5] = value;

                        dataIt += 1;
                    }
                    
                    token = strtok(NULL, s);

                    first = 0;
                }
            }
        }

    } while(result != EOF && dataIt < 500);

    /*

    for (int i = 0; i < 70; i++) {

        printf("%f\n", data[i]);
    }

    */

    //return data;
    
}

/*

double * getSpecData(double data[2554], int day) {

    static double specData[21];

    for (int i = 0; i < 21; i++) {

        specData[i] = data[day*7+i];

    }

    return specData;

}



int main(void) {

    double data[100][5];

    //open, high, low, close, volume, cap, day

    getAllData(data);

    for (int i = 0; i < 100; i++) {

        printf("%f\n", data[i][0]);
    }

    

    double *specData;

    int test = 1;

    
    while (1) {

        printf("%d\n", test);

        specData = getSpecData(data, test);

        test += 1;

    }

    

    specData = getSpecData(data, 363);

    for (int i = 0; i < 14; i++) {

        printf("%f\n", specData[i]);
    }
    
    

    return EXIT_SUCCESS;
}

*/


for (int network = 0; network < primaryNetworks; network++) {
	
		printf("Network %d\n", network);
	
		for (int conv = 0; conv < primaryConvolutions; conv++) {
	
			printf("convolution %d: %s\n", conv, dataSets[network][conv]);
			
		}
	}

