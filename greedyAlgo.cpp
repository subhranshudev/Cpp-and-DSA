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

bool compare2(pair<int, int> p1, pair<int, int> p2){
    int cost1, cost2;
    cost1 = p1.first / p1.second;
    cost2 = p2.first / p2.second;

    return cost1 > cost2; // sort in descending order , i.e. more valued items stored first
}

int fractionalKnapsack(vector<int> value, vector<int> weight, int w){   // TC = O(n logn)
    int n = value.size();
    int knapsackWeight = w;
    vector<pair<double, int>> items(n, make_pair(0, 0));

    for(int i = 0; i< n; i++){
        items[i] = make_pair(value[i], weight[i]);
    }

    sort(items.begin(), items.end(), compare2);

    int maxValue = 0;
    for(int i = 0; i< n; i++){
        double itemValue = items[i].first;
        int itemWeight = items[i].second;

        if(itemWeight <= knapsackWeight){
            knapsackWeight -= itemWeight;
            maxValue += itemValue;
        } else{
            double itemValuePerUnit = itemValue/itemWeight;
            itemWeight = knapsackWeight;
            itemValue = itemWeight*itemValuePerUnit;
            
            knapsackWeight = 0;
            maxValue += itemValue;
            break;
        }
    }

    return maxValue;

}

int main(){
/*    // Activity Selection
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    cout<<"Max activity = " << activitySelection(start, end);
*/

/*    vector<int> start = {0, 1, 2};
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
*/

    // Fractional Knapsack
    vector<int> value = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int w = 50;
    cout<< "Max Value = "<< fractionalKnapsack(value, weight, w);

    return 0;
}