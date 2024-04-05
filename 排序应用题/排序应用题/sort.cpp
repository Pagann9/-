#include "sort.h"

int menu()
{
	int _menu;  
	cout << "1.颜色排序\n2.无序序列找第k大的数\n0.exit\nplease input your choose：";  
	cin >> _menu;
	return _menu;
}

void swap(vector<int>&Arr,int n1, int n2)  //交换数据
{
	int temp;
	temp = Arr[n1];
	Arr[n1] = Arr[n2];
	Arr[n2] = temp;
}

void k_sort()
{
	vector<int>Arr;
	int N,max;
	cout << "please input length and max:";
	cin >> N >> max;  //输入数组长度及最大值
	Arr = generate_2(N,max);  //创建数组
	int k;
	cout << "please input the k number:";
	cin >> k;  //输入所要求的k
	if (k > N)  //不符合要求报错
	{
		cout << "error" << endl;
		return;
	}
	cout<<"The k number is:"<<qsort(Arr, 0, N - 1, k);  //输出结果
}

int qsort(vector<int>& Arr, int begin, int end,int k)
{
	int pivoIndex = 0;
	if (begin <= end)
	{
		pivoIndex = partition(Arr, begin, end);  //分组
		if (pivoIndex == k-1)  //获取到符合要求的参照点
			return Arr[k-1];  //返回
		else if (pivoIndex < k-1)
			return qsort(Arr, pivoIndex + 1, end, k);  //如果该点在k左边递归前面的部分，直到找到k值
		else
			return qsort(Arr, begin, pivoIndex - 1, k); //如果该点在k右边递归后面的部分，直到找到k值
	}
	return -1;  //找不到报错
}

int partition(vector<int>& Arr, int begin, int end)
{
	int pivot = Arr[end];  //设定参照书
	int i = begin - 1;
	for (int j = begin; j < end; j++)
	{
		if (Arr[j] <= pivot)
		{
			i++;
			int t = Arr[j];
			Arr[j] = Arr[i];
			Arr[i] = t;
		}
	}  //将元素放到正确位置
	int t = Arr[end];
	Arr[end] = Arr[i + 1];
	Arr[i + 1] = t;  //重新设定参照数
	return i + 1;  //返回位置
}

void colour_sort()
{
	vector<int>Arr;
	int N;
	cout << "please input length:";
	cin >> N;
	Arr = generate_1(N);  //创建数组
	int begin = 0, mid, end = N-1;  //设立头尾参照点及遍历点
	for (mid = 0; mid < end; mid++)
	{
		if (Arr[mid] == 0)  //等于0和前面的数交换
		{
			swap(Arr,mid, begin);
			begin++;
		}
		else if (Arr[mid] == 2)
		{
			swap(Arr,mid, end);  //等于2和后面的数交换
			end--;
			mid--;  //防止待交换数为2，重新遍历该点
		}
	}
	cout << endl;
	for (int i = 0; i < N; i++) cout << Arr[i] << " ";
}

vector <int> generate_1(int N)
{
	vector<int>Arr(N);
	for (int i = 0; i < N; i++)
	{
		Arr[i] = (rand() + 3) % 3;  //最大值为2
		cout << Arr[i] << " ";
	}
	return Arr;
}

vector<int> generate_2(int N,int max)
{
	vector<int>Arr(N);
	for (int i = 0; i < N; i++)
	{
		Arr[i] = (rand() + max+1) % (max+1);  //产生不大于设立最大值的随机数
		cout << Arr[i] << " ";
	}
	return Arr;
}
