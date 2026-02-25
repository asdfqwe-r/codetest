#include<bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fastio ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int seat[101];
int n,t,p;

int seat_find() {
    bool any_occupied = false;
    for (int i = 1; i <= n; ++i) {
        if (seat[i] > 0) {
            any_occupied = true;
            break;
        }
    }

    if (!any_occupied) {
        return 1;
    }

    int best_seat = -1;
    int max_min_dist = -1;

    for (int i = 1; i <= n; ++i) {
        if (seat[i] > 0) {
            continue;
        }

        int current_min_dist = n + 1;
        for (int j = 1; j <= n; ++j) {
            if (seat[j] > 0) {
                current_min_dist = min(current_min_dist, abs(i - j));
            }
        }

        if (current_min_dist > max_min_dist) {
            max_min_dist = current_min_dist;
            best_seat = i;
        }
    }
    return best_seat;
}

int main() {
    
    cin >> n >> t >> p;
    vector<ii> time;
    for(int i = 0; i < t; i++) {
        int x,y,a,b,t1,t2;
        cin >> x;
        a = x/100;
        b = x%100;
        t1 = a*60 + b;
        cin >> y;
        a = y/100;
        b = y%100;
        t2 = a*60+b;
        time.push_back({t1,t2});
    }
    sort(time.begin(),time.end());

    int ans = 0;
    int idx = 0;
    for(int i = 540; i < 1260; i++) {
        
        for(int j = 1; j <= n; j++) {
            if(seat[j] == i) {
                seat[j] = 0;
            }
        }
        
        ii temp = time[idx];
        while(1) {
            temp = time[idx];
            if(temp.first != i) break;
            int ax = seat_find();
            seat[ax] = temp.second;
            if(idx < t) idx++;
        }

        if(seat[p] == 0) {
            ans++;
        }

        //cout << seat[1] << endl;
    }

    cout << ans;






    
}
// 알고리즘: 구현, 시뮬레이션 (좌석 배치), 정렬
