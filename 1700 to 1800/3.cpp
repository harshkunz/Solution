// Find an integer

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

string s;

int main() {
    int t=1; cin>>t;
    while(t--){
        ll x, y;
        cin>>x>>y;
        
        ll n = x*y - x - y;
        if(n < 1){
            n += 10*x*y;
        }
        
        cout<<n<<endl;
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
        int n;
        cin>>n; 
        
        string t;
        cin>>s>>t;
        
        int p=0, e=0, pe=0, non=0;
        for(int i=0; i<n; i++){
            if(s[i] == '1' && t[i] == '1') pe++;
            else if(s[i] == '1') p++;
            else if(t[i] == '1') e++;
            else non++;
        }
        
        
        int c = 0;
        c += min(pe, non);
        pe -= min(pe, non);
        
        c += min(p, e);
        int d1 = min(p, e);
        p -= d1;
        e -= d1;
        
        
        if(p > 0 && pe > 0){
            c += min(p, pe);
            int d2 = min(p, pe);
            pe -= d2;
            p -= d2;
        }
        
        if(e > 0 && pe > 0){
            c += min(e, pe);
            int d3 = min(e, pe);
            pe -= d3;
            e -= d3;
        }
        
        if(pe > 0){
            c += pe/2;
        }
        
        cout<<c<<endl;
    }
    return 0;
}



#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

string s;

int main() {
    int t=1; cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        ll a[n], p[n], s[n];
        for(int i=0; i<n; i++) cin>>a[i];
        
        p[0] = a[0];
        for(int i=1; i<n; i++){
            p[i] = max(p[i-1], a[i]);
        }
        
        s[n-1] = a[n-1];
        for(int i=n-2; i>=0; i--){
            s[i] = max(s[i+1], a[i]);
        }
        
        ll sum = 0;
        for(int i=0; i<n; i++){
            sum += max(a[i], min(p[i], s[i]));
        }
        
        cout<<sum<<endl;
    }
    return 0;
}



// Chef and Prime Divisors

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;

string s;

int main() {
    int t=1; cin>>t;
    while(t--){
        ll a, b;
        cin>>a>>b;
        
        while(__gcd(a, b) > 1){
            b /= __gcd(a, b);
        }
        
        if(b > 1){
            cout << "No"<<endl;
        }
        else {
            cout<<"Yes"<<endl;
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
        int n;
        cin>>n;
        
        int lcs = INT_MAX;
        for(int i=0; i<n; i++){
            cin>>s;
            int a = 0, b = 0;
            
            for(int j=0; j<s.size(); j++){
                if(s[j] == 'a'){
                    a++;
                }
                else {
                    b++;
                }
            }
            
            lcs = min(lcs, min(a, b));
        }
        
        cout<<lcs<<endl;
    }
    return 0;
}



// Maths & Observations

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
static const long long mod = 1e9 + 7;

string s;

int main() {
    int t=1; cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<ll> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        
        sort(a.begin(), a.end());
        
        vector<ll> p2(n+1, 1);
        for(int i=1; i <= n; i++){
            p2[i] = (p2[i-1] * 2) % mod;
        }
        
        ll ans = 0;
        for(int i=0; i<n; i++){
            ll mx = p2[i];
            ll mn = p2[n-i-1];
            ll c = (mx - mn + mod) % mod;
            ans = (ans + a[i]* c) % mod;
        }
        
        cout<<ans<<endl;
    }
    return 0;
}



