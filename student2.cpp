#include "student.h"
 int cnt=0;
int main() {
    bool flag0=true;
    student students[1024];
    while (flag0) {
        char choice;
        show_demo();
        choice=getch();
        if (islower(choice)) {
            choice=toupper(choice);
        }
        cout<<choice<<endl;
        switch (choice) {
            case 'A':
                //创建一个学生并且录入文件;
            {
                add_student(students);
                break;
            }
            case 'B':
                //查询信息二级菜单
            {
                bool flag1=true;
                while (flag1) {
                    system("cls");
                    show_find_demo();
                    char choice_find;
                    choice_find=getch();
                    if (islower(choice_find)) {
                        choice_find=toupper(choice_find);
                    }
                    cout<<choice_find<<endl;
                    switch (choice_find) {
                        case 'A':
                            read_file(students);
                            //根据学号查询
                            find_by_id(students);
                            break;
                        case 'B':
                            read_file(students);
                            find_by_name(students);
                            break;
                        case 'C':
                            read_file(students);
                            find_by_gender(students);
                            break;
                        case 'D':
                            read_file(students);
                            find_by_college(students);
                            break;
                        case 'E':
                            read_file(students);
                            find_by_major(students);
                            break;
                        case 'F':
                            read_file(students);
                            find_by_id_number(students);
                            break;
                        case 'G':
                            read_file(students);
                            find_by_marriage(students);
                            break;
                        case 'H':
                            read_file(students);
                            find_by_political(students);
                            break;
                        case 'I':
                            read_file(students);
                            find_by_counselor(students);
                            break;
                        case 'J':
                            //组合信息查询三级菜单b
                        {
                            system("cls");
                            show_find_demos();
                            char choice_finds;
                            choice_finds=getch();
                            if (islower(choice_finds)) {
                                choice_finds=toupper(choice_finds);
                            }
                            cout<<choice_finds<<endl;
                            switch (choice_finds) {
                                case 'A':
                                    read_file(students);
                                    find_by_major_gender(students);
                                    system("pause");
                                    break;
                                case 'B':
                                    read_file(students);
                                    find_by_college_political(students);
                                    system("pause");
                                    break;
                                case 'C':
                                    read_file(students);
                                    find_by_college_gender(students);
                                    system("pause");
                                    break;
                                case 'D':
                                    read_file(students);
                                    find_by_college_admisson(students);
                                    system("pause");
                                    break;
                                case 'E':
                                    read_file(students);
                                    find_by_college_nation(students);
                                    system("pause");
                                    break;
                                case 'F':
                                    read_file(students);
                                    find_by_college_education(students);
                                    system("pause");
                                    break;
                                case 'Q':
                                    system("cls");
                                    break;
                            }
                        }
                            break;
                        case 'Q':
                            //返回上一级菜单
                            flag1=false;
                            system("cls");
                            break;
                    }
                }
            }
                 break;
            case 'C':
                //删除信息
            {
                system("cls");
                bool flag2=true;
                while (flag2) {
                    show_delete_demos();
                    char choice_delete;
                    choice_delete=getch();
                    if (islower(choice_delete)) {
                        choice_delete=toupper(choice_delete);
                    }
                    cout<<choice_delete<<endl;
                    switch (choice_delete) {
                        case'A':
                            read_file(students);
                            delete_student(students);
                            system("pause");
                            break;
                        case'B':
                            read_file(students);
                            delete_students(students);
                            system("pause");
                            break;
                        case'Q':
                            flag2=false;
                            break;
                        default:
                            show_switch_error();
                            system("pause");
                            break;
                    }
                    }
                }
            case 'D':
                //修改信息
            {
                system("cls");
                show_change_demos();
                read_file(students);
                get_change_information(students);
            }
                break;
            case 'E':
                //统计
            {
                system("cls");
                bool flag3=true;
                while (flag3) {
                    show_statistics_demos();
                    char choice_sort;
                    choice_sort=getch();
                    if (islower(choice_sort)) {
                        choice_sort=toupper(choice_sort);
                    }
                    cout<<choice_sort<<endl;
                    switch (choice_sort) {
                        case 'A':
                            read_file(students);
                            //统计年级和学院和政治面貌
                            statistics_grade_college_political( students);
                            system("pause");
                            break;
                        case 'B':
                            read_file(students);
                            //统计年级和专业和性别
                            statistics_grade_college_gender( students);
                            system("pause");
                            break;
                        case 'C':
                            read_file(students);
                            //统计年级和专业和教育水平
                            statistics_grade_college_education( students);
                            system("pause");
                            break;
                        case 'Q':
                            flag3=false;
                            system("cls");
                            break;
                    }
                    system("cls");
                }
            }
                break;
            case 'F':
                //排序
            {
                bool flag3=true;
                while (flag3) {
                    system("cls");
                    show_sort_demo();
                    char choice_sort;
                    choice_sort=getch();
                    if (islower(choice_sort)) {
                        choice_sort=toupper(choice_sort);
                    }
                    cout<<choice_sort<<endl;
                    switch (choice_sort) {
                        case 'A':
                            read_file(students);
                            //按照年龄从小到大排序
                            sort_small(students);
                            system("pause");
                            break;
                        case 'B':
                            read_file(students);
                            sort_big(students);
                            system("pause");
                            //按照年龄从大到小排序
                            break;
                        case 'C':
                            read_file(students);
                            sort_small_id(students);
                            system("pause");
                            //按照学号从大到小排序
                            break;
                        case 'D':
                            read_file(students);
                            sort_big_id(students);
                            system("pause");
                            //按照学号从大到小排序
                            break;
                        case 'Q':
                            flag3=false;
                            system("cls");
                            break;
                    }
                }
            }
                break;
            case 'Q':
                flag0=false;
                break;
            default:
                show_switch_error();
                system("pause");
                system("cls");
                break;
    }
}
    system("pause");
}

