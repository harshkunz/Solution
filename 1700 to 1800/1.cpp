#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

string s;

int main() {
    int t=1; cin>>t;
    while(t--){
        int n;  cin>>n;
        int score = 0;
        for(int i=0; i<n; i++){
            int type, a, b;
            cin>>type>>a>>b;
            
            if(type == 1 || a == b || min(a, b) < score){
                score = max(a, b);
                cout<<"YES"<<endl;
            }
            else {
                cout<<"NO"<<endl;
            }
        }

    }
    return 0;
}



#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

string s;

int main() {
    int t=1; cin>>t;
    while(t--){
        int n, x; cin>>n>>x;
        int a[n];
        int mn=INT_MAX, mx=INT_MIN;
        for(int i=0; i<n; i++){
            cin>>a[i];
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }
        
        if(mn <= x && mx >= x){
            cout<<"yes"<<endl;
        }
        else cout<<"no"<<endl;
    }
    return 0;
}



#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

string s;

int msb(int x){
    if(x == 0) return 0;
    
    int b = 1;
    while(x >> b) b++;
    
    return b;
}

int main() {
    int t=1; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        
        vector<vector<int>> pref(n+1, vector<int>(32, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<32; j++){
                pref[i+1][j] = pref[i][j] + (msb(a[i]) == j);
            }
        }
        
        int q;
        cin>>q;
        
        for(int i=0; i<q; i++){
            int l, r, x;
            cin>>l>>r>>x;
            
            int b = msb(x);
            int c = (r-l+1) - (pref[r][b] - pref[l-1][b]);
            
            cout<<c<<endl;
        }

    }
    return 0;
}



#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

string s;

int main() {
    int t=1; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        
        int c=0;
        vector<int> room;
        for(int i=0; i<n; i++){
            cin>>a[i];
            
            if(a[i] == 0){
                c++;
            }
            else {
                if(c > 0){
                    room.push_back(c);
                    c = 0;
                }
            }
        }
        
        if (c > 0) {
            room.push_back(c);
        }
        
        sort(room.begin(), room.end());
        
        int m = room.size();
        
        
        if (m == 0) {
            cout << "No" << endl;
            continue;
        }
        
        if (m == 1) {
            if (room[0] % 2 != 0) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
        
        else {
            int largest = room[m - 1];
            int second_largest = room[m - 2];
            if (largest % 2 != 0 && second_largest < (largest + 1) / 2) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;

string s;

int main() {
    int t=1; cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        vector<ll> a(n), b(n);
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<n; i++) cin>>b[i];
        
        vector<pair<ll, ll>> data(n);
        for(int i=0; i<n; i++){
            data[i] = {a[i] - b[i], i};
        }
        
        sort(data.begin(), data.end());
        
        ll ans = 0;
        for(auto [ef, i]: data){
            ll oc = a[i];
            ll cb = b[i];
            
            if(r < oc) continue;
            
            r -= oc;
            ans += 1;
            
            ans += r / ef;
            r = r % ef;
            
            r += cb;
        }
        
        cout<<ans<<endl;
        
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    while(t--){
        ll n, p, q;
        cin >> n >> p >> q;
        
        vector<ll> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        
        ll c = 0;
        sort(a.begin(), a.end());
        
        for(int i=0; i<n; i++){
            ll value = a[i];
            
            ll u2 = min(q, value / 2);
            ll u1 = value - 2*u2;
            
            if(u1 <= p){
                p -= u1;
                q -= u2;
                c++;
            }
        }
        
        cout << c << endl;
    }
    return 0;
}



#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int ans = 0;
        int i = 0;

        while (i < n) {
            if (s[i] != '0') {
                i++;
                continue;
            }

            int j = i;
            while (j < n && s[j] == '0') j++;
            int len = j - i;

            char left = (i > 0) ? s[i - 1] : '#';
            char right = (j < n) ? s[j] : '#';

            if (left == '#' && right == '#') {
                ans += len;
            } 
            else if (left == '#' || right == '#') {
                ans += 0;
            } 
            else if (left == right) {
                ans += 0;
            } 
            else {
                ans += (len % 2);
            }
            
            i = j;
        }

        cout << ans << '\n';
    }
    return 0;
}



#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<string> a(n);
        int cm = INT_MAX, cx = INT_MIN;
        int rm = INT_MAX, rx = INT_MIN;
        int c = 0;

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            for(int j = 0; j < m; j++) {
                if(a[i][j] == '*') {
                    cm = min(cm, j);
                    cx = max(cx, j);
                    rm = min(rm, i);
                    rx = max(rx, i);
                    c++;
                }
            }
        }

        if(c == 0) {
            cout << 0 << endl;
            continue;
        }

        int diff = max(rx - rm + 1, cx - cm + 1);
        cout<<(diff / 2) + 1<<endl;
    }
    return 0;
}



#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;

string s;

int main() {
    int t=1; cin>>t;    // 1 go
    while(t--){
        ll n, k;
        cin>>n>>k;
        
        cin>>s;
        vector<ll> p(n, 0);
        p[0] = 1;
        for(int i=1; i<n; i++){
            p[i] = p[i-1] + (s[i] == s[i-1] ? 0 : 1);
        }
        
        
        ll t=0;
        for(int i=k; i<n; i++){
            t += (p[i] - p[i-k]);
        }
        
        cout<<t<<endl;
    }
    return 0;
}