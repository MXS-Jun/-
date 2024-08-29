#include <stdio.h>

#define MAXSIZE 100

typedef struct
{
    int r[MAXSIZE + 1];
    int length;
} SqList;

void initList(SqList *sl);
void swap(SqList *sl, int i, int j);
void bubbleSort(SqList *sl, int type);
void printList(SqList *sl);
void clearList(SqList *sl);

int main(void)
{
    SqList list;
    int value;
    initList(&list);

    while (1)
    {
        int n = 1;
        printf("Enter the SqList (less than 100 integers separated by blank) : ");
        while (scanf("%d", &value) == 1 && n < MAXSIZE)
        {
            (list.r)[n++] = value;
            list.length++;
            if (getchar() == '\n')
            {
                break;
            }
        }
        int type;
        printf("Enter the type (ascend:0, descend:1) :");
        scanf("%d", &type);

        bubbleSort(&list, type);
        printList(&list);
        clearList(&list);
    }

    return 0;
}

void initList(SqList *sl)
{
    sl->length = 0;
}

void swap(SqList *sl, int i, int j)
{
    int tmp = (sl->r)[i];
    (sl->r)[i] = (sl->r)[j];
    (sl->r)[j] = tmp;
}

void bubbleSort(SqList *sl, int type) // if type = 0 : ascend; if type = 1: descend;
{
    if (type == 0)
    {
        for (int i = sl->length; i > 1; i--)
        {
            for (int j = 1; j < i; j++)
            {
                if ((sl->r)[j] > (sl->r)[j + 1])
                {
                    swap(sl, j, j + 1);
                }
            }
        }
    }
    else if (type == 1)
    {
        for (int i = sl->length; i > 1; i--)
        {
            for (int j = 1; j < i; j++)
            {
                if ((sl->r)[j] < (sl->r)[j + 1])
                {
                    swap(sl, j, j + 1);
                }
            }
        }
    }
    else
    {
        printf("TYPE ERROR: Type can only be 0 or 1.\n");
    }
}

void printList(SqList *sl)
{
    for (int i = 1; i <= sl->length; i++)
    {
        printf("%d ", (sl->r)[i]);
    }
    printf("\n");
}

void clearList(SqList *sl)
{
    sl->length = 0;
}