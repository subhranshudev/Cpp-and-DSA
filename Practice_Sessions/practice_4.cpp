#include<iostream>
using namespace std;

int main() {
/*    // 1. 0-1 triangle pattern --> This is for alternate 0-1 pattern
    int n = 5;
    int val = true;
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<< val;
            val = !val;
        }
        cout<< endl;
        
    }
*/  /* 
    int n =5; // It is the actual for the pattern given in assignment 
    for (int i = 1; i <=n; i++)
    {
        for (int j = i; j >=1; j--)
        {
            // cout<< j; --> It is skeleton for this 0-1 pattern
            cout<< j%2<< " ";  // For even it will print 0  and for odd it will print 1
        }
        cout<< endl;
    
    }

    
/*   // 2. Rhombus pattern
    int n = 5;
    for (int i = 1; i <=n; i++)
    {
        // Reversed triangle of space
        for (int j= 1; j <=n-i; j++)
        {
            cout<<" ";
        }
        // square pattern
        for (int j = 0; j <=n; j++)
        {
            cout<< "* ";
        }
        cout<< endl;
        
    }
*/ 

/* // 3. Palindrome Pattern
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >=2; j--)
        {
            cout<< j;
        }
        
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        cout<< endl;
        
    }
*/


// int n = 5;
// for (int i = 0; i < n; i++)
// {
//     for (int j = n; j >= n-i; j--)
//     {
//         cout<< j<< " ";
//     }
//     cout<< endl;
    
// }

// or
/*
 int n = 5;
for (int i = n; i >=1; i--)
{
    for (int j = n; j >= i; j--)
    {
        cout<< j << " ";
    }
    cout<< endl; 
}
*/

/* 
int n = 5;
for (int i = 1; i <=n; i++)
{
    for (int j = i; j >= 1; j--)
    {
        cout<< j << " ";
    }
    cout<< endl;
    
}
*/

/* int  n = 5;
for (int i = n; i >= 1; i--)
{
    for (int j = i; j <=n; j++)
    {
        cout<< j <<" ";
    }
    cout<< endl;
    
} */

/*  
int n= 5;
for (int i = 1; i <=n; i++)
{
    for (int j = 1; j <= i; j++)
    {
        cout<< i <<" ";
    }
    cout << endl;
    
}
*/

/*
int  n = 4;
int val = 1;
for (int i = 1; i <= n; i++)
{
    for (int j = 1; j <= i; j++)
    {
        cout<< val<< " ";
        val++;
    }
    cout<< endl;
    
}
*/

/*
int n =5;
for (int i = 1; i <= n; i++)
{
    for (int j = 1; j <= n; j++)
    {
       if (i ==1 || i == n || j == 1 || j == n)
       {
        cout<< "*";
       } else
       {
        cout<< " ";
       } 
       
    }
    cout<< endl;
    
}
*/

/*
int n = 5;
for (int i = 1; i <=n; i++)
{
    // for space
    for (int j = 1; j <= n-i; j++)
    {
        cout<< " ";
    }
    //for element
    for (int j = 1; j <= i; j++)
    {
        cout<< j;
    }
    cout<< endl;
    
}
*/






    return 0;
}