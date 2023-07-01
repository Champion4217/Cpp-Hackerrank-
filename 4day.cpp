#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    // Complete this function
    stringstream ss(str);
    
char ch;
vector<int> ans;
int temp;
while(ss >> temp){
    ans.push_back(temp);
    ss >> ch;
}

return ans;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}

// -----------------------------//

#include <bits/stdc++.h>
using namespace std;

int main()
{
int n, q,i;
cin>>n>>q;
string temp;
vector<string> hrml;
vector<string> quer;
cin.ignore();

for(i=0;i<n;i++)
{
    getline(cin,temp);
    hrml.push_back(temp);
}
for(i=0;i<q;i++)
{
    getline(cin,temp);
    quer.push_back(temp);
}

map<string, string> m;
vector<string> tag;

for(i=0;i<n;i++)
{
    temp=hrml[i];
    temp.erase(remove(temp.begin(), temp.end(), '\"' ),temp.end());
    temp.erase(remove(temp.begin(), temp.end(), '>' ),temp.end());

    if(temp.substr(0,2)=="</")
    {
        tag.pop_back();
    }
    else
    {
        stringstream ss;
        ss.str("");
        ss<<temp;
        string t1,p1,v1;
        char ch;
        ss>>ch>>t1>>p1>>ch>>v1;
        string temp1="";
        if(tag.size()>0)
        {
            temp1=*tag.rbegin();
            temp1=temp1+"."+t1;
        }
        else
            temp1=t1;
        tag.push_back(temp1);
        m[*tag.rbegin()+"~"+p1]=v1;
        while(ss)
        {
            ss>>p1>>ch>>v1;
            m[*tag.rbegin()+"~"+p1]=v1;
        }
    }

}

for(i=0;i<q;i++){
    if (m.find(quer[i]) == m.end())
        cout << "Not Found!\n";
    else
        cout<<m[quer[i]]<<endl;
}
return 0;

}
//--------------------//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache: public Cache
{
public:
    LRUCache(int c) 
    {
      cp = c;
    }

    void set(int k, int v) 
    {
        Node* N;

        if ( mp.empty() ) 
        {

            N = new Node(k,v);
            tail = head = N;
            mp[k] = N;

            return;
        }
        auto it = mp.find(k);
        if ( it != mp.end() ) 
        {
            it->second->value = v;
            if ( head == it->second ) 
            {
                return;
            }
            it->second->prev->next = it->second->next;           
            if ( tail == it->second ) 
            {
                tail = tail->prev;
            }
            else 
            {               
                it->second->next->prev = it->second->prev;
            }           
            it->second->next = head;
            it->second->prev = nullptr;
            head->prev = it->second;
            head = it->second;
        }
        else 
        {
            N = new Node(head->prev, head, k, v);
            head->prev = N; 
            head = N;
            mp[k] = N;
            if ( mp.size() > cp ) 
            {
                tail = tail->prev;
                mp.erase(tail->next->key);
                delete tail->next; 
                tail->next = nullptr;
            }
        }
    }
    int get(int k) 
    {
        auto it = mp.find(k);
        if ( it != mp.end() ) 
        {
            return it->second->value;
        }
        
        return -1;
    }
};
int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}

// ---------------------//

#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
    //Write your code here.
    std::deque<int>  dq(k);
    int i;
    for (i = 0; i < k; ++i) {
        while ( (!dq.empty()) && arr[i] >= arr[dq.back()])
            dq.pop_back();
 
        dq.push_back(i);
    }
 
    for ( ; i < n; ++i) {
        cout << arr[dq.front()] << " ";
 
        while ( (!dq.empty()) && dq.front() <= i - k)
            dq.pop_front();
 
        while ( (!dq.empty()) && arr[i] >= arr[dq.back()])
            dq.pop_back();
 
        dq.push_back(i);
    }
 
    cout << arr[dq.front()] << endl;
}

int main(){
  
    int t;
    cin >> t;
    while(t>0) {
        int n,k;
        cin >> n >> k;
        int i;
        int arr[n];
        for(i=0;i<n;i++)
              cin >> arr[i];
        printKMax(arr, n, k);
        t--;
      }
      return 0;
}