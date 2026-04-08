#include <iostream>
#include <cstdint>

using namespace std;

bool is_perfect(uint64_t n) {
    if (n <= 1) return false;
    uint64_t sum = 1;
    for (uint64_t i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            sum += i;
            if (i * i != n) {
                sum += n / i;
            }
        }
    }
    return sum == n;
}

int main() {
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

