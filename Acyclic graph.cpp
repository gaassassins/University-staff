#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 1555555555;
struct edge {
        int a, b, cost;
};
int main()
{
        vector<edge> e;
        int n, m, i, ans = 0;        
    cin>>n>>m;
    edge t;

    for(i=0; i<m; i++)
        {
         cin>>t.a>>t.b>>t.cost;
        t.a--; t.b--;
        e.push_back(t);
        }
// применяем алгоритм Форда-Беллмана для релеакцасии между вершинами
    vector<int> d (n, -1);
        vector<int> p (n);
 
        int x;
        for (int i=0; i<n; ++i) 
        {
                x = -1;
                for (int j=0; j<m; ++j)
                        if (d[e[j].a] < inf)
                                if (d[e[j].b] > d[e[j].a] + e[j].cost) 
                                {
                                        d[e[j].b] = max (-inf, d[e[j].a] + e[j].cost);
                                        p[e[j].b] = e[j].a;
                                        x = e[j].b;
                                }
        }
 
        if (x == -1)
                cout << "NO"; // найден кратчайший  без отрицательного веса
        else 
        {
                int y = x;
                for (int i=0; i<n; ++i)
                        y = p[y];
 
                vector<int> path;
                for (int cur=y; ; cur=p[cur]) 
                {
                        path.push_back (cur);
                        ans++;
                        if (cur == y && path.size() > 1)  break; // если больше 0 - прерываем
                }
                reverse (path.begin(), path.end());
 
                cout<<"YES"<<endl;
                cout<<ans<<endl;
                for (size_t i=0; i<path.size()-1; ++i)
                        cout << path[i]+1 << ' ';
                cout << path[path.size()-1]+1;
        }
return 0;
}