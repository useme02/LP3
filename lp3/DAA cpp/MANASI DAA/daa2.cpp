#include<bits/stdc++.h>
using namespace std;
struct MinHeapNode
{
	char data;
	unsigned freq;
	MinHeapNode *left,*right;
	
	MinHeapNode(char data,unsigned freq)
	{
		left = right = NULL;
		this -> data = data;
		this -> freq = freq;
	}
};
struct compare
{
	bool operator()(MinHeapNode *l,MinHeapNode *r)
	{
		return (l -> freq > r->freq);
	}
};
void printCodes(MinHeapNode *root,string str)
{
	if(!root)
		return;
	if(root -> data != '$')
		cout<<root->data<<" : "<<str<<endl;
	printCodes(root -> left,str+"0");
	printCodes(root -> right,str+"1");
}
void HuffmanCodes(char data[],int freq[],int size)
{
	struct MinHeapNode *left,*right,*top;
	priority_queue<MinHeapNode *,vector<MinHeapNode*>,compare> minHeap;
	for(int i=0;i<size;i++)
	{
		minHeap.push(new MinHeapNode(data[i],freq[i]));
	}
	while(minHeap.size() != 1)
	{
		left = minHeap.top();
		minHeap.pop();
		
		right = minHeap.top();
		minHeap.pop();
		
		top = new MinHeapNode('$',left -> freq + right -> freq);
		top -> left = left;
		top -> right = right;
		minHeap.push(top);
	}
	cout<<"\n-----------------------Huffman Codes-------------------------"<<endl;
	printCodes(minHeap.top(),"");
}
int main()
{
	int n;
	cout<<"\nEnter the total number of characters : ";
	cin>>n;
	char* data = new char[n];
	int* freq = new int[n];
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter character "<<i+1<<" : ";
		cin>>data[i];
		cout<<"\nEnter frequency of character "<<i+1<<" : ";
		cin>>freq[i];
	}
	HuffmanCodes(data,freq,n);
	delete data;
	delete freq;
	return 0;
}
