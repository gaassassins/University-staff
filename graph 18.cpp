#include <iostream>
#include<fstream>
#include <stdio.h> 
#include < vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;
bool f(int x,int l)
{ 
if (x==l) return true;}

void main()
{
ifstream inp("input.txt");

int n; int m1,m2,k=0;

inp » n; 
inp » m1; 
inp » m2;

vector <int> *vec = new vector <int> [n];
int i=0;
char x; 
while (inp » x)
{
if (isdigit(x)) 
{
int b = x - '0';
vec[i].push_back(b);
if (inp.get() == '\n') i++;}
;}

for (unsigned int i=0; i<vec[m1-1].size();i++)
for (unsigned int j=0; j<vec[m2-1].size();j++)
{ 
if (vec[m1-1][i]==vec[m2-1][j])
{
cout « vec[m1-1][i] « " " « endl; k=1;
}
;} 
if (k==0) cout « "No\n";
system("pause");
;}