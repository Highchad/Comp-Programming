#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
using namespace std;

void setIO(string name) {
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int main() {
    setIO("whereami");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    string sequence;
    cin >> n >> sequence;

    for (int sub_len = 1; sub_len <= n; sub_len++) {
		bool sol_found = true;
		unordered_map<string, int> sub_frequency;
		// store frequencies of all subs with given length (sub_len)
		for (int idx = 0; idx <= n - sub_len; idx++) {
			string sub = sequence.substr(idx, sub_len);
			sub_frequency[sub]++;
			if (sub_frequency[sub] > 1) { sol_found = false; }
		}

		// if all sub sequences are unique -> solution found
		if (sol_found) {
			cout << sub_len << endl;
			break;
		}
	}
}