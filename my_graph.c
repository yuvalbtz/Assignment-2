#include <stdio.h>
#include "my_mat.h"

int main() {
    int matrix[10][10];
    char action;

    // קריאה לפעולות עד EOF
    while (1) {
        printf("Enter action (A/B/C/D/EOF): ");
        scanf(" %c", &action);

        switch (action) {
            case 'A':
                functionA(matrix);
                break;
            case 'B':
                functionB(matrix);
                break;
            case 'C':
                functionC(matrix);
                break;
            case 'D':
                printf("Exiting program\n");
                return 0;
            case EOF:
                printf("EOF detected. Exiting program\n");
                return 0;
            default:
                printf("Invalid action. Try again.\n");
                break;
        }
    }

    return 0;
}
