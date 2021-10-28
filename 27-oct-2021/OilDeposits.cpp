#include<bits/stdc++.h>

int m,n;
char str[1002][1002];

void flood_fill(int x,int y)
{
    if(x < 0 || y < 0 || x == m || y == n)
        return;
    if(str[x][y] != '@')
        return;
    if(str[x][y] == '@')
        str[x][y] = '*';

    flood_fill(x,y+1);
    flood_fill(x,y-1);
    flood_fill(x+1,y);
    flood_fill(x-1,y);
    flood_fill(x+1,y+1);
    flood_fill(x+1,y-1);
    flood_fill(x-1,y+1);
    flood_fill(x-1,y-1);
}
int main()
{
    int counter;
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        if(m == 0)
            break;
        for(int i = 0; i < m;i++)
            for(int j = 0; j < n; j++)
                std::cin >> str[i][j];
        counter = 0;
        //  contar los depositos de petroleo
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(str[i][j] != '*')
                {
                  flood_fill(i,j);
                  counter++;
                }
            }
        }
        printf("%d\n",counter);
    }
    return 0;
}