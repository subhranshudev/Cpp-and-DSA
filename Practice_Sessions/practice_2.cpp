#include<iostream>
#include<cmath>
using namespace std;

int main() {
    // Assignment questions of chapter-10: Conditional Statements

    // get number form user and print whether number is +ve, 0 or -ve: 
/*  int num;   // always use useful variable name
    cout<< "Enter the number: ";
    cin>>num;
    if (num > 0 )
    {
       cout<< "The number is positive";
    }else if (num == 0)
    {
        cout<< "The entered number is zero";
    } else
    {
        cout<< "The number is negative";
    } 
    using ternary operator
    (num > 0) ? cout<< "Positive": (num == 0) ? cout<< "Zero" : cout<< "Negative";
*/

  //Enter the year and check leap year or not
/*  int year;
  cout<<"Enter the year: ";
  cin>> year;
  if (year%4 == 0) {
    if (year %100 == 0) {
      if (year %400 == 0) {
        cout<< year <<" is a leap year";
      } else {
        cout<< year << " is not a leap year";
      }
      
    } else{
      cout<< year <<" is a leap year";
    }
    
  } else {
    cout<< year << " is not a leap year";
  } 
*/

// bool x = (63 < 36) ? true: false;
// cout << "x = "<< x;
  //0, 63 --> athi datatype bool thile b x print kalabele 0 print haba false nuhe
  //bye

 int num;
 cout<< "Enter the number: ";
 cin>>num;
 int n = num; // creating a copy of entered number because it will be updated to a new value and I need the original value for comparision

 // int dig1 = n%10;
// n = n/10;
// int dig2  = n%10;
// n = n/10;
// int dig3 = n %10;

// int sum = (dig1*dig1*dig1) + (dig2*dig2*dig2) + (dig3*dig3*dig3);

//using loop and pow function
int sum = 0;
while (n > 0)
{
  int digit = n%10;
  sum = sum + pow(digit, 3);
  n = n/10;
}


if (num == sum){
  cout<< "The number is an Armstrong number";
} else{
  cout<< "The number is not an Armstrong number";

}


}