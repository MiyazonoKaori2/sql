/*#include<mysql.h>
#include<iostream>
using namespace std;//设置命名空间

const char* host = "127.0.0.1";								//数据库地址
const char* user = "root";										//用户名
const char* pw = "AAaa!123";								//密码
const char* databases_name = "student";			//数据库名
const int port = 3306;											//端口号

//编译一个学生的机构体
typedef struct Student
{
	int studnent_id;
	string student_name;
	string class_id;
}Student;

int main()
{
	MYSQL* con = mysql_init(NULL);
	//设置字符编码
	mysql_options(con, MYSQL_SET_CHARSET_NAME, "GBK");
	//链接数据库  if判断连接是否正常
	if (!mysql_real_connect(con, host, user, pw, databases_name, port, NULL, 0))
	{
		//打印错误原因	使用mysql_error参数
		fprintf(stderr, "failed to connect to database : Error:%s\n", mysql_error(con));
			return -1;
	}


	Student stu{ 1111,"五子棋","软件一班" };

	//设置MySQL语句
	char sql[1024];
	sprintf(sql, "insert ignore into students (student_id, student_name, class_id) values(%d,'%s', '%s')", stu.studnent_id, stu.student_name.c_str(), stu.class_id.c_str());


	//执行sql 语句
	if (mysql_query(con,sql))
	{
		fprintf(stderr, "failed to insert databases : Error:%s\n", mysql_error(con));
		return -1;
	}

	mysql_close(con);

	return 0;
} 
以上是不使用C++类的代码
*/


#include "StudentManager.h"
#include <iostream>


int main()
{
Student stu{ 1001,"张山", "网工二班" };
	
	//StudentManager::GetInstance()->update_student(stu);		//更新

	
	//StudentManager::GetInstance()->insert_student(stu);			//插入


	//StudentManager::GetInstance()->delete_student(1001);     //删除




			/*vector<Student> ret = StudentManager::GetInstance()->get_students();


			for (auto& t : ret)
			{
				cout << t.student_id << ' ' << t.student_name << " " << t.class_id << endl;  
			}  查询*/


	return 0;
}