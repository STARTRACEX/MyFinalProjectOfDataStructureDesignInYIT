#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <malloc.h>
typedef struct studentStruct
{
    char name[10];

    char num[10];
    float score;
    char sex[10];
} stu;
typedef struct nodeStruct
{
    stu data;
    struct nodeStruct *next;
} node;
//建表
stu Scan();
void Add(node *head);
void AddT(node *head);
int Preinsert(node *head);
void Insert(node *head, int i, stu e);
void Print(node *p);
void List(node *head);
node *Find(node *head);
void Delete(node *head);
int Alter(node *head);
int AlterPlus(node *head);
void Help();
int Cheak(char str[]);
int Menu();
void Quit();
float Average(node *head);
int More(node *head);
int Less(node *head);
void v();
int main()
{
    node *l;
    Help();
menu:
    // /menu时重新载入
    while (1)
    {
        if (Menu() == 0)
        {
            system("cls");
            Sleep(300);
            goto menu;
        }
    }
    return 0;
}
node *Creat()
{
    // 分配空间
    node *head = (node *)malloc(sizeof(node));
    // 令头节点指向空
    head->next = NULL;
    return head;
}
// 建立新的节点并以data填充
node *Creatnode(stu data)
{
    node *new = (node *)malloc(sizeof(node));
    // 新节点的数据域赋值
    new->data = data;
    return new;
}
//对数据输入赋值,对非法输入赋值,返回节点的数据
stu Scan()
{
    stu data;
    char str[128];
    scanf("%s", str);
    if (strlen(str) >= 10)
    {
        printf("Input ID failed:Too long\n");
        strcpy(data.num, "Unknow");
    }
    else
        strcpy(data.num, str);
    scanf("%s", str);
    if (strlen(str) >= 10)
    {
        printf("Input name failed:Too long\n");
        strcpy(data.name, "Unknow");
    }
    else
        strcpy(data.name, str);
    scanf("%f", &data.score);
    if (data.score > 150 || data.score < 0)
    {
        printf("Input score failed:Impossible data\n");
        data.score = 0;
    }
    scanf("%s", str);
    if (strlen(str) >= 10)
    {
        printf("Input gender failed:Too long\n");
        strcpy(data.sex, "Unknow");
    }
    else
        strcpy(data.sex, str);
    return data;
}
// 使用头插法将data插入到链表l表头
void HeadAdd(node *head, stu data)
{
    //对new新建节点赋值
    node *new = Creatnode(data);
    new->next = head->next;
    head->next = new;
}
// 使用尾插法将data插入到链表l表尾
void TailAdd(node *head, stu data)
{
    node *p = head;
    while (p->next)
    {
        p = p->next;
    }
    //对new新建节点赋值
    node *new = Creatnode(data);
    p->next = new;
    p->next->next = NULL;
}
// 尾插法输入节点到链表尾部
void Add(node *head)
{
    printf("Input the data(ID Nmae Score and Gender):\n  ");
    while (1)
    {
        //插入一次后确认，提示是否继续
        TailAdd(head, Scan());
        fflush(stdin);
        printf("-\nConfirm your input.\t(Continue:'Enter') ");
        char c = getchar();
        if (c != '\n')
        {
            break;
        }
        else
        {
            printf(" ");
        }
    }
}
//头插法
void AddH(node *head)
{
    printf("Input the data(ID Nmae Score and Gender):\n  ");
    while (1)
    {
        //插入一次后确认，提示是否继续
        HeadAdd(head, Scan());
        fflush(stdin);
        printf("-\nConfirm your input.\t(Continue:'Enter') ");
        char c = getchar();
        if (c != '\n')
        {
            break;
        }
        else
        {
            printf(" ");
        }
    }
}
//为Insert提供数据
int Preinsert(node *head)
{
    //若表不为空
    if (head->next)
    {
        //逐个输出节点和序号
        int sn = 1;
        node *p = head->next;
        while (p != NULL)
        {
            printf("[%d]\t", sn);
            Print(p);
            p = p->next;
            sn++;
        }
        printf("\nInput the sequence number to insert:\n ");
        int i;
    retry:
        scanf("%d", &i);
        //若输入序号不存在
        if (i > sn || i < 1)
        {
            printf("\nImpossible sequence number.\n");
            goto retry;
        }
        //若输入序号存在
        else
        {
            printf("Input the data(ID Nmae Score and Gender):\n");
            //为新数据创建节点，并赋值
            node *in;
            in = Creatnode(Scan());
            //调用Insert
            Insert(head, i, in->data);
            //数据完成插入
            printf("Data:\n\t");
            Print(in);
            printf("Inserted\n");
            free(in);
        }
        return 1;
    }
    //若表为空
    else
    {
        printf("Empty.\n");
        return 0;
    }
}
//在链表中插入节点，i为插入位置，e为插入数据
void Insert(node *head, int i, stu e)
{
    //若插入位置为第一个节点
    if (i == 1)
    {
        //创建新节点
        node *new = Creatnode(e);
        //插入节点
        new->next = head->next;
        head->next = new;
    }
    else
    {
        //设置指针p指向第i-1个节点
        node *p = head->next;
        for (int j = 1; j < i - 1; j++)
        {
            p = p->next;
        }
        //创建新节点
        node *new = Creatnode(e);
        //插入节点
        new->next = p->next;
        p->next = new;
    }
}
//输出p节点信息
void Print(node *p)
{
    printf(" %s\t%s\t%.2f \t %s\n", p->data.num, p->data.name, p->data.score, p->data.sex);
}
//列出全部节点
void List(node *head)
{
    //表不为空循环
    node *p = head->next;
    if (!p)
    {
        printf("Empty.\n");
        return;
    }
    while (p)
    {
        //输出每一个节点信息
        Print(p);
        p = p->next;
    }
}
//查找表中等于data的节点并返回，找不到返回NULL
node *Find(node *head)
{
    //若表不空，正常执行
    if (head->next)
    {
        //让用户输入要查找的数据,并检查其长度
        printf("Input ID to search:\n");
        stu searchdata;
    retrynum:
        scanf("%s", searchdata.num);
        if (strlen(searchdata.num) > 10)
        {
            printf("Too long,try again.\n");
            goto retrynum;
        }
        // p从头节点开始遍历
        node *p = head->next;
        //当p不为空时循环
        while (p)
        {
            if (!strcmp(p->data.num, searchdata.num))
            {
                //找到后输出节点信息,调用Print
                printf("Found: ");
                Print(p);
                break;
            }
            p = p->next;
        }
    }
    //若空
    else
        printf("Empty.\n");
    return head->next;
}
//查找表中num等于sr的节点，将其删除
void Delete(node *head)
{
    //判断是否为空表
    if (!head->next)
    {
        printf("Empty.\n");
        return;
    }
    char sr[128];
    printf("Input ID to delete:\n");
retrydeletenum:
    scanf("%s", sr);
    //判断sr是否超过10字符
    if (strlen(sr) > 10)
    {
        printf("Too long,try again.\n");
        goto retrydeletenum;
    }
    //待删除从头节点开始遍历
    node *delet = head->next;
    node *front = head;
    //查找结点,删除节点不等于目标节点向后遍历,等于退出循环
    while (strcmp(delet->data.num, sr))
    {
        front = delet;
        delet = delet->next;
        if (delet == NULL)
        {
            printf("Not found.\n");
            return;
        }
    }
    //找到后删除
    printf("Data:\n\t");
    Print(delet);
    printf("Deleted.\n");
    front->next = delet->next;
    free(delet);
}
//查找表中num等于sr的节点，将其修改
int Alter(node *head)
{
    //判断是否为空表
    if (!head->next)
    {
        printf("Empty.\n");
        return 0;
    }
    else
    {
        char sr[128];
        printf("Input ID to modify:\n");
    retrymodifynum:
        scanf("%s", sr);
        //判断sr是否超过10字符
        if (strlen(sr) > 10)
        {
            printf("Too long,try again.\n");
            goto retrymodifynum;
        }
        // 待修改从头节点开始遍历
        node *modify = head->next;
        //查找结点,修改节点不等于目标节点向后遍历,等于退出循环
        while (strcmp(modify->data.num, sr))
        {
            //查找要修改的节点
            modify = modify->next;
            if (modify == NULL)
            {
                printf("Not found.\n");
                return 1;
            }
        }
        //找到后先输出节点信息
        Print(modify);
        //确认修改
        printf("Modify? \t\t(Continue:Enter)");
        char c;
        fflush(stdin);
        scanf("%c", &c);
        if (c != '\n')
            return 1;
        //修改节点信息
        printf("Input the data(ID Nmae Score and Gender):\n");
        modify->data = Scan();
        //提示已完成修改
        printf("Data:\n\t");
        Print(modify);
        printf("Updated.\n");
    }
    return 1;
}
//查找表中num等于sr的节点，选择一项数据将其修改
int AlterPlus(node *head)
{
    //判断是否为空表
    if (!head->next)
    {
        printf("Empty.\n");
        return 0;
    }
    else
    {
        char sr[128];
        printf("Input ID to modify:\n");
    retrynum:
        scanf("%s", sr);
        //判断sr是否超过10字符
        if (strlen(sr) > 10)
        {
            printf("Too long,try again.\n");
            goto retrynum;
        }
        // 待修改从头节点开始遍历
        node *modify = head->next;
        //查找结点,修改节点不等于目标节点向后遍历,等于退出循环
        while (strcmp(modify->data.num, sr))
        {
            //查找要修改的节点
            modify = modify->next;
            if (modify == NULL)
            {
                printf("Not found.\n");
                return 1;
            }
        }
        //找到后先输出节点信息
        printf("Items:  <1>\t<2>\t<3>\t<4>\nFound:  ");
        Print(modify);
        //选择修改项
        int choice;
        char stest[128];
    rechoice:
        printf("Select modified data item:\n");
        fflush(stdin);
        scanf("%d", &choice);
        //确认修改
        printf("Modify? \t\t(Continue:Enter)");
        char c;
        fflush(stdin);
        scanf("%c", &c);
        if (c != '\n')
            return 1;
        //修改节点信息
        //根据choice修改节点信息
        switch (choice)
        {
        case 1:
            printf("Input new ID:\n");
            scanf("%s", stest);
            if (strlen(stest) > 10)
            {
                printf("Too long,try again.\n");
                goto rechoice;
            }
            strcpy(modify->data.num, stest);
            break;
        case 2:
            printf("Input new name.\n");
            scanf("%s", stest);
            if (strlen(stest) > 10)
            {
                printf("Too long,try again.\n");
                goto rechoice;
            }
            strcpy(modify->data.name, stest);
            break;
        case 3:
            printf("Input new score:\n");
            scanf("%f", &modify->data.score);
            if (modify->data.score < 0 || modify->data.score > 150)
            {
                printf("Impossible data,try again.\n");
                goto rechoice;
            }
            break;
        case 4:
            printf("Input new sex:\n");
            scanf("%s", stest);
            if (strlen(stest) > 10)
            {
                printf("Too long,try again.\n");
                goto rechoice;
            }
            strcpy(modify->data.sex, stest);
            break;
        default:
            printf("Not found data:\n");
            goto rechoice;
        }
        //提示已完成修改
        printf("Data:\n");
        Print(modify);
        printf("Updated.\n");
    }
    return 1;
}
//求score的平均值
float Average(node *head)
{
    //判断是否为空表
    if (!head->next)
    {
        printf("Empty.\n");
        return 0;
    }
    //计算总分
    float sum = 0, count = 0;
    //遍历表
    node *p = head->next;
    while (p)
    {
        sum += p->data.score;
        count++;
        p = p->next;
    }
    printf(" Average:%.2f\n", sum / count);
    return sum / count;
}
//求score大于90的个数
int More(node *head)
{
    //判断是否为空表
    if (!head->next)
    {
        printf("Empty.\n");
        return 0;
    }
    //计数
    int count = 0;
    //遍历表
    node *p = head->next;
    while (p)
    {
        if (p->data.score > 90)
            count++;
        p = p->next;
    }
    printf(" 'Score' more than 90: %d\n", count);
    return count;
    //返回大于60的个数
}
//求scorexiao于60的个数
int Less(node *head)
{
    //判断是否为空表
    if (!head->next)
    {
        printf("Empty.\n");
        return 0;
    }
    //计数
    int count = 0;
    //遍历表
    node *p = head->next;
    while (p)
    {
        if (p->data.score < 60)
            count++;
        p = p->next;
    }
    printf(" 'Score' less than 60: %d\n", count);
    return count;
}

int Cheak(char str[])
{
    char *c;
    c = strupr(str);
    if (!strcmp(c, "/CREAT") || !strcmp(c, "/C"))
    {
        return 1;
    }
    else if (!strncmp(c, "/AD", 3) || !strcmp(c, "/A"))
    {
        return 2;
    }
    else if (!strcmp(c, "/FIND") || !strcmp(c, "/F"))
    {
        return 3;
    }
    else if (!strcmp(c, "/DELETE") || !strcmp(c, "/D"))
    {
        return 4;
    }
    else if (!strcmp(c, "/ALTER") || !strcmp(c, "/AL"))
    {
        return 5;
    }
    else if (!strcmp(c, "/LIST") || !strcmp(c, "/L"))
    {
        return 6;
    }
    else if (!strcmp(c, "/AVG"))
    {
        return 7;
    }
    else if (!strcmp(c, "/MORE"))
    {
        return 8;
    }
    else if (!strcmp(c, "/LESS"))
    {
        return 9;
    }
    else if (!strcmp(c, "/INSERT") || !strcmp(c, "/I"))
    {
        return 10;
    }
    else if (!strncmp(c, "/ALTERI", 7) || !strcmp(c, "/AI"))
    {
        return 11;
    }
    else if (!strncmp(c, "/ADDH", 7) || !strcmp(c, "/AH"))
    {
        return 12;
    }
    else if (!strcmp(c, "/MENU") || !strcmp(c, "/M"))
    {
        return 0;
    }
    else if (!strcmp(c, "/EXIT") || !strcmp(c, "/E") || !strcmp(c, "/QUIT") || !strcmp(c, "/Q"))
    {
        return -1;
    }
    else if (!strcmp(c, "/HELP") || !strcmp(c, "/H"))
    {
        return 90;
    }
    else if (!strncmp(c, "SIMS", 4))
    {
        return -2;
    }
    else
    {
        return 100;
    }
}
int Menu()
{
    char str[10];
    int c; // c判断是否经过修改，若经过修改，c=1，在case中提示可能造成修改信息错位的警示
    node *l = Creat();
    while (1)
    {
        printf("-Waiting for Command:\n");
        gets(str);
        switch (Cheak(str))
        {
        case -2:
            v();
            break;
        case 0:
            return 0;
        case 1:
        {
            l = Creat();
            printf("Create Success.\n");
            fflush(stdin);
            break;
        }
        case 2:
        {
            Add(l);
            fflush(stdin);
            break;
        }
        case 3:
        {
            Find(l);
            fflush(stdin);
            break;
        }
        case 4:
        {
            Delete(l);
            fflush(stdin);
            break;
        }
        case 5:
            Alter(l);
            fflush(stdin);
            break;
        case 6:
            List(l);
            fflush(stdin);
            break;
        case 7:
            Average(l);
            fflush(stdin);
            break;
        case 8:
            More(l);
            fflush(stdin);
            break;
        case 9:
            Less(l);
            fflush(stdin);
            break;
        case 10:
            c = Preinsert(l);
            fflush(stdin);
            break;
        case 11:
            AlterPlus(l);
            fflush(stdin);
            break;
        case 12:
            //经过了修改，c=1
            if (c == 1)
            {
                printf("ATTENTION: May cause data serial number dislocation\t(Continue:'Enter')");
                //输入回车继续
                char c = getchar();
                if (c == '\n')
                    AddH(l);
            }
            //未经修改，直接进行插入
            else
            {
                AddH(l);
            }
            fflush(stdin);
            break;
        case 90:
            Help();
            fflush(stdin);
            break;
        case -1:
            Quit();
        default:
            printf("\nUnknow Command.'/help' to view help.\n\n");
            break;
        }
    }
}
void Help()
{
    system("cls");
    printf("-How to use?");
    printf("\nView help         '/Help'   '/H'");
    printf("\nReload Menu       '/Menu'   '/M'");
    printf("\nCreat new         '/Creat'  '/C'");
    printf("\nFind the data     '/Add'    '/A'");
    printf("\nDelete the data   '/Insert' '/I'");
    printf("\nFind the data     '/Find'   '/F'");
    printf("\nAlter the data    '/Alter'  '/Al'");
    printf("\nAlter a data item '/AlterI' '/Ai'");
    printf("\nDelete the data   '/Delete' '/D'");
    printf("\nList the dat      '/List'   '/L'");
    printf("\nExit Program      '/Exit'   '/E'");
    printf("\nCalculation:'/Avg''/More''/Less'");
    printf("\n");
}
void Quit()
{
    system("cls");
    printf("\nBye.\n");
    Sleep(600);
    exit(0);
}
void v()
{
    system("cls");
    printf("\tVersion:1.1_Beta_20210210020_WangShichao_YIT\n\tData location:in your ram\n\n");
}