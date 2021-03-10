// T(n) =  O(n log n)
#include <iostream>
#include <algorithm>
using namespace std;

// structure to store each item's value and weight
struct item
{
    int value, weight;
    item(int val, int wt)
    {
        this->value = val;
        this->weight = wt;
    }
};

bool compare(struct item i1, struct item i2)
{
    double r1 = (double)i1.value / (double)i1.weight;
    double r2 = (double)i2.value / (double)i2.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, struct item arr[], int n)
{
    // sorting the p/w values in the descending order
    sort(arr, arr + n, compare);

    double cur_val = 0.0;
    int cur_wt = 0;
    for (int i = 0; i < n; i++)
    {
        if (cur_wt + arr[i].weight <= W) // finding out the max value knapsack can take whole
        {
            cur_val += arr[i].value;
            cur_wt += arr[i].weight;
        }
        else // if fractional value is to be taken
        {
            int remaining = W - cur_wt;
            cur_val += (double)arr[i].value * (double)remaining / (double)arr[i].weight;
            break;
        }
    }
    return cur_val;
}

int main(int argc, char const *argv[])
{
    int W = 50;       //    Weight of knapsack
    item arr[] = {{60, 10}, {100, 20}, {120, 30}}; // {value or profit, weight = p/w}
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum value that knapsack can carry = " << fractionalKnapsack(W, arr, n);
    return 0;
}