
class Solution
{
public:
	vector<int> diffWaysToCompute(string expression)
	{
		vector<int> nums(1, 0);
		vector<char> ops;
		for (int cur = 0; cur < expression.length(); cur++)
		{
			if ('0' <= expression[cur] && expression[cur] <= '9')
			{
				nums.back() *= 10;
				nums.back() += int(expression[cur] - '0');
			}
			else
			{
				nums.push_back(0);
				ops.push_back(expression[cur]);
			}
		}

		vector<vector<vector<int>>> dp(nums.size(), vector<vector<int>>(nums.size()));
		for (int i = 0; i < nums.size(); i++)
			dp[i][i].push_back(nums[i]);
		for (int cnt = 0; cnt < ops.size(); cnt++)
		{
			for (int head = 0, tail = cnt + 1; tail <= ops.size(); head++, tail++)
			{
				for (int mid = head; mid < tail; mid++)
				{
					for (auto left : dp[head][mid])
					{
						for (auto right : dp[mid + 1][tail])
						{
							if (ops[mid] == '+')
								dp[head][tail].push_back(left + right);
							else if (ops[mid] == '-')
								dp[head][tail].push_back(left - right);
							else
								dp[head][tail].push_back(left * right);
						}
					}
				}
			}
		}
		return dp.front().back();
	}
};