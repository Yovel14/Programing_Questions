// solution 1

class Solution
{
public:
	bool canVisitAllRooms(vector<vector<int>> &rooms)
	{
		vector<bool> foundKeys(rooms.size(), false);
		stack<int> keys;
		keys.push(0);
		foundKeys[0] = true;
		int roomsVisitedCount = 0;

		while (!keys.empty())
		{
			int key = keys.top();
			keys.pop();
			roomsVisitedCount++;

			for (int currentKey : rooms[key])
			{
				if (!foundKeys[currentKey])
				{
					keys.push(currentKey);
					foundKeys[currentKey] = true;
				}
			}
		}

		return roomsVisitedCount == rooms.size();
	}
};

// solution 2

class Solution
{
public:
	bool canVisitAllRooms(vector<vector<int>> &rooms)
	{
		vector<bool> visitedRooms(rooms.size(), false);
		set<int> keys;
		keys.insert(0);
		int roomsVisitedCount = 0;

		while (keys.size())
		{
			set<int>::iterator keyIter = keys.begin();
			int key = *keyIter;
			keys.erase(keyIter);
			visitedRooms[key] = true;
			roomsVisitedCount++;

			for (int currentKey : rooms[key])
			{
				if (!visitedRooms[currentKey] && keys.find(currentKey) == keys.end())
				{
					keys.insert(currentKey);
				}
			}
		}

		return roomsVisitedCount == rooms.size();
	}
};

// solution 3

class Solution
{
private:
	int helper(vector<vector<int>> &rooms, vector<bool> &foundKeys, int roomNum)
	{
		if (foundKeys[roomNum])
		{
			return 0;
		}

		foundKeys[roomNum] = true;
		int sum = 1;

		for (int key : rooms[roomNum])
		{
			sum += helper(rooms, foundKeys, key);
		}

		return sum;
	}

public:
	bool canVisitAllRooms(vector<vector<int>> &rooms)
	{
		vector<bool> foundKeys(rooms.size(), false);

		return helper(rooms, foundKeys, 0) == rooms.size();
	}
};