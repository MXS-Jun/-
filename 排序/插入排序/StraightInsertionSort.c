#include <stdio.h>

#define MAXSIZE 100

typedef struct
{
    int record[MAXSIZE + 1];
    int length;
} SeqList;

void InitList(SeqList *list);
void StraightInsertionSort(SeqList *list, int type);
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

        StraightInsertionSort(&list, type);
        PrintList(&list);
        ClearList(&list);
    }

    return 0;
}

void InitList(SeqList *list)
{
    list->length = 0;
}

void StraightInsertionSort(SeqList *list, int type) // if type = 0 : ascend; if type = 1: descend;
{
    if (type == 0)
    {
        for (int i = 2; i <= list->length; i++)
        {
            (list->record)[0] = (list->record)[i];
            for (int j = 1; j < i; j++)
            {
                if ((list->record)[0] <= (list->record)[j])
                {
                    for (int k = i; k > j; k--)
                    {
                        (list->record)[k] = (list->record)[k - 1];
                    }
                    (list->record)[j] = (list->record)[0];
                    break;
                }
            }
        }
    }
    else if (type == 1)
    {
        for (int i = 2; i <= list->length; i++)
        {
            (list->record)[0] = (list->record)[i];
            for (int j = 1; j < i; j++)
            {
                if ((list->record)[0] >= (list->record)[j])
                {
                    for (int k = i; k > j; k--)
                    {
                        (list->record)[k] = (list->record)[k - 1];
                    }
                    (list->record)[j] = (list->record)[0];
                    break;
                }
            }
        }
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