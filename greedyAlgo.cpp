#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
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

    double maxValue = 0;
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

int minAbsoluteDifferenceSum(vector<int> v1, vector<int> v2){
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int n = v1.size();
    int absDiffSum = 0;
    for(int i = 0; i< n; i++){
        cout<< "("<< v1[i]<< ","<< v2[i]<< ")"<< endl;
        absDiffSum += abs(v1[i]-v2[i]);
    }

    return absDiffSum;
}

bool compare3(pair<int, int> p1, pair<int, int>p2){
    return p1.second < p2.second;   // ascending
}

int maxChainLength(vector<pair<int, int>> p){
    int n = p.size();
    sort(p.begin(), p.end(), compare3);

    cout<< "Pair: "<< p[0].first<< ","<< p[0].second<< endl;
    int currEnd = p[0].second;
    int length = 1;
   
    for(int i = 1; i< n; i++){
        if(currEnd < p[i].first){
            cout<< "Pair: "<< p[i].first<<","<< p[i].second<<endl;
            length++;
            currEnd = p[i].second;
        }
    }

    return length;
}

int getMinChange(vector<int> coins, int V){  //  TC = O(n)
    int noOfCoins = 0;
    int n = coins.size();
    for(int i = n-1; i>= 0 && V > 0; i--){
        int currCoinVal = coins[i];
        if(V >= currCoinVal){
            noOfCoins += V/currCoinVal;
            V = V % currCoinVal;
        }
    }

    return noOfCoins;
}

bool compare4(pair<int, int> job1, pair<int, int> job2){
    return job1.second > job2.second;
}

int maxProfit(vector<pair<int, int>> jobs){
    // first-> deadline , second-> profit
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), compare4);

    int profit = jobs[0].second;

    int safeDeadline = 2;

    for(int i = 1; i< n; i++){
        int currDeadline = jobs[i].first;
        int currProfit = jobs[i].second;

        if(currDeadline >= safeDeadline){
            // Do that job
            safeDeadline++;
            profit += currProfit;
        }
    }

    return profit;
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

/*    // Fractional Knapsack
    vector<int> value = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int w = 50;
    cout<< "Max Value = "<< fractionalKnapsack(value, weight, w);
*/

/*    // Min absolute Difference pairs  
    vector<int> A = {1, 2, 3};
    vector<int> B = {2, 1, 3};
    cout<< "Min abs diff sum = " << minAbsoluteDifferenceSum(A, B);
*/

/*    // Max chain length
    int n = 5;
    vector<pair<int, int>> pairs(n , make_pair(0, 0));
    pairs[0] = make_pair(5, 24);
    pairs[1] = make_pair(39, 60);
    pairs[2] = make_pair(5, 28);
    pairs[3] = make_pair(27, 40);
    pairs[4] = make_pair(50, 90);

    cout<< "Max Chain length = "<< maxChainLength(pairs)<< endl;
*/

/*    // Indian Coins; Get Min Change
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 2000};
    int V = 1099;
    cout<<"Min Change = " <<getMinChange(coins, V)<< endl;
*/

/*    // Job Sequencing Problem
    vector<pair<int, int>> jobs(4, make_pair(0, 0));
    // first-> deadline , second-> profit
    jobs[0] = make_pair(4, 20);
    jobs[1] = make_pair(1, 10);
    jobs[2] = make_pair(1, 40);
    jobs[3] = make_pair(1, 30);

    cout<<"Max Profit = "<< maxProfit(jobs)<< endl;
*/ 

 /* // Random; verifying , clearing doubts
    // cout<< "to stirng = "<< to_string(97-1);
    char ch = 18 + 'a';
    cout<< ch<< endl;
    // string ans = "def";
    // ans = ch + ans;
    // cout<< ans;
*/
      // Smallest string with given numeric value --> LC-1663
        int k = 73, n = 5;
        k = k-(n-1);  // numeric value for last position if all other places are filled with 'a'
        char ch;
        string ans = "";
        while(n > 0){
            if(k == 0){
                ch = 'a';
                ans = ch+ans;
                n--;
            }else if(k> 0 && k <= 26){
                ch = (k-1) + 'a';
                ans = ch + ans;
                k = 0;
                n--;
            } else{
                ch = 'z';
                ans = ch + ans;
                k = k-25; // k = k-26+1
                n--;
            }
        }

        cout<< "ans string = "<< ans<< endl;

    return 0;
}