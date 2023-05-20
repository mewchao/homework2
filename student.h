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

//程序内当前 学生的个数
extern int cnt;

class student {
private:
    //学号
    string id;
    //姓名
    string name;
    //性别
    string gender;
    //身份证号
    string id_number;
    //辅导员
    string counselor;
    //出生日期
    string date_of_birth;
    //国家
    string nation;
    //民族
    string ethnic;
    //政治面貌
    string political;
    //学院
    string college;
    //婚宴
    string marriage;
    //学生类别
    string student_type;
    //培养层次
    string education;
    //专业
    string major;
    //入学方式
    string admisson;
    //班级号
    string class_number;
    //学制
    string study_time;
    //入学年月
    string date_of_admission;
    //家庭地址
    string address_home;
    //生源地
    string address_study;
    //家庭人联系信息
    string family_phone_number;
public:
    //获取姓名
    bool get_name();

    //获取学号
    bool get_id(student students[]);

    //获取性别
    bool get_gender();

    //获取身份证号
    bool get_id_number();

    //获取出生日期
    bool get_date_of_birth();

    //获取国家
    bool get_nation();

    //获取民族
    bool get_ethnic();

    //获取政治面貌
    bool get_political_status();

    //获取婚宴状况
    bool get_marriage();

    //获取学院名称
    bool get_college();

    //获取辅导员
    bool get_counselor();

    //获取学生类别
    bool get_student_type();

    //获取教育水平
    bool get_education();

    //获取专业
    bool get_major();

    //获取入学方式
    bool get_admission();

    //获取班级号
    bool get_class_number();

    //获取学制
    bool get_study_time();

    //获取入学日期
    bool get_date_of_admisson();

    //获取家庭住址
    bool get_address_home();

    //获取生源地
    bool get_address_study();

    //获取家人信息以及联系方式
    bool get_family_phone_number();

    //显示所有信息
    void show_info();

    //------------------数据文件函数-------------------

    //把数据文件的数据读入对象数组中
    friend void read_file(student students[]);
    //把单条数据追加到文件-用于增加数据
    friend void add_data_to_file(student stu);
    //把整个对象数组的数据保存到文件里
    friend void add_datas_to_file(student stu[]);

    //------------------查询函数-------------------
    //根据id查询
    friend void find_by_id(student students[]);
    //根据姓名查询
    friend void find_by_name(student students[]);
    //根据性别查询
    friend void find_by_gender(student students[]);
    //根据学院查询
    friend void find_by_college(student students[]);
    //根据专业查询
    friend void find_by_major(student students[]);
    //根据政治面貌查询
    friend void find_by_political(student students[]);
    //根据辅导员查询
    friend void find_by_counselor(student students[]);
    //根据身份证号查询
    friend void find_by_id_number(student students[]);
    //根据婚姻状况查询
    friend void find_by_marriage(student students[]);

//--------------------------组合信息查询---------------------------------
    //根据专业和性别查询
    friend void find_by_major_gender(student students[]);
    //根据学院和政治面貌查询
    friend void find_by_college_political(student students[]);
    //根据学院和性别查询
    friend void find_by_college_gender(student students[]);
    //根据学院和入学情况查询
    friend void find_by_college_admisson(student students[]);
    //根据学院和国家查询
    friend void find_by_college_nation(student students[]);
    //根据学院和教育水平查询
    friend void find_by_college_education(student students[]);


    //=========================删除函数=======================================
    //删除单个学生
    friend void delete_student(student students[]);
    //删除多个学生
    friend void delete_students(student students[]);
    //=========================修改函数=======================================
    //修改信息
    friend void get_change_information(student students[]);

    //=========================排序函数=======================================
    //年龄从小到大排序
    friend void sort_small(student students[]);

    friend void sort_big(student students[]);
    //学号排序
    friend void sort_big_id(student students[]);

    friend void sort_small_id(student students[]);

    //============================统计函数=====================================

    friend void statistics_grade_college_political(student students[]);

    friend void statistics_grade_college_gender(student students[]);

    friend void statistics_grade_college_education(student students[]);
};
//交换学生的基本信息
void swap_student(student &student1, student &student2);
//检查身份证号中的性别
bool check_gender_of_idnumber(string id_number);
//检查身份证号的长度
bool check_len_of_idnumber(string id_number);
//检查身份证号中的地区码
bool check_region_of_idnumber(string id_number);
//检查身份证号17位前是否是数字
bool check_digit_of_idnumber(string id_number);
//检查身份证号最后一位的校验码
bool check_checkcode_of_idnumber(string id_number);

string get_birth_of_id_number(string id_number);

//从学号获取年级  2223->2023
string get_date_of_id(string id);

//比较日期大小 如果str1比str2更早，则返回true
bool is_early(string str1, string str2);

void get_str_by_date(string str, int &year, int &month, int &day);

//--------------------------------------------------
//判断年月日是否为合法日期
bool is_valid_date(int year, int month, int day);
//判断是否是闰年
bool is_leaf(int year);

void get_date_of_int(string date, int &year, int &month, int &day);
//检查是否被在限制入学年龄
bool check_limit_date_of_birth(int year);
//检查入学年月是否限制
bool check_limit_date_of_admission(int year, int month, int day);
//检查学号前两位学院代码
bool check_college_id(string id);
//检查学号前三四位年级
bool check_grade_id(string id);
//检查学号
bool check_id(string id,student students[]);
//检查学号的长度
bool check_len_id(string id);
//检查学号中的班级号
bool check_class_id(string id);
//检查学号是否都是数字
bool check_id_digit(string id);
//检查学号后两位
bool check_back_id(string id);
//检查学号是否在数据文件中重复
bool check_id_repeat(string id,student students[]);
//检查身份证号是否合法
bool check_id_number(string id_number);
//检查入学日期是否合法
bool check_date_of_admission(string date_of_birth);
//检查日期的格式
bool check_format_date(string date_of_birth);
//检查出生日期是否合法
bool check_date_of_birth(string date_of_birth);
//检查输入的性别是否合法
bool check_gender(string gender);
//检查一个字符串内是否含数字
bool has_digit(const string &str);

//增加一个学生
void add_student(student students[]);
//检查姓名是否合法,特别是对中国人姓名的检查
bool check_name(string name,string nation);
//检查一个字符串内是否含有中文
bool hasChinese(const string &str);
//检查一个字符串内是否含有非中文
bool hasNonChinese(const string &str);


//====================================================
//显示政治面貌的菜单
void show_political();
//显示时间显示版权的菜单
void show_time();
//显示时间显示版权的菜单
void show_copyright();
//显示学生类别
void show_studenttype();
//显示民族表
void show_ethnic();
//显示国家表
void show_nation();
//显示学院表
void show_college();
//显示婚姻状况表
void show_marriage();
//显示总菜单
void show_demo();
//示查找的菜单
void show_find_demo();
//显示组合查找的菜单
void show_find_demos();
//删除信息查询菜单
void show_delete_demos();
//显示排序的菜单
void show_sort_demo();
//选项出现错误时,显示错误
void show_switch_error();
//显示修改信息的菜单
void show_change_demos();
//显示统计信息的菜单
void show_statistics_demos();
//显示要更改信息的菜单
void show_change_information_demos();
//根据学院代码显示对应的辅导员
void show_counselor(string code);
//显示教育水平
void show_education();
//显示入学方式的菜单
void show_admisson();
//显示中国省份
void show_china_address();
//根据相应的文件名调用打开对应的文件,并且打印
void file_major(string file_name);
//从总辅导员中选择出对应学院的几个辅导员
string get_counselor_file(string code_college, string code);
#endif