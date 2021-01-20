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
        int read( char a[]);//���ļ�����
        int write(char a[],int n);//д���ļ���
        void printinformation(int n,string a);//�������ӡ����Ļ��
        void carry_out();//ִ�к���
        void printgeshi(string a);//��ӡ��ʽ
        int  count_lackpage_num(int n);//����ȱҳ��
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
        int page_dirtion[num];//ҳ������
        int wu1[num];//�����1
        int wu2[num];//���������2
        int wu3[num];//�����3
        bool lack_page[num];//ȱҳ
};

#endif // PAGE_H
