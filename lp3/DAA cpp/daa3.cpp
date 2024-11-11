// DAAL_3_

//Fractional Knapsack using Greedy approach.

#include <iostream>
using namespace std;

class Node
{
	public:

		float profit;
		float weight;

		Node(float x, float y)
		{
			profit = x; weight = y;
		}
};

void sort(Node* arr[], int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			// Descending
			if(arr[j]->profit/arr[j]->weight < arr[j+1]->profit/arr[j+1]->weight)
			{
				Node *temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main()
{
	int n,c;
	cout<<"Enter the number of objects : ";
	cin>>n;
	cout<<"Enter the capacity of the sack : ";
	cin>>c;

	Node* arr[n];
	for(int i=0;i<n;i++)
	{
		arr[i] = new Node(0,0);
		cout<<"Enter the Profit of object "<<(i+1)<<" : ";
		cin>>arr[i]->profit;
		cout<<"Enter the Weight of object  "<<(i+1)<<" : ";
		cin>>arr[i]->weight;
	}
	sort(arr, n);

	float tot_p = 0;
	float tot_w = 0;
	int i=0;

	while(tot_w < c)
	{
		tot_p += arr[i]->profit;
		tot_w += arr[i]->weight;
		i+=1;
	}
	if(tot_w==c)
		cout<<"Maximum profit = "<<tot_p<<endl;
	else
	{
		tot_p -= arr[i-1]->profit;
		tot_w -= arr[i-1]->weight;
		float required = c - tot_w;
		tot_p += arr[i-1]->profit * required / arr[i-1]->weight;
		tot_w = c;
		cout<<"Maximum profit = "<<tot_p<<endl;
	}

	return 0;
}

/*
tweety@tweety-HP-ProBook-450-G3:~/DAA_BE_34$ ./a.out
Enter the number of objects : 7
Enter the capacity of the sack : 15
Enter the Profit of object 1 : 5
Enter the Weight of object  1 : 1
Enter the Profit of object 2 : 10
Enter the Weight of object  2 : 3
Enter the Profit of object 3 : 15
Enter the Weight of object  3 : 5
Enter the Profit of object 4 : 7
Enter the Weight of object  4 : 4
Enter the Profit of object 5 : 8
Enter the Weight of object  5 : 1
Enter the Profit of object 6 : 9
Enter the Weight of object  6 : 3
Enter the Profit of object 7 : 4
Enter the Weight of object  7 : 2
Maximum profit = 51
*/