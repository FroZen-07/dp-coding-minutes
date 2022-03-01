#include<iostream>
#include<vector>
using namespace std;

// Approaches 
// 1 - Recursive
// 2 - Top Down
// 3 - Buttom Up 
// 4 - Buttom Up (Optimmised Recurrence)

// Recursive O(k^n)
int countWays(int n, int k){
    // base case
    if(n == 0){
        return 1;
    }
    // negative case
    if(n < 0){
        return 0;
    }
    // recursive case
    int ans = 0;
    for(int jump = 1; jump <= k; jump++){
        ans += countWays(n-jump, k);
    }
    return ans;
}


// topDown O(n*k)
int countWaysTD(int n, int k, int *dp){
    // base case
    if(n == 0){
        return 1;
    }
    // negative case
    if(n < 0){
        return 0;
    }
    // check wheather computed
    if(dp[n] != 0){
        return dp[n];
    }
    // recursive case
    int ans = 0;
    for(int jump = 1; jump <= k; jump++){
        ans += countWaysTD(n-jump, k, dp);
    }
    // store and return
    return dp[n] = ans;
}


// buttom up O(n*k)
int countWaysBU(int n, int k){
   // Iterative Approach
    vector<int> dp(n+1, 0);
    dp[0] = 1;

    for(int i = 1; i <=n;i++){
        for(int j = 1; j <= k; j++){
            if(i-j >= 0){
                dp[i] += dp[i-j];
            }
        }
    }
    
    return dp[n];
}


// buttom up Optimised O(n)
int countWaysOpt(int n, int k){
   // Iterative Approach
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;

    // break code into 2 parts
    // Less than or Equal to K
    for(int i = 2; i <= k; i++){
        // O(1)
        dp[i] = 2*dp[i-1];
    }

    // Part 2
    // More than K
    for(int i = k+1; i <= n; i++){
        dp[i] = 2*dp[i-1] - dp[i-k-1];
    }


    return dp[n];
}



int main () {
    int n, k;
    cin >> n >> k;
    int dp[1000] = {0};
    cout << "Recursive: " << countWays(n, k) << endl;
    cout << "Top Down: " << countWaysTD(n, k, dp) << endl;
    cout << "Bottom Up: " << countWaysBU(n, k) << endl;
    cout << "Optimised Bottom Up: " << countWaysOpt(n, k) << endl;
    return 0;
}