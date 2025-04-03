#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//1) Greedy Fractional Knapsack Algorithm
int fractionalKnapsack(int W,vector<pair<int,int>>& items){
    vector<pair<double,pair<int,int>>> ratios;
    int steps=0;
    for(int i=0;i<items.size();i++){  
        double ratio=(double)items[i].second/items[i].first;  
        ratios.push_back({ratio,items[i]});  
        steps++;  
    }
    
    sort(ratios.begin(),ratios.end(),[&steps](auto& a,auto& b){
        steps++;
        return a.first > b.first;
    });
    
    double totalValue=0.0;
    for(int i=0;i< ratios.size();i++){  
        int weight=ratios[i].second.first;  
        int value=ratios[i].second.second;  
        steps++;  
        if(W>=weight){  
            W -= weight;  
            totalValue += value;  
        } 
        else{  
            totalValue += ratios[i].first*W;  
            break;  
        }  
    }
    
    cout<<"Total value="<<totalValue<<endl;
    return steps;
}

//2) 0/1 Knapsack using Dynamic Programming
int knapsack01(int W,vector<pair<int,int>>& items){
    int n=items.size();
    vector<vector<int>> dp(n+1,vector<int>(W+1,0));
    int steps=0;
    for(int i=1;i<=n;i++){
        for(int w=1;w<=W;w++){
            steps++;
            if(items[i-1].first <= w)
                dp[i][w]=max(dp[i-1][w],dp[i-1][w-items[i-1].first] + items[i-1].second);
            else
                dp[i][w]=dp[i-1][w];
        }
    }
    cout<<"Total value="<<dp[n][W]<<endl;
    return steps;
}

void analyzeKnapsack(){
    vector<int> capacities ={10,20,30,40};
    vector<pair<int,int>> items ={{2,10},{3,20},{5,30},{7,40},{1,5}};
    
    for(int i=0;i<capacities.size();i++){
        int W= capacities[i];
        cout<<"=================== Capacity: "<<W<<" ===================\n";
        cout<<"Greedy Knapsack(Fractional): "<<fractionalKnapsack(W,items) <<" steps\n";
        cout<<"0/1 Knapsack(DP): " <<knapsack01(W,items) <<" steps \n";
        cout<<"========================================================\n\n";
    }
}

int main(){
    analyzeKnapsack();
    return 0;
}
