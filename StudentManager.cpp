#include "StudentManager.h"

StudentManager::StudentManager()
{
	con = mysql_init(NULL);
	//设置字符编码
	mysql_options(con, MYSQL_SET_CHARSET_NAME, "GBK");

	if (!mysql_real_connect(con, host, user, pw, databases_name, port, NULL, 0))
	{
		//打印错误原因	使用mysql_error参数
		printf("ERROR");
		exit(1);
	}
}

StudentManager::~StudentManager()
{
	mysql_close(con);
}

bool StudentManager::insert_student(Student& stu)
{
	char sql[1024];
	sprintf(sql, "insert ignore into students (student_id, student_name, class_id) values(%d,'%s', '%s')", stu.student_id, stu.student_name.c_str(), stu.class_id.c_str());


	//执行sql 语句
	if (mysql_query(con, sql))
	{
		fprintf(stderr, "failed to insert databases : Error:%s\n", mysql_error(con));
		return false;
	}

	return true;
}

bool StudentManager::update_student(Student& stu)
{
	char sql[1024];
	sprintf(sql, "UPDATE  students SET student_name = '%s' , class_id = '%s' " 
		"where student_id = %d", stu.student_name.c_str(), stu.class_id.c_str(), stu.student_id);

	if (mysql_query(con, sql))
	{
		fprintf(stderr, "failed to UPDATE : Error:%s\n", mysql_error(con));
		return false;
	}
	return true;

}

bool StudentManager::delete_student(int student_id)
{
	char sql[1024];
	sprintf(sql, "DELETE FROM  students WHERE student_id =%d", student_id);

	if (mysql_query(con, sql))
	{
		fprintf(stderr, "failed to DELETE : Error:%s\n", mysql_error(con));
		return false;
	}
	return true;

}

vector<Student> StudentManager::get_students(string condition)
{
	vector<Student> stuList;
	char sql[1024];
	sprintf(sql, "SELECT * FROM  students %s ", condition.c_str());

	if (mysql_query(con, sql))
	{
		fprintf(stderr, "failed to SELECT : Error:%s\n", mysql_error(con));
		return { };
	}
	MYSQL_RES* res = mysql_store_result(con);


	MYSQL_ROW row;
	while ((row = mysql_fetch_row(res)))
	{
		Student stu;
		stu.student_id = atoi(row[0]);
		stu.student_name = row[1];
		stu.class_id = row[2];
		
		stuList.push_back(stu);

	}




	return stuList;
}
