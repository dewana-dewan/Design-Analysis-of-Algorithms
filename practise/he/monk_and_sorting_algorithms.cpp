#include <iostream>
#include <map>

using namespace std;

long long int poow(int a) {
	long long int i = 1;
	if(a == 0)
		return 1;
	while(a--) {
		i *= 10;
	}
	return i;
}

void this_main(long long int arr[],long int siz) {
	long long ax_arr[siz], outp[siz], diva1, diva2, temp;
	long int j, i;
	map <long long int, long int > mp;
	map <long long int, long int>::iterator it;
	for(i = 1; i < 4; i++ ) {
		diva1 = poow(i*5);
		diva2 = poow((i-1) * 5);
		for(j = 0; j < siz; j++ ) {
			ax_arr[j] = (arr[j] % diva1) / diva2;
			mp[ax_arr[j]]++;
		}
		int k = 0;
		for(it = mp.begin() ; it!= mp.end(); ++it) {
			if(it == mp.begin()) {
				continue;
			}
			it--;
			temp = it -> second;
			it++;
			mp[it -> first] += temp;
		}
		//for(it = mp.begin() ; it!= mp.end(); ++it) {
		//cout << "here";
		//cout << it -> first << " - " << it -> second << endl;
		//}
		//cout << endl;
		if(mp[0] == siz)
			return;
		//for(j = siz - 1; j >= 0; j--) {
		//    cout << ax_arr[j] << ax_arr[j] << endl;
		//}
		for(j = siz - 1; j >= 0; j--) {
			outp[mp[ax_arr[j]] - 1] = arr[j];
			//cout << arr[j] << "  " << mp[ax_arr[j]] -1 << endl <<endl;
			mp[ax_arr[j]] -= 1;
		}
		for(j = 0; j < siz; j++){
			cout << outp[j] << " ";
			arr[j] = outp[j];
		}
		cout << endl;
		mp.erase(mp.begin(), mp.end());

	}

}

int main()
{
	long int tst,i ,j;
	cin >> tst;
	long long int arr[tst];
	for(i = 0; i < tst; i++) {
		cin >> arr[i];
	}
	this_main(arr, i);

	return 0;
}

