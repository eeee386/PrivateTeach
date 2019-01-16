#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

bool divisible(int dividend, int divisor) {
    bool divisible = dividend % divisor == 0;
    return divisible;
}

void BruteForce (int maxNumber) {
    int * primes;
    primes = malloc(sizeof(int) * maxNumber);
    primes[0] = 0;
    primes[1] = 1;
    primes[2] = -1;
    double timeSpent;
    clock_t begin;
    clock_t end;
    int TERMINATOR = -1;

    begin = clock();
    for (int i = 2; i < maxNumber; i++) {
        for (int j = 2; j< maxNumber ; j++) {
            if(primes[j] == -1) {
                primes[j] = i;
                primes[j + 1] = TERMINATOR;
                break;
            }
            if (divisible(i, primes[j])) {
                break;
            }
        }
    }
    end = clock();
    timeSpent = (double)(end - begin)/1000;
    printf("BruteForce %f s\n", timeSpent);

    // print BruteForce Result
    for(int i = 0; i < maxNumber; i++) {
        if(primes[i] == TERMINATOR)  {
            break;
        }
        printf("%d ", primes[i]);
    }

     free(primes);
}

void halvedSquareRootBruteForce (int maxNumber)  {
    int * primes;
    primes = malloc(sizeof(int) * maxNumber);
    primes[0] = 0;
    primes[1] = 1;
    primes[2] = 2;
    primes[3] = 3;
    double timeSpent;
    clock_t begin;
    clock_t end;
    int TERMINATOR = -1;

    int sqrtI;
    int index = 3;
    begin = clock();
    for (int i = 5; i < maxNumber; i = i + 2) {
        sqrtI = (int) sqrt(i);
        for (int j = 2; j <= index; j++) {
            if(divisible(i, primes[j])) {
                break;
            }
            if (primes[j] >= sqrtI && !divisible(i, primes[j])) {
                index++;
                primes[index] = i;
                break;
            }
        }
        if(i + 2 >= maxNumber) {
            index++;
            primes[index] = TERMINATOR;
        }
    }
    end = clock();
    timeSpent = (double)(end - begin)/1000;
    // Print HalvedSquareRootBruteForce Result
    printf("HalvedSquareRootedBruteForce %f s\n", timeSpent);
//        for(int i = 1; i < maxNumber; i++) {
//            printf("%d ", primes[i]);
//            if(primes[i] == -1) {
//                break;
//            }
//        }

    free(primes);
}

void sieveOfEratosthenes(int maxNumber) {
    bool * sievePrimes;
    sievePrimes = malloc(sizeof(bool) * maxNumber);
    double timeSpent;
    clock_t begin;
    clock_t end;

    for (int k = 0; k < maxNumber; k++) {
        sievePrimes[k] = true;
    }

    begin = clock();
    for (int i = 2; i*i <= maxNumber; i++) {
        if(sievePrimes[i] == true) {
            for (int j=i*i; j<=maxNumber; j += i)
                sievePrimes[j] = false;
        }
    }
    end = clock();

    timeSpent = (double)(end - begin)/1000;
    printf("SieveOfEratosthenes %f s\n", timeSpent);
//    for (int i = 1; i < maxNumber; i++) {
//        if(sievePrimes[i] == true) {
//             printf("%d ", i);
//        }
//    }

    free(sievePrimes);
}

int main()
{
    int MAX_NUMBER = 50000000;

    //BRUTEFORCE
    // BruteForce(MAX_NUMBER);

    //HALVEDSQUAREROOTBRUTEFORCE
    halvedSquareRootBruteForce(MAX_NUMBER);


    //SIEVE OF ERATOSTHENES
    sieveOfEratosthenes(MAX_NUMBER);
    return 0;
}
