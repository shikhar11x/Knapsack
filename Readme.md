# Knapsack Algorithm Analysis

## Overview

This program analyzes two variations of the Knapsack algorithm by calculating the number of steps required in different scenarios:

- **Greedy Fractional Knapsack**: Uses a greedy approach to maximize the total value by taking fractions of items.
- **0/1 Knapsack (Dynamic Programming)**: Uses dynamic programming to find the optimal subset of items without allowing fractional selection.

## How It Works

1. The program defines items with weights and values.
2. It runs both the **Greedy Fractional Knapsack** and **0/1 Knapsack** algorithms on different capacities.
3. The results, including step counts and total values, are printed to the console.

## Code Breakdown

- **fractionalKnapsack()**: Implements the greedy fractional knapsack algorithm and counts the number of steps taken.
- **knapsack01()**: Implements the 0/1 knapsack algorithm using dynamic programming and counts the number of steps.
- **analyzeKnapsack()**: Runs both algorithms on different capacities and logs the results.
- **main()**: Calls the analysis function to execute the program.

## Code

```cpp
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
```

## Output Example

```cpp
=================== Capacity: 10 ===================
Total value=61.4286
Greedy Knapsack(Fractional): 17 steps
Total value=60
0/1 Knapsack(DP): 50 steps
========================================================

=================== Capacity: 20 ===================
Total value=105
Greedy Knapsack(Fractional): 19 steps
Total value=105
0/1 Knapsack(DP): 100 steps
========================================================

=================== Capacity: 30 ===================
Total value=105
Greedy Knapsack(Fractional): 19 steps
Total value=105
0/1 Knapsack(DP): 150 steps 
========================================================

=================== Capacity: 40 ===================
Total value=105
Greedy Knapsack(Fractional): 19 steps
Total value=105
0/1 Knapsack(DP): 200 steps
========================================================
```

## Graph

![Graph](./graphs/Figure_1.png)

## Time Complexity

- **Greedy Fractional Knapsack**: \(O(n \log n)\) due to sorting the items by value-to-weight ratio.
- **0/1 Knapsack (Dynamic Programming)**: \(O(nW)\) where \(n\) is the number of items and \(W\) is the capacity of the knapsack.

## Requirements

- C++ Compiler (e.g., g++)
- Standard Library (vector, iostream, algorithm)

## Notes

- The **fractional knapsack** algorithm is more efficient because it sorts items based on value-to-weight ratio and picks the best fraction.
- The **0/1 knapsack** algorithm takes more steps as it considers all subsets of items using dynamic programming.
- The total value for **fractional knapsack** is usually higher than **0/1 knapsack** for the same capacity.
