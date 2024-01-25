#include "NumClass.h"
#include <stdbool.h>

int powe(int num, int pow);

int isArmstrong(int number){
    int copyNumber = number;
    int numDigit = 0;
    int sum = 0;
    int pow=0;

    while (copyNumber != 0) {             //check how many digits
        copyNumber= copyNumber/ 10;
        numDigit++;
    }
    
    copyNumber = number;
    while (copyNumber != 0) {            // Calculate the sum of the digits with pow
        int digit = copyNumber % 10;
        pow= powe(digit, numDigit);
        sum= sum+ pow;
        copyNumber= copyNumber/10;
    }
    if (sum==number)
        return 1;
    return 0;
}


int isPalindrome(int number){
    int copyNumber = number;
    int reversed = 0;

    while (number != 0) {
        int dig = number % 10;  // calculate the digit 
        reversed =(reversed * 10) + dig; 
        number = number / 10;
    }

    if (copyNumber == reversed )
        return 1;
    return 0;
}



int powe(int num, int pow) {
     if (pow==0){
         return 1;
     } else{
         return num * powe (num, pow-1);
  }
}

