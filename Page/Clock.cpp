#include "Clock.h"
#include<iostream>
#include<string>
using namespace std;

Clock::Clock()
{
    //ctor
}

Clock::~Clock()
{
    //dtor
}

void Clock::carry_out(){
int n=read("data_clock.txt");
int c=1;//定义物理块号
int block[4]={0,0,0,0};//存数据
int biaoji[4]={0,0,0,0};//优先级标记，优先级=0先

for(int i=1;i<=n;i++){
int panduan=0;
int pd=0;//记录不缺页时在块内的位置
for(int j=1;j<=3;j++){
    if(getpage_dirtion(i)==block[j]){
        pd=j;
        panduan=1;//不缺页
        break;
    }
}
if(panduan==0){//缺页中断
    //找优先级最大的
   int a1=1;//while条件
   int t1=1;//记录位置
   while(a1){
   t1=1;
   for(int b=1;b<=3;b++){
    if(biaoji[b]==0){
    t1=b;
    break;
    }else{
    t1=-1;
    }
   }
//判断是否找到标记为0
if(t1==-1){
    //没有找到都标记为0
    for(int i=1;i<=3;i++){
        biaoji[i]=0;
    }
}else{
//找到
a1=0;

}

   }
   //更新当前块
   block[t1]=getpage_dirtion(i);
   //更新物理块
   setwu1(c,block[1]);
   setwu2(c,block[2]);
   setwu3(c,block[3]);

   //更新优先级标记
    for(int j=1;j<=3;j++){
        if(j==t1){
            biaoji[j]=1;
        }
    }
   //标记缺省 缺页
   setlack_page(c,false);
   c++;
}else{
//不缺页
 //更新物理块
   setwu1(c,block[1]);
   setwu2(c,block[2]);
   setwu3(c,block[3]);

 //更新优先级标记
    for(int j=1;j<=3;j++){
        if(j==pd){
            biaoji[j]=1;
        }
    }
   //标记缺省 不缺页
   setlack_page(c,true);
   c++;

}
}

//打印到屏幕
printinformation(n,"clock");

//写入到文件输出流
write("clock.txt",n);


}
