#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Sous fonction nbchartoint(chaine*)
//recois une chaine de charactère et retourne le int correspondant;


//Sous fonctions nécessaires
int strlength(char s[]){
	
	int i=0;
	
	while(s[i] != '\0') {
		++i;
	}
	
	return i;
}


//Sous fonction nbchartoint(chaine*)


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
void main(){
	

	char nb[3] = {'2','2','\0'};
	printf("%d\n", strlength(nb));
	printf("%d", nbchartoint(nb));
}
