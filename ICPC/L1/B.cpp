#include<iostream>
#include<cstring>
using namespace std;
int a[200][200];
int tg[200][200];
char s[200][200];
int n,m,r,c;
int ans;
bool jd() {
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m ;j++) {
			if(a[i][j] != tg[i][j]) return false;
		}
	}
	return true;
}
void change() {
	for(int i = 0; i < n;i++) {
		for(int j = 0; j < m; j++) {
			if(i + r<= n&& j + c <=m && a[i][j] != tg[i][j]) {
				for(int k = i;k < i + r;k++) {
					for(int p = j; p < j + c;p++) {
						if(a[k][p]) a[k][p] = 0;
						else a[k][p] = 1;
					}
				}
				ans++;
			}
		}
	}
}

int main() {
	while(cin >> n >> m >> r >> c) {
		if(n == 0 && m == 0 && r == 0 && c == 0) return 0;
		memset(a,0,sizeof a);
		memset(tg,0,sizeof tg);
		memset(s,0,sizeof s);
		ans = 0;
		for(int i = 0;i < n ;i++) {
			cin >> s[i];
			for(int j = 0; j < m;j++) {
				tg[i][j] = s[i][j] - '0';
			}
		}
		
		change();
		if(jd()) cout << ans << endl;
		else cout << -1 << endl;
	}
	return 0;
} 