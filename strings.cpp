#include<iostream>
#include<cstring> // or <string.h> --> For char array
#include<string>
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

bool isAnagram(string str1, string str2) {
        if(str1.length() != str2.length()){
            cout<< "Not a valid Anagram\n";
            return false;
        }

        int count[26];
        for(int i = 0; i < str1.length(); i++){
            int index = str1[i] - 'a';
            count[index]++;
        }
        for(int i = 0; i < str2.length(); i++){
            int index = str2[i] - 'a';
            if(count[index] == 0){
                cout<< "Not a valid Anagram\n";
                return false;
            }
            count[index]--;
        }
        cout<< "Valid Anagram\n";
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

/*   // cstring functions
    char str1[100] = "xbox";
    char str2[100] = "mango";
    cout<< strcmp(str1, str2)<< endl;
*/

    //STRINGS
/*   // Basics
    string str = "hello";
    cout<< str<< endl;
    str = "sekhar";
    cout<< str<< endl;

    cout<< "Enter: ";
    string str2;
    //cin>> str2;
    getline(cin, str2);
    cout << str2<< endl;
    cout<< str2[0]<< endl;
    cout<< str2[1]<< endl;
    cout<< str2[2]<< endl;
*/

/*   // Member Functions
    string str = "Hello, I am Subhranshu Sekhar Swain.";
    cout<< str.length() << endl;
    cout<< str.at(1) << endl;
    cout<< str.substr(12, 10) << endl;
    cout<< str.find("Sekhar") << endl;
*/

    // Valid Anagram-->
    string str1 = "anagram";
    string str2 = "nagaram";
    isAnagram(str1, str2);

    return 0;
}