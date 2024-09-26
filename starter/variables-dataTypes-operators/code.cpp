#include <iostream>
using namespace std;

int main()
{
    // Normal Printing -------:
    // cout << "Hello World" << '/n';
    // cout << "Hello World" << endl;
    // cout << "Hello World\n from Omkar";

    // Primitive DataTypes -------:
    //  int age = 22;
    //  char grade = 'A';
    //  float PI = 3.14f;
    //  bool isSafe = true;
    //  double price = 33.33;
    //  cout << isSafe << endl;

    // Type Conversion [implicit] -------:
    // char grade = 'a';
    // int value = grade;
    // cout << value << endl; // NOte it will result ASCII value as discussed

    // Type Casting [explicit] -------:
    // double price = 100.99;
    // int newPrice = (int)price;
    // cout << newPrice << endl;

    // CIN
    // double age;
    // cout << "Enter your age: ";
    // cin >> age;

    // cout << "Your age is: " << age << endl;

    // Operators
    // int a = 12, b = 5; // can define value in one line also
    // int sum = a + b;
    // int difference = a - b;
    // int product = a * b;
    // int quotient = a / b; // int / int will result value without roundoff and decimal
    // // sp  int / float or double/int will give decimal because preference to bigger datatype.
    // // cout << 15 / (double)5 << endl; Here Type Casting can help/
    // int modulo = a % b;

    // cout << quotient << endl;

    // int a, b;
    // cout << "Enter first number: ";
    // cin >> a;
    // cout << "Enter sencond number: ";
    // cin >> b;

    int a = 10;
    int b = a++; // So here value of a will go to b first, then a will increment
    cout << "b: " << b << endl;
    cout << "a: " << a << endl;
    return 0;
}

// First stage is compile: g++ code.cpp
// Second stage is run: ./a.exe

// If can run both at once using && between but not supported in powershell , use cmd

// single int variable take 4 bytes of storage in memory,
// Generally 8 bite = 1 byte so it takes 8 * 4 i.e. 32 byte

// single char variable take 1 byte of storage in memory,
// char is stored as ASCII value (American standard code of Information Interchange)
// A = 65, B= 66, C=.... this value is saved as binary in memory. Similarly: a= 97 , b= 98 , c= ...

// single float variable take 4 bytes of storage in memory,
// At end of value we write f so it will consider float

// single bool variable take 1 byte of storage in memory,
// it will show 1 as true and 0 as false

// single 'double' variable take 8 bytes i.e. double the value of float of storage in memory,
// so no need to add suffix after value as it defaults take double type

//[implicit] conversion mean it converts automatically but for small -> big.  eg: float --> double viz 4bytes --> 8bytes
// type casting is [explicit] : it does not convert auto because used as big -> eg:  double --> float so have to do manually and assign to lower or similar type

// Binary Operators : Bi means 2 so it takes 2 values to operates eg: [+, -, *, /]
// Unary Operators: only one value is ok. eg: a+1 can be a++ & a-- [Increment & Decrement Unary Operator respectively]

// Difference in a++ & ++a
// a++ first work, then update;
//++a first update, then work;