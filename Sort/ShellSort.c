#include <stdio.h>

#define MAXSIZE 100

typedef struct
{
    int record[MAXSIZE + 1];
    int length;
} SeqList;

void InitList(SeqList *list);
void ShellSort(SeqList *list, int type);
void PrintList(SeqList *list);
void ClearList(SeqList *list);

int main(void)
{
    SeqList list;
    int value;
    InitList(&list);

    while (1)
    {
        int n = 1;
        printf("Enter the SeqList (less than 100 integers separated by blank) : ");
        while (scanf("%d", &value) == 1 && n < MAXSIZE)
        {
            (list.record)[n++] = value;
            list.length++;
            if (getchar() == '\n')
            {
                break;
            }
        }
        int type;
        printf("Enter the type (ascend:0, descend:1) :");
        scanf("%d", &type);

        ShellSort(&list, type);
        PrintList(&list);
        ClearList(&list);
    }

    return 0;
}

void InitList(SeqList *list)
{
    list->length = 0;
}

void ShellSort(SeqList *list, int type) // if type = 0 : ascend; if type = 1: descend;
{
    int increment = list->length;
    if (type == 0)
    {
        do
        {
            increment = increment / 3 + 1;

            for (int i = 1; i <= increment; i++)
            {
                if (i + increment <= list->length)
                {
                    for (int j = i + increment; j <= list->length; j += increment)
                    {
                        (list->record)[0] = (list->record)[j];
                        for (int k = i; k < j; k += increment)
                        {
                            if ((list->record)[k] > (list->record)[0])
                            {
                                for (int h = j; h > k; h -= increment)
                                {
                                    (list->record)[h] = (list->record)[h - increment];
                                }
                                (list->record)[k] = (list->record)[0];
                                break;
                            }
                        }
                    }
                }
            }
        } while (increment > 1);
    }
    else if (type == 1)
    {
        do
        {
            increment = increment / 3 + 1;

            for (int i = 1; i <= increment; i++)
            {
                if (i + increment <= list->length)
                {
                    for (int j = i + increment; j <= list->length; j += increment)
                    {
                        (list->record)[0] = (list->record)[j];
                        for (int k = i; k < j; k += increment)
                        {
                            if ((list->record)[k] < (list->record)[0])
                            {
                                for (int h = j; h > k; h -= increment)
                                {
                                    (list->record)[h] = (list->record)[h - increment];
                                }
                                (list->record)[k] = (list->record)[0];
                                break;
                            }
                        }
                    }
                }
            }
        } while (increment > 1);
    }
    else
    {
        printf("TYPE ERROR: Type can only be 0 or 1.\n");
    }
}

void PrintList(SeqList *list)
{
    for (int i = 1; i <= list->length; i++)
    {
        printf("%d ", (list->record)[i]);
    }
    printf("\n");
}

void ClearList(SeqList *list)
{
    list->length = 0;
}