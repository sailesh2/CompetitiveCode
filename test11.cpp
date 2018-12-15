#include<iostream>
#include<stdio.h>
using namespace std;
class B;
class A{
    public:
    A()
    {
    }
    A(int b)
    {
        aa=b;
    }
    A(const B &b)
    {
        aa=10;
    }
    int aa;
    char c;
};
class B{
float f;
string s;
};

int main(){
A a;
B b;
a=b;
cout<<a.aa;
return 0;
}
