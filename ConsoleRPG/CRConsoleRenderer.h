#pragma once

#include <vector>
#include <iostream>
#include <memory>

using namespace std;

class CRConsoleRenderer
{
public:
	void PrintBuffer();
	void AddBuffer(shared_ptr<string> strPtr);
	void Clear();

private:
	vector<shared_ptr<string>> buffer;
};

