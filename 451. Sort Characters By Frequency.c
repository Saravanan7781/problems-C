#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct charFreq {
    char character;
    int freq;
};

char* frequencySort(char* s) {
    int arr[128] = {0};
    int len = strlen(s);
    char *result = (char *)malloc((len + 1) * sizeof(char)); // +1 for the null terminator

    // Count frequencies
    for (int i = 0; i < len; i++) {
        arr[s[i]]++;
    }

    struct charFreq charFrequency[128];

    // Initialize charFrequency array
    for (int i = 0; i < 128; i++) {
        charFrequency[i].character = i;
        charFrequency[i].freq = arr[i];
    }

    // Sort charFrequency array by frequency (descending order)
    for (int i = 0; i < 128 - 1; i++) {
        for (int j = 0; j < 128 - i - 1; j++) {
            if (charFrequency[j].freq < charFrequency[j + 1].freq) {
                struct charFreq temp = charFrequency[j];
                charFrequency[j] = charFrequency[j + 1];
                charFrequency[j + 1] = temp;
            }
        }
    }

    // Fill the result string based on sorted frequencies
    int index = 0;
    for (int i = 0; i < 128; i++) {
        while (charFrequency[i].freq > 0) {
            result[index] = charFrequency[i].character;
            charFrequency[i].freq--;
            index++;
        }
    }
    result[index] = '\0'; // Null-terminate the result string

    return result;
}

int main() {
    char str[] = "abcdee";
    char* sortedStr = frequencySort(str);
    printf("Sorted by frequency: %s\n", sortedStr);
    free(sortedStr); // Remember to free the allocated memory
    return 0;
}
