#include<iostream>
#include<vector>
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

int main(){
    // Activity Selection
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    cout<<"Max activity = " << activitySelection(start, end);
    return 0;
}