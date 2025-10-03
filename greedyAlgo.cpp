#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int activitySelection(vector<int> start, vector<int> end){
    // Sort according to end time -> already done in question
    // A0 select
    // select no-overlapping
    cout<< "Selecting A0 \n";
    int count = 1;
    int currEndTime = end[0];
    int n = start.size();

    for(int i = 1; i < n; i++){
        if(currEndTime <= start[i]){
            cout<< "Selecting A"<< i<< endl;
            count++;
            currEndTime = end[i];
        }
    }

    return count;
}

bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.second < p2.second;   // ascending
    // return p1.second > p2.second;   // descending
}

int main(){
/*    // Activity Selection
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    cout<<"Max activity = " << activitySelection(start, end);
*/

    vector<int> start = {0, 1, 2};
    vector<int> end = {9, 2, 4};

    vector<pair<int, int>> activity(3, make_pair(0, 0));
    activity[0] = make_pair(0, 9);
    activity[1] = make_pair(1, 2);
    activity[2] = make_pair(2, 4);

    for(int i = 0; i< activity.size(); i++){
        cout<< "A"<< i << ": "<< activity[i].first << ", "<< activity[i].second<< endl;
    }
    cout<< "------sorted------ \n";

    sort(activity.begin(), activity.end(), compare);
    for(int i = 0; i< activity.size(); i++){
        cout<< "A"<< i << ": "<< activity[i].first << ", "<< activity[i].second<< endl;
    }

    return 0;
}