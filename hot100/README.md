# LeetCode 热题 100：C++ 中文题解与知识点总结

> 榜单来源：[LeetCode 热题 100](https://leetcode.cn/studyplan/top-100-liked/)（按 2026-09-07 页面当前清单整理）  
> 内容：100 道题、100 份 C++ 解法、17 个专题；每题都有核心思路、复杂度和详细中文注释。

## 如何使用

1. 先读专题的“核心知识”，再看对应题目的 C++ 文件。
2. 每个源文件开头都写明 **核心思路、时间/空间复杂度和易错点**，正文逐段解释代码。
3. 初学者建议先自己画出状态或指针变化，再对照代码；不要一开始就追求最短写法。
4. 本地语法检查示例：

```bash
g++ -std=c++17 -Wall -Wextra -pedantic -DLOCAL_LEETCODE_TYPES -Itests \
  -fsyntax-only solutions/0001_two_sum.cpp
```

链表/树文件里的节点定义通过 `LOCAL_LEETCODE_TYPES` 保护：本地使用上一条命令，直接提交到力扣时力扣已提供这些类型，因此无需删除源代码。

## 建议学习路线

- **第一轮（数组/哈希/双指针/滑窗）**：建立循环、边界和复杂度直觉。
- **第二轮（链表/栈/堆/二分）**：掌握常见指针结构和数据结构接口。
- **第三轮（树/图/回溯）**：练习递归、遍历和搜索树的剪枝。
- **第四轮（贪心/动态规划）**：先会定义状态与解释转移，再考虑滚动数组等优化。
- 每做完一类题，回到“专题总览”比较不同题目共同的不变量。

## 专题总览

- **哈希**：用空间换时间：快速查值、分组和记录前缀状态。榜单用它完成两数匹配、异位词分类、连续序列以及前缀和计数。

- **双指针**：两个指针按题设顺序移动，用于缩小搜索空间。榜单用它完成原地重排、区间夹逼和排序后的三数搜索。

- **滑动窗口**：维护满足条件的连续区间，通常“右端扩张、左端收缩”。榜单用它处理最长无重复、异位词窗口和最小覆盖。

- **子串**：把“连续区间”问题转换为状态记录：前缀和、单调队列或需求计数。

- **普通数组**：扫描、排序、前缀积和原地标记。重点学习边界收缩与 O(1) 额外空间。

- **矩阵**：按遍历顺序或坐标性质处理二维结构，如四边界收缩、转置旋转和行列标记。

- **链表**：重点掌握哑结点、快慢指针、迭代反转、归并与数据结构组合；与数组相比不能随机访问。

- **二叉树**：重点练习递归定义、DFS 前中后序、BFS 分层和“当前节点向子树返回什么”的后序 DP。

- **图论**：重点学习 DFS/BFS、多源 BFS、入度拓扑排序和 Trie 前缀树。

- **回溯**：统一模板是“做选择 → 递归 → 撤销选择”，再通过 start、visited 或边界约束去重。

- **二分查找**：在单调性或“可判断性质”上二分；统一用左闭右开或左闭右闭边界，并明确保留哪一侧。

- **栈**：利用 LIFO 处理匹配、嵌套、单调递增/递减序列和“下一个更大元素”关系。

- **堆**：堆顶维护当前候选极值；适合动态数据流、前 K 大/小元素与多路合并。

- **贪心算法**：每一步保留当前最优选择；需要能理解为什么局部最优不会破坏最终答案。

- **动态规划**：先定义状态，再找状态转移和边界；数组、背包、子序列和区间问题都遵循这一流程。

- **多维动态规划**：二维状态描述两个前缀/两个坐标之间的关系，重点关注边界初始化和滚动数组优化。

- **技巧**：位运算、投票法、双指针和环检测等 O(1) 空间技巧，核心是识别数据或操作的代数性质。

## 零基础怎么读这些代码

### 先看变量，再看循环

看到一段算法代码时，不要先逐行翻译，而要先回答四个问题：

1. 这个变量代表什么？例如 `left/right` 是搜索边界，`dp[i]` 是某种最优值，`visited` 是已访问状态。
2. 循环的一轮做了什么？是扫描一个元素、扩展一个窗口，还是枚举一种选择？
3. 状态之间怎么转移？新状态是否依赖之前的状态？
4. 循环结束或返回值代表什么？

例如最长连续序列中：

```cpp
while (values.count(end + 1)) {
    ++end;
}
best = max(best, end - x + 1);
```

这里 `x` 是当前连续序列的起点，`end` 是不断向右扩展后能够到达的终点。因为只在 `x-1` 不存在时才开始扩展，每个数字最多只会参与一次，所以平均复杂度是 O(n)。

### 动态规划：先把“状态”说清楚

动态规划不是一种固定套路，而是一种把“重复计算的子问题”保存下来的方法。每次做 DP，都按下面顺序写：

1. **定义状态**：`dp[i]` 到底是什么？
2. **确定选择**：当前状态依赖哪些更小的状态？
3. **写转移方程**：一个状态怎么由已知状态推出？
4. **初始化边界**：空数组、第 0 个元素、容量为 0 时答案是什么？
5. **确定最终答案**：答案是整个数组的状态，还是所有状态的最大值？

#### 线性 DP

| 题目 | 状态定义 | 转移关系 | 为什么这样写 |
|---|---|---|---|
| 70 爬楼梯 | `dp[i]` 是到第 i 阶的方法数 | `dp[i] = dp[i-1] + dp[i-2]` | 最后一步要么来自第 i-1 阶，要么来自第 i-2 阶 |
| 198 打家劫舍 | `dp[i]` 是考虑前 i 户的最大收益 | `dp[i] = max(dp[i-1], dp[i-2] + nums[i])` | 当前户要么不偷，要么偷但不能偷前一户 |
| 53 最大子数组和 | `ending[i]` 是必须以 i 结尾的最大和 | `ending[i] = max(nums[i], ending[i-1] + nums[i])` | 前缀和变成负数后，从当前元素重新开始 |
| 300 最长递增子序列 | `tails[len]` 是长度 len+1 的最小末尾值 | 找到第一个大于等于当前值的位置后更新 | 末尾越小，后面越容易接上更多元素 |
| 152 乘积最大子数组 | 同时保存 `ending_max`、`ending_min` | 二者都由当前值、上一个最大、上一个最小推出 | 负数乘负数可能变成更大的正数，必须同时保留两种状态 |

读代码时，先把变量名翻译成状态。例如：

```cpp
int ending = nums[0];
int answer = nums[0];
```

在 53 题中，`ending` 是“必须包含当前位置”的局部答案，`answer` 是“已经看过的所有位置中的全局答案”。这两个变量职责不同，不能都理解成普通最大值。

#### 背包 DP

零钱兑换 322 和完全平方数 279 属于完全背包：

```cpp
for (int coin : coins) {
    for (int value = coin; value <= amount; ++value) {
        dp[value] = min(dp[value], dp[value - coin] + 1);
    }
}
```

内层从小到大，表示同一种硬币可以被重复使用。分割等和子集 416 则是 0-1 背包，内层必须从大到小：

```cpp
for (int sum = target; sum >= value; --sum) {
    dp[sum] = dp[sum] || dp[sum - value];
}
```

倒序是为了保证当前元素在一轮内最多使用一次。如果你把 0-1 背包写成正序，就可能用同一个元素多次凑和。

#### 字符串/二维 DP

- **139 单词拆分**：`dp[i]` 表示前缀 `s[0..i)` 能否拆分。只要找到一个 `dp[left]` 为真且中间片段在字典中，就可以得到 `dp[right]`。
- **1143 最长公共子序列**：`dp[i][j]` 表示 `text1` 前 i 个字符和 `text2` 前 j 个字符的 LCS 长度。
- **72 编辑距离**：`dp[i][j]` 表示把前 i 个字符转换成前 j 个字符所需的最少操作数。
- **62 不同路径**：到达一格只能从上方或左方来，所以路径数是两个来源之和。
- **64 最小路径和**：当前格代价加上上方和左方较小的代价。

二维 DP 的关键不是画一个很大的表格，而是知道每一格由哪些相邻格子转移而来。代码中的滚动数组只是把二维表格压缩成一维。

### 二叉树：重点看“递归函数返回什么”

树题通常不是先模拟所有节点，而是假设子树已经得到正确答案，再用子树答案计算当前节点答案。

#### 前中后序的本质

- **前序**：先处理当前节点，再处理左右子树。
- **中序**：先处理左子树，再处理当前节点，最后右子树。
- **后序**：先处理左右子树，再处理当前节点。

题 94 中序遍历用栈模拟递归：先把整条左链压入栈，然后弹出节点，再转向右子树。

#### “返回高度”和“更新答案”要分开

543 二叉树直径中：

```cpp
int height(TreeNode* node) {
    int left = height(node->left);
    int right = height(node->right);
    best = max(best, left + right);
    return 1 + max(left, right);
}
```

`return` 的是“经过当前节点并且只向上传一条边的高度”，`best` 保存的是“可以同时向左右走的最长路径”。如果把 `left + right` 直接返回，就会影响父节点的高度计算。

124 最大路径和使用类似思路：左右贡献先用 `max(0, ...)` 截断，因为负贡献只会让路径更小。

#### LCA 的递归含义

236 最近公共祖先中，递归函数返回的是：

- 当前子树中是否找到目标；
- 如果找到了，返回哪一个节点可能是 LCA；
- 如果左右子树都返回目标，当前节点就是分叉点。

所以看到：

```cpp
if (left && right) {
    return root;
}
return left ? left : right;
```

要理解为：左右两边都找到了，当前根节点是共同祖先；只有一边找到，就把这个结果继续向上传。

### 图和搜索：DFS、BFS、拓扑排序

#### DFS

DFS 是“沿着一条路走到底，走不通再回头”。它的核心通常是：

1. 判断当前状态是否合法；
2. 标记当前状态已访问；
3. 递归所有相邻状态；
4. 如果允许其他路径重新使用当前状态，就必须撤销标记。

题 200 岛屿数量中，访问 `grid[y][x] = '1'` 后立即改成 `'0'`，所以同一座岛只会计数一次。

题 79 单词搜索中，当前格子改成 `'#'` 是为了防止同一条路径重复使用这个格子；递归结束后恢复原字符，是为了让其他路径还能使用它。

#### BFS

BFS 通常适合求“最少步数”或“最短层”。题 994 腐烂的橘子把所有初始腐烂源同时放入队列，每一轮处理一层节点，所以一轮正好代表一分钟。

层序遍历 102 和右视图 199 也使用 BFS：

```cpp
int level_size = q.size();
```

这个 `level_size` 是当前层的节点数量，不能在处理过程中不断改变，否则会把下一层节点混进当前层。

#### 拓扑排序

题 207 课程表把“课程依赖”表示成有向边。入度为 0 的节点没有未满足的先修课，可以先学习。每学习一门课，就让它的后继入度减一；减到 0 后再加入队列。如果最终访问的课程数少于总数，说明存在环。

### 回溯：做选择、递归、撤销选择

回溯题的基本模板是：

```text
做选择
递归
撤销选择
```

例如全排列 46：

```cpp
used[i] = true;
path.push_back(nums[i]);
dfs(nums);
path.pop_back();
used[i] = false;
```

`used[i] = true` 保证同一路径不会重复选；递归结束后的两次撤销，保证下一条路径可以从干净状态开始。

子集 78 使用 `start` 控制只能向后选择，从而避免相同子集的不同排列。组合总和 39 下一层仍然从 `i` 开始，表示同一个数字可以重复使用。

括号生成 22 则在搜索过程中维护不变式：

- 左括号数量不能超过 n；
- 已使用右括号数量必须小于左括号数量。

这样根本不会生成非法前缀，比生成后再判断更省。

### 二分查找：先明确“答案在哪个边界”

二分查找并不是只会比较 `nums[mid]`。关键是每次循环之后，答案仍然落在 `[left,right]` 中。

#### 左闭右开

题 35 搜索插入位置使用：

```cpp
int left = 0;
int right = nums.size(); // right 是开区间，不能直接访问
```

`nums[mid] < target` 时把左边界改成 `mid + 1`；否则把右边界改成 `mid`。最后 `left` 就是第一个不小于 target 的位置。

#### 有序旋转数组

题 33 中，每次至少有一半保持有序：

- 如果 `nums[left] <= nums[mid]`，左半段有序；
- 否则右半段有序。

判断 target 是否落在有序半边中，就能把搜索范围缩到另一边。

题 153 寻找最小值时，`nums[mid] > nums[right]` 说明最小值一定在 mid 右侧；否则 mid 也可能是最小值，因此右边界不能排除 mid。

#### 二维矩阵二分

题 74 把矩阵看成一维数组，使用 `mid / n` 和 `mid % n` 还原行列。题 240 的矩阵只有每行、每列分别有序，不能直接整体二分，所以从右上角使用排除法。

### 复杂度怎么理解

- **O(n)**：遍历过程中每个元素最多处理常数次。
- **O(log n)**：每次将搜索范围减半，如二分查找。
- **O(n log n)**：排序，或每轮做一次对数级操作。
- **O(n²)**：常见于双重循环、字符串两前缀状态。
- **O(2^n)、O(n!)**：回溯枚举所有子集或排列。
- **空间复杂度**：只计算算法额外创建的结构，通常不把题目返回的 `answer` 数组算进去。

## 按题型复习清单

### 动态规划优先复习

70 → 198 → 152 → 322 → 416 → 139 → 300 → 1143 → 72 → 64

先做滚动 DP，再做背包，最后做字符串二维 DP。每道题写清：

```text
dp[i] / dp[i][j] 是什么？
最终答案从哪个状态得到？
边界是什么？
转移方程为什么不会漏掉一种情况？
```

### 树优先复习

104 → 102 → 94 → 101 → 98 → 105 → 236 → 543 → 124

先掌握遍历和深度，再学习 BST、建树和后序状态返回。

### 搜索优先复习

35 → 74 → 33 → 153 → 200 → 994 → 207 → 46 → 78 → 79

先分清“二分答案”“DFS 搜状态”“BFS 搜最短层”，不要把所有搜索都看成同一类算法。

## 100 题逐题索引

### 哈希

| 编号 | 题目 | 难度 | 知识点 | 在本题怎么用 | 复杂度 | C++ 解法 |
|---:|---|:---:|---|---|---|---|
| 1 | [两数之和](https://leetcode.cn/problems/two-sum/) | 简单 | 哈希 | 一边遍历，一边把“已经看过的值”放进哈希表；碰到当前数 a 时，只需查询 target-a 是否已经出现过。 | O(n)；空间：O(n)。 | [`0001_two_sum.cpp`](solutions/0001_two_sum.cpp) |
| 49 | [字母异位词分组](https://leetcode.cn/problems/group-anagrams/) | 中等 | 哈希 | 互为字母异位词的字符串排序后完全相同，所以排序结果可作为“桶键”。 | O(n*klogk)，k 为单词平均长度；空间：O(n*k)。 | [`0049_group_anagrams.cpp`](solutions/0049_group_anagrams.cpp) |
| 128 | [最长连续序列](https://leetcode.cn/problems/longest-consecutive-sequence/) | 中等 | 哈希 | 只从“序列起点”开始向后数。若 x-1 不在集合中，x 就是某个序列的开头。 | 每个数只扩展一次，平均 O(n)；空间：O(n)。 | [`0128_longest_consecutive_sequence.cpp`](solutions/0128_longest_consecutive_sequence.cpp) |

### 双指针

| 编号 | 题目 | 难度 | 知识点 | 在本题怎么用 | 复杂度 | C++ 解法 |
|---:|---|:---:|---|---|---|---|
| 283 | [移动零](https://leetcode.cn/problems/move-zeroes/) | 简单 | 双指针 | fast 扫描非零值，slow 指向下一个非零值应写入的位置；最后补零。 | O(n)；额外空间：O(1)。 | [`0283_move_zeroes.cpp`](solutions/0283_move_zeroes.cpp) |
| 11 | [盛最多水的容器](https://leetcode.cn/problems/container-with-most-water/) | 中等 | 双指针 | 面积由短板和宽度决定。每次移动较短的一边，才有机会更新最大值。 | O(n)；额外空间：O(1)。 | [`0011_container_with_most_water.cpp`](solutions/0011_container_with_most_water.cpp) |
| 15 | [三数之和](https://leetcode.cn/problems/3sum/) | 中等 | 双指针 | 固定第一个数，再在其右侧找两个和为 -nums[i] 的数；排序便于跳过重复解。 | O(n²)；空间：除答案外 O(log n)（排序栈空间）。 | [`0015_three_sum.cpp`](solutions/0015_three_sum.cpp) |
| 42 | [接雨水](https://leetcode.cn/problems/trapping-rain-water/) | 困难 | 双指针 | 栈保存左边界；遇到较高柱时弹出底柱，其上方积水由左右两侧较高柱决定。 | O(n)；空间：O(n)。 | [`0042_trapping_rain_water.cpp`](solutions/0042_trapping_rain_water.cpp) |

### 滑动窗口

| 编号 | 题目 | 难度 | 知识点 | 在本题怎么用 | 复杂度 | C++ 解法 |
|---:|---|:---:|---|---|---|---|
| 3 | [无重复字符的最长子串](https://leetcode.cn/problems/longest-substring-without-repeating-characters/) | 中等 | 滑动窗口 | right 扩窗口；出现重复时把 left 追到重复字符的右侧。 | O(n)；空间：O(字符集大小)。 | [`0003_longest_substring_without_repeating_characters.cpp`](solutions/0003_longest_substring_without_repeating_characters.cpp) |
| 438 | [找到字符串中所有字母异位词](https://leetcode.cn/problems/find-all-anagrams-in-a-string/) | 中等 | 滑动窗口 | 维护长度为 p.size() 的窗口，比较 26 个字母的出现次数。 | O(\|s\|)；空间：O(1)。 | [`0438_find_all_anagrams_in_a_string.cpp`](solutions/0438_find_all_anagrams_in_a_string.cpp) |

### 子串

| 编号 | 题目 | 难度 | 知识点 | 在本题怎么用 | 复杂度 | C++ 解法 |
|---:|---|:---:|---|---|---|---|
| 560 | [和为 K 的子数组](https://leetcode.cn/problems/subarray-sum-equals-k/) | 中等 | 子串 | 若 prefix[j] - prefix[i] == k，则区间 [i+1,j] 的和为 k。出现 prefix=k 时代表从数组开头开始的区间。 | O(n)；空间：O(n)。 | [`0560_subarray_sum_equals_k.cpp`](solutions/0560_subarray_sum_equals_k.cpp) |
| 239 | [滑动窗口最大值](https://leetcode.cn/problems/sliding-window-maximum/) | 困难 | 子串 | 队列保存“还有机会成为最大值”的下标，队首始终是当前窗口最大值。 | O(n)；空间：O(k)。 | [`0239_sliding_window_maximum.cpp`](solutions/0239_sliding_window_maximum.cpp) |
| 76 | [最小覆盖子串](https://leetcode.cn/problems/minimum-window-substring/) | 困难 | 子串 | right 扩张直到满足所有字符需求，再收缩 left 寻找更短答案。 | O(\|s\|+\|t\|)；空间：O(字符集大小)。 | [`0076_minimum_window_substring.cpp`](solutions/0076_minimum_window_substring.cpp) |

### 普通数组

| 编号 | 题目 | 难度 | 知识点 | 在本题怎么用 | 复杂度 | C++ 解法 |
|---:|---|:---:|---|---|---|---|
| 53 | [最大子数组和](https://leetcode.cn/problems/maximum-subarray/) | 中等 | 普通数组 | dp[i] 表示“必须以 i 结尾”的最大和；前缀为负时不如重新开始。 | O(n)；空间：O(1)。 | [`0053_maximum_subarray.cpp`](solutions/0053_maximum_subarray.cpp) |
| 56 | [合并区间](https://leetcode.cn/problems/merge-intervals/) | 中等 | 普通数组 | 按起点排序；当前区间起点不大于答案区间的终点时可以合并。 | O(n log n)；空间：O(1) 额外空间（不算答案）。 | [`0056_merge_intervals.cpp`](solutions/0056_merge_intervals.cpp) |
| 189 | [轮转数组](https://leetcode.cn/problems/rotate-array/) | 中等 | 普通数组 | 先整体反转，再分别反转前 k%n 个元素和其余元素。 | O(n)；额外空间：O(1)。 | [`0189_rotate_array.cpp`](solutions/0189_rotate_array.cpp) |
| 238 | [除了自身以外数组的乘积](https://leetcode.cn/problems/product-of-array-except-self/) | 中等 | 普通数组 | answer[i] = i 左侧所有数的乘积 × i 右侧所有数的乘积。 | O(n)；额外空间：O(1)，答案数组不算额外空间。 | [`0238_product_of_array_except_self.cpp`](solutions/0238_product_of_array_except_self.cpp) |
| 41 | [缺失的第一个正数](https://leetcode.cn/problems/first-missing-positive/) | 困难 | 普通数组 | 值 x 应放在下标 x-1；最后扫描位置不匹配处即可。 | O(n)；空间：O(1)。 | [`0041_first_missing_positive.cpp`](solutions/0041_first_missing_positive.cpp) |

### 矩阵

| 编号 | 题目 | 难度 | 知识点 | 在本题怎么用 | 复杂度 | C++ 解法 |
|---:|---|:---:|---|---|---|---|
| 73 | [矩阵置零](https://leetcode.cn/problems/set-matrix-zeroes/) | 中等 | 矩阵 | 用矩阵第 0 行/列记录哪些行列需要清零，避免额外 bool 数组。 | O(mn)；额外空间：O(1)。 | [`0073_set_matrix_zeroes.cpp`](solutions/0073_set_matrix_zeroes.cpp) |
| 54 | [螺旋矩阵](https://leetcode.cn/problems/spiral-matrix/) | 中等 | 矩阵 | 维护上下左右四个边界；每次按“右→下→左→上”走完后收缩边界。 | O(mn)；额外空间：O(1)。 | [`0054_spiral_matrix.cpp`](solutions/0054_spiral_matrix.cpp) |
| 48 | [旋转图像](https://leetcode.cn/problems/rotate-image/) | 中等 | 矩阵 | 顺时针 90° 等价于先沿主对角线转置，再把每行左右翻转。 | O(n²)；额外空间：O(1)。 | [`0048_rotate_image.cpp`](solutions/0048_rotate_image.cpp) |
| 240 | [搜索二维矩阵 II](https://leetcode.cn/problems/search-a-2d-matrix-ii/) | 中等 | 矩阵 | 从右上角出发。目标较小则排除当前整列，目标较大则排除当前整行。 | O(m+n)；额外空间：O(1)。 | [`0240_search_a_2d_matrix_ii.cpp`](solutions/0240_search_a_2d_matrix_ii.cpp) |

### 链表

| 编号 | 题目 | 难度 | 知识点 | 在本题怎么用 | 复杂度 | C++ 解法 |
|---:|---|:---:|---|---|---|---|
| 160 | [相交链表](https://leetcode.cn/problems/intersection-of-two-linked-lists/) | 简单 | 链表 | 两指针分别走完各自链表后切换到另一条头部；若相交，会在第二轮同起点同步相遇。 | O(n+m)；额外空间：O(1)。 | [`0160_intersection_of_two_linked_lists.cpp`](solutions/0160_intersection_of_two_linked_lists.cpp) |
| 206 | [反转链表](https://leetcode.cn/problems/reverse-linked-list/) | 简单 | 链表 | prev 指向已反转部分，current 指向当前节点；先保存 next 再改指针。 | O(n)；额外空间：O(1)。 | [`0206_reverse_linked_list.cpp`](solutions/0206_reverse_linked_list.cpp) |
| 234 | [回文链表](https://leetcode.cn/problems/palindrome-linked-list/) | 简单 | 链表 | 找到中点，反转后半段，再同时比较前后半段；比较完可恢复链表。 | O(n)；额外空间：O(1)。 | [`0234_palindrome_linked_list.cpp`](solutions/0234_palindrome_linked_list.cpp) |
| 141 | [环形链表](https://leetcode.cn/problems/linked-list-cycle/) | 简单 | 链表 | 有环时快指针最终会从后面追上慢指针。 | O(n)；额外空间：O(1)。 | [`0141_linked_list_cycle.cpp`](solutions/0141_linked_list_cycle.cpp) |
| 142 | [环形链表 II](https://leetcode.cn/problems/linked-list-cycle-ii/) | 中等 | 链表 | 相遇后令 one=head、two=相遇点，再同速移动；二者下一次相遇就是环入口。 | O(n)；额外空间：O(1)。 | [`0142_linked_list_cycle_ii.cpp`](solutions/0142_linked_list_cycle_ii.cpp) |
| 21 | [合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/) | 简单 | 链表 | 每轮比较两条链表头，把较小节点接到结果尾部；最后接上剩余部分。 | O(n+m)；额外空间：O(1)（不计哑结点常数）。 | [`0021_merge_two_sorted_lists.cpp`](solutions/0021_merge_two_sorted_lists.cpp) |
| 2 | [两数相加](https://leetcode.cn/problems/add-two-numbers/) | 中等 | 链表 | 逐位相加并记录进位；当还有进位或链表未结束时继续创建节点。 | O(max(n,m))；空间：O(max(n,m))。 | [`0002_add_two_numbers.cpp`](solutions/0002_add_two_numbers.cpp) |
| 19 | [删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/) | 中等 | 链表 | 先让 fast 走 n 步；再让二者一起走，fast 走完时，slow 正好停在待删节点前。 | O(L)；额外空间：O(1)。 | [`0019_remove_nth_node_from_end_of_list.cpp`](solutions/0019_remove_nth_node_from_end_of_list.cpp) |
| 24 | [两两交换链表中的节点](https://leetcode.cn/problems/swap-nodes-in-pairs/) | 中等 | 链表 | 保存 a、b 及下一组起点，交换 a/b 的指向，再移动到下一组。 | O(n)；额外空间：O(1)。 | [`0024_swap_nodes_in_pairs.cpp`](solutions/0024_swap_nodes_in_pairs.cpp) |
| 25 | [K 个一组翻转链表](https://leetcode.cn/problems/reverse-nodes-in-k-group/) | 困难 | 链表 | 先探测当前是否还有 k 个节点；有则反转 [head,next_group)，再把两组接起来。 | O(n)；额外空间：O(1)。 | [`0025_reverse_nodes_in_k_group.cpp`](solutions/0025_reverse_nodes_in_k_group.cpp) |
| 138 | [随机链表的复制](https://leetcode.cn/problems/copy-list-with-random-pointer/) | 中等 | 链表 | 第一遍创建所有新节点；第二遍设置 next 和 random。 | O(n)；空间：O(n)。 | [`0138_copy_list_with_random_pointer.cpp`](solutions/0138_copy_list_with_random_pointer.cpp) |
| 148 | [排序链表](https://leetcode.cn/problems/sort-list/) | 中等 | 链表 | 快慢指针断成两半，递归排序后按双指针合并两个有序链表。 | O(n log n)；空间：O(log n) 递归栈。 | [`0148_sort_list.cpp`](solutions/0148_sort_list.cpp) |
| 23 | [合并 K 个升序链表](https://leetcode.cn/problems/merge-k-sorted-lists/) | 困难 | 链表 | 堆中始终保存每条链表当前未取节点，每次弹出全局最小节点并接上下一个。 | O(n log k)；空间：O(k)。 | [`0023_merge_k_sorted_lists.cpp`](solutions/0023_merge_k_sorted_lists.cpp) |
| 146 | [LRU 缓存](https://leetcode.cn/problems/lru-cache/) | 中等 | 链表 | 哈希表 O(1) 找节点，双向链表维护“最近使用”顺序：头部最新，尾部最旧。每个操作 O(1)；空间 O(capacity)。 | 每个操作 O(1)；空间 O(capacity)。 | [`0146_lru_cache.cpp`](solutions/0146_lru_cache.cpp) |

### 二叉树

| 编号 | 题目 | 难度 | 知识点 | 在本题怎么用 | 复杂度 | C++ 解法 |
|---:|---|:---:|---|---|---|---|
| 94 | [二叉树的中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal/) | 简单 | 二叉树 | 不断把左链入栈；弹栈时访问，再转向右子树。 | O(n)；空间：O(h)。 | [`0094_binary_tree_inorder_traversal.cpp`](solutions/0094_binary_tree_inorder_traversal.cpp) |
| 104 | [二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/) | 简单 | 二叉树 | 以根为起点，树深 = 左右子树较大深度 + 1；空树深度为 0。 | O(n)；空间：O(h)。 | [`0104_maximum_depth_of_binary_tree.cpp`](solutions/0104_maximum_depth_of_binary_tree.cpp) |
| 226 | [翻转二叉树](https://leetcode.cn/problems/invert-binary-tree/) | 简单 | 二叉树 | 对每个节点交换左右子节点，并递归处理两棵子树。 | O(n)；空间：O(h)。 | [`0226_invert_binary_tree.cpp`](solutions/0226_invert_binary_tree.cpp) |
| 101 | [对称二叉树](https://leetcode.cn/problems/symmetric-tree/) | 简单 | 二叉树 | 判断左树的左/右子树，是否分别对称地匹配右树的右/左子树。 | O(n)；空间：O(h)。 | [`0101_symmetric_tree.cpp`](solutions/0101_symmetric_tree.cpp) |
| 543 | [二叉树的直径](https://leetcode.cn/problems/diameter-of-binary-tree/) | 简单 | 二叉树 | 递归返回经过当前节点向上的最长边数；用左右返回值之和更新全局答案。 | O(n)；空间：O(h)。 | [`0543_diameter_of_binary_tree.cpp`](solutions/0543_diameter_of_binary_tree.cpp) |
| 102 | [二叉树的层序遍历](https://leetcode.cn/problems/binary-tree-level-order-traversal/) | 中等 | 二叉树 | 每轮先取得当前队列长度，它就是这一层的节点数，再整层出队。 | O(n)；空间：O(n)。 | [`0102_binary_tree_level_order_traversal.cpp`](solutions/0102_binary_tree_level_order_traversal.cpp) |
| 108 | [将有序数组转换为二叉搜索树](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/) | 简单 | 二叉树 | 每次选择区间中点作为根，左半区建左子树、右半区建右子树。 | O(n)；空间：O(log n)。 | [`0108_convert_sorted_array_to_binary_search_tree.cpp`](solutions/0108_convert_sorted_array_to_binary_search_tree.cpp) |
| 98 | [验证二叉搜索树](https://leetcode.cn/problems/validate-binary-search-tree/) | 中等 | 二叉树 | 每个节点必须位于其祖先允许的开区间 (min,max) 内。 | O(n)；空间：O(h)。 | [`0098_validate_binary_search_tree.cpp`](solutions/0098_validate_binary_search_tree.cpp) |
| 230 | [二叉搜索树中第 K 小的元素](https://leetcode.cn/problems/kth-smallest-element-in-a-bst/) | 中等 | 二叉树 | BST 的中序遍历天然得到从小到大的序列，找到第 k 个即可停止。 | 最坏 O(n)；空间：O(h)。 | [`0230_kth_smallest_element_in_a_bst.cpp`](solutions/0230_kth_smallest_element_in_a_bst.cpp) |
| 199 | [二叉树的右视图](https://leetcode.cn/problems/binary-tree-right-side-view/) | 中等 | 二叉树 | 每一层 BFS 的最后一个节点就是从右边看到的节点。 | O(n)；空间：O(n)。 | [`0199_binary_tree_right_side_view.cpp`](solutions/0199_binary_tree_right_side_view.cpp) |
| 114 | [二叉树展开为链表](https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/) | 中等 | 二叉树 | 逆前序栈遍历（根→右→左），依次把节点接到结果尾部，得到先序顺序。 | O(n)；空间：O(n)。 | [`0114_flatten_binary_tree_to_linked_list.cpp`](solutions/0114_flatten_binary_tree_to_linked_list.cpp) |
| 105 | [从前序与中序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) | 中等 | 二叉树 | 前序第一个值是根；中序中根左侧是左子树，右侧是右子树。 | O(n²) 最坏；空间：O(h)。用哈希索引可优化为 O(n)。 | [`0105_construct_binary_tree_from_preorder_and_inorder.cpp`](solutions/0105_construct_binary_tree_from_preorder_and_inorder.cpp) |
| 437 | [路径总和 III](https://leetcode.cn/problems/path-sum-iii/) | 中等 | 二叉树 | 若当前前缀和为 p，路径和 target 等价于存在更早前缀 p-target。 | O(n)；空间：O(n)。 | [`0437_path_sum_iii.cpp`](solutions/0437_path_sum_iii.cpp) |
| 236 | [二叉树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/) | 中等 | 二叉树 | 若左右递归各找到一个，则当前节点就是 LCA；只有一侧返回时继续向上传。 | O(n)；空间：O(h)。 | [`0236_lowest_common_ancestor_of_a_binary_tree.cpp`](solutions/0236_lowest_common_ancestor_of_a_binary_tree.cpp) |
| 124 | [二叉树中的最大路径和](https://leetcode.cn/problems/binary-tree-maximum-path-sum/) | 困难 | 二叉树 | 单边返回“当前节点 + max(0, 左/右贡献)”；全局答案取“当前节点+左右非负贡献”。 | O(n)；空间：O(h)。 | [`0124_binary_tree_maximum_path_sum.cpp`](solutions/0124_binary_tree_maximum_path_sum.cpp) |

### 图论

| 编号 | 题目 | 难度 | 知识点 | 在本题怎么用 | 复杂度 | C++ 解法 |
|---:|---|:---:|---|---|---|---|
| 200 | [岛屿数量](https://leetcode.cn/problems/number-of-islands/) | 中等 | 图论 | 每遇到一个 '1' 就增加答案，并从它开始把整座岛改为 '0'，避免重复计数。 | O(mn)；空间：O(mn) 最坏递归栈。 | [`0200_number_of_islands.cpp`](solutions/0200_number_of_islands.cpp) |
| 994 | [腐烂的橘子](https://leetcode.cn/problems/rotting-oranges/) | 中等 | 图论 | 把所有腐烂橘子同时加入队列；每一轮对应一分钟，向四周传播腐烂。 | O(mn)；空间：O(mn)。 | [`0994_rotting_oranges.cpp`](solutions/0994_rotting_oranges.cpp) |
| 207 | [课程表](https://leetcode.cn/problems/course-schedule/) | 中等 | 图论 | 课程是点，先修关系是有向边；若不存在环，则可通过拓扑排序学完。 | O(V+E)；空间：O(V+E)。 | [`0207_course_schedule.cpp`](solutions/0207_course_schedule.cpp) |
| 208 | [实现 Trie (前缀树)](https://leetcode.cn/problems/implement-trie-prefix-tree/) | 中等 | 图论 | 每个节点保存 26 个子节点指针和“是否为完整单词”标记。 | insert/search/startsWith 均 O(L)。 | [`0208_implement_trie_prefix_tree.cpp`](solutions/0208_implement_trie_prefix_tree.cpp) |

### 回溯

| 编号 | 题目 | 难度 | 知识点 | 在本题怎么用 | 复杂度 | C++ 解法 |
|---:|---|:---:|---|---|---|---|
| 46 | [全排列](https://leetcode.cn/problems/permutations/) | 中等 | 回溯 | path 保存已选数字，visited 判断是否可用；达到长度时记录一份 path。 | O(n*n!)；空间：O(n)（递归栈与 path）。 | [`0046_permutations.cpp`](solutions/0046_permutations.cpp) |
| 78 | [子集](https://leetcode.cn/problems/subsets/) | 中等 | 回溯 | 在每个位置选择“加入当前元素”或“跳过”；当前 path 每次都是合法答案。 | O(n*2^n)；空间：O(n)。 | [`0078_subsets.cpp`](solutions/0078_subsets.cpp) |
| 17 | [电话号码的字母组合](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/) | 中等 | 回溯 | digit 依次对应多组字符；在位置 i 处枚举按键字符并递归。 | O(3^m*4^n)；空间：O(m+n)。 | [`0017_letter_combinations_of_a_phone_number.cpp`](solutions/0017_letter_combinations_of_a_phone_number.cpp) |
| 39 | [组合总和](https://leetcode.cn/problems/combination-sum/) | 中等 | 回溯 | 排序后，每个位置可以从 start 继续选择，因此允许重复；目标不足时向前枚举。 | 指数级；空间：O(target)。 | [`0039_combination_sum.cpp`](solutions/0039_combination_sum.cpp) |
| 22 | [括号生成](https://leetcode.cn/problems/generate-parentheses/) | 中等 | 回溯 | 只要“左括号数 < n”就可加左；“已用右括号数 < 左括号数”就可加右。 | Catalan 数级别；空间：O(n)。 | [`0022_generate_parentheses.cpp`](solutions/0022_generate_parentheses.cpp) |
| 79 | [单词搜索](https://leetcode.cn/problems/word-search/) | 中等 | 回溯 | 从每个匹配首字母的位置 DFS；临时把访问过的格子改为非字母，递归后恢复。 | 最坏 O(mn*3^L)；空间：O(L)。 | [`0079_word_search.cpp`](solutions/0079_word_search.cpp) |
| 131 | [分割回文串](https://leetcode.cn/problems/palindrome-partitioning/) | 中等 | 回溯 | 从 start 开始枚举下一个切片 [start,i]；只有它是回文串才递归到 i+1。 | 状态 O(n²)，可达答案为指数级；空间 O(n)。 | [`0131_palindrome_partitioning.cpp`](solutions/0131_palindrome_partitioning.cpp) |
| 51 | [N 皇后](https://leetcode.cn/problems/n-queens/) | 困难 | 回溯 | 逐行放后，cols/diag1/diag2 记录已占用列与两条对角线。 | 约 O(N!)；空间 O(N)（仅计每行临时数据）。 | [`0051_n_queens.cpp`](solutions/0051_n_queens.cpp) |

### 二分查找

| 编号 | 题目 | 难度 | 知识点 | 在本题怎么用 | 复杂度 | C++ 解法 |
|---:|---|:---:|---|---|---|---|
| 35 | [搜索插入位置](https://leetcode.cn/problems/search-insert-position/) | 简单 | 二分查找 | 二分找到第一个不小于 target 的位置，它就是插入位置。 | O(log n)；额外空间：O(1)。 | [`0035_search_insert_position.cpp`](solutions/0035_search_insert_position.cpp) |
| 74 | [搜索二维矩阵](https://leetcode.cn/problems/search-a-2d-matrix/) | 中等 | 二分查找 | 把矩阵按行拼成升序数组；mid 映射回 row=mid/n, col=mid%n。 | O(log(mn))；额外空间：O(1)。 | [`0074_search_a_2d_matrix.cpp`](solutions/0074_search_a_2d_matrix.cpp) |
| 34 | [在排序数组中查找元素的第一个和最后一个位置](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/) | 中等 | 二分查找 | first = lower_bound(target)；若不存在或不等则返回 {-1,-1}；last = lower_bound(target+1)-1。 | O(log n)；额外空间：O(1)。 | [`0034_find_first_and_last_position_of_element_in_sorted_array.cpp`](solutions/0034_find_first_and_last_position_of_element_in_sorted_array.cpp) |
| 33 | [搜索旋转排序数组](https://leetcode.cn/problems/search-in-rotated-sorted-array/) | 中等 | 二分查找 | 每次必有一半有序；若 target 落在有序半边就缩小到那里，否则去另一边。 | O(log n)；额外空间：O(1)。 | [`0033_search_in_rotated_sorted_array.cpp`](solutions/0033_search_in_rotated_sorted_array.cpp) |
| 153 | [寻找旋转排序数组中的最小值](https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/) | 中等 | 二分查找 | 比较 nums[mid] 与 nums[right]。若 mid 更大，最小值必在右侧。 | O(log n)；额外空间：O(1)。 | [`0153_find_minimum_in_rotated_sorted_array.cpp`](solutions/0153_find_minimum_in_rotated_sorted_array.cpp) |
| 4 | [寻找两个正序数组的中位数](https://leetcode.cn/problems/median-of-two-sorted-arrays/) | 困难 | 二分查找 | 保证较短数组一侧为 cut1，使 left_half 总共有 (m+n+1)/2 个元素；调整 cut1，使 max_left <= min_right 且 max_right <= min_left。 | O(log min(m,n))；空间：O(1)。 | [`0004_median_of_two_sorted_arrays.cpp`](solutions/0004_median_of_two_sorted_arrays.cpp) |

### 栈

| 编号 | 题目 | 难度 | 知识点 | 在本题怎么用 | 复杂度 | C++ 解法 |
|---:|---|:---:|---|---|---|---|
| 20 | [有效的括号](https://leetcode.cn/problems/valid-parentheses/) | 简单 | 栈 | 左括号入栈；右括号必须与栈顶左括号匹配；最后栈必须为空。 | O(n)；空间：O(n)。 | [`0020_valid_parentheses.cpp`](solutions/0020_valid_parentheses.cpp) |
| 155 | [最小栈](https://leetcode.cn/problems/min-stack/) | 中等 | 栈 | 每次 push 当前值与栈顶最小值中的较小者；栈顶始终保存到目前为止的最小值。 | 时间与空间复杂度见源码。 | [`0155_min_stack.cpp`](solutions/0155_min_stack.cpp) |
| 394 | [字符串解码](https://leetcode.cn/problems/decode-string/) | 中等 | 栈 | 遇到 [ 时把当前字符串和数字入栈；遇到 ] 时重复并拼接。 | O(输出长度)；空间：O(嵌套深度)。 | [`0394_decode_string.cpp`](solutions/0394_decode_string.cpp) |
| 739 | [每日温度](https://leetcode.cn/problems/daily-temperatures/) | 中等 | 栈 | 栈保存“还没有找到更暖日期”的下标；遇到高温时弹出并计算答案。 | O(n)；空间：O(n)。 | [`0739_daily_temperatures.cpp`](solutions/0739_daily_temperatures.cpp) |
| 84 | [柱状图中最大的矩形](https://leetcode.cn/problems/largest-rectangle-in-histogram/) | 困难 | 栈 | 栈保存递增柱索引；柱子第一次变矮时确定其左右边界。 | O(n)；空间：O(n)。 | [`0084_largest_rectangle_in_histogram.cpp`](solutions/0084_largest_rectangle_in_histogram.cpp) |

### 堆

| 编号 | 题目 | 难度 | 知识点 | 在本题怎么用 | 复杂度 | C++ 解法 |
|---:|---|:---:|---|---|---|---|
| 215 | [数组中的第K个最大元素](https://leetcode.cn/problems/kth-largest-element-in-an-array/) | 中等 | 堆 | 遍历时堆始终保留当前最大的 k 个元素，堆顶就是第 k 大。 | O(n log k)；空间：O(k)。 | [`0215_kth_largest_element_in_an_array.cpp`](solutions/0215_kth_largest_element_in_an_array.cpp) |
| 347 | [前 K 个高频元素](https://leetcode.cn/problems/top-k-frequent-elements/) | 中等 | 堆 | 频次最大不超过 n，用 buckets[frequency] 保存元素。 | O(n)；空间：O(n)。 | [`0347_top_k_frequent_elements.cpp`](solutions/0347_top_k_frequent_elements.cpp) |
| 295 | [数据流的中位数](https://leetcode.cn/problems/find-median-from-data-stream/) | 困难 | 堆 | 最大堆保存较小一半，最小堆保存较大一半；两堆最多相差 1 个元素。插入 O(log n)，取中位数 O(1)；空间 O(n)。 | 时间与空间复杂度见源码。 | [`0295_find_median_from_data_stream.cpp`](solutions/0295_find_median_from_data_stream.cpp) |

### 贪心算法

| 编号 | 题目 | 难度 | 知识点 | 在本题怎么用 | 复杂度 | C++ 解法 |
|---:|---|:---:|---|---|---|---|
| 121 | [买卖股票的最佳时机](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/) | 简单 | 贪心算法 | 遍历时记录此前最低买价；今天卖出的利润为 price-min_price。 | O(n)；空间：O(1)。 | [`0121_best_time_to_buy_and_sell_stock.cpp`](solutions/0121_best_time_to_buy_and_sell_stock.cpp) |
| 55 | [跳跃游戏](https://leetcode.cn/problems/jump-game/) | 中等 | 贪心算法 | 扫描时更新 max_reachable；若 i 已越过可达点，则后面都无法到达。 | O(n)；空间：O(1)。 | [`0055_jump_game.cpp`](solutions/0055_jump_game.cpp) |
| 45 | [跳跃游戏 II](https://leetcode.cn/problems/jump-game-ii/) | 中等 | 贪心算法 | cur_end 是当前跳跃可达边界，far_end 是下一段最大边界；走到 cur_end 时才必须再跳一次。 | O(n)；空间：O(1)。 | [`0045_jump_game_ii.cpp`](solutions/0045_jump_game_ii.cpp) |
| 763 | [划分字母区间](https://leetcode.cn/problems/partition-labels/) | 中等 | 贪心算法 | 先记录每字母最后位置；扩展当前区间时，只要其最远末尾仍在当前区内就可继续。 | O(n)；空间：O(字符集大小)。 | [`0763_partition_labels.cpp`](solutions/0763_partition_labels.cpp) |

### 动态规划

| 编号 | 题目 | 难度 | 知识点 | 在本题怎么用 | 复杂度 | C++ 解法 |
|---:|---|:---:|---|---|---|---|
| 70 | [爬楼梯](https://leetcode.cn/problems/climbing-stairs/) | 简单 | 动态规划 | 到第 i 阶的方案数 = 到第 i-1 阶方案 + 到第 i-2 阶方案。 | O(n)；空间：O(1)。 | [`0070_climbing_stairs.cpp`](solutions/0070_climbing_stairs.cpp) |
| 118 | [杨辉三角](https://leetcode.cn/problems/pascals-triangle/) | 简单 | 动态规划 | 每行两端为 1；中间值等于上一行正上方与左上方两数之和。 | O(n²)；空间：O(1) 额外空间（不算答案）。 | [`0118_pascals_triangle.cpp`](solutions/0118_pascals_triangle.cpp) |
| 198 | [打家劫舍](https://leetcode.cn/problems/house-robber/) | 中等 | 动态规划 | dp[i] = max(dp[i-1], dp[i-2]+nums[i])：不偷或偷。 | O(n)；空间：O(1)。 | [`0198_house_robber.cpp`](solutions/0198_house_robber.cpp) |
| 279 | [完全平方数](https://leetcode.cn/problems/perfect-squares/) | 中等 | 动态规划 | dp[i] 表示组成 i 所需最少平方数；外层遍历平方数，内层更新 i。 | O(n√n)；空间：O(n)。 | [`0279_perfect_squares.cpp`](solutions/0279_perfect_squares.cpp) |
| 322 | [零钱兑换](https://leetcode.cn/problems/coin-change/) | 中等 | 动态规划 | dp[a] = min(dp[a-coin]+1)，对每种 coin 使用到任意次数。 | O(amount*n)；空间：O(amount)。 | [`0322_coin_change.cpp`](solutions/0322_coin_change.cpp) |
| 139 | [单词拆分](https://leetcode.cn/problems/word-break/) | 中等 | 动态规划 | dp[i] 表示前缀 s[0..i) 能否拆分；仅在 dp[j] 为真且 s[j..i) 在字典中时转移。 | O(n²) 字符比较级；空间：O(n)。 | [`0139_word_break.cpp`](solutions/0139_word_break.cpp) |
| 300 | [最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/) | 中等 | 动态规划 | tails[len] 保存长度为 len+1 的递增子序列的最小末尾值。 | O(n log n)；空间：O(n)。 | [`0300_longest_increasing_subsequence.cpp`](solutions/0300_longest_increasing_subsequence.cpp) |
| 152 | [乘积最大子数组](https://leetcode.cn/problems/maximum-product-subarray/) | 中等 | 动态规划 | 负数会翻转最大/最小关系，因此同时维护以当前位置结尾的最大、最小乘积。 | O(n)；空间：O(1)。 | [`0152_maximum_product_subarray.cpp`](solutions/0152_maximum_product_subarray.cpp) |
| 416 | [分割等和子集](https://leetcode.cn/problems/partition-equal-subset-sum/) | 中等 | 动态规划 | 先判断总和为偶数；再求是否存在若干数之和为 total/2。 | O(n*target)；空间：O(target)（一维滚动数组）。 | [`0416_partition_equal_subset_sum.cpp`](solutions/0416_partition_equal_subset_sum.cpp) |
| 32 | [最长有效括号](https://leetcode.cn/problems/longest-valid-parentheses/) | 困难 | 动态规划 | 栈保存可能的左边界索引；栈顶表示当前无效区间起点。 | O(n)；空间：O(n)。 | [`0032_longest_valid_parentheses.cpp`](solutions/0032_longest_valid_parentheses.cpp) |

### 多维动态规划

| 编号 | 题目 | 难度 | 知识点 | 在本题怎么用 | 复杂度 | C++ 解法 |
|---:|---|:---:|---|---|---|---|
| 62 | [不同路径](https://leetcode.cn/problems/unique-paths/) | 中等 | 多维动态规划 | 到达 (y,x) 只能从上方或左侧来，故 dp[y][x]=dp[y-1][x]+dp[y][x-1]。 | O(mn)；空间：O(n)。 | [`0062_unique_paths.cpp`](solutions/0062_unique_paths.cpp) |
| 64 | [最小路径和](https://leetcode.cn/problems/minimum-path-sum/) | 中等 | 多维动态规划 | 每格最小代价 = 该格代价 + min(上方最小代价, 左方最小代价)。 | O(mn)；空间：O(n)。 | [`0064_minimum_path_sum.cpp`](solutions/0064_minimum_path_sum.cpp) |
| 5 | [最长回文子串](https://leetcode.cn/problems/longest-palindromic-substring/) | 中等 | 多维动态规划 | 枚举每个字符（奇数中心）和相邻字符间隙（偶数中心），向两侧扩展。 | O(n²)；空间：O(1)。 | [`0005_longest_palindromic_substring.cpp`](solutions/0005_longest_palindromic_substring.cpp) |
| 1143 | [最长公共子序列](https://leetcode.cn/problems/longest-common-subsequence/) | 中等 | 多维动态规划 | 字符相同则 +1；不同则取“少一个字符”的两子问题较大值。 | O(mn)；空间：O(min(m,n))。 | [`1143_longest_common_subsequence.cpp`](solutions/1143_longest_common_subsequence.cpp) |
| 72 | [编辑距离](https://leetcode.cn/problems/edit-distance/) | 中等 | 多维动态规划 | dp[i][j] 表示把 word1 前缀转成 word2 前缀的最少操作数。相同时沿用 diag；否则取删除/插入/替换后最优 +1。 | O(mn)；空间：O(min(m,n))。 | [`0072_edit_distance.cpp`](solutions/0072_edit_distance.cpp) |

### 技巧

| 编号 | 题目 | 难度 | 知识点 | 在本题怎么用 | 复杂度 | C++ 解法 |
|---:|---|:---:|---|---|---|---|
| 136 | [只出现一次的数字](https://leetcode.cn/problems/single-number/) | 简单 | 技巧 | x^x=0，0^x=x，且交换结合；把所有数异或后，出现两次的数互相抵消。 | O(n)；额外空间：O(1)。 | [`0136_single_number.cpp`](solutions/0136_single_number.cpp) |
| 169 | [多数元素](https://leetcode.cn/problems/majority-element/) | 简单 | 技巧 | 不同元素两两抵消；候选在剩余序列中占比必然 > 1/2，所以最后仍为候选。 | O(n)；额外空间：O(1)。 | [`0169_majority_element.cpp`](solutions/0169_majority_element.cpp) |
| 75 | [颜色分类](https://leetcode.cn/problems/sort-colors/) | 中等 | 技巧 | low 之后是 0，unknown 之后是 2；遇到 0 放前面，遇到 2 放后面。 | O(n)；额外空间：O(1)。 | [`0075_sort_colors.cpp`](solutions/0075_sort_colors.cpp) |
| 31 | [下一个排列](https://leetcode.cn/problems/next-permutation/) | 中等 | 技巧 | 从右找第一个 nums[i] < nums[i+1]；再从右找刚好更大的数交换；最后反转 i+1 之后的降序段，得到最小的新后缀。 | O(n)；额外空间：O(1)。 | [`0031_next_permutation.cpp`](solutions/0031_next_permutation.cpp) |
| 287 | [寻找重复数](https://leetcode.cn/problems/find-the-duplicate-number/) | 中等 | 技巧 | 把值 nums[x] 看作下标 x 的下一个节点；重复值导致两条路在环内相遇。 | O(n)；额外空间：O(1)。 | [`0287_find_the_duplicate_number.cpp`](solutions/0287_find_the_duplicate_number.cpp) |

## 推荐刷题顺序

1. 不必严格按题号；建议严格按上方 17 个专题顺序。
2. 同专题先做简单题，再做中等题，最后挑战困难题。
3. 每道题至少记录：**状态/指针定义、核心不变量、复杂度、易错点、相似题**。
4. 做错后隔几天不看代码重写；能独立解释“为什么不会漏”才算真正掌握。

## 文件说明

- `solutions/`：100 份 C++ 题解，每份对应榜单中的一题。
- `tests/list_node.h`：本地编译所需的 `ListNode` 定义。
- `tests/tree_node.h`：本地编译所需的 `TreeNode` 定义。
- `tests/random_node.h`：本地编译所需的随机链表节点定义。
