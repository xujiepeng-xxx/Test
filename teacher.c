#include"teacher.h"
#include"zhuti.h"
#include"xiaogn.h"
#include<string.h>
#include<getch.h>
Teacher *teacher;
int p=0;



void tianjia_xs(void)//添加学生
{
	char new_student_name[20];
	char new_student_sex[4];
	char new_student_password[7];
	printf("请输入姓名:");
	scanf("%s",new_student_name);
	printf("请输入性别:");
	scanf("%s",new_student_sex);
	printf("请输入密码:");
	scanf("%s",new_student_password);
	strcpy(student[cnt].name,new_student_name);
	strcpy(student[cnt].sex,new_student_sex);
	strcpy(student[cnt].password,new_student_password);
	student[cnt].biaozhi_2=1;
	student[cnt].biaozhi_1=0;
	student[cnt].biaozhi_3=1;
	student[cnt].number=cnt+1;
	cnt++;
	printf("添加成功\n");
	anykey_continue();	
}

void pl_tianjia_xs(void)//批量添加学生
{
	int count=0;
	printf("输入要批量添加的学生的个数\n");
	scanf("%d",&count);
	while(count--)
	{
		char new_student_name[20];
		char new_student_sex[4];
		char new_student_password[7];
		printf("请输入姓名:");
		scanf("%s",new_student_name);
		printf("请输入性别:");
		scanf("%s",new_student_sex);
		printf("请输入密码:");
		scanf("%s",new_student_password);
		strcpy(student[cnt].name,new_student_name);
		strcpy(student[cnt].sex,new_student_sex);
		strcpy(student[cnt].password,new_student_password);
		student[cnt].biaozhi_3=1;
		student[cnt].biaozhi_2=1;
		student[cnt].biaozhi_1=0;
		student[cnt].number=cnt+1;
		cnt++;
		printf("添加成功\n");
		anykey_continue();	
	}
}

void jiesuo_xs(void)//解锁学生
{
	printf("密码被锁定的学生学号\n");
	int  number;
	scanf("%d",&number);
	for(int i=0;i<cnt;i++)
	{	
		if(student[i].number==number&&student[i].biaozhi_2==1)
			break;
		if(i==cnt-1)
		{
			printf("查无此人\n");
			anykey_continue();
			return;
		}	
	}
	if(student[number-1].biaozhi_3==0)
	{
		student[number-1].biaozhi_3=1;
		printf("解锁成功\n");
		anykey_continue();
	}
	else
	{
		printf("未被锁定\n");
		anykey_continue();
	}
}
void shanchu_xs(void)//删除学生
{
	int  number1,number2;
	printf("请输入学生学号\n");
	scanf("%d",&number1);
	printf("请再次输入学生学号\n");
	scanf("%d",&number2);
	if(number1!=number2)
	{
		printf("两次输入不一致\n");
		anykey_continue();	
		return ;
	}
	for(int i=0;i<cnt;i++)
	{
		if(number1==student[i].number&&student[i].biaozhi_2==1)
		{
			student[i].biaozhi_2=0;
			printf("删除成功\n");
			break;	
		}
		else if(i==cnt-1)
			printf("查无此人\n");
	}
	anykey_continue();	
	
}


void xiugai_xs(void)//修改学生信息
{
	printf("请输入被修改人学号\n");
	int number;
	char newname[20];
	char newsex[4];
	char newpassword[7];
	char newchinese;
	char newmath;
	char newenglish;
	scanf("%d",&number);
	for(int i=0;i<cnt;i++)
	{
		if(number==student[i].number&&student[i].biaozhi_2==1)
		{
			printf("原信息->姓名:%-10s\t,性别:%-4s\t,密码:%-6s\t,学号:%-3d,语文:%-3hhd,数学:%-3hhd,英语:%-3hhd\n",student[i].name,student[i].sex,student[i].password,student[i].number,student[i].chinese,student[i].math,student[i].english);
			printf("请输入新的信息\n");
			printf("姓名、性别、密码、语文、数学、英语\n");
			scanf("%s %s %s %hhd %hhd %hhd",newname,newsex,newpassword,&newchinese,&newmath,&newenglish);
			strcpy(student[i].name,newname);
			strcpy(student[i].sex,newsex);
			strcpy(student[i].password,newpassword);
			student[i].chinese=newchinese;
			student[i].math=newmath;
			student[i].english=newenglish;
			printf("修改成功\n");
			break;
		}
		if(i==cnt-1)
		{
			printf("查无此人\n");
			break;
		}
		
	}
	anykey_continue();	
}

void chazhao_xs(void)//查找学生信息
{
	printf("查找的模式：按学号查找输入1、按姓名查找请按2\n");
	int shu;
	scanf("%d",&shu);
	if(shu==1)
	{	printf("要查找的学生学号\n");
		int number;
		scanf("%d",&number);
		for(int i=0;i<cnt;i++)
		{
			if(number==student[i].number)
			{
				if(student[i].biaozhi_2==1)
					printf("在校学生\n");
				else
					printf("离校学生\n");
				printf("姓名:%-10s\t,性别:%-4s\t,密码:%-6s\t,学号:%-3d,语文:%-3hhd,数学:%-3hhd,英语:%-3hhd\n",student[i].name,student[i].sex,student[i].password,student[i].number,student[i].chinese,student[i].math,student[i].english);
				break;
			}
			if(i==cnt-1)
				printf("查无此人\n");
		}
	}
	else if(shu==2)
	{
		printf("要查找的学生姓名\n");
		char find_name[20];
		scanf("%s",find_name);
		for(int i=0;i<cnt;i++)
		{
			if(strcmp(student[i].name,find_name) == 0)
			{
				if(student[i].biaozhi_2==1)
					printf("在校学生\n");
				else
					printf("离校学生\n");
				printf("姓名:%-10s\t,性别:%-4s\t,密码:%-6s\t,学号:%-3d,语文:%-3hhd,数学:%-3hhd,英语:%-3hhd\n",student[i].name,student[i].sex,student[i].password,student[i].number,student[i].chinese,student[i].math,student[i].english);
				break;
			}
			if(i==cnt-1)
				printf("查无此人\n");
		}
	}
	anykey_continue();	
	
}
void shuru_xs(void)//输入学生成绩
{
	printf("要添加成绩的学生学号\n");
	int number;
	scanf("%d",&number);
	for(int i=0;i<cnt;i++)
	{	
		if(student[i].number==number&&student[i].biaozhi_2==1)
			break;
		if(i==cnt-1)
		{
			printf("查无此人\n");
			anykey_continue();
			return;
		}
			
	}
	char newchinese,newmath,newenglish;
	printf("输入成绩\n");
	printf("语文、数学、英语\n");
	scanf("%hhd %hhd %hhd",&newchinese,&newmath,&newenglish);
	for(int i=0;i<cnt;i++)
	{
		if(number==student[i].number)
		{
			student[i].chinese=newchinese;
			student[i].math=newmath;
			student[i].english=newenglish;
			printf("添加成功\n");
			break;
		}
		if(i==cnt-1)
			printf("查无此人\n");	
	}
	anykey_continue();		
}

void pl_shuru_xs(void)//批量输入学生成绩
{
	int count=0;
	printf("要添加成绩的学生个数\n");
	scanf("%d",&count);
	
	while(count--)
	{
		printf("要添加成绩的学生学号\n");
		int number;
		scanf("%d",&number);
		for(int i=0;i<cnt;i++)
		{	
			if(student[i].number==number&&student[i].biaozhi_2==1)
				break;
			if(i==cnt-1)
			{
				printf("查无此人\n");
				anykey_continue();
				return;
			}
			
		}
		char newchinese,newmath,newenglish;
		printf("输入成绩\n");
		printf("语文、数学、英语\n");
		scanf("%hhd %hhd %hhd",&newchinese,&newmath,&newenglish);
		for(int i=0;i<cnt;i++)
		{
			if(number==student[i].number)
			{
				student[i].chinese=newchinese;
				student[i].math=newmath;
				student[i].english=newenglish;
				printf("添加成功\n");
				break;
			}
			if(i==cnt-1)
				printf("查无此人\n");	
		}
		anykey_continue();	
	}	
}
void xianshi_zxxs(void)
{
	printf("显示在校学生\n");
	for(int i=0;i<100;i++)
	{
		if(student[i].number!=0)
		{
			if(student[i].biaozhi_2==1)
			printf("姓名:%-10s\t,性别:%-4s\t,密码:%-6s\t,学号:%-3d,语文:%-3hhd,数学:%-3hhd,英语:%-3hhd\n",student[i].name,student[i].sex,student[i].password,student[i].number,student[i].chinese,student[i].math,student[i].english);
		}
		else
			break;
		
	}
	anykey_continue();	
	
}

void xianshi_txxs(void)
{
	printf("显示退学学生\n");
	for(int i=0;i<100;i++)
	{
		if(student[i].number!=0)
		{
			if(student[i].biaozhi_2==0)
			printf("姓名:%-10s\t,性别:%-4s\t,密码:%-6s\t,学号:%-6d,语文:%-3hhd,数学:%-3hhd,英语:%-3hhd\n",student[i].name,student[i].sex,student[i].password,student[i].number,student[i].chinese,student[i].math,student[i].english);
		}
		else
			break;
	}
	anykey_continue();	
	
}
void chongzhi_xs(void)
{
	printf("请输入要修改密码的学生学号\n");
	int number;
	scanf("%d",&number);
	if(student[number-1].biaozhi_2==0)
	{
		printf("查无此人\n");
		anykey_continue();
		return;
	}
	for(int i=0;i<cnt;i++)
	{	
		if(student[i].number==number)
			break;
		if(i==cnt-1)
		{
			printf("查无此人\n");
			anykey_continue();
			return;
		}		
	}	
	char new_password[7];
	char new_password_two[7];
	printf("输入新密码\n");
	scanf("%s",new_password);
	if(strlen(new_password) != 6)
	{
		shuchu_mima();
		return ;
	}
	printf("再次输入新密码\n");
	scanf("%s",new_password_two);
	if(strlen(new_password_two) != 6)
	{
		shuchu_mima();
		return ;
	}
	if(strcmp(new_password,new_password_two)==0)
		strcpy(student[number-1].password,new_password);
	else
		printf("两次输入密码不一样\n");
	anykey_continue();	
}






















