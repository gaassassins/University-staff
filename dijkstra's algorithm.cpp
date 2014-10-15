#include <iostream>

using namespace std;

int w[500][500];//массив весов
bool used[500];//массив вершин которые использовали
int d[500];//массив длины путей
int inf=1000000000;// бесконечность
int main()
{

int n,m,v1,x=0,y=0,z=0;
cout « "Vvedite kol-vo vershin = "; cin » n;

cout « "Vvedite kol-vo reber = "; cin » m;

cout « "Vvedite S = "; cin»v1; // из которой ищем пути

v1--;
memset(w,0,sizeof(w)); //ф-я передающая 0
memset(d,1000000000,sizeof(d)); // ф-я передающая беск
memset(used,false,sizeof(used)); //ф-я просмотра вершины

for (int i=0;i<n;i++) 
d[i]=inf; // присваеваем всем вершинам метку - бесконечность
cout « "Vvedite spisok smejnosti"« endl;
for (int i=0;i<m;i++)
{
cin » x » y » z; // считываем вершины ребра и вес
w[x-1][y-1]=z;
w[y-1][x-1]=z;
}
d[v1]=0; // первой вершине ставим 0
while (true){
int from,zfrom=inf; // запоминаем номера вершины
for (int i=0;i<n;i++)

if ((zfrom>d[i]) && !(used[i])) // если изначально zfrom больше чем вершина ( которая 0) и она не использованная
{
from=i; // присваеваем ей номер
zfrom=d[i]; // и ставим пометку zfrom равную весу вершины
}

if (zfrom>=inf) break; // если пометка бесконечность, то прекращаем работу
used[from]=true;

for(int to=0;to<n;to++)

if (w[from][to]!=0) // если вес ребра "откуда мы идем куда" не равен 0

if ((!used[to]) && (d[to]>d[from]+w[from][to])) // вес вершины "куда идем" больше, чем вес ребра W + вес вершины предыдущей вершины
d[to]=d[from]+w[from][to]; // заменить вес ребра на кратчайший
}
cout « "Kratshayshii path: "«endl;
for (int i=0;i<n;i++)
if (v1!=i) 
if (d[i]<inf) 
cout«v1+1«" "«i+1«" "«d[i]«endl;
else cout«v1+1«" "«i+1«" "«"-1"«endl;
system("pause");
return 0;
}