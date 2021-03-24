#ifndef XIAOGN_H
#define XIAOGN_H

void xianshi_x(int cntt);   //学生二级界面
void xianshi_j(void);       //教师二级界面
void xianshi_a(void);       //校长二级界面
int dengru(int a);          //登入判断
char mima_sr(char str[]);   //隐藏密码输入
void anykey_continue(void); //按任意键继续
void shuchu_mima(void);		//输出密码长度不够的信息
void show_msg(const char* msg,float sec);//显示信息几秒
#endif//XIAOGN_H
