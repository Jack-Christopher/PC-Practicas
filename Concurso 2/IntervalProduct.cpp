#include <iostream>
#include <bits/stdc++.h>

int tree[ 1<<18];
int X[100005];

void construct ( int node, int i, int j ) 
{
    if ( i == j ) 
    {
        tree[node] = (X[i] < 0 ? -1 : (X[i] > 0 ? 1 : 0) );
        return;
    }
    int middle = (i + j)/2;
    construct( 2*(node)+1, i, middle );
    construct( 2*(node)+2, middle + 1, j );

    tree[node] = tree[2*(node)+1] * tree[2*(node)+2];
}

int query ( int node, int i, int j, int l, int r ) 
{
    if ( i == l && j == r )
        return tree[node];

    int middle = (i + j)/2;
    if ( r <= middle )
        return query( 2*(node)+1, i, middle, l, r );
    else if ( l > middle )
        return query( 2*(node)+2, middle + 1, j, l, r );

    int left = query( 2*(node)+1, i, middle, l, middle );
    int right = query( 2*(node)+2, middle + 1, j, middle + 1, r );

    return left * right;
}

int update ( int node, int i, int j, int x, int value ) {
    if ( i == x && j == x ) {
        X[x] = value;
        return tree[node] = (value < 0 ? -1 : (value > 0 ? 1 : 0) );
    }

    int middle = (i + j)/2;
    int left, right;

    if ( x > middle ) 
    {
        left = tree[2*(node)+1];
        right = update( 2*(node)+2, middle + 1, j, x, value );
    }
    else 
    {
        left = update( 2*(node)+1, i, middle, x, value );
        right = tree[2*(node)+2];
    }

    return tree[node] = left * right;
}







int main()
{
    //N : elementos de la secuencia
    //K : rondas
    int N, K;
    int result;
    while (std::cin>> N >> K)
    {
        for (int i = 0; i < N; i++)
            scanf("%d", &X[i]);
        
        construct(0, 0, N-1);
        char command;
        int first, last;
        while (K--)
        {
            scanf(" %c", &command);
            scanf("%d %d", &first, &last);

            if (command == 'C')
                update(0, 0, N-1, first-1, last);
            else if ( command == 'P')
            {
                result = query(0, 0, N-1, first-1, last-1);
            
                if (result < 0)
                    printf("-");
                else if (result > 0)
                    printf("+");
                else
                    printf("0");
            }
        }
        printf("\n");
    }
    return 0;
}