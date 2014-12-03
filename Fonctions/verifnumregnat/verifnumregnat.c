
#include <stdlib.h>
#include <stdio.h>
 
int verifNumRegNat(char* chaine)
{
                int i=0;
                int etat = 1;
                while (i < 13 )
                {
                    
        if(i != 6 && i != 10)
        {
            if(chaine[i]<'0'||chaine[i]>'9')
            {
                etat = 0;
            }
        }
        else
        {
            if (chaine[i]!='-')
            {
                etat = 0;
            }
        }
        i=i+1;
                }
        return etat;
}
 
/*La partie qui suit sert à tester mon code*/
/*int main(void) 
{
                char chaine[] = "153456-123-123";
                printf("%d \n",verifNumRegNat(chaine));
                system("pause");
                return 0;
}*/
