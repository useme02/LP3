// DAAL_4

// 0-1 Knapsack using Dynamic Programming

#include <iostream>
using namespace std;

int main()
{ 
    int n=10;
    // cout<<"Enter the no. of objects : "<<endl;
    // cin>>n;
    int weights[n] = {5,  4,  7, 3, 2,  9,  8, 6, 1, 10};
    int profits[n] = {10, 8, 12, 6, 3, 16, 15, 7, 2, 18};

    // for(int i=0;i<n;i++)
    // {
    //     cout<<"Enter the profit of object"<<(i+1)<<" : "<<endl;
    //     cin>>profits[i];
    //     cout<<"Enter the weight of object"<<(i+1)<<" : "<<endl;
    //     cin>>weights[i];
    // }

    int c=10;
    // cout<<"Enter the capacity of the sack : "<<endl;
    // cin>>c;

    int mem_tab[n+1][c+1];
    for(int i=0;i<=n;i++)
    {
        for(int w=0;w<=c;w++)
            mem_tab[i][w] = 0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int w=1;w<=c;w++)
        {   
            int a = mem_tab[i-1][w], b;

            // 0 <= weight <= w
            if(weights[i-1] <= w)
                b = mem_tab[i-1][w - weights[i-1]] + profits[i-1];
            else
                b = 0;

            mem_tab[i][w] = a>b ? a:b;
         }
    }

    cout<<endl<<"The Memoization Table : "<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int w=0;w<=c;w++)
            cout<<mem_tab[i][w]<<'|';
        cout<<endl;
    }

    int max_p = mem_tab[n][c];
    int tot_w = 0;
    char ans[n];
    for(int i=0;i<n;i++)
    {
        if (mem_tab[i][c] != mem_tab[i+1][c])
        {
            if(tot_w + weights[i] <= c)
            {
                tot_w += weights[i];
                ans[i] = '1';
            }
            else
                ans[i] = '0';
        }
        else
            ans[i] = '0';
    }

    cout<<endl<<"The answer : ";
    for(int i=0;i<n;i++)
        cout<<ans[i];
    cout<<endl;
    
    return 0;
}
