#include <stdio.h>

#define MAXSIZE 100

typedef struct
{
    int r[MAXSIZE + 1];
    int length;
} SqList;

void initList(SqList *sl);
void shellSort(SqList *sl, int type);
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

        shellSort(&list, type);
        printList(&list);
        clearList(&list);
    }

    return 0;
}

void initList(SqList *sl)
{
    sl->length = 0;
}

void shellSort(SqList *sl, int type) // if type = 0 : ascend; if type = 1: descend;
{
    int increment = sl->length;
    if (type == 0)
    {
        do
        {
            increment = increment / 3 + 1;

            for (int i = 1; i <= increment; i++)
            {
                if (i + increment <= sl->length)
                {
                    for (int j = i + increment; j <= sl->length; j += increment)
                    {
                        (sl->r)[0] = (sl->r)[j];
                        for (int k = i; k < j; k += increment)
                        {
                            if ((sl->r)[k] > (sl->r)[0])
                            {
                                for (int h = j; h > k; h -= increment)
                                {
                                    (sl->r)[h] = (sl->r)[h - increment];
                                }
                                (sl->r)[k] = (sl->r)[0];
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
                if (i + increment <= sl->length)
                {
                    for (int j = i + increment; j <= sl->length; j += increment)
                    {
                        (sl->r)[0] = (sl->r)[j];
                        for (int k = i; k < j; k += increment)
                        {
                            if ((sl->r)[k] < (sl->r)[0])
                            {
                                for (int h = j; h > k; h -= increment)
                                {
                                    (sl->r)[h] = (sl->r)[h - increment];
                                }
                                (sl->r)[k] = (sl->r)[0];
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