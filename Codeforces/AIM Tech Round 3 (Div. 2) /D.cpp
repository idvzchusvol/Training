#pragma comment(linker, "/STACK:1024000000,1024000000")
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

const int MXN = 1000005;
char s[MXN];
int fail;
void solve(){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	LL total=0;
	LL n0,n1;
	n0=n1=b||c;
	while(n0*(n0-1)/2<a)n0++;
	while(n1*(n1-1)/2<d)n1++;
	int fail=0;
	fail|=n0*(n0-1)/2!=a;
	fail|=n1*(n1-1)/2!=d;
	fail|=n0*n1!=(b+c);
	if(fail){
		cout<<"Impossible\n";
		return;
	}
	if(a+b+c+d==0){
		cout<<"0\n";
		return;
	}
	int id=0;
	while(n0||n1){
		if(n1>0&&c>=n0)n1--,c-=n0,s[id++]='1';
		else n0--,b-=n1,s[id++]='0';
	}
	s[id]='\0';
	printf("%s\n",s);
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