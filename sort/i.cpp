/**
 * merge sort
 * not by me :(
 * accepted
 */

#include<iostream>
#include<string>
using namespace std;
void Merge(string initlist[], string mergelist[], int left, int mid, int right) {
	int i = left, j = mid + 1, k = left;
	while (i <= mid && j <= right) {   
		if (initlist[i]>initlist[j]) { 
			mergelist[k] = initlist[i];
			i++;
		}
		else {            
			mergelist[k] = initlist[j];
			j++;
		}
		k++;
	}
	while (i <= mid) {    
		mergelist[k] = initlist[i];
		i++;
		k++;
	}
	while (j <= right) {    
		mergelist[k] = initlist[j];
		j++;
		k++;
	}
}

void MergeSort(string s[], int n) {
	string tmp[1000];
	for (int len = 1; len < n; len *= 2) {   
		for (int i = 0; i < n; i++)        
			tmp[i] = s[i];
		for (int left = 0; left < n - len; left += 2 * len) {
			int mid = left + len - 1;
			int right = min(left + 2 * len - 1, n - 1);    
			Merge(tmp, s, left, mid, right);
		}
		for (int i = 0; i < n; i++) {
			cout << s[i];
			if (i == n - 1)
				cout << endl;
			else
				cout << " ";
		}
	}
	cout << endl;
}
 
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s[1000];
		for (int i = 0; i < n; i++)
			cin >> s[i];
		MergeSort(s, n );
	}
}