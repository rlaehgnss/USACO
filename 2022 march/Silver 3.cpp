#include <bits/stdc++.h>
using namespace std;

char s[202020], ans[202020];
int Q, l, r;
queue<char> q;
struct data {
   char c;
}seg[1010101];

char chk(char c1, char c2) {
   if(c1 == c2) return 'X';
   if((c1 == 'W' && c2 == 'O') || (c1 == 'O' && c2 == 'W')) return 'C';
   else if((c1 == 'C' && c2 == 'O') || (c1 == 'O' && c2 == 'C')) return 'W';
   else if((c1 == 'C' && c2 == 'W') || (c1 == 'W' && c2 == 'C')) return 'O';
   else if(c1 == 'X') return c2;
   else if(c2 == 'X') return c1;
}

void build(int now, int st, int en) {
   if(st == en) {
      seg[now].c = s[st-1];
      return;
   }
   int m = (st+en)/2;
   build(now*2, st, m);
   build(now*2+1, m+1, en);
   seg[now].c = chk(seg[now*2].c, seg[now*2+1].c);
}

void query(int now, int st, int en, int qs, int qe) {
   if(en < qs || qe < st) return;
   if(qs <= st && en <= qe) {q.push(seg[now].c); return;}
   int m = (st+en)/2;
   query(now*2, st, m, qs, qe);
   query(now*2+1, m+1, en, qs, qe);
}

int main() {
   scanf("%s %d", s, &Q);
   int len = strlen(s);
   build(1, 1, len);
   for (int i = 1; i <= Q; i++) {
      scanf("%d %d", &l, &r);
      query(1, 1, len, l, r);
      while(q.size() > 1) {
         int s= q.size();
         for (int i = 0; i < s/2; i++) {
            char c1 = q.front(); q.pop();
            char c2 = q.front(); q.pop();
            q.push(chk(c1, c2));
         }
      }
      char c1 = q.front(); q.pop();
      if(c1 == 'C') ans[i] = 'Y';
      else ans[i] = 'N';
   }
   for (int i = 1; i <= Q; i++) printf("%c", ans[i]);
}
