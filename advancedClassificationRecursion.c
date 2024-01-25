#include "NumClass.h"
#include <stdbool.h>

int powerr(int num, int pow);
int length (int num);
int isPalindromeHelperRecursive(int number, int reversedNumber, int original);
int getSumofDigits(int number, int pow);


int isArmstrong(int number) {
    int sum= getSumofDigits(number, length(number));
    if (number == sum ){
        return true;
    }
    else {
        return false;
    }
}

int getSumofDigits(int number, int pow) {
    if (number == 0)
        return 0;
    return powerr ((number%10) , pow) + getSumofDigits((number/10), pow);
}



int isPalindrome(int number) {
    return isPalindromeHelperRecursive(number, 0, number);
}

int isPalindromeHelperRecursive(int number, int reversedNumber, int original) {
    if (number == 0) {
        return (original == reversedNumber);
    } else {
        int digit = number % 10;
        reversedNumber = (reversedNumber * 10) + digit;
        return isPalindromeHelperRecursive(number / 10, reversedNumber, original);
    }
}

int length (int num){
    int original=num;
    if (num == 0){
        return 1;
    }
    int count=0;
    while (original>0)
    {
    original= original/10;
        count++;
    }
    return count;
    }


int powerr(int num, int pow) {
  if (pow==0){
    return 1;
  }else{
    return num * powerr (num, pow-1);
  }
}
