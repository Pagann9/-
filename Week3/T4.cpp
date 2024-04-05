#include "T4.h"
#include <cstring>

extern int _no, _max;
extern LIST* head;
extern int No;
extern int Max;

void generate()  //��������
{
    LIST* temp_1, * temp_2;
    (*head)->next = NULL;
    temp_1 = temp_2 = head;
    for (int i = 0; i < _no; i++)
    {
        temp_1 = new LIST();
        *temp_1 = new ListNode();
        (*temp_1)->data = 0;
        (*temp_1)->next = NULL;
        (*temp_2)->next = *temp_1;
        temp_2 = temp_1;
    }
}

void disp()  //�����������
{
    LIST it;
    it = (*head)->next;
    while (it != NULL)
    {
        cout << it->data << endl;
        it = it->next;
    }
}

void DestroyList()  //��������
{
    LIST p;
    if (head == NULL)
    {
        printf("����Ϊ�գ�\n");  //��������
        return;
    }
    p = *head;
    while (p != NULL)
    {
        *head = p->next;  //ɾ��ͷ������
        free(p);
        p = *head;
    }
    if (*head != NULL)
        cout << "error" << endl;
}

int menu_1()
{
    int _menu;
    cout << "1.InsertSort\n2.MergeSort\n3.QuickSort\n4.CountSort\n5.RadixCountSort\n6.Sort multiple times\n0.exit\nplease input your choose:";
    cin >> _menu;
    return _menu;
}

void menu_2()  //С�������������ѡ�����򷽷�
{
    int _menu;
    cout << "1.InsertSort\n2.MergeSort\n3.QuickSort\n4.CountSort\n5.RadixCountSort\n0.exit\nplease input your choose and sort time:" ;
}

void InsertSort()

{
    int flag=1;
    LIST p_Prev,p_Flag,p_Cur,p_Temp,p_Follow;  
    //��������������ָ�룬�����������ָ�룬����δ������ָ�룬tempָ�룬���prevָ���ǰһ�ڵ�ָ��
    p_Flag = (*head)->next->next;
    while (p_Flag->next != NULL)
    {
        flag = 1;
        p_Follow = *head;
        p_Prev = (*head)->next;
        p_Cur = p_Flag->next;
        while (p_Prev != p_Flag)  //prev������������
        {
            if (p_Cur->data < p_Prev->data)  //���������ֱ�curָ������󣬲��뵽����������
            {
                p_Flag->next = p_Cur->next;
                p_Follow->next = p_Cur;
                p_Cur->next = p_Prev;
                flag = 0; break;  //flag����Ƿ���ڷ�������������
            }
            p_Follow = p_Prev;
            p_Prev = p_Prev->next;
        }
        if (flag == 1)  //�����ϣ�cur���뵽flagǰ
        {
            p_Flag->next = p_Cur->next;
            p_Cur->next = p_Flag;
            p_Follow->next = p_Cur;
        }
    }
    p_Temp = (*head)->next; 
    while (p_Temp->next != p_Flag) {  //���flagָ��ǰһ�ڵ�
        p_Temp = p_Temp->next;
    }  
    p_Prev = (*head)->next;
    p_Follow = *head;
    while (p_Prev != p_Flag)  //��������
    {
        if (p_Flag->data < p_Prev->data)  //���������ֱ�flagָ������󣬽�flag�ڵ���뵽����������
        {
            p_Temp->next = NULL;  //�������һ���ڵ�ָ��NULL����ֹ����ѭ��
            p_Flag->next = p_Prev;
            p_Follow->next = p_Flag;
            flag = 0; break;
        }
        p_Follow = p_Follow->next;
        p_Prev = p_Follow->next;
    }
}

void merge(vector<int>& Arr, int begin, int mid, int end)
{
    int n1 = mid - begin + 1;
    int n2 = end - mid;
    int pos = begin;
    vector<int>B(n1), E(n2);
    for (int i = 0; i < n1; i++)  //����
        B[i] = Arr[begin + i];
    for (int j = 0; j < n2; j++)  //����
        E[j] = Arr[mid + 1 + j];
    int i = 0, j = 0, k = begin;
    while (i < n1 && j < n2)
    {
        if (B[i] <= E[j])
        {
            Arr[k] = B[i];
            i++;
        }
        else
        {
            Arr[k] = E[j];
            j++;
        }
        k++;
    }  //��Ԫ�طŵ���ȷ��λ����
    while (i < n1)
    {
        Arr[k] = B[i];
        i++; k++;
    }
    while (j < n2)
    {
        Arr[k] = E[j];
        j++; k++;
    }  //��ʣ�µ�Ԫ�طŻ�������
}

void msort(vector<int>& Arr, int begin, int end)
{
    if (begin < end)
    {
        int mid = (begin + end) / 2;
        msort(Arr, begin, mid);  //����
        msort(Arr, mid + 1, end);  //����
        merge(Arr, begin, mid, end);  //�鲢
    }
}

void MergeSort(int n)
{
    std::vector<int> Arr,tempArr;
    LIST temp;
    temp = (*head)->next;
    while (temp != NULL)
    {
        Arr.push_back(temp->data);
        temp = temp->next;
    }  //���������ݱ��浽�����з�������
    msort(Arr, 0, n- 1);
    tempArr.clear();
}


void QuickSort()
{
    LIST temp;
    vector<int>Arr;
    temp = (*head)->next;
    while (temp != NULL)
    {
        Arr.push_back(temp->data);
        temp = temp->next;
    }
    qsort(Arr, 0, _no-1);
}

void qsort(vector<int>& Arr, int begin, int end)
{
    if (begin < end)
    {
        int pivoIndex = partition(Arr,begin,end);  //����
        qsort(Arr, begin, pivoIndex - 1);    //�ݹ�
        qsort(Arr, pivoIndex + 1, end);  //�ݹ�
    }
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
    }  //��Ԫ�طŵ���ȷ��λ����
    int t = Arr[end];
    Arr[end] = Arr[i+1];
    Arr[i+1] = t;  //����������
    return i+1;
}

void CountSort()
{
    LIST temp;
    vector<int>Arr;
    temp = (*head)->next;
    while (temp != NULL)
    {
        Arr.push_back(temp->data);
        temp = temp->next;
    }  //���������ݱ��浽�����з�������
    int count_Max, count_Min;
    count_Max = count_Min = Arr[0];
    for (int i = 1; i < _no; i++)
    {
        if (Arr[i] > count_Max) count_Max = Arr[i];
        if (Arr[i] < count_Min) count_Min = Arr[i];
    }  //Ѱ�������Сֵ
    int* count = (int*)malloc(sizeof(int) * (count_Max - count_Min+1));  
    memset(count, 0, sizeof(int)* (count_Max - count_Min+1));  //�½���������
    for (int i = 0; i < _no; i++)
        count[Arr[i] - count_Min]++;  //����
    for (int i = 1; i < count_Max - count_Min+1; i++)
        count[i] = count[i] + count[i - 1];  //�ۻ�
    int* output = (int*)malloc(sizeof(int) * (_no));
    memset(output, 0, sizeof(int) * (_no));  //�½��������
    for (int i = 0; i < _no; i++)
    {
        output[count[Arr[i] - count_Min]-1] = Arr[i];  
        count[Arr[i] - count_Min]--;
    }  //��Ž��
}

void RadixCountSort()
{
    int max_num = max_element();  //Ѱ���������
    int digits = 0;
    while (max_num != 0)
    {
        max_num = max_num / 10;
        digits++;
    }  //�������λ��
    vector<vector<int>>buckets(10);  //�½���ά����
    vector<int>Arr(_no);
    LIST temp = (*head)->next;
    int d = 0;
    while(temp!=NULL && d < _no)
    {
        Arr[d]=temp->data;
        temp = temp->next;
        d++;
    }  //���������ݱ��浽�����з�������
    for (int i = 1; i <= digits; i++)
    {
        buckets.clear();  
        vector<vector<int>>buckets(10);  //ÿ�ΰ�λ����ǰ��ղ������µĶ�ά����
         for(int j=0;j<_no;j++)
        {
            int digitval = get_digit(Arr[j], i);  //��ȡλ�ϵ���
            buckets[digitval].push_back(Arr[j]);  //�������ŵ���Ӧ������
        }
         int j = 0;
        for (const auto&row:buckets)
        {
            for (int num : row)
            {
                Arr[j] = num; j++;
            }
        }  //һһ��˳�������滻ԭʼ�����γ��µ�˳��
    }
    buckets.clear();
}

int max_element()
{
    LIST temp;
    temp = (*head)->next;
    int maxnum = temp->data;
    while (temp != NULL)
    {
        if (temp->data > maxnum) maxnum = temp->data;
        temp = temp->next;
    }  //�������������ֵ
    return maxnum;  //�������ֵ
}

int get_digit(int num, int d)
{
    for (int i = 1; i <= d; i++)
        num = num / 10;
    return num % 10;  //����λ�ϵ���
}

void Sort()
{
    int _menu, time;
    cin >> _menu >> time;  //��������ʽ���������
    switch (_menu)
    {
    case 1:for(int i=0;i<time;i++) InsertSort(); break;
    case 2:for (int i = 0; i < time; i++) MergeSort(_no); break;
    case 3:for (int i = 0; i < time; i++) QuickSort();  break;
    case 4:for (int i = 0; i < time; i++) CountSort(); break;
    case 5:for (int i = 0; i < time; i++) RadixCountSort();  break;
    case 0:break;
    default:cout << "error\n";
    }  //����ѭ������
}

void putout()
{
    std::ofstream outFile("outfile.txt");
    if (!outFile)  //���ļ�ʧ�ܱ���
    {
        std::cerr << "fail to open the file" << std::endl;
        return;
    }
    head = new LIST();
    *head = new ListNode();
    generate();  //��������
    LIST it = (*head)->next;
    while(it!=NULL)
    {
        it->data = (rand()+Max) % _max;  //���������
        outFile << it->data << "\n";  //�����ݷŵ��ļ���
        it = it->next;
    }
    outFile.close();  //�ر��ļ�
    DestroyList();  //��������
}

void putin()
{
    std::ifstream outFile("outfile.txt");
    if (!outFile)  //���ļ�ʧ�ܱ���
    {
        std::cerr << "fail to open the file" << std::endl;
        return;
    }
    head = new LIST();
    *head = new ListNode();
    generate();  //��������
    LIST it = (*head)->next;
    while (it != NULL)
    {
        outFile >> it->data;  //���ļ��ж�ȡ����
        it = it->next;
    }
    outFile.close();  //�ر��ļ�
}


