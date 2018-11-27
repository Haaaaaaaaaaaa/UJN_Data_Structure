//Program         :����ջ�ж�һ���ַ����Ƿ��ǻ���
//Written by      :caitao
//Date            :28/10/2018
//Version number  :VC 6.0
#include <iostream>
#include <assert.h>           
#include <cstring>         
#include <iomanip>
#include <cstdlib>
const int stackIncreament=20;                   //ջ���ʱ��չ�ռ������
using namespace std;

template <class T>

class SeqStack                                  //˳��ջ���ඨ��
{
public:
    SeqStack(int sz=50);                        //����һ����ջ
    ~SeqStack(){delete[] elements;}             //��������
    void Push(const T& x);                      //���IsFull(),��������������x���뵽ջ��ջ��
    bool Pop(T& x);								//���IsEmpty(),��ִ���˳�ջ������false,�����˵�λ��ջ����Ԫ�أ�����return��
    bool getTop(T& x);							//���IsEmpty()���򷵻�false,���򷵻�true��
    bool IsEmpty()const{return(top==-1)?true:false;}
												//���ջ��Ԫ�ظ���Ϊ�㣬�򷵻�true,���򷵻�false��
    bool IsFull()const{return(top==maxSize-1)?true:false;}
												//���ջ��Ԫ�ظ�������maxSize,�򷵻�ture,���򷵻�false��
    int getSize()const{return top+1;}           //��������ջ��Ԫ�ظ���
    void makeEmpty(){top=-1;}                   //���ջ������
   

private:
    T *elements;                                //���ջ��Ԫ�ص�ջ����
    int top;                                    //ջ��ָ��
    int maxSize;                                //ջ��������Ԫ�ظ���
    void overflowProcess();                     //ջ���������
};
 
template <class T>
SeqStack<T>::SeqStack(int sz):top(-1),maxSize(sz)//˳��ջ�Ĺ��캯��
{
    elements=new T[maxSize];
    assert(elements!=NULL);
}

template <class T>
void SeqStack<T>::overflowProcess()               //˽�к���������ջ�Ŀռ䡣
{
    T *newArray=new T[maxSize+stackIncreament];
    if(newArray=NULL){cerr<<"�洢����ʧ�ܣ�"<<endl;exit(1);}
    for(int i=0;i<=top;i++)
        newArray[i]=elements[i];
    maxSize=maxSize+stackIncreament;
    delete[] elements;
    elements=newArray;
}

template <class T>

void SeqStack<T>::Push(const T& x)
//������������ջ��������Ԫ��x���뵽��ջ��ջ���������������
{
    if(IsFull()==true) overflowProcess();        //ջ�����������
    elements[++top]=x;				             //ջ��ָ���ȼ���1���ٽ�ջ
}

template <class T>

bool SeqStack<T>::Pop(T& x)
//������������ջ�����������ظ�ջջ��Ԫ�ص�ֵ��Ȼ��ջ��ָ����1
{
    if(IsEmpty()==true) return false;			//�ж�ջ�շ���ջ����������
    x=elements[top--];							//ջָ����1 
    return true;								//��ջ�ɹ� 
}

template <class T>

bool SeqStack<T>::getTop(T& x)
//������������ջ�����������ظ�ջջ��Ԫ�صĵ�ַ 
{
    if(IsEmpty()==true)							//��վ�շ���ջ���������� 
        return false;
    x=elements[top];							//����ջ��Ԫ�ص�ֵ 
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

