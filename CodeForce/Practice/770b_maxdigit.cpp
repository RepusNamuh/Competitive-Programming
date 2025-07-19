#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>


int sumDigit(long long x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;  // Add last digit to sum
        x /= 10;        // Remove last digit
    }
    return sum;
}

long long intpow(int base, int exp) {
    long long result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}
int main() {
    long long x, test, n, highest = 0;
    std::cin >> x;
    std::vector<long long> nums;
    
    n = floor(log10(abs(x))) + 1; // Calculate number of digits
    int xdigit = (x / static_cast<long long>(intpow(10, n - 1))) % 10;
    
    if (x % static_cast<long long>(intpow(10, n - 1)) == 0) {
        test = x / 10 != 0 ? x - 1 : x;
        if (test != 0) {
            std::cout << test << std::endl;
            return 0;
        }
    } else {
        test = ((xdigit + 1) * intpow(10, n - 1) - 1);
    }

    for (int i = 1; i < n; i++) {
        long long xprefix = x / static_cast<long long>(intpow(10, n - i - 1)); // Get prefix of x
        long long testprefix = test / static_cast<long long>(intpow(10, n - i - 1)); // Get prefix of test

        long long digit = xprefix / 10; // Get first digit
        long long testdigit = testprefix / 10; // Get first digit of test
        long long sumtemp;

        long long temp;

        if (testprefix > xprefix && digit == testdigit) {
            temp = test -  intpow(10, n - i);
        } else if (testprefix > xprefix && testdigit > digit) {
            temp = test - (testprefix - xprefix - 1) * intpow(10, n - i - 1);
        }

        digit = sumDigit(x);
        testdigit = sumDigit(test);
        sumtemp = sumDigit(temp);
        if (test < x){
            if (sumtemp > digit && sumtemp > testdigit) {
                test = temp;
            }
        } else if (sumtemp > digit && temp < test) {
            test = temp;
        }
    }
    
    nums.push_back(test);
    nums.push_back((xdigit) * intpow(10, n - 1) - 1);
    nums.push_back(x);
    for (const auto& num: nums) {
        int currsum = sumDigit(highest);
        int newsum = sumDigit(num);
        if (num > x){
            continue;
        }
        if ((newsum > currsum)
            || (newsum == currsum && num > highest)) {
            highest = num;
        }
    }

    std::cout << highest << std::endl;
    return 0;
} 