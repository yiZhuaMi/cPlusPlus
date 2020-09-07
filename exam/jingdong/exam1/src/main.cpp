#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxTotal(vector<vector<int>> &triangle)
{
    if (triangle.size() < 2)
        return triangle.empty() ? 0 : triangle[0][0];

    for (int i = triangle.size() - 2; i >= 0; i--)
        for (int j = 0; j < triangle[i].size(); j++)
            triangle[i][j] = triangle[i][j] + max(triangle[i + 1][j], triangle[i + 1][j + 1]);

    return triangle[0][0];
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> triangle(N);
    for (int i = 0; i < N; i++)
    {
        int k = 0;
        while (k++ < i * 2 + 1)
        {
            int tmp;
            cin >> tmp;
            triangle[i].push_back(tmp);
        }
    }
    cout<<maxTotal(triangle)<<endl;
}