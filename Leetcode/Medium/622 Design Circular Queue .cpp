class MyCircularQueue
{
private:
	int size;
	int index;
	queue<int> q;

public:
	// index is the place to add new item
	MyCircularQueue(int k)
	{
		this->size = k;
	}

	bool enQueue(int value)
	{
		if (this->isFull())
			return false;
		this->q.push(value);
		return true;
	}

	bool deQueue()
	{
		if (this->isEmpty())
			return false;
		q.pop();
		return true;
	}

	int Front()
	{
		if (!this->isEmpty())
			return this->q.front();
		return -1;
	}

	int Rear()
	{
		if (!this->isEmpty())
			return this->q.back();
		return -1;
	}

	bool isEmpty()
	{
		return this->q.size() == 0;
	}

	bool isFull()
	{
		return this->q.size() == this->size;
	}
};