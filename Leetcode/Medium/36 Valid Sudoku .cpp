bool isValidSudoku(vector<vector<char>> &board)
{
	int index;
	int block_index;
	bool rows[10][10] = {0};
	bool columns[10][10] = {0};
	bool blocks[10][10] = {0};

	for (int y = 0; y < 9; y++)
		for (int x = 0; x < 9; x++)
		{
			if (board[y][x] != '.')
			{
				index = board[y][x] - '0';
				block_index = (y / 3) * 3 + x / 3;

				if (blocks[block_index][index])
					return false;
				blocks[block_index][index] = true;

				if (rows[y][index])
					return false;
				rows[y][index] = true;

				if (columns[x][index])
					return false;
				columns[x][index] = true;
			}
		}
	return true;
}

void Fill(bool exist[])
{
	for (int i = 1; i < 10; i++)
		exist[i] = false;
}
bool isValidSudoku(vector<vector<char>> &board)
{
	int index;
	bool exist[10] = {0};

	for (vector<char> &a : board)
	{
		for (char &c : a)
		{
			if (c != '.')
			{
				index = c - '0';
				if (exist[index])
					return false;
				exist[index] = true;
			}
		}
		Fill(exist);
	}

	//check col
	for (int col = 0; col < 9; col++)
	{
		for (int row = 0; row < 9; row++)
		{
			if (board[row][col] != '.')
			{
				index = board[row][col] - '0';
				if (exist[index])
					return false;
				exist[index] = true;
			}
		}
		Fill(exist);
	}

	for (int row = 0; row < 9; row += 3)
	{
		for (int col = 0; col < 9; col += 3)
		{
			for (int r = row; r < (row + 3); r++)
			{
				for (int c = col; c < (col + 3); c++)
				{
					if (board[r][c] != '.')
					{
						index = board[r][c] - '0';
						if (exist[index])
							return false;
						exist[index] = true;
					}
				}
			}
			Fill(exist);
		}
	}
	return true;
}