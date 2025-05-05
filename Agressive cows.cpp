//https://www.geeksforgeeks.org/problems/aggressive-cows/1

//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    bool check(vector<int>& stalls, int k, int mid)
    {
        int last = stalls[0];
        k--;
        for(int i=1;i<stalls.size();i++)
        {
            if(k==0)
                return true;
            if((stalls[i]-last)>=mid)
            {
                last = stalls[i];
                k--;
            }
        }
        
        return k<=0;
    }
    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(),stalls.end());
        
        int mini = stalls[0];
        int maxi = stalls[stalls.size()-1];
        
        int low = 1;
        int high = (maxi-mini);
        int mid = (high+low)/2;
        
        while(low<=high)
        {
            mid = (high+low)/2;
            
            if(check(stalls,k,mid))
            {
                low = mid+1;
            }
            else
                high = mid-1;
        }
        
        return high;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
