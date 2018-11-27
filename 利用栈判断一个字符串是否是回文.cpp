//Program         :利用栈判断一个字符串是否是回文
//Written by      :caitao
//Date            :28/10/2018
//Version number  :VC 6.0
#include <iostream>
#include <assert.h>           
#include <cstring>         
#include <iomanip>
#include <cstdlib>
const int stackIncreament=20;                   //栈溢出时扩展空间的增量
using namespace std;

template <class T>

class SeqStack                                  //顺序栈的类定义
{
public:
    SeqStack(int sz=50);                        //建立一个空栈
    ~SeqStack(){delete[] elements;}             //析构函数
    void Push(const T& x);                      //如果IsFull(),则溢出处理；否则把x插入到栈的栈顶
    bool Pop(T& x);								//如果IsEmpty(),则不执行退出栈，返回false,否则退掉位于栈顶的元素，返回return。
    bool getTop(T& x);							//如果IsEmpty()，则返回false,否则返回true。
    bool IsEmpty()const{return(top==-1)?true:false;}
												//如果栈中元素个数为零，则返回true,否则返回false。
    bool IsFull()const{return(top==maxSize-1)?true:false;}
												//如果栈中元素个数等于maxSize,则返回ture,否则返回false。
    int getSize()const{return top+1;}           //函数返回栈中元素个数
    void makeEmpty(){top=-1;}                   //清空栈的内容
   

private:
    T *elements;                                //存放栈中元素的栈数组
    int top;                                    //栈顶指针
    int maxSize;                                //栈最大可容纳元素个数
    void overflowProcess();                     //栈的溢出处理
};
 
template <class T>
SeqStack<T>::SeqStack(int sz):top(-1),maxSize(sz)//顺序栈的构造函数
{
    elements=new T[maxSize];
    assert(elements!=NULL);
}

template <class T>
void SeqStack<T>::overflowProcess()               //私有函数，扩充栈的空间。
{
    T *newArray=new T[maxSize+stackIncreament];
    if(newArray=NULL){cerr<<"存储分配失败！"<<endl;exit(1);}
    for(int i=0;i<=top;i++)
        newArray[i]=elements[i];
    maxSize=maxSize+stackIncreament;
    delete[] elements;
    elements=newArray;
}

template <class T>

void SeqStack<T>::Push(const T& x)
//公共函数：若栈不满，则将元素x插入到该栈的栈顶，否则溢出处理
{
    if(IsFull()==true) overflowProcess();        //栈满则溢出处理
    elements[++top]=x;				             //栈顶指针先加上1，再进栈
}

template <class T>

bool SeqStack<T>::Pop(T& x)
//公工函数：若栈不空则函数返回该栈栈顶元素的值，然后栈顶指针退1
{
    if(IsEmpty()==true) return false;			//判断栈空否，若栈空则函数返回
    x=elements[top--];							//栈指针退1 
    return true;								//退栈成功 
}

template <class T>

bool SeqStack<T>::getTop(T& x)
//公共函数：若栈不空则函数返回该栈栈顶元素的地址 
{
    if(IsEmpty()==true)							//判站空否，若栈空则函数返回 
        return false;
    x=elements[top];							//返回栈顶元素的值 
    return true;
}



int panduan(char *p)
{  SeqStack<char> S(100);
    int length=strlen(p);
	char c;
	for(int i=0;i<length;i++)
	{ 
		S.Push(p[i]);
	}
	for(int j=0;j<length;j++)
	{  
		S.Pop(c);
		if(c!=p[j])
		  return 0;
	}
	return 1;
}

int main()
{
    SeqStack<char> S(100);
	char *p;
    p=new char[50];
    cin>>p;
    if(panduan(p)==1)
    cout<<"yes"<<endl;
    else
    cout<<"no"<<endl;
    return 0;
}

