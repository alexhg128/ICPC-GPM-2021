#include <iostream>
#include <vector>

int main() {
    std::vector<int> sieve = std::vector<int>(1000002);
    std::vector<int> acum = std::vector<int>(1000002, 0);
    int n = 1000001;
    for (int x = 2; x <= n; x++) {
        if (sieve[x]) continue;
        for (int u = 2*x; u <= n; u += x) {
           sieve[u] = x;
        }
    }
    for(int i = 2; i < sieve.size(); i++) {
        if(sieve[i] == 0) {
            acum[i] = acum[i - 1] + 1;
        } else {
            acum[i] = acum[i - 1];
        }
    }

    int t;
    std::cin >> t;
    for(int x = 0; x < t; x++) {
        int i, j;
        std::cin >> i;
        std::cin >> j;
        if( i == 0 ) i = 1;
        std::cout << acum[j] - acum[i - 1] << std::endl;
    }
}