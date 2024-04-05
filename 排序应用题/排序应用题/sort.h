#pragma once

#include <iostream>
#include <vector>
using namespace std;

int menu();
void colour_sort();
vector <int> generate_1(int N);
vector <int> generate_2(int N, int max);
void swap(vector<int>& Arr,int n1, int n2);
void k_sort();
int qsort(vector<int>& Arr, int begin, int end,int k);
int partition(vector<int>& Arr, int begin, int end);
