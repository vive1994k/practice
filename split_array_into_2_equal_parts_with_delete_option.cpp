#include <iostream>
#include <vector>
using namespace std;

const int MAX_ARR_SIZE = 50;
const int MAX_ARR_SUM = 1000;

bool is_sum_possible[MAX_ARR_SUM+10][MAX_ARR_SUM+10][MAX_ARR_SIZE+10] = {};

int main() {
	int n;
	cin>>n;
	vector<int> input(n+1);
	for(int i = 1;i<=n;++i)
	{
		cin>>input[i];
	}
	//agar baar baar input leke karna ho to is_sum_possible ko poora false kar dena yahan pe
	is_sum_possible[0][0][0] = true;	//dp ki base condition
	for(int i = 1;i<=n;++i) {
		for(int sum1 = 0;sum1<=MAX_ARR_SUM;++sum1) {
			for(int sum2 = 0;sum2 <= MAX_ARR_SUM; ++sum2) {
				is_sum_possible[sum1][sum2][i] = is_sum_possible[sum1][sum2][i-1];
				if(sum1 >= input[i]) {
					is_sum_possible[sum1][sum2][i] |= is_sum_possible[sum1-input[i]][sum2][i-1];
				}
				if(sum2 >= input[i]) {
					is_sum_possible[sum1][sum2][i] |= is_sum_possible[sum1][sum2-input[i]][i-1];
				}
			}
		}
	}
	int answer = 0;
	for(int j = 0;j<=MAX_ARR_SUM;++j) {
		if(is_sum_possible[j][j][n]) {
			answer = j;
		}
	}
	cout<<answer<<'\n';
	return 0;
}
