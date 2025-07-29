/*
ID: shiaust1
LANG: C++
TASK: ride
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin ("ride.in");

    string n, m;
    cin >> n >> m;

    int n_product=1;
    int m_product=1;

    for(int i=0; i<n.length(); i++) {
        n_product *= (n[i]-64);
    }

    for(int i=0; i<m.length(); i++) {
        m_product *= (m[i]-64);
    }

    if(n_product%47==m_product%47) {
        ofstream("ride.out") << "GO" << endl;
    } else {
        ofstream("ride.out") << "STAY" << endl;
    }
}