# include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int row, column;
	char c;
	cin >> column >> c;
	row = (column + 1) / 2;

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			if (i == 0 || i == row - 1 || j == 0 || j == column - 1)
			{
				cout << c;
				if (j == column - 1)
					cout << "\n";
			}
			else
			{
				cout << " ";
			}
		}
	}
	return 0;
}