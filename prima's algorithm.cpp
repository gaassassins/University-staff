#include <iostream>
#include <vector>
#include <iomanip>

#define forn(i,n) for(int i=0;i<n;i++) // замен€ет цикл
using namespace std;
int n,m; // кол-во вершин и ребер
vector <pair<int,int> > g[500]; //кроме вершин список смежности хранит и вес ребра
vector <bool> used(500,0);//вектор использованных вершин
int inf=10000000;
vector <int> d(500,inf); //вектор рассто€ний

int main()
{
freopen("input.txt","rt",stdin);
freopen("output.txt","wt",stdout);
cin>>n>>m;
int x,y,l; // x - откуда, y - куда, l - вес

pair <int,int> temp;

forn(i,m){ 
cin>>x>>y>>l;
x--;
y--;
temp.first=y; // куда
temp.second=l; // вес
g[x].push_back(temp);
temp.first=x; // мен€ем на откуда ты идешь
g[y].push_back(temp);
}

vector <pair<int,int> > path(500);  // множество неывбранных ребер

d[0]=0; // изначальный вес равен нулю
while(true){
int v=-1; // изначально вершины нет
int dist=inf;
forn(u,n)
if(!used[u] && dist>=d[u]) // если она непроссмотренна€ и бесконечность больше, чем вершина
{
v=u; // v присваеваем номер вершины
dist=d[u]; // и бесконечности вершину
}

if (v==-1) break; // если это не верно, то прерываем программу
used[v]=true; // вершина использована

forn(u,g[v].size()) // идем от вершины и учитываем ее вес (стоимость)

if(!used[g[v][u].first]) // если эта вершина не из вектора просмотренных вершин, тогда устраиваем поиск минимального пути
{
if (d[g[v][u].first]>g[v][u].second)   // если рассто€ние от одной вершины больше чем вес другой вершины
path[g[v][u].first] = make_pair(v,g[v][u].first); // из вершины котороый мы идем делаем пару с вершиной которую мы нашли
d[g[v][u].first] = min(d[g[v][u].first],g[v][u].second); // находим минимальный вес из двух вершин
}
}

long long sum=0; 
forn(i,n) sum+=d[i];
cout << sum << endl;
forn(i,n-1)
cout<<path[i+1].first+1 << " " << path[i+1].second+1 << endl; // вывод€тс€ откуда-куда остовного минимального дерева

return 0;
}
