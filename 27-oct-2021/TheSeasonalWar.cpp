#include <iostream>

int matrix[25][25];
// int n, m;

void flood_fill(int x,int y, int dim)
{
    if(x < 0 || y < 0 || x >= dim || y >= dim)
        return;
    if(matrix[x][y] != 1)
        return;
    if(matrix[x][y] == 1)
        matrix[x][y] = 0;

    flood_fill(x,y+1,dim);
    flood_fill(x,y-1,dim);
    flood_fill(x+1,y,dim);
    flood_fill(x-1,y,dim);
    flood_fill(x+1,y+1,dim);
    flood_fill(x+1,y-1,dim);
    flood_fill(x-1,y+1,dim);
    flood_fill(x-1,y-1,dim);
}


int main()
{
    int dim, counter;
    char number;
    int test_case = 1;

    while (std::cin>> dim)
    {
        // std::getchar();
        // printf("dim: %d\n", dim);
        for(int i = 0; i < dim;i++)
        {
            // std::cout<< "row: " << i << std::endl;
            for(int j = 0; j < dim; j++)
            {
                // printf("j: %d\t", j);
                std::cin>> number;
                if (number == '0')
                    matrix[i][j] = 0;
                else
                    matrix[i][j] = 1;
            }
            // printf("\n");
            // std::cout<< std::endl;
        }

        counter = 0;

        for(int i = 0; i < dim; i++)
        {
            for(int j = 0; j < dim; j++)
            {
                if(matrix[i][j] != 0)
                {
                    // printf("matrix[%d][%d] = %d\n", i, j, matrix[i][j]);
                    flood_fill(i,j,dim);
                    counter++;
                }
            }
        }
        
        std::cout<< "Image number " << test_case++ << " contains " << counter << " war eagles." << std::endl;
    }

    return 0;
}