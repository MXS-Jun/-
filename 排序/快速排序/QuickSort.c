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
void Sort(SeqList *list, int low, int high, int type);
int Partition(SeqList *list, int low, int high, int type);
void QuickSort(SeqList *list, int type);
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

        QuickSort(&list, type);
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

void Sort(SeqList *list, int low, int high, int type)
{
    if (low < high)
    {
        int pivot = Partition(list, low, high, type);

        Sort(list, low, pivot - 1, type);
        Sort(list, pivot + 1, high, type);
    }
}

int Partition(SeqList *list, int low, int high, int type)
{
    int pivot_key = (list->record)[low];

    while (low < high)
    {
        if (type == 0)
        {
            while (low < high && (list->record)[high] > pivot_key)
            {
                high--;
            }
            Swap(list, low, high);
            while (low < high && (list->record)[low] < pivot_key)
            {
                low++;
            }
            Swap(list, low, high);
        }
        else
        {
            while (low < high && (list->record)[high] < pivot_key)
            {
                high--;
            }
            Swap(list, low, high);
            while (low < high && (list->record)[low] > pivot_key)
            {
                low++;
            }
            Swap(list, low, high);
        }
    }

    return low;
}

void QuickSort(SeqList *list, int type) // if type = 0 : ascend; if type = 1: descend;
{
    if (type == 0)
    {
        Sort(list, 1, list->length, 0);
    }
    else if (type == 1)
    {
        Sort(list, 1, list->length, 1);
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