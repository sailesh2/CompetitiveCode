#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;

int main()
{
    int i,t,j,n,q,x,a,b,k,save,popped;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        int dish[n+1],arr[n+1],s[n+1];
        vector< vector<int> > lt;
        vector<int> v;
        lt.push_back(v);
        for(j=1;j<=n;j++)
        {
            cin>>s[j];
            dish[j]=j;
            arr[j]=j;
            vector<int> v1;
            v1.push_back(j);
            lt.push_back(v1);
        }
        cin>>q;
        for(j=0;j<q;j++)
        {
            cin>>x;
            if(x==0)
            {
                cin>>a>>b;
                if(arr[dish[a]]==arr[dish[b]])
                    cout<<"Invalid query!\n";
                else
                {
                    if(s[a]>=s[b])
                    {
                        if(lt[dish[b]].size()<=lt[dish[a]].size())
                        {
                            k=dish[b];
                            while(!(lt[k].empty()))
                            {
                                popped=lt[k].back();
                                dish[popped]=dish[a];
                                lt[dish[a]].push_back(popped);
                                lt[k].pop_back();
                            }
                        }
                        else
                        {
                            save=arr[dish[a]];
                            k=dish[a];
                            while(!(lt[k].empty()))
                            {
                                popped=lt[k].back();
                                dish[popped]=dish[b];
                                lt[dish[b]].push_back(popped);
                                lt[k].pop_back();
                            }
                            arr[dish[b]]=save;
                        }
                    }
                    else
                    {
                        if(lt[dish[a]].size()<=lt[dish[b]].size())
                        {
                            k=dish[a];
                            while(!(lt[k].empty()))
                            {
                                popped=lt[k].back();
                                dish[popped]=dish[b];
                                lt[dish[b]].push_back(popped);
                                lt[k].pop_back();
                            }
                        }
                        else
                        {
                            save=arr[dish[b]];
                            k=dish[b];
                            while(!(lt[k].empty()))
                            {
                                popped=lt[k].back();
                                dish[popped]=dish[a];
                                lt[dish[a]].push_back(popped);
                                lt[k].pop_back();
                            }
                            arr[dish[a]]=save;
                        }
                    }
                }
            }
            else
            {
                cin>>a;
                cout<<arr[dish[a]]<<"\n";
            }
        }
    }
    return 0;
}
