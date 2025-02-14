// #include<stack>

// bool findRedundantBrackets(string &s)
// {
//     stack<char> st;
//     for(int i=0; i<s.length(); i++) {
//         char ch =s[i];
        
//         if(ch == '(' || ch == '+' ||ch == '-' || ch == '*' || ch == '/') {
//             st.push(ch);
//         }
//         else
//         {
//             //ch ya toh ')' hai or lowercase letter
            
//             if(ch == ')') {
//                 bool isRedundant = true;
                
//                 while(st.top() != '(') {
//                     char top = st.top();
//                     if(top == '+' ||top == '-' || top == '*' || top == '/') {
//                         isRedundant = false;
//                     }
//                     st.pop();
//                 }
                
//                 if(isRedundant == true)
//                     return true;
//                 st.pop();
//             }
            
//         } 
//     }
//     return false;
// }

#include <stack>
#include <string>
using namespace std;

bool findRedundantBrackets(const string &s) {
    stack<char> st;

    for (char ch : s) {
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        } else if (ch == ')') {
            bool hasOperator = false;

            while (!st.empty() && st.top() != '(') {
                if (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/') {
                    hasOperator = true;
                }
                st.pop();
            }

            if (!st.empty()) st.pop(); // Pop '('

            if (!hasOperator) return true; // Redundant brackets found
        }
    }
    return false;
}
