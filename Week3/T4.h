#pragma once
#include <malloc.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef struct ListNode
{
     int data;
     ListNode* next;
}ListNode,*LIST;

void putout();
void putin();
void generate();
void disp();
void DestroyList();
int menu_1();
void InsertSort();
void msort(vector<int>& Arr, int begin, int end);
void merge(vector<int>& Arr, int begin, int mid, int end);
void MergeSort(int n);
void QuickSort();
void qsort(vector<int>& Arr, int begin, int end);
int partition(vector<int>& Arr, int begin, int end);
void CountSort();
void RadixCountSort();
int max_element();
int get_digit(int num,int d);
void Sort();
void menu_2();