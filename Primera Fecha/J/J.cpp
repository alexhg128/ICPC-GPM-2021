#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
int modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;
 
    if (m == 1)
        return 0;
 
    while (a > 1) {
        int q = a / m;
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
 
    if (x < 0)
        x += m0;
 
    return x;
}

int main() {
    int N;
    cin >> N;

    unordered_set<int> s = unordered_set<int>();
    vector<vector<int> > vs = vector<vector<int> >();
    vector<int> sum = vector<int>();
    for(int i = 0; i < N; i++) {
        s.insert(i);
        vs.push_back(vector<int>());
        sum.push_back(-1);
    }
    vector<int> v = vector<int>();
    v.push_back(-1);

    for(int i = 0; i < N-1; i++) {
        int M;
        cin >> M;
        if(s.find(M - 1) != s.end()) {
            s.erase(M - 1);
        }
        vs[M - 1].push_back(i + 1);
        v.push_back(M - 1);
    }

    queue<int> q = queue<int>();
    long long Total = 0;

    for(int leaf: s) {
        sum[leaf] = 1;
        q.push(leaf);
    }

    while(!q.empty()) {
        int current = q.front();
        q.pop();

        Total += sum[current];

        if(v[current] != -1 && sum[v[current]] == -1) {
            q.push(v[current]);
            sum[v[current]] = sum[current] + 1;
        }

        for(int child: vs[current]) {
            if(sum[child] == -1) {
                q.push(child);
                sum[child] = sum[current] + 1;
            }
        }
    }

    long long inv = modInverse(N, 998244353);
    cout << (Total * inv) % 998244353 << endl;

}