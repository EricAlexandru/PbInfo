///PROBLEMA DAME
#include <iostream>
using namespace std;
int st[100], n, nrsol;
int absolut(int x)
{
 if(x<0) x=-x;
 return x;
}
int valid(int k)
{
 int i;
 for (i=1; i<=k-1; i++)
 if ( (st[i]==st[k]) || (absolut( (st[k]-st[i]) ) == (k-i) ) )
    return 0;
return 1; }
int solutie( int k){
    if (k==n)
        return 1;
    return 0; }

void init (int k) {
st[k]=0; 
}

void tipar () {
 int i,j;
 nrsol++;
 cout<<"\nSolutia "<<nrsol<<" este\n";
 for(i=1;i<=n;i++){
 cout<<endl;
 for(j=1;j<=n;j++)
 if (st[j]==i)
 cout<<" D ";
 else
 cout<<" + ";
}
 cout<<endl; }

void back(int k) {
 init(k);
 int i;
 for (i=1;i<=n;i++){
 st[k]=i;
 if (valid(k)==1){
    if (solutie(k)==1)
        tipar();
    else
        back(k+1);
    }
}
}

int main()
{
 cout<<"Numarul de dame (dimensiunea tablei): ";
 cin>>n;
 back(1);
 cout<<"\nSunt "<<nrsol<<" solutii";
 return 0;
}