这段代码实现了一个基于归并排序的顺序表排序功能。下面是对代码的详细解释：

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

### 归并排序相关函数

#### 归并函数

```c
void Merge(SeqList *list, int start, int mid, int end, int type)
```

该函数用于将两个有序子序列合并成一个有序序列。`start` 和 `mid` 是左子序列的起始和结束位置，`end` 是右子序列的结束位置，`type` 决定排序顺序（升序或降序）。

#### 分割函数

```c
void Divide(SeqList *list, int start, int end, int type)
```

该函数用于递归地将顺序表分割成更小的子序列，直到每个子序列只有一个元素。然后调用 `Merge` 函数进行合并。

#### 归并排序主函数

```c
void MergeSort(SeqList *list, int type)
```

根据 `type` 的值（0表示升序，1表示降序），调用 `Divide` 函数进行归并排序。

### 辅助函数

#### 打印顺序表

```c
void PrintList(SeqList *list)
```

打印顺序表中的所有元素。

#### 清空顺序表

```c
void ClearList(SeqList *list)
```

将顺序表的长度重置为0，清空顺序表。

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

主函数中，首先初始化顺序表，然后进入一个无限循环，每次循环中：

1. 读取用户输入的整数序列，直到输入的整数个数达到最大值100或用户按下回车键。
2. 读取排序类型（升序或降序）。
3. 调用 `MergeSort` 函数进行排序。
4. 调用 `PrintList` 函数打印排序后的顺序表。
5. 调用 `ClearList` 函数清空顺序表，准备下一次输入。

### 注意事项

1. 代码中使用了宏定义 `MAXSIZE` 来限制顺序表的最大长度为100。
2. 在读取用户输入时，使用了 `getchar()` 来处理输入中的空格和换行符，确保正确读取整数。
3. 在 `MergeSort` 函数中，如果 `type` 不是0或1，程序会输出错误信息并退出。