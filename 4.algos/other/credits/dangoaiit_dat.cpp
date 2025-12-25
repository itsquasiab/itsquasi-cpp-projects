#include <iostream>
#include <algorithm>
#define ll long long 
using namespace std;
int n, q, p;
string s;
int st[531445];
void build(int id) {
	if(id*3>n) {
		st[id]=(s[id]=='A'?1:-1);
		return;
	}
	build(id*3-2);
	build(id*3-1);
	build(id*3);
	st[id]=st[id*3-2]+st[id*3-1]+st[id*3];
}
void update(int id, int cnt) {
	while(1) {
		int par=(id+2)/3;
		if(cnt>0) {
			st[id]=st[id*3]+st[id*3-1]+st[id*3-2];
		}
		else {
			st[id]*=-1;
		}
		cnt++;
		if(par<=3) {
			break;
		}
		id=par;
	}
}
void check_update(int id) {
	int tmp=(id+2)/3;
	tmp*=3;
	if(tmp*3>n) {
		update(id, 0);
	}
}
main() {
	if(fopen("dangoaiit.inp", "r")) {
		freopen("dangoaiit.inp", "r", stdin);
		freopen("dangoaiit.out", "w", stdout);
	}
	cin>>n>>q;
	cin>>s;
	s=' '+s;
	if(n==1) {
		int tmp=0;
		for(int i=1; i<s.size(); i++) {
			tmp+=(s[i]=='A'?1:-1);
		}
		while(q--) {
			cin>>p;
			s[p]=(s[p]=='A'?'B':'A');
			(s[p]=='A')?tmp+=2:tmp-=2;
			cout<<((tmp>0)?'A':'B')<<'\n';
		}
		exit(0);
	}
	build(2);
	build(3);
	while(q--) {
		cin>>p;
		int tmp=0;	
		if(p==1 || p==2 || p==3) {
			s[p]=(s[p]=='A'?'B':'A');
			for(int i=1; i<=3; i++) {
				tmp+=(s[i]=='A'?1:-1);
			}
		}
		else {
			check_update(p);
			for(int i=1; i<=3; i++) { // get 1
				tmp+=(s[i]=='A'?1:-1);
			}
		}
		tmp+=st[2]+st[3];
		
		cout<<((tmp>0)?'A':'B')<<'\n';

	}
}