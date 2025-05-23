#include <iostream>
using namespace std;

#define MAXSIZE 100
#define OK 1
#define ERROR 0
typedef int Status;
typedef int ElemType;

// 定义顺序表结构体
typedef struct SqList {
    ElemType *elem; // 动态分配的数组，用于存储元素
    int length;     // 顺序表的当前长度
}SqList;

// 初始化顺序表
Status InitList (SqList &L) {
    L.elem = new ElemType[MAXSIZE]; // 分配最大容量的数组
    if (!L.elem) return ERROR;      // 分配失败返回错误
    L.length = 0;                   // 初始化长度为0
    return OK;                      // 返回成功状态
}

// 获取顺序表中第i个元素
Status GetElem(SqList L, int i, ElemType &e) {
    if (i < 1 || i > L.length ) return ERROR; // 检查索引是否合法
    e = L.elem[i-1];                          // 获取元素值
    return OK;                                // 返回成功状态
}

// 查找元素在顺序表中的位置
int LocateElem(SqList L, ElemType e){
    for (int i = 0; i < L.length; i++){       // 遍历顺序表
        if (L.elem[i] == e) return i+1;       // 找到元素返回其位置
    }
    return ERROR;                             // 未找到返回错误
}

// 在顺序表的第i个位置插入元素
Status ListInsert(SqList &L, int i, ElemType e){
    if (i < 1 || i > L.length) return ERROR;  // 检查插入位置是否合法
    if (L.length == MAXSIZE) return ERROR;    // 检查顺序表是否已满
    for (int j = L.length - 1; j >= i - 1; j--){ // 从后向前移动元素
        L.elem[j + 1] = L.elem[j];
    }
    L.elem[i-1] = e;                          // 插入新元素
    L.length++;                               // 更新顺序表长度
    return OK;                                // 返回成功状态
}

// 删除顺序表中第i个位置的元素
Status ListDelete(SqList &L, int i){
    if (i < 1 || i > L.length) return ERROR;  // 检查删除位置是否合法
    for (int j = i; j <= L.length - 1; j++){  // 从前向后移动元素
        L.elem[j-1] = L.elem[j];
    }
    L.length--;                               // 更新顺序表长度
    return OK;                                // 返回成功状态
}

// 打印顺序表中的所有元素
void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        cout << L.elem[i] << " ";
    }
    cout << endl;
}

// 销毁顺序表
Status DestroyList(SqList &L) {
    if (L.elem) {
        delete[] L.elem;  // 释放动态分配的内存
        L.elem = NULL; // 将指针置为空
        L.length = 0;     // 重置长度
        return OK;
    }
    return ERROR;
}

// 测试数据结构 
int main(){
    SqList L;
    InitList(L);
    cout << "请输入10个数：";
    for (int i = 0; i < 10; i++){
        cin >> L.elem[i];
        L.length++;
    }
    cout << "顺序表当前长度为：" << L.length << endl;
    PrintList(L); // 打印顺序表

    cout << "请输入元素位置：";
    int pos;
    cin >> pos;
    int e;
    GetElem(L, pos, e);
    cout << "该元素为：" << e << endl;

    cout << "请输入元素：";
    cin >> e;
    pos = LocateElem(L, e);
    cout << "元素位置为：" << pos << endl;

    cout << "请输入插入位置及元素：";
    cin >> pos >> e;
    ListInsert(L, pos, e);
    cout << "顺序表当前长度为：" << L.length << endl;
    PrintList(L); // 打印顺序表

    cout << "请输入删除位置：";
    cin >> pos;
    ListDelete(L, pos);
    cout << "顺序表当前长度为：" << L.length << endl;
    PrintList(L); // 打印顺序表

    DestroyList(L); // 销毁顺序表
    return 0;   
}