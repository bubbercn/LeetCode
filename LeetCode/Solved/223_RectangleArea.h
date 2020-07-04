#pragma once
#include "Common.h"

class Solution
{
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        long area1 = (C - A) * (D - B);
        long area2 = (G - E) * (H - F);
        long overlapArea = getOverlap(A, C, E, G) * getOverlap(B, D, F, H);
        return area1 + area2 - overlapArea;
    }
private:
    int getOverlap(int a1, int a2, int b1, int b2)
    {
        if (a1 > b1)
        {
            swap(a1, b1);
            swap(a2, b2);
        }
        if (a2 <= b1)
        {
            return 0;
        }
        else if (a2 > b1 && a2 < b2)
        {
            return a2 - b1;
        }
        else
        {
            return b2 - b1;
        }
    }
};

void Test()
{
    Solution solution;
    int A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2;
    assert(solution.computeArea(A, B, C, D, E, F, G, H));
}