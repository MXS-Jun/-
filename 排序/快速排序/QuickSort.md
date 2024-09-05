这段代码实现了一个基于快速排序算法的顺序表排序程序。下面是对代码的详细解释：

### 数据结构定义

```c
typedef struct
{
    int record[MAXSIZE + 1];
    int length;
} SeqList;
```

定义了一个顺序表结构 `SeqList`，其中 `record` 是一个数组，用于存储数据，`length` 表示当前顺序表的长度。

### 初始化顺序表

```c
void InitList(SeqList *list)
{
    list->length = 0;
}
```

初始化顺序表，将长度设置为0。

### 交换元素

```c
void Swap(SeqList *list, int i, int j)
{
    int tmp = (list->record)[i];
    (list->record)[i] = (list->record)[j];
    (list->record)[j] = tmp;
}
```

交换顺序表中两个位置的元素。

### 快速排序的辅助函数

#### 分区函数

```c
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
```

分区函数用于将数组分为两部分，左边的元素都小于等于基准值，右边的元素都大于等于基准值。根据 `type` 参数决定是升序还是降序。

#### 排序函数

```c
void Sort(SeqList *list, int low, int high, int type)
{
    if (low < high)
    {
        int pivot = Partition(list, low, high, type);

        Sort(list, low, pivot - 1, type);
        Sort(list, pivot + 1, high, type);
    }
}
```

递归地对分区后的两部分进行排序。

### 快速排序主函数

```c
void QuickSort(SeqList *list, int type)
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
```

根据 `type` 参数调用 `Sort` 函数进行排序。

### 打印顺序表

```c
void PrintList(SeqList *list)
{
    for (int i = 1; i < list->length; i++)
    {
        printf("%d ", (list->record)[i]);
    }
    printf("%d\n", (list->record)[list->length]);
}
```

打印顺序表中的所有元素。

### 清空顺序表

```c
void ClearList(SeqList *list)
{
    list->length = 0;
}
```

清空顺序表，将长度设置为0。

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

        QuickSort(&list, type);
        PrintList(&list);
        ClearList(&list);
    }

    return 0;
}
```

主函数中，首先初始化顺序表，然后进入一个无限循环，每次循环中读取用户输入的整数序列和排序类型，调用 `QuickSort` 函数进行排序，然后打印排序后的顺序表，最后清空顺序表。