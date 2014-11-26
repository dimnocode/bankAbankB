#include <stdlib.h>
#include <stdio.h>

int fgetsPerso(char *destination,int size);    
int fgetsPerso(char *destination,int size)      /*Fonction qui fai en sorte que si on depasse le nombre de caractere de la saisie, ca nous mes une erreur*/
{
  int nombreCaracteres = 0;
  int i;
  destination[size-1]='\0';
  char lettre;
  do
  {
    lettre = getchar();
    if(lettre!='\n')
    {
      destination[nombreCaracteres] = lettre;
      nombreCaracteres++;
    }
    if(nombreCaracteres>size-1)
    {
      return 0;
    }  
  }
  while(lettre != '\n');
  return 1;
}                         
