/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量

给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

示例 1:

输入:
11110
11010
11000
00000

输出: 1
示例 2:

输入:
11000
11000
00100
00011

输出: 3

 */
//DFS: 擦除所有连接的‘1’
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    eraseIslands(grid, i, j);
                }
            }
        }
        return islands;
    }
private:
    void eraseIslands(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == 0)
            return ;
        grid[i][j] = 0;
        eraseIslands(grid, i - 1, j);
        eraseIslands(grid, i + 1, j);
        eraseIslands(grid, i, j - 1);
        eraseIslands(grid, i, j + 1);
    }
};

//BFS: 广度优先搜索
/*
广度优先搜索类似于树的层次遍历过程。它需要借助一个队列来实现。
1.准备工作：创建一个visited数组，用来记录已被访问过的顶点；创建一个队列，用来存放每一层的顶点；初始化图G。

2.从图中的v0开始访问，将的visited[v0]数组的值设置为true，同时将v0入队。

3.只要队列不空，则重复如下操作：
    (1)队头顶点u出队。
    (2)依次检查u的所有邻接顶点w，若visited[w]的值为false，则访问w，并将visited[w]置为true，同时将w入队。
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0, offset[] = {0, 1, 0, -1, 0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    grid[i][j] = '0';
                    queue<pair<int, int>> todo;
                    todo.push({i, j});
                    while (!todo.empty()) {         //BFS
                        auto p = todo.front();
                        todo.pop();
                        for (int k=0; k < 4; k++) { //遍历 p 即 grid[i][j] 周围的点
                            int r = p.first + offset[k], c = p.second + offset[k + 1];
                            if (r >= 0 && r < m  && c >= 0 && c < n && grid[r][c] == '1') {
                                todo.push({r, c});
                                grid[r][c] = '0';
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};

