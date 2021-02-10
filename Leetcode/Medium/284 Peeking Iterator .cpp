// Time : O(1)
// Space : O(1) two support variables
class PeekingIterator : public Iterator
{
	bool _hasNext;
	int _nextVal;

public:
	PeekingIterator(const vector<int> &nums) : Iterator(nums)
	{
		this->_hasNext = Iterator::hasNext();
		if (this->_hasNext)
			this->_nextVal = Iterator::next();
	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek()
	{
		return this->_nextVal;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next()
	{
		int t = this->_nextVal;

		this->_hasNext = Iterator::hasNext();
		if (this->_hasNext)
			this->_nextVal = Iterator::next();

		return t;
	}

	bool hasNext() const
	{
		return _hasNext;
	}
};