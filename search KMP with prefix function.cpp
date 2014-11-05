#include <iostream>
#include <vector>
#include <string>
#define forn(i,n) for(int i=0;i<n;i++)

using namespace std;

string s2,s1;

vector<int> prefix_function (string s) {
int n = (int) s.length(); // размер строк

vector<int> pi (n); 
for (int i=1; i<n; ++i) {
int j = pi[i-1]; //длина текущего рассматриваемого образца

while ((j > 0) && (s[i] != s[j] || j==s2.size() || i==s2.size()))
j = pi[j-1]; // промежуточное значение
if (s[i] == s[j] && i!=s2.size() && j!=s2.size()) ++j; //если s[i] символ в подстроке и символ в префикс функции s[j] равны
pi[i] = j; 
}
return pi;
}

int main()
{
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);


cin >> s2 >>s 1; //считывается подстрока и строка
s1=s2+'#'+s1;


vector<int> p=prefix_function (s1);

forn(i,p.size())
{

if( p[i]==s2.size() ) // если значение префикс функции равно искомой подстроке
{
cout << i-2*s2.size()+1 << " "; //выводится номера первого вхождения подстроки в строку
}
}

return 0;
}