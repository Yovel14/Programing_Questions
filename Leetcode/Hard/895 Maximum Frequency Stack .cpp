// Space : O(n) where n is the amount of pushed integers
class FreqStack
{
private:
	int mx_freq = 0;
	unordered_map<int, int> freq;
	unordered_map<int, stack<int>> group;

public:
	FreqStack()
	{
	}

	void push(int x) // Time : O(1)
	{
		cout << "push" << '\n';

		int count = ++freq[x];

		if (mx_freq < count)
			mx_freq = count;

		group[count].push(x);
	}

	int pop() // Time : O(1)
	{

		cout << "pop" << '\n';
		unordered_map<int, stack<int>>::iterator it = group.find(mx_freq);

		int t = it->second.top();
		it->second.pop();
		--freq[t];

		if (it->second.empty())
			mx_freq--;

		return t;
	}
};