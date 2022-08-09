#include <bits/stdc++.h>
using namespace std;

char s[101010], t[101010], ans[101010];
int Q, lens, lent, ssum[101010][18] = {{0}}, tsum[101010][18] = {{0}}, imp_1[18] = {0}, imp_2[18][18] = {{0}};
int main() {
   scanf("%s %s %d", s, t, &Q);
   lens = strlen(s);
   lent = strlen(t);
   for (int i = 0; i < lens; i++) {
      for (int j = 0; j < 18; j++) {
         if(i == 0) ssum[i][j] = 0;
         else ssum[i][j] = ssum[i-1][j];
      }
      ssum[i][int(s[i])-97]++;
   }
   for (int i = 0; i < lent; i++) {
      for (int j = 0; j < 18; j++) {
         if(i == 0) tsum[i][j] = 0;
         else tsum[i][j] = tsum[i-1][j];
      }
      tsum[i][int(t[i])-97]++;
   }
   for (int i = 0; i < 18; i++) {
      if(ssum[lens-1][i] != tsum[lent-1][i]) imp_1[i] = 1;
      else if(ssum[lens-1][i] == 0) imp_1[i] = 2;
   }
   for (int i = 0; i < 17; i++) {
      for (int j = i+1; j < 18; j++) {
         if(imp_1[i] == 0 && imp_1[j] == 0) {
            queue<char> q;
            for (int k = 0; k < lens; k++) {
               if(s[k] == char(i+97) || s[k] == char(j+97)) q.push(s[k]);
            }
            for (int k = 0; k < lent; k++) {
               if(t[k] == char(i+97) || t[k] == char(j+97)) {
                  if(q.front() == t[k]) q.pop();
                  else {imp_2[i][j] = 1; imp_2[j][i] = 1;}
               }
            }
         }
      }
   }
   for (int i = 1; i <= Q; i++) {
      char c[25];
      scanf("%s", c);
      int lenc = strlen(c), chk2 = 0;
      for (int i = 0; i < lenc; i++) {
         if(imp_1[int(c[i])-97] == 1) {chk2 = 1; break;}
      }
      if(chk2 == 0) {
         for (int i = 0; i < lenc-1; i++) {
            for (int j = i+1; j < lenc; j++) {
               if(imp_2[int(c[i])-97][int(c[j])-97] == 1) {chk2 = 1; break;}
            }
            if(chk2 == 1) break;
         }
      }
      if(chk2 == 0) ans[i] = 'Y';
      else ans[i] = 'N';
   }
   for (int i = 1; i <= Q; i++) printf("%c", ans[i]);
}
