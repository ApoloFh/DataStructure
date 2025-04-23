#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
typedef int Status;
typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

// 初始化链表
Status InitList(LinkList &L) {
    L = new LNode;       // 创建头结点
    L->next = NULL;      // 初始化为空链表
    return OK;
}

// 获取链表中第i个元素
Status GetElem(LinkList L, int i, ElemType &e) {
    LNode *p = L->next;  // 指向第一个节点
    int j = 1;           // 计数器
    while (p && j < i) { // 遍历链表直到第i个节点
        p = p->next;
        j++;
    }
    if (!p || j > i) return ERROR; // 如果节点不存在，返回错误
    e = p->data;                   // 获取节点数据
    return OK;
}

// 查找元素在链表中的位置
int LocateElem(LinkList L, ElemType e) {
    LNode *p = L->next;  // 指向第一个节点
    int j = 1;           // 计数器
    while (p && p->data != e) { // 遍历链表直到找到元素
        p = p->next;
        j++;
    }
    return j;            // 返回元素位置
}

// 在链表的第i个位置插入元素
Status ListInsert(LinkList &L, int i, ElemType e) {
    LNode *p = L;        // 指向头结点
    int j = 0;           // 计数器
    while (p && j < i - 1) { // 遍历链表直到第i-1个节点
        p = p->next;
        j++;
    }
    if (!p || j > i - 1) return ERROR; // 如果节点不存在，返回错误
    LNode *s = new LNode; // 创建新节点
    s->data = e;          // 设置新节点数据
    s->next = p->next;    // 插入新节点
    p->next = s;
    return OK;
}

// 删除链表中第i个位置的元素
Status ListDelete(LinkList &L, int i) {
    LNode *p = L;        // 指向头结点
    int j = 0;           // 计数器
    while (p->next && j < i - 1) { // 遍历链表直到第i-1个节点
        p = p->next;
        j++;
    }
    if (!p->next || j > i - 1) return ERROR; // 如果节点不存在，返回错误
    LNode *q = p->next; // 指向待删除节点
    p->next = q->next;  // 删除节点
    delete q;           // 释放内存
    return OK;
}

// 头插法创建链表
void CreateList_H(LinkList &L, int n) {
    L = new LNode;       // 创建头结点
    L->next = NULL;      // 初始化为空链表
    for (int i = 0; i < n; i++) { // 循环插入n个元素
        LNode *p = new LNode; // 创建新节点
        cin >> p->data;       // 输入节点数据
        p->next = L->next;    // 插入到链表头部
        L->next = p;
    }
}

// 尾插法创建链表
void CreateList_R(LinkList &L, int n) {
    L = new LNode;       // 创建头结点
    L->next = NULL;      // 初始化为空链表
    LNode *r = L;        // 尾指针
    for (int i = 0; i < n; i++) { // 循环插入n个元素
        LNode *p = new LNode; // 创建新节点
        cin >> p->data;       // 输入节点数据
        r->next = p;          // 插入到链表尾部
        r = p;                // 更新尾指针
    }
    r->next = NULL;      // 设置尾节点的next为NULL
}

// 打印链表
void PrintList(LinkList L) {
    LNode *p = L->next;  // 指向第一个节点
    while (p) {          // 遍历链表
        cout << p->data << " "; // 输出节点数据
        p = p->next;
    }
    cout << endl;
}

// 销毁链表，释放内存
void DestroyList(LinkList &L) {
    LNode *p = L;        // 指向头结点
    while (p) {          // 遍历链表
        LNode *q = p;    // 暂存当前节点
        p = p->next;     // 移动到下一个节点
        delete q;        // 释放当前节点
    }
    L = NULL;            // 将链表置为空
}

// 测试数据结构
int main() {
    LinkList L;
    InitList(L);
    cout << "请输入10个数：";
    CreateList_R(L, 10);
    PrintList(L);
    cout << "请输入插入位置和元素：";
    int i, e;
    cin >> i >> e;
    ListInsert(L, i, e);
    PrintList(L);
    cout << "请输入查找元素：";
    cin >> e;
    int pos = LocateElem(L, e);
    cout << "元素位置为：" << pos << endl;
    cout << "请输入删除位置：";
    cin >> i;
    ListDelete(L, i);
    PrintList(L);
    DestroyList(L);
    return 0;
}