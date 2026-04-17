#include<stdio.h>
#include<stdbool.h>

bool lemonadeChange(int* bills, int billsSize) {
    
    int cont5 = 0, cont10=0 , cont20=0;

    for(int i=0; i<billsSize;i++) {

        if(bills[0]!=5) return false;
        if(bills[i]==5)  {
            cont5++;
        } 
        
        else if(bills[i]==10 && cont5==0)  {
            return false;
        } else if(bills[i]==10 && cont5>0) {
            cont10++;
            cont5--;
        } 
        else if(bills[i]==20 && cont10>0 && cont5>0) {
                cont10--;
                cont5--;
                cont20++;
        }

        else if(bills[i]==20 && cont5==0)  return false;
        else if(bills[i]==20 && cont5<3 && cont10==0)  return false;
        
        
    }
        return true;
}



 int main() {
    
    int vetor[10] = {5,20,5,10,20};

    if(lemonadeChange(vetor, 5)==true) printf("\n\nPossivel!\n\n");
    else printf("\n\nImpossivel\n\n");

    
    return 0;
}
