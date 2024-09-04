这段代码实现了一个顺序表（SeqList）的初始化、插入排序、打印和清空功能。以下是代码的详细解释：

### 数据结构定义
```c
typedef struct
{
    int record[MAXSIZE + 1];
    int length;
} SeqList;
```
定义了一个顺序表结构体，其中`record`是一个数组，用于存储数据，`length`表示当前顺序表的长度。

### 函数定义
1. **初始化顺序表**
```c
void InitList(SeqList *list)
{
    list->length = 0;
}
```
初始化顺序表，将长度设置为0。

2. **直接插入排序**
```c
void StraightInsertionSort(SeqList *list, int type)
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
```
实现直接插入排序。根据`type`参数，决定是升序（`type=0`）还是降序（`type=1`）排序。排序过程中，使用了一个哨兵元素`record[0]`来简化插入操作。

3. **打印顺序表**
```c
void PrintList(SeqList *list)
{
    for (int i = 1; i <= list->length; i++)
    {
        printf("%d ", (list->record)[i]);
    }
    printf("\n");
}
```
打印顺序表中的所有元素。

4. **清空顺序表**
```c
void ClearList(SeqList *list)
{
    list->length = 0;
}
```
将顺序表的长度设置为0，实现清空操作。

### 主函数
```c
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
```
主函数中，首先初始化顺序表。然后进入一个无限循环，每次循环中：
1. 提示用户输入顺序表的元素，直到输入100个元素或遇到换行符。
2. 提示用户输入排序类型（升序或降序）。
3. 调用`StraightInsertionSort`函数进行排序。
4. 调用`PrintList`函数打印排序后的顺序表。
5. 调用`ClearList`函数清空顺序表，以便下一次输入。

### 注意事项
1. 顺序表的最大长度为100，由`MAXSIZE`定义。
2. 输入顺序表时，最多只能输入100个整数，且整数之间用空格分隔。
3. 排序类型只能为0（升序）或1（降序），否则会提示类型错误。
4. 程序运行后会不断循环，直到手动终止（如通过关闭程序窗口）。