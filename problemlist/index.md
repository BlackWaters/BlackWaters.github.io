---
layout: page
title: Problem List
date: 2020-10-21
comments: true
---



这里做一个小记录，把平常写到的比较有意思的问题都放进来。现在时间也比较少，没啥时间写完整的题解，就做个简单的记录。

---

## [CF Round 676 E. Swedish Heroes](https://codeforces.com/contest/1421/problem/E)

- 2020.10.21

比较有难度的dp，dp规则不好发现。

corner case和proof比较有意思。

## [Atcoder Grand Contest 048 B - Bracket Score](https://atcoder.jp/contests/agc048/tasks/agc048_b)

- 2020.10.21

思维题。

顺带一提这场第一题也值得重新看看（情况比较多）。

## [Atcoder Beginner Contest 180 F - Unbranched](https://atcoder.jp/contests/abc180/tasks/abc180_f)

- 2020.10.21

计数问题。该题重点在于如何不重复的计数（定第一个点）。

## [CF Raif Round D. Bouncing Boomerangs](https://codeforces.com/contest/1428/problem/D)

- 2020.10.21

需要理清关系的构造。

（2后必有1）
（3必须建立在已有的电上）

分层构造，感觉写起来比较复杂。

[我的提交](https://codeforces.com/contest/1428/submission/96224830)

## [CF Raif Round E. Carrots for Rabbits](https://codeforces.com/contest/1428/problem/E)

- 2020.10.22

第一次的做法已经非常接近解法了。

(每次减去对答案贡献最大的值，注意贡献的计算)

## [CF Raif Round F. Fruit Sequences](https://codeforces.com/contest/1428/problem/F)

- 2020.10.23

量化答案，注意写法的优化（可以做到\\(O(n)\\)）。

应该属于比较巧妙的计数问题。

格外注意：**先理清楚数学关系再写！不要求快！**

## [计蒜客 新年炸裂](https://nanti.jisuanke.com/t/T3253)

- 2020.10.23

该题题解给了一个非常巧妙的概率做法

> 考虑一个最短的简单环一定是与1直接相连的两个点间的最短路径长度加上这两个点到1的距离，那么我们考虑最短路，每次随机将1的出点分组，每次将距离最短的两个点分到不同组内的概率为\\(50\%\\)，每次从一组向另一组跑最短路，跑k次后正确率便达到了\\(1-\frac{1}{2^k}\\) ，多跑几次即可。

不得不说很妙。


## [CF Round 680 Divide and Sum](http://codeforces.com/contest/1445/problem/D)

> No matter how we split the array, the cost of a partition will always be the same.

我的智商受到了侮辱。

仔细看证明。

## [AtCoder Beginner Contest 182 F - Valid payments](https://atcoder.jp/contests/abc182/tasks/abc182_f)

[Jonathan Paulson's solution in this round](https://www.youtube.com/watch?reload=9&v=VsUvBvgeb9Y&feature=youtu.be)

这个博主的解决思路实在是非常好理解。

这题感觉还是挺难分析的，首先是看了一段别人的代码，大概能看出来是考虑X的最小表示中，每个位置的进位。

我们考虑由X来构造y，比如我们用\\(g_i\\)来表示X第i个bit的值，我们能发现：

- 当\\(g_i > 0\\)时，我们只要在\\(g_i\\)的位置上填上一定的值导致进位的话，我们得到的y一定在i位上不存在值。
- 当\\(g_i = 0\\)时，我们不能在当前位置上填任何数，因为任何值都会导致y在i上有值。

如此我们得到一个dp的做法：
\\[
    我们设dp(i,j)表示：从第n个位置考虑到i，当前第i个位置上，是否存在进位(bool j)，所能得到的所有方案数。
\\]

这样我们发现\\(dp(i,j\\)可以从\\(dp(i+1,k)\\)转移过来，至于是否进位，这个很好分情况讨论