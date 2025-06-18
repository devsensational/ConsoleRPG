#include "CRConsoleRenderer.h"

void CRConsoleRenderer::RenderMap(shared_ptr<vector<vector<int>>>& grid)
{
    for (const auto& row : *grid) {
        for (int val : row) {
            cout << "бс";
        }
        cout << '\n';
    }
}

void CRConsoleRenderer::Print(const string& str)
{
    cout << str;
}

void CRConsoleRenderer::PrintLine(const string& str)
{
    cout << str << '\n';
}
