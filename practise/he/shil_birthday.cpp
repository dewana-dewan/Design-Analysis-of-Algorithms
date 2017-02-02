#include <iostream>
#include <set>
using namespace std;

int main()
{
	long long int tst, j;
	set <long long int> st;
	cin >> tst;
	while(tst--) {
		cin >> j;
		st.insert(j);
	}
	j = st.size();
	cout << j*(j - 1)/2 << endl;
	return 0;
}

