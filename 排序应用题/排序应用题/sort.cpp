#include "sort.h"

int menu()
{
	int _menu;  
	cout << "1.��ɫ����\n2.���������ҵ�k�����\n0.exit\nplease input your choose��";  
	cin >> _menu;
	return _menu;
}

void swap(vector<int>&Arr,int n1, int n2)  //��������
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
	cin >> N >> max;  //�������鳤�ȼ����ֵ
	Arr = generate_2(N,max);  //��������
	int k;
	cout << "please input the k number:";
	cin >> k;  //������Ҫ���k
	if (k > N)  //������Ҫ�󱨴�
	{
		cout << "error" << endl;
		return;
	}
	cout<<"The k number is:"<<qsort(Arr, 0, N - 1, k);  //������
}

int qsort(vector<int>& Arr, int begin, int end,int k)
{
	int pivoIndex = 0;
	if (begin <= end)
	{
		pivoIndex = partition(Arr, begin, end);  //����
		if (pivoIndex == k-1)  //��ȡ������Ҫ��Ĳ��յ�
			return Arr[k-1];  //����
		else if (pivoIndex < k-1)
			return qsort(Arr, pivoIndex + 1, end, k);  //����õ���k��ߵݹ�ǰ��Ĳ��֣�ֱ���ҵ�kֵ
		else
			return qsort(Arr, begin, pivoIndex - 1, k); //����õ���k�ұߵݹ����Ĳ��֣�ֱ���ҵ�kֵ
	}
	return -1;  //�Ҳ�������
}

int partition(vector<int>& Arr, int begin, int end)
{
	int pivot = Arr[end];  //�趨������
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
	}  //��Ԫ�طŵ���ȷλ��
	int t = Arr[end];
	Arr[end] = Arr[i + 1];
	Arr[i + 1] = t;  //�����趨������
	return i + 1;  //����λ��
}

void colour_sort()
{
	vector<int>Arr;
	int N;
	cout << "please input length:";
	cin >> N;
	Arr = generate_1(N);  //��������
	int begin = 0, mid, end = N-1;  //����ͷβ���յ㼰������
	for (mid = 0; mid < end; mid++)
	{
		if (Arr[mid] == 0)  //����0��ǰ���������
		{
			swap(Arr,mid, begin);
			begin++;
		}
		else if (Arr[mid] == 2)
		{
			swap(Arr,mid, end);  //����2�ͺ����������
			end--;
			mid--;  //��ֹ��������Ϊ2�����±����õ�
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
		Arr[i] = (rand() + 3) % 3;  //���ֵΪ2
		cout << Arr[i] << " ";
	}
	return Arr;
}

vector<int> generate_2(int N,int max)
{
	vector<int>Arr(N);
	for (int i = 0; i < N; i++)
	{
		Arr[i] = (rand() + max+1) % (max+1);  //�����������������ֵ�������
		cout << Arr[i] << " ";
	}
	return Arr;
}
