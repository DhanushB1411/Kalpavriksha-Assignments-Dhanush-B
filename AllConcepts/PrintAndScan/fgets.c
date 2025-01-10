#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {

    int n;
    printf("Enter num : \n");
    scanf("%d", &n);
    getchar();  // Clear the newline left in the buffer

    char name[40];
    printf("Enter string : \n");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove newline character
    printf("%s\n", name);

    char ch;
    printf("Enter ch : \n");
    scanf("%c", &ch);
    getchar();  // Clear the newline left in the buffer
    printf("%c\n", ch);

    char str[20];
    printf("Enter string : \n");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove newline character
    printf("%s\n", str);

    char str1[20];
    printf("Enter string : \n");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';  // Remove newline character
    printf("%s\n", str1);

    return 0;
}
