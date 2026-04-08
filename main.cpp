#include <iostream>
#include <cstdint>

using namespace std;

// Function to check if a given number n is a perfect number
bool is_perfect(uint64_t n) {
    // 1 and 0 are not perfect numbers
    if (n <= 1) return false;
    
    uint64_t sum = 1; // 1 is always a proper divisor
    
    // Iterate up to the square root of n to find all divisors
    for (uint64_t i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            sum += i;
            // If i is not the square root of n, add the corresponding divisor
            if (i * i != n) {
                sum += n / i;
            }
        }
    }
    
    // A perfect number is equal to the sum of its proper divisors
    return sum == n;
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m;
    if (!(cin >> m)) return 0;
    
    for (int i = 0; i < m; ++i) {
        uint64_t n;
        cin >> n;
        if (is_perfect(n)) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    
    return 0;
}