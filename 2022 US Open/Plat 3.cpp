#include <bits/stdc++.h>
using namespace std;

int n, p[303030];
char c[303030];


int main() {
   scanf("%d", &n);
   for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
   scanf("%s", c);
   int curp = 1, k = 0;
   while(curp < n && k < n-1) {
      char d = c[k];
      vector<int> v;
      if(d == 'U')v.push_back(p[curp]);
      else v.push_back(-p[curp]);
      while(curp < n && k < n-1 && c[k] == d) {
         curp++;
         if(d == 'U' && v[v.size()-1] < p[curp]) {k++; v.push_back(p[curp]);}
         else if(d == 'U') {
            auto iter = lower_bound(v.begin(), v.end(), p[curp]);
            *iter = p[curp];
         }
         else if(d == 'D' && v[v.size()-1] < -p[curp]) {k++; v.push_back(-p[curp]);}
         else {
            auto iter = lower_bound(v.begin(), v.end(), -p[curp]);
            *iter = -p[curp];
         }
      }
   }
   printf("%d", k);
}
