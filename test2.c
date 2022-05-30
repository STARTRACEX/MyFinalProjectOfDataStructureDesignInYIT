#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <malloc.h>
#define Ture 1  //成功标识
#define False 0 //失败标识
typedef struct InfoStructure
{
    char num[10], name[10], sex[10];
    float score;
} DataType;
typedef struct node
{
    DataType data;     //结点值,数据域
    struct node *next; //下一个结点的地址,指针域
} ListNode, *LinkList;

//初始化链表
LinkList InitList()
{
    LinkList head = (LinkList)malloc(sizeof(ListNode)); // head指针指向头节点空间

    if (head == NULL)
    {
        return False;
    }
    head->next = NULL;
    return head;
}

//在单链表的尾部添加元素
int Add(LinkList L)
{
    DataType x;
    LinkList r = L; //设r为尾结点

    while (r->next) //若不为空,即r不是尾结点
    {
        r = r->next;
    }
    //申请新结点空间失败返回False
    LinkList s = (LinkList)malloc(sizeof(ListNode));
    if (s == NULL)
        return False;
    printf("Enter element(ID,name,score and gender(1 for male,0 for female)). Exit: Not alphanumeric ID\n");
    while (1)
    {
        scanf("%s", x.num);
        if (!isalnum(x.num[0]))
        {
            break;
            scanf("%s %f %s", x.name, &x.score, x.sex);
            s->data = x;    
            s->next = NULL; //尾结点s指向为空
            r->next = s;    //链接前驱节点
            r = s;          //令r为尾结点
        }
        return Ture;
    }
}

//输出一次
void Print(LinkList L)
{
    printf("%s\t%s\t%f\t", L->data.num, L->data.name, L->data.score);
    //如果sex是1则输出男,否则输出女
    if (!strcmp(L->data.sex, "1"))
        printf("Male\n");
    else
        printf("Female\n");
}
//输出全部
int List(LinkList L)
{
    LinkList p = L->next; //定义p指针指向头部元素后的元素即为第一个元素
    printf("ID\tName\ttScore\tGender\n");
    while (p->next)
    {
        Print(L);
        p = p->next; // p指针后移
    }
    return Ture;
}

//查找L中值为e的元素(学号)并返回,若找不到则返回NULL
LinkList Locate(LinkList L, char e[])
{
    LinkList p = L->next;
    // p不为空时
    while (p->next)
    {
        if (!strcmp(p->data.num, e))
            return p; //若相同返回p，再调用输出函数输出
        p = p->next;  // p向后遍历
    }
    //找不到返回空
    return NULL;
}

//查找
LinkList Find(LinkList L)
{
    //输入学号
    char e[10];
    printf("Enter student ID you want to find:");
    scanf("%s", e);
    LinkList p = Locate(L, e);
    //若p存在，输出
    if (p)
    {
        Print(L);
        //返回p用于修改或删除
        return p;
    }
    else
        //找不到元素
        printf("Not found.\n");
        return NULL;
}
//搜索元素并修改，失败返回False
int Alter(LinkList L)
{
    LinkList p= Find(L);
    //若p存在则修改
    if (p)
    {
        Print(L);
        //输入修改后的信息
        printf("Enter new information:");
        scanf("%s %s %f %s", p->data.num, p->data.name, &p->data.score, p->data.sex);
        return Ture;
    }
    else
        return False;
}
//在L中删除第i个元素,失败返回False
int Delete(LinkList L, int i)
{
    //先查找元素
    LinkList p = L, s = Find(L);
    if(s)
    {
        while (p->next != s)
        {
            p = p->next;
        }
        s = p->next;       // p指向s,将被删除
        p->next = s->next; // s指向下一项被p替换
        return Ture;
    }
    else
        return False;
}

//求score的平均值返回
float Average(LinkList L)
{
    LinkList p = L->next;
    float sum = 0, i = 0;
    while (p->next)
    {
        sum += p->data.score;
        p = p->next;
        i++;
    }
    return sum / i;
}
//返回score小于某个值的个数
int Less(LinkList L, float x)
{
    LinkList p = L->next;
    int i = 0;
    while (p->next)
    {
        if (p->data.score < x)
            i++;
        p = p->next;
    }
    return i;
}
//返回score大于某个值的个数
int More(LinkList L, float x)
{
    LinkList p = L->next;
    int i = 0;
    while (p->next)
    {
        if (p->data.score > x)
            i++;
        p = p->next;
    }
    return i;
}
int main()
{
    LinkList L;
    Add(L);
    Print(L);
    system("pause");
    return 0;
}
