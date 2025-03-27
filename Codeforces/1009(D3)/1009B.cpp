#include<iostream>
#include<queue>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        queue<int> q;
        for(int i = 0; i < n; i++) {
            int x; 
            cin >> x;
            q.push(x);
        }

        while(q.size() > 1) {
            int a,b;
            a = q.front();
            q.pop();
            b = q.front();
            q.pop();
            q.push(a+b-1);
        }

        cout << q.front() << '\n';

    }
}