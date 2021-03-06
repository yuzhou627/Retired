#include<bits/stdc++.h>

#define FI(i,a,b) for(int i=(a);i<=(b);i++)
#define FD(i,a,b) for(int i=(a);i>=(b);i--)

#define PII pair<int,int>
#define mp make_pair
#define fi first
#define se second

using namespace std;

int n,s[150005],res;

bool ok(int x){
  if(x<=0 || x>=n) return true;
  if(x%2==1) return s[x]<s[x+1];
  else return s[x]>s[x+1];
}

vector<int> cand;

map<PII,bool> M;

int main(){
  scanf("%d",&n);
  FI(i,1,n) scanf("%d",&s[i]);
  FI(i,1,n) if(!ok(i)) cand.push_back(i);
  if(cand.size()>=6){
    printf("0\n");
    return 0;
  }
  FI(i,0,(int)cand.size()-1){
   FI(u,0,1){
    FI(j,1,n){
      int a=j,b=cand[i]+u;
      if(a>b) swap(a,b);
      if(b>n || a==b || M.count(mp(a,b))) continue;
      M[mp(a,b)]=true;
      
      swap(s[a],s[b]);
      bool work=true;
      FI(k,0,1){
        if(!ok(a-k)) work=false;
        if(!ok(b-k)) work=false;
        FI(l,0,(int)cand.size()-1) if(!ok(cand[l]-k)) work=false;
      }
      if(work) res++;
      swap(s[a],s[b]);
    }
   }
  }
  printf("%d\n",res);
  return 0;
}
