Enter file contents here//algo de tri de numero de n clients
#include<stdlib.h>
#include<stdio.h>
#define faux 0
#define vrai 1


int n=10,i=0,temp=0,tri=faux,pos=n-1;
int tab[n] = {5,8,7,10,62,85,12,10,45,74};

void tri_numero()
{
     
  while(tri==faux)
  {
             tri=vrai;
             for(i=0;i<pos;i++)
             {
                             if(tab[i]>tab[i+1])
                             {
                                             temp=tab[i];
                                             tab[i]=tab[i+1];
                                             tab[i+1]=temp;
                                             tri=faux;
                                             pos=i;
                             }
             }
  }
}          

main()
{
 tri_numero();
 for(i=0;i<10;i++)
 printf("%d\n",tab[i]);
 system("pause");      
}
