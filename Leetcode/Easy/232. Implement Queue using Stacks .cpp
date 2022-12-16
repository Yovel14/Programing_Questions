class MyQueue
{
private:
	std::stack<int> mainStack;
	std::stack<int> tempStack;

	void inline transferStackValues(std::stack<int> &s1, std::stack<int> &s2)
	{
		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
	}

public:
	MyQueue() {}

	void push(int x)
	{ // time: O(1)
		this->mainStack.push(x);
	}

	int pop()
	{ // time: O(n) wehre n is the number of values pushed in
		this->transferStackValues(this->mainStack, this->tempStack);
		int temp = this->tempStack.top();
		this->tempStack.pop();
		this->transferStackValues(this->tempStack, this->mainStack);
		return temp;
	}

	int peek()
	{ // time: O(n) wehre n is the number of values pushed in
		this->transferStackValues(this->mainStack, this->tempStack);
		int temp = this->tempStack.top();
		this->transferStackValues(this->tempStack, this->mainStack);
		return temp;
	}

	bool empty()
	{ // time: O(1)
		return this->mainStack.empty();
	}
};
