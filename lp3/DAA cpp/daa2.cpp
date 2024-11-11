// DAAL_2_

//Huffman Encoding using Greedy approach.

#include <iostream>
using namespace std;

class Node
{
	public:

		int data;
		char leaf;
		string path;
		Node *left;
		Node *right;

		Node(int x, char y, string z, Node *l=NULL, Node *r=NULL)
		{
			data = x; leaf = y; path = z; left = l; right = r;
		}
};

class QNode
{
	public:

		Node *data;
		QNode *next;

		QNode(Node *x)
		{
			data = x; next = NULL;
		}
};

class Queue
{
	public:
		QNode *front;
		Queue(){ front=NULL; }

		void enqueue(Node *x)
		{
			QNode *n = new QNode(x);
			if (front==NULL)
				front = n;
			else
			{
				QNode *temp = front;
				while(temp->next != NULL)
					temp = temp->next;
				temp->next = n;
			}
		}

		QNode* dequeue()
		{
			if (front==NULL)
			{
				cout<<"Queue Underflowed."<<endl;
				return NULL;
			}
			else
			{
				QNode *temp = front;
				front = front->next;
				return temp;
			}
		}
};

void sort(Node* arr[], int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]->data > arr[j+1]->data)
			{
				Node *temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

void pathify(Node* n) 
{
	Queue *q = new Queue();
	q->enqueue(n);
    while(q->front != NULL)
    {
    	Node *x = q->dequeue()->data;
    	if(x->left != NULL)
    	{
    		x->left->path = x->path+'0';
    		q->enqueue(x->left);
	    }
    	if(x->right != NULL)
    	{
    		x->right->path = x->path+'1';
    		q->enqueue(x->right);
	    }
    }
}

int main()
{
	int n;
	cout<<"Enter the number of characters in the document : ";
	cin>>n;
	Node* arr[2 * n - 1];

	for(int i=0; i<2*n-1; i++)
		arr[i] = new Node(0,' '," ");

	for(int i=0;i<n;i++)
	{
		cout<<"Enter the character "<<(i+1)<<" : ";
		cin>>arr[i]->leaf;
		cout<<"Enter the frequency of character "<<(i+1)<<" : ";
		cin>>arr[i]->data;
	}

	for(int i=0;i<n-1;i++)
	{
		sort(arr, 2*n-1);
		Node *temp = new Node(arr[n+i-1]->data + arr[n+i]->data, ' ', " ", arr[n+i-1], arr[n+i]);
		arr[n+i-1]->data = 0; arr[n+i]->data = 0;
		arr[0] = temp;
	}

	Node *root = arr[0];
	pathify(root);

	cout<<"The Huffman Codes are : "<<endl;
	for(int i=0;i<2*n-1;i++)
	{
		if (arr[i]->leaf !=' ')
			cout<<arr[i]->leaf<<" = "<<arr[i]->path<<endl;
	}

	return 0;
}

/*
tweety@tweety-HP-ProBook-450-G3:~/DAA_BE_34$ ./a.out
Enter the number of characters in the document : 5
Enter the character 1 : E
Enter the frequency of character 1 : 2
Enter the character 2 : A
Enter the frequency of character 2 : 3
Enter the character 3 : D
Enter the frequency of character 3 : 4
Enter the character 4 : B
Enter the frequency of character 4 : 5
Enter the character 5 : C
Enter the frequency of character 5 : 6
The Huffman Codes are : 
E =  010
A =  011
D =  00
B =  10
C =  11
*/