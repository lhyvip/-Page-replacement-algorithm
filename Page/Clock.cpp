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
int c=1;//����������
int block[4]={0,0,0,0};//������
int biaoji[4]={0,0,0,0};//���ȼ���ǣ����ȼ�=0��

for(int i=1;i<=n;i++){
int panduan=0;
int pd=0;//��¼��ȱҳʱ�ڿ��ڵ�λ��
for(int j=1;j<=3;j++){
    if(getpage_dirtion(i)==block[j]){
        pd=j;
        panduan=1;//��ȱҳ
        break;
    }
}
if(panduan==0){//ȱҳ�ж�
    //�����ȼ�����
   int a1=1;//while����
   int t1=1;//��¼λ��
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
//�ж��Ƿ��ҵ����Ϊ0
if(t1==-1){
    //û���ҵ������Ϊ0
    for(int i=1;i<=3;i++){
        biaoji[i]=0;
    }
}else{
//�ҵ�
a1=0;

}

   }
   //���µ�ǰ��
   block[t1]=getpage_dirtion(i);
   //���������
   setwu1(c,block[1]);
   setwu2(c,block[2]);
   setwu3(c,block[3]);

   //�������ȼ����
    for(int j=1;j<=3;j++){
        if(j==t1){
            biaoji[j]=1;
        }
    }
   //���ȱʡ ȱҳ
   setlack_page(c,false);
   c++;
}else{
//��ȱҳ
 //���������
   setwu1(c,block[1]);
   setwu2(c,block[2]);
   setwu3(c,block[3]);

 //�������ȼ����
    for(int j=1;j<=3;j++){
        if(j==pd){
            biaoji[j]=1;
        }
    }
   //���ȱʡ ��ȱҳ
   setlack_page(c,true);
   c++;

}
}

//��ӡ����Ļ
printinformation(n,"clock");

//д�뵽�ļ������
write("clock.txt",n);


}
