class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {

        vector<int> people;
        for(int i=0;i<num_people;i++)
            people.push_back(0);
        int ctr=1;
        int prev=0;
        int sm=1;
        int ind=0;
        while(sm<candies){
            people[ind]=people[ind]+ctr;
            ctr++;
            prev=sm;
            sm=sm+ctr;
            ind=(ind+1)%num_people;
        }

        people[ind]=people[ind]+candies-prev;
        return people;
    }
};
