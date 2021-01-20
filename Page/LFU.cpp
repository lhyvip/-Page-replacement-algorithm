#include "LFU.h"

LFU::LFU()
{
    //ctor
}

LFU::~LFU()
{
    //dtor
}
void LFU::carry_out(){
int n=read("data1.txt");
int c=1;//定义物理块号
int block[4]={0,0,0,0};//存数据
int biaoji[4]={0,0,0,0};//优先级标记，优先级越小越高

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
    int t=biaoji[1];//找优先级最大的
    int t1=1;//记录位置
   for(int b=2;b<=3;b++){
    if(t>biaoji[b]){
    t=biaoji[b];
    t1=b;
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
            biaoji[j]++;
        }
    }
   //标记缺省 不缺页
   setlack_page(c,true);
   c++;

}
}

//打印到屏幕
printinformation(n,"LFU");

//写入到文件输出流
write("lfu.txt",n);




}
