#include <stdio.h>
#include <math.h>

#include <stdlib.h>
#include <time.h>

#include <unistd.h>

#define PRIMARYNETWORKS 2
#define PRIMARYCONVOLUTIONS 10
#define PRIMARYNEURONS 20
#define DAYSMEMORY 10

int day = 0; // day 0 = january 1st 2010

char dataSet_primary1[PRIMARYCONVOLUTIONS][100] =

{{ // stocks

"LIT.csv","NIO.csv","TSLA.csv", "CHPT.csv", "XPEV.csv", "DRIV.csv", "BLNK.csv", "FORD.csv", "EVGO.csv", "VOO.csv"

},{ //keywords

"lithium.csv", "nio.csv", "tesla.csv", "chargepoint.csv","xpeng.csv",
"electric vehicle.csv", "blink.csv", "ford.csv", "evgo.csv", "mercedes.csv",
"batteries.csv", "TSLAkey.csv", "solar.csv", "environment.csv", "carbon.csv",
"carbon credits.csv", "lithium-ion", "EV market.csv", "electric car.csv", "combustion engine.csv"

}};



void main(void)
{

	//download all data

	return EXIT_SUCCESS;
}
