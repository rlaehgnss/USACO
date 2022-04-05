#include <bits/stdc++.h>
using namespace std;

int n, chk[101010] = {0}, cnt = 0, cycling = 0, cycling_s;
long long ans = 0;
struct data {
   int a,v;
}p[101010];
priority_queue<int, vector<int>, greater<int>> pq;

void dfs(int cur, int cyclechk) {
   if(chk[p[cur].a] == 0) {
      chk[p[cur].a] = cyclechk;
      dfs(p[cur].a, cyclechk);
      if(cycling == 1) {
         if(cur == cycling_s) {
            cycling = 0;
            cycling_s = 0;
         }
         pq.push(p[cur].v);
      }
   }
   else if(chk[p[cur].a] == cyclechk) {
      pq.push(p[cur].v);
      cycling = 1;
      cycling_s = p[cur].a;
   }
   else return;
}

int main() {
   scanf("%d", &n);
   for (int i = 1; i <= n; i++) {
      scanf("%d %d", &p[i].a, &p[i].v);
      ans += p[i].v;
   }
   for (int i = 1; i <= n; i++) {
      if(chk[i] != 0) continue;
      chk[i] = ++cnt;
      dfs(i, cnt);
      if(!pq.empty()) {
         ans -= pq.top();
         while(!pq.empty()) pq.pop();
      }
   }
   printf("%lld", ans);
}
