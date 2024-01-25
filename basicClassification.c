#include "NumClass.h"

int factorial(int n);

int isStrong (int number){
   int copyNumber = number;
   int sum = 0;

    while (copyNumber != 0) {
        int digit = copyNumber % 10;
        sum += factorial(digit);
        copyNumber /= 10;
    }

    if (sum == number)
         return 1;
    return 0;


}

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int isPrime (int number){
  if (number < 1) {
        return 0;  // not prime
    }

    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return 0;  // not prime
        }
    }
    return 1;  // is prime
}



