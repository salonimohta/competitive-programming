/*
	AARUSH JUNEJA
	@vivace1
	IIT(ISM),Dhanbad
*/

#include<bits/stdc++.h>
using namespace std;

typedef double lf;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef set<ll> sll;
typedef vector<ll> vll;
typedef map<string,ll> msl;
typedef pair<int,int> pii;
typedef pair<ll,ll> ii;
typedef vector<ii > vpll;
typedef map<ll,ll> mll;
typedef vector<vll > vvll;
typedef list<ll> lll;
typedef vector<lll > vlll;
typedef pair<ll,ii> iii;

#define rtn return 
#define gc getchar
#define pb push_back
#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define lp(i,a,b)   for(ll i = ll(a); i<=ll(b) ; i++) 
#define lpr(i,a,b)  for(ll i = ll(a); i>=ll(b) ; i--)       
#define lpit(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define mid(s,e) (s+(e-s)/2)

ll ip(){
	ll x = 0; bool isNeg = false; char c;
	c = gc();
	if(c == '-')	isNeg = true , c = gc();
	for( ; c >= '0'  && c <= '9' ; c = gc()); x = (x << 1) + (x << 3) + c - '0';
	if(isNeg)	x *= -1;	return x;
}

//inline ll ncr(ll n,ll r){ ll ans = 1 ; if(r > n-r) r = n-r; lp(i,0,r){ans*=(n-i) ; ans/=(i+1); } rtn ans; }
inline ll gcd(ll a,ll b){if(!a) rtn b; rtn gcd(b%a,a); }
inline ll fme(ll x,ll n,ll mod){ll ans=1;x%=mod;while(n>0){if(n&1){ ans*=x;ans%=mod;} x*=x;x%=mod;n>>=1;}rtn ans%mod;}
inline bool isPalin(string &s){	int len = s.size()-1;lp(i,0,(len/2)+1){if(!(s[i]==s[len-i]))	rtn false;} rtn true;}
inline ll lcm(ll a,ll b){rtn (a*b)/gcd(a,b); }
inline ll fmm(ll a,ll b,ll m) {ll r=0;a%=m;b%=m;while(b>0){if(b&1){r+=a;r%=m;}a+=a;a%=m;b>>=1;}rtn r%m;}
inline ll sfme(ll a,ll b,ll m) {ll r=1;a%=m;while(b>0){if(b&1)r=fmm(r,a,m);a=fmm(a,a,m);b>>=1;}rtn r%m;}
//--------------------------------TEMPLATE ENDS HERE--------------------------------------------------//

#define MOD 1000000007
#define N 100010

inline int in(){
    int NR=0;
    register char c=gc();
    while( c < 48 || c > 57 ){c=gc();}
    while(c>47 && c< 58){
		NR = (NR << 3) + (NR << 1) + (c - 48);
		c=gc();
    }
    return NR;
}
ll fact[200000 + 1], invfact[200000 + 1];

ll ncr(ll n, ll k){
 return (((fact[n] * invfact[k]) % MOD) * invfact[n - k]) % MOD;
} 
void initialize(void){
    ll i;
    fact[0] = 1;
    
    for (i = 1; i <= 200000; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
    
    invfact[200000] = fme(fact[200000], MOD - 2,MOD);
    
    for (i = 200000 - 1; i >= 0; i--)
        invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;

}

int main(){
	//ios::sync_with_stdio(false);
	ll t,n,m,e,a,b,q,w,k;
	//ll p,q,curr,c;
    ///////////// START FROM HERE ////////////////////
	initialize();
	string s;
	cin >> s;
	n = s.size();
	vll x(n),y(n);
	x[0] = 0;
	lp(i,1,n-1){
	    if(s[i-1]=='('){
	        x[i] = x[i-1]+1;
	    }else{
	    	x[i] = x[i-1];
		}
	}
	
	y[n-1] = 0;
	lpr(i,n-2,0){
	    if(s[i+1]==')'){
	        y[i] = y[i+1]+1;
	    }else{
	    	y[i] = y[i+1];
		}
	}
		
	ll ans = 0;
	lp(i,0,n-1){
	    if(s[i]=='('){
	        ans = ( ans + ncr(x[i]+y[i],y[i]-1) )%MOD;
	    }
	}
	
    cout << ans << "\n";
	
	return 0;
}
