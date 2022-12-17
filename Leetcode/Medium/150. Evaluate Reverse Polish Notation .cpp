class Solution
{
private:
	bool inline isOperator(string &str)
	{
		return str == "+" || str == "-" || str == "*" || str == "/";
	}

	long inline performOperation(long &v1i, long &v2i, string &oper)
	{
		if (oper == "+")
		{
			return v1i + v2i;
		}

		if (oper == "-")
		{
			return v1i - v2i;
		}

		if (oper == "*")
		{
			return v1i * v2i;
		}

		return v1i / v2i;
	}

public:
	int evalRPN(vector<string> &tokens)
	{
		stack<long> nums;

		for (int index = 0; index < tokens.size(); index++)
		{
			if (this->isOperator(tokens[index]))
			{
				long v2 = nums.top();
				nums.pop();
				long v1 = nums.top();
				nums.pop();

				nums.push(this->performOperation(v1, v2, tokens[index]));
			}
			else
			{
				nums.push(std::stoi(tokens[index]));
			}
		}

		return nums.top();
	}
};