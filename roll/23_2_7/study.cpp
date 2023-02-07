#include <iostream>
#include <vector>
using namespace std;


class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(2, 0));
        //dp[i][0] 持有股票
        //dp[i][1] 不持有股票
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < len; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }

        return dp[len - 1][1];
    }
};



class Solution2 {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0));
        for (int j = 1; j < 2 * k; j += 2)
        {
            dp[0][j] = -prices[0];
        }

        for (int i = 1; i < len; i++)
        {
            for (int j = 0; j < 2 * k - 1; j += 2)
            {
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);//持有
                dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);//不持有
            }
        }

        return dp[len - 1][2 * k];
    }
};

class A
{
public:
	A() : _a1(10),_a2(20),_a3(30)
	{

	}
	A(int a1, int a2)
	{
		_a1 = a1;
		_a2 = a2;
		//_a3 = a3;
		//这里相当于赋值而已
	}
	void print()
	{
		cout << _a1 << "and" << _a2 << endl;
		cout << _a3 << endl;
	}

private:
	int _a1;
	int _a2;
	const int _a3 = 10;
};

//
//int main()
//{
//	A a1;
//	a1.print();
//
//	A a2(2,3);
//	a2.print();
//	
//}