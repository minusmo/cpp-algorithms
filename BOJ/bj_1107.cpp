#include <iostream>
#include <array>
#include <queue>
#define MAXSIZE 999999
using namespace std;

int calculateMinCost(const int N, array<bool,10> numbers, const int disables);
bool canBeMade(int number, array<bool,10> numbers);
int lenOfNum(int number);

int main() {
    int N, disables;
    array<bool, 10> numbers;
    numbers.fill(true);
    cin >> N;
    cin >> disables;
    int disabled;
    for (int i=0;i<disables;i++)
    {
        cin >> disabled;
        numbers[disabled] = false;
    }

    int costs = calculateMinCost(N,numbers,disables);
    cout << costs << endl;
    return 0;
}

int calculateMinCost(const int N, array<bool,10> numbers, const int disables)
{
    if (N == 100)
    {
        return 0;
    }
    if (disables == 10)
    {
        if (N < 100)
        {
            return 100 - N;
        }
        else
        {
            return N - 100;
        }
    }

    int minCost = 500000;
    int cost;
    array<bool,MAXSIZE+1> isVisited;
    isVisited.fill(false);
    queue<pair<int,int> > q;
    q.push({N,0});
    while (!q.empty())
    {
        auto num = q.front();
        q.pop();
        isVisited[num.first] = true;
        if (canBeMade(num.first, numbers))
        {
            int lenofnum = lenOfNum(num.first);
            int operationFrom100 = 0;
            if (num.first > 100) {
                operationFrom100 = num.first - 100;
            }
            else if (num.first < 100)
            {
                operationFrom100 = 100 - num.first;
            }
            if (lenofnum <= operationFrom100)
            {
                cost = lenofnum + num.second;
            }
            else
            {
                cost = operationFrom100 + num.second;
            }
            if (minCost > cost)
            {
                minCost = cost;
            }
            continue;
        }
        if (isVisited[num.first-1] == false && (num.first-1) >= 0)
        {
            q.push({num.first-1,num.second+1});
        }
        if (isVisited[num.first+1] == false)
        {
            q.push({num.first+1,num.second+1});
        }
    }
    return minCost;
}

bool canBeMade(int number, array<bool,10> numbers)
{
    if (number == 100)
    {
        return true;
    }
    if (number == 0)
    {
        return numbers[number];
    }
    int remainder;
    while (number != 0)
    {
        remainder = number % 10;
        if (numbers[remainder] == false)
        {
            return false;
        }
        number /= 10;
    }
    return true;
}

int lenOfNum(int number)
{
    if (number == 100)
    {
        return 0;
    }
    if (number == 0)
    {
        return 1;
    }
    int length = 0;
    while (number != 0)
    {
        length += 1;
        number /= 10;
    }
    return length;
}
