#include <stdio.h>

float calculator(void) {
    float a, b;
    char op;

    printf("Enter expression (e.g., 3 + 4) separated by spaces: ");

    if (scanf("%f %c %f", &a, &op, &b) != 3) {
        printf("Invalid input.\n");
        return 0.0f;
    }

    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else if (op == '*')
        return a * b;
    else if (op == '/') {
        if (b == 0.0f) {
            printf("Cannot divide by 0.\n");
            return 0.0f;
        }

        return a / b;
    }

    printf("Invalid operator.\n");
    return 0.0f;
}



int main() {
    int mugs=4;
    printf("We have %d mugs\n", mugs);
    return 0;
    
}