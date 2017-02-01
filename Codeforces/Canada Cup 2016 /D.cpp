//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<fstream>
#include<numeric>
#include<iomanip>
#include<bitset>
#include<list>
#include<stdexcept>
#include<functional>
#include<utility>
#include<ctime>
#include<cassert>
using namespace std;
#define RI(X) scanf("%d", &(X))
#define DRI(X) int (X); scanf("%d", &X)
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
LL modPow(LL a,LL b,LL MOD){
	LL ret=1;for(;b;b>>=1){
		if(b&1)ret=ret*a%MOD;a=a*a%MOD;
	}return ret;
}

const int MXN = 300005;
LL t[MXN];
LL w[MXN];
vector<pair<LL,int> >TL;
void solve(){
	int n;
	while(cin>>n){
		rep(i,0,n)cin>>t[i]>>w[i];
		TL.clear();
		rep(i,0,n)TL.PB(MP(-t[i],i));
		sort(all(TL));
		int id = -1;
		rep(i,0,n)if(TL[i].BB==0)id=i;
		set<pair<LL,int> >S;
		int ans = id;
		rep(i,0,id){
			int j =TL[i].BB;
			S.insert(MP(w[j]-t[j]+1,j));
		}
		id++;
		LL rem = t[0];
		while(rem>=0&&!S.empty()){
			auto tp=*S.OP;
			if(rem>=tp.AA){
				rem-=tp.AA;
				S.erase(S.OP);
				while(id<n&&-TL[id].AA>rem){
					int j=TL[id].BB;
					S.insert(MP(w[j]-t[j]+1,j));
					id++;
				}
				int rank=sz(S);
				cmin(ans,rank);
				//printf("%d\n",rank);
			}else break;
		}
		if(S.empty())ans=0;
		printf("%d\n",ans+1);
	}
}

int main(){
	int _T=1;
	//scanf("%d",&_T);
	rep(CA,0,_T){
		//printf("Case #%d: ",CA+1);
		solve();
	}
	return 0;
}