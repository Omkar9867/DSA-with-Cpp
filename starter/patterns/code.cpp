#include <iostream>
using namespace std;

int main(){
    // //Number Pattern
    // int n=7;
    // for(int i=1; i<=n; i++){//Lines
    //     for(int j=1; j<=n; j++){//Every single line
    //         cout << j;
    //     }
    //     cout << endl;
    // }

    // //Normal star pattern
    // int n=4;
    // for(int i=0; i<n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // //Character pattern
    // int n = 7;
    // for(int i=0; i<n; i++){
    //     char ch = 'A';
    //     for(int j=0; j<n; j++){
    //         cout << ch << " ";
    //         ch = ch+1; //ASCII value is being converted: A --> 65+1 => 66 --> B
    //     }
    //     cout << endl;
    // }

    // //Increase number print
    // int n = 3;
    // int num = 1;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << num << " ";
    //         num++;
    //     }
    //     cout << endl;
    // }

    // //Increase character print
    // int n = 6;
    // char ch = 'A';
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << ch << " "; //ASCII value is being converted: A --> 65+1 => 66 --> B
    //         ch += 1;
    //     }
    //     cout << endl;
    // }

    // //Triangle Pattern
    // int n=4;
    // for(int i=0; i<n; i++){//Line
    //     for(int j=0; j<i+1; j++){// Resson is:Each line pattern will print how much? if 1, then when i=0 : +1 and so on. Example (j<i+1) here if i=2 then 2+1=3, so loop will run 3 times
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // //Triangle Number but with same number on each line
    // int n = 4;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<i+1; j++){
    //         cout << (i+1);
    //     }
    //     cout << endl;
    // }

    // //Triangle Character but with same charater on each line
    // int n=4;
    // char ch = 'A';
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<i+1; j++){
    //         cout << ch << " ";
    //     }
    //     cout << endl;
    //     ch++;
    // }

    // //Triangle with diff num starts from 1
    // int n = 4;
    // for(int i=0; i<n; i++){
    //     for(int j=1; j<=i+1; j++){ //OR  for(int j=0; j<i+1; j++)
    //         cout << j;             //OR      cout << j+1
    //     }
    //     cout << endl;
    // }

    //Triangle with diff num but reverse
    // int n = 4;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<i+1; j++){   //----> This is my logic actual logic is after this
    //         cout << i-j+1;
    //     }
    //     cout << endl;
    // }
    // int n = 4;
    // for(int i=0; i<n; i++){
    //     for(int j=i+1; j>0; j--){   //---->Actual logic using backward loop: //Reverse logic first was 0 to i+1 , now is i+1 to 0
    //         cout << j;
    //     }
    //     cout << endl;
    // }
    
    // //Character triangle reverse
    // int n = 4;
    // for(int i=0; i<n; i++){
    //     char ch = 'A'+i;   //New logic for reverse characters
    //     for(int j=i+1; j>0; j--){     //---->Actual logic using backward loop: //Reverse logic first was 0 to i+1 , now is i+1 to 0
    //         cout << ch << " ";
    //         ch --;
    //     }
    //     cout << endl;
    // }


    // //Floyd's Triangle Pattern
    // int n = 4;
    // int num = 1;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<i+1; j++){ //Even in backwards will result the same [int j=i+1; j>0; j--]
    //         cout << num << " ";
    //         num ++;
    //     }
    //     cout << endl;
    // }

    // //=> Inverted Triangle number Pattern
    // int n=4;
    // for(int i=0; i<n; i++){ //Lines 
    //     for(int j=0; j<i; j++){
    //         cout << " ";           //Logic to print space first , and space is according to i
    //     }
    //     for(int k=0; k<n-i; k++){
    //         cout << i+1;           //Logic to print star according to i-n
    //     }
    //     cout << endl;
    // }

    // //Pyramid Pattern number pattern
    // //    1|          
    // //   12|1
    // //  123|21        ==> Logic here is to separate the pyramid into 2 separate triangle where first spaces then number again some number
    // // 1234|321
    // int n=7;
    // for(int i=0; i<n; i++){ //Lines 
    //     for(int j=0; j<n-i-1; j++){ //spaces where n-i = 4 but want 3 so n-i-1
    //         cout << " ";
    //     }
    //     for(int k=1; k<=i+1; k++){ //1st set of numbers
    //         cout << k;            //print k because increasing and start by one as seen in diagram
    //     }
    //     for(int l=i; l>0; l--){ //here will run i times but have to reverse the numbers
    //         cout << l;
    //     }
    //     cout << endl;
    // }

    //Hollow diamond pattern
//        *
//      *   *
//     *     *
//    *       *
//   ------------  //Logic here is to split the diamond into 2 separate parts but in horizontal direction
//     *     *
//      *   *
//        *  
    int n=4;
    for(int i=0; i<n; i++){//lins of first part
        for(int j=0; j<n-i-1; j++){//spaces first part first space
            cout << " ";
        }
        cout << "*";  //first star after space
        if(i != 0){
            for(int k=0; k<2*i-1; k++){  //second spaces  ==> Logic here is that spaces in middle is odd order so running loop evenly
                cout << " ";
            } 
        cout << "*";  //second star after space
        }
        cout << endl;
    }
    //Now the second part
    for(int i=0; i<n-1; i++){ //Lines logic for second part
        for(int j=0; j<i+1; j++){ //spaces second part first space
            cout << " ";    
        }
        cout << "*";//first star after space
        if(i != n-2){ //Since 3 lines
            // for(int k=0; k<2*(n-2-i)-1; k++){ //second spaces second star ==> logic here is second spaces i.e. in middle is in odd number but in reverse: Since i is when increasing spaces are decreasing, so negative(i) 
            for(int k=0; k<2*(n-i)-5; k++){  // 2*(n-2-i) ==> 2n-4-2i-1 ==> 2(n-i)-5
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}


// For diamond sum
// i=0 , n=4

// odd number is 2* __ -1

// 2* what will give me 3 when i = 0// so i=0 then spaces 3, so can we say 2*2-1 will give me 3
//                                        i=1 then spaces 2, so            2*2-1 -1 will give me 2

// 2*(n-2-i)-1 because n-i is reverse