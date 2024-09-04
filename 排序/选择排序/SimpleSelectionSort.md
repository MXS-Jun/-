这段代码实现了一个简单的顺序表（SeqList）及其排序功能。下面是对代码的详细解释：

### 1. 数据结构定义

```c
typedef struct
{
    int record[MAXSIZE + 1];
    int length;
} SeqList;
```

- `SeqList` 是一个结构体，包含一个整型数组 `record` 和一个整型变量 `length`。
- `record` 数组用于存储顺序表的元素，数组大小为 `MAXSIZE + 1`，其中 `MAXSIZE` 是定义的最大元素数量（100）。
- `length` 记录当前顺序表中实际存储的元素数量。

### 2. 函数定义

#### 初始化顺序表

```c
void InitList(SeqList *list)
{
    list->length = 0;
}
```

- `InitList` 函数用于初始化顺序表，将 `length` 设置为 0。

#### 交换元素

```c
void Swap(SeqList *list, int i, int j)
{
    int tmp = (list->record)[i];
    (list->record)[i] = (list->record)[j];
    (list->record)[j] = tmp;
}
```

- `Swap` 函数用于交换顺序表中索引 `i` 和 `j` 处的元素。

#### 简单选择排序

```c
void SimpleSelectionSort(SeqList *list, int type)
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
```

- `SimpleSelectionSort` 函数实现了简单选择排序算法。
- 根据传入的 `type` 参数，决定是升序（`type == 0`）还是降序（`type == 1`）排序。
- 如果 `type` 不是 0 或 1，则输出错误信息。

#### 打印顺序表

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

- `PrintList` 函数用于打印顺序表中的所有元素。

#### 清空顺序表

```c
void ClearList(SeqList *list)
{
    list->length = 0;
}
```

- `ClearList` 函数用于清空顺序表，将 `length` 设置为 0。

### 3. 主函数

```c
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
```

- 主函数中，首先初始化一个顺序表 `list`。
- 使用一个无限循环，允许用户多次输入顺序表并进行排序。
- 用户输入顺序表时，最多输入 100 个整数，以空格分隔。
- 用户输入排序类型（升序或降序）。
- 调用 `SimpleSelectionSort` 函数进行排序，然后调用 `PrintList` 函数打印排序后的顺序表。
- 最后调用 `ClearList` 函数清空顺序表，以便下一次输入。

### 注意事项

- 代码中使用了 `MAXSIZE` 作为顺序表的最大容量，确保用户输入的元素数量不超过这个限制。
- 在输入顺序表时，如果用户输入的元素数量超过 100，程序不会报错，但只会处理前 100 个元素。
- 代码中没有对输入的合法性进行严格检查，例如输入非整数的情况。在实际应用中，可能需要添加相应的错误处理机制。