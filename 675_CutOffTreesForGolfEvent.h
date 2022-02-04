#pragma once
#include "Common.h"

class Solution
{
public:
    int cutOffTree(vector<vector<int>> &forest)
    {
        m = forest.size();
        n = forest[0].size();
        k = m * n;
        map<int, int> valueIndexMap;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (forest[i][j] == 0 || forest[i][j] == 1)
                    continue;

                int index = i * n + j;
                valueIndexMap[forest[i][j]] = index;
            }
        }

        int result = 0;
        int begin = 0;
        for (auto [value, index] : valueIndexMap)
        {
            if (int d = distance(begin, index, forest); d == -1)
            {
                return -1;
            }
            else
            {
                result += d;
                begin = index;
            }
        }
        return result;
    }

private:
    int distance(int i, int j, vector<vector<int>> &forest)
    {
        list<int> current = {i};
        vector<bool> visited(k, false);
        visited[i] = true;
        int result = 0;
        while (!current.empty())
        {
            list<int> next;
            for (auto point : current)
            {
                if (point == j)
                    return result;

                int x = point / n;
                int y = point % n;
                if (int up = point - n; x - 1 >= 0 && !visited[up] && forest[x - 1][y])
                {
                    next.emplace_back(up);
                    visited[up] = true;
                }
                if (int down = point + n; down < k && !visited[down] && forest[x + 1][y])
                {
                    next.emplace_back(down);
                    visited[down] = true;
                }
                if (int left = point - 1; y - 1 >= 0 && !visited[left] && forest[x][y - 1])
                {
                    next.emplace_back(left);
                    visited[left] = true;
                }
                if (int right = point + 1; y + 1 < n && !visited[right] && forest[x][y + 1])
                {
                    next.emplace_back(right);
                    visited[right] = true;
                }
            }
            current.swap(next);
            result++;
        }
        return -1;
    }
    map<pair<int, int>, int> lookup;
    int m;
    int n;
    int k;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> forest = {
        {1, 2, 3},
        {0, 0, 4},
        {7, 6, 5},
    };
    EXPECT_EQ(solution.cutOffTree(forest), 6);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> forest = {
        {1, 2, 3},
        {0, 0, 0},
        {7, 6, 5},
    };
    EXPECT_EQ(solution.cutOffTree(forest), -1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> forest = {
        {2, 3, 4},
        {0, 0, 5},
        {8, 7, 6},
    };
    EXPECT_EQ(solution.cutOffTree(forest), 6);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<vector<int>> forest = {
        {0, 0, 0, 3528, 2256, 9394, 3153},
        {8740, 1758, 6319, 3400, 4502, 7475, 6812},
        {0, 0, 3079, 6312, 0, 0, 0},
        {6828, 0, 0, 0, 0, 0, 8145},
        {6964, 4631, 0, 0, 0, 4811, 0},
        {0, 0, 0, 0, 9734, 4696, 4246},
        {3413, 8887, 0, 4766, 0, 0, 0},
        {7739, 0, 0, 2920, 0, 5321, 2250},
        {3032, 0, 3015, 0, 3269, 8582, 0},
    };
    EXPECT_EQ(solution.cutOffTree(forest), -1);
}

TEST_F(LeetCodeTest, Failure2)
{
    vector<vector<int>> forest = {
        {54581641, 64080174, 24346381, 69107959},
        {86374198, 61363882, 68783324, 79706116},
        {668150, 92178815, 89819108, 94701471},
        {83920491, 22724204, 46281641, 47531096},
        {89078499, 18904913, 25462145, 60813308},
    };
    EXPECT_EQ(solution.cutOffTree(forest), 57);
}

TEST_F(LeetCodeTest, Failure3)
{
    vector<vector<int>> forest = {
        {584, 41176, 0, 84851, 5441, 70639, 56597, 62679, 49323, 86340, 5352, 0, 93554, 0, 12084, 40642, 93702, 46453, 21713, 27842, 1339, 59987, 3604, 90313, 77097, 68238, 60394},
        {67899, 70450, 0, 47502, 99265, 85901, 13579, 7320, 36586, 0, 0, 81886, 90379, 31744, 90234, 76250, 10104, 62356, 59519, 7782, 71566, 91515, 24832, 78046, 204, 63974, 72204},
        {3657, 47544, 54745, 59243, 44861, 47148, 83563, 26920, 81164, 22887, 85661, 47198, 90529, 0, 61724, 63224, 96440, 28524, 32600, 37691, 67572, 77872, 59735, 19587, 48869, 69551, 0},
        {0, 81904, 55598, 28273, 61332, 30929, 95175, 2596, 62937, 9711, 36764, 0, 69181, 40582, 89972, 34806, 89956, 35087, 84547, 88362, 0, 12632, 28051, 77608, 17549, 71324, 7031},
        {15555, 0, 91139, 16345, 71032, 79505, 32456, 64864, 77687, 98643, 95207, 71967, 95495, 82715, 76404, 63943, 63973, 55193, 11812, 30160, 17410, 54556, 60496, 35945, 64739, 87782, 45283},
        {76521, 7740, 36829, 0, 78711, 70264, 88457, 35349, 40047, 96915, 50902, 19002, 0, 31609, 62536, 46918, 3386, 55625, 16156, 14947, 31147, 66393, 63296, 80438, 64446, 97131, 0},
        {22397, 55228, 27150, 9519, 54197, 26866, 64562, 95463, 1952, 26498, 42378, 5105, 909, 24560, 21019, 2270, 37376, 53928, 6452, 9305, 22444, 65989, 77999, 80300, 95492, 30322, 80433},
        {4736, 79210, 42457, 23429, 7138, 36957, 96801, 10996, 95622, 66141, 41590, 337, 89548, 72250, 86233, 51111, 44300, 71974, 62813, 22195, 3755, 43518, 4333, 63540, 8378, 76457, 66325},
        {39196, 0, 96504, 3942, 3516, 40470, 68830, 61639, 42489, 6841, 30048, 53638, 31133, 77646, 3016, 14014, 25359, 29856, 90389, 34929, 0, 1638, 6440, 60418, 38462, 7574, 49059},
        {32551, 46791, 9154, 46218, 11838, 4169, 84723, 83850, 0, 5521, 23503, 54877, 91954, 3229, 24989, 52449, 2404, 36246, 21387, 27407, 74997, 73106, 79400, 75833, 70818, 17850, 99594},
        {96055, 22364, 48491, 40218, 66766, 18706, 94119, 32361, 81313, 28969, 0, 78222, 1247, 55861, 12770, 86641, 11552, 70553, 0, 45633, 43220, 98035, 0, 0, 50663, 97908, 30624},
        {86578, 40713, 20328, 76454, 34313, 0, 23213, 0, 0, 53316, 3235, 11475, 4755, 9671, 81476, 39129, 30175, 67985, 28547, 91578, 0, 89149, 45768, 0, 89732, 72480, 69633},
        {45641, 87506, 40356, 27213, 13512, 14406, 0, 54267, 45665, 54893, 62600, 64803, 97061, 39195, 64986, 18539, 0, 24169, 0, 41540, 0, 47890, 86003, 0, 15880, 20283, 29033},
        {91217, 88922, 15946, 1541, 60641, 55461, 66377, 62516, 76719, 43872, 81218, 0, 0, 67023, 23349, 6300, 23862, 23090, 49655, 43960, 9390, 96602, 7291, 93517, 96320, 41286, 75862},
        {12984, 0, 11418, 36033, 90978, 11016, 81388, 9023, 17361, 28536, 44317, 87824, 5028, 52109, 17297, 3424, 93246, 15313, 38295, 90914, 42382, 88405, 78363, 38181, 75694, 14063, 83030},
        {78653, 0, 69802, 74818, 67980, 12615, 61595, 89897, 19098, 6135, 44671, 12635, 31584, 8215, 68928, 57468, 26781, 48977, 38781, 7374, 78059, 99491, 15483, 55666, 81777, 26107, 23195},
        {95803, 0, 34621, 15431, 11437, 0, 42946, 98472, 9156, 3895, 61023, 61370, 74365, 17231, 43459, 5130, 42170, 88326, 10921, 27233, 67624, 0, 40570, 49014, 54062, 15474, 26875},
        {39524, 52632, 28692, 92559, 49635, 55362, 92322, 3878, 55730, 64614, 17061, 30708, 6652, 23458, 29102, 89160, 62210, 32167, 10358, 86971, 82013, 0, 12979, 93914, 38533, 0, 21777},
        {20298, 0, 0, 54863, 30028, 25633, 3397, 18943, 86887, 0, 7680, 85736, 24445, 32654, 81065, 92349, 70788, 65234, 8409, 39904, 76676, 6311, 41699, 0, 49766, 19066, 61389},
        {98947, 12747, 12424, 33975, 0, 91772, 75442, 89531, 7900, 90852, 15257, 84715, 33881, 17099, 25810, 0, 17997, 78578, 10160, 89605, 27030, 58687, 28603, 6972, 79040, 98632, 92991},
        {53890, 23801, 85650, 63911, 612, 66980, 75525, 35940, 19500, 83181, 76783, 36814, 13928, 41578, 79896, 11658, 59694, 21287, 88732, 50685, 9816, 9215, 90499, 81561, 59082, 35397, 664},
        {10704, 0, 47683, 91141, 13000, 59671, 63986, 65514, 45447, 79405, 0, 77599, 8445, 35668, 43665, 30164, 85561, 18640, 23723, 0, 26745, 15785, 84867, 83701, 0, 68958, 22010},
        {24454, 77324, 20725, 89455, 83717, 82482, 60498, 7191, 73315, 94284, 31921, 84243, 67118, 62731, 1678, 46376, 94405, 4051, 0, 0, 0, 96329, 75733, 99345, 26763, 15444, 30255},
    };
    EXPECT_EQ(solution.cutOffTree(forest), 9581);
}

TEST_F(LeetCodeTest, Failure4)
{
    vector<vector<int>> forest = {
        {4, 2, 3},
        {0, 0, 1},
        {7, 6, 5},
    };
    EXPECT_EQ(solution.cutOffTree(forest), 10);
}