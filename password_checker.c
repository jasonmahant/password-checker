#include <stdio.h>
#include <string.h>
#include <ctype.h>

void checkPassword(char *password) {
    int length = strlen(password);
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    int score = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) hasUpper = 1;
        if (islower(password[i])) hasLower = 1;
        if (isdigit(password[i])) hasDigit = 1;
        if (ispunct(password[i])) hasSpecial = 1;
    }

    // Score the password
    if (length >= 8) score++;
    if (length >= 12) score++;
    if (hasUpper) score++;
    if (hasLower) score++;
    if (hasDigit) score++;
    if (hasSpecial) score++;

    // Feedback
    printf("\n--- Password Analysis ---\n");
    printf("Length: %d characters\n", length);
    printf("Uppercase letters: %s\n", hasUpper ? "Yes" : "No");
    printf("Lowercase letters: %s\n", hasLower ? "Yes" : "No");
    printf("Numbers: %s\n", hasDigit ? "Yes" : "No");
    printf("Special characters: %s\n", hasSpecial ? "Yes" : "No");

    printf("\nStrength: ");
    if (score <= 2) printf("WEAK\n");
    else if (score <= 4) printf("MODERATE\n");
    else printf("STRONG\n");

    // Tips
    printf("\nTips to improve:\n");
    if (length < 8) printf("- Use at least 8 characters\n");
    if (!hasUpper) printf("- Add uppercase letters\n");
    if (!hasLower) printf("- Add lowercase letters\n");
    if (!hasDigit) printf("- Add numbers\n");
    if (!hasSpecial) printf("- Add special characters (!@#$)\n");
}

int main() {
    char password[100];
    printf("=== Password Strength Checker ===\n");
    printf("Enter a password to check: ");
    scanf("%s", password);
    checkPassword(password);
    return 0;
}