#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isPalindrome(char* str) // checks if given string is palindrome
{
    int left = 0;
    int right = strlen(str) - 1;
    while (left < right) { // 2 pointer comparison

        while (str[left] == ' ') { // skipping spaces
            left++;
        }
        while (str[right] == ' ') { // skipping spaces
            right--;
        }
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main(void)
{
    char input[1024];
    bool res = false;
    printf("Введите строку: ");
    scanf("%[^\n]%*c", input);
    res = isPalindrome(input);
    if (res) {
        printf("It's palindrome!\n");
    } else {
        printf("It isn't palindrome!\n");
    }
}
