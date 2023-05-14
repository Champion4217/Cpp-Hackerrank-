#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int a,b,c,s;
    cin>>a>>b>>c;
    s=a+b+c;
    cout<<s<<endl;  
    return 0;
}

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int a,b,n;
    cin>>a>>b;
    string word[10]={"","one","two","three","four","five","six","seven","eight","nine"};
     for(n=a;n<=b;n++){
         if(n>=1&&n<=9){
             cout<<word[n]<<endl;
         }else if (n>9&&n%2==0){
             cout<<"even"<<endl;
         }else if(n>9&&n%2!=0){
             cout<<"odd"<<endl;
         }
     }
    return 0;
}
