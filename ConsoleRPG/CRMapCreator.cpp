#include "CRMapCreator.h"
#include <vector>

using namespace std;

shared_ptr<vector<vector<int>>> CRMapCreator::CreateNewMap(int rows, int cols)
{
    auto vec2D = make_shared<vector<vector<int>>>(rows, vector<int>(cols, 0));
    return vec2D;
}
