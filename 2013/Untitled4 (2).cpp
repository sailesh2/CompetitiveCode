#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <ctime>
#include <cstdio>
#include<conio.h>

using namespace std;
const int N = 200000;
typedef long long int64;
typedef pair<int, int64> P;
int arr[N][2], c, n;

int main() {
    int cl = clock();
    for(scanf("%d", &c); c--; ) {
        scanf("%d", &n);
        for(int i = 0; i < n; i ++) {
            scanf("%d", &arr[i][0]);
        }
        for(int i = 0; i < n;  i ++) {
            scanf("%d", &arr[i][1]);
        }
        set<P> st;
        st.insert(P(0, 0));
        for(int i = 0; i < n; i ++) {
            set<P>::iterator it = st.lower_bound(P(arr[i][0], 0));
            it --;
            P new_item(arr[i][0], it->second + arr[i][1]);
            it ++;
            bool valid = true;
            vector<P> erase_list;
            while(it != st.end()) {
                if(it->first == arr[i][0] && it->second >= new_item.second) {
                    valid = false;
                    break;
                } else if(it->second <= new_item.second) {
                    erase_list.push_back(*it);
                    it ++;
                } else {
                    break;
                }
            }
            for(vector<P>::iterator it = erase_list.begin(); it != erase_list.end(); it ++) {
                st.erase(*it);
            }
            if(valid) {
                st.insert(new_item);
            }
        }
        cout << st.rbegin()->second << endl;
    }
    cerr << (clock() - cl) * 0.001 << endl;
    getch();
    return 0;
}
