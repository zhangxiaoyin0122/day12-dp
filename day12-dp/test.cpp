#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		int row = triangle.size();
		for (int i = row - 2; i >= 0; i--) {
			for (int j = 0; j <= i; j++) {
				triangle[i][j] = min(triangle[i + 1][j], triangle[i + 1][j + 1]) + triangle[i][j];
			}
		}
		return triangle[0][0];
	}
};

class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m < 1 || n < 1)
			return 0;
		vector<vector<int> > v(m, vector<int>(n, 1));
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				v[i][j] = v[i - 1][j] + v[i][j - 1];
			}
		}
		return v[m - 1][n - 1];
	}
};

class Solution {
public:
	int minPathSum(vector<vector<int> >& grid) {
		if (grid.empty())
			return 0;
		int row = grid.size();
		int col = grid[0].size();
		for (int i = 1; i < row; i++)
			grid[i][0] = grid[i - 1][0] + grid[i][0];
		for (int j = 1; j < col; j++)
			grid[0][j] = grid[0][j - 1] + grid[0][j];
		for (int i = 1; i < row; ++i) {
			for (int j = 1; j < col; ++j) {
				grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
			}
		}
		return grid[row - 1][col - 1];
	}
};

//˼·
//1.f[i][j] = ��i����Ʒ����Ϊjʱ��ֵ������
//2.����ת������
//1 > j >= A[i] ����: f[i][j] = max(f[i][j - A[i]] + V[i], f[i - 1][j])
//2 > j < A[i] ���� f[i][j] = f[i - 1][j]
//	3.��ʼ������Ϊ�ڷ�0����Ʒ������Ϊjʱ��û�м�ֵ�ģ�dp[0][j] = 0
	int backPackII(int m, vector<int> &A, vector<int> &V)
{
	int n = A.size() + 1;
	vector<vector<int>> dp(n, vector<int>(m + 1, 0));
	dp[0][m] = 0;
	for (int i = 1; i <= A.size(); ++i)
	{
		for (int j = m; j >= 0; --j)
		{
			if (j >= A[i - 1])   //����ʹ��A[i-1]����ΪA��V�����±��ԭ��
				dp[i][j] = max(dp[i - 1][j - A[i - 1]] + V[i - 1], dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	//ѭ�������������ֵ����Ϊ��һ�������������ŵ�
	int result = 0;
	for (int i = 0; i <= m; ++i)
		if (result < dp[n - 1][i])
			result = dp[n - 1][i];
	return result;
}