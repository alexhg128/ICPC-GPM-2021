#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

double heron(int a, int b, int c) {
    double s = ((double) (a + b + c)) / 2.0;
    double area = s * (s - a) * (s - b) * (s - c);
    return sqrt(area);
}

int knapsack(int needed_weight, int items, vector<int> values, vector<int> weights, int max_weight) {
    vector<int> dp = vector<int>(needed_weight + max_weight + 1, INT_MAX);
    dp[0] = 0;
    int m = INT_MAX;
    for(int i = 0; i < needed_weight + max_weight + 1; i++) {
        for(int j = 0; j < items; j++) {
            if (weights[j] <= i) {
                dp[i] = min(dp[i], dp[i - weights[j]]  + values[j]);
            }
        }
        if(i >= needed_weight) {
            if(dp[i] < m) {
                m = dp[i];
            }
        }
    }
    for(int i = 0; i < dp.size(); i++) {
        cout << dp[i] << endl;
    }            
    return m;
}

int main() {
    int b, n;
    cin >> b >> n;
    if(n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> weights = vector<int>();
    vector<int> prices = vector<int>();
    int m = -1;
    bool nonempty = false;
    
    for(int i = 0; i < b; i++) {
        int wi, pi;
        cin >> wi >> pi;
        weights.push_back(wi);
        prices.push_back(pi);
        if(wi != 0) {
            nonempty = true;
        }
        if(wi > m) {
            m = wi;
        }
    }

    if(nonempty == false) {
        cout << -1 << endl;
        return 0;
    }

    double area = 0;
    
    for(long long i = 0; i < n; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        area += heron(a, b, c);
    }

    long long kg = ceil(area / 30);
    cout << kg << endl;
    cout << knapsack(kg, weights.size(), prices, weights, m) << endl;
    return 0;
}