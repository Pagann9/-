#include <random>
#include <iostream>
#include <stack>
#include <queue>
#include "binary_sort_tree.h"

using namespace std;

extern Status Menu_1();
extern Status Menu_2();
extern Status Menu_3();
extern void printnumber_1(BinarySortTreePtr Root);
extern void printnumber_2(BinarySortTreePtr Root);
extern void printnumber_3(BinarySortTreePtr Root);
extern void printnumber_4(BinarySortTreePtr Root);
extern void printnumber_5(BinarySortTreePtr Root);
extern void printnumber_6(BinarySortTreePtr Root);
extern void printnumber_7(BinarySortTreePtr Root);

void visit(NodePtr);  //遍历输出
//排序接口
Status preorderR(NodePtr root);
Status inorderR(NodePtr root);
Status postorderR(NodePtr root);
//删除接口
ElemType Delete(NodePtr r_temp,ElemType _delete, BinarySortTreePtr Root);
//删除操作时寻找叶子结点进行替换
NodePtr Find(NodePtr r_temp);
//删除被替换的叶子结点
void r_Delete(NodePtr r_temp);
//寻找待删除叶子结点的前一节点
NodePtr delete_Find(NodePtr r_find, NodePtr r_temp);

extern BinarySortTreePtr Root;
Status N = 1;  //用于给节点赋值
Status h = 0;  //创建树时指定高度
std::stack <Node*> childstack;  //用于非递归遍历时的栈

Status Menu_1()
{
	Status menu;
	cout << "1.遍历\n2.插入\n3.删除\n4.查找\n0.exit\nplease input your choose：";
	cin >> menu;
	return menu;
}

Status Menu_2()
{
	Status menu;
	cout << "1.先序遍历\n2.中序遍历\n3.后序遍历\n4.层次遍历\n0.exit\nplease input your choose：";
	cin >> menu;
	return menu;
}

Status Menu_3()
{
	Status menu;
	cout << "1.递归\n2.非递归\n0.exit\nplease input your choose：";
	cin >> menu;
	return menu;
}

Status BST_levelOrder(BinarySortTreePtr Root, void(*visit)(NodePtr))
{
	NodePtr r_temp = Root->root;;
	queue<NodePtr>q;  //队列
	q.push(r_temp);
	while (!q.empty())
	{
		r_temp = q.front();
		//遍历后弹出
		visit(r_temp);  
		q.pop();
		//分别将左节点和右节点入队列
		if(r_temp->left!=NULL) 	q.push(r_temp->left); 
		if (r_temp->right != NULL) 	q.push(r_temp->right);
	}
	return succeed;
}

Node* generation(Status h)  //创建树的接口
{
	if (h < 2)  //控制层高
	{
		Node* root = new(Node);  //新建节点
		root->value = N;  //赋值
		N++;  //变换N用于下一节点
		root->left = generation(h + 1);  //递归创建左子树
		root->right = generation(h + 1);  //递归创建右子树
		return root;
	}
	else 	return NULL;
}

extern void printnumber_1(BinarySortTreePtr Root)
{
	BST_preorderI(Root, visit);
}

extern void printnumber_2(BinarySortTreePtr Root)
{
	BST_inorderI(Root, visit);
}

void printnumber_3(BinarySortTreePtr Root)
{
	BST_postorderI(Root, visit);
}

void printnumber_4(BinarySortTreePtr Root)
{
	BST_preorderR(Root, visit);
}

void printnumber_5(BinarySortTreePtr Root)
{
	BST_inorderR(Root, visit);
}

void printnumber_6(BinarySortTreePtr Root)
{
	BST_postorderR(Root, visit);
}

void printnumber_7(BinarySortTreePtr Root)
{
	BST_levelOrder(Root, visit);
}

void visit(NodePtr root)
{
	cout << root->value << " ";
}

Status BST_init(BinarySortTreePtr Root)
{
	NodePtr ini_temp;
	//创建根节点
	Root->root = new Node;
	Root->root->value = N;
	N++;  
	ini_temp = Root->root;
	Status h = 0;  //给h赋值用于递归的终止条件
	ini_temp->left = generation(0);  //进入接口创建左子树
	ini_temp->right = generation(0);  //进入接口创建左子树
	return succeed;
}

Status BST_insert(BinarySortTreePtr Root, ElemType _insert)
{
	NodePtr r_temp = Root->root,r_new;
	do
	{
		if (r_temp->value == _insert) return false;  //检查待插入节点是否存在
		//比较节点与插入值，找到插入的正确位置
		if (r_temp->right != NULL && r_temp->right->value <= _insert) r_temp = r_temp->right;  
		else if (r_temp->left != NULL) r_temp = r_temp->left;
	} while (r_temp->left != NULL || r_temp->right != NULL);
	//新建节点
	r_new = new(Node);
	r_new->left = r_new->right = NULL;
	r_new->value = _insert;
	//插入
	if (r_temp->left != NULL && r_temp->right == NULL) r_temp->right = r_new;
	else r_temp->left = r_new;
	return succeed;
}

Status BST_delete(BinarySortTreePtr Root, ElemType _delete)
{
	NodePtr r_temp = Root->root;
	//分别遍历左子树和右子树
	if (Delete(r_temp->left, _delete, Root) == succeed) return succeed;
	else if (Delete(r_temp->right, _delete,Root) == false) return succeed;
	return false;
}

ElemType Delete(NodePtr r_temp,ElemType _delete, BinarySortTreePtr Root)
{
	NodePtr r_delete,r_prev;
	if (r_temp == NULL) return false;  //找不到待删除节点返回false
	if (r_temp->value == _delete)
	{
		//只有一个子节点
		if (r_temp->left == NULL && r_temp->right != NULL)
		{
			r_temp->value = r_temp->right->value;
			r_temp->left = r_temp->right->left;
			r_temp->right = r_temp->right->right;
			return succeed;
		}
		else if (r_temp->left != NULL && r_temp->right == NULL)
		{
			r_temp->value = r_temp->left->value;
			r_temp->right = r_temp->left->right;
			r_temp->left = r_temp->left->left;
			return succeed;
		}
		//两个子节点
		else if (r_temp->right != NULL && r_temp->left != NULL)
		{
			r_delete = Find(r_temp->left);
			r_temp->value = r_delete->value;
			r_Delete(r_temp->left);
			return succeed;
		}
		//叶子结点
		else
		{
			r_prev = delete_Find(Root->root,r_temp);
			if (r_prev->left->value == r_temp->value) r_prev->left = NULL;
			else r_prev->right = NULL;
			return succeed;
		}
	}
	//分别递归左子树和右子树
	ElemType leftResult = Delete(r_temp->left, _delete,Root);
	ElemType rightResult = Delete(r_temp->right, _delete, Root);
	//报错
	if (leftResult == false && rightResult == false) {
		return false;
	}
}

NodePtr delete_Find(NodePtr r_find,NodePtr r_temp)
{
	if (r_find != NULL) {
		//找到其父节点返回
		if (r_find->left == r_temp || r_find->right == r_temp) {
			return r_find;
		}
		else {
			//分别递归遍历左子树和右子树
			NodePtr leftResult = delete_Find(r_find->left, r_temp);
			NodePtr rightResult = delete_Find(r_find->right, r_temp);
			//报错
			if (leftResult == NULL && rightResult == NULL) {
				return NULL;
			}
		}
	}

}

void r_Delete(NodePtr r_temp)
{
	NodePtr r_prev;
	while (r_temp->left != NULL || r_temp->right != NULL)
	{
		//遍历，寻找其父节点
		if (r_temp->left != NULL && r_temp->right == NULL)
		{
			r_prev = r_temp;
			r_temp = r_temp->left;
		}
		else
		{
			r_prev = r_temp;
			r_temp = r_temp->right;
		}
	}
	//删除操作
	if (r_prev->left == r_temp)
	{
		r_prev->left = NULL;
		free(r_temp);
	}
	else
	{
		r_prev->right = NULL;
	}
}

NodePtr Find(NodePtr r_temp)
{
	while (r_temp->left != NULL || r_temp->right != NULL)
	{
		//根据树的数据分布特点，往树的左子树的右下角遍历寻找待替换节点
		if (r_temp->left != NULL && r_temp->right == NULL)
			r_temp = r_temp->left;
		else
			r_temp = r_temp->right;
	}
	return r_temp;
}

Status BST_search(BinarySortTreePtr Root, ElemType _search)
{
	NodePtr r_temp = Root->root;
	do
	{
		//找到节点返回
		if (r_temp->value == _search) return succeed;
		//比大小，遍历到合适的位置
		if (r_temp->right != NULL && r_temp->right->value <= _search) r_temp = r_temp->right;
		else if(r_temp->left != NULL) r_temp = r_temp->left;
	} while (r_temp->left != NULL && r_temp->right != NULL);
	return false;
}

Status BST_preorderI(BinarySortTreePtr Root, void(*visit)(NodePtr root))
{
	NodePtr r_temp = Root->root;
	if (r_temp == NULL) return false;  //检查树是否为空
	while (r_temp != NULL || !childstack.empty())
	{
		if (r_temp != NULL)
		{
			visit(r_temp);  //遍历
			if (r_temp->right != NULL)  //将右节点入栈
				childstack.push(r_temp->right);
			r_temp = r_temp->left;  //遍历到左节点
		}
		else  //若左子树遍历完后弹出右节点
		{
			r_temp = childstack.top();
			childstack.pop();
		}
	}
	return succeed;
}

Status BST_preorderR(BinarySortTreePtr Root, void(*visit)(NodePtr))
{
	return preorderR(Root->root);
}

Status preorderR(NodePtr root)
{
	if (root == NULL) return succeed;  //判空
	visit(root);  //遍历
	//按前序遍历递归
	preorderR(root->left);
	preorderR(root->right);
}

Status inorderR(NodePtr root)
{
	if (root == NULL) return succeed;  //判空
	//按中序遍历递归
	inorderR(root->left);
	visit(root);
	inorderR(root->right);
}

Status postorderR(NodePtr root)
{
	if (root == NULL) return succeed;  //判空
	//按后序遍历进行递归
	inorderR(root->left);
	inorderR(root->right);
	visit(root);
}

Status BST_inorderI(BinarySortTreePtr Root, void(*visit)(NodePtr))
{
	NodePtr r_temp = Root->root;
	if (r_temp == NULL) return false;  //判空
	while (r_temp != NULL || !childstack.empty())
	{
		if (r_temp != NULL)
		{
			childstack.push(r_temp);  //将左节点入栈
			r_temp = r_temp->left;
		}
		else  //若遍历到叶子结点，将r_temp赋值为空再次循环获得父节点的右节点进行遍历
		{
			r_temp = childstack.top();
			childstack.pop();
			visit(r_temp);
			r_temp = r_temp->right;
		}
	}
	return succeed;
}

Status BST_inorderR(BinarySortTreePtr Root, void(*visit)(NodePtr))
{
	return inorderR(Root->root);
}

Status BST_postorderI(BinarySortTreePtr Root, void(*visit)(NodePtr))
{
	NodePtr r_temp = Root->root;
	NodePtr r_lastvisit = NULL;  //判空
	if (r_temp == NULL) return false;
	do
	{
		while (r_temp != NULL)
		{
			childstack.push(r_temp);  //入栈
			r_temp = r_temp->left;
		}
		while (!childstack.empty())  //栈不为空，继续遍历
		{
			r_temp = childstack.top();
			if (r_temp->right == NULL || r_temp->right == r_lastvisit)
			{
				visit(r_temp);
				r_lastvisit = r_temp;  //记录被遍历过的节点，防止入栈过的节点再次被遍历
				childstack.pop();
			}
			else
			{
				r_temp = r_temp->right;  //r_temp遍历其右节点
				break;
			}
		}
	} while (!childstack.empty());
	return succeed;
}

Status BST_postorderR(BinarySortTreePtr Root, void(*visit)(NodePtr))
{
	return postorderR(Root->root);
}
