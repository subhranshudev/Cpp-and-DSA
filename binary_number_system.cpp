#include<iostream>
using namespace std;
 
void binToDec(int bin){
    int n = bin;
    int pow = 1;
    int dec = 0;
    while (n > 0)
    {
        int digit = n%10;
        dec = dec+(digit*pow);
        pow = pow*2;
        n = n/10;
    }
    cout<< "Decimal equivalent is = "<< dec ;
    
}

void decToBin(int dec) {
    int pow = 1;
    int bin = 0;
    while (dec > 0)
    {
       int remainder = dec%2;
       bin = bin + (remainder*pow);
       pow = pow*10;
       dec = dec/2;
    }
    cout<< "Binary equivalent = "<< bin;
}


int main() {
    // Binary to decimal conversion
    // int binNum = 1011;
    // binToDec(binNum);

    // Decimal to binary
    // int decNum = 7;
    // decToBin(decNum);

    // Assignments --> binary to decimal and decimal to binary conversion(done in class), binary addition 

    // Practice Session 6


    return 0;
}