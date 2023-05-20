#ifndef STUDENT_H
#define STUDENT_H


#ifndef IOMANIP_
#define IOMANIP_

#include<iomanip>

#endif

#include <sstream>

#ifndef VERCTOR_
#define VERCTOR_

#include<vector>

#endif

#ifndef CONIO_H
#define CONIO_H

#include<conio.h>

#endif

#ifndef CTYPE_H
#define CTYPE_H

#include<ctype.h>

#endif

#ifndef WINDOWS_H
#define WINDOWS_H
#define DIVID "-----------------------------------------------------------------------------------------------------\n"

#include<windows.h>

#endif

#ifndef IOSTREAM_
#define IOSTREAM_

#include <iostream>

using namespace std;
#endif

#ifndef STDIO_H
#define STDIO_H

#include <stdio.h>

#endif

#ifndef STRING_
#define STRING_

#include <string>

#endif //STRING_

#ifndef STRING_H
#define STRING_H

#include <string.h>

#endif //STRING_H

#ifndef CHRONO_
#define CHRONO_

#include <chrono>

#endif

//�����ڵ�ǰ ѧ���ĸ���
extern int cnt;

class student {
private:
    //ѧ��
    string id;
    //����
    string name;
    //�Ա�
    string gender;
    //���֤��
    string id_number;
    //����Ա
    string counselor;
    //��������
    string date_of_birth;
    //����
    string nation;
    //����
    string ethnic;
    //������ò
    string political;
    //ѧԺ
    string college;
    //����
    string marriage;
    //ѧ�����
    string student_type;
    //�������
    string education;
    //רҵ
    string major;
    //��ѧ��ʽ
    string admisson;
    //�༶��
    string class_number;
    //ѧ��
    string study_time;
    //��ѧ����
    string date_of_admission;
    //��ͥ��ַ
    string address_home;
    //��Դ��
    string address_study;
    //��ͥ����ϵ��Ϣ
    string family_phone_number;
public:
    //��ȡ����
    bool get_name();

    //��ȡѧ��
    bool get_id(student students[]);

    //��ȡ�Ա�
    bool get_gender();

    //��ȡ���֤��
    bool get_id_number();

    //��ȡ��������
    bool get_date_of_birth();

    //��ȡ����
    bool get_nation();

    //��ȡ����
    bool get_ethnic();

    //��ȡ������ò
    bool get_political_status();

    //��ȡ����״��
    bool get_marriage();

    //��ȡѧԺ����
    bool get_college();

    //��ȡ����Ա
    bool get_counselor();

    //��ȡѧ�����
    bool get_student_type();

    //��ȡ����ˮƽ
    bool get_education();

    //��ȡרҵ
    bool get_major();

    //��ȡ��ѧ��ʽ
    bool get_admission();

    //��ȡ�༶��
    bool get_class_number();

    //��ȡѧ��
    bool get_study_time();

    //��ȡ��ѧ����
    bool get_date_of_admisson();

    //��ȡ��ͥסַ
    bool get_address_home();

    //��ȡ��Դ��
    bool get_address_study();

    //��ȡ������Ϣ�Լ���ϵ��ʽ
    bool get_family_phone_number();

    //��ʾ������Ϣ
    void show_info();

    //------------------�����ļ�����-------------------

    //�������ļ������ݶ������������
    friend void read_file(student students[]);
    //�ѵ�������׷�ӵ��ļ�-������������
    friend void add_data_to_file(student stu);
    //������������������ݱ��浽�ļ���
    friend void add_datas_to_file(student stu[]);

    //------------------��ѯ����-------------------
    //����id��ѯ
    friend void find_by_id(student students[]);
    //����������ѯ
    friend void find_by_name(student students[]);
    //�����Ա��ѯ
    friend void find_by_gender(student students[]);
    //����ѧԺ��ѯ
    friend void find_by_college(student students[]);
    //����רҵ��ѯ
    friend void find_by_major(student students[]);
    //����������ò��ѯ
    friend void find_by_political(student students[]);
    //���ݸ���Ա��ѯ
    friend void find_by_counselor(student students[]);
    //�������֤�Ų�ѯ
    friend void find_by_id_number(student students[]);
    //���ݻ���״����ѯ
    friend void find_by_marriage(student students[]);

//--------------------------�����Ϣ��ѯ---------------------------------
    //����רҵ���Ա��ѯ
    friend void find_by_major_gender(student students[]);
    //����ѧԺ��������ò��ѯ
    friend void find_by_college_political(student students[]);
    //����ѧԺ���Ա��ѯ
    friend void find_by_college_gender(student students[]);
    //����ѧԺ����ѧ�����ѯ
    friend void find_by_college_admisson(student students[]);
    //����ѧԺ�͹��Ҳ�ѯ
    friend void find_by_college_nation(student students[]);
    //����ѧԺ�ͽ���ˮƽ��ѯ
    friend void find_by_college_education(student students[]);


    //=========================ɾ������=======================================
    //ɾ������ѧ��
    friend void delete_student(student students[]);
    //ɾ�����ѧ��
    friend void delete_students(student students[]);
    //=========================�޸ĺ���=======================================
    //�޸���Ϣ
    friend void get_change_information(student students[]);

    //=========================������=======================================
    //�����С��������
    friend void sort_small(student students[]);

    friend void sort_big(student students[]);
    //ѧ������
    friend void sort_big_id(student students[]);

    friend void sort_small_id(student students[]);

    //============================ͳ�ƺ���=====================================

    friend void statistics_grade_college_political(student students[]);

    friend void statistics_grade_college_gender(student students[]);

    friend void statistics_grade_college_education(student students[]);
};
//����ѧ���Ļ�����Ϣ
void swap_student(student &student1, student &student2);
//������֤���е��Ա�
bool check_gender_of_idnumber(string id_number);
//������֤�ŵĳ���
bool check_len_of_idnumber(string id_number);
//������֤���еĵ�����
bool check_region_of_idnumber(string id_number);
//������֤��17λǰ�Ƿ�������
bool check_digit_of_idnumber(string id_number);
//������֤�����һλ��У����
bool check_checkcode_of_idnumber(string id_number);

string get_birth_of_id_number(string id_number);

//��ѧ�Ż�ȡ�꼶  2223->2023
string get_date_of_id(string id);

//�Ƚ����ڴ�С ���str1��str2���磬�򷵻�true
bool is_early(string str1, string str2);

void get_str_by_date(string str, int &year, int &month, int &day);

//--------------------------------------------------
//�ж��������Ƿ�Ϊ�Ϸ�����
bool is_valid_date(int year, int month, int day);
//�ж��Ƿ�������
bool is_leaf(int year);

void get_date_of_int(string date, int &year, int &month, int &day);
//����Ƿ���������ѧ����
bool check_limit_date_of_birth(int year);
//�����ѧ�����Ƿ�����
bool check_limit_date_of_admission(int year, int month, int day);
//���ѧ��ǰ��λѧԺ����
bool check_college_id(string id);
//���ѧ��ǰ����λ�꼶
bool check_grade_id(string id);
//���ѧ��
bool check_id(string id,student students[]);
//���ѧ�ŵĳ���
bool check_len_id(string id);
//���ѧ���еİ༶��
bool check_class_id(string id);
//���ѧ���Ƿ�������
bool check_id_digit(string id);
//���ѧ�ź���λ
bool check_back_id(string id);
//���ѧ���Ƿ��������ļ����ظ�
bool check_id_repeat(string id,student students[]);
//������֤���Ƿ�Ϸ�
bool check_id_number(string id_number);
//�����ѧ�����Ƿ�Ϸ�
bool check_date_of_admission(string date_of_birth);
//������ڵĸ�ʽ
bool check_format_date(string date_of_birth);
//�����������Ƿ�Ϸ�
bool check_date_of_birth(string date_of_birth);
//���������Ա��Ƿ�Ϸ�
bool check_gender(string gender);
//���һ���ַ������Ƿ�����
bool has_digit(const string &str);

//����һ��ѧ��
void add_student(student students[]);
//��������Ƿ�Ϸ�,�ر��Ƕ��й��������ļ��
bool check_name(string name,string nation);
//���һ���ַ������Ƿ�������
bool hasChinese(const string &str);
//���һ���ַ������Ƿ��з�����
bool hasNonChinese(const string &str);


//====================================================
//��ʾ������ò�Ĳ˵�
void show_political();
//��ʾʱ����ʾ��Ȩ�Ĳ˵�
void show_time();
//��ʾʱ����ʾ��Ȩ�Ĳ˵�
void show_copyright();
//��ʾѧ�����
void show_studenttype();
//��ʾ�����
void show_ethnic();
//��ʾ���ұ�
void show_nation();
//��ʾѧԺ��
void show_college();
//��ʾ����״����
void show_marriage();
//��ʾ�ܲ˵�
void show_demo();
//ʾ���ҵĲ˵�
void show_find_demo();
//��ʾ��ϲ��ҵĲ˵�
void show_find_demos();
//ɾ����Ϣ��ѯ�˵�
void show_delete_demos();
//��ʾ����Ĳ˵�
void show_sort_demo();
//ѡ����ִ���ʱ,��ʾ����
void show_switch_error();
//��ʾ�޸���Ϣ�Ĳ˵�
void show_change_demos();
//��ʾͳ����Ϣ�Ĳ˵�
void show_statistics_demos();
//��ʾҪ������Ϣ�Ĳ˵�
void show_change_information_demos();
//����ѧԺ������ʾ��Ӧ�ĸ���Ա
void show_counselor(string code);
//��ʾ����ˮƽ
void show_education();
//��ʾ��ѧ��ʽ�Ĳ˵�
void show_admisson();
//��ʾ�й�ʡ��
void show_china_address();
//������Ӧ���ļ������ô򿪶�Ӧ���ļ�,���Ҵ�ӡ
void file_major(string file_name);
//���ܸ���Ա��ѡ�����ӦѧԺ�ļ�������Ա
string get_counselor_file(string code_college, string code);
#endif