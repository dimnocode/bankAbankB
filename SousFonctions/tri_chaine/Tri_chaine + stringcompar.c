#include <stdlib.h>
#include <stdio.h>
#define faux 0
#define vrai 1


int stringcompare(char *chaineA, char* chaineB)   //Fonction qui compare les differentes chaine de caract
{
 int i=0;
 while (chaineA[i]!='\0'&&chaineB[i]!='\0')
 {
  if (chaineA[i] > chaineB[i])
  {
   return -1 ;             
  } 
  else if(chaineA[i]<chaineB[i])
  {
   return 1 ;   
  } 
  i++;   
 }  
 if(strlen(chaineA) == strlen (chaineB))
 {
  return 0 ;           
 }
 else if(strlen(chaineA) < strlen(chaineB))
 {
  return 1;
 }
 else 
 {
   return -1;
 }
}

struct client    //stucture de client
{
  char nom[31];     
};

void trinom(struct client source[],int size)   //fonction qui tri les chaine de caract
{
  int temp=0;
  int tri=faux;
  int i=0;
  while (tri==faux)
  
  {
   tri=vrai;
   for(i=0;i<size-1;i++)
   {
    if (stringcompare(source[i].nom, source[i+1].nom)==-1)
    {
     struct client temp = source[i];
     source[i] = source [i+1];
     source [i+1] = temp;
     tri = faux;                 
    }               
   }     
  }   
}
main()
{
 int i=0;
 struct client clients[5];
 for(i=0;i<5;i++)
 {
   printf("Nom %d)",i+1);
   gets(clients[i].nom);              
 }     
   //appel de la fonction TRI  
   trinom(clients,sizeof(clients)/sizeof(clients[0].nom));
   for (i=0;i<5;i++)
   {
     printf("Nom %d) : %s\n",i+1, clients[i].nom);  
   }
 system("pause");     
}
