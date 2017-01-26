#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int cmp(string a, string b) {
	int c;
	if(a.compare(b) >0)
		return 0;
	else
		return 1;
}

int main() {
	string s;
	int ind, i ,j;
	vector<string> arr;
	cin >> s;
	cin >> ind;
	for(i = 0; i < s.size(); i++) {
		arr.push_back(s.substr(i, s.size()));
		cout << s.substr(i, s.size()) << " ";
	}
	sort(arr.begin(), arr.end(), cmp);
	/*
	for(i = 0; i < s.size(); i++) {
		cout << arr[i] << " " << i << endl;
	}
	*/
	cout << arr[ind - 1];

	return 0;
}
