/*
 * 121. 买卖股票的最佳时机（维护历史最低价）
 * 核心思路：遍历时记录此前最低买价；今天卖出的利润为 price-min_price。
 * 时间：O(n)；空间：O(1)。
 * 易错点：先更新 min 再计算利润，还是先计算后更新均可，但至少交易一次。
 */
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int min_price = INT_MAX, answer = 0;
        for (int price : prices)
        {
            // 当前价格只能搭配此前出现过的最低买价得到最大卖出利润。
            answer = max(answer, price - min_price);
            min_price = min(min_price, price);
        }
        return answer;
    }
};
