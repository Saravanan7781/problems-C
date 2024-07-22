#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

// Function to check if a number is prime
bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= sqrt(x); ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate palindrome numbers of a given length
int generatePalindrome(int num, bool oddLength) {
    int palin = num;
    if (oddLength) num /= 10;
    while (num > 0) {
        palin = palin * 10 + (num % 10);
        num /= 10;
    }
    return palin;
}

// Function to find the smallest prime palindrome >= n
int primePalindrome(int n) {
    if (n <= 2) return 2;
    if (n <= 3) return 3;
    if (n <= 5) return 5;
    if (n <= 7) return 7;
    if (n <= 11) return 11;

    for (int len = 1; len < 6; ++len) {
        // Generate odd-length palindromes
        for (int num = pow(10, len - 1); num < pow(10, len); ++num) {
            int palin = generatePalindrome(num, true);
            if (palin >= n && isPrime(palin)) {
                return palin;
            }
        }
        // Generate even-length palindromes
        for (int num = pow(10, len - 1); num < pow(10, len); ++num) {
            int palin = generatePalindrome(num, false);
            if (palin >= n && isPrime(palin)) {
                return palin;
            }
        }
    }

    return -1; // The problem guarantees an answer exists, so this line should never be reached
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int result = primePalindrome(n);
    printf("The smallest prime palindrome >= %d is %d\n", n, result);

    return 0;
}
