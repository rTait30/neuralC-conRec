#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double * getAllData(int check, FILE* dates) {

    char str[128];
    int result;
    FILE* f = fopen("ford.csv", "r");

    int record = 0;

    static double data[300000];

    int dataIt = 0;
    
    
    
    
    
    
    do {      

        record += 1;  

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
                
                
                
                if ((record-1)/2 == check) {
                
                	printf("%s record %d\n", token, (record-1)/2);
                
                	printf("write token %s\n", token);
                
                	fprintf(dates, "%s,", token);
                
                

		            int count = 0;
		           
		            /* walk through other tokens */
		            while( token != NULL ) {

		                if (count > 0) {
		                
		                	fprintf(dates, "%s", token);
		                	
		                	if (count < 5) {fprintf(dates,",");}

		                    double value = atof(token);

		                    data[dataIt] = value;

		                    dataIt += 1;
		                    
		                }
		                
		                token = strtok(NULL, s);

		                count+= 1;
		            }
		            
		            fprintf(dates, ";\n");
                
                }
            }
        }

    } while(result != EOF);

    /*

    for (int i = 0; i < 70; i++) {

        printf("%f\n", data[i]);
    }

    */

    return data;
    
}

double * getSpecData(double data[2554], int day) {

    static double specData[21];

    for (int i = 0; i < 21; i++) {

        specData[i] = data[day*7+i];

    }

    return specData;

}



int main(void) {

    double *data;

    //open, high, low, close, volume, cap, day

    //data = getAllData();
    
    FILE *dates = fopen("dates.csv", "w");
    
    //fprintf(dates, "test3\n");
    
    //fprintf(dates, "test4\n");
    
    
    
    for (int write = 2922; write >= 2000; write--) {
    
    	getAllData(write, dates);
    
    }
    
    /*

    for (int i = 0; i < 2555; i++) {

        printf("%f\n", data[i]);
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
    
    */

    return EXIT_SUCCESS;
}




