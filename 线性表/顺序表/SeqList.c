#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAXSIZE 100

typedef struct
{
    int record[MAXSIZE];
    int length;
} SeqList;

void InitSeqList(SeqList *list);
int ClearSeqList(SeqList *list);
int GetLength(SeqList *list);
bool IsEmpty(SeqList *list);
void InsertElem(SeqList *list, int index, int elem);
void DeleteElem(SeqList *list, int index, int *elem);
int LocateElem(SeqList *list, int elem, int start);
int ReverseSeqList(SeqList *list);
int GetMaxElem(SeqList *list);
int GetMinElem(SeqList *list);
void PrintSeqList(SeqList *list);

int main(void)
{
    SeqList list;
    InitSeqList(&list);

    int func_num = 0;
    int index;
    int elem;

    while (true)
    {
        printf("1. 清空表\n");
        printf("2. 取表长\n");
        printf("3. 判空表\n");
        printf("4. 插入元素\n");
        printf("5. 删除元素\n");
        printf("6. 定位元素\n");
        printf("7. 逆置表\n");
        printf("8. 取最大元素\n");
        printf("9. 取最小元素\n");
        printf("10. 打印表\n");
        printf(">>");

        scanf("%d", &func_num);

        switch (func_num)
        {
        case 1:
            ClearSeqList(&list);
            printf("表已清空\n");
            break;
        case 2:
            printf("表长为%d\n", GetLength(&list));
            break;
        case 3:
            if (IsEmpty(&list))
            {
                printf("表空\n");
            }
            else
            {
                printf("表非空\n");
            }
            break;
        case 4:
            printf("输入插入位置\n>>");
            scanf("%d", &index);
            printf("输入插入的值\n>>");
            scanf("%d", &elem);
            InsertElem(&list, index, elem);
            break;
        case 5:
            printf("输入删除位置\n>>");
            scanf("%d", &index);
            DeleteElem(&list, index, &elem);
            break;
        case 6:
            printf("输入要定位的值\n>>");
            scanf("%d", &elem);
            index = LocateElem(&list, elem, 0);
            if (index == -1)
            {
                printf("没查找到\n");
            }
            else
            {
                printf("%d在位置%d处\n", elem, index);
            }
            break;
        case 7:
            ReverseSeqList(&list);
            printf("表逆置成功\n");
            break;
        case 8:
            printf("最大元素是%d\n", GetMaxElem(&list));
            break;
        case 9:
            printf("最小元素是%d\n", GetMinElem(&list));
            break;
        case 10:
            PrintSeqList(&list);
            break;
        default:
            printf("请输入合法的功能号\n");
            break;
        }
    }

    return 0;
}

void InitSeqList(SeqList *list)
{
    list->length = 0;
}

int ClearSeqList(SeqList *list)
{
    for (int i = 0; i < MAXSIZE; i++)
    {
        (list->record)[i] = 0;
    }
    list->length = 0;
}

int GetLength(SeqList *list)
{
    return list->length;
}

bool IsEmpty(SeqList *list)
{
    if (list->length == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void InsertElem(SeqList *list, int index, int elem)
{
    if (index > list->length || index < 0)
    {
        printf("The insert index is illegal.\n");
    }
    else
    {
        for (int i = list->length; i > index; i--)
        {
            (list->record)[i] = (list->record)[i - 1];
        }
        (list->record)[index] = elem;
        list->length++;
    }
}

void DeleteElem(SeqList *list, int index, int *elem)
{
    if (index > list->length || index < 0)
    {
        printf("The delete index is illegal.\n");
    }
    else
    {
        *elem = (list->record)[index];
        for (int i = index; i < list->length - 1; i++)
        {
            (list->record)[i] = (list->record)[i + 1];
        }
        list->length--;
    }
}

int LocateElem(SeqList *list, int elem, int start)
{
    if (start < 0 || start >= list->length)
    {
        printf("The locate start point is illegal.\n");
        return -1;
    }
    else
    {
        for (int i = start; i < list->length; i++)
        {
            if ((list->record)[i] == elem)
            {
                return i;
            }
        }
        return -1;
    }
}

int ReverseSeqList(SeqList *list)
{
    int tmp;
    for (int i = 0, j = list->length - 1; i < j; i++, j--)
    {
        tmp = (list->record)[i];
        (list->record)[i] = (list->record)[j];
        (list->record)[j] = tmp;
    }
}

int GetMaxElem(SeqList *list)
{
    int max = INT_MIN;
    for (int i = 0; i < list->length; i++)
    {
        if ((list->record)[i] > max)
        {
            max = (list->record)[i];
        }
    }
    return max;
}

int GetMinElem(SeqList *list)
{
    int min = INT_MAX;
    for (int i = 0; i < list->length; i++)
    {
        if ((list->record)[i] < min)
        {
            min = (list->record)[i];
        }
    }
    return min;
}

void PrintSeqList(SeqList *list)
{
    for (int i = 0; i < list->length; i++)
    {
        if (i < list->length - 1)
        {
            printf("%d ", (list->record)[i]);
        }
        else
        {
            printf("%d\n", (list->record)[list->length - 1]);
        }
    }
}
