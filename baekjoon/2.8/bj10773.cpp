#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> moneySaveStack;

    int K , saveCur, totalSum;
    cin >> K;
    totalSum = 0;
    for (int i = 0; i < K; i++)
    {
        
        cin >> saveCur;
        if (saveCur == 0) // case1: mistake number
        {
            totalSum -= moneySaveStack.top();
            moneySaveStack.pop();

        }
        else // case2: new number
        {
            moneySaveStack.push(saveCur);
            totalSum += saveCur;
        }
    }

    cout << totalSum;
}
