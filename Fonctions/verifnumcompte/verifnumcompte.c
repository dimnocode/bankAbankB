#include <stdio.h>
#include <stdlib.h>

int verifnumcompte (char* chaine);                         
int verifnumcompte (char* chaine)

{
  if(chaine[0]!='B')
  {
   printf("Ce num%cro de compte est incorrect\n",130);
   return 0;                 
  }
  if(chaine[1]!='E')
  {
   printf("Ce num%cro de compte est incorrect\n",130);
   return 0;                  
  }
  if(chaine[2]>57||chaine[2]<48)
  {
   printf("Ce num%cro de compte est incorrect\n",130);
   return 0;                  
  }
  if(chaine[3]>57||chaine[3]<48)
  {
   printf("Ce num%cro de compte est incorrect\n",130);
   return 0;                  
  }
  if(chaine[4]!=' ')
  {
   printf("Ce num%cro de compte est incorrect\n",130);
   return 0;                  
  }
  if(chaine[5]>57||chaine[5]<48)
  {
   printf("Ce num%cro de compte est incorrect\n",130);
   return 0;                  
  }
  if(chaine[6]>57||chaine[6]<48)
  {
   printf("Ce num%cro de compte est incorrect\n",130);
   return 0;                  
  }
  if(chaine[7]>57||chaine[7]<48)
  {
   printf("Ce num%cro de compte est incorrect\n",130);
   return 0;                  
  }
  if(chaine[8]>57||chaine[8]<48)
  {
   printf("Ce num%cro de compte est incorrect\n",130);
   return 0;                  
  }
  if(chaine[9]!=' ')
  {
   printf("Ce num%cro de compte est incorrect\n",130);
   return 0;                  
  }
  if(chaine[10]>57||chaine[5]<48)
  {
   printf("Ce num%cro de compte est incorrect\n",130);
   return 0;                  
  }
  if(chaine[11]>57||chaine[11]<48)
  {
   printf("Ce num%cro de compte est incorrect\n",130);
   return 0;                  
  }
  if(chaine[12]>57||chaine[12]<48)
  {
   printf("Ce num%cro de compte est incorrect\n",130);
   return 0;                  
  }
  if(chaine[13]>57||chaine[13]<48)
  {
   printf("Ce num%cro de compte est incorrect\n",130);
   return 0;                  
  }
  if(chaine[14]!=' ')
  {
   printf("Ce num%cro de compte est incorrect\n",130);
   return 0;                  
  }
  if(chaine[15]>57||chaine[15]<48)
  {
   printf("Ce num%cro de compte est incorrect\n",130);
   return 0;                  
  }
  if(chaine[16]>57||chaine[16]<48)
  {
   printf("Ce num%cro de compte est incorrect\n",130);
   return 0;                  
  }
  if(chaine[17]>57||chaine[17]<48)
  {
   printf("Ce num%cro de compte est incorrect\n",130);
   return 0;                  
  }
  if(chaine[18]>57||chaine[18]<48)
  {
   printf("Ce num%cro de compte est incorrect\n",130);
   return 0;                  
  }
  return 1;
}
