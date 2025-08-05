#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t, n;
    
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        std::vector<long long> prefixArray(n);
        std::vector<long long> suffixArray(n);
        bool isValid = true;

        for (int i = 0; i < n; ++i) {
            long long temp;
            std::cin >> temp;
            prefixArray[i] = temp;
            if (i > 0 && prefixArray[i - 1] % temp !=0) {
                isValid = false;
            }
        }

        for (int i = 0; i < n; ++i) {
            long long temp;
            std ::cin >> temp;
            suffixArray[i] = temp;
            if (i > 0 && temp % suffixArray[i - 1] != 0) {
                isValid = false;
            }
        }

        if (prefixArray[n - 1] != suffixArray[0]) {
           isValid = false;
        }
        std::vector<long long> A(n);
        for (int i = 0; i < n; ++i) {
            A[i] = std::lcm<long long>(prefixArray[i], suffixArray[i]);
        }

        long long x = 0, y = 0;
        for (int i = 0; i < n; ++i) {
            x = std::gcd(x, A[i]);
            y = std::gcd(y, A[n - 1 - i]);
            if (x != prefixArray[i] || y != suffixArray[n - 1 - i]) {
                isValid = false;
                break;
            }
        }

        std::cout << (isValid ? "YES" : "NO") << "\n";
    }
}