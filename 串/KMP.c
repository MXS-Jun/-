#include <stdio.h>

void GetLine(char *line);
void PrintLine(char *line);
unsigned int GetLength(char *line);
int *GetNextArray(char *substring);
void KMP(char *line, char *substring);

int main(void)
{
    char *line;

    GetLine(line);

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

int *GetNextArray(char *substring)
{
    unsigned int substring_length = GetLength(substring);
    int nextarray[substring_length];

    nextarray[0] = -1;
    for (unsigned int i = 1; i < substring_length; i++)
    {
        for(unsigned int j=0; j<i;j++)
        {
            for(int k=0;k<j;k++)
            {
                
            }
        }
    }
}

void KMP(char *line, char *substring)
{
    unsigned int line_length = GetLength(line);
    unsigned int substring_length = GetLength(substring);
}