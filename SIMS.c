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
    // /menuʱ��������

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
//����һ����������������ͷָ��
node *Creat()
{
    // ����ռ�
    node *head = (node *)malloc(sizeof(node));
    // ��ͷ�ڵ�ָ���
    head->next = NULL;
    return head;
}
// �����µĽڵ㲢��data���
node *Creatnode(stu data)
{
    node *new = (node *)malloc(sizeof(node));
    // �½ڵ��������ֵ
    new->data = data;
    return new;
}
//���������븳ֵ,�ԷǷ����븳ֵ,���ؽڵ������
stu Scan()
{
    int f = 1;
    stu data;
    char str[128];
    scanf("%s", str);
    if (strlen(str) >= 10)
    {
        if (lang == 936)
            printf("�������̫���ˣ�������ΪUnknow\n");
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
            printf("�������̫���ˣ�������ΪUnknow\n");
        else
            printf("Input name failed:Too long\n");
        strcpy(data.name, "Unknow");
    }
    else
        strcpy(data.name, str);
    // score1
    scanf("%s", str);
    //��֤�Ƿ��ַ�
    for (int i = 0; i < strlen(str); i++)
    {
        if (isdigit(str[i]) == 0 && str[i] != '.')
        {
            if (lang == 936)
                printf("�����ܵ����ݣ�������Ϊ0\n");
            else
                printf("Input score failed:Impossible data\n");
            data.score = 0;
            f = 0; //��Ϊ�Ѿ���score��ֵ�ı��£�ʹ֮����ж��Թ�
            break;
        }
    }
    //��֤�Ϸ��ַ���.����
    if (f)
        for (int i = 0, j = 0; i < strlen(str); i++)
        {
            if (str[i] == '.')
                j++;
            if (j > 1)
            {
                if (lang == 936)
                    printf("�����ܵ����ݣ�������Ϊ0\n");
                else
                    printf("Input score failed:Impossible data\n");
                f = 0;
                data.score = 0;
                break;
            }
        }
    //��֤�Ϸ�����ȡֵ��Χ
    if (f)
        if (atof(str) > 150 || atof(str) < 0)
        {
            if (lang == 936)
                printf("�����ܵ����ݣ�������Ϊ 0\n");
            else
                printf("Input score failed:Impossible data\n");
            data.score = 0;
        }
    data.score = (float)atof(str);
    // score2
    scanf("%s", str);
    //��֤�Ƿ��ַ�
    for (int i = 0; i < strlen(str); i++)
    {
        if (isdigit(str[i]) == 0 && str[i] != '.')
        {
            if (lang == 936)
                printf("�����ܵ����ݣ�������Ϊ0\n");
            else
                printf("Input score failed:Impossible data\n");
            data.score2 = 0;
            f = 0; //��Ϊ�Ѿ���score��ֵ�ı��£�ʹ֮����ж��Թ�
            break;
        }
    }
    //��֤�Ϸ��ַ���.����
    if (f)
        for (int i = 0, j = 0; i < strlen(str); i++)
        {
            if (str[i] == '.')
                j++;
            if (j > 1)
            {
                if (lang == 936)
                    printf("�����ܵ����ݣ�������Ϊ0\n");
                else
                    printf("Input score failed:Impossible data\n");
                f = 0;
                data.score2 = 0;
                break;
            }
        }
    //��֤�Ϸ�����ȡֵ��Χ
    if (f)
        if (atof(str) > 150 || atof(str) < 0)
        {
            if (lang == 936)
                printf("�����ܵ����ݣ�������Ϊ 0\n");
            else
                printf("Input score failed:Impossible data\n");
            data.score2 = 0;
        }
    data.score2 = (float)atof(str);
    return data;
}
// ʹ��ͷ�巨��data���뵽����l��ͷ
void HeadAdd(node *head, stu data)
{
    node *new = Creatnode(data);
    new->next = head->next;
    head->next = new;
}
// ʹ��β�巨��data���뵽����l��β
void TailAdd(node *head, stu data)
{
    node *p = head;
    while (p->next)
    {
        p = p->next;
    }
    //��new�½��ڵ㸳ֵ
    node *new = Creatnode(data);
    p->next = new;
    p->next->next = NULL;
}
// β�巨����ڵ㵽����β��
void Add(node *head)
{
    if (lang == 936)
        printf("������Ϣ��ID �����ͷ�������\n ");
    else
        printf("Input the data(ID Nmae Score):\n ");
    while (1)
    {
        TailAdd(head, Scan());
        fflush(stdin);
        if (lang == 936)
            printf("�����Ѵ���\t ����'Enter'ȷ��");
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
//ͷ�巨
void AddH(node *head)
{
    if (lang == 936)
        printf("������Ϣ��ID �����ͷ�������\n ");
    else
        printf("Input the data(ID Nmae Score):\n  ");
    while (1)
    {
        //����һ�κ�ȷ�ϣ���ʾ�Ƿ����
        HeadAdd(head, Scan());
        fflush(stdin);
        if (lang == 936)
            printf("�����Ѵ���\t ����'Enter'����");
        else
            printf("-\nConfirm your input.\t(Continue:'Enter') ");
        char c = getchar();
        if (c != '\n')
            break;
        else
            printf(" ");
    }
}
//ΪInsert�ṩ����
int Preinsert(node *head)
{
    //����Ϊ��
    if (head->next)
    {
        //�������ڵ�����
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
            printf("�������к��Բ��뵽��\n ");
        else
            printf("\nInput the sequence number to insert:\n ");
        int i;
    retry:
        scanf("%d", &i);
        //��������Ų�����
        if (i > sn || i < 1)
        {
            if (lang == 936)
                printf("�����ܵ���ţ�����һ��\n ");
            else
                printf("\nImpossible sequence number.\n");
            goto retry;
        }
        //��������Ŵ���
        else
        {
            if (lang == 936)
                printf("������Ϣ��ID �������ͷ�������\n ");
            else
                printf("Input the data(ID Nmae Score):\n");
            //Ϊ�����ݴ����ڵ㣬����ֵ
            node *in;
            in = Creatnode(Scan());
            //����Insert
            Insert(head, i, in->data);
            //������ɲ���
            if (lang == 936)
                printf("���ݣ�\n");
            else
                printf("Data:\n\t");
            Print(in);
            if (lang == 936)
                printf("�Ѳ���\n");
            else
                printf("Inserted\n");
            free(in);
        }
        return 1;
    }
    //����Ϊ��
    else
    {
        if (lang == 936)
            printf("������\n");
        else
            printf("Empty.\n");
        return 0;
    }
}
//�������в���ڵ㣬iΪ����λ�ã�eΪ��������
void Insert(node *head, int i, stu e)
{
    //������λ��Ϊ��һ���ڵ�
    if (i == 1)
    {
        //�����½ڵ�
        node *new = Creatnode(e);
        //����ڵ�
        new->next = head->next;
        head->next = new;
    }
    else
    {
        //����ָ��pָ���i-1���ڵ�
        node *p = head->next;
        for (int j = 1; j < i - 1; j++)
        {
            p = p->next;
        }
        //�����½ڵ�
        node *new = Creatnode(e);
        //����ڵ�
        new->next = p->next;
        p->next = new;
    }
}
//���p�ڵ���Ϣ
void Print(node *p)
{
    printf(" %s\t%s\t%.2f\t%.2f\n", p->data.num, p->data.name, p->data.score, p->data.score2);
}
//�г�ȫ���ڵ�
void List(node *head)
{
    //��Ϊ��ѭ��
    node *p = head->next;
    if (!p)
    {
        if (lang == 936)
            printf("������\n");
        else
            printf("Empty.\n");
        return;
    }
    printf(" ID\t����\t%s\t%s\n", subj, subj2);
    while (p != NULL)
    {
        Print(p);
        p = p->next;
    }
}
//���ұ��е���data�Ľڵ㲢���أ��Ҳ�������NULL
node *Find(node *head)
{
    //�����գ�����ִ��
    if (head->next)
    {
        //���û�����Ҫ���ҵ�����,������䳤��
        if (lang == 936)
            printf("����ѧ����������\n");
        else
            printf("Input ID to search:\n");
        stu searchdata;
    retrynum:
        scanf("%s", searchdata.num);
        if (strlen(searchdata.num) > 10)
        {
            if (lang == 936)
                printf("�������̫���ˣ�����һ��\n");
            else
                printf("Too long,try again.\n");
            goto retrynum;
        }
        // p��ͷ�ڵ㿪ʼ����
        node *p = head->next;
        //��p��Ϊ��ʱѭ��
        while (p)
        {
            if (!strcmp(p->data.num, searchdata.num))
            {
                //�ҵ�������ڵ���Ϣ,����Print
                if (lang == 936)
                    printf("�ҵ����ݣ�\n");
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
            printf("������\n");
        else
            printf("Empty.\n");
    }
    return head->next;
}
node *FindPlus(node *head)
{
    // ���û�����Ҫ���ҵ���Ŀ
    if (head->next)
    {
        if (lang == 936)
        {
            printf(" ͨ����Ŀ���ң�\n\n");
            printf(" <1>\t<2>\t<3>\n");
            printf(" ����\t%s\t%s", subj, subj2);
            printf("\n��������ţ�\n");
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
            //��������
            if (lang == 936)
                printf("����������\n");
            else
                printf("Input name:\n");
            char name[10];
            scanf("%s", name);
            // p��ͷ�ڵ㿪ʼ����
            //��p��Ϊ��ʱѭ��
            while (p)
            {
                if (!strcmp(p->data.name, name))
                {
                    //�ҵ�������ڵ���Ϣ,����Print
                    if (f == 0)
                    {
                        if (lang == 936)
                            printf("�ҵ����ݣ�\n");
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
            //����÷�
            if (lang == 936)
                printf("����÷֣�\n");
            else
                printf("Input score:\n");
            float score;
            scanf("%f", &score);
            while (p)
            {
                if (p->data.score == score)
                {
                    //�ҵ�������ڵ���Ϣ,����Print
                    if (f == 0)
                    {
                        if (lang == 936)
                            printf("�ҵ����ݣ�\n");
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
            //����÷�
            if (lang == 936)
                printf("����÷֣�\n");
            else
                printf("Input score:\n");
            scanf("%f", &score);
            while (p)
            {
                if (p->data.score == score)
                {
                    //�ҵ�������ڵ���Ϣ,����Print
                    if (f == 0)
                    {
                        if (lang == 936)
                            printf("�ҵ����ݣ�\n");
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
                printf("�������\n");
            else
                printf("Input error!\n");
            break;
        }
    }
    else
    {
        if (lang == 936)
            printf("������\n");
        else
            printf("Empty.\n");
    }
    return head->next;
}
//���ұ���num����sr�Ľڵ㣬����ɾ��
void Delete(node *head)
{
    //�ж��Ƿ�Ϊ�ձ�
    if (!head->next)
    {
        if (lang == 936)
            printf("������\n");
        else
            printf("Empty.\n");
        return;
    }
    char sr[128];
    if (lang == 936)
        printf("����ID��ɾ����\n");
    else
        printf("Input ID to delete:\n");
retrydeletenum:
    scanf("%s", sr);
    //�ж�sr�Ƿ񳬹�10�ַ�
    if (strlen(sr) > 10)
    {
        if (lang == 936)
            printf("�������̫���ˣ�����һ��\n");
        else
            printf("Too long,try again.\n");
        goto retrydeletenum;
    }
    //��ɾ����ͷ�ڵ㿪ʼ����
    node *delet = head->next;
    node *front = head;
    //���ҽ��,ɾ���ڵ㲻����Ŀ��ڵ�������,�����˳�ѭ��
    while (strcmp(delet->data.num, sr))
    {
        front = delet;
        delet = delet->next;
        if (delet == NULL)
        {
            if (lang == 936)
                printf("δ�ҵ�����\n");
            else
                printf("Not found.\n");
            return;
        }
    }
    //�ҵ���ɾ��
    if (lang == 936)
        printf("���ݣ�\n");
    else
        printf("Data:\n\t");
    Print(delet);
    if (lang == 936)
        printf("����ɾ��������'Enter'ɾ��");
    else
        printf("Will be deleted. (Confirm:'Enter')");
    //����enter������ɾ��
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
    //����Ϊ��
    if (head->next)
    {
        if (lang == 936)
        {
            printf("ͨ����Ŀɾ����\n\n");
            printf("\t<1>\t<2>\t<3>\n");
            printf("\t����\t%s\t%s", subj, subj2);
            printf("\n��������ţ�\n");
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
        // se��Ϊѡ��
        scanf("%d", &se);
        sn = 0;
        switch (se)
        {
            //����������÷�
        case 1:
            printf("����������\n");
            scanf("%s", ch);
            //�������ڵ�����
            while (p != NULL)
            {
                if (strcmp(p->data.name, ch) == 0)
                {
                    sn++;
                    printf("<>>%d��>��%s\t%f\t%f\n", sn, p->data.name, p->data.score, p->data.score2);
                }
                p = p->next;
                // p���ʱ�˳�
                if (p == NULL)
                    break;
            }
            break;
        case 2:
            printf("����%s��\n", subj);
            scanf("%s", ch);
            while (p != NULL)
            {
                if (p->data.score == atof(ch))
                {
                    sn++;
                    printf("<%d>��%s\t%f\t%f\n", sn, p->data.name, p->data.score, p->data.score2);
                }
                p = p->next;
                // p���ʱ�˳�
                if (p == NULL)
                    break;
            }
            break;
        case 3: //ͬ��
            printf("����%s��\n", subj2);
            scanf("%s", ch);
            while (p != NULL)
            {
                if (p->data.score2 == atof(ch))
                {
                    sn++;
                    printf("<%d>��%s\t%f\t%f\n", sn, p->data.name, p->data.score2);
                }
                p = p->next;
                // p���ʱ�˳�
                if (p == NULL)
                    break;
            }
            break;
        default:
            //����һ��
            if (lang == 936)
                printf("�����ڵ���Ŀ������һ�Σ�\n");
            else
                printf("Input error,try items again:\n");
            goto dp;
            break;
        }

        //���û����ͬ�����
        if (sn == 0)
        {
            if (lang == 936)
                printf("δ�ҵ���ͬ��\n");
            else
                printf("Not found same item.\n");
            return 0;
        }
        int num = 0, q = 1;

    tr:
        //�������ɾ��
        if (lang == 936)
            printf("��������ţ�\n");
        else
            printf("Input serial number\n");

        num = 0, q = 1;
        q = scanf("%d", &num);
        //���������

        if (q != 1 || num < 1 || num > sn)
        {
            if (lang == 936)
                printf("�����������һ�Σ�\n");
            else
                printf("Input error,try again:\n");
            goto tr;
        }
        else
        {
            //�����ʾ
            if (lang == 936)
                printf("���ݣ�\n");
            else
                printf("Data:\n");
            //�����ɾ���ڵ�
            int i = 1;
            p = head->next;
            while (p != NULL)
            {
                if (i == num)
                {
                    printf("<%d>��%s\t%f\t%f\n", i, p->data.name, p->data.score, p->data.score2);
                    break;
                }
                p = p->next;
                i++;
            }
            if (lang == 936)
                printf("����ɾ��������'Enter'ȷ��\n");
            else
                printf("Will be delete.Confirm 'Enter'\n");
            //����enter������ɾ��
            char c;
            fflush(stdin);
            scanf("%c", &c);
            if (c != '\n')
            {
                return 0;
            }
            //������1��ɾ��ͷ�ڵ�
            if (num == 1)
            {
                node *delet = head->next;
                head->next = delet->next;
                free(delet);
            }
            else
            {
                //���������һ���ڵ�
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
                    //�������м�ڵ�
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
                printf("ɾ�������\n");
            else
                printf("Delete completed.\n");
        }
    }
    //����Ϊ��
    else
    {
        if (lang == 936)
            printf("������\n");
        else
            printf("Empty.\n");
        return 0;
    }
}

//���ұ���num����sr�Ľڵ㣬�����޸�
int Alter(node *head)
{
    //�ж��Ƿ�Ϊ�ձ�
    if (!head->next)
    {
        if (lang == 936)
            printf("������\n");
        else
            printf("Empty.\n");
        return 0;
    }
    else
    {
        char sr[128];
        if (lang == 936)
            printf("����ID���޸�\n");
        else
            printf("Input ID to modify:\n");
    retrymodifynum:
        scanf("%s", sr);
        //�ж�sr�Ƿ񳬹�10�ַ�
        if (strlen(sr) > 10)
        {
            if (lang == 936)
                printf("�������̫���ˣ�����һ��\n");
            else
                printf("Too long,try again.\n");
            goto retrymodifynum;
        }
        // ���޸Ĵ�ͷ�ڵ㿪ʼ����
        node *modify = head->next;
        //���ҽ��,�޸Ľڵ㲻����Ŀ��ڵ�������,�����˳�ѭ��
        while (strcmp(modify->data.num, sr))
        {
            //����Ҫ�޸ĵĽڵ�
            modify = modify->next;
            if (modify == NULL)
            {
                if (lang == 936)
                    printf("δ�ҵ�����\n");
                else
                    printf("Not found.\n");
                return 1;
            }
        }
        //�ҵ���������ڵ���Ϣ
        Print(modify);
        if (lang == 936)
            printf("ȷ���޸ģ�\t����'Enter'����");
        else
            printf("Modify? \t\t(Continue:'Enter')");
        char c;
        fflush(stdin);
        scanf("%c", &c);
        if (c != '\n')
            return 1;
        //�޸Ľڵ���Ϣ
        if (lang == 936)
            printf("������Ϣ��ID,�����ͷ�������\n");
        else
            printf("Input the data(ID Nmae Score):\n");
        modify->data = Scan();
        //��ʾ������޸�
        if (lang == 936)
            printf("���ݣ�\n");
        else
            printf("Data:\n\t");
        Print(modify);
        if (lang == 936)
            printf("�Ѹ���\n");
        else
            printf("Updated.\n");
    }
    return 1;
}
//���ұ���num����sr�Ľڵ㣬ѡ��һ�����ݽ����޸�
int AlterPlus(node *head)
{
    //�ж��Ƿ�Ϊ�ձ�
    if (!head->next)
    {
        if (lang == 936)
            printf("������\n");
        else
            printf("Empty.\n");
        return 0;
    }
    else
    {
        char sr[128];
        if (lang == 936)
            printf("����ID���޸�\n");
        else
            printf("Input ID to modify:\n");
    retrynum:
        scanf("%s", sr);
        //�ж�sr�Ƿ񳬹�10�ַ�
        if (strlen(sr) > 10)
        {
            if (lang == 936)
                printf("�������̫���ˣ�����һ��n");
            else
                printf("Too long,try again.\n");
            goto retrynum;
        }
        // ���޸Ĵ�ͷ�ڵ㿪ʼ����
        node *modify = head->next;
        //���ҽ��,�޸Ľڵ㲻����Ŀ��ڵ�������,�����˳�ѭ��
        while (strcmp(modify->data.num, sr))
        {
            //����Ҫ�޸ĵĽڵ�
            modify = modify->next;
            if (modify == NULL)
            {
                if (lang == 936)
                    printf("δ�ҵ�����\n");
                else
                    printf("Not found.\n");
                return 1;
            }
        }
        //�ҵ���������ڵ���Ϣ
        if (lang == 936)
        {
            printf("\tID\t����\t%s\t%s\n", subj, subj2);
            printf("��Ŀ�� <1>\t<2>\t<3>\t<4>\n���ݣ� ");
        }
        else
        {
            printf("\tID\tName\t%s\t%s\n", subj, subj2);
            printf("Items:  <1>\t<2>\t<3>\t<4>\nFound:  ");
        }
        Print(modify);
        //ѡ���޸���
        int choice;
        char stest[128];
    rechoice:
        if (lang == 936)
            printf("ѡ����Ŀ���޸�\n");
        else
            printf("Select modified data item:\n");
        fflush(stdin);
        scanf("%d", &choice);
        //ȷ���޸�
        if (lang == 936)
            printf("ȷ���޸ģ�\t\t����'Enter'����");
        else
            printf("Modify? \t\t(Continue:'Enter')");
        char c;
        fflush(stdin);
        scanf("%c", &c);
        if (c != '\n')
            return 1;
        //�޸Ľڵ���Ϣ/����choice�޸Ľڵ���Ϣ
        switch (choice)
        {
        case 1:
            if (lang == 936)
                printf("�µ�ID��\n");
            else
                printf("Input new ID:\n");
            scanf("%s", stest);
            if (strlen(stest) > 10)
            {
                if (lang == 936)
                    printf("�������̫���ˣ�����һ��n");
                else
                    printf("Too long,try again.\n");
                goto rechoice;
            }
            strcpy(modify->data.num, stest);
            break;
        case 2:
            if (lang == 936)
                printf("�����µ�����\n");
            else
                printf("Input new name.\n");
            scanf("%s", stest);
            if (strlen(stest) > 10)
            {
                if (lang == 936)
                    printf("�������̫���ˣ�����һ��\n");
                else
                    printf("Too long,try again.\n");
                goto rechoice;
            }
            strcpy(modify->data.name, stest);
            break;
        case 3:
            if (lang == 936)
                printf("�����µķ���\n");
            else
                printf("Input new score.\n");
            scanf("%s", stest);
            //�ж������Ƿ�Ϊ���ֺ�С����
            for (int i = 0; i < strlen(stest); i++)
            {
                if ((isdigit(stest[i]) == 0) && stest[i] != '.')
                {
                    if (lang == 936)
                        printf("�����ܵ����ݣ�����һ��\n");
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
                            printf("�����ܵ����ݣ�����һ��\n");
                        else
                            printf("Input score failed:Impossible data\n");
                        goto rechoice;
                    }
                }
            }
            if (atof(stest) < 0 || atof(stest) > 150)
            {
                if (lang == 936)
                    printf("�����ܵ����ݣ�����һ��\n");
                else
                    printf("Impossible data,try again.\n");
                goto rechoice;
            }
            modify->data.score = (float)atof(stest);
            break;
        case 4:
            if (lang == 936)
                printf("�����µķ���\n");
            else
                printf("Input new score.\n");
            scanf("%s", stest);
            //�ж������Ƿ�Ϊ���ֺ�С����
            for (int i = 0; i < strlen(stest); i++)
            {
                if ((isdigit(stest[i]) == 0) && stest[i] != '.')
                {
                    if (lang == 936)
                        printf("�����ܵ����ݣ�����һ��\n");
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
                            printf("�����ܵ����ݣ�����һ��\n");
                        else
                            printf("Input score failed:Impossible data\n");
                        goto rechoice;
                    }
                }
            }
            if (atof(stest) < 0 || atof(stest) > 150)
            {
                if (lang == 936)
                    printf("�����ܵ����ݣ�����һ��\n");
                else
                    printf("Impossible data,try again.\n");
                goto rechoice;
            }
            modify->data.score2 = (float)atof(stest);
            break;
        default:
            if (lang == 936)
                printf("�Ҳ�������\n");
            else
                printf("Not found data:\n");
            goto rechoice;
        }
        //�޸ĳɹ�
        if (lang == 936)
            printf("����\n");
        else
            printf("Data:\n");
        Print(modify);
        if (lang == 936)
            printf("�Ѹ���\n");
        else
            printf("Updated.\n");
    }
    return 1;
}
//��ƽ����
float Average(node *head)
{
    if (!head->next)
    {
        if (lang == 936)
            printf("������\n");
        else
            printf("Empty.\n");
        return 0;
    }
    //����
    float sum = 0, sum2 = 0, count = 0;
    //�������
    node *p = head->next;
    while (p)
    {
        sum += p->data.score;
        sum2 += p->data.score2;
        count++;
        p = p->next;
    }
    if (lang == 936)
        printf("ƽ��ֵ��%s %.2f\t%s %.2f\n", subj, sum / count, subj2, sum2 / count);
    else
        printf(" Average:%.2f\t%.2f\n", subj, sum / count, subj2, sum2 / count);
    return 1;
}
//�����90������
int More(node *head)
{
    if (!head->next)
    {
        if (lang == 936)
            printf("������\n");
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
        printf("����90�ֵ�������%s %d\t%s %d\n", subj, count, subj2, count2);
    else
        printf(" 'Score' more than 90: %s %d\t%s %d\n", subj, count, subj2, count2);
    return 1;
}
int SortCHECK(node *head)
{
    //����Ƿ�������
    if (!head->next)
    {
        if (lang == 936)
            printf("������\n");
        else
            printf("Empty.\n");
        return 0;
    }
    if (lang == 936)
        printf("���������Ŀ\n");
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

//��subj��score��������
int SortAdaption(node *head, int subj)
{
    // ����һ���±�
    int f = 1; //�л���־
flag:
    f++;
    printf("flag=%d\n", f);

    node *newhead = (node *)malloc(sizeof(node));
    newhead->next = NULL;
    //�������±��ÿһ��score������ԭ���ÿһ��score
    node *p = head->next;

    while (p)
    {
        node *newnode = (node *)malloc(sizeof(node));
        newnode->data = p->data;
        newnode->next = NULL;
        //���뵽�±�
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
    //����±�
    system("cls");
    List(newhead);
    if (lang == 936)
    {
        if (f % 2 == 0)
            printf("����������\n");
        else
            printf("�����ѽ���\n");
        printf("'Enter'����\t'C'�л�����ʽ\n");
    }
    else
    {
        if (f % 2 == 0)
            printf("Data ascending\n");
        else
            printf("Data descending.\n");
        printf("Save:'Enter'\tChange direction:'C'\n");
    }
    //�û�����س������浽ԭ��
    char c;
    fflush(stdin);
    c = getche();
    if (c == '\r')
    {
        //���±�����ݿ�����ԭ��
        node *q = head->next;
        node *p = newhead->next;
        while (q)
        {
            q->data = p->data;
            q = q->next;
            p = p->next;
        }
        if (lang == 936)
            printf("�ѱ���\n");
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
//С��60������
int Less(node *head)
{
    if (!head->next)
    {
        if (lang == 936)
            printf("������\n");
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
        printf("С��60�ֵ�������%d\t%d\n", count, count2);
    else
        printf(" 'Score' less than 60: %d\t%d\n", count, count2);
    return 1;
}
void Save(node *head)
{
    //�����ݱ��浽�ļ�data.md
    FILE *fp;
    fp = fopen("data.md", "w");
    if (!fp)
    {
        if (lang == 936)
            printf("����ʧ��\n");
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
        printf("�ѱ���\n");
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
        //��str����system��
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
            printf("-�ȴ�ָ��...\n");
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
                printf("�����ɹ�\n");
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
            //�������޸ģ�c=1
            if (c == 1)
            {
                if (lang == 936)
                    printf("ע�⣺�����������ݻ���\t����'Enter'����\n");
                else
                    printf("ATTENTION: May cause data serial number dislocation\t(Continue:'Enter')");
                //����س������������˻�
                char c = getchar();
                if (c == '\n')
                    AddH(l);
            }
            //δ���޸ģ�ֱ�ӽ��в���
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
            printf("�ѽ����Ը����� �й�-����\n\n");
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
                printf("δ֪���������'/help'�鿴����\n\n");
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
    printf("\n��������\t\t'/Lang_cn'/Lang_en'");
    printf("\n");
}
void HelpCN()
{
    printf("���ʹ�ã�");
    printf("\n�鿴����\t\t'/Help'   '/H'");
    printf("\n�������˵�\t\t'/Menu'   '/M'");
    printf("\n����������\t\t'/Creat'  '/C'");
    printf("\n���������\t\t'/Add'    '/A'");
    printf("\nͷ�����������\t\t'/Addh'   '/Ah'");
    printf("\n��������\t\t'/Insert' '/I'");
    printf("\n��������\t\t'/Find'   '/F'");
    printf("\n�Զ������\t\t'/Finda'  '/Fa'");
    printf("\n�޸�����\t\t'/Alter'  '/Al'");
    printf("\n�޸�������Ŀ\t\t'/Alteri' '/Ai'");
    printf("\nɾ������\t\t'/Delete' '/D'");
    printf("\n�Զ�������\t\t'/SortA'  '/SA'");
    printf("\n��Ŀ���� (��ǰ%s,%s)\t'/Subj'", subj, subj2);
    printf("\n�г�ȫ������\t\t'/List'   '/L'");
    printf("\n����\t\t\t'/Save'   '/S'");
    printf("\n�˳�\t\t\t'/Exit'   '/E'");
    printf("\n����:\t\t\t'/Avg''/More''/Less'");
    printf("\n���԰�����\t\t'/Beta'");
    printf("\nChange language\t\t'/Lang_cn'/Lang_en'");
    printf("\n");
}
void Quit()
{
    system("cls");
    if (lang == 936)
        printf("\n\tδ��������ݽ���ʧ\t����'Enter'�˳�\n");
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