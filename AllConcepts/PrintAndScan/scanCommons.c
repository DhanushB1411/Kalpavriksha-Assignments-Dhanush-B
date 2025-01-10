#include<stdio.h>

int main(){

   int i;
    char name[100];

    printf("Enter input (format: integer,string): ");
    scanf("%d,%99s", &i, name);

    printf("Integer: %d\n", i);
    printf("String: %s\n", name);
    //The , in the format specifier ensures that the input is parsed correctly, expecting a comma between the integer and the string.
    
       int a, b, c;

    printf("Enter three numbers separated by commas (e.g., 10,20,30): ");
    scanf("%d,%d,%d", &a, &b, &c);

    printf("Numbers: %d, %d, %d\n", a, b, c);

        int day, month, year;

    printf("Enter date in DD/MM/YYYY format: ");
    scanf("%d/%d/%d", &day, &month, &year);

    printf("Day: %d, Month: %d, Year: %d\n", day, month, year);

    int id;
    char grade;
    char name[50];

    printf("Enter data in the format (ID Grade Name): ");
    scanf("%d %c %s", &id, &grade, name);

    printf("ID: %d\n", id);
    printf("Grade: %c\n", grade);
    printf("Name: %s\n", name);
}