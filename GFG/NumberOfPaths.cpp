//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends

class Solution {
public:
    int numberOfPaths(int rows, int columns) {
        long long numPaths = 1;
        
        const int MOD = 1000000007;
        
        for (int i = 0; i < rows - 1; i++) {
            numPaths = (numPaths * (i + columns)) % MOD;
            
            long long temp = modInverse(i + 1, MOD);
            numPaths = (numPaths * temp) % MOD;
        }
        
        return numPaths;
    }

private:
    long long modInverse(long long a, long long m) {
        long long m0 = m;
        long long x0 = 0;
        long long x1 = 1;
        
        if (m == 1)
            return 0;
        
        while (a > 1) {
            long long q = a / m;
            long long t = m;
            
            m = a % m;
            a = t;
            t = x0;
            
            x0 = x1 - q * x0;
            x1 = t;
        }
        
        if (x1 < 0)
            x1 += m0;
        
        return x1;
    }
};


//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N, M;
		cin>>M>>N;
		Solution ob;
	    cout << ob.numberOfPaths(M, N)<<endl;
	}
    return 0;
}
// } Driver Code Ends
