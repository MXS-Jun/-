这段代码实现了一个基于归并排序的顺序表排序功能。下面是对代码的详细解释：

### 数据结构定义

```c
typedef struct
{
    int record[MAXSIZE + 1];
    int length;
} SeqList;
```

- `SeqList` 结构体定义了一个顺序表，其中 `record` 是一个数组，用于存储数据，`length` 表示当前顺序表的长度。

### 初始化顺序表

```c
void InitList(SeqList *list)
{
    list->length = 0;
}
```

- `InitList` 函数用于初始化顺序表，将长度设置为0。

### 归并排序相关函数

#### 归并函数

```c
void Merge(SeqList *list, int start, int mid, int end, int type)
```

- `Merge` 函数用于将两个有序子序列合并成一个有序序列。
- `start`、`mid`、`end` 分别表示两个子序列的起始和结束位置。
- `type` 表示排序类型，0表示升序，1表示降序。

#### 分割函数

```c
void Divide(SeqList *list, int start, int end, int type)
```

- `Divide` 函数用于递归地将顺序表分割成更小的子序列，直到每个子序列只有一个元素。
- `start` 和 `end` 分别表示当前子序列的起始和结束位置。

#### 归并排序主函数

```c
void MergeSort(SeqList *list, int type)
```

- `MergeSort` 函数是归并排序的主函数，根据 `type` 的值决定是升序还是降序排序。

### 辅助函数

#### 打印顺序表

```c
void PrintList(SeqList *list)
```

- `PrintList` 函数用于打印顺序表中的所有元素。

#### 清空顺序表

```c
void ClearList(SeqList *list)
```

- `ClearList` 函数用于清空顺序表，将长度设置为0。

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

        MergeSort(&list, type);
        PrintList(&list);
        ClearList(&list);
    }

    return 0;
}
```

- 主函数中，首先初始化顺序表，然后进入一个无限循环。
- 在循环中，用户可以输入一组整数，并选择排序类型（升序或降序）。
- 调用 `MergeSort` 函数进行排序，然后调用 `PrintList` 函数打印排序后的顺序表，最后调用 `ClearList` 函数清空顺序表，以便进行下一次输入和排序。

### 注意事项

- 代码中使用了宏定义 `MAXSIZE` 来限制顺序表的最大长度为100。
- 在输入数据时，用户可以输入多个整数，直到输入的整数个数达到100或者用户按下回车键。
- 代码中没有对输入的数据进行错误检查，例如输入非整数的情况。在实际应用中，可能需要添加相应的错误处理机制。