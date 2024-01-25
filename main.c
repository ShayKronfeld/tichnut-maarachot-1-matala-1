#include "NumClass.h"


int main (){
    int num1, num2, max,min;

    scanf("%d%d",&num1,&num2);
    
    if (num1>num2){
        max=num1;
        min=num2;
    }
    else{
        max=num2;
        min=num1;
    }

printf("The Armstrong numbers are:");
for (int i=min; i<=max; i++){
            if  (isArmstrong(i)){
                printf(" %d",i);
            }
        }


printf("\nThe Palindromes are:");
 for (int i=min; i<=max; i++){
        if  (isPalindrome(i)){
             printf(" %d",i);
        
    }
 }
printf("\nThe Prime numbers are:");
for (int i=min; i<=max; i++){
        if  (isPrime(i)){
             printf(" %d",i); 
        }
    }

printf("\nThe Strong numbers are:"); 
 for (int i=min; i<=max; i++){
        if  (isStrong(i)){
             printf(" %d",i);
        }
    }
printf("\n");

return 0;


}
