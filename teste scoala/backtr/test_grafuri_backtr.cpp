/*#include <iostream>
using namespace std;
int a[100], u[100], n, k;
/// permutari, aranjamente, combinari
void afis(int x)
{
    for(int i=1; i<=x; i++) cout << a[i] << " ";
    cout << endl;
}

void bkp(int p) /// p- poztia pe care pun elementul
{
    int i;
    for(i=1; i<=n; i++)
        if(u[i]==0)
    {
        a[p] = i;
        u[i] = 1;
        if(p==n)afis(n)
;
            else bkp(p+1);
        u[i] = 0;
    }
}
void bka(int p) /// p- poztia pe care pun elementul
{
    int i;
    for(i=1; i<=n; i++)
        if(u[i]==0)
    {
        a[p] = i;
        u[i] = 1;
        if(p==k)afis(k);
            else bka(p+1);
        u[i] = 0;
    }
}
void bkc(int p) /// p- pozitia pe care pun elementul
{
    int i;
    for(i=a[p-1]+1; i<=n; i++)
    {
        a[p] = i;
        if(p==k)afis(k);
            else bkc(p+1);
    }
}
int main()
{
    cin >> n >> k;
    bkc(1);


    return 0;
}
*/

#include<iostream>
using namespace std;
int st[100],k,n;
void init (int k)
{
    st[k]=0;
}
bool succesor (int k)
{ if(st[k]<n) {st[k]++;
   return true;}
   else return false;
}
bool valid (int k)
{ bool ev=true;
 for(int i=1;i<k;i++)
 if (st[i]==st[k])ev=false;
 return ev;
}
bool solutie (int k)
{ return (k==n);
}
void tipar (int k)
{ for(int i=1;i<=k;i++)
 cout<<st[i]<<" ";
 cout<<'\n';
}
void back (int k)
{k=1; init(k);
 while (k>0){
  if(succesor(k)){ 
    if(valid(k)){ 
        if(solutie(k))tipar(k);
        else {k++;  init(k); }
    }
  }
  else k--;}
}
int main(){
    do{cout<<"n=";cin>>n;}while(n<=0);
    back(n);}