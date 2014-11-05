#include <iostream>
#include <vector>
#include <string>
#define forn(i,n) for(int i=0;i<n;i++)

using namespace std;

string s;

vector<int> prefix_function (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=0; i<n; ++i)
		for (int k=0; k<=i; ++k)
			if (s.substr(0,k) == s.substr(i-k+1,k))
				pi[i] = k;
	return pi;
}

int main()
{
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);


cin >> s; //считывается подстрока и строка

vector<int> p=prefix_function (s);

forn(i,p.size())
{


cout << p[i] << " "; //выводится номера первого вхождения подстроки в строку

}

return 0;
}