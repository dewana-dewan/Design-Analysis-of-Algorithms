#include <iostream>
using namespace std;

int find_opt(int arr[][2], int k, int i, int low, int high, int siz) {
    if(high - low == k)
        return 1;
    if(high - low > k || i == siz)
        return 0;
    if(low <= arr[i][0] && arr[i][0] <= high){
        if(arr[i][1] - low == k)
            return 1;
        return (find_opt(arr, k, i + 1, low, high, siz) || find_opt(arr, k, i + 1, low, arr[i][1], siz) || find_opt(arr, k, i + 1, arr[i][0], arr[i][1], siz) );
    }
    return( find_opt(arr, k, i + 1, arr[i][0], arr[i][1], siz));        
    
}

int main()
{
    int tst, siz, lky, i, j, temp;
    cin >> tst;
    while(tst--) {
        cin >> siz;
        cin >> lky;
        int arr[siz][2];
        for(i = 0; i < siz; i++) {
            cin >> arr[i][0];
            cin >> arr[i][1];
        }
        for(i = 0; i < siz; i++) {
            for(j = 1; j < siz - i; j++) {
                if(arr[j][0] == arr[j - 1][0]) {
                    if(arr[j][1] < arr[j - 1][1]) {
                        temp = arr[j][0];
                        arr[j][0] = arr[j - 1][0];
                        arr[j - 1][0] = temp;
                        temp = arr[j][1];
                        arr[j][1] = arr[j - 1][1];
                        arr[j - 1][1] = temp;
                    }
                }
                if(arr[j][0] < arr[j - 1][0]) {
                        temp = arr[j][0];
                        arr[j][0] = arr[j - 1][0];
                        arr[j - 1][0] = temp;
                        temp = arr[j][1];
                        arr[j][1] = arr[j - 1][1];
                        arr[j - 1][1] = temp;
                }
            }
        }
        /*for(i = 0; i < siz; i++) {
            cout << arr[i][0] << " ";
            cout << arr[i][1] << endl;
        }*/
        for(i = 0; i < siz; i++) {
            if(find_opt(arr, lky ,i + 1, arr[i][0], arr[i][1], siz)) {
                printf("Yes\n");
                break;
            }
            if(i == siz -1)
                printf("No\n");
        }
    }
    return 0;
}

