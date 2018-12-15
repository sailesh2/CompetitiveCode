#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    long long int n,k,i,cnt,save,sm=0,l=0,m=0;
    cin>>n>>k;
    long long int arr[n];
    long long int ans[n];
    long long int brr[n][2];
    long long int crr[n][2];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cnt=0;
    for(i=0;i<k;i++)
    {
        if(cnt==0)
        {
            if(arr[i+1]>=arr[i])
            {
                cnt=1;
                save=i;
            }
        }
        else
        {
            if(i==k-1 || arr[i+1]<arr[i])
            {
                cnt=0;
                brr[l][0]=save;
                brr[l][1]=i;
                l++;
                sm=sm+((i-save)*(i-save+1))/2;
            }
        }
    }
    long long int it=0;
    long long int it1=l-1;
    ans[m]=sm;
    //cout<<sm<<"\n";
    //cout<<brr[it][0]<<" "<<brr[it][1]<<"\n";
    //cout<<brr[it1][0]<<" "<<brr[it1][1]<<"\n";
    m++;
    for(i=1;i+k-1<n;i++)
    {
        if(i>brr[it][1])
        {
      //      cout<<"en1\n";
            it++;
        }
        else if(i>=brr[it][0] && i<=brr[it][1])
        {
        //    cout<<"en2\n";
            sm=sm-((brr[it][1]-brr[it][0])*(brr[it][1]-brr[it][0]+1))/2;
            sm=sm+((brr[it][1]-i)*(brr[it][1]-i+1))/2;
            brr[it][0]=i;
        }
        if(i+k-1==brr[it1][1]+1 && arr[i+k-1]>=arr[brr[it1][1]])
        {
          //  cout<<"en3\n";
            sm=sm-((brr[it1][1]-brr[it1][0])*(brr[it1][1]-brr[it1][0]+1))/2;
            sm=sm+((i+k-1-brr[it1][0])*(i+k-1-brr[it1][0]+1))/2;
            brr[it1][1]=i+k-1;
        }
        else if(arr[i+k-1]>=arr[i+k-2])
        {
            //cout<<"en4\n";
            brr[l][0]=i+k-2;
            brr[l][1]=i+k-1;
            l++;
            it1=l-1;
            sm=sm+((brr[it1][1]-brr[it1][0])*(brr[it1][1]-brr[it1][0]+1))/2;
        }

        ans[m]=sm;

        //cout<<sm<<"\n";
        //cout<<brr[it][0]<<" "<<brr[it][1]<<"\n";
        //cout<<brr[it1][0]<<" "<<brr[it1][1]<<"\n";
        m++;
    }




        cnt=0;
        l=0;
        m=0;
        sm=0;


    for(i=0;i<k;i++)
    {
        if(cnt==0)
        {
            if(arr[i+1]<=arr[i])
            {
                cnt=1;
                save=i;
            }
        }
        else
        {
            if(i==k-1 || arr[i+1]>arr[i])
            {
                cnt=0;
                crr[l][0]=save;
                crr[l][1]=i;
                l++;
                sm=sm+((i-save)*(i-save+1))/2;
            }
        }
    }
    it=0;
    it1=l-1;
    cout<<ans[m]-sm <<"\n";

    //cout<<"\n\n"<<sm<<"\n";
    //cout<<crr[it][0]<<" "<<crr[it][1]<<"\n";
    //cout<<crr[it1][0]<<" "<<crr[it1][1]<<"\n";
    m++;
    for(i=1;i+k-1<n;i++)
    {
        if(i>crr[it][1])
        {
            //cout<<"cn1\n";
            it++;
        }
        else if(i>=crr[it][0] && i<=crr[it][1])
        {
            //cout<<"cn2\n";
            sm=sm-((crr[it][1]-crr[it][0])*(crr[it][1]-crr[it][0]+1))/2;
            sm=sm+((crr[it][1]-i)*(crr[it][1]-i+1))/2;
            crr[it][0]=i;
        }
        if(i+k-1==crr[it1][1]+1 && arr[i+k-1]<=arr[crr[it1][1]])
        {
            //cout<<"cn3\n";
            sm=sm-((crr[it1][1]-crr[it1][0])*(crr[it1][1]-crr[it1][0]+1))/2;
            sm=sm+((i+k-1-crr[it1][0])*(i+k-1-crr[it1][0]+1))/2;
            crr[it1][1]=i+k-1;
        }
        else if(arr[i+k-1]<=arr[i+k-2])
        {
            //cout<<"cn4\n";
            crr[l][0]=i+k-2;
            crr[l][1]=i+k-1;
            l++;
            it1=l-1;
            sm=sm+((crr[it1][1]-crr[it1][0])*(crr[it1][1]-crr[it1][0]+1))/2;
        }

        cout<<ans[m]-sm <<"\n";

    //cout<<sm<<"\n";
    //cout<<crr[it][0]<<" "<<crr[it][1]<<"\n";
    //cout<<crr[it1][0]<<" "<<crr[it1][1]<<"\n";
        m++;
    }


    return 0;
}
