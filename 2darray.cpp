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

void totalDiagonalSum(int matrix[][4], int n){
    int primaryDsum = 0, secondaryDsum = 0, common = 0, totalSum = 0;

    for (int i = 0; i < n; i++) // O(N^2)
    {
        for (int j = 0; j < n; j++)
        {
            
            if (i == j)
            {
                primaryDsum = primaryDsum + matrix[i][j];   
                totalSum = totalSum + matrix[i][j];
            }else if (j == n-1-i)
            {
                secondaryDsum = secondaryDsum + matrix[i][j];
                totalSum = totalSum + matrix[i][j];
            }       
        }
        
    }
    cout<< "Primary diagonal sum = "<< primaryDsum<< endl ;
    cout<< "Secondary diagonal sum = "<< secondaryDsum << endl ;
    cout<< "Total sum = "<< totalSum<< endl;

}

void totalDiagonalSum2(int matrix[][3], int n){
    int sum = 0, common = 0;
    for (int i = 0; i < n; i++) //O(N)
    {   
        sum = sum + matrix[i][i];   
        if (i != n-i-1)
        {
            sum = sum + matrix[i][n-i-1]; 
        }
        
    }
    cout<< "Total sum = "<< sum << endl;
    
}

bool search(int matrix[][4], int n, int m, int key){
    int i = 0, j = m-1;
    while(i<n && j>=0){
        if (matrix[i][j] == key)
        {
           cout<< "Found at ("<< i<< ","<< j<< ")\n";
           return true;
        } else if(matrix[i][j] < key){
            i++;
        } else{
            j--;
        }
    }
    cout<< "Key not found \n";
    return false;
}

bool search2(int matrix[][4], int n, int m, int key){
    int i = n-1, j = 0;
    while(i>=0 && j<m){
        if (matrix[i][j] == key)
        {
           cout<< "Found at ("<< i<< ","<< j<< ")\n";
           return true;
        } else if(matrix[i][j] < key){
            j++;
        } else{
            i--;
        }
    }
    cout<< "Key not found \n";
    return false;
}

void matrixPtr(int mat[][4], int n, int m){
    cout<< "Matrix row Pointer = "<< mat<< endl;
    cout<< "Matrix row Pointer = "<< mat+1<< endl;
    cout<< "Matrix row Pointer = "<< mat+2<< endl;

    cout<< "Matrix row value = "<< *(mat)<< endl;
    cout<< "Matrix row value = "<< *(mat+1)<< endl;
    cout<< "Matrix row value = "<< *(mat+2)<< endl;

    cout<< "Value of a particular element = "<< *(*(mat + 3)+3)<< endl;
}

void keyNum(int mat[][3], int n, int m, int key){
    int num = 0;
    for (int i = 0; i < n; i++)
    {
       for (int  j = 0; j < m; j++)
       {
            if (mat[i][j] == key)
            {
                num++;
            }
            
       }
       
    }
    cout<< key << " is present "<< num << " times \n";
    
}

int sumIthrow(int mat[][3], int m, int rownum){
    int sum = 0;
    for (int j = 0; j < m; j++)
    {
        sum = sum + mat[rownum-1][j];
    }
    cout<< "Sum of elements of row " << rownum << " = "<< sum<< endl;
    return sum;
}

/*void swap(int &val1, int &val2){
    int temp = val1;
    val1 = val2;
    val2 = temp;
}*/ // Or I can use the inbuilt swap function

int main(){
    //int arr[3][4];
    //int n = 3, m = 4;
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

/*    // Spiral matrix
int matrix[4][4] = { {1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16} };

spiralMatrix(matrix, 4, 4);

int matrix2[3][4] = { {1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12} };
spiralMatrix(matrix2, 3, 4);
*/

/*   // Diagonal sum
    int matrix[4][4] = { {1, 2, 3, 4},
                        {5, 6, 7, 8},
                        {9, 10, 11, 12},
                        {13, 14, 15, 16} };
    int matrix2[3][3] = { {1, 2, 3},
                         {4, 5, 6},
                         {7, 8, 9} };
    // totalDiagonalSum(matrix, 4);
    //totalDiagonalSum(matrix2, 3);
    //totalDiagonalSum2(matrix, 4);
    totalDiagonalSum2(matrix2, 3);
*/

/*    // Search in sorted(both row and column) matrix
    int matrix[4][4] = { {10, 20, 30, 40},
                         {15, 25, 35, 45},
                         {27, 29, 37, 48},
                         {32, 33, 39, 50} };
    //search(matrix, 4, 4, 32);
    search2(matrix, 4, 4, 39);
*/

/*   // Matrix Pointer
    int mat[4][4] = { {1, 2, 3, 4},
                    {5, 6, 7, 8},
                    {9, 10, 11, 12},
                    {13, 14, 15, 16} };
    matrixPtr(mat, 4, 4);
*/

    // ASSIGNMENT
/*    // 1. Print how many times a particular number or element is present
    int arr[2][3] = { {4, 7, 8},
                       {8, 8, 7} };
    keyNum(arr, 2, 3, 8);
*/

/*    // 2. Print the sum of numbers in ith row
    int nums[][3] = { {1, 4, 9},
                       {11, 4, 3},
                       {2, 2, 3} };

    sumIthrow(nums, 3, 2);
*/
    
/*    // 3. Transpose of a matrix
    int row = 2, col = 3;
    int mat[][col] =  { {1, 2, 3},
                        {4, 5, 6} };

    int transpose[col][row] = {{0}};
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
           transpose[j][i] = mat[i][j];
        };
        
    }

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
          cout<< transpose[i][j] <<" ";
        }
        cout<< endl;
        
    }
*/

/*    // convert 1D array to 2D array --> Leetcode 2022
    // Solution using array
    int original[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(original) / sizeof(int);
    int m =3, n = 2;

   if ((size % 2) != 0)
   {
     cout << "can't convert to 2D array"<< endl;
   } else {
        int mat[m][n] = {{0}};
        int k = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
            mat[i][j] = original[k];
            k++;
            }
            
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
            cout<< mat[i][j] <<" ";
            }
            cout<< endl;
            
        }
        
   }
*/   
 
    // Rotate image
    
    int mat[][3] = { {1, 2, 3},
                     {4, 5, 6},
                     {7, 8, 9} };
    int mat2[][4] = { {5, 1, 9, 11},
                      {2, 4, 8, 10},
                      {13, 3, 6, 7},
                      {15, 14, 12, 16} };
    int row = 3, col = 3;

/*  // Brute force approach --> with creating a extra matrix
    int rotated[col][row] = {{0}};
    for (int i = 0; i < row; i++)
    {
       for (int j = 0; j < col; j++)
       {
            rotated[j][col-1-i] = mat2[i][j];
       }
       
    }

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
          cout<< rotated[i][j] <<" ";
        }
        cout<< endl;
        
    }
*/
    
    //Optimised --> Without creating any extra array
    // Taking transpose of swquare matrix
    for (int i = 0; i < row; i++)
    {
       for (int j = i+1; j < col; j++)
       {
            swap(mat[i][j], mat[j][i]);
       }
       
    }

    for (int i = 0; i < row; i++)
    {
        int start = 0, end = col-1;
        while (start<=end)
        {
           swap(mat[i][start], mat[i][end]);
           start++;
           end--;
        }
        
    }
    

    //Printing the array
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
          cout<< mat[i][j] <<" ";
        }
        cout<< endl;
        
    }
    

    return 0;
}