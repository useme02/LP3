#include<iostream>
using namespace std;
class Node
{
	public:
		float profit;
		float weight;
		int originalIndex;
		Node(float x,float y,int index)
		{
			profit = x;
			weight = y;
			originalIndex = index;
		}
};
void sort(Node *arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]->profit / arr[j] -> weight < arr[j+1]->profit / arr[j+1]->weight)
			{
				Node* temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
int main()
{
	int n;
	cout<<"\nEnter the total number of objects : ";
	cin>>n;
	int c;
	cout<<"\nEnter the capacity of the knapsack : ";
	cin>>c;
	
	Node *arr[n];
	for(int i=0;i<n;i++)
	{
		float p,w;
		cout<<"\nEnter profit "<<i+1<<" : ";
		cin>>p;
		cout<<"\nEnter weight "<<i+1<<" : ";
		cin>>w;
		arr[i] = new Node(p,w,i+1);
	}
	sort(arr,n);
	cout<<"\n----------------------------------------------------------------------------------";
	cout<<"\nObjects\t\t\tProfit\t\t\tWeight\t\t\tRatio\t\t\tAction\t\t\tTotal Profit\t\t\tTotal Weight";
	cout<<"\n---------------------------------------------------------------------------------------";
	float tot_p = 0;				   
	float tot_w = 0;
	int i=0;
	while(tot_w < c && i<n)
	{
		
		float ratio = arr[i]->profit / arr[i]->weight;
		cout<<"\n"<<arr[i]->originalIndex<<"\t\t\t"<<arr[i]->profit<<"\t\t\t"<<arr[i]->weight<<"\t\t\t"<<ratio<<"\t\t\t";
		if(tot_w + arr[i] ->weight <= c)
		{
			tot_p += arr[i]->profit;
			tot_w += arr[i]->weight;
			cout<<"ADD ENTIRE"<<"\t\t\t"<<tot_p<<"\t\t\t"<<tot_w<<endl;
		}
		else
		{
			float required = c - tot_w;
			tot_p += arr[i]->profit * (required/arr[i]->weight);
			tot_w = c;
			cout<<"ADD FRACTIONAL"<<"\t\t\t"<<tot_p<<"\t\t\t"<<tot_w<<endl;
			break;
		}
		i++;
	}
	cout<<"\nMaximum Profit : "<<tot_p<<endl;
	for(int i=0;i<n;i++)
	{
		delete arr[i];
	}
	return 0;
}
