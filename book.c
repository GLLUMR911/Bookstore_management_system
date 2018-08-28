#include <stdio.h>
#include <mysql/mysql.h>
#include <string.h>
#include <stdlib.h>


void insert_admin();
void update_admin();
void delete_admin();
int login_admin();
void insert_book();
void update_book();
void delete_book();
void select_book();
void insert_user();
int login_user();
void select1_book();
void select2_book();
void delete_user();

int main()
{
gll:
	printf("\n\n\n欢迎使用书店管理系统!\n\n\n");
	
	printf("         主菜单          \n");
			
	printf("*************************\n");

	printf("请选择登录用户:\n");
	printf("1:管理员\n2.客户\n3.退出系统\n");
	
	printf("*************************\n");

	int a, b;

	int zz, c;
	int z;
	int aa;
	int i;

	scanf("%d", &a);
	while(a && a != 3)

	{
		if(1 == a)
		{
umr:			
			printf("*************************\n");


			printf("请选择服务:\n");
			printf("1.创建管理员\n2.修改管理员信息\n3.删除管理员\n4.登录\n5.返回上级界面\n6.退出系统\n");
			
			printf("*************************\n");

			scanf("%d", &b);

			if(1 == b)
			{
				insert_admin();
			}
	
			if(2 == b)
			{
				update_admin();
			}

			if(3 == b)
			{
				delete_admin();
			}
			
			if(4 == b)
			{
			


				z = login_admin();
		

				if(z == 1)
				{
					while(aa && aa!= 5)	
					{
qwe:
						printf("*************************\n\n");

						printf("请选择操作:\n");

						printf("1.添加书籍!\n");
						printf("2.修改书籍!\n");
						printf("3.查看书籍!\n");
						printf("4.删除书籍!\n");
						printf("5.返回上级菜单!\n");
						printf("*************************\n\n");

						scanf("%d", &aa);
						if(1 == aa)
						{
							insert_book();
						}

						if(2 == aa)
						{
							update_book();
						}

						if(3 == aa)
						{
							select_book();
						}

						if(4 == aa)
						{
							delete_book();
						}

					}
				}
				if(z == -1)
				{
					goto umr;	
				}
			}

			if(5 == b)
			{
				goto gll;
			}

			if(6 == b)
			  exit(0);


		}
		if(2 == a)
		{	
zzz:
			printf("*************************\n\n");

		
			printf("请选择操作:\n");
			printf("1.创建用户\n2.登录\n3.返回上级目录\n");
			
			printf("*************************\n\n");


			scanf("%d", &i);
			if(1 == i)
			{
				insert_user();
			}
			
			if(2 == i)
			{

				zz = login_user();

				if(zz == 1)
				{

					while(1)	
					{	
						printf("*************************\n\n");

						printf("请选择操作:\n");

						printf("1.按书名查找书籍!\n2.显示所有书籍\n");
						printf("3.删除用户!\n");
						printf("4.返回上级菜单!\n");

						printf("*************************\n\n");

						scanf("%d", &c);
						if(1 == c)
						{
							select1_book();
						}

						if(2 ==c)
						{
							select2_book();
						}

						if(3 == c)
						{
							delete_user();
						}

						if(4 == c)
						{
							goto zzz;
						}



				}


				if(zz == -1)
				{
					goto zzz;	
				}


			}
		}	
			if(3 == i)
			{
				goto gll;
			}
		
	}
	}
	return 0;
}

void insert_admin()
{
	MYSQL mysql;

	mysql_init(&mysql);

	if(!mysql_real_connect(&mysql, "localhost", "gll", "123456", "mydb", 0, NULL, 0))
	{
	
		fprintf(stderr, "Failed to connect to database :Error : %s\n", mysql_error(&mysql));
	
	}


	mysql_query(&mysql, "set names utf8");


	char Insert[100];
	unsigned int aid;
	char aname[20];
	char apasswd[16];

	int passwd = 123456;
	int temp;
	printf("请输入终端密码:");
	scanf("%d", &temp);
	if(temp == passwd)
	{
		printf("密码正确!\n");
		printf("请输入:\n");
		printf("管理员id:"); scanf("%d", &aid);
		printf("管理员姓名:"); scanf("%s", aname);
		printf("管理员密码:"); scanf("%s", apasswd);

		sprintf(Insert, "insert into adm values (%d, '%s', '%s')", aid, aname, apasswd);

		if(	mysql_query(&mysql, Insert))
		{
			fprintf(stderr, "Failed to insert to database :Error : %s\n", mysql_error(&mysql));

		}
		else
		{
			if(mysql_affected_rows(&mysql) == 1)
			{
				printf("添加管理员成功!\n");
			}
			else 
			{
				printf("添加管理员失败!\n");
			}
		}

	}

	mysql_close(&mysql);
}

void update_admin()
{
	MYSQL mysql;

	mysql_init(&mysql);

	if(!mysql_real_connect(&mysql, "localhost", "gll", "123456", "mydb", 0, NULL, 0))
	{
	
		fprintf(stderr, "Failed to connect to database :Error : %s\n", mysql_error(&mysql));
	
	}


	mysql_query(&mysql, "set names utf8");


	char Update[100];
	unsigned int aid;
	char aname[20];
	char apasswd[50];

	int passwd = 123456;
	int temp;
	printf("请输入终端密码:");
	scanf("%d", &temp);
	if(temp == passwd)
	{
		printf("密码正确!\n");
		printf("请输入要修改的列名和管理员id:\n");

		char str[20];
		
		scanf("%s", str);
		scanf("%d", &aid);
		
		if(strcmp(str, "aid") == 0)
		{
			int n;
			printf("修改为:");			
			scanf("%d", &n);
			sprintf(Update, "update adm set %s = %d where aid = %d", str, n,  aid);
		}

		if(strcmp(str, "aname") == 0 || strcmp(str, "apasswd"))
		{
			char s[10];
			printf("修改为:");
			scanf("%s", s);
			sprintf(Update, "update adm set %s = '%s' where aid = %d", str, s,  aid);

		}
		
		if(	mysql_query(&mysql, Update))
		{
			fprintf(stderr, "Failed to update to database :Error : %s\n", mysql_error(&mysql));

		}
		else
		{
			if(mysql_affected_rows(&mysql) == 1)
			{
				printf("修改管理员%s成功!\n", str);
			}
			else 
			{
				printf("修改管理员%s失败!\n", str);
			}
		}


	}
		mysql_close(&mysql);

}

void delete_admin()
{
	MYSQL mysql;

	mysql_init(&mysql);

	if(!mysql_real_connect(&mysql, "localhost", "gll", "123456", "mydb", 0, NULL, 0))
	{
	
		fprintf(stderr, "Failed to connect to database :Error : %s\n", mysql_error(&mysql));
	
	}


	mysql_query(&mysql, "set names utf8");


	char Delete[100];
	unsigned int aid;
	char aname[20];
	unsigned int apasswd;

	int passwd = 123456;
	int temp;
	printf("请输入终端密码:");
	scanf("%d", &temp);
	if(temp == passwd)
	{
		printf("密码正确!\n");
		printf("请输入要删除管理员id:\n");

		int i;
		scanf("%d", &i);
		
		sprintf(Delete, "delete from adm where aid = %d", i);

		
		if(	mysql_query(&mysql, Delete))
		{
			fprintf(stderr, "Failed to delect to database :Error : %s\n", mysql_error(&mysql));

		}
		else
		{
			if(mysql_affected_rows(&mysql) == 1)
			{
				printf("删除管理员%d成功!\n", i);
			}
			else 
			{
				printf("删除管理员%d失败!\n", i);
			}
		}


	}
	mysql_close(&mysql);

}

int login_admin()
{
	MYSQL mysql;

	mysql_init(&mysql);

	if(!mysql_real_connect(&mysql, "localhost", "gll", "123456", "mydb", 0, NULL, 0))
	{
	
		fprintf(stderr, "Failed to connect to database :Error : %s\n", mysql_error(&mysql));
	
	}


	mysql_query(&mysql, "set names utf8");


	char Select[100];
	unsigned int aid;
	char aname[20];
	char apasswd[50];
	
	unsigned int user;
	char passwd[16];
	char name[20];
	
	printf("请输入管理员编号:"); scanf("%d", &user);
	printf("请输入管理员姓名:"); scanf("%s", name);
	printf("请输入管理员密码:"); scanf("%s", passwd);

	sprintf(Select, "select * from adm where aid = %d", user);

	if(mysql_query(&mysql, Select))
	{
		fprintf(stderr, "Failed to select to database :Error : %s\n", mysql_error(&mysql));

	}
	else
	{
		MYSQL_RES *res;

		res = mysql_store_result(&mysql);

		MYSQL_ROW row;

		while(row = mysql_fetch_row(res))
		{	
			if(strcmp(row[1], name) == 0 && (strcmp(row[2] , passwd)) == 0)
			{
				printf("登陆成功!\n"); 
				return 1;
			}
			else 
			{
				printf("密码错误或用户不存在!\n");
				return -1;
			}
		}	
	}
	mysql_close(&mysql);

}

void insert_book()
{
	MYSQL mysql;

	mysql_init(&mysql);

	if(!mysql_real_connect(&mysql, "localhost", "gll", "123456", "mydb", 0, NULL, 0))
	{
	
		fprintf(stderr, "Failed to connect to database :Error : %s\n", mysql_error(&mysql));
	
	}


	mysql_query(&mysql, "set names utf8");


	char Insert[100];
	unsigned int bid;
	char bname[100];
	unsigned int bprice;
	unsigned int bcost;
	char btime[12];
	char btype[20];


	printf("请输入书编号:"); scanf("%d", &bid);
	printf("请输入书名:"); scanf("%s", bname);
	printf("请输入书售价:"); scanf("%d", &bprice);
	printf("请输入书进价:"); scanf("%d", &bcost);
	printf("请输入书进货时间:"); scanf("%s", btime);
	printf("请输入书类别:"); scanf("%s", btype);


		sprintf(Insert, "insert into book values (%d, '%s', %d, %d, '%s', '%s')", bid, bname, bprice, bcost, btime, btype);

		if(	mysql_query(&mysql, Insert))
		{
			fprintf(stderr, "Failed to insert to database :Error : %s\n", mysql_error(&mysql));

		}
		else
		{
			if(mysql_affected_rows(&mysql) == 1)
			{
				printf("添加书籍信息成功!\n");
			}
			else 
			{
				printf("添加书籍信息失败!\n");
			}
		}

	

	mysql_close(&mysql);

}

void update_book()
{
	MYSQL mysql;

	mysql_init(&mysql);

	if(!mysql_real_connect(&mysql, "localhost", "gll", "123456", "mydb", 0, NULL, 0))
	{
	
		fprintf(stderr, "Failed to connect to database :Error : %s\n", mysql_error(&mysql));	
	
	}


	mysql_query(&mysql, "set names utf8");


	char Update[100];
	unsigned int bid;
	char bname[100];
	unsigned int bprice;
	unsigned int bcost;
	char btime[12];
	char btype[20];
	
	printf("请输入要修改的列名和书籍编号:\n");

		char str[20];
		
		scanf("%s", str);
		scanf("%d", &bid);
		
		if(strcmp(str, "bid") == 0 || strcmp(str, "bprice") == 0 || strcmp(str, "bcost") == 0)
		{
			int n;
			printf("修改为:");
			scanf("%d", &n);
			sprintf(Update, "update book set %s = %d where bid = %d", str, n,  bid);
		}

		if(strcmp(str, "bid") == 0 || strcmp(str, "bname") == 0 || strcmp(str, "btime") == 0 || strcmp(str, "btype") == 0)
		{
			char s[10];
			printf("修改为:");
			scanf("%s", s);
			sprintf(Update, "update book set %s = '%s' where bid = %d", str, s,  bid);

		}
		
		if(	mysql_query(&mysql, Update))
		{
			fprintf(stderr, "Failed to update to database :Error : %s\n", mysql_error(&mysql));

		}
		else
		{
			if(mysql_affected_rows(&mysql) == 1)
			{
				printf("修改书籍信息%s成功!\n", str);
			}
			else 
			{
				printf("修改书籍信息%s失败!\n", str);
			}
		}

	mysql_close(&mysql);

}

void delete_book()
{
	MYSQL mysql;

	mysql_init(&mysql);

	if(!mysql_real_connect(&mysql, "localhost", "gll", "123456", "mydb", 0, NULL, 0))
	{
	
		fprintf(stderr, "Failed to connect to database :Error : %s\n", mysql_error(&mysql));
	
	}


	mysql_query(&mysql, "set names utf8");


	char Delete[100];
	unsigned int bid;
	char bname[100];
	unsigned int bprice;
	unsigned int bcost;
	char btime[12];
	char btype[20];



		int i;
		printf("要删除的书籍编号:");
		scanf("%d", &i);
		
		sprintf(Delete, "delete from book where bid = %d", i);

		
		if(	mysql_query(&mysql, Delete))
		{
			fprintf(stderr, "Failed to delect to database :Error : %s\n", mysql_error(&mysql));

		}
		else
		{
			if(mysql_affected_rows(&mysql) == 1)
			{
				printf("删除书籍%d成功!\n", i);
			}
			else 
			{
				printf("删除书籍%d失败!\n", i);
			}
		}

	mysql_close(&mysql);

}

void select_book()
{
	MYSQL mysql;

	mysql_init(&mysql);

	if(!mysql_real_connect(&mysql, "localhost", "gll", "123456", "mydb", 0, NULL, 0))
	{
	
		fprintf(stderr, "Failed to connect to database :Error : %s\n", mysql_error(&mysql));
	
	}


	mysql_query(&mysql, "set names utf8");


	char Select[100];
	unsigned int bid;
	char bname[100];
	unsigned int bprice;
	unsigned int bcost;
	char btime[12];
	char btype[20];

	printf("请输入要查询的书籍编号:");

	int id;
	scanf("%d", &id);

	sprintf(Select, "select * from book where bid = %d", id);

	if(mysql_query(&mysql, Select))
	{
		fprintf(stderr, "Failed to select to database :Error : %s\n", mysql_error(&mysql));

	}
	else
	{
		MYSQL_RES *res;

		res = mysql_store_result(&mysql);

		MYSQL_ROW row;

		while(row = mysql_fetch_row(res))
		{
			int i;
			for(i = 0; i < 5; i++)
			  printf("%s ", row[i]);
			printf("\n");
		}	

	}
		mysql_close(&mysql);

}

void insert_user()
{	
	MYSQL mysql;

	mysql_init(&mysql);

	if(!mysql_real_connect(&mysql, "localhost", "gll", "123456", "mydb", 0, NULL, 0))
	{
	
		fprintf(stderr, "Failed to connect to database :Error : %s\n", mysql_error(&mysql));
	
	}


	mysql_query(&mysql, "set names utf8");

	int uid;
	char uname[20];
	char usex[10];
	char utime[40];
	char uphone[12];
	char uddr[50];
	char upasswd[50];
	char Insert[100];


	printf("请输入用户id:"); scanf("%d", &uid);
	printf("请输入用户名:"); scanf("%s", uname);
	printf("请输入用户性别:"); scanf("%s", usex);
//	printf("请输入用户创建进价:"); scanf("%s", utime);
	printf("请输入用户电话:"); scanf("%s", uphone);
	printf("请输入用户地址:"); scanf("%s", uddr);
	printf("请输入用户密码:"); scanf("%s", upasswd);


		sprintf(Insert, "insert into user values (%d, '%s', '%s', '%s', '%s', '%s', curdate())", uid, uname, usex, uphone, uddr, upasswd, utime);

		if(	mysql_query(&mysql, Insert))
		{
			fprintf(stderr, "Failed to insert to database :Error : %s\n", mysql_error(&mysql));

		}
		else
		{
			if(mysql_affected_rows(&mysql) == 1)
			{
				printf("添加用户信息成功!\n");
			}
			else 
			{
				printf("添加用户信息失败!\n");
			}
		}

	mysql_close(&mysql);

}

int login_user()
{
	MYSQL mysql;

	mysql_init(&mysql);

	if(!mysql_real_connect(&mysql, "localhost", "gll", "123456", "mydb", 0, NULL, 0))
	{
	
		fprintf(stderr, "Failed to connect to database :Error : %s\n", mysql_error(&mysql));
	
	}


	mysql_query(&mysql, "set names utf8");


	char Select[100];
	int uid;
	char uname[20];
	char usex[10];
	char utime[40];
	char uphone[12];
	char uddr[50];
	char upasswd[50];

	int user;
	char passwd[16];
	
	printf("请输入用户编号:"); scanf("%d", &user);
	printf("请输入用户密码:"); scanf("%s", passwd);

	sprintf(Select, "select * from user where uid = %d", user);

	if(mysql_query(&mysql, Select))
	{
		fprintf(stderr, "Failed to select to database :Error : %s\n", mysql_error(&mysql));

	}
	else
	{
		MYSQL_RES *res;

		res = mysql_store_result(&mysql);

		MYSQL_ROW row;

		while(row = mysql_fetch_row(res))
		{	
			if(strcmp(row[5], passwd) == 0)
			{
				printf("登陆成功!\n"); 
				return 1;
			}
			else 
			{
				printf("密码错误或用户不存在!\n");
				return -1;
			}	

		}	
	}
	mysql_close(&mysql);



}


void select1_book()
{
	MYSQL mysql;

	mysql_init(&mysql);

	if(!mysql_real_connect(&mysql, "localhost", "gll", "123456", "mydb", 0, NULL, 0))
	{
	
		fprintf(stderr, "Failed to connect to database :Error : %s\n", mysql_error(&mysql));
	
	}


	mysql_query(&mysql, "set names utf8");



	char Select[100];
	unsigned int bid;
	char bname[100];
	unsigned int bprice;
	unsigned int bcost;
	char btime[12];
	char btype[20];

	char name[30];
	printf("输入需要查询书籍的名字:");
	scanf("%s", name);

		sprintf(Select, "select * from book where bname = '%s'", name);

	if(mysql_query(&mysql, Select))
	{
		fprintf(stderr, "Failed to select to database :Error : %s\n", mysql_error(&mysql));

	}
	else
	{
		MYSQL_RES *res;

		res = mysql_store_result(&mysql);

		MYSQL_ROW row;

		while(row = mysql_fetch_row(res))
		{
			printf(" 书籍编号:%s\n 书籍名称:%s\n 价格:%s\n 所属类别%s\n", row[0], row[1], row[2], row[5]);
		}	
		mysql_free_result(res);
	}
	mysql_close(&mysql);

}

void delete_user()
{
	MYSQL mysql;

	mysql_init(&mysql);

	if(!mysql_real_connect(&mysql, "localhost", "gll", "123456", "mydb", 0, NULL, 0))
	{
	
		fprintf(stderr, "Failed to connect to database :Error : %s\n", mysql_error(&mysql));
	
	}


	mysql_query(&mysql, "set names utf8");

	char Select[100];
	char Delete[100];
	int uid;
	char uname[20];
	char usex[10];
	char utime[40];
	char uphone[12];
	char uddr[50];

	int user;
	char passwd[16];

		int i;
	

		sprintf(Select, "select * from user");

	if(mysql_query(&mysql, Select))
	{
		fprintf(stderr, "Failed to select to database :Error : %s\n", mysql_error(&mysql));

	}
	else
	{
		MYSQL_RES *res;

		res = mysql_store_result(&mysql);

		MYSQL_ROW row;

		while(row = mysql_fetch_row(res))
		{
			i = atoi(row[0]);
		}	
		mysql_free_result(res);
	}


		sprintf(Delete, "delete from user where uid = %d", i);

		
		if(	mysql_query(&mysql, Delete))
		{
			fprintf(stderr, "Failed to delect to database :Error : %s\n", mysql_error(&mysql));

		}
		else
		{
			if(mysql_affected_rows(&mysql) == 1)
			{
				printf("删除用户%d成功!\n", i);
			}
			else 
			{
				printf("删除用户%d失败!\n", i);
			}
		}

	mysql_close(&mysql);


}

void select2_book()
{
		MYSQL mysql;

	mysql_init(&mysql);

	if(!mysql_real_connect(&mysql, "localhost", "gll", "123456", "mydb", 0, NULL, 0))
	{
	
		fprintf(stderr, "Failed to connect to database :Error : %s\n", mysql_error(&mysql));
	
	}


	mysql_query(&mysql, "set names utf8");



	char Select[100];
	unsigned int bid;
	char bname[100];
	unsigned int bprice;
	unsigned int bcost;
	char btime[12];
	char btype[20];

	

		sprintf(Select, "select * from book ");

	if(mysql_query(&mysql, Select))
	{
		fprintf(stderr, "Failed to select to database :Error : %s\n", mysql_error(&mysql));

	}
	else
	{
		MYSQL_RES *res;

		res = mysql_store_result(&mysql);

		MYSQL_ROW row;

		while(row = mysql_fetch_row(res))
		{
			printf(" 书籍编号:%s\n 书籍名称:%s\n 价格:%s\n 所属类别%s\n\n", row[0], row[1], row[2], row[5]);
		}	
		mysql_free_result(res);
	}
	mysql_close(&mysql);


}
