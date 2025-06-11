#include<iostream>
using namespace std;

bool checkPrime(int n) {
    if (n == 0 || n == 1) {
        return false; // Neither prime nor composite
    }
        
    for (int i = 2; i*i <= n; i++)
    {
        if (n%i == 0)
        {
            return false;
        } 
    }
    return true;
}

int calculateSum(int num) {
    int sum = 0;
    while (num>0)
    {
        int digit = num%10;
        sum = sum+digit;
        num = num/10;
    }
    return sum;
    
}

int wholeSquare(int a, int b){
    int result = (a*a)+(b*b)+(2*a*b);
    return result;
}

void largest(int num1, int num2, int num3){
    if (num1 > num2 && num1 > num3)
    {
        cout<< num1<< " is largest";
    } else if (num2 > num3)
    {
        cout<< num2<< " is largest";
    } else {
        cout<< num3<< " is largest";
    }
    
    
}

char nextChar(char ch) {
    if (ch == 'z')
    {
        return 'a';
    }
    
    char newCh= ch + 1;
    return newCh;
}


int main() {
/*   // Print all prime numbers between 2 and N
    int N;
    cout<< "Enter N: ";
    cin>>N;
    for (int i = 2; i <= N; i++)
    {
        if (checkPrime(i))
        {
            cout<< i <<" ";
        }
        
    }
*/

/* // 1. Palindrome check
    int num;
    cout<< "Enter number: ";
    cin>> num;
    int num2 = num;
    int newNum = 0;
    while (num2 > 0)
    {
        int digit = num2%10; // Extracting digits from last
        newNum = (newNum*10) + digit; // reversing the number
        num2 = num2/10;
    }

    if (num == newNum)
    {
        cout<< num << " is a palindrome";
    } else{
        cout<< num << " is not a palindrome";
    }
*/

/*   // 2. calculate sum of digits of a number
    int num;
    cout<< "Enter number: ";
    cin>> num;
    int sum = calculateSum(num);
    cout <<"sum of digits = "<< sum; 
*/   


/*    //3. calculate whole square(a^2+b^2+2ab)
    int a, b;
    cout<< "Enter a: ";
    cin>>a;
    cout<< "Enter b: ";
    cin>>b;
    int result = wholeSquare(a, b);
    cout<< "Result = "<< result;
*/

/*   // 4. largest of 3 numbers
    int num1, num2, num3;
    cout<< "Enter number 1: ";
    cin>> num1;
    cout<< "Enter number 2: ";
    cin>> num2;
    cout<< "Enter number 3: ";
    cin>> num3;
    largest(num1, num2, num3);
*/

    // 5. print next character
    char ch;
    cout<< "Enter the character: ";
    cin>> ch;
    char newChar = nextChar(ch);
    cout<<"New character: "<< newChar;


    return 0;
}