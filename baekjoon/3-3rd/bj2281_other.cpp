#include <iostream>
#include <cstring>//memset
#include <algorithm>//min
using namespace std;

int n, m;
int DP[1001][1001];
int Name[1001];
int M = 999999999;
int exe_count = 0;
int solution(int idx, int len) {
	//이름 다 썼으면
	if (idx > n)
		return 0;

	int& res = DP[idx][len];

	//이미 구한 값이면
	if (res != -1)
		return res;
	exe_count ++;
	//한 칸 내린 경우
	res = (m - len + 1)*(m - len + 1) + solution(idx + 1, Name[idx] + 1);
	
	//같은 칸에 쓰는 경우
	if (len + Name[idx] <= m)
		res = min(res, solution(idx + 1, len + Name[idx] + 1));
	
	return res;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> Name[i];
	}
	memset(DP, -1, sizeof(DP));
	cout << solution(2, Name[1] + 1) << '\n';
    cout << "count " << exe_count << endl;
	return 0;
}