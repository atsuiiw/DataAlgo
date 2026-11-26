#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> st, en;   // disjoint half-open intervals [st[i], en[i]), sorted

void sol(){
    int opr; cin >> opr;
    if(opr == 1){
        ll a, b; cin >> a >> b;
        ll e = b + 1;

        // l = first interval with en >= a      (overlaps or touches on the left)
        // r = first interval with st >  e      (everything before r touches/overlaps on the right)
        int l = lower_bound(en.begin(), en.end(), a) - en.begin();
        int r = upper_bound(st.begin(), st.end(), e) - st.begin();

        if(l >= r){                       // no overlap: plain insert
            st.insert(st.begin() + l, a);
            en.insert(en.begin() + l, e);
        }
        else{                             // merge intervals l..r-1 into one
            ll ns = min(a, st[l]);
            ll ne = max(e, en[r-1]);
            st[l] = ns;
            en[l] = ne;
            st.erase(st.begin() + l + 1, st.begin() + r);
            en.erase(en.begin() + l + 1, en.begin() + r);
        }
    }
    else if(opr == 2){
        cout << st.size() << '\n';
    }
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int q; cin >> q;
    while(q--) sol();
    return 0;
}
