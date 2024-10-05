#include <iostream>
using namespace std;

int main()
{
    // int num = -1;
    // if (num >= 0){
    //     cout << "Positive" << endl;
    // } else {
    //     cout << "Negative" << endl;
    // }
    // int age;
    // cout << "Enter your age: ";
    // cin >> age;
    // if(age >= 18){
    //     cout << "You can vote\n";
    // }else{
    //     cout << "You cannot vote\n";
    // }
    
    // char ch;
    // cout << "Enter a letter: ";
    // cin >> ch;

    // if(ch >= 65 && ch <= 90){   //This is called implicit type of conversion. char is converted into it's ASCII value and then compared.
    //     cout << "Upper-Case\n";
    // }else{
    //     cout << "Lower=Case\n";
    // }

    // ch >= 65 && ch<= 90 ? cout << "UpperCase\n" : cout << "LowerCase\n"; //Ternary Operator
    // cout << (ch >= 65 && ch<= 90 ? "UpperCase\n": "LowerCase");

    //LOOP
    // int count = 1; //initialization
    // while(count <= 10){ //conditon
    //     cout << count << " ";
    //     count++; //update
    // }

    // int n = 10;
    int sum = 0;

    // for(int i = 1; i<=n; i++) {
    //     if(i%2 != 0){
    //         sum += i;
    //     }
    //     // if(i == 5) break;
    // }
    // int i = 1;
    bool isPrime = true;
    // while(i <= n){
    //     if(i%2 != 0){
    //         sum += i;
    //     }
    //     i++;
    // }
    // do{
    //     if(i%2 != 0){
    //         sum+= i;
    //     }
    //     i++;
    // }while(i <= n);
    // for(int i = 2; i <=n-1; i++){
    //     if(n%i == 0){
    //         // cout << "It is not a Prime Number" << endl;
    //         isPrime = false;
    //         break;
    //     }
    //         // cout << "It is a Prime Number" << endl;
    //         // isPrime = true;
    //         //Since isPrime is defined first no need to write again correct?
    // }
    // cout << isPrime << endl;

    //Start pattern loop
    int l = 5;
    for(int i = 1; i<=l; i++){ //Line of stars
        int x = 10;
        for (int j = 1; j<= x; j++){ //In one line how many stars
            cout << "* ";
        }
    cout << endl;
    }  

    //HomeWork:
    //Sum of all numbers from 1 to N which is divisible by 3
    // int n = 20;
    // int sumNum = 0;
    // for(int i=1; i<=n; i++){
    //     if(i % 3 == 0){
    //         sumNum += i;
    //     }
    // }
    // cout << sumNum << endl;

    //Factorial of n
    int n = 4;
    int factorial = 1;
    for(int i=2; i<=n; i++){
        factorial *= i ;
    }
    cout << factorial << endl;
    cout << "Finish" << endl;
    return 0;
}


//Major difference:
//do()while() loop does the work and check the condition then.
//while() loop checks the condition first and does the work.