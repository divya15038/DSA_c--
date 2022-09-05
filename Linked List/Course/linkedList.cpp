#include<iostream>
#include "list.h"
using namespace std;

int main(){
    List l;
    l.push_front(12);
    l.push_front(14);
    l.push_back(2);

    l.print();

    l.insert(3, 1);
    l.print();

    l.insert(4, 0);
    l.insert(5, l.len()-1);
    l.insert(9, 4);
    l.insert(78, l.len()+2);
    l.print();
    cout << l.pop(l.len()-1) << endl;
    l.print();
    return 0;
}