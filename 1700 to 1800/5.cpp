// Prefixing

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

string s;

int main() {
    int t=1; cin>>t;
    while(t--){
        int n;
        cin>>n; 
        
        vector<int> a(n);
        int mx = INT_MIN;
        for(int i=0; i<n; i++){
            cin>>a[i];
            mx = max(mx, a[i]);
        }
        
        set<int> seen;
        for(int i=0; i<n; i++){
            if(seen.find(a[i]) == seen.end()){
                cout<<a[i]<<" ";
                seen.insert(a[i]);
            }
            else {
                cout<<mx<<" ";
            }
        }
        
        cout<<endl;
    }
    return 0;
}


// Same Parity Swaps in Binary Strings

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

string s;

int main() {
    int t=1; cin>>t;
    while(t--){
        int n;
        cin>>n>>s;
        
        int o0 = 0, o1 = 0, e0 = 0, e1 = 0;
        for(int i=0; i<n; i++){
            if((i+1)%2 == 0){
                if(s[i] == '1'){
                    e1++;
                }
                else {
                    e0++;
                }
            }
            else {
                if(s[i] == '1'){
                    o1++;
                }
                else {
                    o0++;
                }
            }
        }
        
        int v1 = min(o0, e1);
        int rem;
        
        if(n%2 == 0){
            rem = max(0, (n/2) - v1 - 1);
        }
        else {
            rem = (n/2) - v1;
        }
        
        int v2 = min(rem, min(e0, o1));
        
        cout<< v1 + v2 <<endl;
    }
    return 0;
}


// Problem-2

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cal(ll k, vector<ll>& a, ll h) {
    ll hours = 0;
    for (ll x : a) {
        hours += (x + k - 1) / k;
        if (hours > h) return false;
    }
    return true;
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        ll n, h;
        cin >> n >> h;

        vector<ll> a(n);
        ll mx = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mx = max(mx, a[i]);
        }

        ll low = 1, high = mx, ans = mx;

        while (low <= high) {
            ll mid = (low + high) / 2;
            if (cal(mid, a, h) == true){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}


// Digit Operation

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

int main() {
    int t=1; cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        
        vector<string> a(n), b(n);
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<n; i++) cin>>b[i];
        
        bool flag = true;
        for(int i=0; i<n; i++){
            if(a[i].size() != b[i].size()){
                flag = false;
                break;
            }
        }
        
        if(flag == false){
            cout<<"NO"<<endl;
            continue;
        }
        
        vector<int> ca(10, 0), cb(10, 0);
        
        for(auto &s: a){
            for(char c: s){
                ca[c - '0']++;
            }
        }
        
        for(auto &s: b){
            for(char c: s){
                cb[c - '0']++;
            }
        }
        
        ll cost = 0;
        for(int i=0; i<10; i++){
            if(ca[i] < cb[i]){
                cost += cb[i] - ca[i];
            }
        }
        
        if(cost <= k){
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
        
    }
    return 0;
}


// Add to Subsequence

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

string s;

int main() {
    int t=1; cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        map<int, int> freq;
        int mx = 0;
        
        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            
            freq[x]++;
            mx = max(mx, freq[x]);
        }
        
        int ops = ceil(log2(mx));
        cout<< ops <<endl;

    }
    return 0;
}



