//Enter file contents here//ex 9.23 tri_chaine 
#include<stdlib.h>
#include<stdio.h>

int strcomp2(char tabA[],char tabB[])
{
    int i=0;
    
    while(tabA[i]==tabB[i])
    {
        i++;
          
		  if((int)tabA[i]<(int)tabB[i])
        {
         return 1;                                
        }
        else
        {
            return 0;
        }
    }
  
}

main()
{
      char tab[100]={0};
      char tab2[100]={0};
      int a;
      printf("veuillez entrer la premi%cre saisie\n",138);
      gets(tab);
       printf("veuillez entrer la deuxi%cme saisie\n",138);
      gets(tab2);
      
      a=strcomp2(tab,tab2);
      
      printf("%d",a);
 system("pause");
 
}
