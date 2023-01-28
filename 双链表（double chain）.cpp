#include <iostream>
using namespace std;
const int N=1e5+10;
int e[N],r[N],l[N],idx,m;
void add(int k,int x){
    e[idx]=x;
    r[idx]=r[k];
    l[idx]=k;
    l[r[k]]=idx;
    r[k]=idx;
    idx++;
}
void remove(int k){
    r[l[k]]=r[k];
    l[r[k]]=l[k];
}
int main()
{
    ios::sync_with_stdio(false); //cin，cout先把要输出的东西存入缓冲区，再输出，导致效率降低
                                //而这段语句可以来打消iostream的输入输出缓存，可以节省许多时间，使效率与scanf与printf相差无几
    r[0]=1,l[1]=0,idx=2; //初始化
    cin>>m;
    while(m--)
    {
        string ro;
        int x,k;
        cin>>ro;
        if(ro=="L"){
            cin>>x;
            add(0,x);
        }
        else if(ro=="R"){
            cin>>x;
            add(l[1],x);
            
        }
        else if(ro=="D"){
            cin>>k;
            remove(k+1);
        }
        else if(ro=="IL"){
            cin>>k>>x;
            add(l[k+1],x);
        }
        else{
            cin>>k>>x;
            add(k+1,x);
        }
    }
    for(int i=r[0];i!=1;i=r[i])  cout<<e[i]<<" ";
    return 0;
}
