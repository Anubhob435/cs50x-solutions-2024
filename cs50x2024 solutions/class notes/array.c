#include <stdio.h>
#include <string.h>

int main() {
    char words[5][20];
    char result[6];

    printf("Enter 5 words:\n");
    for (int i = 0; i < 5; i++) {
        printf("Word %d: ", i + 1);
        scanf("%19s", words[i]);
    }

    for (int i = 0; i < 5; i++) {
        result[i] = words[i][0];
    }

    result[5] = '\0';
    printf("Result word: %s\n", result);
    return 0;
}
