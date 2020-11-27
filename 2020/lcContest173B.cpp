struct Resturant{
    int id;
    int rating;
    int vegan;
    int price;
    int distance;
};

bool compRest(struct Resturant a, struct Resturant b){
    if(a.rating == b.rating)
        return a.id>b.id;
    return a.rating>b.rating;
}

class Solution {
private:
    vector<Resturant> convertIntoResturant(vector<vector<int>>& data){
        vector<Resturant> resturants;
        for(int i=0;i<data.size();i++){
            struct Resturant res;
            res.id=data[i][0];
            res.rating=data[i][1];
            res.vegan=data[i][2];
            res.price=data[i][3];
            res.distance=data[i][4];

            resturants.push_back(res);
        }

        return resturants;
    }

    vector<Resturant> filter(vector<Resturant> resturants, int veganFriendly, int maxPrice, int maxDistance){
        vector<Resturant> filteredRes;
        for(int i=0;i<resturants.size();i++){
            if(veganFriendly==1){
                if(resturants[i].vegan==1 && resturants[i].price<=maxPrice && resturants[i].distance<=maxDistance){
                    filteredRes.push_back(resturants[i]);
                }
            }else{
                if(resturants[i].price<=maxPrice && resturants[i].distance<=maxDistance){
                    filteredRes.push_back(resturants[i]);
                }
            }
        }

        return filteredRes;
    }

    vector<int> convertIntoID(vector<Resturant> res){
        vector<int> resIds;
        for(int i=0;i<res.size();i++){
            resIds.push_back(res[i].id);
        }
        return resIds;
    }

public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<Resturant> res = filter(convertIntoResturant(restaurants),veganFriendly,maxPrice,maxDistance);
        sort(res.begin(),res.end(),compRest);
        return convertIntoID(res);
    }
};
