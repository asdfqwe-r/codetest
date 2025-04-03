#include<bits/stdc++.h>
#define ll long long 
using namespace std;

typedef struct {
    int x;
    int absx;
}st;

struct comp {
    bool operator() (st a, st b) {
        if(a.absx == b.absx) return a.x > b.x;
        else {
            return a.absx > b.absx;
        }
    }
};

int n;
priority_queue<st,vector<st>,comp> pq;

int main() {
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        st temp;
        int ex;
        cin >> ex;
        if(ex == 0) {
            if(pq.empty()) {
                v.push_back(0);
            }
            else {
                v.push_back(pq.top().x);
                pq.pop();
            }
        }
        else {
            temp.x = ex;
            temp.absx = ex>0?ex : -1*ex;
            pq.push(temp);
        }
    }

    for(auto x : v) {
        cout << x << '\n';
    }
}