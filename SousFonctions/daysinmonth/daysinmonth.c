#include <stdio.h>
#include <stdlib.h>

//Sous fonction monthdays(int d, int y)
//Retourne le nombre de jours d'un mois d'une année donnée

int daysinmonth(int d, int y){
	
	int monthdays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) { 
		monthdays[1] = 29;
	}
	
	return monthdays[d-1];
	
}


//Fonction main de test

void main() {
	
	int mon, yea;
	
	printf("\n\nEntrez un mois : ");
	scanf("%d", &mon);
	
	printf("\n\nEntrez une annee : ");
	scanf("%d", &yea);
	
	printf("\n\nLe nombre de jour du mois : %d/%d est de %d\n", mon, yea, daysinmonth(mon, yea));
	
	system("pause");
		
}



