#include<iostream>
using namespace std;

void oddOreven(int num){
    if (!(num & 1))
    {
        cout<<"Even\n";
    } else{
        cout<<"Odd\n";
    }
}

int getIthBit(int num, int i){
    int bitmask = 1 << i;

    if (!(num & bitmask))
    {
        cout<< "0\n";
        return 0;
    } else{
        cout<< "1\n";
        return 1;
    }    
}

int setIthBit(int num, int i){
    int bitmask = 1<<i;
    return (num | bitmask);
}

int clearIthBit(int num, int i){
    int bitmask = ~(1<<i);
    num = num & bitmask;
    return num;
}

bool isPowerOf2(int num){
    if (!(num & (num-1)))
    {
        return true;
    }else{
        return false;
    }  
}

int updateIthBit(int num, int i, int value){
    num = num & (~(1<<i)); // clear
    int bitmask = value<<i;
    num = num | bitmask; // set with value
    return num;
}

int clearIBits(int num, int i){
    int bitMask = ~0 << i;
    num = num & bitMask;
    return num;
}

int countSetBits(int num){
    int count = 0;
    while(num > 0){
        int lastDigit = num & 1;
        count = count + lastDigit;
        num = num>>1;
    }
    return count;
}



int main(){
/*    // Bitwise Operators
    cout<< (3 & 5)<< endl; 
    cout<< (3 | 5)<< endl;
    cout<< (3 ^ 5)<< endl;
*/

/*    // One's Complement
    cout << (~6)<< endl;
    cout << (~0)<< endl;
*/

/*    // Binary Shift Operator
    cout<< (7 << 2)<< endl;
    cout<< (7 >> 2)<< endl;
*/
    
    // // Question
    // cout << (~4)<< endl;
    // cout<< (8 >> 1)<< endl;

/*    // Check odd or even
    oddOreven(5);
    oddOreven(8);
*/

/*    // get ith bit
    getIthBit(6, 2);
    getIthBit(5, 1);
*/

    // set ith bit
   //cout<< setIthBit(6, 3)<< endl;

   // Clear ith bit 
   //cout<< clearIthBit(6, 1)<< endl;

/*   // Check Power of 2 or not
   cout<< isPowerOf2(15) << endl;
   cout<< isPowerOf2(8) << endl;
*/

/*   // Update with given value
    cout<< updateIthBit(7, 2, 0)<< endl;
    cout<< updateIthBit(7, 3, 1)<< endl;
*/

    // Clear last i bits
   // cout<< clearIBits(15, 2)<< endl;

/*    // count setBits
    cout<< countSetBits(10)<< endl;
    cout<< countSetBits(7)<< endl;
*/



    return 0;
}