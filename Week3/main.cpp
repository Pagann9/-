#include"T4.h"
#include<iostream>
#include <fstream>
#include <chrono>
#include <stdlib.h>
using namespace std;

int _no, _max;  //数据量、最大值
LIST* head;

int main()
{
    int _menu;
    cout << "please input 'No Max': " <<endl;
    cin >> _no >>_max; //输入
    putout();  //放入数据到文件中
    putin();  //从文件中获取数据
    _menu=menu_1();  //菜单
    auto start = std::chrono::high_resolution_clock::now();  //计时起点
    switch (_menu)
    {
    case 1:InsertSort(); break;  //插入排序
    case 2:MergeSort(_no); break;  //归并
    case 3:QuickSort();  break;  //快排
    case 4:CountSort(); break;  //计数
    case 5:RadixCountSort();  break;  //基数计数排序
    case 6:system("cls"); menu_2(); Sort(); break;  //小量数据多次排序
    case 0:break;  //退出
    default:cout << "error\n";  //报错
    }
    auto finish = std::chrono::high_resolution_clock::now();  //计时终点
    std::chrono::duration<double> elapsed = finish - start;  //获取时间
    std::cout << "Sorting took " << elapsed.count() << " seconds\n";  //输出时间
    return 0;
}
