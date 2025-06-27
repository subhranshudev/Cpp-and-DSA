#include<iostream>
#include<string.h> // or <cstring>
using namespace std;

int main(){
/*  // Basics 
    char word[] = { 'c', 'o', 'd', 'e', '\0'};
    cout<< word << endl; // It will directly print all the elements of char array, No loops required
    cout<< strlen(word)<< endl;
    char word2[] = "hello";
    cout<< word2 << endl;
    cout<< strlen(word2)<< endl;
*/

    // Taking inputs
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

    return 0;
}