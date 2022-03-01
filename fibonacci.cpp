#include<iostream>
using namespace std;

// Simple Recursive solution

int fib(int n){
    // base case
    if(n == 0 or n == 1){
        return n;
    }
    //recursive case
    return fib(n-1) + fib(n-2);

}

// Top Down DP

int fibDp(int n, int dp[]){
    if(n == 0 or n == 1){
        return n;
    }
    // check if the state is already computed
    if(dp[n] != 0){
        return dp[n];
    }
    // otherwise compute it and store it
    return dp[n] = fibDp(n-1, dp) + fibDp(n-2, dp);
}



//  Buttom Up DP (Iterative Approach)

int fib2(int n){
    int dp[1000001] = {0};
    // base case => assignment
    dp[0] = 0;
    dp[1] = 1;

    // bottom up dp
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-2] + dp[i-1];
    }
    return dp[n];
}

 





int main () {
    // int arr[1001];
    // arr[0] = 0;
    // arr[1] = 1;
    // for(int i = 2; i < 1001; i++){
    //     arr[i] = 0;
    // }

    // fibDp(100, arr);

    // cout << arr[10] << endl;

    cout << fib2(5) << endl;
     
    return 0;
}