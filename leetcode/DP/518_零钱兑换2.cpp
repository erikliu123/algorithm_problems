#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
/*
给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。 

 

示例 1:

输入: amount = 5, coins = [1, 2, 5]
输出: 4
解释: 有四种方式可以凑成总金额:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(auto &x:coins)
        {
            for(int v=1; v<=amount; v++)
            {
                if(v>=x)
                    dp[v]+=dp[v-x];

            }
        }
        return dp[amount];

    }
};