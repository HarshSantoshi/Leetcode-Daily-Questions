// C++ code to find
// duplicates in O(n) time
//S.C=O(1)
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int arr[] = { 0, 4, 3, 2, 7, 8, 2, 3, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	// count the frequency
	for (int i = 0; i < n; i++) {
		arr[arr[i] % n]
			= arr[arr[i] % n] + n;
	}
	cout << "The repeating elements are : " << endl;
	for (int i = 0; i < n; i++) {
		if (arr[i] >= n * 2) {
			cout << i << " " << endl;
		}
	}
	return 0;
}

