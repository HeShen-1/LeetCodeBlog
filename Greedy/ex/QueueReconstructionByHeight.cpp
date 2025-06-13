#include "pch.h"

vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
{
    sort(people.begin(), people.end(), [](vector<int> a, vector<int> b)
         {
        if (a[0] == b[0]) 
            return a[1] < b[1];
        return a[0] > b[0]; });

    cout << "sorted:" << endl;
    for (size_t i = 0; i < people.size(); ++i)
    {
        for (size_t j = 0; j < people[i].size(); ++j)
        {
            cout << "[" << i << "][" << j << "]=" << people[i][j] << " ";
        }
        cout << endl;
    }

    list<vector<int>> que;
    for (int i = 0; i < people.size(); i++)
    {
        int position = people[i][1];
        list<vector<int>>::iterator it = que.begin();
        while (position--)
        {
            it++;
        }
        que.insert(it, people[i]);
    }
    return vector<vector<int>>(que.begin(), que.end());
}

int main()
{
    vector<vector<int>> test = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    vector<vector<int>> a = reconstructQueue(test);

    cout << "result:" << endl;
    for (size_t i = 0; i < a.size(); ++i)
    {
        for (size_t j = 0; j < a[i].size(); ++j)
        {
            cout << "[" << i << "][" << j << "]=" << a[i][j] << " ";
        }
        cout << endl;
    }
}
