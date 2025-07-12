#include <stdio.h>
#include <math.h>
#include <windows.h>

void basic_calculations();
void advanced_calculations();
double factorial(int);
void solveQuadratic();
void log_to_file(const char* operation, double result);

int main() {
    int choice;

    do {
        printf("\n=== Advanced Calculator ===\n");
        printf("1. Basic Calculations\n");
        printf("2. Advanced Calculations\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                basic_calculations();
                break;
            case 2:
                advanced_calculations();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void basic_calculations() {
    int choice;
    double a, b, res;
    int x, y;

    do {
        printf("\n--- Basic Calculations ---\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Modulus\n0. Back to Main Menu\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                printf("Enter two numbers:\n");
                scanf("%lf %lf", &a, &b);
                res = a + b;
                printf("Result = %.2lf\n", res);
                log_to_file("Addition", res);
                break;
            case 2:
                printf("Enter two numbers:\n");
                scanf("%lf %lf", &a, &b);
                res = a - b;
                printf("Result = %.2lf\n", res);
                log_to_file("Subtraction", res);
                break;
            case 3:
                printf("Enter two numbers:\n");
                scanf("%lf %lf", &a, &b);
                res = a * b;
                printf("Result = %.2lf\n", res);
                log_to_file("Multiplication", res);
                break;
            case 4:
                printf("Enter two numbers:\n");
                scanf("%lf %lf", &a, &b);
                if (b != 0) {
                    res = a / b;
                    printf("Result = %.2lf\n", res);
                    log_to_file("Division", res);
                } else {
                    printf("Error: Division by zero!\n");
                }
                break;
            case 5:
                printf("Enter two integers:\n");
                scanf("%d %d", &x, &y);
                if (y != 0) {
                    int mod = x % y;
                    printf("Result = %d\n", mod);
                    log_to_file("Modulus", (double)mod);
                } else {
                    printf("Error: Division by zero!\n");
                }
                break;
            case 0:
                break;
            default:
                printf("Invalid choice!\n");
        }
        Sleep(1000);
    } while (choice != 0);
}

void advanced_calculations() {
    int choice;
    double a, b, res;

    do {
        printf("\n--- Advanced Calculations ---\n");
        printf("1. Power\n2. Square Root\n3. Sine\n4. Cosine\n5. Tangent\n");
        printf("6. Natural Log\n7. Log Base 10\n8. Exponential\n9. Factorial\n10. Absolute\n");
        printf("11. Degrees to Radians\n12. Radians to Degrees\n13. Solve Quadratic\n0. Back to Main Menu\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                printf("Enter base and exponent:\n");
                scanf("%lf %lf", &a, &b);
                res = pow(a, b);
                printf("Result = %.2lf\n", res);
                log_to_file("Power", res);
                break;
            case 2:
                printf("Enter a number:\n");
                scanf("%lf", &a);
                if (a >= 0) {
                    res = sqrt(a);
                    printf("Result = %.2lf\n", res);
                    log_to_file("Square Root", res);
                } else {
                    printf("Error: Negative input!\n");
                }
                break;
            case 3:
                printf("Enter angle in degrees:\n");
                scanf("%lf", &a);
                res = sin(a * M_PI / 180);
                printf("Result = %.2lf\n", res);
                log_to_file("Sine", res);
                break;
            case 4:
                printf("Enter angle in degrees:\n");
                scanf("%lf", &a);
                res = cos(a * M_PI / 180);
                printf("Result = %.2lf\n", res);
                log_to_file("Cosine", res);
                break;
            case 5:
                printf("Enter angle in degrees:\n");
                scanf("%lf", &a);
                res = tan(a * M_PI / 180);
                printf("Result = %.2lf\n", res);
                log_to_file("Tangent", res);
                break;
            case 6:
                printf("Enter a positive number:\n");
                scanf("%lf", &a);
                if (a > 0) {
                    res = log(a);
                    printf("Result = %.2lf\n", res);
                    log_to_file("Natural Log", res);
                } else {
                    printf("Error: Invalid input!\n");
                }
                break;
            case 7:
                printf("Enter a positive number:\n");
                scanf("%lf", &a);
                if (a > 0) {
                    res = log10(a);
                    printf("Result = %.2lf\n", res);
                    log_to_file("Log Base 10", res);
                } else {
                    printf("Error: Invalid input!\n");
                }
                break;
            case 8:
                printf("Enter a number:\n");
                scanf("%lf", &a);
                res = exp(a);
                printf("Result = %.2lf\n", res);
                log_to_file("Exponential", res);
                break;
            case 9:
                printf("Enter a non-negative integer:\n");
                scanf("%lf", &a);
                if (a < 0 || (int)a != a) {
                    printf("Error: Invalid input for factorial!\n");
                } else {
                    res = factorial((int)a);
                    printf("Result = %.0lf\n", res);
                    log_to_file("Factorial", res);
                }
                break;
            case 10:
                printf("Enter a number:\n");
                scanf("%lf", &a);
                res = fabs(a);
                printf("Result = %.2lf\n", res);
                log_to_file("Absolute", res);
                break;
            case 11:
                printf("Enter angle in degrees:\n");
                scanf("%lf", &a);
                res = a * M_PI / 180;
                printf("Radians = %.4lf\n", res);
                log_to_file("Degrees to Radians", res);
                break;
            case 12:
                printf("Enter angle in radians:\n");
                scanf("%lf", &a);
                res = a * 180 / M_PI;
                printf("Degrees = %.4lf\n", res);
                log_to_file("Radians to Degrees", res);
                break;
            case 13:
                solveQuadratic();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice!\n");
        }
        Sleep(1000);
    } while (choice != 0);
}

double factorial(int n) {
    double result = 1;
    if (n < 0) return -1;
    for (int i = 1; i <= n; i++)
        result *= i;
    return result;
}

void solveQuadratic() {
    double a, b, c, discriminant, root1, root2;
    printf("Enter coefficients a, b and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    discriminant = b * b - 4 * a * c;

    if (a == 0) {
        printf("Not a quadratic equation.\n");
        return;
    }

    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots are real and distinct: %.2lf and %.2lf\n", root1, root2);
    } else if (discriminant == 0) {
        root1 = -b / (2 * a);
        printf("Roots are real and equal: %.2lf\n", root1);
    } else {
        double realPart = -b / (2 * a);
        double imagPart = sqrt(-discriminant) / (2 * a);
        printf("Roots are complex: %.2lf + %.2lfi and %.2lf - %.2lfi\n",
               realPart, imagPart, realPart, imagPart);
    }
}

void log_to_file(const char* operation, double result) {
    FILE *ptr = fopen("calculator.txt", "a");
    if (ptr == NULL) {
        printf("Error opening log file.\n");
        return;
    }
    fprintf(ptr, "%s = %.2lf\n", operation, result);
    fclose(ptr);
}