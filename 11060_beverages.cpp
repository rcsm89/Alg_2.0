#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<string> drinks;
map<string, int> topoOrder;
bool connect[100][100];

void matchPath(vector<int> &enjoy, int *cont)
{
    string aux;
    if (enjoy.size() == drinks.size())
    {
        for (int i = 0; i < enjoy.size(); i++)
        {
          aux = drinks[enjoy[i]].c_str();
            if(i==(drinks.size()-1))
              cout << aux  << ".\n" << endl;
            else
              cout << aux << " ";
        }
        return;
    }
    for (int i = 0; i < drinks.size(); i++)
    {
        if (!cont[i])
        {
            cont[i] = -1;
            for (int j = 0; j < drinks.size(); j++)
                cont[j] -= connect[i][j];

            enjoy.push_back(i);
            matchPath(enjoy, cont);
            return;
        }
    }
}

int main()
{
    int n, m, cs = 1;
    while (cin>>n)
    {
        if(n==0)
            break;
        string s;
        drinks.clear();
        for (int i = 0; i < n; i++)
        {
            cin>>s;
            drinks.push_back(s);
            topoOrder[s] = i;
        }
        cin>>m;
        int cont[100];
        memset(cont, false, sizeof(cont));
        memset(connect, false, sizeof(connect));
        while (m--)
        {
            string a, b;
            cin>>a>>b;
            int i = topoOrder[a], j = topoOrder[b];
            if (!connect[i][j])
            {
                connect[i][j] = true;
                cont[j]++;
            }
        }
        vector<int> enjoy;
        cout << "Case #" << cs++ << ": Dilbert should drink beverages in this order: ";
        matchPath(enjoy, cont);
    }
    return 0;
}