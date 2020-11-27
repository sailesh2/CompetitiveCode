class TweetCounts {
private:
    map<string, map<int,int> > minTweetMp;
    map<string, map<int,int> >::iterator minTweetMpIt;
    map<string, map<int,int> > dayTweetMp;
    map<string, map<int,int> >::iterator dayTweetMpIt;
    map<string, map<int,int> > hrTweetMp;
    map<string, map<int,int> >::iterator hrTweetMpIt;

    void storeMinTweet(string tweetName, int time){
        int m = time/60;
        minTweetMpIt = minTweetMp.find(tweetName);
        map<int,int> minMap;
        map<int,int>::iterator minMapIt;
        if(minTweetMpIt != minTweetMp.end()){
            minMap=minTweetMpIt->second;
            minTweetMp.erase(minTweetMpIt);
        }
        minMapIt=minMap.find(m);
        int v=0;
        if(minMapIt!=minMap.end()){
            v=minMapIt->second;
            minMap.erase(minMapIt);
        }
        v++;
        minMap.insert(make_pair(m,v));
        minTweetMp.insert(make_pair(tweetName,minMap));
    }

    void storeHourTweet(string tweetName, int time){
        int h = time/(60*60);
        hrTweetMpIt = hrTweetMp.find(tweetName);
        map<int,int> hrMap;
        map<int,int>::iterator hrMapIt;
        if(hrTweetMpIt != hrTweetMp.end()){
            hrMap=hrTweetMpIt->second;
            hrTweetMp.erase(hrTweetMpIt);
        }
        hrMapIt=hrMap.find(h);
        int v=0;
        if(hrMapIt!=hrMap.end()){
            v=hrMapIt->second;
            hrMap.erase(hrMapIt);
        }
        v++;
        hrMap.insert(make_pair(h,v));
        hrTweetMp.insert(make_pair(tweetName,hrMap));
    }

    void storeDayTweet(string tweetName, int time){
        int d = time/(60*60*24);
        dayTweetMpIt = dayTweetMp.find(tweetName);
        map<int,int> dayMap;
        map<int,int>::iterator dayMapIt;
        if(dayTweetMpIt != dayTweetMp.end()){
            dayMap=dayTweetMpIt->second;
            dayTweetMp.erase(dayTweetMpIt);
        }
        dayMapIt=dayMap.find(d);
        int v=0;
        if(dayMapIt!=dayMap.end()){
            v=dayMapIt->second;
            dayMap.erase(dayMapIt);
        }
        v++;
        dayMap.insert(make_pair(d,v));
        dayTweetMp.insert(make_pair(tweetName,dayMap));
    }

    vector<int> tweetCount(string tweetName, int sm,int em, map<string, map<int,int> > tm, map<string, map<int,int> >::iterator tmIt){
            vector<int> ans;

            for(int i=sm;i<=em;i++){
                map<int,int> minMap;
                map<int,int>::iterator minMapIt;
                int v=0;
                tmIt=tm.find(tweetName);
                if(tmIt!=tm.end()){
                    minMap=tmIt->second;
                }
                minMapIt=minMap.find(i);
                if(minMapIt!=minMap.end()){
                    v=minMapIt->second;
                }
                ans.push_back(v);
            }

            return ans;
    }
public:
    TweetCounts() {

    }

    void recordTweet(string tweetName, int time) {
        storeMinTweet(tweetName,time);
        storeHourTweet(tweetName,time);
        storeDayTweet(tweetName,time);
    }

    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        if(freq[0]=='m'){
            int sm=startTime/60;
            int em=endTime/60;
            return tweetCount(sm,em,tweetName,minTweetMp, minTweetMpIt);
        }else if(freq[0]=='h'){
            int sm=startTime/(60*60);
            int em=endTime/(60*60);
            return tweetCount(sm,em,tweetName,hrTweetMp, hrTweetMpIt);

        }else{
            int sm=startTime/(60*60*24);
            int em=endTime/(60*60*24);
            return tweetCount(sm,em,tweetName,dayTweetMp, dayTweetMpIt);

        }
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
