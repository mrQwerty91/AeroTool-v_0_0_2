/*
---------------AEROTOOL----------------
Tool per il calcolo dei parametri 
fondamentali di un aeromobile.
V 0.0.2
--- Designed by Stefano Quagliarella---
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float quota, velocita, superficie_alare, CoeffLift, aeroEff;
float lift, drag;
float t0 = 288.16;
float n = 1.23496;
float k = 0.0065;
float p0 = 1.225;
float tZ, pZ;

int scelta;

int uscita = 0;


int main() {
	printf("----------------- AEROTOOL v0.0.2 ----------\n");
	printf("   Benvenuto nel programma di calcolo dei   \n");
	printf("   parametri fondamentali di un aeromobile. \n\n");
	printf("I risultati sono da considerarsi in VORU in troposfera.\n\n");
	printf("Developed by Stefano Quagliarella\n\n\n");
	while(uscita!=1){
		printf("\nCosa vuoi fare? (Inserisci il numero della scelta)\n\n");
		printf("1- Inserimento dati del velivolo\n");
		printf("2- Calcolo della portanza\n");
		printf("3- Calcolo della resistenza aerodinamica\n");
		printf("4- Esci\n\n");
		printf("Scelta: ");
		scanf("%d", &scelta);
		printf("\n");
		switch (scelta){
			case 1:
				insDati();
				break;
			case 2:
				calcoloLift();
				break;
			case 3:
				calcoloDrag();
				break;
			case 4:
				uscita = 1;
				break;	
		}
		if ( scelta > 4 ){
			printf("Non ho ancora cosi' tante opzioni! \n");
		}else{}
	}
	printf("----------------------------------------");
	return 0;
}

void insDati(){
	printf("Inserire i parametri richiesti:\n\n");
	printf("- Quota di volo (m): ");
	scanf("%f", &quota);
	printf("- Velocita' di volo (m/s): ");
	scanf("%f", &velocita);
	printf("- Superficie alare (m^2): ");
	scanf("%f", &superficie_alare);
	printf("- Coefficiente di portanza: ");
	scanf("%f", &CoeffLift);
	printf("- Efficienza aerodinamica del velivolo: ");
	scanf("%f", &aeroEff);
}

void calcoloLift(){
	
	tZ = t0 - (k*quota);
	pZ = p0*pow((tZ/t0) , (1/(n-1)));
	
	
	lift = 0.5*pZ*pow(velocita , 2)*superficie_alare*CoeffLift;
	printf("-- Portanza: %f N\n", lift);
	
}

void calcoloDrag(){
	drag = lift/aeroEff;
	printf("-- Resistenza aerodinamica %f N\n\n", drag);
}


