#include <stdio.h>

#define MAXSIZE 100

typedef struct
{
    int record[MAXSIZE + 1];
    int length;
} SeqList;

void Swap(SeqList *list, int i, int j);
void InitList(SeqList *list);
void SimpleSelectionSort(SeqList *list, int type);
void PrintList(SeqList *list);
void ClearList(SeqList *list);

int main(void)
{
    SeqList list;
    InitList(&list);
    int value;

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

        SimpleSelectionSort(&list, type);
        PrintList(&list);
        ClearList(&list);
    }

    return 0;
}

void Swap(SeqList *list, int i, int j)
{
    int tmp = (list->record)[i];
    (list->record)[i] = (list->record)[j];
    (list->record)[j] = tmp;
}

void InitList(SeqList *list)
{
    list->length = 0;
}

void SimpleSelectionSort(SeqList *list, int type) // if type = 0 : ascend; if type = 1: descend;
{
    if (type == 0)
    {
        for (int i = 1; i < list->length; i++)
        {
            for (int j = i + 1; j <= list->length; j++)
            {
                if ((list->record)[i] > (list->record)[j])
                {
                    Swap(list, i, j);
                }
            }
        }
    }
    else if (type == 1)
    {
        for (int i = 1; i < list->length; i++)
        {
            for (int j = i + 1; j <= list->length; j++)
            {
                if ((list->record)[i] < (list->record)[j])
                {
                    Swap(list, i, j);
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