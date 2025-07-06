#include<iostream>
using namespace std;

class User{
    int id;
    string username;
    string password;
    string bio;

    void deactivate(){
        cout<< "Deleting account\n";
    }
    void editBio(string newbio){
        bio = newbio;
    }
};

class Student{
    string name;
    float cgpa;

public:     // Access Modifiers  
    void getPercentage(){
        cout<< (cgpa*10)<< "\n";
    }

    // Setters
    void setName(string nameVal){
        name = nameVal;
    }
    void setcgpa(float cgpaVal){
        cgpa = cgpaVal;
    }

    //Getters
    string getName(){
        return name;
    }
    float getCgpa(){
        return cgpa;
    }


};

class Car{
    string name;
    string color;

public:
    Car(){
        cout<< "Parameterized Constructor\n";
    }
    Car(string name, string color){
        cout<< "Nonparameterized Constructor\n";
        // name = nameVal;
        // color = colorVal;
        // or
        this->name = name;
        this->color = color;
    }
    void start(){
        cout<< "Car has started";
    }
    void stop(){
        cout<< "Car has stopped";
    }
    string getName(){
        return name;
    }
    string getColor(){
        return color;
    }
};

class Users{
private:
    int id;
    string password;

public:
    string username;

    Users(int id){
        this->id = id;
    }

    void setPassword(string password){
        this->password = password;
    }

    string getPassword(){
        return password;
    }
};

class Cars{
public:
    string name;
    string color;
    int *mileage;

    Cars(string name, string color){
        this->name = name;
        this->color = color;
        mileage = new int;
        *mileage = 12;
    }

    //custom copy constructor
    Cars(Cars &original){
        cout<< "Copying Original to new...\n";
        name = original.name;
        color = original.color;
        //mileage = original.mileage; // It cretes shallow copy
        mileage = new int;   //  These two lines create Deep copy
        *mileage = *original.mileage;  // A new address is created in previous line and the value of original object is copied
    }

    ~Cars(){        //--> Destructor is also invoked automatically when main function ends
        cout<< "Deleting Object...";
        if (mileage != NULL)
        {
            delete mileage; // Delete the location in Heap memory
            mileage = NULL; // As the heap memory location is deleted, the value of address of that location will be removed from
                            // variable mileage and some garbage value will be stored. Replace those garbage values with NULL
        }
        
    }

};

// Single Inheritance
class Animal{
public: 
    string color;

    void eat(){
        cout<< "Eats...\n";
    }
    void breathe(){
        cout<< "breathes...\n";
    }
};

class Fish : public Animal {
public:
    int fins;

    void Swim(){
        cout<< "Swims...\n";
    }
};

//Multilevel Inheritance
class Animals{
public:
    void eat(){
        cout<< "Eat\n";
    }

    void breathe(){
        cout<< "Breathe\n";
    }
};

class Mammal : public Animals{
public:
    string bloodType;

    Mammal(){
        bloodType = "warm";
    }
};

class Dog : public Mammal{
public:
    void tailWag(){
        cout<< "A dog wags its tail\n";
    }
};

//Multiple Inheritance
class Teacher{
public:
    int salary;
    string subject;
};

class Students{
public:
    int rollno;
    float cgpa;
};

class TA : public Teacher, public Students{
public:
    string name;
};

// Hierarchial Inheritance
class Animalss{
public:
    void breathe(){
        cout<< "Breathes\n";
    }
    void eat(){
        cout<< "Eat\n";
    }
};

class Birds : public Animalss{
public:
    void fly(){
        cout<<"Flies\n";
    }
};

class Fishes : public Animalss{
public:
    void swim(){
        cout<< "swims\n";
    }
};

int main(){
    //User u1; // object
    //cout<< sizeof(u1)<< endl;

/*    Student s1;
   s1.name = "Sekhar";      // We can acess these properties and methods if they are made public inside class
   s1.cgpa = 9.0;

   cout<< s1.name<< endl; 
   cout<< s1.cgpa<< endl;
   s1.getPercentage();
*/

/*    // Getters and Setters
    Student s1;
    s1.setName("Subhranshu");
    s1.setcgpa(9.27);

    cout<< s1.getName()<< endl;
    cout<< s1.getCgpa()<< endl;
*/

/*    // Constructor
    Car c0;
    Car c1("PORSCHE 911", "Off White");
    cout<< "Car name: "<< c1.getName()<< endl;
    cout<< "Color: "<< c1.getColor()<< endl;
*/

/*    //Q.
    Users user1(101);
    user1.username = "Subhranshu";
    user1.setPassword("sekhar123");

    cout<<"Username: " <<user1.username<< endl;
    cout<< "Password: "<<user1.getPassword()<< endl;
*/

/*    // Copy Constructor , Shallow copy and Deep copy
    Cars c1("PORSCHE 911", "Off White");

    Cars c2(c1);  // The Copy Constructor will copy all the properties of c1 to c2 while creating it
    cout<<"Name: " <<c2.name<< endl;
    cout<< "Color: "<< c2.color<<endl;
    cout<< "Mileage: "<< *c2.mileage<<endl;

    *c2.mileage = 10;
   cout<< "Mileage c1: "<< *c1.mileage<<endl;
*/

/*    // Destructor 
    Cars c1("PORSCHE 911", "Off White");
    cout<<"Name: " <<c1.name<< endl;
    cout<< "Color: "<< c1.color<<endl;
    cout<< "Mileage: "<< *c1.mileage<<endl;
*/

    // Inheritance 
/*    // Single Inheritance
    Fish f1;
    f1.fins = 3;
    cout<<"Fins: " <<f1.fins<< endl;
    f1.Swim();
    f1.breathe();
    f1.eat();
*/

/*   // Multilevel Inheritance
    Dog d1;

    d1.eat();
    d1.breathe();
    cout<<d1.bloodType << endl;
    d1.tailWag();
*/

/*    // Multiple Inheritance
    TA ta1;
    ta1.name = "Sekhar";
    ta1.subject = "C++";
    ta1.cgpa = 9.23;

    cout<< "Name: "<< ta1.name<< endl;
    cout<< "Subject: "<< ta1.subject<< endl;
    cout<< "cgpa: "<< ta1.cgpa<< endl;
*/

    // Hierarchial Inheritance
    Birds b1;
    b1.fly();
    b1.breathe();
    b1.eat();

    Fishes f0;
    f0.swim();
    f0.breathe();
    f0.eat();

     
    // Hybrid Inheritance

    return 0;
}