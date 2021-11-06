#include<iostream>
#include<stdio.h>
#include<algorithm>

int *array;

int main()
{
    array = new int[3000000]{};
    int tc,n;
    int i;

    scanf("%d",&tc);

    while(tc--)
    {
        scanf("%d",&n);
        for(int j=0;j<n;j++)
            scanf("%d",&array[j]);

        std::sort(array,array+n);

        for(i=0;i<n-1;i++)
            printf("%d ",array[i]);

        printf("%d",array[n-1]);
        printf("\n");
    }

    delete[] array;
    return 0;
}
