#include "NumClass.h"


int main (){
    int num1, num2, max,min;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    if (num1>num2){
        max=num1;
        min=num2;
    }
    else{
        max=num2;
        min=num1;
    }
for (int i=min; i<=max; i++){
        if  (isPrime(i)){
             printf("%d ",i);
        }
    }
    printf("\n");
    for (int i=min; i<=max; i++){
            if  (isArmstrong(i)){
                printf("%d ",i);
            }
        }
        printf("\n");
 for (int i=min; i<=max; i++){
        if  (isStrong(i)){
             printf("%d ",i);
        }
    }
    printf("\n");
     for (int i=min; i<=max; i++){
        if  (isPalindrome(i)){
             printf("%d ",i);
        }
    }
    printf("\n");

    return 0;
} 
