#include <stdio.h>
#include <stdbool.h>

bool lemonadeChange(int* bills, int billsSize) {
    
    int cont5 = 0;
    int cont10 = 0;

    if (bills[0] != 5)
        return false;

    for (int i = 0; i < billsSize; i++) {

        if (bills[i] == 5) {
            cont5++;
        } 
        
        else if (bills[i] == 10) {
            if (cont5 == 0) {
                return false;
            }
            cont5--;
            cont10++;
        } 
        
        else if (bills[i] == 20) {
            if (cont10 > 0 && cont5 > 0) {
                cont10--;
                cont5--;
            } 
            else if (cont5 >= 3) {
                cont5 -= 3;
            } 
            else {
                return false;
            }
        }
    }

    return true;
}

int main() {
    
    int vetor[10] = {5, 5, 5, 10, 20};

    if (lemonadeChange(vetor, 5))
        printf("\n\nPossivel!\n\n");
    else
        printf("\n\nImpossivel\n\n");

    return 0;
}
