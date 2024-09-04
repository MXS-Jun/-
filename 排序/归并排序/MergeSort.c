#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct
{
    int record[MAXSIZE + 1];
    int length;
} SeqList;

void InitList(SeqList *list);
void Merge(SeqList *list, int start, int mid, int end, int type);
void Divide(SeqList *list, int start, int end, int type);
void MergeSort(SeqList *list, int type);
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

        MergeSort(&list, type);
        PrintList(&list);
        ClearList(&list);
    }

    return 0;
}

void InitList(SeqList *list)
{
    list->length = 0;
}

void Merge(SeqList *list, int start, int mid, int end, int type)
{
    int left_len = mid - start + 1;
    int right_len = end - mid;
    int left_tmp[left_len];
    int right_tmp[right_len];

    for (int i = 0; i < left_len; i++)
    {
        left_tmp[i] = (list->record)[start + i];
    }
    for (int i = 0; i < right_len; i++)
    {
        right_tmp[i] = (list->record)[mid + 1 + i];
    }

    int i;
    int j;
    int k = start;

    if (type == 0)
    {
        for (i = 0, j = 0; i < left_len && j < right_len; k++)
        {
            if (left_tmp[i] <= right_tmp[j])
            {
                (list->record)[k] = left_tmp[i];
                i++;
            }
            else
            {
                (list->record)[k] = right_tmp[j];
                j++;
            }
        }
    }

    if (type == 1)
    {
        for (i = 0, j = 0; i < left_len && j < right_len; k++)
        {
            if (left_tmp[i] >= right_tmp[j])
            {
                (list->record)[k] = left_tmp[i];
                i++;
            }
            else
            {
                (list->record)[k] = right_tmp[j];
                j++;
            }
        }
    }

    while (i < left_len)
    {
        (list->record)[k] = left_tmp[i];
        i++;
        k++;
    }

    while (j < right_len)
    {
        (list->record)[k] = right_tmp[j];
        j++;
        k++;
    }
}

void Divide(SeqList *list, int start, int end, int type)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;

        Divide(list, start, mid, type);
        Divide(list, mid + 1, end, type);
        Merge(list, start, mid, end, type);
    }
}

void MergeSort(SeqList *list, int type) // if type = 0 : ascend; if type = 1: descend;
{
    if (type == 0)
    {
        Divide(list, 1, list->length, 0);
    }
    else if (type == 1)
    {
        Divide(list, 1, list->length, 1);
    }
    else
    {
        printf("TYPE ERROR: Type can only be 0 or 1.\n");
        exit(1);
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