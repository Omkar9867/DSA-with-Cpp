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

    int n = 10;
    int sum = 0;

    for(int i = 1; i<=n; i++) {
        sum += i;
        if(i == 5) break;
    }
    cout << sum << endl;

    cout << "Finish" << endl;
    return 0;
}
