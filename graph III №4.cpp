#include <iostream>
#include <fstream>
const int inf=1E9;
using namespace std;

int main()
{ 

ifstream inp("input.txt");
ofstream outp("output.txt");

int n,i,j,k,d[100][100];
inp » n;

for (i=0;i<n;++i) // пробегаем по матрице
{
for (j=0;j<n;++j)
{
inp » d[i][j]; // вводим матрицу
if (i==j) 
{
d[i][j]=0; // если номера вершин равны, то присваиваем нули
}

else

{
if (d[i][j]==0) 
{
d[i][j]=inf; // если нет пути из вершины, то выводим бесконечность
}
}
}
}

for (k=0;k<n;++k)
{
for (i=0;i<n;++i)
{
for (j=0;j<n;++j)
{
if (d[i][k]<inf && d[k][j]<inf)
{
d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
}
}
}

for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
cout « d[i][j]«" ";
}
cout « endl;
}

int p = 0;
cin » p;
bool find = false;
for(int i=0;i<n;i++)
{
find = false;
for(int j=0;j<n;j++)
{ 
if(d[i][j] > p)
{
find = true;
}
}

if(!find)
{
outp « i+1«" ";
}
}

inp.close();
outp.close();
return 0;
}