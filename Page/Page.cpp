#include "Page.h"
#include<iostream>
#include<fstream>
using namespace std;
Page::Page()
{
    //ctor
}

Page::~Page()
{
    //dtor
}
void Page::setpage_dirtion(int i,int a){
page_dirtion[i]=a;
}
void Page::setwu1(int i,int a){
wu1[i]=a;
}
void Page::setwu2(int i,int a){
wu2[i]=a;
}
void Page::setwu3(int i,int a){
wu3[i]=a;
}
void Page::setlack_page(int i,bool a){
lack_page[i]=a;
}

int Page::getpage_dirtion(int i){
return page_dirtion[i];
}
int Page::getwu1(int i){
return wu1[i];
}
int Page::getwu2(int i){
return wu2[i];
}

int Page::getwu3(int i){
return wu3[i];
}

bool Page::getlack_page(int i){
return lack_page[i];
}

//输入格式
void Page::printgeshi(string a){
cout<<endl<<endl<<"-------"<<a<<"算法--------\n";
}

//计算缺页次数
int  Page::count_lackpage_num(int n){
  int  num=0;
for(int i=1;i<=n;++i){
    if(getlack_page(i)==0){
        num++;
    }
}
return num;
}

//从文件中读取数据
int Page::read(char a[]){
int i=1;
ifstream file1(a);
if(!file1){
cout<<"打开失败";
}else{
string pagedirtion;
file1>>pagedirtion;
//获取信息
while(i<=12){
    file1>>page_dirtion[i];
    i++;

}
}
file1.close();
return i-1;
}


//将文件写入文件
int Page::write(char  a[],int n){
ofstream file2(a);
file2<<"页面走向: ";
for(int i=1;i<=n;i++){
    file2<<getpage_dirtion(i)<<" ";
}
file2<<endl;
file2<<"物理块1:  ";
for(int i=1;i<=n;i++){
    file2<<getwu1(i)<<" ";
}
file2<<endl;
file2<<"物理块2:  ";
for(int i=1;i<=n;i++){
    file2<<getwu2(i)<<" ";
}
file2<<endl;
file2<<"物理块3:  ";
for(int i=1;i<=n;i++){
    file2<<getwu3(i)<<" ";
}
file2<<endl;
file2<<"缺页:     ";
for(int i=1;i<=n;i++){
    file2<<getlack_page(i)<<" ";
}


}


//打印信息到屏幕
void Page::printinformation(int n,string a){
//打印到屏幕
printgeshi(a);
cout<<"页面走向: ";
for(int i=1;i<=n;i++){
    cout<<getpage_dirtion(i)<<" ";
}
cout<<endl;
cout<<"物理块1:  ";
for(int i=1;i<=n;i++){
    cout<<getwu1(i)<<" ";
}
cout<<endl;
cout<<"物理块2:  ";
for(int i=1;i<=n;i++){
    cout<<getwu2(i)<<" ";
}
cout<<endl;
cout<<"物理块3:  ";
for(int i=1;i<=n;i++){
    cout<<getwu3(i)<<" ";
}
cout<<endl;
cout<<"缺页:     ";
for(int i=1;i<=n;i++){
    cout<<getlack_page(i)<<" ";
}

int num=count_lackpage_num(n);
cout<<"缺页次数为："<<num<<endl;

}
