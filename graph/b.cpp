#include<iostream>

class graph {
    int vnum;
    std::string* vertex;
    int** adjmatrix;
    char kind;
public:
    graph() {
        std::cin >> kind >> vnum;
        vertex = new std::string[vnum];
        for (int i = 0; i < vnum; i++) {
            std::cin >> vertex[i];
        }
        adjmatrix = new int* [vnum];
        for (int i = 0; i < vnum; i++) {
            adjmatrix[i] = new int[vnum];
            for (int j = 0; j < vnum; j++) {
                adjmatrix[i][j] = 0;
            }
        }
        int n;
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            std::string s1, s2;
            std::cin >> s1 >> s2;
            int index1 = 0;
            int index2 = 0;
            for (int j = 0; j < vnum; j++) {
                if (vertex[j] == s1) {
                    index1 = j;
                    break;
                }
            }
            for (int j = 0; j < vnum; j++) {
                if (vertex[j] == s2) {
                    index2 = j;
                    break;
                }
            }
            switch (kind) {
            case 'U':
                adjmatrix[index2][index1] = 1;
            case 'D':
                adjmatrix[index1][index2] = 1;
            default:
                break;
            }
        }
    }
    void display_array() {
        for (int i = 0; i < vnum; i++) {
            std::cout << adjmatrix[i][0];
            for (int j = 1; j < vnum; j++) {
                std::cout << " " << adjmatrix[i][j];
            }
            std::cout << '\n';
        }
    }
    void display_node() {
        if (kind == 'U') {
            for (int i = 0; i < vnum; i++) {
                int cnt = 0;
                for (int j = 0; j < vnum; j++) {
                    if (adjmatrix[i][j] != 0) {
                        cnt++;
                    }
                }
                if (cnt) {
                    std::cout << vertex[i] << ": " << cnt << '\n';
                } else {
                    std::cout << vertex[i] << '\n';
                }
            }
        }
        else if (kind == 'D') {
            for (int i = 0; i < vnum; i++) {
                int cnt1 = 0;
                for (int j = 0; j < vnum; j++) {
                    if (adjmatrix[i][j] != 0) {
                        cnt1++;
                    }
                }
                int cnt2 = 0;
                for (int j = 0; j < vnum; j++) {
                    if (adjmatrix[j][i] != 0) {
                        cnt2++;
                    }
                }
                if (cnt1 || cnt2) {
                    std::cout << vertex[i] << ": " << cnt1 << " " << cnt2 << " " << cnt1 + cnt2 << '\n';
                } else {
                    std::cout << vertex[i] << '\n';
                }
            }
        }
    }
    ~graph() {
        delete[]vertex;
        for (int i = 0; i < vnum; i++) {
            delete[]adjmatrix[i];
        }
        delete[]adjmatrix;
    }
};
int main() {
    int n;
    std::cin >> n;
    while (n--) {
        graph g;
        g.display_array();
        g.display_node();
    }
    return 0;
}