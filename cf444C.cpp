#include<bits/stdc++.h>

using namespace std;

int main(){
    int arr[25];
    for(int i=1;i<=24;i++){
        cin>>arr[i];
    }

    int cnt=0;
    if((arr[1]==arr[3] && arr[3]==arr[6] && arr[6]==arr[8])  && (arr[2]==arr[4] && arr[4]==arr[22] && arr[22]==arr[24])
      &&(arr[9]==arr[11] && arr[11]==arr[21] && arr[21]==arr[23]) && (arr[5]==arr[7] && arr[7]==arr[10] && arr[10]==arr[12])
      &&(arr[13]==arr[14] && arr[14]==arr[15] && arr[15]==arr[16]) && (arr[17]==arr[18] && arr[18]==arr[19] && arr[19]==arr[20]))
    {
        cout<<"YES";
    }
    else if((arr[1]==arr[3] && arr[3]==arr[21] && arr[21]==arr[23]) && (arr[2]==arr[4] && arr[4]==arr[10] && arr[10]==arr[12])
      &&(arr[9]==arr[11] && arr[11]==arr[6] && arr[6]==arr[8]) &&(arr[5]==arr[7] && arr[7]==arr[22] && arr[22]==arr[24])
      &&(arr[13]==arr[14] && arr[14]==arr[15] && arr[15]==arr[16]) && (arr[17]==arr[18] && arr[18]==arr[19] && arr[19]==arr[20]))
    {
        cout<<"YES";
    }
    else if((arr[5]==arr[7] && arr[7]==arr[2] && arr[2]==arr[4]) && (arr[9]==arr[11] && arr[11]==arr[6] && arr[6]==arr[8])
      &&(arr[1]==arr[3] && arr[3]==arr[21] && arr[21]==arr[23]) &&(arr[22] ==arr[24] && arr[24]==arr[10] && arr[10]==arr[12])
      &&(arr[13]==arr[14] && arr[14]==arr[15] && arr[15]==arr[16]) && (arr[17]==arr[18] && arr[18]==arr[19] && arr[19]==arr[20]))
    {
        cout<<"YES";
    }
    else if((arr[5]==arr[7] && arr[7]==arr[21] && arr[21]==arr[23]) && (arr[9]==arr[11] && arr[11]==arr[10] && arr[10]==arr[12])
       &&(arr[1]==arr[3] && arr[3]==arr[2] && arr[2]==arr[4]) && (arr[22]==arr[24] && arr[24]==arr[6] && arr[6]==arr[8])
       &&(arr[13]==arr[14] && arr[14]==arr[15] && arr[15]==arr[16]) && (arr[17]==arr[18] && arr[18]==arr[19] && arr[19]==arr[20]))
    {
        cout<<"YES";
    }
    else if((arr[3]==arr[4] && arr[4]==arr[13] && arr[13]==arr[15]) && (arr[14]==arr[16] && arr[16]==arr[11] && arr[11]==arr[12])
       && (arr[9]==arr[10] && arr[10]==arr[18] && arr[18]==arr[20]) && (arr[17]==arr[19] && arr[19]==arr[1] && arr[1]==arr[2])
       && (arr[5]==arr[6] && arr[6]==arr[7] && arr[7]==arr[8]) && (arr[21]==arr[22] && arr[22]==arr[23] && arr[23]==arr[24]))
    {
        cout<<"YES";
    }
   else if((arr[3]==arr[4] && arr[4]==arr[18] && arr[18]==arr[20]) && (arr[17]==arr[19] && arr[19]==arr[11] && arr[11]==arr[12])
       && (arr[9]==arr[10] && arr[10]==arr[13] && arr[13]==arr[15]) && (arr[14]==arr[16] && arr[16]==arr[1] && arr[1]==arr[2])
       && (arr[5]==arr[6] && arr[6]==arr[7] && arr[7]==arr[8]) && (arr[21]==arr[22] && arr[22]==arr[23] && arr[23]==arr[24]))
    {
        cout<<"YES";
    }
    else if((arr[1]==arr[2] && arr[2]==arr[14] && arr[14]==arr[16]) && (arr[13]==arr[15] && arr[15]==arr[9] && arr[9]==arr[10])
        && (arr[11]==arr[12] && arr[12]==arr[17] && arr[17]==arr[19]) && (arr[18]==arr[20] && arr[20]==arr[3] && arr[3]==arr[4])
        && (arr[5]==arr[6] && arr[6]==arr[7] && arr[7]==arr[8]) && (arr[21]==arr[22] && arr[22]==arr[23] && arr[23]==arr[24]))

    {
        cout<<"YES";
    }
    else if((arr[1]==arr[2] && arr[2]==arr[17] && arr[17] == arr[19]) && (arr[18]==arr[20] && arr[20]==arr[9] && arr[9]==arr[10])
         &&(arr[11]=arr[12] && arr[12]==arr[14] && arr[14]==arr[16]) && (arr[13]==arr[15] && arr[15]==arr[3] && arr[3]==arr[4])
         && (arr[5]==arr[6] && arr[6]==arr[7] && arr[7]==arr[8]) && (arr[21]==arr[22] && arr[22]==arr[23] && arr[23]==arr[24]))

    {
        cout<<"YES";
    }
    else if((arr[5]==arr[6] && arr[6]==arr[15] && arr[15]==arr[16]) && (arr[13]==arr[14] && arr[14]==arr[23] && arr[23]==arr[24])
        && (arr[21]==arr[22] && arr[22]==arr[19] && arr[19]==arr[20]) && (arr[17]==arr[18] && arr[18]==arr[7] && arr[7]==arr[8])
        && (arr[1]==arr[2] && arr[2]==arr[3] && arr[3]==arr[4]) && (arr[9]==arr[10] && arr[10]==arr[11] && arr[11]==arr[12]))
    {
        cout<<"YES";
    }
    else if((arr[5]==arr[6] && arr[6]==arr[19] && arr[19]==arr[20]) && (arr[17]==arr[18] && arr[18] ==arr[23] && arr[23]==arr[24])
        && (arr[21]==arr[22] && arr[22] ==arr[15] && arr[15]==arr[16]) && (arr[13]==arr[14] && arr[14]==arr[7] && arr[7]==arr[8])
        && (arr[1]==arr[2] && arr[2]==arr[3] && arr[3]==arr[4]) && (arr[9]==arr[10] && arr[10]==arr[11] && arr[11]==arr[12]))
    {
        cout<<"YES";
    }
    else if((arr[7]==arr[8] && arr[8]==arr[13] && arr[13]==arr[14]) && (arr[15]==arr[16] && arr[16]==arr[21] && arr[21]==arr[22])
       &&(arr[23]==arr[24] && arr[24]==arr[17] && arr[17]==arr[18]) && (arr[19]==arr[20] && arr[20]==arr[5] && arr[5]==arr[6])
       && (arr[1]==arr[2] && arr[2]==arr[3] && arr[3]==arr[4]) && (arr[9]==arr[10] && arr[10]==arr[11] && arr[11]==arr[12]))

    {
       cout<<"YES";
    }
    else if((arr[7]==arr[8] && arr[8]==arr[17] && arr[17]==arr[18]) && (arr[19]==arr[20] && arr[20]==arr[21] && arr[21]==arr[22])
    && (arr[23]==arr[24] && arr[24]==arr[13] && arr[13]==arr[14]) && (arr[15]==arr[16] && arr[16]==arr[5] && arr[5]==arr[6])
        && (arr[1]==arr[2] && arr[2]==arr[3] && arr[3]==arr[4]) && (arr[9]==arr[10] && arr[10]==arr[11] && arr[11]==arr[12]))

    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }

    return 0;
}
