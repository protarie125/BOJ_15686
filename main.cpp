#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using vii = vector<pii>;

vii hus;
vii chs;
vii selected;
int mndist;

void calcDist() {
	auto dist = int{ 0 };
	for (const auto& h : hus) {
		auto hmn = int{ -1 };
		for (const auto& c : selected) {
			auto temp = abs(h.first - c.first) + abs(h.second - c.second);

			if (-1 == hmn) {
				hmn = temp;
			}
			else if (temp < hmn) {
				hmn = temp;
			}
		}

		dist += hmn;
	}

	if (-1 == mndist) {
		mndist = dist;
	}
	else if (dist < mndist) {
		mndist = dist;
	}
}

void solve(int m, int chct, int b) {
	if (selected.size() == m) {
		calcDist();
		return;
	}

	for (auto i = b; i < chct; ++i) {
		selected.push_back(chs[i]);
		solve(m, chct, i + 1);
		selected.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < n; ++j) {
			int x;
			cin >> x;

			if (1 == x) {
				hus.push_back({ i, j });
			}
			else if (2 == x) {
				chs.push_back({ i, j });
			}
		}
	}

	const auto& chct = static_cast<int>(chs.size());

	selected = vii{};
	mndist = -1;
	solve(m, chct, 0);

	cout << mndist;

	return 0;
}