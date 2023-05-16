#include<bits/stdc++.h>
using namespace std;

int max_of_four(int a,int b,int c,int d){
    int g = max(a, max(b,c));
   int greatNum = max(g,d);
    return greatNum ;
}
int main(){
    int m,n,e,h;
    cin>>m>>n>>e>>h;
    cout<<max_of_four(m,n,e,h);
    
    return 0;
    
    
}

#include<iostream>
using namespace std;

void myFunction(int a, int b){
    int c = a+b;
    int d;
    if(a>b){
        d = a-b;
    }else{
         d = b-a;
    }
    cout<<c<<endl;
    cout<<d<<endl;
    return ;
}

int main(){
    int e,f;
    cin>>e>>f;
    myFunction(e,f);
    return 0;
}