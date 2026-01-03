#include<iostream>
#include "DLL.h"
using namespace std;

int main(){
    DLL<int> ls;
    ls.push_front(5);
    ls.push_front(7);
    ls.push_back(6);
    ls.push_back(10);
    ls.pop_back();
    for(int i=0;i<ls.get_length();i++){
        cout<< ls[i]<<" ";
    }
}