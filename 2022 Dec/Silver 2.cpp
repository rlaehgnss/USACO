#include <bits/stdc++.h>
using namespace std;
int t, n, m, x, y, component[101010] = {0};
vector<int> v[101010], componentgroup[101010];
vector<long long> from0(101010, 1e9), fromn(101010, 1e9);
void dfs(int cur, int cnt) {
   int s = v[cur].size();
   for (int i = 0; i < s; i++) {
      if(component[v[cur][i]] != cnt) {
         component[v[cur][i]] = cnt;
         dfs(v[cur][i], cnt);
      }
   }
}

int main() {
   scanf("%d", &t);
   while(t--) {
      //getting input
      scanf("%d %d", &n, &m);
      for (int i = 1; i <= m; i++) {
         scanf("%d %d", &x, &y);
         v[x].push_back(y);
         v[y].push_back(x);
      }
      //dividing input into components
      for (int i = 1; i <= n; i++) component[i] = i;
      for (int i = 1; i <= n; i++) {
         if(component[i] == i) dfs(i, i);
      }
      if(component[1] == component[n]) {
         printf("0\n");
         for (int i = 1; i <= n; i++) {v[i].clear(); component[i] = 0;}
         continue;
      }
      //componet dividing & finding costs
      for (int i = 1; i <= n; i++) componentgroup[component[i]].push_back(i);
      long long ans = 1e18;
      int s1 = componentgroup[component[1]].size(), s2 = componentgroup[component[n]].size(), cnt0 = 0, cntn = 0;
      for (int i = 1; i <= n; i++) {
         while(cnt0 < s1) {
            from0[component[i]] = min(from0[component[i]], (long long)abs(componentgroup[component[1]][cnt0]-i));
            if(componentgroup[component[1]][cnt0] < i) cnt0++;
            else break;
         }
         if(cnt0) cnt0--;
         while(cntn < s2) {
            fromn[component[i]] = min(fromn[component[i]], (long long)abs(componentgroup[component[n]][cntn]-i));
            if(componentgroup[component[n]][cntn] < i) cntn++;
            else break;
         }
         if(cntn) cntn--;
      }
      //printing ans, clearing
      for (int i = 1; i <= n; i++) ans = min(ans, from0[i]*from0[i]+fromn[i]*fromn[i]);
      printf("%lld\n", ans);
      for (int i = 1; i <= n; i++) {v[i].clear(); component[i] = 0;componentgroup[i].clear(); from0[i] = 1e9; fromn[i] = 1e9;}
   }
}
