#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("text.txt");


class CompareModule
{

public:
	bool operator() (const pair<int, string>& a, const pair<int, string>& b)
	{
		if (a.first != b.first)
			return a.first < b.first;
		return a.second > b.second;
	}
};

bool strchr1(const string s,const char c) {
	for (auto i : s)
		if (i == c)
			return true;
	return false;
}
void SplitWords(vector <string> &v,string s) {
	string aux = "";
	for (int i = 0; i <= s.length(); ++i) {
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		if (strchr1(" ,.?!\n", s[i])) {
			if (aux.length())
				v.push_back(aux);
			aux = "";
		}
		else {
			aux += s[i];
		}
	}
}
int main() {
	string s;
	vector <string> v;
	getline(fin, s);
	SplitWords(v, s);

	map<string, int> mp;
	for (auto i : v) {
		mp[i]++;
	}
	priority_queue < pair<int, string>, vector<pair<int, string>>, CompareModule > pq;
	for (auto i : mp) {
		pq.push({ i.second,i.first });
	}
	while (!pq.empty())
	{
		cout << pq.top().first << " => " << pq.top().second << "\n";
		pq.pop();
	}
}