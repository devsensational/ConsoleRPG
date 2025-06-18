#pragma once

#include <vector>
#include <memory>

using namespace std;

class CRMapCreator
{
public:
	shared_ptr<vector<vector<int>>> CreateNewMap(int rows, int cols);
};

