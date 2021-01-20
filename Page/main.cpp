#include<iostream>
#include"FIFO.h"
#include"LRU.h"
#include"Clock.h"
#include"LFU.h"
#include"OPT.h"
using namespace std;
int main(){
FIFO a1;
a1.carry_out();

LRU a2;
a2.carry_out();


LFU a3;
a3.carry_out();

Clock a4;
a4.carry_out();


OPT a5;
a5.carry_out();

}
