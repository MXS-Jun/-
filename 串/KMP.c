#include <stdio.h>

#define MAXSIZE 100

void GetLine(char line[]);
void PrintLine(char line[]);
unsigned int GetLength(char line[]);
void GetNextArray(char substring[], unsigned int substring_length, int nextarray[]);
void PrintNextArray(int nextarray[], unsigned int substring_length);
int KMP(char line[], char substring[]);

int main(void)
{
    char line[MAXSIZE];
    char substring[MAXSIZE];

    while (1)
    {
        printf("Input the main-string: ");
        GetLine(line);
        printf("Input the sub-string: ");
        GetLine(substring);

        int start = KMP(line, substring);
        if (start == -1)
        {
            printf("Not found.\n");
        }
        else
        {
            printf("The start of sub-string in main-string is %d.\n", start);
        }
    }

    return 0;
}

void GetLine(char line[])
{
    char letter;
    unsigned int i = 0;
    while ((letter = getchar()) && (letter != '\n') && i < MAXSIZE - 1)
    {
        line[i] = letter;
        i++;
    }
    line[i] = '\0';
}

void PrintLine(char line[])
{
    unsigned int i = 0;
    while (line[i] != '\0')
    {
        printf("%c", line[i]);
        i++;
    }
    printf("\n");
}

unsigned int GetLength(char line[])
{
    unsigned int i = 0;
    while ((line[i]) != '\0')
    {
        i++;
    }
    return i;
}

void GetNextArray(char substring[], unsigned int substring_length, int nextarray[])
{
    if (substring_length > 0)
    {
        nextarray[0] = -1;
    }
    if (substring_length > 1)
    {
        nextarray[1] = 0;
    }
    if (substring_length > 2)
    {
        for (unsigned int i = 2; i < substring_length; i++)
        {
            int val = 0;
            for (unsigned int j = 0; j < i - 1; j++)
            {
                int tmp = 0;
                int flag = 0;
                for (int k = 0; k <= j; k++)
                {
                    if (substring[k] == substring[i - 1 - j + k])
                    {
                        tmp++;
                    }
                    else
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1)
                {
                    tmp = 0;
                }
                if (tmp > val)
                {
                    val = tmp;
                }
            }
            nextarray[i] = val;
        }
    }
}

void PrintNextArray(int nextarray[], unsigned int substring_length)
{
    for (unsigned int i = 0; i < substring_length; i++)
    {
        printf("%d", nextarray[i]);
    }
    printf("\n");
}

int KMP(char line[], char substring[])
{
    unsigned int line_length = GetLength(line);
    unsigned int substring_length = GetLength(substring);
    int nextarray[substring_length];
    GetNextArray(substring, substring_length, nextarray);

    int i = 0;
    int j = 0;

    while (i < line_length && j < substring_length)
    {
        if (j == -1 || line[i] == substring[j])
        {
            i++;
            j++;
        }
        else
        {
            j = nextarray[j];
        }
    }
    if (j >= substring_length)
    {
        return i - substring_length;
    }
    else
    {
        return -1;
    }
}