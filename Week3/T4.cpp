#include "T4.h"
#include <cstring>

extern int _no, _max;
extern LIST* head;
extern int No;
extern int Max;

void generate()  //创建链表
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

void disp()  //遍历输出链表
{
    LIST it;
    it = (*head)->next;
    while (it != NULL)
    {
        cout << it->data << endl;
        it = it->next;
    }
}

void DestroyList()  //销毁链表
{
    LIST p;
    if (head == NULL)
    {
        printf("链表为空！\n");  //检查空链表
        return;
    }
    p = *head;
    while (p != NULL)
    {
        *head = p->next;  //删除头结点后结点
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

void menu_2()  //小数据量多次排序选择排序方法
{
    int _menu;
    cout << "1.InsertSort\n2.MergeSort\n3.QuickSort\n4.CountSort\n5.RadixCountSort\n0.exit\nplease input your choose and sort time:" ;
}

void InsertSort()

{
    int flag=1;
    LIST p_Prev,p_Flag,p_Cur,p_Temp,p_Follow;  
    //遍历已排序区间指针，标记已排序区指针，遍历未排序区指针，temp指针，标记prev指针的前一节点指针
    p_Flag = (*head)->next->next;
    while (p_Flag->next != NULL)
    {
        flag = 1;
        p_Follow = *head;
        p_Prev = (*head)->next;
        p_Cur = p_Flag->next;
        while (p_Prev != p_Flag)  //prev遍历已排序区
        {
            if (p_Cur->data < p_Prev->data)  //若存在数字比cur指向的数大，插入到已排序区中
            {
                p_Flag->next = p_Cur->next;
                p_Follow->next = p_Cur;
                p_Cur->next = p_Prev;
                flag = 0; break;  //flag标记是否存在符合条件的数字
            }
            p_Follow = p_Prev;
            p_Prev = p_Prev->next;
        }
        if (flag == 1)  //不符合，cur插入到flag前
        {
            p_Flag->next = p_Cur->next;
            p_Cur->next = p_Flag;
            p_Follow->next = p_Cur;
        }
    }
    p_Temp = (*head)->next; 
    while (p_Temp->next != p_Flag) {  //标记flag指针前一节点
        p_Temp = p_Temp->next;
    }  
    p_Prev = (*head)->next;
    p_Follow = *head;
    while (p_Prev != p_Flag)  //遍历链表
    {
        if (p_Flag->data < p_Prev->data)  //若存在数字比flag指向的数大，将flag节点插入到已排序区中
        {
            p_Temp->next = NULL;  //链表最后一个节点指向NULL，防止链表循环
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
    for (int i = 0; i < n1; i++)  //分区
        B[i] = Arr[begin + i];
    for (int j = 0; j < n2; j++)  //分区
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
    }  //把元素放到正确的位置上
    while (i < n1)
    {
        Arr[k] = B[i];
        i++; k++;
    }
    while (j < n2)
    {
        Arr[k] = E[j];
        j++; k++;
    }  //把剩下的元素放回数组中
}

void msort(vector<int>& Arr, int begin, int end)
{
    if (begin < end)
    {
        int mid = (begin + end) / 2;
        msort(Arr, begin, mid);  //分区
        msort(Arr, mid + 1, end);  //分区
        merge(Arr, begin, mid, end);  //归并
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
    }  //将链表数据保存到数组中方便排序
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
        int pivoIndex = partition(Arr,begin,end);  //分区
        qsort(Arr, begin, pivoIndex - 1);    //递归
        qsort(Arr, pivoIndex + 1, end);  //递归
    }
}

int partition(vector<int>& Arr, int begin, int end)
{
    int pivot = Arr[end];  //设定参照数
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
    }  //把元素放到正确的位置上
    int t = Arr[end];
    Arr[end] = Arr[i+1];
    Arr[i+1] = t;  //更换参照数
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
    }  //将链表数据保存到数组中方便排序
    int count_Max, count_Min;
    count_Max = count_Min = Arr[0];
    for (int i = 1; i < _no; i++)
    {
        if (Arr[i] > count_Max) count_Max = Arr[i];
        if (Arr[i] < count_Min) count_Min = Arr[i];
    }  //寻找最大最小值
    int* count = (int*)malloc(sizeof(int) * (count_Max - count_Min+1));  
    memset(count, 0, sizeof(int)* (count_Max - count_Min+1));  //新建记数数组
    for (int i = 0; i < _no; i++)
        count[Arr[i] - count_Min]++;  //计数
    for (int i = 1; i < count_Max - count_Min+1; i++)
        count[i] = count[i] + count[i - 1];  //累积
    int* output = (int*)malloc(sizeof(int) * (_no));
    memset(output, 0, sizeof(int) * (_no));  //新建结果数组
    for (int i = 0; i < _no; i++)
    {
        output[count[Arr[i] - count_Min]-1] = Arr[i];  
        count[Arr[i] - count_Min]--;
    }  //存放结果
}

void RadixCountSort()
{
    int max_num = max_element();  //寻找最大数字
    int digits = 0;
    while (max_num != 0)
    {
        max_num = max_num / 10;
        digits++;
    }  //计算最大位数
    vector<vector<int>>buckets(10);  //新建二维数组
    vector<int>Arr(_no);
    LIST temp = (*head)->next;
    int d = 0;
    while(temp!=NULL && d < _no)
    {
        Arr[d]=temp->data;
        temp = temp->next;
        d++;
    }  //将链表数据保存到数组中方便排序
    for (int i = 1; i <= digits; i++)
    {
        buckets.clear();  
        vector<vector<int>>buckets(10);  //每次按位排序前清空并建立新的二维数组
         for(int j=0;j<_no;j++)
        {
            int digitval = get_digit(Arr[j], i);  //获取位上的数
            buckets[digitval].push_back(Arr[j]);  //将该数放到对应的组中
        }
         int j = 0;
        for (const auto&row:buckets)
        {
            for (int num : row)
            {
                Arr[j] = num; j++;
            }
        }  //一一按顺序存放数替换原始数组形成新的顺序
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
    }  //遍历链表找最大值
    return maxnum;  //返回最大值
}

int get_digit(int num, int d)
{
    for (int i = 1; i <= d; i++)
        num = num / 10;
    return num % 10;  //返回位上的数
}

void Sort()
{
    int _menu, time;
    cin >> _menu >> time;  //输入排序方式及排序次数
    switch (_menu)
    {
    case 1:for(int i=0;i<time;i++) InsertSort(); break;
    case 2:for (int i = 0; i < time; i++) MergeSort(_no); break;
    case 3:for (int i = 0; i < time; i++) QuickSort();  break;
    case 4:for (int i = 0; i < time; i++) CountSort(); break;
    case 5:for (int i = 0; i < time; i++) RadixCountSort();  break;
    case 0:break;
    default:cout << "error\n";
    }  //进行循环排序
}

void putout()
{
    std::ofstream outFile("outfile.txt");
    if (!outFile)  //打开文件失败报错
    {
        std::cerr << "fail to open the file" << std::endl;
        return;
    }
    head = new LIST();
    *head = new ListNode();
    generate();  //创建链表
    LIST it = (*head)->next;
    while(it!=NULL)
    {
        it->data = (rand()+Max) % _max;  //创造随机数
        outFile << it->data << "\n";  //将数据放到文件中
        it = it->next;
    }
    outFile.close();  //关闭文件
    DestroyList();  //销毁链表
}

void putin()
{
    std::ifstream outFile("outfile.txt");
    if (!outFile)  //打开文件失败报错
    {
        std::cerr << "fail to open the file" << std::endl;
        return;
    }
    head = new LIST();
    *head = new ListNode();
    generate();  //创建链表
    LIST it = (*head)->next;
    while (it != NULL)
    {
        outFile >> it->data;  //从文件中读取数据
        it = it->next;
    }
    outFile.close();  //关闭文件
}


