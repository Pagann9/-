#include "sort.h"

int main()
{
    int _menu;
    _menu = menu();  //菜单
    switch (_menu) 
    {
    case 1:colour_sort(); break;  //颜色排序
    case 2:k_sort(); break;  //找第k小的数
    default:cout << "error\n";  //报错
    }
    return 0;
}
