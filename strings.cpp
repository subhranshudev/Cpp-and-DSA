#include<iostream>
#include<string.h> // or <cstring>
using namespace std;

void toUpperCase(char word[], int n){
    for (int i = 0; i < n; i++)
    {
       char ch = word[i];
       if (ch>= 'A' && ch<= 'Z')
       {
            continue;
       } else{
            word[i] = ch - 'a' + 'A';
       }
       
    }
    
}

void toLowerCase(char word[], int n){
    for (int i = 0; i < n; i++)
    {
       char ch = word[i];
       if (ch>= 'a' && ch<= 'z')
       {
            continue;
       } else{
            word[i] = ch - 'A' + 'a';
       }
       
    }
    
}

void reverse(char word[], int n){
    int start = 0, end = n-1;
    while (start< end)
    {
       swap(word[start], word[end]);
       start++;
       end--;
    }
}

bool isdPalindrome(char word[], int n){
    int start = 0, end = n-1;
    while(start < end){
        if (word[start] != word[end])
        {
            cout<< "Not a valid palindrome"<< endl;
            return false;
        } 
        start++;
        end--;
    }
    cout << "Valid Palindrome";
    return true;
}




int main(){
/*  // Basics 
    char word[] = { 'c', 'o', 'd', 'e', '\0'};
    cout<< word << endl; // It will directly print all the elements of char array, No loops required
    cout<< strlen(word)<< endl;
    char word2[] = "hello";
    cout<< word2 << endl;
    cout<< strlen(word2)<< endl;
*/

/*    // Taking inputs
    // char word[30]; 
    // cin>> word;  // It will ignore all the inputs after a whitespace
    // cout << "Your word is: "<< word<< endl;
    // cout<< "Length of word is: "<< strlen(word)<< endl;

    char sentence[30];
    cout<< "Enter: ";
    cin.getline(sentence, 30, '*'); // It will take all inputs including whitespaces but wil stop taking input from the
                                    // char given in 3rd parameter(3rd parameter called delimiter is optional)
    cout << "Your sentence is: "<< sentence<< endl;
    cout<< "Length of sentence is: "<< strlen(sentence)<< endl;
*/

/*    // Convert to UpperCase
    char word[] = "ApPle";
    toUpperCase(word, strlen(word));
    cout<< word<< endl;
    // Convert to Lowercase
    char word2[] = "dHaNi";
    toLowerCase(word2, strlen(word2));
    cout<< word2<< endl;
*/

/*    // Reverse a Character array
    char word[] = "code";
    reverse(word, strlen(word));
    cout<< word<< endl;
*/

/*    // Valid Palindrome or not
    char word[] = "racecar";
    isdPalindrome(word, strlen(word));
*/

    return 0;
}