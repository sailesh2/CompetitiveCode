


#include <iostream>
#include <sstream>
#include<stdio.h>
#include <string>
using namespace std;

int main()
{
    while(1)
    {
        char s[100];
        //cin.getline(s,100);
        int i;
        if(scanf("%s",s)==EOF)
            break;
        cout<<s;
        istringstream iss(s);

        do
        {
            string sub;
            iss >> sub;
            if(!iss)
                break;
            cout << "Substring: " << sub << endl;
        } while (1);
    }
}
