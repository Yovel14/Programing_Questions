#include <iostream>

using namespace std;

template <typename T>
class Fenwick_Tree
{
private:
	int size;
	T *tree;

public:
	Fenwick_Tree(int size)
	{
		this->size = size + 1;
		this->tree = new T[this->size]();
	}

	// update value at index i
	void update(int i, T delta)
	{
		i++;
		while (i < size)
		{
			tree[i] += delta;
			i += (i & (~i + 1));
		}
	}

	// sum from 0 to i inclusive
	T sum(int i)
	{
		i++;
		T sum = 0;
		while (i > 0)
		{
			sum += tree[i];
			i -= (i & (~i + 1));
		}
		return sum;
	}

	// sum from l to r inclusive of both l and r
	T range_sum(int l, int r)
	{
		if (l > 0)
			return sum(r) - sum(l - 1);
		return sum(r);
	}

	// value at index. not sum to index
	T get(int index)
	{
		return range_sum(index, index);
	}
};

main()
{
	Fenwick_Tree<int> tree(2); // initialize

	tree.update(0, 1);			 // update value at index 0
	cout << tree.sum(0) << '\n'; // print sum to index 0;

	tree.update(1, 2);			 // update value at index 1
	cout << tree.sum(1) << '\n'; // print sum to index 1;

	cout << tree.get(0) << '\n'; // get original value at index 0;

	cout << tree.get(1) << '\n'; // get original value at index 1
	return 0;
}