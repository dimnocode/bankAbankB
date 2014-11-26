Enter file contents here//créerez une fonction nommée « encodenouvclientB» dont le prototype est le suivant : struct clientB encodenouvclientB (void) ; 
//Cette fonction permet à l’utilisateur d’encoder les informations concernant un nouveau client de la banque B. La fonction vérifie 
//la validité des informations et invite l’utilisateur à se corriger si certaines informations sont erronées. 
//Cette fonction fera notamment appel aux fonctions verifnom, verifprenom, et verifdatenaiss évoquées précédemment. 
//Les « saisies vides » (lorsque l’utilisateur appuie sur la touche ENTER sans avoir préalablement saisi de caractère) sont interdites 
//pour chaque information concernant un client de la banque B (autrement dit pas de « saisie vide » pour le nom, le prénom et la date de naissance). 
//Les informations valides concernant le nouveau client de la banque B seront contenues dans la structure clientB retournée par la fonction ;
//
//struct clientB
//{
//char nom [31];
//char prenom [31];
//char datenaiss [11] ;
//}cB;
 
 
#include<stdlib.h>
#include<stdio.h>

 int strlength(char s[])
{ 
 	int i=0; 
 	 
 	while(s[i] != '\0') 
{ 
 		++i; 
 	} 
 	 
 	return i; 
 } 
 //Fonction verifnom  
 
 int verifnom(char *nom){ 
 	 
 	int i, lnom; 
 	//Calcul de la longueur de la chaine 
 	lnom = strlength(nom); 
 		 
 	//Passage vers majuscule de la chaine (option) 
 	//lowtoupcase(nom); 
 	 
 	//Si 1er caractère est un espace alors invalide 
 	if((int)nom[0] == 32) { 
 		return 0; 
 	} 
 	 
 	//Vérification des caractères 
 	for(i=0;i<lnom;++i){ 
 		 
 		 
 		if(((int)nom[i] < 65 || (int)nom[i] > 90) && ((int)nom[i] != 32)){ 
 			return 0; 
 		} 
 	 
 	 
 	} 
 	return 1; 
 	 
 } 
 
 int verifprenom(char *prenom){ 
 	 
 	int i, lprenom; 
 	//Calcul de la longueur de la chaine 
 	lprenom = strlength(prenom); 
 		 
 	//Passage vers majuscule de la chaine (option) 
 	//lowtoupcase(prenom); 
 	 
 	//Si 1er caractère est un espace alors invalide 
 	if((int)prenom[0] == 32 || (int)prenom[i] == 45) { 
 		return 0; 
 	} 
 	 
 	//Vérification des caractères 
 	for(i=0;i<lprenom;++i){ 
 		 
 		 
 		if(((int)prenom[i] < 65 || (int)prenom[i] > 90) && (int)prenom[i] != 32 && (int)prenom[i] != 45 ){ 
 			return 0; 
 		} 
 	 
 	 
 	} 
 	return 1; 
 	 
 } 
 
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
 int daysinmonth(int d, int y){ 
 	 
 	int monthdays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
 	 
 	if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {  
 		monthdays[1] = 29; 
 	} 
 	 
 	return monthdays[d-1]; 
 	 
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
 



 
 



struct clientB
{
char nom [31];
char prenom [31];
char datenaiss [11] ;
}cB;

encodenouvclientB(void)
{

      
                      
                      
       
       do
       {
                       printf("veuillez entrer le nom du nouveau client\n");
                       gets(cB.nom);
                      

       }
       while(verifnom(cB.nom)!=1 || cB.nom[0]=='\0');
       
       
       
       do
       {
                       printf("veuillez entrer le pr%cnom du nouveau client\n",130);
                       gets(cB.prenom);
                                     
       }
       while(verifprenom(cB.prenom)!=1 || cB.prenom[0]=='\0');
       
        
       
      
      do
      {
      printf("veuillez entrer la date de naissance du nouveau client.\n");
      printf("la date de naissance s'encode comme suit : jj/mm/aaaa\n");
      gets(cB.datenaiss);
                       
      }
      while(verifdatenaiss(cB.datenaiss)!=1 || cB.datenaiss[0]=='\0');
       
      
                            
}

main()
{
  encodenouvclientB();
  
  puts(cB.nom);
  puts(cB.prenom);
  puts(cB.datenaiss);
  printf("les donnees sont elles correctes?\n");
  
  system("pause");    
}

