#include <iostream>
using namespace std;

int main(){
    int a = 10;
    float f = 12.99;
    int* ptr = &a;
    int** parPtr = &ptr;

    int *ppt = NULL;

    // cout << &a  << " " << **(&ptr) << endl;
    // cout << &a  << " " << *(ptr) << endl;
    cout << ppt << endl;
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
//Generally if a fuction needs a parameter and call it we pass the parameter and it is passed by reference, i.e its copy is stored
//But if we pass the address of the parameter [variable] by passing pointer of 'a' or memory address of 'a' i.e. &a