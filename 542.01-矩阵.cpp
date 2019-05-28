/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 ??

????? 0 ? 1 ???????????????? 0 ????

??????????? 1 ?

?? 1: 
??:

0 0 0
0 1 0
0 0 0
??:

0 0 0
0 1 0
0 0 0
?? 2: 
??:

0 0 0
0 1 0
1 1 1
??:

0 0 0
0 1 0
1 2 1
??:

???????????? 10000?
????????????? 0?
???????????????: ????????

 */
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<pair<int, int>> dirs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});
        deque<pair<int, int>> que;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j]) 
                    matrix[i][j] = INT_MAX;
                else 
                    que.push_back({i, j});  //??0??????0??
            }
        }

        //BFS
        while (!que.empty()) {
            auto q = que.front();   //??????0?
            que.pop_front();
            for (auto dir : dirs) { //??????
                int r = q.first + dir.first;
                int c = q.second + dir.second;
                if (r >= row || c >= col || r < 0 || c < 0) 
                    continue;
                if (matrix[r][c] >= matrix[q.first][q.second] + 1) {    //?????
                    matrix[r][c] = matrix[q.first][q.second] + 1;       //?????
                    que.push_back({r, c});
                }
            }
        }

        return matrix;
    }
};

