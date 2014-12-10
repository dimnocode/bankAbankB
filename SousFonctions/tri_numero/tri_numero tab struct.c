Enter file contents here
#include<stdlib.h>
#include<stdio.h>
#define faux 0
#define vrai 1
int ,i=0,temp,tri=faux,pos=n-1;

void tri_numero()
{
     while(tri==faux)
     {
                     tri=vrai;
             for(i=0;i<pos;i++)
             {
                     if(trinumA.numero[i]>trinumA.numero[i+1])
                     {
                   struct clientA temp=trinumA[i];             //le temp est une structure temporaire clientA
                   trinumA[i]=trinumA[i+1];
                   trinumA[i+1]= temp;
                   tri=faux;
                   pos=i;
                     }
             }
     }
}
