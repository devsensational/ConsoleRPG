#pragma once

#include <vector>
#include <iostream>
#include <memory>

using namespace std;

class CRConsoleRenderer
{
public:
	void RenderMap(shared_ptr<vector<vector<int>>>& grid);
	void Print(const string& str);
	void PrintLine(const string& str);


};

