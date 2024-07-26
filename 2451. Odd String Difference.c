bool isUnique(const int* arr1, const int* arr2, int len) {
    for (int i = 0; i < len; i++) {
        if (arr1[i] != arr2[i]) {
            return true; // Found a difference
        }
    }
    return false; // All elements are the same
}

// Function to find the odd string out
char* oddString(char** words, int wordsSize) {
    int wordLen = strlen(words[0]);
    int** multiArr = (int**)malloc(wordsSize * sizeof(int*));
    for (int i = 0; i < wordsSize; i++) {
        multiArr[i] = (int*)malloc((wordLen - 1) * sizeof(int));
    }
    
    // Calculate the difference arrays
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < wordLen - 1; j++) {
            multiArr[i][j] = words[i][j + 1] - words[i][j];
        }
    }
    
    // Print the difference arrays for debugging
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < wordLen - 1; j++) {
            printf("%d ", multiArr[i][j]);
        }
        printf("\n");
    }

    // Find the odd array
    int index = -1;
    for (int i = 0; i < wordsSize; i++) {
        int count = 0;
        for (int j = 0; j < wordsSize; j++) {
            if (i != j && !isUnique(multiArr[i], multiArr[j], wordLen - 1)) {
                count++;
            }
        }
        if (count == 0) {
            index = i;
            break;
        }
    }

    
    return words[index];
}
