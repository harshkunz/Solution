// Box of Chocolates

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

string s;

int main() {
    int t=1; cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        int a[n];
        int mx = INT_MIN;
        for(int i=0; i<n; i++){
            cin>>a[i];
            mx = max(mx, a[i]);
        }
        
        int l=-1, r=-1;
        for(int i=0; i<n; i++){
            if(a[i] == mx){
                if(l == -1){
                    l = i;
                }
                r = i;
            }
        }
        
        int ans = (n-r) - (n/2 - l);
        if(ans < 0) ans = 0;
        
        cout<<ans<<endl;
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
        ll n, x; 
        cin>>n>>x;
        
        vector<ll> a(n);
        unordered_map<ll, ll> freq;
        for(int i=0; i<n; i++){
            cin>>a[i];
            freq[a[i]]++;
        }
        
        ll mf = 0;
        ll op = LLONG_MAX;
        
        for(auto it: freq){
            ll val = it.first;
            ll count = it.second;
            
            if(count > mf){
                mf = count;
                op = 0;
            }
            
            if(count == mf && count < op){
                op = count;
            }
            
            ll y = val ^ x;
            
            if(x == 0) continue;
            
            if(freq.count(y)){
                ll total = freq[y] + count;
                
                if(total > mf){
                    mf = total;
                    op = count;
                }
                else if(total == mf && count < op){
                    op = count;
                }
            }
        }
        
        cout<<mf<<" "<<op<<endl;
    }
    return 0;
}






#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;

        vector<vector<ll>> data(n);
        for (ll i = 0; i < n; i++) {
            ll a, d, p;
            cin >> a >> d >> p;
            data[i] = {d, a, p};
        }

        sort(data.begin(), data.end());
        unordered_map<ll, ll> comp;

        ll count = 0;
        for (ll i = 0; i < n; i++) {
            ll d = data[i][0];
            ll a = data[i][1];
            ll p = data[i][2];

            if (!comp.count(p) || a >= comp[p]) {
                count++;
                comp[p] = d;
            }
        }

        cout << count << endl;
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
        
        cin>>s;
        int a=0, b=0, last=0;
        for(int i=0; i < 2*n; i++){
            if(s[i] == '1'){
                if((i+1) % 2 != 0) a++;
                else b++;
            }
    
            int ra = n - (i+2) / 2;
            int rb = n - (i+1) / 2;
            
            if(a > b + rb || b > a + ra){
                last = i+1;
                break;
            }
        }
        
        if(last == 0){
            last = 2*n;
        }
        
        cout<<last<<endl;
        
    }
    return 0;
}




#include <bits/stdc++.h>
using namespace std;
typedef long log
const int N = 1e5 + 10;

string s;

int main() {
    int t=1; cin>>t;
    while(t--){
        ll m, n;
        cin>>m>>n;
        
        if(n > m){
            cout << "No"<<endl;
        }
        else {
            while(m % 2 == 0){
                m /= 2;
            }
            
            if(n % m == 0){
                cout<<"Yes"<<endl;
            }
            else {
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}