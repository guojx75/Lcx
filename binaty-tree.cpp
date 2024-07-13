#include <vector>
#include <queue>
#include <string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

vector<int> levelOrder(TreeNode* root) {
	queue<TreeNode*> queue;
	queue.push(root);
	vector<int> vec;
	while (!queue.empty()) {
		TreeNode* node = queue.front();
		queue.pop();
		vec.push_back(node->val);
		if (node->left) queue.push(node->left);
		if (node->right) queue.push(node->right);
	}
	return vec;
}

class ArrayBinaryTree {
public:
	ArrayBinaryTree(vector<int> arr) {
		tree = arr;
	}
	int size() {
		return tree.size();
	}
	int val(int i) {
		if (i < 0 || i >= size()) {
			return INT_MAX;
		}
		return tree[i];
	}
	int left(int i) {
		return i * 2 + 1;
	}
	int right(int i) {
		return i * 2 + 2;
	}
	int parent(int i) {
		return (i - 1) / 2;
	}
	vector<int> levelOrder() {
		vector<int> res;
		for (int i = 0; i < size(); i++) {
			if (val(i) != INT_MAX) {
				res.push_back(val(i));
			}
		}
		return res;
	}
	vector<int> preOrder() {
		vector<int> res;
		dfs(0, "pre", res);
		return res;
	}
	vector<int> inOrder() {
		vector<int> res;
		dfs(0, "in", res);
		return res;
	}
	vector<int> postOrder() {
		vector<int> res;
		dfs(0, "post", res);
		return res;
	}
private:
	vector<int> tree;
	void dfs(int i, string order, vector<int>& res) {
		if (val(i) == INT_MAX) return;
		if (order == "pre") res.push_back(val(i));
		dfs(left(i), order, res);
		if (order == "in") res.push_back(val(i));
		dfs(left(i), order, res);
		if (order == "post") res.push_back(val(i));
	}
};

struct AVLNode {
	int val{};
	int height = 0;
	AVLNode* left{};
	AVLNode* right{};
	AVLNode() = default;
	explicit AVLNode(int x): val(x){}
};
int height(AVLNode* node) {
	return node == nullptr ? -1 : node->height;
}
void updateHeight(AVLNode* node) {
	node->height = max(height(node->left), height(node->right)) + 1;
}
int balanceFactor(AVLNode* node) {
	if (node == nullptr) return 0;
	return height(node->left) - height(node->right);
}