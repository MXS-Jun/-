这段代码实现了一个KMP（Knuth-Morris-Pratt）字符串匹配算法。KMP算法是一种高效的字符串匹配算法，它通过预处理模式串（即要匹配的子字符串），生成一个部分匹配表（也称为next数组），从而在匹配过程中避免重复比较，提高匹配效率。

### 实现原理

1. **生成next数组**：next数组用于记录模式串中每个位置的最长相同前后缀的长度。生成next数组的过程是算法的核心，它决定了模式串在匹配失败时应该回退的位置。

2. **字符串匹配**：在得到next数组后，使用它来进行字符串匹配。匹配过程中，如果字符不匹配，则根据next数组决定模式串的下一个匹配位置。

### 主要函数

- `GetLine(char line[])`：从标准输入读取一行字符，存储到数组`line`中。
- `PrintLine(char line[])`：打印数组`line`中的字符。
- `GetLength(char line[])`：计算数组`line`的长度。
- `GetNextArray(char substring[], unsigned int substring_length, int nextarray[])`：生成模式串的next数组。
- `PrintNextArray(int nextarray[], unsigned int substring_length)`：打印next数组。
- `KMP(char line[], char substring[])`：使用KMP算法在主字符串`line`中查找子字符串`substring`的位置。

### 注意事项

- 在`GetLine`函数中，使用`getchar()`逐个读取字符，直到遇到换行符或达到最大长度限制。
- `GetNextArray`函数中，next数组的计算较为复杂，需要理解前后缀的概念。
- `KMP`函数中，匹配过程通过比较主字符串和模式串的字符，并根据next数组决定模式串的移动。

### 用途

这段代码可以用于文本编辑器、搜索引擎等需要快速匹配字符串的场景，提高匹配效率。