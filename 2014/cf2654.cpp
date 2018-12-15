#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int i,k=0,x,y,z,j,cnt=0;
    int arr[8][3],brr[8][3];
    int drr[100];
    int crr[100]={0};
    for(i=0;i<8;i++)
    {
        cin>>x>>y>>z;
        brr[i][0]=x;
        brr[i][1]=y;
        brr[i][2]=z;
        if(crr[x]==0)
        {
            drr[k++]=x;
        }
        crr[x]++;
        if(crr[y]==0)
        {
            drr[k++]=y;
        }
        crr[y]++;
        if(crr[z]==0)
        {
            drr[k++]=z;
        }
        crr[z]++;
    }

    if(cnt==1)
        cout<<"NO";
    else
    {
        sort(drr,drr+k);
        switch(k)
        {
        case 2:
            if(crr[drr[0]]==12 && crr[drr[1]]==12)
            {
                cout<<"YES\n";
                for(i=0;i<4;i++)
                {
                    arr[i][0]=drr[0];
                }
                for(;i<8;i++)
                {
                    arr[i][0]=drr[1];
                }
                for(i=0;i<2;i++)
                {
                    arr[i][1]=drr[0];
                }
                for(;i<4;i++)
                {
                    arr[i][1]=drr[1];
                }
                for(;i<6;i++)
                {
                    arr[i][1]=drr[0];
                }
                for(;i<8;i++)
                {
                    arr[i][1]=drr[1];
                }
                for(i=0;i<8;i=i+2)
                {
                    arr[i][2]=drr[0];
                }
                for(i=1;i<8;i=i+2)
                {
                    arr[i][2]=drr[1];
                }
                for(i=0;i<8;i++)
                {
                    cout<<arr[i][0]<<" "<<arr[i][1]<<" "<<arr[i][2]<<"\n";
                }
            }
            else
                cout<<"NO";
            break;
        case 3:
            if(crr[drr[0]]==4 && crr[drr[1]]==8 && crr[drr[2]]==12)
            {
                cout<<"YES\n";
                for(i=0;i<4;i++)
                {
                    arr[i][0]=drr[0];
                }
                for(;i<8;i++)
                {
                    arr[i][0]=drr[2];
                }
                for(i=0;i<2;i++)
                {
                    arr[i][1]=drr[1];
                }
                for(;i<4;i++)
                {
                    arr[i][1]=drr[2];
                }

                for(;i<6;i++)
                {
                    arr[i][1]=drr[1];
                }

                for(;i<8;i++)
                {
                    arr[i][1]=drr[2];
                }
                for(i=0;i<8;i=i+2)
                {
                    arr[i][2]=drr[1];
                }
                for(i=1;i<8;i=i+2)
                {
                    arr[i][2]=drr[2];
                }

                for(i=0;i<8;i++)
                {
                    cout<<arr[i][0]<<" "<<arr[i][1]<<" "<<arr[i][2]<<"\n";
                }
            }
            else
                cout<<"NO";
            break;
        case 4:
            if(crr[drr[0]]==4 && crr[drr[1]]==4 && crr[drr[2]]==8 && crr[drr[3]]==8)
            {
                cout<<"YES\n";
                for(i=0;i<4;i++)
                {
                    arr[i][0]=drr[0];
                }
                for(;i<8;i++)
                {
                    arr[i][0]=drr[3];
                }
                for(i=0;i<2;i++)
                {
                    arr[i][1]=drr[1];
                }
                for(;i<4;i++)
                {
                    arr[i][1]=drr[2];
                }

                for(;i<6;i++)
                {
                    arr[i][1]=drr[1];
                }

                for(;i<8;i++)
                {
                    arr[i][1]=drr[2];
                }
                for(i=0;i<8;i=i+2)
                {
                    arr[i][2]=drr[2];
                }
                for(i=1;i<8;i=i+2)
                {
                    arr[i][2]=drr[3];
                }

                for(i=0;i<8;i++)
                {
                    cout<<arr[i][0]<<" "<<arr[i][1]<<" "<<arr[i][2]<<"\n";
                }
            }
            else
                cout<<"NO";
            break;
        case 5:
            if(crr[drr[0]]==4 && crr[drr[1]]==4 && crr[drr[2]]==4 && crr[drr[3]]==4 && crr[drr[4]]==8)
            {
                cout<<"YES\n";
                for(i=0;i<4;i++)
                {
                    arr[i][0]=drr[0];
                }
                for(;i<8;i++)
                {
                    arr[i][0]=drr[4];
                }
                for(i=0;i<2;i++)
                {
                    arr[i][1]=drr[1];
                }
                for(;i<4;i++)
                {
                    arr[i][1]=drr[2];
                }

                for(;i<6;i++)
                {
                    arr[i][1]=drr[1];
                }

                for(;i<8;i++)
                {
                    arr[i][1]=drr[2];
                }
                for(i=0;i<8;i=i+2)
                {
                    arr[i][2]=drr[3];
                }
                for(i=1;i<8;i=i+2)
                {
                    arr[i][2]=drr[4];
                }

                for(i=0;i<8;i++)
                {
                    cout<<arr[i][0]<<" "<<arr[i][1]<<" "<<arr[i][2]<<"\n";
                }
            }
            else
                cout<<"NO";
            break;
        case 6:
            if(crr[drr[0]]==4 && crr[drr[1]]==4 && crr[drr[2]]==4 && crr[drr[3]]==4 && crr[drr[4]]==4 && crr[drr[5]]==4)
            {
                cout<<"YES\n";
                for(i=0;i<4;i++)
                {
                    arr[i][0]=drr[0];
                }
                for(;i<8;i++)
                {
                    arr[i][0]=drr[1];
                }
                for(i=0;i<2;i++)
                {
                    arr[i][1]=drr[2];
                }
                for(;i<4;i++)
                {
                    arr[i][1]=drr[3];
                }

                for(;i<6;i++)
                {
                    arr[i][1]=drr[2];
                }

                for(;i<8;i++)
                {
                    arr[i][1]=drr[3];
                }
                for(i=0;i<8;i=i+2)
                {
                    arr[i][2]=drr[4];
                }
                for(i=1;i<8;i=i+2)
                {
                    arr[i][2]=drr[5];
                }

                for(i=0;i<8;i++)
                {
                    cout<<arr[i][0]<<" "<<arr[i][1]<<" "<<arr[i][2]<<"\n";
                }
            }
            else
                cout<<"NO";
            break;
        default:
            cout<<"NO";
            break;
        }
    }
    return 0;
}
