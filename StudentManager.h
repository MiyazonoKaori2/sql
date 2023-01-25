#pragma once
#include<mysql.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef struct Student
{
	int student_id;
	string student_name;
	string class_id;
}Student;

class StudentManager
{
	StudentManager();							//构造函数
	~StudentManager();
public:
	static StudentManager* GetInstance()
	{
		static StudentManager StudentManager;		//单例模式
		return &StudentManager;
	}

public:
	bool insert_student(Student& t);						//插入
	bool update_student(Student& t);					//更新
	bool delete_student(int student_id);				//删除
	vector<Student> get_students(string	 condition =""	);     //查询

private:
	MYSQL* con;
	const char* host = "127.0.0.1";								//数据库地址
	const char* user = "root";										//用户名
	const char* pw = "AAaa!123";								//密码
	const char* databases_name = "student";			//数据库名
	const int port = 3306;											//端口号
	
};

