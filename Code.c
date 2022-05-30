#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<ctype.h>
void Cheak();
void help();

int main()
{
    
    Cheak();
    system("pause");
    printf("hi");
    return 0;
}
//检查用户的输入执行不同功能
void Cheak()
{
    Cheak:system("cls");
    printf("Wait For Command\n");
    char cm[48],*C;
    // C=strupr(gets(cm));
    // if (!strcmp(C, "/HELP") || !strcmp(C, "/H"))
    //     help();
    // else if (!strcmp(C, "/EXIT") || !strcmp(C, "/E") || !strcmp(C, "/QUIT") || !strcmp(C, "/Q"))
    //     exit(0);
    

    // else if (!strcmp(C, "/ADD") || !strcmp(C, "/A"))
    // {

    // }
    // else if (!strcmp(C, "/CREAT"))
    // {
    // }
    // else if (!strcmp(C, "/FIND") || !strcmp(C, "/F"))
    // {
    // }
    // else if (!strcmp(C, "/CHANGE") || !strcmp(C, "/C"))
    // {
    // }
    // else if (!strcmp(C, "/DELETE") || !strcmp(C, "/D"))
    // {
    // }
    // else if (!strcmp(C, "/LIST") || !strcmp(C, "/L"))
    // {
    // }
    // else
    //     printf("\nUnrecognized command, enter '/Help' to view help.\n");
    // system("pause");
}
//主菜单
void Menu()
{
    Cheak();
    printf("\n/Help:View help");
    printf("\n/Menu:Back to Menu");
    printf("\n/Creat:Creat the data");
    printf("\n/Find:Find the data");
    printf("\n/Change:Change the data");
    printf("\n/Delete:Delete the data");
    printf("\n/List:List the data");
    printf("\n/Exit:Exit Program");
    printf("\n::<Cheak>::\n");
}
