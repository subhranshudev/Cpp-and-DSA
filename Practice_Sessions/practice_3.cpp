#include<iostream>
#include<cmath>
using namespace std;

int main() {
/*   // 1. factorial of number entered by the user
    int num;
    cout<< "Enter the number: ";
    cin>> num;
    int fact = 1;
    for (int i = 1; i <=num; i++)
    {
        fact = fact*i;
    }
    cout<< "factorial = "<<  fact;
*/

/*    // 2. to print the multiplication table of a number
    int num; 
    cout<< "Enter the number: ";
    cin>> num;
    for (int i = 1; i <=10; i++)
    {
        int result = num*i;
        cout<< result << " ";
    }
*/

/*    // 3. check the number is Armstrong number or not
    int num;
    cout<< "Enter the number: ";
    cin>> num;
    int num2 = num;
    int sum = 0;
    while (num2>0)
    {
        int digit = num2 % 10;
        sum = sum + pow(digit, 3);
        num2 = num2/10;
    }

    if (num == sum)
    {
        cout<< "The entered number is an Armstrong number";
    } else{
        cout<< "The entered number is not an Armstrong number";
    }
*/

/*    // 4. WAP to print all the prime numbers from 2 to N
    int N;
    cout<< "Enter N: ";
    cin>> N;
    for (int i= 2; i <=N; i++)
    {
        if (i == 2)
        {
            cout<< i <<" ";
        }
        
        for (int j = 2; j <=sqrt(N); j++)
        {
           if (i%j != 0)
           {
                cout<< i <<" ";
           }
           
        }  
    }
*/

/*    // 5. Print a Fibonacci Series of N numbers 
    int N;
    cout<< "Enter N: ";
    cin>> N;
    int first = 0, second = 1;
    cout << first << " " << second << " ";
    for (int i = 3; i <=N; i++)
    {
       int third = first + second;
       first = second;
       second = third;
       cout<< third << " ";
    }
*/ 

// Fizz Buzz 
int n;
cout<< "Enter n: ";
cin>>n;

//  for (int i = 1; i <=n; i++) {
//     if (i%3 == 0 && i%5 == 0)
//     {
//         cout<< "FizzBuzz ";
//     } else if (i%3 == 0)
//     {
//        cout<<"Fizz ";
//     }else if (i%5 == 0)
//     {
//         cout<< "Buzz ";
//     } else
//     {
//         cout<< i<< " ";
//     }  
    
// }

 // optimised approach-->
 int Fizz = 0, Buzz = 0;
 for (int i = 1; i <= n; i++)
 {
    Fizz++;
    Buzz++;
    if (Fizz == 3 && Buzz == 5)
    {
        cout<< "FizzBuzz ";
        Fizz =0;
        Buzz = 0;
    }else if (Fizz == 3)
    {
        cout<< "Fizz ";
        Fizz = 0;
    }else if (Buzz == 5)
    {
        cout<< "Buzz ";
        Buzz =0;
    } else{
        cout<< i << " ";
    }
    
    
 }
 


    
    

    
}