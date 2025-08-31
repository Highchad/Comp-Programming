#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int max=INT32_MAX;
    int n;
    cin >> n;

    vector<int> weight(2*n);
    for(int &i : weight) { cin >> i; }

    sort(weight.begin(), weight.end());

    for (int i=0; i<2*n; i++) {
        for (int j=i+1; j<2*n; j++) {
            vector<int> s;
            for (int k=0; k<2*n; k++) {
                if (k != i && k != j) { s.push_back(weight[k]); }
            }

            int temp=0;
            for (int z=0; z<2*n-2; z+=2) {
                temp += s[z+1]-s[z];
            }
            max = min(max, temp);
        }
    }

    cout << max << endl;
}