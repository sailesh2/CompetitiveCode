#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int r,g,b;
    cin>>r>>g>>b;

    long long int vr[r];
    long long int vg[g];
    long long int vb[b];

    for(long long int i=0;i<r;i++)
        cin>>vr[i];
    for(long long int i=0;i<g;i++)
        cin>>vg[i];
    for(long long int i=0;i<b;i++)
        cin>>vb[i];

    sort(vr,vr+r);
    sort(vg,vg+g);
    sort(vb,vb+b);

    long long int e=0,p=0;
    long long int er=r-1;
    long long int eg=g-1;
    long long int eb=b-1;
    while(1){
        e=0;
        if(er>=0)
            e++;
        if(eg>=0)
            e++;
        if(eb>=0)
            e++;
        if(e<=1)
            break;

        if(er>=0 && eg>=0 && eb>=0){
            if(vr[er]>vg[eg] && vr[er]>vb[eb]){
                if(vg[eg]>vb[eb]){
                    p=p+vr[er]*vg[eg];
                    eg--;
                }else{
                    p=p+vr[er]*vb[eb];
                    eb--;
                }
                er--;
            }else if(vg[eg]>vr[er] && vg[eg]>vb[eb]){
                if(vr[er]>vb[eb]){
                    p=p+vg[eg]*vr[er];
                    er--;
                }else{
                    p=p+vg[eg]*vb[eb];
                    eb--;
                }
                eg--;
            }else{
                if(vr[er]>vg[eg]){
                    p=p+vb[eb]*vr[er];
                    er--;
                }else{
                    p=p+vb[eb]*vg[eg];
                    eg--;
                }
                eb--;
            }
        }else if(er>=0 && eg>=0){
            p=p+vr[er]*vg[eg];
            eg--;
            er--;
        }else if(eg>=0 && eb>=0){
            p=p+vg[eg]*vb[eb];
            eg--;
            eb--;
        }else{
            p=p+vr[er]*vb[eb];
            eb--;
            er--;
        }
    }
    cout<<p;
    return 0;
}
