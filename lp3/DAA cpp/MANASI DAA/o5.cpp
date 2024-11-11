#include<iostream>
using namespace std;
#define max 10
void printSolution(int board[max][max],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<" "<<board[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}
bool isSafe(int board[max][max],int row,int col,int n)
{
	int i,j;
	for(i=0;i<col;i++)
		if(board[row][i])
			return false;
			
	for(i=row,j=col;i>=0 && j>=0;i--,j--)
		if(board[i][j])
			return false;
	
	for(i=row,j=col;j>=0 && i<n;i++,j--)
		if(board[i][j])
			return false;
			
	return true;
}
bool solveNQUtil(int board[max][max],int col,int n)
{
	if(col >= n)
		return true;
	
	for(int i=0;i<n;i++)
	{
		if(isSafe(board,i,col,n))
		{
			board[i][col] = 1;
			cout<<"\nQueen place at ("<<i<<","<<col<<")"<<endl;
			printSolution(board,n);
			
			if(solveNQUtil(board,col+1,n))
				return true;
			board[i][col] = 0;
			cout<<"\nBractracking from ("<<i<<","<<col<<")"<<endl;
			printSolution(board,n);
		}
	}
	return false;
}
int main()
{
	int n;
	cout<<"\nEnter n: ";
	cin>>n;
	
	int board[max][max];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			board[i][j] = 0;
	
	/*	// Ask user for the position of the first queen
	    int  firstrow;
	    
	    cout << "Enter the row (0 to " << n - 1 << ") for the first queen: ";
	    cin >> firstrow;
	    
	    // Place the first queen at the specified position
	    board[firstrow][0] = 1;
	    printSolution(board, n); // Print the initial board with the first queen

	    // Start placing the next queens from col 1, since col 0 has the first queen*/
		     //(board,1,n)
	if(!solveNQUtil(board,0,n))
	{
		cout<<"\nSolution does not exists"<<endl;
	}
	else
	{
		cout<<"\nFinal solution"<<endl;
		printSolution(board,n);
	}
	return 0;
}
