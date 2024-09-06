#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct
{
    int record[MAXSIZE + 1];
    int length;
} SeqList;

void InitList(SeqList *list);
void Swap(SeqList *list, int i, int j);
void HeapAdjust(SeqList *list, int root, int size, int type);
void HeapSort(SeqList *list, int type);
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

        HeapSort(&list, type);
        PrintList(&list);
        ClearList(&list);
    }

    return 0;
}

void InitList(SeqList *list)
{
    list->length = 0;
}

void Swap(SeqList *list, int i, int j)
{
    int tmp = (list->record)[i];
    (list->record)[i] = (list->record)[j];
    (list->record)[j] = tmp;
}

void HeapAdjust(SeqList *list, int root, int size, int type)
{
    if (type == 0)
    {
        int tmp = (list->record)[root];

        for (int j = 2 * root; j <= size; j = 2 * root)
        {
            if (j < size && (list->record)[j] < (list->record)[j + 1])
            {
                j++;
            }

            if (tmp > (list->record)[j])
            {
                break;
            }

            (list->record)[root] = (list->record)[j];
            root = j;
        }

        (list->record)[root] = tmp;
    }
    else
    {
        int tmp = (list->record)[root];

        for (int j = 2 * root; j <= size; j = 2 * root)
        {
            if (j < size && (list->record)[j] > (list->record)[j + 1])
            {
                j++;
            }

            if (tmp < (list->record)[j])
            {
                break;
            }

            (list->record)[root] = (list->record)[j];
            root = j;
        }

        (list->record)[root] = tmp;
    }
}

void HeapSort(SeqList *list, int type) // if type = 0 : ascend; if type = 1: descend;
{
    if (type == 0)
    {
        for (int i = (list->length) / 2; i > 0; i--)
        {
            HeapAdjust(list, i, list->length, 0);
        }

        for (int i = list->length; i > 1; i--)
        {
            Swap(list, 1, i);
            HeapAdjust(list, 1, i - 1, 0);
        }
    }
    else if (type == 1)
    {
        for (int i = (list->length) / 2; i > 0; i--)
        {
            HeapAdjust(list, i, list->length, 1);
        }

        for (int i = list->length; i > 1; i--)
        {
            Swap(list, 1, i);
            HeapAdjust(list, 1, i - 1, 1);
        }
    }
    else
    {
        printf("TYPE ERROR: Type can only be 0 or 1.\n");
        exit(0);
    }
}

void PrintList(SeqList *list)
{
    for (int i = 1; i < list->length; i++)
    {
        printf("%d ", (list->record)[i]);
    }
    printf("%d\n", (list->record)[list->length]);
}

void ClearList(SeqList *list)
{
    list->length = 0;
}