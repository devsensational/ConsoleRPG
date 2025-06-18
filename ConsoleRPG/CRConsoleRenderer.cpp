#include <iostream>
#include <windows.h>

#include "CRConsoleRenderer.h"

using namespace std;

void CRConsoleRenderer::PrintBuffer()
{
	system("cls");
	for (const auto& str : buffer)
	{
		cout << *str << '\n';
	}
}

void CRConsoleRenderer::AddBuffer(shared_ptr<string> strPtr)
{
	buffer.push_back(strPtr);
}

void CRConsoleRenderer::Clear()
{
	buffer.clear();
}
