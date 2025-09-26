#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int nums[20][20] = {0};
    int num = 1;
    pair<int, int> from = {0, n - 1};
    int dir = 0;
    int directions[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    while (true)
    {
        nums[from.first][from.second] = num;
        num++;
        pair<int, int> to;
        to.first = from.first + directions[dir][0];
        to.second = from.second + directions[dir][1];
        if (to.first < 0 || to.first >= n || to.second < 0 || to.second >= n || nums[to.first][to.second] != 0)
        {
            dir = (dir + 1) % 4;
            to.first = from.first + directions[dir][0];
            to.second = from.second + directions[dir][1];
            if (to.first < 0 || to.first >= n || to.second < 0 || to.second >= n || nums[to.first][to.second] != 0)
            {
                break;
            }
        }
        from = to;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}