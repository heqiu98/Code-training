#include <iostream>
#include <vector>

using namespace std;

int main(){
		int n, k;
		cin >> n >> k;
		
		//创建一个网格并初始化为可放置状态
		vector<vector<bool>> grid(n,vector<bool>(n,true));

		//标记不可放置方块的位置
		for(int i=0; i < k; ++i){
				int y, x;
				cin >> y >> x;
				grid[y][x]= false;
		}

		int maxSquares=0;

		//检查每个 2x2 的方块位置!

		for(int i=0;i<=n-2;++i){
				for (int j=0; j <= n-2; ++j){
						// 检查当前 2x2 是否可以放置
						if (grid[i][j] && grid[i][j+1] && grid[i+1][j] && grid[i+1][j+1]){
									maxSquares++;
									//将已放置方块的位置标记为不可放置(防止重叠)
									grid[i][j] = grid[i][j+1] = grid[i+1][j]= grid[i+1][j+1] = false;
						}
				}
		}
		
		cout<< maxSquares << endl;
		
		return 0;
}