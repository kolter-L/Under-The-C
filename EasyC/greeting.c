# include <stdio.h>
# include <stdlib.h>

int main() {
    char* my_name = (char*)malloc(sizeof(char)*20);
    printf("Enter your name: ");
    scanf("%s", my_name);
    printf("Hello, %s!\n", my_name);
    free(my_name);

    return 0;
}