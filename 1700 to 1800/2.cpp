// Ceiling Sum

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
        
        if(a == b){
            cout<<0<<endl;
            continue;
        }
        
        else {
            ll value = floor((b - a + 2) / 2.0);
            cout<<value<<endl;
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
        int n, m;
        cin>>n>>m;
        
        int mat[n+1][m+1];
        
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        
        mat[x1][y1] = 1;
        mat[x2][y2] = 2;
        
        bool chess = (((x1 + y1) % 2) != ((x2 + y2) % 2));
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                
                if ((i == x1) && (j == y1)) continue;
                if ((i == x2) && (j == y2)) continue;
                
                if(((i + j) % 2) == ((x1 + y1) % 2)){
                    mat[i][j] = 1;
                }
                else {
                    mat[i][j] = (chess ? 2 : 3);
                }
            }
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cout<<mat[i][j]<<' ';
            }
            cout<<endl;
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
        ll x, y;
        cin>>x>>y;
        
        ll a1, b1;
        if(x % 2 == 0){
            a1 = x/2;
            b1 = x/2;
        }
        else {
            a1 = x/2;
            b1 = x/2 + 1;
        }

        bool f = false;
        for(ll i=1; i*i <= y; i++){
            if(y % i != 0) continue;
            
            if(y/i < a1 || i > b1){
                cout<<a1<<" "<<b1<<endl;
                cout<<i<<" "<<y/i<<endl;
                f = true;
                break;
            }
        }
        
        if(f == false){
            cout<<-1<<endl;
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
        ll n, m; 
        cin>>n>>m;
        
        vector<ll> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        
        sort(a.begin(), a.end());
        
        int mex = 1;
        int t = 0;
        for(int i=0; i<n; i++){
            if(a[i] == m) continue;
            if(a[i] == mex) mex++;
            t++;
        }
        
        if(mex != m || t == 0){
            cout<<-1<<endl;
        }
        else {
            cout<<t<<endl;
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
        int n;
        cin>>n;
        
        ll c = 0;
        ll i = 0;
        while(c < n){
            if(__builtin_popcountll(i) % 2 == 0){
                cout<<i<<" ";
                c++;
            }
            i++;
        }
        
        cout<<endl;
    }
    return 0;
}




#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;


int blockSize;
vector<int> a, blockMin, blockMax;

void build(int n) {
    blockSize = sqrt(n) + 1;
    blockMin.assign(blockSize, INT_MAX);
    blockMax.assign(blockSize, INT_MIN);

    for (int i = 0; i < n; i++) {
        blockMin[i / blockSize] = min(blockMin[i / blockSize], a[i]);
        blockMax[i / blockSize] = max(blockMax[i / blockSize], a[i]);
    }
}

int rangeMin(int l, int r) {
    int ans = INT_MAX;

    while (l <= r && l % blockSize != 0)
        ans = min(ans, a[l++]);

    while (l + blockSize - 1 <= r) {
        ans = min(ans, blockMin[l / blockSize]);
        l += blockSize;
    }

    while (l <= r)
        ans = min(ans, a[l++]);

    return ans;
}

int rangeMax(int l, int r) {
    int ans = INT_MIN;

    while (l <= r && l % blockSize != 0)
        ans = max(ans, a[l++]);

    while (l + blockSize - 1 <= r) {
        ans = max(ans, blockMax[l / blockSize]);
        l += blockSize;
    }

    while (l <= r)
        ans = max(ans, a[l++]);

    return ans;
}


int main() {
    int n;
    cin>>n;
    a.resize(n);
    
    for(int i=0; i<n; i++) cin>>a[i];
    build(n);
    
    int q;
    cin>>q;
    while(q--){
        int l, r;
        cin>>l>>r;
        
        int min_range = rangeMin(l, r);
        int max_range = rangeMax(l, r);
        int max_outside = max(rangeMax(0, l-1), rangeMax(r+1, n-1));
        
        double t = min_range + max((double)max_outside, (max_range - min_range) / 2.0);
        
        cout << fixed << setprecision(1) << t << endl;
    }
    
    return 0;
}