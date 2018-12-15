// Name: sailesh kumar upadhyaya
// USN: sailesh.ku.upadhyaya@gmail.com
// Summary:

#include <iostream>
#include <string>

using namespace std;

// Remove additional cin/cout before submission. The checker depends on the input and output format.
int CountRedundantParentheses(const string expression)
{
    int i,j,counter=0,brackets=0,cnt,cnt2,savej,ctr,cnt3,ctr2;
    char save;
    for(i=0;i<expression.length();i++)
    {
        if(expression[i]=='(')
        {
            ctr2=0;
            cnt=1;
            for(j=i+1;j<expression.length();j++)
            {
                if(expression[j]=='(')
                    ctr2++;
                if(expression[j]==')')
                    ctr2--;


                if(expression[j]=='+' || expression[j]=='*' || expression[j]=='-' || expression[j]=='/')
                {
                    if(ctr2==0)
                    {
                    cnt=0;
                    save=expression[j];
                    break;
                    }
                }
            }
            if(cnt==0)
            {
                ctr=1;
                savej=j;
                j++;
                cnt2=0;
                for(;j<expression.length();j++)
                {
                    if(expression[j]=='(')
                        ctr++;
                    if(expression[j]==')')
                        ctr--;
                    if(ctr<0)
                    {
                        cnt2=0;
                        break;
                    }
                    if(expression[j]=='+' || expression[j]=='*' || expression[j]=='-' || expression[j]=='/')
                    {
                        if(ctr==0)
                        {
                        if(save!=expression[j])
                        {
                            cnt2=1;
                        }
                        break;
                        }
                    }
                }
                if(cnt2==0)
                {
                    cnt3=0;
                    j=savej-1;
                    for(;j>=0;j--)
                    {
                        if(expression[j]=='+' || expression[j]=='*' || expression[j]=='-' || expression[j]=='/')
                        {
                            if(save==expression[j])
                            {
                                cnt3=1;
                                counter++;
                            }
                            else
                            {
                                cnt3=2;
                            }
                            break;
                        }
                    }
                    if(cnt3==0)
                        counter++;
                }
            }
            else
            {
                counter++;
            }
        }
    }
    return counter;
}

// Do not modify main() when submitting.
int main()
{
    string expression;
    cin >> expression;
    cout << CountRedundantParentheses(expression);
}
