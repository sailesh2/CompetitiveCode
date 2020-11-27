#include<bits/stdc++.h>

using namespace std;

vector<pair<char,int> > leftFilter;
vector<pair<char,int> > rightFilter;

vector<int> leftRemains;
vector<int> rightRemains;

vector<pair<int,int> > matchPairs;

vector<int> leftQuestions;
vector<int> rightQuestions;

string leftBoots,rightBoots;


bool bootComp(pair<char,int> boot1, pair<char,int> boot2){
    return boot1.first<boot2.first;
}


pair<vector<pair<char,int> >, vector<int> > preProcess(string boots){
    vector<pair<char,int> > bootFilter;
    vector<int> bootQuestions;

    for(int i=0;i<boots.length();i++){
        if(boots[i]=='?'){
            bootQuestions.push_back(i);
        }else{
            bootFilter.push_back(make_pair(boots[i],i));
        }
    }

    return make_pair(bootFilter,bootQuestions);
}

void startPreProcess(){
    pair<vector<pair<char,int> >, vector<int> > prePrcessLeft = preProcess(leftBoots);
    pair<vector<pair<char,int> >, vector<int> > prePrcessRight = preProcess(rightBoots);

    leftFilter = prePrcessLeft.first;
    leftQuestions = prePrcessLeft.second;

    rightFilter = prePrcessRight.first;
    rightQuestions = prePrcessRight.second;
}

void processMatches(){

    int leftI=0,rightI=0,leftE=leftFilter.size(),rightE=rightFilter.size();
    while(leftI<leftE && rightI<rightE){
        while(leftI<leftE && leftFilter[leftI].first<rightFilter[rightI].first){

            leftRemains.push_back(leftFilter[leftI].second);
            leftI++;
        }
        if(leftI<leftE){

            if(leftFilter[leftI].first==rightFilter[rightI].first){
                matchPairs.push_back(make_pair(leftFilter[leftI].second,rightFilter[rightI].second));
                leftI++;
                rightI++;
                continue;
            }

        }else{
            break;
        }

        while(rightI<rightE && rightFilter[rightI].first<leftFilter[leftI].first){

            rightRemains.push_back(rightFilter[rightI].second);
            rightI++;
        }
        if(rightI<rightE){

            if(leftFilter[leftI].first==rightFilter[rightI].first){
                matchPairs.push_back(make_pair(leftFilter[leftI].second,rightFilter[rightI].second));

                leftI++;
                rightI++;
                continue;
            }

        }else{
            break;
        }
    }

    while(leftI<leftE){
        leftRemains.push_back(leftFilter[leftI].second);
        leftI++;

    }

    while(rightI<rightE){
        rightRemains.push_back(rightFilter[rightI].second);
        rightI++;

    }

}

void processRemains(){
    int rightQuestionStart=0;
    int leftQuestionStart=0;

    for(int i=0;i<min(leftRemains.size(),rightQuestions.size());i++){
        matchPairs.push_back(make_pair(leftRemains[i],rightQuestions[i]));
        rightQuestionStart=i+1;
    }

    for(int i=0;i<min(rightRemains.size(),leftQuestions.size());i++){
        matchPairs.push_back(make_pair(leftQuestions[i],rightRemains[i]));
        leftQuestionStart=i+1;
    }

    for(int i=leftQuestionStart,j=rightQuestionStart;i<leftQuestions.size() && j<rightQuestions.size();i++,j++){
        matchPairs.push_back(make_pair(leftQuestions[i],rightQuestions[j]));
    }

}

int main(){
int n;
cin>>n;
    cin>>leftBoots>>rightBoots;
    startPreProcess();

    sort(leftFilter.begin(),leftFilter.end(),bootComp);
    sort(rightFilter.begin(),rightFilter.end(),bootComp);

    processMatches();

    processRemains();

    cout<<matchPairs.size()<<"\n";
    for(int i=0;i<matchPairs.size();i++){
        cout<<matchPairs[i].first+1<<" "<<matchPairs[i].second+1<<"\n";
    }
    return 0;
}
