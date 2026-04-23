#include <iostream>

using namespace std;

bool find(int **arr, int line, int size, const bool *vis) {
    for (int i = 0; i < size; ++i)
        if (!vis[i] && arr[i][line])
            return false;
    return true;
}

bool flag(const bool *vis, int n) {
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int **arr = new int *[n];
        bool *vis = new bool[n];
        for (int i = 0; i < n; i++)
            vis[i] = false;
        for (int i = 0; i < n; i++)
            arr[i] = new int[n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        while (flag(vis, n)) {
            for (int i = 0; i < n; i++) {
                if (!vis[i] && find(arr, i, n, vis)) {
                    vis[i] = true;
                    cout << i << ' ';
                    break;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
