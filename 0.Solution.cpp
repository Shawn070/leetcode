#include <iostream>
#include <string>		//stoi
#include <vector>
#include <algorithm>	//sort	max	min
#include <functional>	//greater<int>()	less<int>()
#include <map>
#include <set>
#include <thread>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr;
        return create(preorder, inorder, 0, inorder.size() - 1, 0);
    }
    // low high 为inorder的搜索范围，index 为preorder的检索位置
    TreeNode* create(vector<int>& preorder, vector<int>& inorder, int low, int high, int index) {
        if (low > high) return nullptr;
        TreeNode* node = new TreeNode(preorder[index]);
        if (low == high) return node;

        // pos 为inorder检索到的位置
        int pos = 0;
        for (int i = low; i <= high; i++) {
            if (inorder[i] == node->val) {
                pos = i;
                break;
            }
        }
        node->left  = create(preorder, inorder, low, pos - 1, index + 1);
        // + (pos - low) 跳过 preorder 中已经在上一个 create 中加入过的结点
        node->right = create(preorder, inorder, pos + 1, high, index + 1 + (pos - low));
        return node;
    }
};


/*
输入
[3,9,20,15,7]   //前序
[9,3,15,20,7]   //中序
输出
[3,9,20,null,null,15,7]
预期结果
[3,9,20,null,null,15,7]
*/

int main(){

    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder  = {9,3,15,20,7};

    Solution s;

    TreeNode * head = s.buildTree(preorder, inorder);

	system("pause");
	return 0;
}