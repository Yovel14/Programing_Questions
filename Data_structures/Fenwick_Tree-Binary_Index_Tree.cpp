#include <iostream>
#include <vector>

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
	Fenwick_Tree(vector<int> &v)
	{
		this->size = v.size() + 1;
		this->tree = new T[this->size];
		for (int i = 0; i < v.size(); i++)
			this->tree[i + 1] = v[i];

		int p;
		for (int i = 1; i < this->size; i++)
		{
			p = i + (i & (~i + 1));
			if (p < this->size)
				tree[p] += tree[i];
		}
	}
	Fenwick_Tree(int a[], int size)
	{
		this->size = size + 1;
		this->tree = new T[this->size];
		for (int i = 0; i < size; i++)
			this->tree[i + 1] = a[i];

		int p;
		for (int i = 1; i < this->size; i++)
		{
			p = i + (i & (~i + 1));
			if (p < this->size)
				tree[p] += tree[i];
		}
	}

	~Fenwick_Tree()
	{
		delete tree;
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

	tree.update(0, 1);								// update value at index 0;
	cout << "expected 1 : " << tree.sum(0) << '\n'; // print sum to index 0;

	tree.update(1, 2);								// update value at index 1;
	cout << "expected 3 : " << tree.sum(1) << '\n'; // print sum to index 1;

	cout << "expected 1 : " << tree.get(0) << '\n'; // get original value at index 0;

	cout << "expected 2 : " << tree.get(1) << '\n'; // get original value at index 1;

	tree.~Fenwick_Tree();

	vector<int> test_vector = {1, 2};
	Fenwick_Tree<int> tree2(test_vector);
	cout << "expected 3 : " << tree2.sum(1) << '\n'; // print sum to index 1;

	int test_arr[] = {1, 2};
	Fenwick_Tree<int> tree3(test_arr, 2);
	cout << "expected 3 : " << tree3.sum(1) << '\n'; // print sum to index 1;

	return 0;
}
