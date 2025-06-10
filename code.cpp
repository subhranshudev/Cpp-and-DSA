// #include<iostream>
// using namespace std;

// int main(){
//     //cout<< "Hello Subhranshu"<< "\n";
//      cout<< "Hello Subhranshu"<< "\n";
//      cout<< "Hello World"<< "\n";

//     //int a, b;
//     // cout<< "Enter a: ";
//     // cin>> a;

//     // cout<< "Enter b: ";
//     // cin>> b;
//     // int sum = a+b;
//     // cout<< "Sum is: "<< sum;

//     // cout<< "Enter two numbers: ";
//     // cin>> a>> b;

//     // int sum = a+ b;
//     // int diff = a- b;
//     // int product = a* b;
//     // int div = a/ b;
//     // int modulo = a% b;

//     // cout<< "Sum, diff, product, div, modulo: "<< sum<< " ,"<< diff<< " ,"<< product<< " ,"<< div<< " ,"<< modulo;


// //  CONDITIONALS --->
//     //int n;
//     // cout<< "Enter the number: ";
//     // cin>> n;
//     // if (n >=0)
//     // {
//     //     cout<<"Entered number is positive";
//     // }else {
//     //     cout<<"Entered number is negative";
//     // }

//     // cout<< "Enter the number: ";
//     // cin>> n;
//     // if (n % 2 == 0)
//     // {
//     //     cout<<"Entered number is even";
//     // }else {
//     //     cout<<"Entered number is odd";
//     // }
    
//     // int marks;
//     // cout<<"Enter marks: ";
//     // cin>> marks;

//     // if (marks >= 90)
//     // {
//     //     cout<< "Grade: A";
//     // }
//     // else if (marks >= 80)
//     // {
//     //     cout<< "Grade: B";
//     // }
//     // else if (marks >= 70)
//     // {
//     //     cout<< "Grade: C";
//     // }
//     // else if (marks >= 60)
//     // {
//     //     cout<< "Grade: D";
//     // }
//     // else
//     // {
//     //     cout<< "Grade: E";
//     // }
    

// //     char letter;
// //     cout<< "Enter the letter: ";
// //     cin>> letter;

// //    // int ascii = (int)letter;

// //     if (letter >='a' && letter <= 'z')
// //     {
// //        cout<< "Lowercase";
// //     }
// //     else if (letter >='A' && letter <= 'Z')
// //     {
// //        cout<< "Uppercase";
// //     }
// //     else
// //     {
// //         cout<< "invalid character";
// //     }

// // Use of ascii value, type casting and conditionals 

//     // Implict conversion
//     // char letter;
//     // cout<< "Enter the letter: ";
//     // cin>> letter;

    
//     // if (letter >= 97)
//     // {
//     //    cout<< "Lowercase";
//     // }
//     // else if (letter >= 65 && letter <= 90)
//     // {
//     //    cout<< "Uppercase";
//     // }
//     // else
//     // {
//     //     cout<< "invalid character";
//     // }

//     // Explicit conversion
//     // char letter;
//     // cout<< "Enter the letter: ";
//     // cin>> letter;

//     // int ascii = (int)letter;

//     // if (ascii >= 97)
//     // {
//     //    cout<< "Lowercase";
//     // }
//     // else if (ascii >= 65 && ascii <= 90)
//     // {
//     //    cout<< "Uppercase";
//     // }
//     // else
//     // {
//     //     cout<< "invalid character";
//     // }
    

// // Ternary operator
// // condition ? true : false ;

//     // int n;
//     // cout<< "Enter the number: ";
//     // cin>> n;

//     // //n >= 0 ? cout<<"Positive" : cout<< "Negative" ;
//     // cout<< (n >= 0 ? "Positive" : "Negative");

// // LOOPS --->
//     // int count = 1;
//     // int n;
//     // cout<< "Enter the number: ";
//     // cin>> n;


//     // while ( count <= n )
//     // {
//     //     cout<< count << " ";
//     //     count++;
//     // }

//     // for (int i = 1; i <= n; i++)
//     // {
//     //      cout<< i << " ";
//     // }

// //     int sum = 0 ;
// //     // for (int i = 1; i <= n; i++)
// //     // {
// //     //     sum += i;
// //     // }
// //     // cout<< "sum: " << sum;
    
// //     int oddSum = 0;
// //     for (int i = 1; i <= n; i++)
// //     {
// //        if (i % 2 != 0)
// //        {
// //             oddSum += i;
// //        }
       
// //     }
// //     cout<< "Odd sum: " << oddSum << endl;

// //     int evenSum = 0;
// //     for (int i = 1; i <= n; i++)
// //     {
// //        if (i % 2 == 0)
// //        {
// //             evenSum += i;
// //        }
       
// //     }
// //     cout<< "Even sum: " << evenSum;
    
// // CHECK "PRIME NUMBER" OR NOT

// // int n;
// // bool isPrime = true;
// // cout<<"Enter the number: ";
// // cin>> n;
// //  for (int i = 2; i < n; i++)
// //  {
// //     if (n % i == 0)
// //     {
// //         isPrime =false;
// //         break;
// //     }
    
// //  }

// //  if (isPrime == true)
// //  {
// //     cout<< "The number is prime";
// //  }else
// //  {
// //     cout<< "The number is not prime";
// //  }
 
 
// // NESTED LOOP --> 

// // for (int i = 1; i <= 5; i++)
// // {
// //     for (int j = 1; j <= 5; j++)
// //     {
// //        cout<<"* " ;
// //     }
// //     cout<< endl;
    
// // }

//     return 0;
// }

// #include <iostream>
// #include<cmath>
// using namespace std;

// int main(){
    // int a;
    // cout<< "Enter number:";
    // cin>>a;
    // cin>>b;
    // if (a>b)
    // {
    //     cout<<a<<" is the largest number";
    // }else {
    //     cout<<b<<" is the largest number";
    // }

    // if (a%2 == 0)
    // {
    //    cout<<a<< " is an even number";
    // }else{
    //     cout<<a<< " is an odd number";
    // }
    
    // int income;
    // float tax;

    // cout<< "Enter your income(in lakhs): ";
    // cin>> income;

    // if (income<5)
    // {
    //     tax= 0;
    // }else if (income<=10)
    // {
    //     tax = (0.2*income);
    // }else{
    //     tax = (0.3*income);
    // }
    
    // cout<< "Your tax is = "<<tax*100000;   
    // int a, b, c;
    // cout<< "Enter a: ";
    // cin>>a;
    // cout<< "Enter b: ";
    // cin>>b;
    // cout<< "Enter c: ";
    // cin>>c;

    // if (a>=b && a>=c)
    // {
    //    cout<<"a is largest "<< a;
    // }else if (b>=c)
    // {
    //     cout<<"b is largest "<< b;
    // }else 
    // {
    //     cout<<"c is largest "<< c;
    // }

    // for(int i=1; i<=5; i++){
    //     cout<<"Apna College"<<endl;
    // }
    
    // int n;
    // cout<< "Enter the number: ";
    // cin>>n;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout<<i<<" ";
    // }

    // int N, sum=0;
    // cout<<"Enter N: ";
    // cin>>N;
    // for (int i = 1; i <=N; i++)
    // {
    //     sum = sum + i;
    // }
    // cout<<"Sum of first "<< N <<" natural number is: "<< sum;
    
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j= 0; j < 4; j++)
    //     {
    //         cout<<"* ";
    //     }
    //     cout<<endl;
        
    // }
    

    // int n;
    // cout<<"Enter n: ";
    // cin>>n;
    // for (int i = n; i >=1; i--)
    // {
    //     cout<<i<<" ";
    // }

    // int n= 10829;
    // int lastDigit, sum = 0;
    // while (n > 0)
    // {
    //     lastDigit = n % 10;
    //     cout<< lastDigit<< " ";
    //     if (lastDigit % 2 != 0)
    //     {
    //         sum += lastDigit;
    //     }
        
        
    //     n = n/10;
    // }
    // cout<<"sum = "<<sum;
    // int n = 10829;
    // int lastDigit = 0, result = 0;
    // while (n > 0)
    // {
    //     lastDigit = n%10;
    //     cout<<" "<<lastDigit;
    //     result = result *10 + lastDigit;
    //     n = n/10;
    // }
    // cout<<"result = "<<result;

    // int n;
    
    // do
    // {
    //     cout<<"Enter number: ";
    //     cin>>n;
    //     if (n%10 == 0)
    //     {
    //         continue;
    //     }
        
    //     cout<<"You entered "<< n << endl;

    // } while (true);
    
    // int n;
    // bool isPrime = true;
    // cout<<"Enter the number: ";
    // cin>>n;
    // for (int i = 2; i <= sqrt(n); i++)
    // {
    //    if (n % i == 0)
    //    {
    //     isPrime = false;
    //     break;
    //    }
    // }
    // if (!isPrime)
    // {
    //     cout<<"n is not a prime number";
    // } else
    // {
    //     cout<<"n is a prime number";
    // }
    
    // for (int i = 1; i <= 4; i++)
    // {
    //     for (int j = 1; j <= 4; j++)
    //     {
    //         cout<<i <<" ";
    //     }
    //     cout<<"\n";
        
    // }

    // for (int i = 1; i <=4; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }
    
//     int n = 4;
//     for (int i = 1; i <=n; i++)
//     {
//        for (int j = 1; j <=n-i+1; j++)
//        {
//         cout<<"* ";
//        }
//        cout<<endl;
       
//     }
    
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <=i; j++)
//         {
//            cout<< j<<" ";
//         }
//         cout<<endl;
        
//     }


//     char ch = 'A';
//    for (int i = 1; i <=n; i++)
//    {
//     for (int j = 1; j <=i; j++)
//     {
//         cout<<ch;
//         ch++;
//     }
//     cout<<endl;
//    }

// int n = 4;
// for (int i = 1; i <=n; i++)
// {
//     cout<<"*";
    
//     for (int j = 1; j <=n-1; j++)
//     {
//         if (i==1 || i==n)
//         {
//             cout<<"*";
//         } else
//         {
//             cout<<" ";
//         }
//     }
    
//     cout<<"*"<< endl;

// }

// for (int i = 1; i <=n; i++)
// {
//     for (int j = 1; j <=n; j++)
//     {
//         if (j<=n-i)
//         {
//             cout<<" ";
//         }else
//         {
//             cout<<"*";
//         }   
//     }
//     cout<<endl;
    
// }

// for (int i = 1; i <=n; i++)
// {
//     for (int j = 1; j <=n-i; j++)
//     {
//         cout<<" ";
//     }
//     for (int j = 1; j <= i ; j++)
//     {
//         cout<<"*";
//     }
//     cout<<endl;
    
// }

//     int num = 1;
//     for (int i = 1; i <=5; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             cout<< num++<< " ";
//         }
//         cout<< endl;
        
//     }
    // int n = 4;
    // for (int i = 1; i <= n ; i++)
    // {
    //     // for spaces
    //     for (int j = 1; j <= n-i; j++)
    //     {
    //         cout<< " ";
    //     }

    //     //for stars
    //     for (int j = 1; j <= 2*i-1; j++)
    //     {
    //         cout<< "*";
    //     }
    //     cout<< endl;   
    // }
    
    // for (int i = n; i >= 1; i--)
    // {
        
    //     //for spaces
    //     for (int j = 1; j <= n-i; j++)
    //     {
    //         cout<< " ";
    //     }
        
    //     // for stars
    //     for (int j = 1; j <= 2*i-1; j++)
    //     {
    //         cout<< "*";
    //     }
    //     cout<< endl;
        
    // }

    //for upper portion
//     

#include<iostream>
#include<cmath>
using namespace std;

// int prod(int a, int b){
//     return a*b;
// }

// bool isEven(int a){
//     if (a%2 == 0)
//     {
//         return true;
//     } else {
//        return false;
//     }  
// }

// int factorial(int n){
//     int fact = 1;
//     for(int i = 1; i<=n; i++){
//         fact = fact*i;
//     }
//     return fact;
// }

// bool isPrime(int n){
//     if (n == 1)
//     {
//         return false;
//     }
    
//     for (int i = 2; i <=sqrt(n); i++)
//     {
//        if (n%i == 0)
//        {
//         return false;
//        }

       
//     }
//     return true;
    
// }

// int factorial(int n){
//     int fact = 1;
//     for (int i = 1; i <= n; i++)
//     {
//        fact = fact*i;
//     }

//     return fact;
    
// }

// int binCoeff(int n, int r){
//     int val1 = factorial(n);
//     int val2 = factorial(r);
//     int val3 = factorial(n-r);

//     int result = val1/ (val2*val3);
//     return result;
// }

bool isPrime(int n){
    if(n == 1){
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n%i == 0)
        {
            return false;
        }
        
    }
    return true;
    
}

void allPrimes(int n){
    for (int i = 2; i <=n; i++)
    {
        if (isPrime(i))
        {
            cout<< i <<" ";
        }
        
    }
    
}

int main() {
//    int prodVal = prod(2, 3);
//    cout<<"Product = "<< prodVal;

//    cout<< isEven(8);

    // cout<<"factorial = "<< factorial(6);

    // cout<< isPrime(7);

    // cout<< "binomial coeff = "<< binCoeff(4, 2);
    allPrimes(50);
    return 0;
}