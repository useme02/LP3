// DAAL_5_

//n-Queens using Backtracking. (n=4)

#include <iostream>
using namespace std;

void print(int board[4][4])
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
			cout<<board[i][j]<<"|";
		cout<<endl;
	}
	cout<<"--------"<<endl;
}

bool attack(int board[4][4], int row, int i)
{
	bool attack=false;

	// Not in same column
	for(int j=0;j<4;j++)
	{
		if(j!=row && board[j][i]==1)
			attack = true;
 	}

 	// Not on same diagonal
 	for(int j=0;j<4;j++)
	{
		for(int k=0;k<4;k++)
		{
			if(j+k == row+i && board[j][k]==1)
				attack = true;
			if(j-k == row-i && board[j][k]==1)
				attack = true;
	 	}
 	}
 	return attack;
}

void nqueens(int board[4][4], int row)
{
	if(row == 4)
	{
		print(board);
		return;
	}
	else
	{
		for(int i=0;i<4;i++)
		{
			if(!attack(board, row, i))
			{
				board[row][i] = 1;
				nqueens(board, row+1);
				board[row][i] = 0;
			}	
		}
	}
}

int main()
{
	int board[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	nqueens(board, 0);
	return 0;
}

/*
tweety@tweety-HP-ProBook-450-G3:~/DAA_BE_34$ ./a.out
0|1|0|0|
0|0|0|1|
1|0|0|0|
0|0|1|0|
--------
0|0|1|0|
1|0|0|0|
0|0|0|1|
0|1|0|0|
--------
*/