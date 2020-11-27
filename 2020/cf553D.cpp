#include<bits/stdc++.h>
#define gc getchar

using namespace std;

inline long long int lscan()
{
long long int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}

struct Student{
    long long int a;
    long long int b;
    long long int pos;
};

bool stuComp(Student s1, Student s2){
    return s1.a+s2.b>s1.b+s2.a;
}

int main(){
    long long int n;
    n=lscan();
    long long int x,y;
    Student arr[n];
    for(long long int i=0;i<n;i++){
        x=lscan();
        y=lscan();
        Student student;
        student.a=x;
        student.b=y;
        student.pos=i+1;
        arr[i]=student;
    }

    sort(arr,arr+n,stuComp);

    long long int dis=0;
    for(long long int i=0;i<n;i++){
        dis=dis+ arr[i].a*i + arr[i].b*(n-1-i);
    }
    cout<<dis;
    return 0;
}
