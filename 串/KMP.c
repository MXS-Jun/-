#include <stdio.h>

void GetLine(char *line);
void PrintLine(char *line);
unsigned int GetLength(char *line);
void GetNextArray(char *substring, unsigned int substring_length, int nextarray[]);
void PrintNextArray(int nextarray[], unsigned int substring_length);
void KMP(char *line, char *substring);

int main(void)
{
    char *line;
    char *substring;

    GetLine(line);
    GetLine(substring);

    unsigned int line_length = GetLength(line);
    unsigned int substring_length = GetLength(substring);

    int nextarray[substring_length];
    GetNextArray(substring, substring_length, nextarray);
    PrintNextArray(nextarray, substring_length);

    return 0;
}

void GetLine(char *line)
{
    char letter;
    unsigned int i = 0;
    while ((letter = getchar()) && (letter != '\n'))
    {
        line[i] = letter;
        i++;
    }
    line[i] = '\0';
}

void PrintLine(char *line)
{
    unsigned int i = 0;
    while (line[i] != '\0')
    {
        printf("%c", line[i]);
        i++;
    }
    printf("\n");
}

unsigned int GetLength(char *line)
{
    unsigned int i = 0;
    while ((line[i]) != '\0')
    {
        i++;
    }
    return i;
}

void GetNextArray(char *substring, unsigned int substring_length, int nextarray[])
{
    if (substring_length > 0)
    {
        nextarray[0] = -1;
    }
    if (substring_length > 1)
    {
        nextarray[1] = 1;
    }
    if (substring_length > 2)
    {
        for (unsigned int i = 2; i < substring_length; i++)
        {
            int val = 0;
            for (unsigned int j = 0; j < i - 1; j++)
            {
                int tmp = 0;
                for (int k = 0; k <= j; k++)
                {
                    if (substring[k] = substring[i - 1 - j + k])
                    {
                        tmp++;
                    }
                    else
                    {
                        break;
                    }
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
}

void KMP(char *line, char *substring)
{
    unsigned int line_length = GetLength(line);
    unsigned int substring_length = GetLength(substring);
}