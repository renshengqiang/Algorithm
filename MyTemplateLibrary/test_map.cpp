#include <Map.h>
#include <string>
#include <iostream>
using namespace std;
using namespace QTL;
int main()
{
    Map<int, string> map;
    
    map.Insert(Pair<int, string>(1, "rsq"));
    map.Insert(Pair<int, string>(2, "sbj"));
    map.Insert(Pair<int, string>(3, "lj"));
    map.Insert(Pair<int, string>(4, "wzb"));
    map.Insert(Pair<int, string>(5, "zg"));

    for(Map<int, string>::iterator iter = map.begin(); iter != map.end(); ++iter)
    {
        cout << iter->first << " " << iter->second << endl;
    }

    Map<int, string>::iterator ret = map.find(3);
    cout << ret->first << " " << ret->second << endl;
    return 0;
}
