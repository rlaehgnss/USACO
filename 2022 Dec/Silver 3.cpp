#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, a[200005][2];

int main() {
   scanf("%d %d", &n, &m);
   for (int i = 1; i <= n; i++) scanf("%d %d", &a[i][0], &a[i][1]);

   //starting point check
   vector<ll> v1(2*m+1);
   vector<ll> w1(2*m+1);
   for (int i = 1; i <= n; i++) {
      v1[a[i][0]]++;
   }
   for (int i = 0; i <= m; i++) {
      for (int j = 0; j <= m; j++) {
         w1[i+j] += v1[i]*v1[j];
      }
   }

   //ending point check
   vector<ll> v2(2*m+1), w2(2*m+1);
   for (int i = 1; i <= n; i++) v2[a[i][1]]++;
   for (int i = 0; i <= m; i++) {
      for (int j = 0; j <= m; j++) {
         w2[i+j] += v2[i]*v2[j];
      }
   }
   ll ans = 0;
   for (int i = 0; i <= 2*m; i++) {
      ans += w1[i];
      printf("%lld\n", ans);
      ans -= w2[i];
   }
}
