#include <bits/stdc++.h>
using namespace std;
int n, k, m;
vector<pair<int, int>> v;
int main() {
   scanf("%d %d %d", &k, &m, &n);
   v.resize(k+m);
   for (int i = 0; i < k; i++) scanf("%d %d", &v[i].first, &v[i].second);
   for (int i = k; i < k+m; i++) {scanf("%d", &v[i].first); v[i].second = -1;}
   sort(v.begin(), v.end());
   vector<long long> ans;
   int r_i = -1;
   long long sum = 0;
   for (int i = 0; i < (int)v.size(); i++) {
      if(v[i].second == -1) {
         if(sum == 0) r_i = i;  //범위 사이에 patch가 존재하지 않음
         else {
            if(r_i == -1) ans.push_back(sum);
            else {
               long long ans1 = 0, ans2 = 0;
               for (int j = r_i+1, c = r_i; j < i; j++) {
                  while(c+1 < i && (v[c+1].first - v[j].first)*2 < v[i].first-v[r_i].first) ans2 += v[++c].second;
                  ans1 = max(ans1, ans2);
                  ans2 -= v[j].second;
               }
               ans.push_back(ans1);
               ans.push_back(sum-ans1);
            }
            r_i = i;
            sum = 0;
         }
      }
      else {
         //if(i != 0 && v[i-1].second == -1 && v[i-1].first == v[i].first) continue; //patch와 nhoj cow가 같은 위치에 존재
         sum += v[i].second;
      }
   }
   ans.push_back(sum);
   sort(rbegin(ans), rend(ans));
   ans.resize(n);
   long long hap = 0;
   for (auto val : ans) hap += val;
   printf("%lld", hap);
}
