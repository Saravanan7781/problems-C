#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseStr(char* s, int k) {
    int len = strlen(s);
    char* newStr = (char *)malloc((len+1) * sizeof(char));
    strcpy(newStr, s);

    for (int i = 0; i < len; i += 2 * k) {
        int left = i;
        int right = i + k - 1 < len ? i + k - 1 : len - 1;
        while (left < right) {
            char temp = newStr[left];
            newStr[left++] = newStr[right];
            newStr[right--] = temp;
        }
    }

    return newStr;
}

int main() {
    char s[] = "fdcqkmxwholhytmhafpesaentdvxginrjlyqzyhehybknvdmfrfvtbsovjbdhevlfxpdaovjgunjqlimjkfnqcqnajmebeddqsgl";
    int k = 10;
    char* result = reverseStr(s, k);
    printf("Reversed String: %s\n", result);
    free(result);
    return 0;
}
