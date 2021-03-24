#include "principal.h"
#include "zhuti.h"
#include "xiaogn.h"
#include <stdio.h>
#include <string.h>
void chongzhi_a(void)//重置自己的密码
{
	char new_password[50];
	char new_password_two[50];
	printf("输入新的6位密码\n");
	scanf("%s",new_password);
	if(strlen(new_password) != 6)
	{
		printf("输入的密码长度不对，请输入6位密码！");
		anykey_continue();
		return;
	}
	printf("再次输入新的6位密码\n");
	scanf("%s",new_password_two);
	if(strlen(new_password_two) != 6)
	{
		printf("输入的密码长度不对，请输入6位密码！");
		anykey_continue();
		return;
	}
	if(strcmp(new_password,new_password_two)==0)
	{
		strcpy(principal[0].password,new_password);
		printf("密码重置成功！");
		anykey_continue();	
	}
	else
	{
		printf("两次输入密码不一样\n");
		anykey_continue();
	}
}


void chongzhi_j(void)//重置教师的密码
{
	char number;
	printf("请输入老师的工号\n");
	scanf("%hhd",&number);
	int i = 0,biaozhi_js=0;
	for(i=0;i<cnt_j;i++)
	{	
		if(teacher[i].number==number)
		{
			biaozhi_js = 1;
			if(teacher[i].biaozhi_2 == 0)
			{
			printf("该老师已经退休");
			anykey_continue();
			return;
			}
			break;
		}	
	}
	if(biaozhi_js==0)
	{
		printf("查无此人\n");
		anykey_continue();
		return;
	}
	char new_password[50];
	char new_password_two[50];
	printf("输入新的6位密码\n");
	scanf("%s",new_password);
	if(strlen(new_password) != 6)
	{
		printf("输入的密码长度不对，请输入6位密码！");
		anykey_continue();
		return;
	}
	printf("再次输入新的6位密码\n");
	scanf("%s",new_password_two);
	if(strlen(new_password_two) != 6)
	{
		printf("输入的密码长度不对，请输入6位密码！");
		anykey_continue();
		return;
	}	
	if(strcmp(new_password,new_password_two)==0)
	{
		strcpy(teacher[(int)number-1].password,new_password);
		printf("密码重置成功！");
		teacher[(int)number-1].biaozhi_3 = 1;
		anykey_continue();
	}
	else
	{
		printf("两次输入密码不一样\n");
		anykey_continue();
	}
}


void tianjia_js(void)//添加教师
{
	char new_teacher_name[20];
	char new_teacher_sex[4];
	char new_teacher_password[50];
	printf("请输入：姓名、性别、6位密码\n");
	printf("姓名：");
	scanf("%s",new_teacher_name);
	printf("性别：");
	scanf("%s",new_teacher_sex);
	printf("6位密码：");
	scanf("%s",new_teacher_password);
	if(strlen(new_teacher_password) != 6)
	{
		printf("输入的密码长度不对，请输入6位密码！");
		anykey_continue();
		return;
	} 
	strcpy(teacher[cnt_j].name,new_teacher_name);
	strcpy(teacher[cnt_j].sex,new_teacher_sex);
	strcpy(teacher[cnt_j].password,new_teacher_password);
	teacher[cnt_j].biaozhi_3=1;
	teacher[cnt_j].biaozhi_2=1;
	teacher[cnt_j].biaozhi_1=0;
	teacher[cnt_j].number=cnt_j+1;
	cnt_j++;
	printf("添加成功\n");
	anykey_continue();	
}

void pl_tianjia_js(void)//批量添加教师
{
	int count=0;
	printf("输入要批量添加的老师的个数\n");
	scanf("%d",&count);
	while(count--)
	{
		char new_teacher_name[20];
		char new_teacher_sex[4];
		char new_teacher_password[7];
		printf("请输入姓名:");
		scanf("%s",new_teacher_name);
		printf("请输入性别:");
		scanf("%s",new_teacher_sex);
		printf("请输入密码:");
		scanf("%s",new_teacher_password);
		strcpy(teacher[cnt_j].name,new_teacher_name);
		strcpy(teacher[cnt_j].sex,new_teacher_sex);
		strcpy(teacher[cnt_j].password,new_teacher_password);
		teacher[cnt_j].biaozhi_3=1;
		teacher[cnt_j].biaozhi_2=1;
		teacher[cnt_j].biaozhi_1=0;
		teacher[cnt_j].number=cnt_j+1;
		cnt_j++;
		printf("添加老师成功\n");
		anykey_continue();	
	}
}

void shanchu_js(void)//删除教师
{
	int number;
	int biaoshi=0;
	printf("请输入要删除的老师工号\n");
	scanf("%d",&number);
	for(int i=0;i<50;i++)
	{
		if(number==teacher[i].number)
		{
			if(teacher[i].biaozhi_2 == 0)
			{
				printf("该教师已被删除");
				anykey_continue();
				return;
			}
			teacher[i].biaozhi_2=0;
			biaoshi = 1;
			printf("删除成功\n");
			anykey_continue();
			break;	
		}
	}
	if(biaoshi == 0)
	{
		printf("查无此人");
		anykey_continue();
	}	
}
void xianshi_zxjs(void)//显示所有在校教师
{
	int biaoshi = 0;
	printf("显示所有在校老师\n");
	for(int i=0;i<50;i++)
	{
		if(teacher[i].number)
		{
			if(teacher[i].biaozhi_2)
			{
				printf("姓名:%s  性别:%s  密码:%s 工号:%hhd\n",teacher[i].name,teacher[i].sex,teacher[i].password,teacher[i].number);
				biaoshi = 1;
			}
		}
		else
			break;
	}
	if(biaoshi == 0)
	{
		printf("没有在校老师");
		anykey_continue();
	}
}
void jiesuo_js(void)
{
	char numm = 0;
	printf("请输入要解锁的教师工号：");
	scanf("%hhd",&numm);
	for(int i=0;i<cnt_j;i++)
	{
		if(numm == teacher[i].number)
		{
			if(0 == teacher[i].biaozhi_2)
			{
				printf("该教师已经离职\n");
				anykey_continue();
				return;
			}
			else if(1 == teacher[i].biaozhi_3)
			{
				printf("该教师密码没有被锁\n");
				anykey_continue();
				return;
			}
			else if(0 == teacher[i].biaozhi_3)
			{
				teacher[i].biaozhi_3 = 1;
				printf("密码已经解锁\n");
				anykey_continue();
				return;
			}
		}	
	}
	printf("查无此人\n");
	anykey_continue();
	return;
}
void xianshi_txjs(void)//显示所有退休教师
{
	int biaoshi = 0;
	printf("显示退休老师\n");
	for(int i=0;i<50;i++)
	{
		if(teacher[i].number!=0)
		{
			if(teacher[i].biaozhi_2==0)
			{
				printf("姓名:%s  性别:%s  密码:%s  工号:%hhd  \n",teacher[i].name,teacher[i].sex,teacher[i].password,teacher[i].number);
				biaoshi = 1;
			}
		}
		else
			break;
	}
	if(biaoshi == 0)
	{
		printf("没有退休老师");
		anykey_continue();
	}
}
