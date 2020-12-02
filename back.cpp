#include <bits/stdc++.h>
#include <cctype>
#include <cstring>
using namespace std;

void create(string key,int value, std::map<string, int> &m){
    map<string, int>::iterator it ; 
    it = m.find(key);
    if(it != m.end()){
        cout << "error. This key already there in the data, Try to insert new key-value pair";
    }
    else{
        if (isalpha(key)){
            long long s = 1024*1020*1024;
            if(m.size()<s && value<=(16*1024*1024)){
                if(key.size()<=32){
                    m[key]=1;
                }
            }
            else{
                cout << "Memory limit exceeded";
            }
        }
        else{
            cout << " Invalid key, Please insert new key";
        }
            
    }

}

void read(string key,std::map<string, int> &m ){
    map<string, int>::iterator it ; 
    it = m.find(key);
    if(it == m.end()){
        cout << "error. This key not exists in the data, Try using with another key";
    }
    else{
        int v = m[key];
        string  k = key + " - " + to_string(v);
        cout << k;
    }
}

void del(string key,std::map<string, int> &m){
    map<string, int>::iterator it ; 
    it = m.find(key);
    if(it == m.end()){
        cout << "error. This key not exists in the data, Try using with another key";
    }
    else{
        int v=m[key];
        m.erase(key);
        cout << "Given key is succesfully deleted.";
    }
}

void alter(string key,int value, std::map<string, int> &m){
    int v = m[key];
    map<string, int>::iterator it ; 
    it = m.find(key);
    if(it == m.end()){
        cout << "error. This key not exists in the data, Try to modify another key";
    }
    else{
        m.erase(key);
        m[key]=value;
        cout << "the value is modified with respect to the given key";
    }
    
}
int main(){
    map<string,int> m;
    string key; 
    string altkey;
    string keydel;
    int kval;
    int altvalue;
    cout << " please insert key-Value pair";
    cout << "Input key";
    getline(cin, key);
    cout << " input value to the given key";
    cin >> kval;
    cout << "now we are inserting into the data";
    create(key,kval,m);


    cout << "to reed the value pair of the given key in the data";
    read(key,m);

    cout << "to delete the key in the data";
    cout << "please enter the key which you wants to delete";
    getline(cin,keydel);
    del(keydel,m);

    cout << "to alter the value of the given key";
    getline(cin, altkey);
    cin >> altvalue;
    alter(altkey,altvalue,m);

    return 0;


}