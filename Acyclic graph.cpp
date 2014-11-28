#include <iostream>
#include <fstream>
#include <stdio.h> 
#include < vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;
int n;

vector <vector<int» g2;
map <int,vector<int» g;
map<int,int> cl;
map<int,int> p;

int cycle_st, cycle_end;

bool dfs (int v) {
cl[v] = 1; 
int to; 

for (int i=0; i < (int)g[v].size(); ++i) {

if (g[v][i]!=0) {

to = g[v][i];

if (cl[to] == 0) {
p[to] = v;
if (dfs (to)) return true;
}

else if (cl[to] == 1 && p[v] != to) {
cycle_end = v;
cycle_st = to;
return true;
}}}

cl[v] = 2;
return false;
}

void main() {

ifstream inp("input.txt");
inp >> n; 

int x,y,j; 
int i = 0;
string str;

getline (inp, str);

for ( int i=0 ; i<n ; i++)
{

getline (inp, str );
stringstream sio(str);
sio >> x;
cl[x] = 0;
p[x] = -1;

while ( sio»y )

{ 
g[x].push_back(y);

} 
}

cycle_st = -1;

for (map <int,vector<int>>::iterator it = g.begin(); it != g.end(); it++)
if (dfs ((*it).first)) 
break;

if (cycle_st == -1)
cout << "Acyclic" << endl;
else
cout << "Cyclic" << endl;

system ("pause");
}