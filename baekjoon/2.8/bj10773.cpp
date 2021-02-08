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
        if (saveCur == 0)
        {
            moneySaveStack.pop();
        }
        else
        {
            moneySaveStack.push(saveCur);
        }
    }
    while(true){
        if(moneySaveStack.empty()){
            break;
        }
        totalSum += moneySaveStack.top();
        moneySaveStack.pop();
    }
    cout << totalSum;
}
