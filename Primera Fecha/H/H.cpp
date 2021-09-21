#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

int main() {
    int B;
    cin >> B;

    string seq = "";
    cin >> seq;
    int seq_size = seq.size();
    int min = seq_size;
    if(B == 0) {
        cout << 0 << endl;
    } else if(B == 1) {
        cout << seq.length() << endl;
    } else {
        for(int i = 2; i <= B; i++) {
            unordered_map<string, pair<int, int> > m = unordered_map<string, pair<int, int> >();
            for(int j = 0; j < seq_size; j++) {
                if(j + i <= seq_size) {
                    string x = seq.substr(j, i);
                    if(m.find(x) != m.end()) {
                        if(m[x].second + i <= j) {
                            m[x].first += 1;
                            m[x].second = j;
                        }
                    } else {
                        m.insert(make_pair(x, make_pair(1, j)));
                    }
                }
            }

            int max = 0;
            for(pair<string, pair<int, int> > x: m) {
                if(x.second.first > max) {
                    max = x.second.first;
                }
            }

            int calc = seq_size - (i * max) + max;
            if(calc < min) {
                min = calc;
            }

       }
       cout << min << endl;
   }
}