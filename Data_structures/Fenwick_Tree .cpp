#include <vector>
using namespace std;

class Fenwick_Tree
{
private:
	int size;
	vector<int> tree;

public:
	Fenwick_Tree(int size)
	{
		this->size = size + 1;
		this->tree = vector<int>(this->size);
	}

	void update(int i, int delta)
	{
		i++;
		while (i < size)
		{
			tree[i] += delta;
			i += (i & (~i + 1));
		}
	}

	int sum(int i)
	{
		i++;
		int sum = 0;
		while (i > 0)
		{
			sum += tree[i];
			i -= (i & (~i + 1));
		}
		return sum;
	}

	int range_sum(int l, int r) // not incluseive of r
	{
		return sum(l) - sum(r);
	}
};