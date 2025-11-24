#include <stdio.h>
int substringCount(char* str, char* substr)
{
    int counter = 0;
    int indstr = 0;
    int indsubstr = 0;
    while (str[indstr] != '\0') {
        if (str[indstr] == substr[indsubstr]) {
            indsubstr++;
        } else {
            indsubstr = 0;
        }
        if (substr[indsubstr] == '\0') {
            counter += 1;
            indsubstr = 0;
        }
        indstr++;
    }
    return counter;
}

int main()
{
    printf("%d\n", substringCount("testtest12test", "test"));
    printf("%d\n", substringCount("testtest12test", "tt"));
    return 0;
}
