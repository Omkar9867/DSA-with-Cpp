#include <iostream>
using namespace std;

void changeA(int &ptr){
    ptr = 7;
}

int main(){
    // int a = 10;
    // float f = 12.99;
    // int* ptr = &a;
    // int** parPtr = &ptr;

    // int *ppt = NULL;
    // changeA(a);

    // int b = 10;
    // int *p = &b;
    // cout << p << endl;
    // p++;
    // cout << p << endl;

    int arr[] = {1,2,3,4,5};
    // int *ptr = arr;
    int ptr = *arr; //which will give first index ; // 1
    int ptr2 = *(arr+1); //which will give second index ; // 2

    int* ponter = arr;

    // cout << &a  << " " << **(&ptr) << endl;
    // cout << &a  << " " << *(ptr) << endl;
    cout << *ponter << endl;
    cout << *(ponter+1) << endl;
    cout << *ponter << endl; //Derefernce so it will output the value
    return 0;
}


//Note: & is special charater use in multiple places. similarly it is used to display the address of a specific variable
//Example usage = int a = 0; --> So address of a can be found as ---> cout << &a

//Pointers
//Special variables that store address of other variables
//To define it is  a pointer use '*' for a varaible and store other variable address for it eg: int* pointer = &a
//pointer variable itself will have its own address but it has the value as address of other variable.
//Note: Type of pointer variable sould be the same as the variable which its pointer is taking

//pointer to pointer
//This pointer will have 2 star so it can be assumed that the pointer is of another pointer.

// * ==> Dereferance operator ---> value at the address
//so to destructure the value from the pointer add * eg: *(&a) and for nester **(&ptr)

// Null Pointer --> pointer that is not point to valid address
// Can be written as : int* ptr = NULL; --> prints 0 viz memory address is null
//Used when --> LinkedList, Trees

//Pass By Reference
// 1st Method
//Generally if a fuction needs a parameter and call it we pass the parameter and it is passed by reference, i.e its copy is stored
//But if we pass the address of the parameter [variable] by passing pointer of 'a' or memory address of ' a' i.e. &a
// 2nd Method (alias)
//for eg: 'Tony Stark' or 'Iron Man' both are same person
//If we pass variable on another name in my function and while calling if we add our main variable it will be by refernce ,
//only while defining the func use '&' i.e. alias with the other arg name
//Example fun(&b) will be storing same address of a when func(a)


//Array Pointer
//Array itself is a pointer and called as constant pointer, so if tried to modifiy any value of arr with a variable it will give an error.

//Pointer Arithmetic
//.Increment -->
//when a++ then the value gets increment but the addreess adds additional 4 byte which it incremented
//eg: a=10 *p = &a == 100; when a++; then a=11, p=104
//.Decrement -->
//Similarly for decrement when a-- then the value gets decrement but the addreess subracts additional 4 byte which it decremented 
//eg: a=10 *p = &a == 100; when a--; then a=9, p=96

//Adding two pointers is not allowed, but subracting can be done with same type
//Also comparing two pointers '< > = '