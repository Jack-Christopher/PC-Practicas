#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int getSum(int BITree[], int index)
{
	int sum = 0;
    while (index > 0)
	{
		sum += BITree[index];
    	index -= index & (-index);
	}
	return sum;
}

void updateBIT(int BITree[], int n, int index, int val)
{
	while (index <= n)
	{
	    BITree[index] += val;
	    index += index & (-index);
	}
}

long long int getInvCount(int arr[], int n)
{
	long long int invcount = 0; 
	long long int maxElement = 0;
	for (int i=0; i<n; i++)
		if (maxElement < arr[i])
			maxElement = arr[i];

	int BIT[maxElement+1];
	for (int i=1; i<=maxElement; i++)
		BIT[i] = 0;

	for (int i=n-1; i>=0; i--)
	{
		invcount += getSum(BIT, arr[i]-1);
    	updateBIT(BIT, maxElement, arr[i], 1);
	}
	return invcount;
}


// If i < j and A[i] > A[j] then (i, j) is an inversion 

int A[200000];

int main()
{
    int T;
    int n;
    scanf("%d", &T);
    getchar();
    
    while (T--)
    {
        scanf("%d", &n);
        for (int k=0; k<n; k++)
            scanf("%d", &A[k]);            
        getchar();
        std::cout << getInvCount(A, n) << std::endl;
    }

    return 0;
}