/*********************************************************
 *this file include the method to create the binary tree**
 *the recursion and not recursion method to traverse    **
 *the binary tree(preOrder, inOrder, behindOrder)     ****
 ********************************************************/
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class TreeNode {
public:
	char val;
	TreeNode* lchild;
	TreeNode* rchild;
};

class BinaryTree {
public:
	BinaryTree(TreeNode* t = NULL);
	void create_tree();
	void visit(TreeNode* t);

	void preorder_traverse_tree_not_recursion();
	void preorder_traverse_tree_recursion();

	void inorder_traverse_tree_not_recursion();
	void inorder_traverse_tree_recursion();

	void behindorder_traverse_tree_not_recursion();
	void behindorder_traverse_tree_recursion();

	int get_binary_tree_width();
	bool is_balance();
	int depth();
	int minDepth();
private:
	void init_tree(TreeNode** t);
  	void preorder(TreeNode* t); 	
  	void inorder(TreeNode* t); 	
  	void behindorder(TreeNode* t); 	
	int depth(TreeNode* tree);
	int minDepth(TreeNode* tree);
	bool is_balance(TreeNode* tree, int* depth);
	TreeNode* tree;
	int m_depth;
};

BinaryTree::BinaryTree(TreeNode* t)
	: tree(t) { }

void BinaryTree::visit(TreeNode* t) {
	cout<<t->val<<" ";	
}

void BinaryTree::init_tree(TreeNode** t) {
	char val;
	cin>>val;
	if('#' == val)
		*t = NULL;
	else{
		*t = new TreeNode;
		(*t) -> val = val;

		init_tree( &((*t)->lchild) );
		init_tree( &((*t) -> rchild) );
	}
}

void BinaryTree::create_tree() {
	init_tree(&tree);
}

void BinaryTree::preorder_traverse_tree_not_recursion() {
	TreeNode* t = tree;
	stack<TreeNode*> S;
	while( (t!=NULL) || !S.empty() ) {
		if(t != NULL){
			visit(t);
			S.push(t);
			t = t->lchild;
		} else {
			t = S.top();
			S.pop();
			t = t->rchild;
		}
	}
}

void BinaryTree::inorder_traverse_tree_not_recursion() {
	TreeNode* t = tree;
	stack<TreeNode*> S;
	while( (t!=NULL) || !S.empty() ) {
		if(t != NULL) {
			S.push(t);	
			t = t->lchild;
		} else {
			t = S.top();
			S.pop();
			visit(t);
			t = t->rchild;
		}
	}
}

//
void BinaryTree::behindorder_traverse_tree_not_recursion() {

}

void BinaryTree::preorder(TreeNode* t) {
	if(t) {
		visit(t);
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

void BinaryTree::inorder(TreeNode* t) {
	if(t) {
		inorder(t->lchild);
		visit(t);
		inorder(t->rchild);
	}
}

void BinaryTree::behindorder(TreeNode* t) {
	if(t) {
		behindorder(t->lchild);
		behindorder(t->rchild);
		visit(t);
	}
}

void BinaryTree::preorder_traverse_tree_recursion() {
	preorder(tree);
}

void BinaryTree::inorder_traverse_tree_recursion() {
	inorder(tree);
}

void BinaryTree::behindorder_traverse_tree_recursion() {
	behindorder(tree);
}

int BinaryTree::depth(TreeNode* tree) {
	if(NULL == tree)
		return 0;
	int leftLen = depth(tree->lchild);
	int rightLen = depth(tree->rchild);

	return leftLen > rightLen ? leftLen + 1 : rightLen + 1;
}

int BinaryTree::depth() {
	m_depth = depth(tree);
	return m_depth;
}

/*求树的较小的子树的高度*/
int BinaryTree::minDepth(TreeNode* tree) {
	if(NULL == tree)
		return 0;
	int leftLen = depth(tree->lchild);
	int rightLen = depth(tree->rchild);

	return leftLen < rightLen ? leftLen + 1 : rightLen + 1;
}

int BinaryTree::minDepth() {
	return minDepth(tree);	
}

/*利用“后序遍历”判断二叉树是否是平衡二叉树，并且求出其深度*/
bool BinaryTree::is_balance(TreeNode* tree, int& depth) {
	if(NULL == tree) {
		depth = 0;
		return true;
	}
	
	int left, right;
	if(is_balance(tree->lchild, left) &&
			is_balance(tree->rchild, right))
	{
		int d = leftLen - rightLen;
		if(d<=1 && d>=-1) {
			depth = leftLen > rightLen ? leftLen+1 : rightLen+1;
			return true;
		}
	}

	return false;
}

bool BinaryTree::is_balance(){
	return is_balance(tree, &m_depth);
}

/*计算二叉树宽度，采用的方法是：遍历得到每一层的宽度**
 *记录下来与当前最大的宽度进行对比，得到最大的宽度 */
int BinaryTree::get_binary_tree_width() {
	if(nullptr == tree)
		return 0;
	queue<TreeNode*> Q;
	Q.push(tree);

	int width = 1; //当前最大的层次宽度
	int curWidth = 1;//当前层次的宽度（节点的个数）
	int nextWidth = 0;//下一层次的宽度

	while(!Q.empty()) {
		while(0 != curWidth) {
			TreeNode* pTemp = Q.front();
			Q.pop();
			--curWidth;
			if(pTemp->lchild) {
				Q.push(pTemp->lchild);
				++nextWidth;
			}

			if(pTemp->rchild) {
				Q.push(pTemp->rchild);
				++nextWidth;
			}
		}

		if(nextWidth > width) 
			width = nextWidth;
		curWidth = nextWidth;
		nextWidth = 0;
	}

	return width;
}
