#include <iostream>
#include "binary_sort_tree.h"
using namespace std;

//菜单
Status Menu_1();
Status Menu_2();
Status Menu_3();
//接口
void printnumber_1(BinarySortTreePtr);
void printnumber_2(BinarySortTreePtr);
void printnumber_3(BinarySortTreePtr);
void printnumber_4(BinarySortTreePtr);
void printnumber_5(BinarySortTreePtr);
void printnumber_6(BinarySortTreePtr);
void printnumber_7(BinarySortTreePtr);

BinarySortTreePtr Root;  //根节点

int main()
{
    ElemType menu_1 = 1, menu_2, menu_3, _check;
    BinarySortTree* Root = new(BinarySortTree);
    BST_init(Root);  //创建
    while (menu_1 != 0)
    {
        menu_1 = Menu_1();
        switch (menu_1)
        {
        case 1:
            menu_2 = Menu_2();
            switch (menu_2)
            {
            case 1:
                menu_3 = Menu_3();
                switch (menu_3)
                {
                case 1:printnumber_4(Root); system("pause"); break;
                case 2:printnumber_1(Root); system("pause"); break;
                case 0:break;
                default:cout << "ERROR" << endl; break;
                }break;
            case 2:
                menu_3 = Menu_3();
                switch (menu_3)
                {
                case 1:printnumber_5(Root); system("pause"); break;
                case 2:printnumber_2(Root); system("pause"); break;
                case 0:break;
                default:cout << "ERROR" << endl; break;  //输入不合理报错
                }break;
            case 3:
                menu_3 = Menu_3();
                switch (menu_3)
                {
                case 1:printnumber_6(Root); system("pause"); break;
                case 2:printnumber_3(Root); system("pause"); break;
                case 0:break;
                default:cout << "ERROR" << endl; break;
                }break;
            case 4:printnumber_7(Root); system("pause"); break;
            default:cout << "ERROR" << endl; break;  //输入不合理报错
            }break;
        case 2:
            ElemType _insert;
            cout << "please input number for insert:";
            cin >> _insert;
            _check = BST_insert(Root, _insert);
            if (_check == false) cout << "error" << endl; system("pause"); break;  //待输入节点已存在报错
        case 3:
            ElemType _delete;
            cout << "please input number for delete:";
            cin >> _delete;
            _check = BST_delete(Root, _delete);
            //待删除节点不存在报错
            if (_check == false)  
            {
                cout << "not exist" << endl;
                system("pause");
            }break;
        case 4:
            ElemType _search;
            cout << "please input number for search:";
            cin >> _search;
            _check = BST_search(Root, _search); //根据返回值判断是否存在
            if (_check == succeed) cout << "exist" << endl;
            else
            {
                cout << "not exist" << endl;
                system("pause");
            }break;
        default:cout << "ERROR" << endl; break;  //输入不合理报错
        }
        system("cls");
    }
    return 0;
}