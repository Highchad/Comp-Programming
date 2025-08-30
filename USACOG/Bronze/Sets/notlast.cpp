#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#define ll long long
using namespace std;

void setIO(string name) {
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int main() {
    setIO("notlast");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;

    map<string, int> milk;
    for (int i=0; i<n; i++) {
        string name;
        int log;
        cin >> name >> log;
        milk[name] += log;
    }

    vector<pair<int, string>> cows;
    for (pair<string, int> t : milk) { cows.push_back({t.second, t.first}); }
    sort(cows.begin(), cows.end());
    int i=1;

	for(;i<7;i++){
		if(cows[i].first!=cows[0].first){
			break;
		}
	}
	if(i==7 || (i<6 && cows[i].first==cows[i+1].first)){
		cout<<"Tie"<<endl;
	}
	else{
		cout<<cows[i].second<<endl;
	}
}