// #include<iostream>
// using namespace std;


// //1 -> Even
// // 0 -> odd
// bool isEven(int a) {
//     //odd
//     if(a&1) {
//         return 0;
//     }
//     else { //Even
//         return 1;
//     }

// }

// int main() {
    
//     int num;
//     cin >> num;

//     if(isEven(num)) {
//         cout <<" Number is Even" <<endl;
//     }
//     else {
//         cout<< " Number is Odd" <<endl;
//     }


//     return 0;
// }
#include <iostream>
using namespace std;

// Function to check even or odd
bool isEven(int a) {
    return !(a & 1);  // Returns true if even, false if odd
}

int main() {
    int num;
    
    cout << "Enter a number: "; // Prompt for user input
    cin >> num;

    if (isEven(num)) {
        cout << "Number is Even" << endl;
    } else {
        cout << "Number is Odd" << endl;
    }

    return 0;
}
