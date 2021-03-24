#include "student.h"
#include "zhuti.h"
#include"xiaogn.h"
#include<stdio.h>
#include<string.h>
void chaxun_x_cj(int num_x)  //学生查询成绩信息
{
	printf("语文成绩:%-5hhd,数学成绩:%-5hhd,英语成绩:%-5hhd\n",student[num_x].chinese,student[num_x].math,student[num_x].english);
	char max_chinese=0,max_math=0,max_english=0;
	double sum_chinese=0,sum_math=0,sum_english=0;
	int pai1=0,pai2=0,pai3=0;
	int i=0;
	for(i=0;i<cnt;i++)
	{
		if(student[i].number)
		{
			sum_chinese+=(double)student[i].chinese;
			sum_math+=(double)student[i].math;
			sum_english+=(double)student[i].english;
			if(student[i].math>max_math)
				max_math=student[i].math;
			if(student[i].chinese>max_chinese)
				max_chinese=student[i].chinese;			
			if(student[i].english>max_english)
				max_english=student[i].english;
			if(student[num_x].chinese<student[i].chinese)
				pai1++;
			if(student[num_x].math<student[i].math)
				pai2++;
			if(student[num_x].english<student[i].english)
				pai3++;
		}
		else
			break;
	}
	printf("语文最高:%-5hhd,数学最高:%-5hhd,英语最高:%-5hhd\n",max_chinese,max_math,max_english);
	printf("语文排名:%-5d,数学排名:%-5d,英语排名:%-5d\n",pai1+1,pai2+1,pai3+1);
	printf("语文平均:%-5.2f,数学平均:%-5.2f,英语平均:%-5.2f\n",sum_chinese/i,sum_math/i,sum_english/i);
	anykey_continue();
}
void xiugai_x(int num_x)     //学生密码
{
	char old_password[7];
	char new_password[7];
	char new_password_two[7];
	printf("请输入原密码：");
	scanf("%s",old_password);
	if(strcmp(old_password,student[num_x].password) == 0)//密码正确
	{
		printf("密码正确、请输入新密码\n");
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
		{
			strcpy(student[num_x].password,new_password);
			anykey_continue();
		}	
		else
		{
			printf("两次输入密码不一样\n");
			anykey_continue();	
		}
	}
	else
	{
		printf("原密码错误\n");
		anykey_continue();	
	}
	
}

void chaxun_x_gr(int num_x)  //学生查询个人信息
{
	printf("姓名:%s,性别:%s,学号:%d,密码:%s\n",student[num_x].name,student[num_x].sex,student[num_x].number,student[num_x].password);
	anykey_continue();	
}


