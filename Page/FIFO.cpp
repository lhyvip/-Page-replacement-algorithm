#include "FIFO.h"
#include<iostream>
using namespace std;
FIFO::FIFO()
{
    //ctor
}

FIFO::~FIFO()
{
    //dtor
}
void FIFO::carry_out(){
int n=read("data1.txt");
int c=1;//����������
int block[4]={0,0,0,0};//������
int biaoji[4]={1,1,1,1};//���ȼ���ǣ����ȼ�Խ��Խ��
//ǰ����
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
    int t=biaoji[1];//�����ȼ�����
    int t1=1;//��¼λ��
   for(int b=2;b<=3;b++){
    if(t<biaoji[b]){
    t=biaoji[b];
    t1=b;
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
        if(j!=t1){
            biaoji[j]++;
        }else{
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
        if(j!=pd){
            biaoji[j]++;
        }else{
        biaoji[j]=1;
        }
    }
   //���ȱʡ ��ȱҳ
   setlack_page(c,true);
   c++;

}
}

//��ӡ����Ļ
printinformation(n,"FIFO");

//д�뵽�ļ������
write("fifo.txt",n);

}
