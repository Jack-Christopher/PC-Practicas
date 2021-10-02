#include <iostream>
#include <vector>

bool BinarySearch( std::vector<std::vector<int>>& matrix, int left, int right, int target)
{
    int i_start = left / matrix.size();
    int i_end = right / matrix.size();
    int j_start = left % matrix.size();
    int j_end = right % matrix.size();
    int i_mid = (i_start + i_end) / 2;
    int j_mid = (j_start + j_end) / 2;
    int mid = matrix[0].size() * i_mid + j_mid;

    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (matrix[i_mid][j_mid] == target)
            return true;
        if (matrix[i_mid][j_mid] > target)
            return BinarySearch(matrix, left, mid - 1, target);

        return BinarySearch(matrix, mid + 1, right, target);
    }
  
    return false;
}

bool BinarySearch( std::vector<std::vector<int>>& matrix, int target )
{
    return BinarySearch( matrix, 0, matrix.size()*matrix[0].size() - 1, target );
}


int main()
{
    std::vector<std::vector<int>> matrix = {    
        {1,   2,  3,  4,  5},
        {6,   7,  8,  9,  10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    std::cout << BinarySearch(matrix, 70) << std::endl;
    

    return 0;
}