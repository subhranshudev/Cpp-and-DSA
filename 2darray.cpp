#include<iostream>
using namespace std;

void spiralMatrix(int matrix[][4], int n, int m){
    int srow = 0, scol = 0, erow = n-1, ecol = m-1;
    while (srow <= erow && scol <= ecol)
    {
        //top
        for (int j = scol; j <= ecol; j++)
        {
            cout<< matrix[srow][j]<< " ";
        }

        //right
        for (int i = srow + 1; i <= erow; i++)
        {
            cout<< matrix[i][ecol]<< " ";
        }
        
        //bottom
        for (int j = ecol - 1; j >= scol; j--)
        {
            if(srow == erow){
                break;
            }
        cout<< matrix[erow][j]<< " ";
        }

        // left
        for (int i = erow - 1; i >= srow + 1; i--)
        {
            if(scol == ecol){
                break;
            }
            cout<< matrix[i][scol]<< " ";
        }

        srow++, scol++;
        erow--, ecol--;
    }
cout<< endl;
}

int main(){
    int arr[3][4];
    int n = 3, m = 4;
/*    // Taking input and printing output
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>> arr[i][j];
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<< arr[i][j]<< " ";
        }
        cout<< endl;
        
    }
*/   

int matrix[4][4] = { {1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16} };

spiralMatrix(matrix, 4, 4);

int matrix2[3][4] = { {1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12} };
spiralMatrix(matrix2, 3, 4);
    return 0;
}