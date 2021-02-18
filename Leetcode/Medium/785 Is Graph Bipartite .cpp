// DFS (it can be done with BFS as well)
// Time : O(V + E) V - number of vertexes; E - number of edges
// Space : O(V)
// color each node with either 0 or 1 and if two adjacent have the same color then it's impossible than it's possible
bool DFS(int index, vector<vector<int>> &graph, vector<int> &col)
{
	int cur_col = col[index];

	for (int conn : graph[index]) // conn: conected node
	{
		if (col[conn] == cur_col)
			return false;
		if (col[conn] == -1)
		{
			col[conn] = 1 - cur_col;
			if (!DFS(conn, graph, col))
				return false;
		}
	}
	return true;
}
bool isBipartite(vector<vector<int>> &graph)
{
	int n = graph.size();
	vector<int> col(n, -1); // colors: -1 undefind, 1 ,0

	for (int i = 0; i < n; i++)
	{
		if (col[i] == -1)
		{
			col[i] = 1;
			if (!DFS(i, graph, col))
				return false;
		}
	}
	return true;
}