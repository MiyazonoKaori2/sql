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
	StudentManager();							//���캯��
	~StudentManager();
public:
	static StudentManager* GetInstance()
	{
		static StudentManager StudentManager;		//����ģʽ
		return &StudentManager;
	}

public:
	bool insert_student(Student& t);						//����
	bool update_student(Student& t);					//����
	bool delete_student(int student_id);				//ɾ��
	vector<Student> get_students(string	 condition =""	);     //��ѯ

private:
	MYSQL* con;
	const char* host = "127.0.0.1";								//���ݿ��ַ
	const char* user = "root";										//�û���
	const char* pw = "AAaa!123";								//����
	const char* databases_name = "student";			//���ݿ���
	const int port = 3306;											//�˿ں�
	
};

