#include <stdio.h>

void removeSpecificCharacter(char *str,char spCh){
    char *pointerSpecificChar = str;
    char *pointerOtherChar = str;

    while (*pointerSpecificChar != spCh )
    {
        pointerSpecificChar++;
        if(*pointerSpecificChar== '\0'){
            return;
        }
    }
   
    
    pointerOtherChar = pointerSpecificChar + 1;
    

    while (*pointerSpecificChar || *pointerOtherChar)
    {

        while (*pointerOtherChar == spCh)
        {
            pointerOtherChar++;
        }

        if (*pointerOtherChar == '\0')
            break;

        char temp = *pointerOtherChar;
        *pointerOtherChar = *pointerSpecificChar;
        *pointerSpecificChar = temp;

        pointerSpecificChar++;
        pointerOtherChar++;
    }
    *pointerSpecificChar = '\0';
}

int main()
{
    char str[100];
    printf("Enter :");
    scanf(" %[^\n]%*c", str);

    printf("Enter specific character to remove : \n");
    char spCh;
    scanf("%c", &spCh);

    removeSpecificCharacter(str,spCh);

    printf("%s\n",str);
}