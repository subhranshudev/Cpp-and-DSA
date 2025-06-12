#include<iostream>
using namespace std;

void changeA(int a){
    a = 20;
    cout<< "changeA: "<< a<< "\n";
}

void changeB(int *ptr){
    *ptr = 20;
    cout<< "changeB: "<< *ptr<< "\n";
}

void changeC(int &param) {
    param = 20;
    cout<< "changeC: "<< param<< "\n";
}

int main() {
 /*   // // Address of operator
    // int a =10;
    // cout<< "Address: "<< &a<< "\n";

    // //Pointer
    // int *ptr = &a;
    // cout<< "Value in pointer = "<< ptr<< "\n";

    // //Deference Operator 
    // int b = 20;
    // int *ptr2 = &b;
    // cout<< ptr2 << "\n"; // Gives the address of variable (Here b)
    // cout<< *ptr2<< "\n"; // Gives the value of variable whose address is stored in that pointer( Here 20, i.e value of b )

    // *ptr2 = 30; // value updation of b
    // cout<< "b = " << b<< "\n";

    // NULL Pointer
    int *ptr3 = NULL;
    //cout<< "ptr3 = "<< ptr3<< "\n";
   // cout<< *ptr3; // Dereferencing is not possible

   // Passing Arguments
   int a = 10;
   changeA(a); // pass by value
   cout<<"main: " << a << "\n";
     
   int b = 10;
   changeB(&b); //pass by reference (using pointer)
   cout<< "main: "<< b<< "\n";

   int c = 15;
   changeC(c); // pass by reference (using Reference Variable)
   cout<< "main: "<< c<< "\n";

   // Question 1
//    int x= 5, y= 10;
//    int *ptr1 = &x, *ptr2 = &y;
//    cout<< "&x = "<< &x<< "\n";
//    cout<< "&y = "<< &y<< "\n";
//    cout<< "ptr1 = "<< ptr1<< "\n";
//    cout<< "ptr2 = "<< ptr2<< "\n";
//    ptr2 = ptr1;
//    cout<< "ptr1 = "<< ptr1<< "\n";
//    cout<< "ptr2 = "<< ptr2<< "\n";
    
   // Q2
   //float* a, b;
   //Q3
   int *pointer = 0;
   cout<< "Pointer: "<< pointer<< "\n";
*/
   // Assignment
   // Q3
   int a = 32;
   int *ptr = &a;
   cout<< ptr << "\n";
   char ch = 'A';
   char &cho = ch;
   cout<< cho << "\n";

   cho += a; //a
   *ptr += ch; // 129

   cout<< a << " , "<< ch << endl;


    return 0;
}