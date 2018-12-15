// Name: sailesh kumar upadhyaya
// USN: sailesh.ku.upadhyaya@gmail.com
/* Summary:
    Algorithm:
    steps:
        1.scan the string
        2.if it finds '('
                        then get the first operator to its right within its bracket range
                        and compare to the operator to the right of its ending bracket and the operator left to its openning bracket
                        if both are same
                            then those brackets are useless
       3.return the no of useless brackets
*/
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
        cnt=0;
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
                j++;
                cnt2=0;
                for(;j<expression.length();j++)
                {
                    if(expression[j]=='(')
                        ctr++;
                    if(expression[j]==')')
                        ctr--;

                    if(expression[j]=='+' || expression[j]=='*' || expression[j]=='-' || expression[j]=='/')
                    {
                        if(ctr==0)
                        {
                        if(save!=expression[j])
                        {
                            if((save=='+' && expression[j]=='-'))
                            {
                                cnt2=0;
                            }
                            else
                                cnt2=1;
                        }
                        else
                        {
                            if(save=='-')
                                cnt2=1;
                        }
                        break;
                        }
                    }
                }
                if(cnt2==0)
                {
                    cnt3=0;
                    j=i-1;
                    for(;j>=0;j--)
                    {
                        if(expression[j]=='+' || expression[j]=='*' || expression[j]=='-' || expression[j]=='/')
                        {
                            if(save==expression[j])
                            {
                                cnt3=1;
                                if(save!='-')
                                counter++;
                            }
                            else
                            {
                                if((save=='-' && expression[j]=='+'))
                                    counter++;
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
