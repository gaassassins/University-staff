#include <iostream>
#include <fstream>
#include <stdio.h> 
#include < vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

void main()
{ifstream inp("input.txt");
ofstream outp("output.txt");
int n; int k;
inp>>x;inp>>k; 
vector <int> *vec = new vector <int> [n+1];
int i=0;
char x; 
while (inp>>x)
{
if (isdigit(x)) 
{
int b = x - '0';
vec[i].push_back(b); 
//cout«b«i«"\n";
if (inp.get() == '\n') i++;
};
}

for (int i=0 ; i<n; i++)
{ 
	if (i!=k-1)
for (unsigned int j=0; j<vec[i].size(); j++)
if (vec[i][j]!=k)
{cout<<vec[i][j]«" " << endl; } 
cout<<"\n";
;} 
if (k==0) cout<<"no";
;}