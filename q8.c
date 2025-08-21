#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countWords(char str[]) {
    int count = 0, inWord = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i])) {  // if character is not space
            if (!inWord) {
                count++;    // start of a new word
                inWord = 1;
            }
        } else {
            inWord = 0;      // end of a word
        }
    }
    return count;
}

int main() {
    char str[200];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);  // read full line with spaces

    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';

    int wordCount = countWords(str);
    printf("Number of words: %d\n", wordCount);

    return 0;
}
