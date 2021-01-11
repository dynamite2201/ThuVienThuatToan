#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1000;

struct service {
    long long int a;
    long long int b;
    long long int c;
};
service services[N];
long long int sum[N] = {0};
vector<int> coordinate;

int convert(int x) {
    return (lower_bound(coordinate.begin(), coordinate.end(), x) - coordinate.begin());
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long int n, C;
    cin >> n >> C;

    for (int i = 1; i <= n; ++i) {
        cin >> services[i].a >> services[i].b >> services[i].c;
        coordinate.push_back(services[i].a);
        coordinate.push_back(services[i].b);
    }

    sort(coordinate.begin(), coordinate.end());
    coordinate.resize(unique(coordinate.begin(), coordinate.end()) - coordinate.begin());

    for (int i = 1; i <= n; i++) {
        services[i].a = 2 * convert(services[i].a);
        services[i].b = 2 * convert(services[i].b);
        sum[services[i].a] += services[i].c;
        sum[services[i].b + 1] -= services[i].c;
    }

    int numPoint = 2 * coordinate.size();

    for (int i = 1; i < numPoint; i++) {
        sum[i] += sum[i - 1];
    }

    long long int total = 0;

//     (Số ngày giữa 2 mút) x(Số Tiền)
    for (int i = 1; i <= numPoint - 3; i += 2) {
        total += (coordinate[i / 2 + 1] - coordinate[i / 2] - 1) * min(C, sum[i]);
    }

//     Cộng thêm Tiền các vị trí mút
    for (int i = 0; i <= numPoint - 2; i += 2) {
        total += min(C, sum[i]);
    }
    cout << total;
}