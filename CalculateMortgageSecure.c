#include <stdio.h>
#include <stdbool.h>

bool readSalaries(double *salary1, double *salary2);

int main() {
    double salary1, salary2;
    
    printf("Enter two salaries: ");
    
    if (readSalaries(&salary1, &salary2)) {
        printf("Success! You entered: %.2f and %.2f\n", salary1, salary2);
        printf("Average: %.2f\n", (salary1 + salary2) / 2);
    } else {
        printf("Error: Invalid input. Please enter two numbers.\n");
        return 1;
    }
    
    return 0;
}

bool readSalaries(double *salary1, double *salary2) {
    if (salary1 == NULL || salary2 == NULL) {
        return false;
    }
    
    int result = scanf("%lf %lf", salary1, salary2);
    
    if (result != 2) {
        // Clear input buffer on error
        while (getchar() != '\n');
        return false;
    }
    
    return true;
}