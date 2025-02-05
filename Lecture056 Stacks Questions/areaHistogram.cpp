
#include <vector>
#include <stack>
#include <climits>
using namespace std;

class Solution {
private:
    // Function to find the next smaller element's index for each element
    vector<int> nextSmallerElement(const vector<int>& arr, int n) {
        stack<int> s;
        vector<int> ans(n, n);  // Initialize with 'n' assuming no smaller element to the right

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                ans[i] = s.top();
            }
            s.push(i);
        }
        return ans;
    }

    // Function to find the previous smaller element's index for each element
    vector<int> prevSmallerElement(const vector<int>& arr, int n) {
        stack<int> s;
        vector<int> ans(n, -1);  // Initialize with '-1' assuming no smaller element to the left

        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                ans[i] = s.top();
            }
            s.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        // Get next and previous smaller elements' indices
        vector<int> next = nextSmallerElement(heights, n);
        vector<int> prev = prevSmallerElement(heights, n);

        int maxArea = 0;

        // Calculate area for each histogram bar
        for (int i = 0; i < n; i++) {
            int height = heights[i];
            int width = next[i] - prev[i] - 1;  // Calculate width of the rectangle
            int area = height * width;
            maxArea = max(maxArea, area);  // Update max area
        }

        return maxArea;
    }
};
// class Solution {
// private:
//     vector<int> nextSmallerElement(vector<int> arr, int n) {
//         stack<int> s;
//         s.push(-1);
//         vector<int> ans(n);

//         for(int i=n-1; i>=0 ; i--) {
//             int curr = arr[i];
//             while(s.top() != -1 && arr[s.top()] >= curr)
//             {
//                 s.pop();
//             }
//             //ans is stack ka top
//             ans[i] = s.top();
//             s.push(i);
//         }
//         return ans;
//     }
    
//     vector<int> prevSmallerElement(vector<int> arr, int n) {
//         stack<int> s;
//         s.push(-1);
//         vector<int> ans(n);

//         for(int i=0; i<n; i++) {
//             int curr = arr[i];
//             while(s.top() != -1 && arr[s.top()] >= curr)
//             {
//                 s.pop();
//             }
//             //ans is stack ka top
//             ans[i] = s.top();
//             s.push(i);
//         }
//         return ans; 
//     }
    
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n= heights.size();
        
//         vector<int> next(n);
//         next = nextSmallerElement(heights, n);
            
//         vector<int> prev(n);
//         prev = prevSmallerElement(heights, n);
        
//         int area = INT_MIN;
//         for(int i=0; i<n; i++) {
//             int l = heights[i];
            
//             if(next[i] == -1) {
//                 next[i] = n;
//             }
//              int b = next[i] - prev[i] - 1;
//             int newArea = l*b;
//             area = max(area, newArea);
//         }
//         return area;
//     }
// };
