/**
 * Maximum Profit on App
    You have made a smartphone app and want to set its subscription price such that the profit earned is maximised. There are certain users who will subscribe to your app only if their budget is greater than or equal to your price.
    You will be provided with a list of size N having budgets of subscribers and you need to return the maximum profit that you can earn.
    Lets say you decide that price of your app is Rs. x and there are N number of subscribers. So maximum profit you can earn is :
    m * x
    where m is total number of subscribers whose budget is greater than or equal to x.
    Input format :
    Line 1 : N (No. of subscribers)
    Line 2 : Budget of subscribers (separated by space)
    Output Format :
    Maximum profit
    Constraints :
    1 <= N <= 10^6
    1 <=budget[i]<=9999
    Sample Input 1 :
    4
    30 20 53 14
    Sample Output 1 :
    60
    Sample Output 1 Explanation :
    Price of your app should be Rs. 20 or Rs. 30. For both prices, you can get the profit Rs. 60.
    Sample Input 2 :
    5
    34 78 90 15 67
    Sample Output 2 :
    201
    Sample Output 2 Explanation :
    Price of your app should be Rs. 67. You can get the profit Rs. 201 (i.e. 3 * 67).
*/

#include <iostream>
using namespace std;

void merge_two_sorted_arrays(int *input, int startIndex, int mid, int endIndex)
{
    int index = startIndex, jIndex = mid + 1, outputIndex = 0;

    int *output = new int[endIndex - startIndex + 1];
    while (index <= mid && jIndex <= endIndex)
    {
        if (input[index] >= input[jIndex])
        {
            output[outputIndex++] = input[jIndex++];
        }
        else
        {
            output[outputIndex++] = input[index++];
        }
    }

    while (index <= mid)
    {
        output[outputIndex++] = input[index++];
    }

    while (jIndex <= endIndex)
    {
        output[outputIndex++] = input[jIndex++];
    }

    outputIndex = 0;
    for (int index = startIndex; index <= endIndex; ++index)
    {
        input[index] = output[outputIndex++];
    }
}

void merge_sort(int *input, int startIndex, int endIndex)
{

    // Base Case
    if (startIndex >= endIndex)
    {
        return;
    }

    int mid = (startIndex + endIndex) / 2;

    merge_sort(input, startIndex, mid);
    merge_sort(input, mid + 1, endIndex);

    merge_two_sorted_arrays(input, startIndex, mid, endIndex);
}

int maximumProfit(int budget[], int n)
{
    // Write your code here

    merge_sort(budget, 0, n - 1);

    int largest = 0;
    for (int index = 0; index < n; ++index)
    {
        int max_profit = budget[index] * (n - index);

        if (largest < max_profit)
        {
            largest = max_profit;
        }
    }

    return largest;
}

int main()
{
    int n, *input, i, *cost;
    cin >> n;
    input = new int[n];
    for (i = 0; i < n; i++)
        cin >> input[i];

    cout << maximumProfit(input, n) << endl;
}
