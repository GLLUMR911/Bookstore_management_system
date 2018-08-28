#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
	char *pwd = NULL;

	pwd = getpass("请输入密码:");

	if(strcmp(pwd, "aaa123456") == 0)
	  printf("登陆成功!\n");
	
	else printf("登录失败!\n");

	
}
