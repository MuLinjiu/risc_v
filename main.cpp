//
// Created by Xialin He on 2021/6/28.
//
#include <iostream>
#include <sstream>
#include "Types.hpp"
#include "Simulator.hpp"
Simulator Si;
using namespace std;
int memorypointer = 0,pos;
string s;
void INPUT(){
    while(getline(cin,s)){
        if(s[0] == '@') {
            s = s.substr(1);
            stringstream stringstream1(s);
            stringstream1 >> hex >> pos;
        }
        else {
            stringstream stringstream2(s);
            while (stringstream2 >> hex >> a[0]) {
                memory[pos++] = a[0];
            }
        }
    }
}

int main(){
    //freopen("bulgarian.data", "r", stdin);
    //freopen("2.txt","w",stdout);
    INPUT();
    Si.RUN();
    //cout << PRE.efficiency();
    return 0;
}