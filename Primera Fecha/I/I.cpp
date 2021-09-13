#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, k, t;
    cin >> n >> k >> t;
    vector<long long> cities = vector<long long>();
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        cities.push_back(temp);
    }

    if(n == 1) {
        cout << -1 << endl;
        return 0;
    }

    long long T = 0;
    long long I = 0;
    long long J = 0;
    long long TLO = LONG_MAX;

    for(int i = 0; i < cities.size(); i++) {
        T += (cities[n - 1] - cities[i]);
    }

    for(int i = 0; i < cities.size() - 1; i++) {
        long long C = (i + 1) * t;
        long long L = cities[i] + k;

        vector<long long>::iterator low = lower_bound(cities.begin(), cities.end(), L);
        long long pos = low - cities.begin();
        int j = 0;
        if(pos ==  cities.size()) {
            j = cities.size() - 1;
        } else if(cities[pos] == L) {
            j = pos;
        } else  {
            j = pos - 1;
        }

        long long D = (cities[j] - cities[i]) * (i + 1);
        long long TLOC = T - D + C;
        if(TLOC < TLO) {
            TLO = TLOC;
            I = i;
            J = j;
        }
    }

    if(TLO < T) {
        cout << I + 1 << " " << J +  1 << " " << TLO << endl;
    } else {
        cout << -1 << endl;
    }
}