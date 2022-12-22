// solution 1: create graph that describes dislike relationship and device nodes into colors red and blue and there is a devision mistake it's not possible otherwise it is check that using bfs
class Solution
{
private:
	bool BFS(int source, vector<int> &color, vector<vector<int>> &adj)
	{
		queue<int> q;
		q.push(source);
		color[source] = 0;

		while (!q.empty())
		{
			int currentNode = q.front();
			q.pop();

			for (int &neighbor : adj[currentNode])
			{
				if (color[neighbor] == color[currentNode])
				{
					return false;
				}
				if (color[neighbor] == -1)
				{
					q.push(neighbor);
					color[neighbor] = 1 - color[currentNode];
				}
			}
		}

		return true;
	}

public:
	bool possibleBipartition(int n, vector<vector<int>> &dislikes)
	{
		vector<vector<int>> adj(n + 1, vector<int>());

		for (vector<int> &dislike : dislikes)
		{
			adj[dislike[0]].push_back(dislike[1]);
			adj[dislike[1]].push_back(dislike[0]);
		}

		vector<int> color(n + 1, -1);
		for (int i = 1; i <= n; i++)
		{
			if (color[i] == -1)
			{
				if (!BFS(i, color, adj))
				{
					return false;
				}
			}
		}

		return true;
	}
};

// solution 2: create graph that describes dislike relationship and device nodes into colors red and blue and there is a devision mistake it's not possible otherwise it is check that using bfs

class Solution
{
private:
	bool dfs(int source, vector<int> &color, vector<vector<int>> &adj)
	{
		for (int nieghbor : adj[source])
		{
			if (color[nieghbor] == color[source])
			{
				return false;
			}

			if (color[nieghbor] == -1)
			{
				color[nieghbor] = 1 - color[source];
				if (!dfs(nieghbor, color, adj))
				{
					return false;
				}
			}
		}

		return true;
	}

public:
	bool possibleBipartition(int n, vector<vector<int>> &dislikes)
	{
		vector<vector<int>> adj(n + 1, vector<int>());

		for (vector<int> &dislike : dislikes)
		{
			adj[dislike[0]].push_back(dislike[1]);
			adj[dislike[1]].push_back(dislike[0]);
		}

		vector<int> color(n + 1, -1);
		for (int i = 1; i <= n; i++)
		{
			if (color[i] == -1)
			{
				color[i] = 0;
				if (!dfs(i, color, adj))
				{
					return false;
				}
			}
		}

		return true;
	}
};