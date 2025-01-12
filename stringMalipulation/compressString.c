#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



char *CompressString(char *strOriginal, char *strComp)
{

    char *strOrgPointer = strOriginal;
    char *strCompPointer = strComp;

    int size = strlen(strOriginal);

    int count_cons_ch = 0;
    bool flag = false;

    char cur_Ch = *strOrgPointer;

    while (*strOrgPointer)
    {

        if (*strOrgPointer == cur_Ch)
        {
            count_cons_ch++;
            strOrgPointer++;
        }
        else
        {
            if (count_cons_ch > 1)
            {
                flag = true;
            }
            *strCompPointer = cur_Ch;
            strCompPointer++;

            char numbers[10];
            int noNum = 0;
            while (count_cons_ch != 0)
            {
                int num = count_cons_ch % 10;
                numbers[noNum++] = '0' + num;
                count_cons_ch = count_cons_ch / 10;
            }

            for (int i = noNum - 1; i >= 0; i--)
            {
                *strCompPointer = numbers[i];
                strCompPointer++;
            }

            cur_Ch = *strOrgPointer;
        }

        if (*strOrgPointer == '\0')
        {
            *strCompPointer = cur_Ch;
            strCompPointer++;
            char numbers[10];
            int noNum = 0;
            while (count_cons_ch != 0)
            {
                int num = count_cons_ch % 10;
                numbers[noNum++] = '0' + num;
                count_cons_ch = count_cons_ch / 10;
            }

            for (int i = noNum - 1; i >= 0; i--)
            {
                *strCompPointer = numbers[i];
                strCompPointer++;
            }

            *strCompPointer = '\0';
        }
    }

    if (flag)
    {
        return strComp;
    }
    return strOriginal;
}

int main()
{
    char str[100];
    printf("Enter :");
    scanf(" %[^\n]%*c", str);

    char compString[100];

    char *finalstrCompPointer = CompressString(str, compString);
    printf("%s\n", finalstrCompPointer);

    return 0;
}