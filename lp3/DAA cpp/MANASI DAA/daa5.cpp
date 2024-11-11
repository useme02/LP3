#include<iostream>
using namespace std;
#define max 10
void printSolution(int board[max][max],int n)
{
	for(int i =0 ;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{	
			cout<<" "<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
bool issafe(int board[max][max],int row,int col,int n)
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
		
		if(issafe(board,i,col,n))
		{
			board[i][col] = 1;
			cout<<"\nQueen placed at ("<<i<<","<<col<<")"<<endl;
			printSolution(board,n);
			if(solveNQUtil(board,col+1,n))
				return true;
			board[i][col]=0;
			cout<<"\nBacktracking from ("<<i<<","<<col<<")"<<endl;
			printSolution(board,n);
		}
	}
	return false;
}
int main()
{
	int n;
	cout<<"\nEnter the number of queens : ";
	cin>>n;
	int board[max][max]={0};
	if(!solveNQUtil(board,0,n))
	{
		cout<<"\nNo solution exits"<<endl;
	}
	else
	{
		cout<<"\nFinal Solution"<<endl;
		printSolution(board,n);
	}
	return 0;
	
}
