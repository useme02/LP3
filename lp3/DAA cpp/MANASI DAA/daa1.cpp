#include<iostream>
using namespace std;
int fibo_recursive(int n)
{
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	else 
		return fibo_recursive(n - 1) + fibo_recursive(n-2);
}
void print_fibo_recursive_sequence(int n)
{
	for(int i=0;i<=n;i++)
	{
		cout<<" "<<fibo_recursive(i)<<" ";
	}
	cout<<endl;
}
int fibo_iterative(int n)
{
	int a = 0,b=1,c;
	cout<<a<<" ";
	for(int i=0;i<n;i++)
	{
		cout<<b<<" ";
		c = a+b;
		a=b;
		b=c;
	}
	return a;
}
int main()
{
	while(true)
	{
		int n,ch;
		cout<<"\nEnter the n: ";
		cin>>n;
		cout<<"\nEnter 1.Recursive 2.Non-Recursive 3.Exit : ";
		cin>>ch;
		if(ch == 1)
		{
			cout<<"\nFibonacci Sequence : ";
			print_fibo_recursive_sequence(n);
			int a = fibo_recursive(n);
			cout<<"\nNth fibonacci number is : "<<a<<endl;
		}
		else if(ch == 2)
		{
			cout<<"\nFibonacci Sequence : ";
			int a = fibo_iterative(n);
			cout<<"\nNth fibonacci number is : "<<a<<endl;
		}
		else
		{
			cout<<"Invalid Choice.";
			break;
		}
	}
	return 0;
}
