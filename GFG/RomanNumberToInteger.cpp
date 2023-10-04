//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        unordered_map<char, int> u;
        u['I'] = 1;
        u['V'] = 5;
        u['X'] = 10;
        u['L'] = 50;
        u['C'] = 100;
        u['D'] = 500;
        u['M'] = 1000;
        
        int ans = u[str[0]];
        
        for(int i=1; i<str.length(); i++){
            if(u[str[i-1]] < u[str[i]])
            {
                ans -= 2 * u[str[i-1]];
            }

            ans += u[str[i]];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends
