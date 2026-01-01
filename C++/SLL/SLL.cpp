#include <iostream>
#include "SLL.h"
using namespace std;

int main(){
    SLL<int>s;
    s.push_front(1);
    s.push_front(12);
    s.push_front(13);
    // 13 12 1
    s.pop_front();
    //12 1
    s.push_back(4);
    s.push_back(45);
    // 12 1 4 45
    s.pop_back();
    // 12 1 4
    s.pop_at(2);
    // 12 1
    s.push_after(1,45);
    // 12 1 45

    // Traversing
    for(int i=0;i<s.get_length();i++){
        cout<<s[i]<<" ";
    }
}
