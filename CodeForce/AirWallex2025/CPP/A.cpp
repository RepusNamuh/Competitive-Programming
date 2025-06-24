#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    dp[0] = x;
    
    for (int i = 0; i <= k; i++){
        for (int a = 0; a < n; ++a){
            newdp[a] = dp[a];
        }
    
        for (int j = 0; j < m; ++j){
            auto [from: int, to:int, r: long double, f: long double] = exch[j];
    
            long double next = dp[from] * r - f;
            if (next > 0 && next > newdp[to]){
                newdp[to] = next;
            }
        }
    
        for (int a = 0; a < n; ++a){
            dp[a] = newdp[a];
        }
    }
    
    cout << std::fixed << setprecision(n:5) << dp[0];
    
    return 0;
    }