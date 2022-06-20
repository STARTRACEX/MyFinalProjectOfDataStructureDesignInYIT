#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
int lang = 936;
char subj[100] = "DM", subj2[100] = "M";
typedef struct studentStruct
{
    char name[10], num[10];
    float score, score2;
} stu;
typedef struct nodeStruct
{
    stu data;
    struct nodeStruct *next;
} node;
stu Scan();
node *Creat();
void HeadAdd(node *head, stu data);
void TailAdd(node *head, stu data);
void Add(node *head);
void AddH(node *head);
int Preinsert(node *head);
void Insert(node *head, int i, stu e);
void Print(node *p);
void List(node *head);
node *Find(node *head);
node *FindPlus(node *head);
void BETA();
int DelPro(node *head);
void Delete(node *head);
int Alter(node *head);
int AlterPlus(node *head);
void Help();
void HelpCN();
int Cheak(char str[]);
int Menu();
void Quit();
int SortCHECK(node *head);
int SortAdaption(node *head, int subj);
float Average(node *head);
int More(node *head);
int Less(node *head);
void v();
int main()
{
    system("title SIMS  1.5_Beta ");
    system("chcp 936");
    system("cls");
    node *l;
    if (lang == 936)
        HelpCN();
    else
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
//创建一个空链表，返回链表头指针
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
    int f = 1;
    stu data;
    char str[128];
    scanf("%s", str);
    if (strlen(str) >= 10)
    {
        if (lang == 936)
            printf("您输入的太长了，将储存为Unknow\n");
        else
            printf("Input ID failed:Too long\n");
        strcpy(data.num, "Unknow");
    }
    else
        strcpy(data.num, str);
    scanf("%s", str);
    if (strlen(str) >= 10)
    {
        if (lang == 936)
            printf("您输入的太长了，将储存为Unknow\n");
        else
            printf("Input name failed:Too long\n");
        strcpy(data.name, "Unknow");
    }
    else
        strcpy(data.name, str);
    // score1
    scanf("%s", str);
    //验证非法字符
    for (int i = 0; i < strlen(str); i++)
    {
        if (isdigit(str[i]) == 0 && str[i] != '.')
        {
            if (lang == 936)
                printf("不可能的数据，将储存为0\n");
            else
                printf("Input score failed:Impossible data\n");
            data.score = 0;
            f = 0; //作为已经对score赋值的标致，使之后的判定略过
            break;
        }
    }
    //验证合法字符“.”数
    if (f)
        for (int i = 0, j = 0; i < strlen(str); i++)
        {
            if (str[i] == '.')
                j++;
            if (j > 1)
            {
                if (lang == 936)
                    printf("不可能的数据，将储存为0\n");
                else
                    printf("Input score failed:Impossible data\n");
                f = 0;
                data.score = 0;
                break;
            }
        }
    //验证合法数字取值范围
    if (f)
        if (atof(str) > 150 || atof(str) < 0)
        {
            if (lang == 936)
                printf("不可能的数据，将储存为 0\n");
            else
                printf("Input score failed:Impossible data\n");
            data.score = 0;
        }
    data.score = (float)atof(str);
    // score2
    scanf("%s", str);
    //验证非法字符
    for (int i = 0; i < strlen(str); i++)
    {
        if (isdigit(str[i]) == 0 && str[i] != '.')
        {
            if (lang == 936)
                printf("不可能的数据，将储存为0\n");
            else
                printf("Input score failed:Impossible data\n");
            data.score2 = 0;
            f = 0; //作为已经对score赋值的标致，使之后的判定略过
            break;
        }
    }
    //验证合法字符“.”数
    if (f)
        for (int i = 0, j = 0; i < strlen(str); i++)
        {
            if (str[i] == '.')
                j++;
            if (j > 1)
            {
                if (lang == 936)
                    printf("不可能的数据，将储存为0\n");
                else
                    printf("Input score failed:Impossible data\n");
                f = 0;
                data.score2 = 0;
                break;
            }
        }
    //验证合法数字取值范围
    if (f)
        if (atof(str) > 150 || atof(str) < 0)
        {
            if (lang == 936)
                printf("不可能的数据，将储存为 0\n");
            else
                printf("Input score failed:Impossible data\n");
            data.score2 = 0;
        }
    data.score2 = (float)atof(str);
    return data;
}
// 使用头插法将data插入到链表l表头
void HeadAdd(node *head, stu data)
{
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
    if (lang == 936)
        printf("输入信息（ID 姓名和分数）：\n ");
    else
        printf("Input the data(ID Nmae Score):\n ");
    while (1)
    {
        TailAdd(head, Scan());
        fflush(stdin);
        if (lang == 936)
            printf("输入已储存\t 按下'Enter'确认");
        else
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
    if (lang == 936)
        printf("输入信息（ID 姓名和分数）：\n ");
    else
        printf("Input the data(ID Nmae Score):\n  ");
    while (1)
    {
        //插入一次后确认，提示是否继续
        HeadAdd(head, Scan());
        fflush(stdin);
        if (lang == 936)
            printf("输入已储存\t 按下'Enter'继续");
        else
            printf("-\nConfirm your input.\t(Continue:'Enter') ");
        char c = getchar();
        if (c != '\n')
            break;
        else
            printf(" ");
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
        if (lang == 936)
            printf("输入序列号以插入到：\n ");
        else
            printf("\nInput the sequence number to insert:\n ");
        int i;
    retry:
        scanf("%d", &i);
        //若输入序号不存在
        if (i > sn || i < 1)
        {
            if (lang == 936)
                printf("不可能的序号，再试一次\n ");
            else
                printf("\nImpossible sequence number.\n");
            goto retry;
        }
        //若输入序号存在
        else
        {
            if (lang == 936)
                printf("输入信息（ID 姓名，和分数）：\n ");
            else
                printf("Input the data(ID Nmae Score):\n");
            //为新数据创建节点，并赋值
            node *in;
            in = Creatnode(Scan());
            //调用Insert
            Insert(head, i, in->data);
            //数据完成插入
            if (lang == 936)
                printf("数据：\n");
            else
                printf("Data:\n\t");
            Print(in);
            if (lang == 936)
                printf("已插入\n");
            else
                printf("Inserted\n");
            free(in);
        }
        return 1;
    }
    //若表为空
    else
    {
        if (lang == 936)
            printf("空数据\n");
        else
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
    printf(" %s\t%s\t%.2f\t%.2f\n", p->data.num, p->data.name, p->data.score, p->data.score2);
}
//列出全部节点
void List(node *head)
{
    //表不为空循环
    node *p = head->next;
    if (!p)
    {
        if (lang == 936)
            printf("空数据\n");
        else
            printf("Empty.\n");
        return;
    }
    printf(" ID\t姓名\t%s\t%s\n", subj, subj2);
    while (p != NULL)
    {
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
        if (lang == 936)
            printf("输入学号以搜索：\n");
        else
            printf("Input ID to search:\n");
        stu searchdata;
    retrynum:
        scanf("%s", searchdata.num);
        if (strlen(searchdata.num) > 10)
        {
            if (lang == 936)
                printf("您输入的太长了！再试一次\n");
            else
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
                if (lang == 936)
                    printf("找到内容：\n");
                else
                    printf("Found: ");
                Print(p);
                break;
            }
            p = p->next;
        }
    }
    else
    {
        if (lang == 936)
            printf("空数据\n");
        else
            printf("Empty.\n");
    }
    return head->next;
}
node *FindPlus(node *head)
{
    // 由用户输入要查找的项目
    if (head->next)
    {
        if (lang == 936)
        {
            printf(" 通过项目查找：\n\n");
            printf(" <1>\t<2>\t<3>\n");
            printf(" 姓名\t%s\t%s", subj, subj2);
            printf("\n请输入序号：\n");
        }
        else
        {
            printf(" Set search by:\n\n");
            printf(" <1>\t<2>\t<3>\n");
            printf(" Name\t%s\t%s", subj, subj2);
            printf("\nInput serial number:\n");
        }
        int i, f = 0;
        node *p = head->next;
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            //输入姓名
            if (lang == 936)
                printf("输入姓名：\n");
            else
                printf("Input name:\n");
            char name[10];
            scanf("%s", name);
            // p从头节点开始遍历
            //当p不为空时循环
            while (p)
            {
                if (!strcmp(p->data.name, name))
                {
                    //找到后输出节点信息,调用Print
                    if (f == 0)
                    {
                        if (lang == 936)
                            printf("找到内容：\n");
                        else
                            printf("Found: ");
                        f = 1;
                    }
                    Print(p);
                }
                p = p->next;
            }
            break;
        case 2:
            //输入得分
            if (lang == 936)
                printf("输入得分：\n");
            else
                printf("Input score:\n");
            float score;
            scanf("%f", &score);
            while (p)
            {
                if (p->data.score == score)
                {
                    //找到后输出节点信息,调用Print
                    if (f == 0)
                    {
                        if (lang == 936)
                            printf("找到内容：\n");
                        else
                            printf("Found: ");
                        f = 1;
                    }
                    Print(p);
                }
                p = p->next;
            }
            break;
        case 3:
            //输入得分
            if (lang == 936)
                printf("输入得分：\n");
            else
                printf("Input score:\n");
            scanf("%f", &score);
            while (p)
            {
                if (p->data.score == score)
                {
                    //找到后输出节点信息,调用Print
                    if (f == 0)
                    {
                        if (lang == 936)
                            printf("找到内容：\n");
                        else
                            printf("Found: ");
                        f = 1;
                    }
                    Print(p);
                }
                p = p->next;
            }
            break;
        default:
            if (lang == 936)
                printf("输入错误！\n");
            else
                printf("Input error!\n");
            break;
        }
    }
    else
    {
        if (lang == 936)
            printf("空数据\n");
        else
            printf("Empty.\n");
    }
    return head->next;
}
//查找表中num等于sr的节点，将其删除
void Delete(node *head)
{
    //判断是否为空表
    if (!head->next)
    {
        if (lang == 936)
            printf("空数据\n");
        else
            printf("Empty.\n");
        return;
    }
    char sr[128];
    if (lang == 936)
        printf("输入ID以删除：\n");
    else
        printf("Input ID to delete:\n");
retrydeletenum:
    scanf("%s", sr);
    //判断sr是否超过10字符
    if (strlen(sr) > 10)
    {
        if (lang == 936)
            printf("您输入的太长了！再试一次\n");
        else
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
            if (lang == 936)
                printf("未找到内容\n");
            else
                printf("Not found.\n");
            return;
        }
    }
    //找到后删除
    if (lang == 936)
        printf("数据：\n");
    else
        printf("Data:\n\t");
    Print(delet);
    if (lang == 936)
        printf("将被删除，按下'Enter'删除");
    else
        printf("Will be deleted. (Confirm:'Enter')");
    //按下enter键不再删除
    char c;
    fflush(stdin);
    scanf("%c", &c);
    if (c == '\n')
    {
        front->next = delet->next;
        free(delet);
    }
    return;
}
int DelPro(node *head)
{
    //若表不为空
    if (head->next)
    {
        if (lang == 936)
        {
            printf("通过项目删除：\n\n");
            printf("\t<1>\t<2>\t<3>\n");
            printf("\t姓名\t%s\t%s", subj, subj2);
            printf("\n请输入序号：\n");
        }
        else
        {
            printf(" Set search by:\n\n");
            printf(" \t<1>\t<2>\t<3>\n");
            printf(" \tNane\t%s\t%s", subj, subj2);
            printf("\nInput serial number:\n");
        }
        int sn = 0;
        int se = 0;
        node *p = head->next;
        char ch[10];
    dp:
        // se作为选择
        scanf("%d", &se);
        sn = 0;
        switch (se)
        {
            //输入姓名或得分
        case 1:
            printf("输入姓名：\n");
            scanf("%s", ch);
            //逐个输出节点和序号
            while (p != NULL)
            {
                if (strcmp(p->data.name, ch) == 0)
                {
                    sn++;
                    printf("<>>%d个>：%s\t%f\t%f\n", sn, p->data.name, p->data.score, p->data.score2);
                }
                p = p->next;
                // p最后时退出
                if (p == NULL)
                    break;
            }
            break;
        case 2:
            printf("输入%s：\n", subj);
            scanf("%s", ch);
            while (p != NULL)
            {
                if (p->data.score == atof(ch))
                {
                    sn++;
                    printf("<%d>：%s\t%f\t%f\n", sn, p->data.name, p->data.score, p->data.score2);
                }
                p = p->next;
                // p最后时退出
                if (p == NULL)
                    break;
            }
            break;
        case 3: //同上
            printf("输入%s：\n", subj2);
            scanf("%s", ch);
            while (p != NULL)
            {
                if (p->data.score2 == atof(ch))
                {
                    sn++;
                    printf("<%d>：%s\t%f\t%f\n", sn, p->data.name, p->data.score2);
                }
                p = p->next;
                // p最后时退出
                if (p == NULL)
                    break;
            }
            break;
        default:
            //再试一次
            if (lang == 936)
                printf("不存在的项目，再试一次：\n");
            else
                printf("Input error,try items again:\n");
            goto dp;
            break;
        }

        //如果没有相同项，返回
        if (sn == 0)
        {
            if (lang == 936)
                printf("未找到相同项\n");
            else
                printf("Not found same item.\n");
            return 0;
        }
        int num = 0, q = 1;

    tr:
        //输入序号删除
        if (lang == 936)
            printf("请输入序号：\n");
        else
            printf("Input serial number\n");

        num = 0, q = 1;
        q = scanf("%d", &num);
        //若输入错误

        if (q != 1 || num < 1 || num > sn)
        {
            if (lang == 936)
                printf("输入错误，再试一次：\n");
            else
                printf("Input error,try again:\n");
            goto tr;
        }
        else
        {
            //输出提示
            if (lang == 936)
                printf("数据：\n");
            else
                printf("Data:\n");
            //输出被删除节点
            int i = 1;
            p = head->next;
            while (p != NULL)
            {
                if (i == num)
                {
                    printf("<%d>：%s\t%f\t%f\n", i, p->data.name, p->data.score, p->data.score2);
                    break;
                }
                p = p->next;
                i++;
            }
            if (lang == 936)
                printf("将被删除，按下'Enter'确认\n");
            else
                printf("Will be delete.Confirm 'Enter'\n");
            //按下enter键不再删除
            char c;
            fflush(stdin);
            scanf("%c", &c);
            if (c != '\n')
            {
                return 0;
            }
            //若输入1则删除头节点
            if (num == 1)
            {
                node *delet = head->next;
                head->next = delet->next;
                free(delet);
            }
            else
            {
                //若输入最后一个节点
                if (num == sn)
                {
                    node *delet = head->next;
                    while (delet->next != NULL)
                        delet = delet->next;
                    delet->next = NULL;
                    free(delet);
                }
                else
                {
                    //若输入中间节点
                    node *delet = head->next;
                    int i = 1;
                    while (i < num - 1)
                    {
                        delet = delet->next;
                        i++;
                    }
                    delet->next = delet->next->next;
                    free(delet->next);
                }
            }
            if (lang == 936)
                printf("删除已完成\n");
            else
                printf("Delete completed.\n");
        }
    }
    //若表为空
    else
    {
        if (lang == 936)
            printf("空数据\n");
        else
            printf("Empty.\n");
        return 0;
    }
}

//查找表中num等于sr的节点，将其修改
int Alter(node *head)
{
    //判断是否为空表
    if (!head->next)
    {
        if (lang == 936)
            printf("空数据\n");
        else
            printf("Empty.\n");
        return 0;
    }
    else
    {
        char sr[128];
        if (lang == 936)
            printf("输入ID以修改\n");
        else
            printf("Input ID to modify:\n");
    retrymodifynum:
        scanf("%s", sr);
        //判断sr是否超过10字符
        if (strlen(sr) > 10)
        {
            if (lang == 936)
                printf("您输入的太长了！再试一次\n");
            else
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
                if (lang == 936)
                    printf("未找到内容\n");
                else
                    printf("Not found.\n");
                return 1;
            }
        }
        //找到后先输出节点信息
        Print(modify);
        if (lang == 936)
            printf("确认修改？\t按下'Enter'继续");
        else
            printf("Modify? \t\t(Continue:'Enter')");
        char c;
        fflush(stdin);
        scanf("%c", &c);
        if (c != '\n')
            return 1;
        //修改节点信息
        if (lang == 936)
            printf("输入信息（ID,姓名和分数）：\n");
        else
            printf("Input the data(ID Nmae Score):\n");
        modify->data = Scan();
        //提示已完成修改
        if (lang == 936)
            printf("数据：\n");
        else
            printf("Data:\n\t");
        Print(modify);
        if (lang == 936)
            printf("已更新\n");
        else
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
        if (lang == 936)
            printf("空数据\n");
        else
            printf("Empty.\n");
        return 0;
    }
    else
    {
        char sr[128];
        if (lang == 936)
            printf("输入ID以修改\n");
        else
            printf("Input ID to modify:\n");
    retrynum:
        scanf("%s", sr);
        //判断sr是否超过10字符
        if (strlen(sr) > 10)
        {
            if (lang == 936)
                printf("您输入的太长了！再试一次n");
            else
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
                if (lang == 936)
                    printf("未找到内容\n");
                else
                    printf("Not found.\n");
                return 1;
            }
        }
        //找到后先输出节点信息
        if (lang == 936)
        {
            printf("\tID\t姓名\t%s\t%s\n", subj, subj2);
            printf("项目： <1>\t<2>\t<3>\t<4>\n内容： ");
        }
        else
        {
            printf("\tID\tName\t%s\t%s\n", subj, subj2);
            printf("Items:  <1>\t<2>\t<3>\t<4>\nFound:  ");
        }
        Print(modify);
        //选择修改项
        int choice;
        char stest[128];
    rechoice:
        if (lang == 936)
            printf("选择项目以修改\n");
        else
            printf("Select modified data item:\n");
        fflush(stdin);
        scanf("%d", &choice);
        //确认修改
        if (lang == 936)
            printf("确认修改？\t\t按下'Enter'继续");
        else
            printf("Modify? \t\t(Continue:'Enter')");
        char c;
        fflush(stdin);
        scanf("%c", &c);
        if (c != '\n')
            return 1;
        //修改节点信息/根据choice修改节点信息
        switch (choice)
        {
        case 1:
            if (lang == 936)
                printf("新的ID：\n");
            else
                printf("Input new ID:\n");
            scanf("%s", stest);
            if (strlen(stest) > 10)
            {
                if (lang == 936)
                    printf("您输入的太长了！再试一次n");
                else
                    printf("Too long,try again.\n");
                goto rechoice;
            }
            strcpy(modify->data.num, stest);
            break;
        case 2:
            if (lang == 936)
                printf("输入新的姓名\n");
            else
                printf("Input new name.\n");
            scanf("%s", stest);
            if (strlen(stest) > 10)
            {
                if (lang == 936)
                    printf("您输入的太长了！再试一次\n");
                else
                    printf("Too long,try again.\n");
                goto rechoice;
            }
            strcpy(modify->data.name, stest);
            break;
        case 3:
            if (lang == 936)
                printf("输入新的分数\n");
            else
                printf("Input new score.\n");
            scanf("%s", stest);
            //判断输入是否为数字和小数点
            for (int i = 0; i < strlen(stest); i++)
            {
                if ((isdigit(stest[i]) == 0) && stest[i] != '.')
                {
                    if (lang == 936)
                        printf("不可能的数据，再试一次\n");
                    else
                        printf("Impossible data,try again.\n");
                    goto rechoice;
                }
            }
            for (int i = 0, j = 0; i < strlen(stest); i++)
            {

                if (stest[i] == '.')
                {
                    j++;
                    if (j > 1)
                    {
                        if (lang == 936)
                            printf("不可能的数据，再试一次\n");
                        else
                            printf("Input score failed:Impossible data\n");
                        goto rechoice;
                    }
                }
            }
            if (atof(stest) < 0 || atof(stest) > 150)
            {
                if (lang == 936)
                    printf("不可能的数据，再试一次\n");
                else
                    printf("Impossible data,try again.\n");
                goto rechoice;
            }
            modify->data.score = (float)atof(stest);
            break;
        case 4:
            if (lang == 936)
                printf("输入新的分数\n");
            else
                printf("Input new score.\n");
            scanf("%s", stest);
            //判断输入是否为数字和小数点
            for (int i = 0; i < strlen(stest); i++)
            {
                if ((isdigit(stest[i]) == 0) && stest[i] != '.')
                {
                    if (lang == 936)
                        printf("不可能的数据，再试一次\n");
                    else
                        printf("Impossible data,try again.\n");
                    goto rechoice;
                }
            }
            for (int i = 0, j = 0; i < strlen(stest); i++)
            {
                if (stest[i] == '.')
                {
                    j++;
                    if (j > 1)
                    {
                        if (lang == 936)
                            printf("不可能的数据，再试一次\n");
                        else
                            printf("Input score failed:Impossible data\n");
                        goto rechoice;
                    }
                }
            }
            if (atof(stest) < 0 || atof(stest) > 150)
            {
                if (lang == 936)
                    printf("不可能的数据，再试一次\n");
                else
                    printf("Impossible data,try again.\n");
                goto rechoice;
            }
            modify->data.score2 = (float)atof(stest);
            break;
        default:
            if (lang == 936)
                printf("找不到内容\n");
            else
                printf("Not found data:\n");
            goto rechoice;
        }
        //修改成功
        if (lang == 936)
            printf("数据\n");
        else
            printf("Data:\n");
        Print(modify);
        if (lang == 936)
            printf("已更新\n");
        else
            printf("Updated.\n");
    }
    return 1;
}
//求平均分
float Average(node *head)
{
    if (!head->next)
    {
        if (lang == 936)
            printf("空数据\n");
        else
            printf("Empty.\n");
        return 0;
    }
    //计算
    float sum = 0, sum2 = 0, count = 0;
    //遍历相加
    node *p = head->next;
    while (p)
    {
        sum += p->data.score;
        sum2 += p->data.score2;
        count++;
        p = p->next;
    }
    if (lang == 936)
        printf("平均值：%s %.2f\t%s %.2f\n", subj, sum / count, subj2, sum2 / count);
    else
        printf(" Average:%.2f\t%.2f\n", subj, sum / count, subj2, sum2 / count);
    return 1;
}
//求高于90的人数
int More(node *head)
{
    if (!head->next)
    {
        if (lang == 936)
            printf("空数据\n");
        else
            printf("Empty.\n");
        return 0;
    }
    int count = 0, count2 = 0;
    node *p = head->next;
    while (p)
    {
        if (p->data.score > 90)
            count++;
        if (p->data.score2 > 90)
            count2++;
        p = p->next;
    }

    if (lang == 936)
        printf("超过90分的人数：%s %d\t%s %d\n", subj, count, subj2, count2);
    else
        printf(" 'Score' more than 90: %s %d\t%s %d\n", subj, count, subj2, count2);
    return 1;
}
int SortCHECK(node *head)
{
    //检查是否有数据
    if (!head->next)
    {
        if (lang == 936)
            printf("空数据\n");
        else
            printf("Empty.\n");
        return 0;
    }
    if (lang == 936)
        printf("设置排序科目\n");
    else
        printf("Set sort by subject\n");
    printf("<1>\t<2>\t\n");
    printf("%s\t%s\t\n", subj, subj2);
    int choice;
    fflush(stdin);
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        SortAdaption(head, 1);
        break;
    case 2:
        SortAdaption(head, 2);
        break;
    }
}

//对subj的score降序排序
int SortAdaption(node *head, int subj)
{
    // 创建一个新表
    int f = 1; //切换标志
flag:
    f++;
    printf("flag=%d\n", f);

    node *newhead = (node *)malloc(sizeof(node));
    newhead->next = NULL;
    //遍历令新表的每一个score都等于原表的每一个score
    node *p = head->next;

    while (p)
    {
        node *newnode = (node *)malloc(sizeof(node));
        newnode->data = p->data;
        newnode->next = NULL;
        //插入到新表
        node *q = newhead;
        if (f % 2 == 0)
        {
            if (subj == 1)
                while (q->next && q->next->data.score < newnode->data.score)
                    q = q->next;
            if (subj == 2)
                while (q->next && q->next->data.score2 < newnode->data.score2)
                    q = q->next;
        }
        if (f % 2 == 1)
        {
            if (subj == 1)
                while (q->next && q->next->data.score > newnode->data.score)
                    q = q->next;
            if (subj == 2)
                while (q->next && q->next->data.score2 > newnode->data.score2)
                    q = q->next;
        }
        newnode->next = q->next;
        q->next = newnode;
        p = p->next;
    }
    //输出新表
    system("cls");
    List(newhead);
    if (lang == 936)
    {
        if (f % 2 == 0)
            printf("数据已升序\n");
        else
            printf("数据已降序\n");
        printf("'Enter'保存\t'C'切换排序方式\n");
    }
    else
    {
        if (f % 2 == 0)
            printf("Data ascending\n");
        else
            printf("Data descending.\n");
        printf("Save:'Enter'\tChange direction:'C'\n");
    }
    //用户输入回车将保存到原表
    char c;
    fflush(stdin);
    c = getche();
    if (c == '\r')
    {
        //将新表的数据拷贝到原表
        node *q = head->next;
        node *p = newhead->next;
        while (q)
        {
            q->data = p->data;
            q = q->next;
            p = p->next;
        }
        if (lang == 936)
            printf("已保存\n");
        else
            printf("Saved\n");
    }
    if (c == 'C' || c == 'c')
    {
        goto flag;
        printf("flag=%d\n", f);
    }

    return 1;
}
//小于60的人数
int Less(node *head)
{
    if (!head->next)
    {
        if (lang == 936)
            printf("空数据\n");
        else
            printf("Empty.\n");
        return 0;
    }
    int count = 0, count2 = 0;
    node *p = head->next;
    while (p)
    {
        if (p->data.score < 60)
            count++;
        if (p->data.score2 < 60)
            count2++;
        p = p->next;
    }
    if (lang == 936)
        printf("小于60分的人数：%d\t%d\n", count, count2);
    else
        printf(" 'Score' less than 60: %d\t%d\n", count, count2);
    return 1;
}
void Save(node *head)
{
    //将数据保存到文件data.md
    FILE *fp;
    fp = fopen("data.md", "w");
    if (!fp)
    {
        if (lang == 936)
            printf("保存失败\n");
        else
            printf("Save failed.\n");
        return;
    }
    node *p = head->next;
    while (p)
    {
        fprintf(fp, "%s\t%s\t%f\t%f\n", p->data.num, p->data.name, p->data.score, p->data.score2);
        p = p->next;
    }
    fclose(fp);
    if (lang == 936)
        printf("已保存\n");
    else
        printf("Saved.\n");
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
    else if (!strcmp(c, "/SAVE") || !strcmp(c, "/S"))
    {
        return 20;
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
    else if (!strcmp(c, "/SUBJ"))
    {
        return 439;
    }
    else if (!strcmp(c, "/SORTA") || !strcmp(c, "/SA"))
    {
        return 440;
    }
    else if (!strcmp(c, "/FINDA") || !strcmp(c, "/FA"))
    {
        return 19;
    }
    else if (!strcmp(c, "/LANG_CN") || !strcmp(c, "/CN"))
    {
        system("cls");
        return 936;
    }
    else if (!strcmp(c, "/LANG_EN") || !strcmp(c, "/EN"))
    {
        system("cls");
        return 101;
    }
    else if (!strcmp(c, "/BETA"))
    {
        system("cls");
        return 1000;
    }
    else if (!strcmp(c, "/DELPRO"))
    {

        return 1001;
    }
    else if (!strncmp(c, "CHCP", 4))
    {
        //将str放入system中
        system(str);
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
    int c;
    node *l = Creat();
    while (1)
    {
        if (lang == 936)
            printf("-等待指令...\n");
        else
            printf("-Waiting for Command:\n");
        gets(str);
        switch (Cheak(str))
        {
        case -2:
            system("cls");
            v();
            break;
        case 0:
            system("cls");
            break;
        case 1:
            l = Creat();
            if (lang == 936)
                printf("建立成功\n");
            else
                printf("Create Success.\n");
            fflush(stdin);
            break;
        case 2:
            Add(l);
            fflush(stdin);
            break;
        case 3:
            Find(l);
            fflush(stdin);
            break;
        case 4:
            Delete(l);
            fflush(stdin);
            break;
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
                if (lang == 936)
                    printf("注意：这可能造成数据混乱\t按下'Enter'继续\n");
                else
                    printf("ATTENTION: May cause data serial number dislocation\t(Continue:'Enter')");
                //输入回车继续，否则退回
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
        case 19:
            FindPlus(l);
            fflush(stdin);
            break;
        case 20:
            Save(l);
            break;
        case 90:
            system("cls");
            if (lang == 936)
                HelpCN();
            else
                Help();
            system("chcp");
            fflush(stdin);
            break;
        case 439:
            printf("Subj1:");
            scanf("%s", subj);
            printf("Subj2:");
            scanf("%s", subj2);
            fflush(stdin);
            break;
        case 440:
            SortCHECK(l);
            fflush(stdin);
            break;
        case 936:
            lang = 936;
            system("chcp");
            printf("已将语言更改至 中国-中文\n\n");
            HelpCN();
            break;
        case 101:
            lang = 101;
            system("chcp");
            printf("Language has been reset to  Global-English\n\n");
            Help();
            break;
        case -1:
            Quit();
            system("cls");
            break;
        case 1000:
            BETA();
            break;
        case 1001:
            DelPro(l);
            break;
        default:
            if (lang = 936)
                printf("未知的命令，输入'/help'查看帮助\n\n");
            else
                printf("\nUnknow Command.'/help' to view help.\n\n");
            break;
        }
    }
}
void BETA()
{
    system("cls");
    printf("These functions are being improved\n");
    printf("Custom delete\t\t'/Delpro'\n");
    v();
}
void Help()
{
    printf("-How to use?");
    printf("\nView help\t\t'/Help'   '/H'");
    printf("\nReload Menu\t\t'/Menu'   '/M'");
    printf("\nCreat new\t\t'/Creat'  '/C'");
    printf("\nAdd new data\t\t'/Add'    '/A'");
    printf("\nAdd new head data\t'/Addh'   '/Ah'");
    printf("\nInsert the data\t\t'/Insert' '/I'");
    printf("\nFind the data\t\t'/Find'   '/F'");
    printf("\nCunsom find\t\t'/Finda'   '/Fa'");
    printf("\nAlter the data\t\t'/Alter'  '/Al'");
    printf("\nAlter a data item\t'/AlterI' '/Ai'");
    printf("\nDelete the data\t\t'/Delete' '/D'");
    printf("\nCustom sorting\t\t'/SortA'   '/SA'");
    printf("\nChange (%s,%s)\t\t'/Subj'", subj, subj2);
    printf("\nList the dat\t\t'/List'   '/L'");
    printf("\nSave\t\t\t'/Save'   '/S'");
    printf("\nExit Program\t\t'/Exit'   '/E'");
    printf("\nCalculation:\t\t'/Avg''/More''/Less'");
    printf("\n更改语言\t\t'/Lang_cn'/Lang_en'");
    printf("\n");
}
void HelpCN()
{
    printf("如何使用？");
    printf("\n查看帮助\t\t'/Help'   '/H'");
    printf("\n加载主菜单\t\t'/Menu'   '/M'");
    printf("\n建立新数据\t\t'/Creat'  '/C'");
    printf("\n添加新数据\t\t'/Add'    '/A'");
    printf("\n头部添加新数据\t\t'/Addh'   '/Ah'");
    printf("\n插入数据\t\t'/Insert' '/I'");
    printf("\n查找数据\t\t'/Find'   '/F'");
    printf("\n自定义查找\t\t'/Finda'  '/Fa'");
    printf("\n修改数据\t\t'/Alter'  '/Al'");
    printf("\n修改数据项目\t\t'/Alteri' '/Ai'");
    printf("\n删除数据\t\t'/Delete' '/D'");
    printf("\n自定义排序\t\t'/SortA'  '/SA'");
    printf("\n科目更改 (当前%s,%s)\t'/Subj'", subj, subj2);
    printf("\n列出全部数据\t\t'/List'   '/L'");
    printf("\n保存\t\t\t'/Save'   '/S'");
    printf("\n退出\t\t\t'/Exit'   '/E'");
    printf("\n计算:\t\t\t'/Avg''/More''/Less'");
    printf("\n测试版内容\t\t'/Beta'");
    printf("\nChange language\t\t'/Lang_cn'/Lang_en'");
    printf("\n");
}
void Quit()
{
    system("cls");
    if (lang == 936)
        printf("\n\t未保存的内容将丢失\t按下'Enter'退出\n");
    else
        printf("\n\tUnsaved content will be lost\tExit:'Enter'\n");
    char c = getch();
    if (c == '\r')
    {
        system("cls");
        printf("\nBye.\n");
        Sleep(600);
        exit(0);
    }
    else
        return;
}
void v()
{
    printf("\n\n\tVersion:1.5_Beta_20210210020_WangShichao_YIT\n\tData save:dara.md\n\tView more through\n\t https://startracex.github.io/ \n\t https://github.com/STARTRACEX  \n");
}