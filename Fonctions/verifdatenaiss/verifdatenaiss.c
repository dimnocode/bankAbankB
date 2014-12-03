#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Fonction
// --------
// int verifdatenaiss(char* chaine)
// Cette fonction retourne la valeur 0 si la chaine de caractères ne correspond pas à une date de naissance valide
// et retourne la valeur 1 dans le cas contraire ;


//Sous fontions nécessaires

//strlength
int strlength(char s[]){
	
	int i=0;
	
	while(s[i] != '\0') {
		++i;
	}
	
	return i;
}


//nbchartoint


int nbchartoint(char *chaine){
	
	int i, res=0, lchaine = strlength(chaine);
	
	
	for(i=0;i<lchaine;++i){
		
		if((int)chaine[i] >= 48 && (int)chaine[i] <= 57){
			
			res += ((int)chaine[i] - 48) * (int)pow(10.0, (float)lchaine-i-1);
			
		} 	else { 
				return res = -1;
			}
	}
	
	return res;
	
}

//daysinmonth
int daysinmonth(int mo, int ye){
	
	int monthdays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 	//Tableau du nombre de jour pour chaque mois (annees non bisextiles)
	
	if((ye % 4 == 0 && ye % 100 != 0) || ye % 400 == 0) { 					//Si l'annee est bisextile (divisible par 4 et non par 100 ou divisible par 400)
		monthdays[1] = 29;													//Alors le nombre de jour de mois de fevrier est de 29
	}
	
	return monthdays[mo-1];													//Retourne le nombre de jour du mois
	
}


//Fonction verifdatenaiss(char *chaine)


int verifdatenaiss(char *chaine) {
  int i, j, m, a, result;
  
  
  if(strlength(chaine) == 10 && chaine[2] == '/' && chaine[5] == '/') {					//Si longeur de chaine = 10 ET 
  																						//si les "/" sont bien placés
  		char jour[3] = {chaine[0], chaine[1], '\0' };
		char mois[3] = {chaine[3], chaine[4], '\0' };									//Division de la date en différentes 
		char annee[5] = {chaine[6], chaine[7], chaine[8], chaine[9], '\0' };			//variables char[] jours, mois, années
 
        j = nbchartoint(jour);
        m = nbchartoint(mois);															//Conversion en int
        a = nbchartoint(annee);
        
        
		if(j <= daysinmonth(m, a) && j >= 1){											//Si le jour du mois est valide (année bisextile)
												
    		if(a >= 1905 && a <=1996) {													//Si la date est postérieure au 31 décembre 1904 et 
    																					//antérieure au 1er janvier 1997
    		
				return 1;																//Alors retourne 1 = valide
			} 
		
  		} 	

    }
  
	return 0;																			//Si longeur de chaine != 10 OU 
																						//si les "/" ne sont pas bien placés
																						//Retourne 0 = invalide  
}


void main(){
	
	char d[11];
	printf("\nEntrez une date (01/12/1965) : ");
	gets(d);
	printf("\nValide ? %d",verifdatenaiss(d));
	
}
