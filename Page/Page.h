#ifndef PAGE_H
#define PAGE_H
#include<string.h>
#include<iostream>
using namespace std;
const int num =20;

class Page
{
    public:
        Page();
        virtual ~Page();
        int read( char a[]);//从文件流读
        int write(char a[],int n);//写入文件流
        void printinformation(int n,string a);//将结果打印到屏幕上
        void carry_out();//执行函数
        void printgeshi(string a);//打印格式
        int  count_lackpage_num(int n);//计算缺页数
        void setpage_dirtion(int i,int a);
        void setwu1(int i,int a);
        void setwu2(int i,int a);
        void setwu3(int i,int a);

        void setlack_page(int i,bool a);
        int getpage_dirtion(int i);
        int getwu1(int i);
        int getwu2(int i);
        int getwu3(int i);
        bool getlack_page(int i);
    protected:

    private:
        int page_dirtion[num];//页面走向
        int wu1[num];//物理块1
        int wu2[num];//定义物理块2
        int wu3[num];//物理块3
        bool lack_page[num];//缺页
};

#endif // PAGE_H
