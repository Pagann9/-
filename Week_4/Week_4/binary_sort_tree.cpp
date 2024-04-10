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

void visit(NodePtr);  //�������
//����ӿ�
Status preorderR(NodePtr root);
Status inorderR(NodePtr root);
Status postorderR(NodePtr root);
//ɾ���ӿ�
ElemType Delete(NodePtr r_temp,ElemType _delete, BinarySortTreePtr Root);
//ɾ������ʱѰ��Ҷ�ӽ������滻
NodePtr Find(NodePtr r_temp);
//ɾ�����滻��Ҷ�ӽ��
void r_Delete(NodePtr r_temp);
//Ѱ�Ҵ�ɾ��Ҷ�ӽ���ǰһ�ڵ�
NodePtr delete_Find(NodePtr r_find, NodePtr r_temp);

extern BinarySortTreePtr Root;
Status N = 1;  //���ڸ��ڵ㸳ֵ
Status h = 0;  //������ʱָ���߶�
std::stack <Node*> childstack;  //���ڷǵݹ����ʱ��ջ

Status Menu_1()
{
	Status menu;
	cout << "1.����\n2.����\n3.ɾ��\n4.����\n0.exit\nplease input your choose��";
	cin >> menu;
	return menu;
}

Status Menu_2()
{
	Status menu;
	cout << "1.�������\n2.�������\n3.�������\n4.��α���\n0.exit\nplease input your choose��";
	cin >> menu;
	return menu;
}

Status Menu_3()
{
	Status menu;
	cout << "1.�ݹ�\n2.�ǵݹ�\n0.exit\nplease input your choose��";
	cin >> menu;
	return menu;
}

Status BST_levelOrder(BinarySortTreePtr Root, void(*visit)(NodePtr))
{
	NodePtr r_temp = Root->root;;
	queue<NodePtr>q;  //����
	q.push(r_temp);
	while (!q.empty())
	{
		r_temp = q.front();
		//�����󵯳�
		visit(r_temp);  
		q.pop();
		//�ֱ���ڵ���ҽڵ������
		if(r_temp->left!=NULL) 	q.push(r_temp->left); 
		if (r_temp->right != NULL) 	q.push(r_temp->right);
	}
	return succeed;
}

Node* generation(Status h)  //�������Ľӿ�
{
	if (h < 2)  //���Ʋ��
	{
		Node* root = new(Node);  //�½��ڵ�
		root->value = N;  //��ֵ
		N++;  //�任N������һ�ڵ�
		root->left = generation(h + 1);  //�ݹ鴴��������
		root->right = generation(h + 1);  //�ݹ鴴��������
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
	//�������ڵ�
	Root->root = new Node;
	Root->root->value = N;
	N++;  
	ini_temp = Root->root;
	Status h = 0;  //��h��ֵ���ڵݹ����ֹ����
	ini_temp->left = generation(0);  //����ӿڴ���������
	ini_temp->right = generation(0);  //����ӿڴ���������
	return succeed;
}

Status BST_insert(BinarySortTreePtr Root, ElemType _insert)
{
	NodePtr r_temp = Root->root,r_new;
	do
	{
		if (r_temp->value == _insert) return false;  //��������ڵ��Ƿ����
		//�ȽϽڵ������ֵ���ҵ��������ȷλ��
		if (r_temp->right != NULL && r_temp->right->value <= _insert) r_temp = r_temp->right;  
		else if (r_temp->left != NULL) r_temp = r_temp->left;
	} while (r_temp->left != NULL || r_temp->right != NULL);
	//�½��ڵ�
	r_new = new(Node);
	r_new->left = r_new->right = NULL;
	r_new->value = _insert;
	//����
	if (r_temp->left != NULL && r_temp->right == NULL) r_temp->right = r_new;
	else r_temp->left = r_new;
	return succeed;
}

Status BST_delete(BinarySortTreePtr Root, ElemType _delete)
{
	NodePtr r_temp = Root->root;
	//�ֱ������������������
	if (Delete(r_temp->left, _delete, Root) == succeed) return succeed;
	else if (Delete(r_temp->right, _delete,Root) == false) return succeed;
	return false;
}

ElemType Delete(NodePtr r_temp,ElemType _delete, BinarySortTreePtr Root)
{
	NodePtr r_delete,r_prev;
	if (r_temp == NULL) return false;  //�Ҳ�����ɾ���ڵ㷵��false
	if (r_temp->value == _delete)
	{
		//ֻ��һ���ӽڵ�
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
		//�����ӽڵ�
		else if (r_temp->right != NULL && r_temp->left != NULL)
		{
			r_delete = Find(r_temp->left);
			r_temp->value = r_delete->value;
			r_Delete(r_temp->left);
			return succeed;
		}
		//Ҷ�ӽ��
		else
		{
			r_prev = delete_Find(Root->root,r_temp);
			if (r_prev->left->value == r_temp->value) r_prev->left = NULL;
			else r_prev->right = NULL;
			return succeed;
		}
	}
	//�ֱ�ݹ���������������
	ElemType leftResult = Delete(r_temp->left, _delete,Root);
	ElemType rightResult = Delete(r_temp->right, _delete, Root);
	//����
	if (leftResult == false && rightResult == false) {
		return false;
	}
}

NodePtr delete_Find(NodePtr r_find,NodePtr r_temp)
{
	if (r_find != NULL) {
		//�ҵ��丸�ڵ㷵��
		if (r_find->left == r_temp || r_find->right == r_temp) {
			return r_find;
		}
		else {
			//�ֱ�ݹ������������������
			NodePtr leftResult = delete_Find(r_find->left, r_temp);
			NodePtr rightResult = delete_Find(r_find->right, r_temp);
			//����
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
		//������Ѱ���丸�ڵ�
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
	//ɾ������
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
		//�����������ݷֲ��ص㣬�����������������½Ǳ���Ѱ�Ҵ��滻�ڵ�
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
		//�ҵ��ڵ㷵��
		if (r_temp->value == _search) return succeed;
		//�ȴ�С�����������ʵ�λ��
		if (r_temp->right != NULL && r_temp->right->value <= _search) r_temp = r_temp->right;
		else if(r_temp->left != NULL) r_temp = r_temp->left;
	} while (r_temp->left != NULL && r_temp->right != NULL);
	return false;
}

Status BST_preorderI(BinarySortTreePtr Root, void(*visit)(NodePtr root))
{
	NodePtr r_temp = Root->root;
	if (r_temp == NULL) return false;  //������Ƿ�Ϊ��
	while (r_temp != NULL || !childstack.empty())
	{
		if (r_temp != NULL)
		{
			visit(r_temp);  //����
			if (r_temp->right != NULL)  //���ҽڵ���ջ
				childstack.push(r_temp->right);
			r_temp = r_temp->left;  //��������ڵ�
		}
		else  //��������������󵯳��ҽڵ�
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
	if (root == NULL) return succeed;  //�п�
	visit(root);  //����
	//��ǰ������ݹ�
	preorderR(root->left);
	preorderR(root->right);
}

Status inorderR(NodePtr root)
{
	if (root == NULL) return succeed;  //�п�
	//����������ݹ�
	inorderR(root->left);
	visit(root);
	inorderR(root->right);
}

Status postorderR(NodePtr root)
{
	if (root == NULL) return succeed;  //�п�
	//������������еݹ�
	inorderR(root->left);
	inorderR(root->right);
	visit(root);
}

Status BST_inorderI(BinarySortTreePtr Root, void(*visit)(NodePtr))
{
	NodePtr r_temp = Root->root;
	if (r_temp == NULL) return false;  //�п�
	while (r_temp != NULL || !childstack.empty())
	{
		if (r_temp != NULL)
		{
			childstack.push(r_temp);  //����ڵ���ջ
			r_temp = r_temp->left;
		}
		else  //��������Ҷ�ӽ�㣬��r_temp��ֵΪ���ٴ�ѭ����ø��ڵ���ҽڵ���б���
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
	NodePtr r_lastvisit = NULL;  //�п�
	if (r_temp == NULL) return false;
	do
	{
		while (r_temp != NULL)
		{
			childstack.push(r_temp);  //��ջ
			r_temp = r_temp->left;
		}
		while (!childstack.empty())  //ջ��Ϊ�գ���������
		{
			r_temp = childstack.top();
			if (r_temp->right == NULL || r_temp->right == r_lastvisit)
			{
				visit(r_temp);
				r_lastvisit = r_temp;  //��¼���������Ľڵ㣬��ֹ��ջ���Ľڵ��ٴα�����
				childstack.pop();
			}
			else
			{
				r_temp = r_temp->right;  //r_temp�������ҽڵ�
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
