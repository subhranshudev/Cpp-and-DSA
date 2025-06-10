#include<iostream>
using namespace std;

int main() {
    // Assignment questions of chapter-10: Conditional Statements

    // get number form user and print whether number is +ve, 0 or -ve: 
  int num;   // always use useful variable name
    cout<< "Enter the number: ";
    cin>>num;
    // if (num > 0 )
    // {
    //    cout<< "The number is positive";
    // }else if (num == 0)
    // {
    //     cout<< "The entered number is zero";
    // } else
    // {
    //     cout<< "The number is negative";
    // } 
    // using ternary operator
    (num > 0) ? cout<< "Positive": (num == 0) ? cout<< "Zero" : cout<< "Negative";

}