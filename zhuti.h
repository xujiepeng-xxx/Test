#ifndef ZHUTI_H
#define ZHUTI_H
#define MAX_XS 1000    //最大学生人数
#define MAX_JS 50      //最大教师人数
typedef struct Student //重定义结构体变量
{
	char name[20];   //姓名
	char sex[4];     //性别
	int  number;     //学号
	char password[7];//密码 6位
	char chinese;    //语文成绩
	char math;       //数学成绩
	char english;	 //英语成绩
	char biaozhi_1;	 //是否第一次登入的标记，0为未登入过
	char biaozhi_2;  //是否退学的标记，1在校
	char biaozhi_3;  //密码是否被锁的标记，0被锁
}Student;

typedef struct Teacher//重定义结构体变量
{
	char name[20];    //姓名
	char sex[4];      //性别
	char password[7]; //密码 6位
	char number;	  //工号
	char biaozhi_1;	  //是否第一次登入的标记，0为未登入过
	char biaozhi_2;   //是否退休的标记，1在校
	char biaozhi_3;   //密码是否被锁的标记，0被锁
}Teacher;
typedef struct Principal//重定义结构体变量
{
	char zhanghao[6];//帐号 admin
	char password[7];//密码 admin
	char biaozhi;	 //是否第一次登入的标记，0为未登入过
}Principal;
extern Student* student;     //声明结构体变量 学生
extern Teacher* teacher;     //声明结构体变量 教师
extern Principal* principal; //声明结构体变量 校长
extern int cnt;   //学生人数
extern int cnt_j; //教师人数
void daoru(void); //导入数据
void run_xt(void);//系统启动
#endif//HUTI_H
