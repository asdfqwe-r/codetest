#include <bits/stdc++.h>
using namespace std;

vector<double> Q;
vector<pair<double,double>> Ch;
vector<pair<double,double>> Co;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //freopen("input.txt", "r", stdin);
    
    string s;
    while(cin >> s) {
        if(s == "Query") {
            double x;
            cin >> x;
            Q.push_back(x);
        }
        if(s == "Chocolate") {
            double t,n;
            cin >> t >> n;
            Ch.push_back({t,n});
        }
        if(s == "Coffee") {
            double t,n;
            cin >> t >> n;
            Co.push_back({t,n});
        }
    }

    cout << fixed;
    cout.precision(1);

    sort(Q.begin(), Q.end());
    for (auto t : Q) {
        double R = 0;
        for(auto [nt, nn] : Ch) {
            if(nt > t) continue;
            double cmp = 8*nn - (t-nt)/12;
            if(cmp > 0)R += cmp;
        }
        for(auto [nt, nn] : Co) {
            if(nt > t) continue;
            double cmp = 2*nn - (t-nt)*(t-nt)/79;
            if(cmp>0)R += cmp;
        }
        cout << static_cast<int>(t) << ' ' << max<double>(1,R) << '\n';
    }
    
    
    
    return 0;
}