/*#include<mysql.h>
#include<iostream>
using namespace std;//���������ռ�

const char* host = "127.0.0.1";								//���ݿ��ַ
const char* user = "root";										//�û���
const char* pw = "AAaa!123";								//����
const char* databases_name = "student";			//���ݿ���
const int port = 3306;											//�˿ں�

//����һ��ѧ���Ļ�����
typedef struct Student
{
	int studnent_id;
	string student_name;
	string class_id;
}Student;

int main()
{
	MYSQL* con = mysql_init(NULL);
	//�����ַ�����
	mysql_options(con, MYSQL_SET_CHARSET_NAME, "GBK");
	//�������ݿ�  if�ж������Ƿ�����
	if (!mysql_real_connect(con, host, user, pw, databases_name, port, NULL, 0))
	{
		//��ӡ����ԭ��	ʹ��mysql_error����
		fprintf(stderr, "failed to connect to database : Error:%s\n", mysql_error(con));
			return -1;
	}


	Student stu{ 1111,"������","���һ��" };

	//����MySQL���
	char sql[1024];
	sprintf(sql, "insert ignore into students (student_id, student_name, class_id) values(%d,'%s', '%s')", stu.studnent_id, stu.student_name.c_str(), stu.class_id.c_str());


	//ִ��sql ���
	if (mysql_query(con,sql))
	{
		fprintf(stderr, "failed to insert databases : Error:%s\n", mysql_error(con));
		return -1;
	}

	mysql_close(con);

	return 0;
} 
�����ǲ�ʹ��C++��Ĵ���
*/


#include "StudentManager.h"
#include <iostream>


int main()
{
Student stu{ 1001,"��ɽ", "��������" };
	
	//StudentManager::GetInstance()->update_student(stu);		//����

	
	//StudentManager::GetInstance()->insert_student(stu);			//����


	//StudentManager::GetInstance()->delete_student(1001);     //ɾ��




			/*vector<Student> ret = StudentManager::GetInstance()->get_students();


			for (auto& t : ret)
			{
				cout << t.student_id << ' ' << t.student_name << " " << t.class_id << endl;  
			}  ��ѯ*/


	return 0;
}