#include "student.h"

//-------------------------获取信息---------------------
void student::show_info() {
    cout<<DIVID;
    cout<<"学号:"<<this->id<<endl;
    cout<<"姓名:"<<this->name<<endl;
    cout<<"性别:"<<this->gender<<endl;
    cout<<"民族:"<<this->ethnic<<endl;
    cout<<"身份证号:"<<this->id_number<<endl;
    cout<<"出生日期:"<<this->date_of_birth<<endl;
    cout<<"入学日期:"<<this->date_of_admission<<endl;
    cout<<"学院:"<<this->college<<endl;
    cout<<"专业:"<<this->major<<endl;
    cout<<"班级:"<<this->class_number<<endl;
    cout<<"学制:"<<this->study_time<<endl;
    cout<<"辅导员:"<<this->counselor<<endl;
    cout<<"国家:"<<this->nation<<endl;
    cout<<"家庭地址:"<<this->address_home<<endl;
    cout<<"生源地地址:"<<this->address_study<<endl;
    cout<<"家人以及联系方式:"<<this->family_phone_number<<endl;
    cout<<"政治面貌:"<<this->political<<endl;
    cout<<"婚姻状况:"<<this->marriage<<endl;
    cout<<"学生类别:"<<this->student_type<<endl;
    cout<<"教育水平:"<<this->education<<endl;
    cout<<"入学方式:"<<this->admisson<<endl;
}


bool student::get_date_of_birth() {
    string date_of_birth;
    cout<<"请输入出生日期(形如2004.07.24):";
    cin>>date_of_birth;
    if (check_date_of_birth(date_of_birth)) {
        this->date_of_birth=date_of_birth;
        cout<<"出生日期录入成功"<<endl;
        system("pause");
        return true;
    } else {
        cout<<"出生日期录入失败"<<endl;
        return false;
    }

}

bool student::get_name() {
    string name;
    cout<<"请输入姓名:"<<endl;
    cin>>name;
    if (check_name(name, this->nation)) {
        this->name=name;
        cout<<"姓名录入成功"<<endl;
        system("pause");
        return true;
    } else {
        cout<<endl<<endl;
        cout<<"           ===================================================================="<<endl;
        cout<<"           =================姓名录入失败，请重新录入学生信息！！============="<<endl;
        cout<<"           ===================================================================="<<endl;
        cout<<endl<<endl;
        system("pause");
        return false;
    }
}

//获取学号
bool student::get_id(student students[]) {
    string id;
    cout<<"请输入学号:";
    cin>>id;
    if (check_id(id, students)) {
        this->id=id;
        cout<<"学号录入成功"<<endl;
        system("pause");
        return true;
    } else {
        cout<<endl<<endl;
        cout<<"           ===================================================================="<<endl;
        cout<<"           =================学号录入失败，请重新录入学生信息！！============="<<endl;
        cout<<"           ===================================================================="<<endl;
        cout<<endl<<endl;
        system("pause");
        return false;
    }
}

bool student::get_gender() {
    string gender;
    cout<<"请输入性别(男/m/M 女/f/F):";
    cin>>gender;
    if (check_gender(gender)) {
        if (gender=="f"||gender=="F"||gender=="女")
            this->gender="女";
        if (gender=="m"||gender=="M"||gender=="男")
            this->gender="男";
        return true;
    } else {
        cout<<"请输入正确的性别！！！"<<endl;
        return false;
    }
    system("pause");
}

//获取身份证号
bool student::get_id_number() {
    string id_number;
    cout<<"请输入身份证号:";
    cin>>id_number;
    if (check_id_number(id_number)) {
        if (get_birth_of_id_number(id_number)==this->date_of_birth) {
            if ((check_gender_of_idnumber(id_number)&&this->gender=="男")||
                ((!check_gender_of_idnumber(id_number)&&this->gender=="女"))) {
                this->id_number=id_number;
                cout<<"身份证号录入成功"<<endl;
                return true;
            } else {
                cout<<"输入的身份证号码与输入性别不匹配！！";
                return false;
            }
        } else {
            cout<<"输入的身份证号码与输入的出生日期不匹配！！";
            return false;
        }
    } else {
        cout<<"身份证号录入失败"<<endl;
        return false;
    }
    system("pause");
}

//--------------------------------------file_get---------------------
bool student::get_nation() {
    bool ans=false;
    string code;
    show_nation();
    while (true) {
        char ch=getch();
        cout<<ch;
        if (ch=='\r') { // 如果用户按下了Enter键
            if (code.empty()) {
                code="CN";
            }
            break; // 退出循环
        } else {
            code+=ch; // 将字符追加到code中
        }
    }
    FILE *fp;
    fp=::fopen("../Nation.txt", "r");
    int flag=0;
    if (fp!=nullptr) {
        char line[1024];
        //不断地一行一行读入字符数组
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(0, 4)=="["+code+"]") {
                flag=1;
                //处理掉换行符
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //获取国家的值
                this->nation=string(line).substr(5);
                ans=true;
                cout<<endl;
                cout<<"国家录入成功"<<"你的选择为:"<<this->nation<<endl;
                break;
            }
        }
    }
    if(!flag){
        cout<<"请输入正确的国家代码"<<endl;
    }
    ::fclose(fp);
    system("pause");
    return ans;
}

bool student::get_ethnic() {
    bool ans=false;
    string code;
    show_ethnic();
    cin>>code;
    FILE *fp;
    fp=::fopen("../Ethnic.txt", "r");
    int flag=0;
    if (fp!=nullptr) {
        char line[1024];
        //不断地一行一行读入字符数组
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(0, 4)=="["+code+"]") {
                //处理掉换行符
                flag=1;
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //获取国家的值
                this->ethnic=string(line).substr(5);
                ans=true;
                cout<<"民族录入成功"<<"你的选择为:"<<this->ethnic;
                break;
            }
        }
    }
    if(!flag){
        cout<<"请输入正确的民族代码"<<endl;
    }
    ::fclose(fp);
    system("pause");
    return ans;
}

bool student::get_political_status() {
    bool ans=false;
    string code;
    show_political();
    cin>>code;
    FILE *fp;
    fp=::fopen("../Political.txt", "r");
    int flag=0;
    if (fp!=nullptr) {
        char line[1024];
        //不断地一行一行读入字符数组
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(0, 4)=="["+code+"]") {
                flag=1;
                //处理掉换行符
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //获取国家的值
                this->political=string(line).substr(5);
                ans=true;
                cout<<"政治面貌录入成功"<<"你的选择为:"<<this->political<<endl;
                break;
            }
        }
    }
    if(!flag){
        cout<<"请输入正确的政治面貌代码"<<endl;
    }
    ::fclose(fp);
    system("pause");
    return ans;
}

bool student::get_marriage() {
    bool ans=false;
    string code;
    show_marriage();
    cin>>code;
    FILE *fp;
    fp=::fopen("../Marriage.txt", "r");

    if (fp!=nullptr) {
        char line[1024];
        //不断地一行一行读入字符数组
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(0, 4)=="["+code+"]") {
                //处理掉换行符
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //获取国家的值
                this->marriage=string(line).substr(5);
                ans=true;
                cout<<"婚姻状况录入成功"<<"你的选择为:"<<this->marriage<<endl;
                break;
            }
        }
    }
    ::fclose(fp);
    system("pause");
    return ans;
}

bool student::get_college() {
    bool ans=false;
    string code;
    show_college();
    cin>>code;
    FILE *fp;
    fp=::fopen("../College.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //不断地一行一行读入字符数组
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(0, 4)=="["+code+"]") {
                //处理掉换行符
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //获取学院的值
                this->college=string(line).substr(5);
                ans=true;
                cout<<"学院录入成功,"<<"你的选择为:"<<this->college<<endl;
                break;
            }
        }
    }
    ::fclose(fp);
    system("pause");
    return ans;
}

//从总辅导员中选择出对应学院的几个辅导员
string get_counselor_file(string code_college, string code) {
    FILE *fp;
    fp=fopen("../Counselor.txt", "r");
    if (fp==nullptr) { cout<<"Failed to open file.\n"; }
    char line[1024];
    int cnt=0;
    while (fgets(line, sizeof(line), fp)!=nullptr) {
        if (string(line).substr(1, 2)==code_college&&string(line).substr(5, 2)==code) {
            //找到对应的辅导员了
            ::fclose(fp);
            return string(string(line).substr(8, 6));
        }
    }
}


bool student::get_counselor() {
    if (this->college=="") {
        cout<<"请先输入学院";
        return false;
    }
    if (this->college=="电气工程与自动化学院") {
        show_counselor("01");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("01", code);
        cout<<"你的选择是"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="机械工程及自动化学院") {
        show_counselor("02");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("02", code);
        cout<<"你的选择是"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="数学与统计学院") {
        show_counselor("03");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("03", code);
        cout<<"你的选择是"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="石油化工学院") {
        show_counselor("04");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("04", code);
        cout<<"你的选择是"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="土木工程学院") {
        show_counselor("05");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("05", code);
        cout<<"你的选择是"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="环境与安全工程学院") {
        show_counselor("06");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("06", code);
        cout<<"你的选择是"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="经济与管理学院") {
        show_counselor("07");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("07", code);
        cout<<"你的选择是"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="生物科学与工程学院") {
        show_counselor("08");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("08", code);
        cout<<"你的选择是"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="外国语学院") {
        show_counselor("09");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("09", code);
        cout<<"你的选择是"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="计算机与大数据学院") {
        show_counselor("22");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("22", code);
        cout<<"你的选择是"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="物理与信息工程学院与微电子学院") {
        show_counselor("11");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("11", code);
        cout<<"你的选择是"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="化学学院") {
        show_counselor("13");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("13", code);
        cout<<"你的选择是"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="建筑与城乡规划学院") {
        show_counselor("15");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("15", code);
        cout<<"你的选择是"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="紫金地质与矿业学院") {
        show_counselor("16");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("16", code);
        cout<<"你的选择是"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="材料科学与工程学院") {
        show_counselor("18");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("18", code);
        cout<<"你的选择是"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="计算机与大数据学院") {
        show_counselor("22");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("22", code);
        cout<<"你的选择是"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="海洋学院") {
        show_counselor("01");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("01", code);
        cout<<"你的选择是"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="人文社会科学学院") {
        show_counselor("29");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("29", code);
        cout<<"你的选择是"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="梅努斯国际工程学院") {
        show_counselor("83");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("83", code);
        cout<<"你的选择是"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="先进制造学院") {
        show_counselor("85");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("85", code);
        cout<<"你的选择是"<<this->counselor<<endl;
        return true;
    }
    system("pause");
}

bool student::get_student_type() {
    bool ans=false;
    string code;
    show_studenttype();
    int flag=1;
    cin>>code;
    FILE *fp;
    fp=::fopen("../Studenttype.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //不断地一行一行读入字符数组
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(0, 3)=="["+code+"]") {
                flag=1;
                //处理掉换行符
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //获取国家的值
                this->student_type=string(line).substr(4);
                ans=true;
                cout<<"入学方式录入成功"<<"你的选择为:"<<this->student_type;
                break;
            }
        }
    }
    if(!flag){
        cout<<"请输入正确的学生类别代码"<<endl;
    }
    ::fclose(fp);
    return ans;
}

bool student::get_education() {
    bool ans=false;
    string code;
    show_education();
    cin>>code;
    FILE *fp;
    int flag=0;
    fp=::fopen("../Education.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //不断地一行一行读入字符数组
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==code) {
                flag=1;
                //处理掉换行符
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //获取国家的值
                this->education=string(line).substr(4);
                ans=true;
                cout<<"教育水平录入成功"<<"你的选择为:"<<this->education<<endl;
                break;
            }
        }
    }
    if(!flag){
        cout<<"教育水平录入失败，请输入正确入学方式代码"<<endl;
    }
    ::fclose(fp);
    return ans;
}

//根据相应的文件名调用打开对应的文件,并且打印
void file_major(string file_name) {
    FILE *fp;
    fp=fopen(file_name.c_str(), "r");
    if (fp==nullptr) { cout<<"Failed to open file.\n"; }
    char line[1024];
    while (fgets(line, sizeof(line), fp)!=nullptr) {
        char *pos=strchr(line, '\n');
        if (pos!=nullptr) {
            *pos='\0';
        }//删除换行符
        cout<<line<<endl;
    }
    ::fclose(fp);
    cout<<endl<<"请选择对应的专业代码：";
}

bool student::get_admission() {
    bool ans=false;
    string code;
    show_admisson();
    cin>>code;
    FILE *fp;
    fp=::fopen("../Admission.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //不断地一行一行读入字符数组
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==code) {
                //处理掉换行符
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //获取国家的值
                this->admisson=string(line).substr(5);
                ans=true;
                cout<<"入学方式录入成功"<<"你的选择为:"<<this->admisson<<endl;
                break;
            }
        }
    }
    ::fclose(fp);
    return ans;
}


//班级号
bool student::get_class_number() {
    bool ans=false;
    int flag=0;
    cout<<endl<<"[1]01  "<<"[2]02  "<<"[3]03"<<endl<<"[4]04  "<<"[5]05  "<<"[6]06"<<endl<<"[7]07  "<<"[8]08"<<endl;
    cout<<"请输入你的班级代码：";
    string code;
    cin>>code;
    if (code=="1") {
        flag=1;
        ans=true;
        this->class_number="01";
        cout<<endl<<"输入成功,你的选择是"<<this->class_number<<"班"<<endl;
    } else if (code=="2") {
        flag=1;
        ans=true;
        this->class_number="02";
        cout<<endl<<"输入成功,你的选择是"<<this->class_number<<"班"<<endl;
    } else if (code=="3") {
        flag=1;
        ans=true;
        this->class_number="03";
        cout<<endl<<"输入成功,你的选择是"<<this->class_number<<"班"<<endl;
    } else if (code=="4") {
        flag=1;
        ans=true;
        this->class_number="04";
        cout<<endl<<"输入成功,你的选择是"<<this->class_number<<"班"<<endl;
    } else if (code=="5") {
        flag=1;
        ans=true;
        this->class_number="05";
        cout<<endl<<"输入成功,你的选择是"<<this->class_number<<"班"<<endl;
    } else if (code=="6") {
        flag=1;
        ans=true;
        this->class_number="06";
        cout<<endl<<"输入成功,你的选择是"<<this->class_number<<"班"<<endl;
    } else if (code=="7") {
        flag=1;
        ans=true;
        this->class_number="07";
        cout<<endl<<"输入成功,你的选择是"<<this->class_number<<"班"<<endl;
    } else if (code=="8") {
        flag=1;
        ans=true;
        this->class_number="08";
        cout<<endl<<"输入成功,你的选择是"<<this->class_number<<"班"<<endl;
    }
    if(!flag){
        cout<<"请输入正确的班级号对应的代码"<<endl;
    }
    return ans;
}

//学制
bool student::get_study_time() {
    bool ans=false;
    string code;
    cout<<endl<<"[01]四年"<<endl<<"[02]五年制"<<endl;
    cout<<"请输入你的学制代码(按下回车默认值为四年)：";
    bool flag=0;
    while (true) {
        char ch=getch();
        cout<<ch;
        if (ch=='\r') { // 如果用户按下了Enter键
            if (code.empty()) {
                code="01";
                flag=1;
            }
            break; // 退出循环
        } else {
            code+=ch; // 将字符追加到code中
        }
    }
    if (code=="01") {
        flag=1;
        ans=true;
        this->study_time="四年";
        flag=1;
    } else if (code=="02") {
        ans=true;
        this->study_time="五年";
    }
    if(!flag){
        cout<<endl<<"输入失败，请选择正确的学制代码"<<endl;
    }
    cout<<endl<<"输入成功，你的选择是"<<this->study_time<<endl;
    return ans;
}


//入学日期
bool student::get_date_of_admisson() {
    string date_of_admission;
    cout<<"请输入入学日期(形如2023.09.24):";
    cin>>date_of_admission;
    //检查日期是否合法和入学月份是否是8-10，如果错误给出提示
    if (check_date_of_admission(date_of_admission)) {
        //日期初步判断合法，再  检验学号和入学日期是否符合，如果不符合，给出提醒
        if (get_date_of_id(this->id)!=date_of_admission.substr(0, 4)) {
            cout<<endl<<endl;
            cout<<"           ===================================================================="<<endl;
            cout<<"           =================警告！！输入的入学日期和学号不符合============="<<endl;
            cout<<"           ===================================================================="<<endl;
            cout<<endl<<endl;
        }
        this->date_of_admission=date_of_admission;
        cout<<"入学日期录入成功!!"<<endl;
        return true;
    } else {
        cout<<"入学日期不合法,请重试！！"<<endl;
        cout<<endl<<endl;
        cout<<"           ===================================================================="<<endl;
        cout<<"           =================入学日期录入失败，请重新录入学生信息！！============="<<endl;
        cout<<"           ===================================================================="<<endl;
        cout<<endl<<endl;
        return true;
    }
}


//家庭地址
bool student::get_address_home() {
    bool ans=false;
    string code, detail;
    show_china_address();
    cout<<endl<<"请选择家庭地址对应的行政区代码：";
    cin>>code;
    cout<<"输入详细地址:";
    cin>>detail;
    FILE *fp;
    fp=::fopen("../China_address.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //不断地一行一行读入字符数组
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==code) {
                //处理掉换行符
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                this->address_home=string(line).substr(4)+detail;
                ans=true;
                cout<<"家庭地址录入成功"<<"你的选择为:"<<this->address_home<<endl;
                break;
            }
        }
    }
    ::fclose(fp);
    return ans;
}


//生源地
bool student::get_address_study() {
    bool ans=false;
    string code, detail;
    show_china_address();
    cout<<endl<<"请选择生源地对应的行政区代码：";
    cin>>code;
    cout<<"输入详细地址:";
    cin>>detail;
    FILE *fp;
    fp=::fopen("../China_address.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //不断地一行一行读入字符数组
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==code) {
                //处理掉换行符
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                this->address_study=string(line).substr(4)+detail;
                ans=true;
                cout<<"生源地录入成功"<<"你的选择为:"<<this->address_study<<endl;
                break;
            }
        }
    }
    ::fclose(fp);
    return ans;
}


//家庭联系人信息
bool student::get_family_phone_number() {
    string family;
    string phone_number;
    cout<<"请输入一个家人姓名:";
    cin>>family;
    cout<<"请此家人的电话号码:";
    cin>>phone_number;
    string family_phone_number=family+"_"+phone_number;
    this->family_phone_number=family_phone_number;
    return true;
}


bool student::get_major() {
    //根据不同的学院显示不同的专业
    if (this->college=="电气工程与自动化学院") {
        file_major("../dianqi.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../dianqi.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //不断地一行一行读入字符数组
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //处理掉换行符
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //获取国家的值
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"专业录入成功"<<"你的选择为:"<<this->major<<endl;
                        break;
                    }
                } else {
                    cout<<"file false";
                    break;
                }
            }
        }
        ::fclose(fp);
        return ans;
    }
    if (this->college=="机械工程及自动化学院") {
        file_major("../jixie.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../jixie.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //不断地一行一行读入字符数组
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //处理掉换行符
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //获取国家的值
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"专业录入成功"<<"你的选择为:"<<this->major<<endl;
                        break;
                    }
                } else {
                    cout<<"file false";
                    break;
                }
            }
        }
        ::fclose(fp);
        return ans;
    }
    if (this->college=="数学与统计学院") {
        file_major("../shuxeu.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../shuxue.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //不断地一行一行读入字符数组
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //处理掉换行符
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //获取国家的值
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"专业录入成功"<<"你的选择为:"<<this->major<<endl;
                        break;
                    }
                } else {
                    cout<<"file false";
                    break;
                }
            }
        }
        ::fclose(fp);
        return ans;
    }
    if (this->college=="石油化工学院") {
        file_major("../shiyou.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../shiyou.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //不断地一行一行读入字符数组
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //处理掉换行符
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //获取国家的值
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"专业录入成功"<<"你的选择为:"<<this->major<<endl;
                        break;
                    }
                } else {
                    cout<<"file false";
                    break;
                }
            }
        }
        ::fclose(fp);
        return ans;
    }
    if (this->college=="土木工程学院") {
        file_major("../tumu.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../tumu.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //不断地一行一行读入字符数组
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //处理掉换行符
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //获取国家的值
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"专业录入成功"<<"你的选择为:"<<this->major<<endl;
                        break;
                    }
                } else {
                    cout<<"file false";
                    break;
                }
            }
        }
        ::fclose(fp);
        return ans;

    }
    if (this->college=="环境与安全工程学院") {
        file_major("../huanan.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../huanan.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //不断地一行一行读入字符数组
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //处理掉换行符
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //获取国家的值
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"专业录入成功"<<"你的选择为:"<<this->major<<endl;
                        break;
                    }
                } else {
                    cout<<"file false";
                    break;
                }
            }
        }
        ::fclose(fp);
        return ans;
    }
    if (this->college=="经济与管理学院") {
        file_major("../jingguan.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../jingguan.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //不断地一行一行读入字符数组
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //处理掉换行符
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //获取国家的值
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"专业录入成功"<<"你的选择为:"<<this->major<<endl;
                        break;
                    }
                } else {
                    cout<<"file false";
                    break;
                }
            }
        }
        ::fclose(fp);
        return ans;
    }
    if (this->college=="生物科学与工程学院") {
        file_major("../shengwu.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../shengwu.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //不断地一行一行读入字符数组
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //处理掉换行符
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //获取国家的值
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"专业录入成功"<<"你的选择为:"<<this->major<<endl;
                        break;
                    }
                } else {
                    cout<<"file false";
                    break;
                }
            }
        }
        ::fclose(fp);
        return ans;

    }
    if (this->college=="外国语学院") {
        file_major("../waiyu.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../waiyu.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //不断地一行一行读入字符数组
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //处理掉换行符
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //获取国家的值
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"专业录入成功"<<"你的选择为:"<<this->major<<endl;
                        break;
                    }
                } else {
                    cout<<"file false";
                    break;
                }
            }
        }
        ::fclose(fp);
        return ans;

    }
    if (this->college=="计算机与大数据学院") {
        file_major("../jisuanji.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../jisuanji.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //不断地一行一行读入字符数组
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //处理掉换行符
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //获取国家的值
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"专业录入成功"<<"你的选择为:"<<this->major<<endl;
                        break;
                    }
                } else {
                    cout<<"file false";
                    break;
                }
            }
        }
        ::fclose(fp);
        return ans;

    }
    if (this->college=="物理与信息工程学院与微电子学院") {
        file_major("../wuxin.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../wuxin.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //不断地一行一行读入字符数组
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //处理掉换行符
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //获取国家的值
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"专业录入成功"<<"你的选择为:"<<this->major<<endl;
                        break;
                    }
                } else {
                    cout<<"file false";
                    break;
                }
            }
        }
        ::fclose(fp);
        return ans;

    }
    if (this->college=="化学学院") {
        file_major("../huaxue.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../huaxue.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //不断地一行一行读入字符数组
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //处理掉换行符
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //获取国家的值
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"专业录入成功"<<"你的选择为:"<<this->major<<endl;
                        break;
                    }
                } else {
                    cout<<"file false";
                    break;
                }
            }
        }
        ::fclose(fp);
        return ans;

    }
    if (this->college=="建筑与城乡规划学院") {
        file_major("../jianzhu.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../jianzhu.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //不断地一行一行读入字符数组
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //处理掉换行符
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //获取国家的值
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"专业录入成功"<<"你的选择为:"<<this->major<<endl;
                        break;
                    }
                } else {
                    cout<<"file false";
                    break;
                }
            }
        }
        ::fclose(fp);
        return ans;

    }
    if (this->college=="紫金地质与矿业学院") {
        file_major("../zijin.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../zijin.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //不断地一行一行读入字符数组
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //处理掉换行符
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //获取国家的值
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"专业录入成功"<<"你的选择为:"<<this->major<<endl;
                        break;
                    }
                } else {
                    cout<<"file false";
                    break;
                }
            }
        }
        ::fclose(fp);
        return ans;

    }
    if (this->college=="材料科学与工程学院") {
        file_major("../cailiao.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../cailiao.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //不断地一行一行读入字符数组
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //处理掉换行符
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //获取国家的值
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"专业录入成功"<<"你的选择为:"<<this->major<<endl;
                        break;
                    }
                } else {
                    cout<<"file false";
                    break;
                }
            }
        }
        ::fclose(fp);
        return ans;

    }
    if (this->college=="法学院") {
        file_major("../faxue.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../faxue.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //不断地一行一行读入字符数组
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //处理掉换行符
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //获取国家的值
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"专业录入成功"<<"你的选择为:"<<this->major<<endl;
                        break;
                    }
                } else {
                    cout<<"file false";
                    break;
                }
            }
        }
        ::fclose(fp);
        return ans;

    }
    if (this->college=="计算机与大数据学院") {
        file_major("../jisuanji.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../jisuanji.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //不断地一行一行读入字符数组
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //处理掉换行符
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //获取国家的值
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"专业录入成功"<<"你的选择为:"<<this->major<<endl;
                        break;
                    }
                } else {
                    cout<<"file false";
                    break;
                }
            }
        }
        ::fclose(fp);
        return ans;

    }
    if (this->college=="海洋学院") {
//meww
    }
    if (this->college=="人文社会科学学院") {

        file_major("../renwen.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../renwen.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //不断地一行一行读入字符数组
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //处理掉换行符
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //获取国家的值
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"专业录入成功"<<"你的选择为:"<<this->major<<endl;
                        break;
                    }
                } else {
                    cout<<"file false";
                    break;
                }
            }
        }
        ::fclose(fp);
        return ans;
    }
    if (this->college=="梅努斯国际工程学院") {

    }
    if (this->college=="先进制造学院") {

    }
}

//-------------------------获取信息结束---------------------
//------------------------显示版权时间----------------------
//显示时间显示版权的菜单
void show_copyright() {
    cout<<endl<<"    ---Copyright---(c++) 2023-2023 游竣超(222200231). All Rights Reserved.---    ";
    cout<<endl<<endl<<"                    福州大学(高校)学生信息管理系统    ";
    cout<<endl;
    show_time();
    cout<<endl;
}

void show_time() {
    string week[7]={"星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六"};
    SYSTEMTIME now2;
    GetLocalTime(&now2);
    time_t now=time(0);
    tm *ltm=localtime(&now);
    cout<<endl<<"        当前日期、时间 :"<<ltm->tm_year+1900<<"."<<1+ltm->tm_mon<<"."<<ltm->tm_mday<<" "<<ltm->tm_hour
        <<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<"("<<week[now2.wDayOfWeek]<<") "<<endl;
}
//----------------------显示版权时间结束--------------------------


//----------------------显示菜单--------------
//显示总菜单
void show_demo() {
    show_copyright();
    cout<<"      *                    A:录入学生信息                    *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    B:查询学生信息                    *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    C:删除学生信息                    *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    D:修改学生信息                    *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    E:统计学生信息                    *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    F:排序学生信息                    *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    Q:退出系统                        *"<<endl;
    cout<<"请输入选项：";
}

//显示排序的菜单
void show_sort_demo() {
    show_copyright();
    cout<<"            *             A:按照年龄大小 从小到大排序              *"<<endl;
    cout<<"            *                                                      *"<<endl;
    cout<<"            *             B:按照年龄大小 从大到小排序              *"<<endl;
    cout<<"            *                                                      *"<<endl;
    cout<<"            *             C:按照学号大小 从小到大排序              *"<<endl;
    cout<<"            *                                                      *"<<endl;
    cout<<"            *             D:按照学号大小 从大到小排序              *"<<endl;
    cout<<"            *                                                      *"<<endl;


    cout<<"            *             Q:返回上一级菜单                         *"<<endl;
    cout<<"请输入选项：";


}

//后续可以改成抛出异常
void show_switch_error() {
    cout<<endl;
    cout<<"       =====无此选项！！请重新输入选项！！====="<<endl;
    cout<<endl;
    system("pause");
}

//删除信息查询菜单
void show_delete_demos() {
    show_copyright();
    cout<<"      *                    A:根据学号删除                    *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    B:根据专业和年级删除              *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    Q:返回上一级菜单                  *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"请输入选项："<<endl;
}


//删除修改查询菜单
void show_change_demos() {
    show_copyright();
    cout<<"               --请录入你想修改的同学--"<<endl;
    cout<<"                   *[1]学号     "<<endl;
    cout<<endl;
    cout<<"                   *[2]姓名     "<<endl;
    cout<<endl;
    cout<<"                   *[3]身份证号  "<<endl;
    cout<<endl;
    cout<<"                   请输入你要录入的选项："<<endl;
}

//删除统计查询菜单
void show_statistics_demos() {
    show_copyright();
    cout<<"                   ---请录入你想统计的信息--"<<endl;
    cout<<"                   *[A]统计年级和学院和政治面貌     "<<endl;
    cout<<endl;
    cout<<"                   *[B]统计年级和专业和性别     "<<endl;
    cout<<endl;
    cout<<"                   *[C]统计年级和专业和教育水平     "<<endl;
    cout<<endl;
    cout<<"                   *[Q]返回上一级菜单     "<<endl;
    cout<<endl;
    cout<<"                   请输入你要统计的选项："<<endl;
}

//修改的信息
void show_change_information_demos() {
    show_copyright();
    cout<<"               --请录入你想修改的信息--"<<endl;
    cout<<"                   *[1]学号     "<<endl;
    cout<<endl;
    cout<<"                   *[2]姓名     "<<endl;
    cout<<endl;
    cout<<"                   *[3]性别  "<<endl;
    cout<<endl;
    cout<<"                   *[4]身份证号     "<<endl;
    cout<<endl;
    cout<<"                   *[5]政治面貌     "<<endl;
    cout<<endl;
    cout<<"                   *[6]学院  "<<endl;
    cout<<endl;
    cout<<"                   *[7]专业     "<<endl;
    cout<<endl;
    cout<<"                   *[8]班级号     "<<endl;
    cout<<endl;
    cout<<"                   *[9]辅导员  "<<endl;
    cout<<endl;
    cout<<"                   *[10]学制     "<<endl;
    cout<<endl;
    cout<<"                   *[11]出生日期     "<<endl;
    cout<<endl;
    cout<<"                   *[12]入学日期  "<<endl;
    cout<<endl;
    cout<<"                   *[13]国家  "<<endl;
    cout<<endl;
    cout<<"                   *[14]民族  "<<endl;
    cout<<endl;
    cout<<"                   *[15]教育水平 "<<endl;
    cout<<endl;
    cout<<"                   *[16]婚姻状况 "<<endl;
    cout<<endl;
    cout<<"                   *[17]学生类别 "<<endl;
    cout<<endl;
    cout<<"                   *[18]家庭地址 "<<endl;
    cout<<endl;
    cout<<"                   *[19]生源地 "<<endl;
    cout<<endl;
    cout<<"                   *[20]家庭联系人及联系方式 "<<endl;
    cout<<endl;
    cout<<"                   *[21]入学方式 "<<endl;
    cout<<endl;
    cout<<"                   请输入你要修改的信息："<<endl;
}


//组合信息查询菜单
void show_find_demos() {
    show_copyright();
    cout<<"      *                    A:根据专业和性别查询              *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    B:根据学院和政治面貌查询          *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    C:根据学院和性别查询              *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    D:根据学院入学方式查询            *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    E:根据学院和国家查询              *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    F:根据学院和教育水平查询          *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    Q:返回上一级菜单                  *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"请输入选项："<<endl;
}

//示查找的菜单
void show_find_demo() {
    show_copyright();
    cout<<"      *                    A:根据学号查询                    *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    B:根据姓名查询                    *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    C:根据性别查询                    *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    D:根据学院查询                    *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    E:根据专业查询                    *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    F:根据身份证号查询                *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    G:根据婚姻状况查询                *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    H:根据政治面貌查询                *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    I:根据辅导员查询                  *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    J:组合信息查询                    *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    Q:返回上一级菜单                  *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"请输入选项："<<endl;
}
//----------------------显示菜单-------------------结-束--------------





//-------------------------------------文件操作--------------------------
//显示民族表
void show_ethnic() {
    FILE *fp;
    fp=fopen("../Ethnic.txt", "r");
    if (fp==nullptr) { cout<<"Failed to open file.\n"; }
    char line[1024];
    int cnt=0;
    while (fgets(line, sizeof(line), fp)!=nullptr) {
        char *pos=strchr(line, '\n');
        if (pos!=nullptr) {
            *pos='\0';
        }//删除换行符
        cout<<line<<"\t";
        cnt++;
        if (cnt%5==0)cout<<endl;
    }
    cout<<endl<<"请选择对应的民族代码：";
}


//根据学院代码显示对应的辅导员
void show_counselor(string code) {
    FILE *fp;
    fp=fopen("../Counselor.txt", "r");
    if (fp==nullptr) { cout<<"Failed to open file.\n"; }
    char line[1024];
    int cnt=0;
    while (fgets(line, sizeof(line), fp)!=nullptr) {
        if (string(line).substr(1, 2)==code) {
            //找到对应的学院了
            char *pos=strchr(line, '\n');
            if (pos!=nullptr) {
                *pos='\0';
            }//删除换行符
            cout<<string(line).substr(4, 10)<<endl;
            cnt++;
        }
    }
    cout<<endl<<"请选择对应的辅导员代码：";
    ::fclose(fp);
}

//显示学院表
void show_college() {
    FILE *fp;
    fp=fopen("../College.txt", "r");
    if (fp==nullptr) { cout<<"Failed to open file.\n"; }
    char line[1024];
    int cnt=0;
    while (fgets(line, sizeof(line), fp)!=nullptr) {
        char *pos=strchr(line, '\n');
        if (pos!=nullptr) {
            *pos='\0';
        }//删除换行符
        cout<<line<<endl;
    }
    cout<<endl<<"请选择对应的学院代码：";
}


void show_marriage() {
    FILE *fp;
    fp=fopen("../Marriage.txt", "r");
    if (fp==nullptr) { cout<<"Failed to open file.\n"; }
    char line[1024];
    int cnt=0;
    while (fgets(line, sizeof(line), fp)!=nullptr) {
        char *pos=strchr(line, '\n');
        if (pos!=nullptr) {
            *pos='\0';
        }//删除换行符
        cout<<line<<endl;
    }
    cout<<endl<<"请选择对应的婚宴状况代码：";
}

//显示政治面貌的菜单
void show_political() {
    FILE *fp;
    fp=fopen("../Political.txt", "r");
    if (fp==nullptr) { cout<<"Failed to open file.\n"; }
    char line[1024];
    int cnt=0;
    cout<<endl;
    while (fgets(line, sizeof(line), fp)!=nullptr) {
        char *pos=strchr(line, '\n');
        if (pos!=nullptr) {
            *pos='\0';
        }//删除换行符
        cout<<line<<endl;
    }
    cout<<endl<<"请选择对应的政治面貌代码：";
}

void show_nation() {
    FILE *fp;
    fp=fopen("../Nation.txt", "r");
    if (fp==nullptr) { cout<<"Failed to open file.\n"; }
    char line[1024];
    int cnt=0;
    while (fgets(line, sizeof(line), fp)!=nullptr) {
        char *pos=strchr(line, '\n');
        if (pos!=nullptr) {
            *pos='\0';
        }//删除换行符
        cout<<setw(50)<<left<<line;
        if (cnt%2==0)cout<<endl;
        cnt++;

    }
    cout<<endl<<"请选择对应的国家代码(press enter to use default CHINA)：";
}

//显示学生类别
void show_studenttype() {
    FILE *fp;
    fp=fopen("../Studenttype.txt", "r");
    if (fp==nullptr) { cout<<"Failed to open file.\n"; }
    char line[1024];
    while (fgets(line, sizeof(line), fp)!=nullptr) {
        char *pos=strchr(line, '\n');
        if (pos!=nullptr) {
            *pos='\0';
        }//删除换行符
        cout<<line<<endl;
    }
    cout<<endl<<"请选择对应的入学方式代码：";
}

//显示教育水平
void show_education() {
    FILE *fp;
    fp=fopen("../Education.txt", "r");
    if (fp==nullptr) { cout<<"Failed to open file.\n"; }
    char line[1024];
    int cnt=0;
    while (fgets(line, sizeof(line), fp)!=nullptr) {
        char *pos=strchr(line, '\n');
        if (pos!=nullptr) {
            *pos='\0';
        }//删除换行符
        cout<<setw(30)<<left<<line;
        cnt++;
        if (cnt%3==0)cout<<endl;
    }
    cout<<endl<<"请选择对应的教育水平代码：";
}


void show_china_address() {
    FILE *fp;
    fp=fopen("../china_address.txt", "r");
    if (fp==nullptr) { cout<<"Failed to open file.\n"; }
    char line[1024];
    int cnt=0;
    while (fgets(line, sizeof(line), fp)!=nullptr) {
        char *pos=strchr(line, '\n');
        if (pos!=nullptr) {
            *pos='\0';
        }//删除换行符
        cout<<line<<endl;
        cnt++;
    }
}

//显示入学方式的菜单
void show_admisson() {
    FILE *fp;
    fp=fopen("../Admission.txt", "r");
    if (fp==nullptr) { cout<<"Failed to open file.\n"; }
    char line[1024];
    int cnt=0;
    while (fgets(line, sizeof(line), fp)!=nullptr) {
        char *pos=strchr(line, '\n');
        if (pos!=nullptr) {
            *pos='\0';
        }//删除换行符
        cout<<line<<endl;
        cnt++;
    }
    cout<<endl<<"请选择对应的入学方式水平代码：";
}
//-------------------------------------文件操作结束--------------------------



//-------------------------------------检验出生日期--------------------------
//检验出生日期
bool check_date_of_birth(string date_of_birth) {
    int year, month, day;
    if(check_format_date(date_of_birth))
    {
        get_date_of_int(date_of_birth, year, month, day);
        if (is_valid_date(year, month, day)) {
            if (check_limit_date_of_birth(year)) {
                return true;
            } else {
                cout<<"未符合入学年龄，入学年龄需要在12-62岁之间！"<<endl;
                return false;
            }
        } else {
            cout<<"该日期不合法！"<<endl;
            return false;
        }
    }
    else{
        cout<<"该日期的格式不合法！"<<endl;
        return false;
    }
}
//2004.07.24
bool check_format_date(string date_of_birth){
    if(date_of_birth.length()!=10){
        return false;
    }
    if(date_of_birth[4]!='.'||date_of_birth[7]!='.'){
        return false;
    }
    if(!isdigit(date_of_birth[0])||!isdigit(date_of_birth[1])||!isdigit(date_of_birth[2])
    ||!isdigit(date_of_birth[3])||!isdigit(date_of_birth[5])||!isdigit(date_of_birth[6])
    ||!isdigit(date_of_birth[8])||!isdigit(date_of_birth[9])){
        return false;
    }
    return true;
}
//检查日期是否合法和入学月份是否是8-10，如果错误给出提示
bool check_date_of_admission(string date_of_birth) {
    int year, month, day;
    //获取当前年份，若入学年份晚于现在，不合法
    auto now=std::chrono::system_clock::now();
    std::time_t current_time=std::chrono::system_clock::to_time_t(now);
    std::tm local_time=*std::localtime(&current_time);
    int current_year=local_time.tm_year+1900;


    if(check_format_date(date_of_birth))
    {
        get_date_of_int(date_of_birth, year, month, day);
        if (is_valid_date(year, month, day)) {
            if (check_limit_date_of_admission(year, month, day)) {
                if (year<=current_year) {
                    return true;
                } else {
                    cout<<"入学年份应该不晚于今年!!"<<endl;
                }
            } else {
                cout<<"入学月份应该为为8=<月份<=10！！"<<endl;
            }
        } else {
            cout<<"日期不合法 ! !"<<endl;
            return false;
        }
    }
    else{
        cout<<"日期格式不合法 ! !"<<endl;
        return false;
    }
}

//检验日期是否合法
bool is_valid_date(int year, int month, int day) {
    if (year<0||month<1||month>12||day<1) {
        return false;
    }
    int max_day=31;
    switch (month) {
        case 2:
            max_day=is_leaf(year) ? 29 : 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            max_day=30;
            break;
    }
    return day<=max_day;
}


void get_str_by_date(string str, int &year, int &month, int &day) {
    year=stoi(str.substr(0, 4));
    month=stoi(str.substr(5, 2));
    day=stoi(str.substr(8, 2));
}


//如果str1早于str2,返回true
bool is_early(string str1, string str2) {
    bool ans=true;
    int year1, year2, month1, month2, day1, day2;
    get_str_by_date(str1, year1, month1, day1);
    get_str_by_date(str2, year2, month2, day2);

    if (year1<year2)
        ans=true;
    else if (year1>year2)
        ans=false;
    else {
        if (month1<month2)
            ans=true;
        else if (month1>month2)
            ans=false;
        else {
            if (day1<day2)
                ans=true;
            else if (day1>day2)
                ans=false;
            else
                ans=false;
        }
    }
    return ans;
}


//闰年
bool is_leaf(int year) {
    return year%4==0&&(year%100!=0||year%400==0);
}

//从1997，05.19得到1997，5，19
void get_date_of_int(string date, int &year, int &month, int &day) {
    year=stoi(date.substr(0, 4));
    month=stoi(date.substr(5, 2));
    day=stoi(date.substr(8, 2));
}

//检查是否被在限制入学年龄
bool check_limit_date_of_birth(int year) {
    auto now=std::chrono::system_clock::now();
    std::time_t current_time=std::chrono::system_clock::to_time_t(now);
    std::tm local_time=*std::localtime(&current_time);
    int current_year=local_time.tm_year+1900;
    //入学年龄需要在12-62岁之间
    //例如2023-12+1=2012，2012-12岁符合条件
    if (current_year-62+1<=year&&year<=current_year-12+1)return true;
    else return false;
}


//检查入学年月是否限制
bool check_limit_date_of_admission(int year, int month, int day) {
    if (8<=month&&month<=10) {
        return true;
    } else {
        return false;
    }
}

//-------------------------------------检验出生日期结束--------------------------
//-------------------------------------检验学号--------------------------------
bool check_id(string id, student students[]) {
    if (!check_len_id(id)) {
        cout<<"学号长度有误！！应该为9位学号！！"<<endl;
        return false;
    } else if (!check_college_id(id)) {
        cout<<"学号学院代码有误！！"<<endl;
        return false;
    } else if (!check_id_repeat(id, students)) {
        //在数据文件种没找到相同的返回true，找到相同的返回false
        cout<<"该学号已经存在！！"<<endl;
        return false;
    } else if (!check_id_digit(id)) {
        cout<<"该学号必须由数字构成！！"<<endl;
        return false;
    } else if (!check_class_id(id)) {
        cout<<"该学号的班级号出现错误！！"<<endl;
        return false;
    } else if (!check_back_id(id)) {
        cout<<"该学号的最后两位出现错误！！"<<endl;
        return false;
    } else {
        if (!check_grade_id(id)) {
            cout<<endl<<endl;
            cout<<"           ===================================================================="<<endl;
            cout<<"           =================警告！！输入的学号和当前年份不符合============="<<endl;
            cout<<"           ===================================================================="<<endl;
            cout<<endl<<endl;
        }
        return true;
    }
}

//检查学号是否都是数字
bool check_id_digit(string id) {
    for (int i=0; i<id.length(); i++) {
        //如果有非数字，直接返回false
        if (!isdigit(id[i])) {
            return false;
        }
    }
    return true;
}

//检查学号位数
bool check_len_id(string id) {
    if (id.length()==9)return true;
    return false;
}

//检查学号中的班级号
bool check_class_id(string id) {
    string college=(id.substr(0, 2));
    //学院为这些的学号，222200231，567位为班级号
    if (college=="06"||college=="08"||college=="09"||college=="15"||college=="18"||college=="19"||college=="22"||
        college=="29") {
        string class_id=id.substr(4, 3);
        if (class_id=="001"||class_id=="002"||class_id=="003"||class_id=="004"||class_id=="005"||class_id=="006"||
            class_id=="007"||class_id=="008") {
            //正确
            return true;
        } else {
            return false;
        }
    } else {
//学院为这些的学号，56位为班级号
        string class_id=id.substr(4, 2);
        if (class_id=="01"||class_id=="02"||class_id=="03"||class_id=="04"||class_id=="05"||class_id=="06"||
            class_id=="07"||class_id=="08") {
            //正确
            return true;
        } else {
            return false;
        }
    }
}

//检查学号后两位
bool check_back_id(string id) {
    //222200231
    int college=stoi(id.substr(7, 2));
    if (college>80) {
        //班级人数不会超过80人
        return false;
    } else {
        return true;
    }
}

//在数据文件种没找到相同的返回true，找到相同的返回false
bool check_id_repeat(string id, student students[]) {
    read_file(students);
    FILE *fp;
    fp=fopen("../students.txt", "r");
    if (fp==nullptr) { cout<<"Failed to open file.\n"; }
    char line[1024];
    int flag=1;
    while (fgets(line, sizeof(line), fp)!=nullptr) {
        string id_exist=string(line).substr(0, 9);
        if (id==id_exist) {
            flag=0;
            break;
        }
    }
    if (flag==1)return true;
    else return false;
}

//检查前两位学院
bool check_college_id(string id) {
    int College[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 16, 18, 19, 22, 25, 29, 83, 85};
    const int college_size=sizeof(College)/sizeof(int);
    int college_number=stoi(id.substr(0, 2));
    for (int i=0; i<college_size; i++) {
        if (college_number==College[i]) {
            return true;
        }
    }
    return false;
}

//检查前三四位年级
bool check_grade_id(string id) {
    //获取当前年份
    time_t now=time(0);
    tm *ltm=localtime(&now);
    int now_year=ltm->tm_year+1900;
    int year_number=stoi(id.substr(2, 2));
    year_number+=2000;
    if (now_year==year_number)return true;
    return false;
}

//-------------------------------------检验学号结束-----------------
//-------------------------------------身份证号的检验------------------------
//检验身份证号
bool check_id_number(string id_number) {
    if (!check_len_of_idnumber(id_number)) {
        cout<<"身份证号长度错误"<<endl;
        return false;
    } else if (!check_digit_of_idnumber(id_number)) {
        cout<<"身份证前17位错误"<<endl;
        return false;
    } else if (!check_region_of_idnumber(id_number)) {
        cout<<"地区码错误"<<endl;
        return false;
    } else if (!check_checkcode_of_idnumber(id_number)) {
        cout<<"身份证号码校验错误"<<endl;
        return false;
    }
    return true;
}

//检验身份证号的顺序码，奇数返回true男性,偶数返回false女性
bool check_gender_of_idnumber(string id_number) {
    int order=stoi(id_number.substr(16, 1));
    if (order%2==0)return false;
    else return true;
}

//检验身份证号的校验码
bool check_checkcode_of_idnumber(string id_number) {
    int weight[]={7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char check_code[]={'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    int sum=0;
    //产生校验码,string[i]得到的是字符常量
    for (int i=0; i<17; i++) {
        sum+=(id_number[i]-'0')*weight[i];
    }
    int remainder=sum%11;
    //判断最后一位校验码是否正确
    if (id_number[17]==check_code[remainder]) {
        return true;
    } else {
        return false;
    }
}

//检验身份证的长度
bool check_len_of_idnumber(string id_number) {
    if (id_number.length()!=18) {
        cout<<"身份证号码输入有误，应该为18位"<<endl;
        return false;
    } else return true;
}

//检查身份证号码里的地区码
bool check_region_of_idnumber(string id_number) {
    int region_code=stoi(id_number.substr(0, 6));
    char *region;
    FILE *fp;
    fp=fopen("../Region.txt", "r");
    if (fp==nullptr) { cout<<"Failed to open file.\n"; }
    char line[1024];
    int flag=1;
    while (fgets(line, sizeof(line), fp)!=nullptr) {
        int region=stoi(string(line).substr(0, 6));
        if (region==region_code) {
            flag=0;
            break;
        }
    }
    if (flag==1)return false;
    else return true;
}

//检验身份证号前十七位是否都是数字
bool check_digit_of_idnumber(string id_number) {
    for (int i=0; i<17; i++) {
        if (!isdigit(id_number[i])) {
            return false;
        }
    }
    return true;
}

//身份证号返回出生日期35062720040724  2004.07.24
string get_birth_of_id_number(string id_number) {
    string date_of_birth=id_number.substr(6, 4)+'.'+id_number.substr(10, 2)+'.'+id_number.substr(12, 2);
    return date_of_birth;
}

//----------------------------------------身份证号的检验结束------------------------

//从学号获取年级
string get_date_of_id(string id) {
    string date_of_admission=id.substr(2, 2);
    return "20"+date_of_admission;
}


//不合法返回false
bool check_name(string name, string nation) {
    int len=name.length();
    //中国人的姓名检测
    if (nation=="中国") {
        if (hasNonChinese(name)) {
            cout<<"中国人名字不合法！！";
            return false;
        }
        if (len>40||len<4) {
            cout<<"姓名为2-20个汉字，名字不合法！！";
            return false;
        }
    }
    if (hasChinese(name)&&hasNonChinese(name)) {
        cout<<"同时含有中文和其他，名字不合法！！";
        return false;
    }
    if (has_digit(name)) {
        cout<<"含有数字名字不合法！！";
        return false;
    }
    //长度限制
    if (len>40&&nation!="中国") {
        cout<<"姓名长度不超过40个字符，名字不合法！！";
        return false;
    }
    return true;
}

bool has_digit(const string &str) {
    for (int i=0; i<str.length(); i++) {
        if (isdigit((str[i]))) {
            return true;
        }
    }
    return false;
}


//判断是否有中文
bool hasChinese(const string &str) {
    unsigned char c;
    for (int i=0; i<str.length(); i++) {
        c=str[i];
        if (c>0x80) {
            return true;
        }
    }
    return false;
}


//判断是否有除了中文以外的字符
bool hasNonChinese(const string &str) {
    unsigned char c;
    for (int i=0; i<str.length(); i++) {
        c=str[i];
        if (c<=0x80) {
            return true;
        }
    }
    return false;
}


bool check_gender(string gender) {
    if (gender=="男"||gender=="女") {
        return true;
    }
    if (gender=="f"||gender=="m") {
        return true;
    }
    if (gender=="F"||gender=="M") {
        return true;
    }
    return false;
}


void add_student(student students[]) {
    student student;
//    student.get_id(students)&&student.get_nation()&&student.get_name()&&student.get_gender()&&
//    student.get_date_of_birth()&&student.get_id_number()
//    &&student.get_ethnic()
//    student.get_ethnic()&&student.get_nation()&&student.get_id(students)&&
//    student.get_date_of_admisson()
//    student.get_gender()&&
//    student.get_political_status()&&student.get_marriage()
//    &&student.get_college()&&student.get_major()student.get_study_time()&&student.get_counselor()student.get_education()&&student.get_admission()
//        &&student.get_student_type()&&s
//        &&
    if (
        student.get_class_number()
        &&student.get_address_home()&&student.get_address_study()
        &&student.get_family_phone_number()
            ) {
        cout<<endl<<"该学生信息录入成功！！"<<endl;
        students[cnt++]=student;
        add_data_to_file(student);
        //把一整条数据写入文件
    } else {
        cout<<endl<<"该学生信息有错误，请重试"<<endl;
    }
    system("pause");
    system("cls");
}

//把一整条数据写入文件
void add_data_to_file(student stu) {
    FILE *fp=::fopen("../students.txt", "a+");
    ::fprintf(fp, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",
              stu.id.c_str(), stu.name.c_str(), stu.gender.c_str(), stu.id_number.c_str(), stu.political.c_str(),
              stu.college.c_str(), stu.major.c_str(),
              stu.class_number.c_str(), stu.counselor.c_str(), stu.study_time.c_str(),
              stu.date_of_birth.c_str(), stu.date_of_admission.c_str(), stu.nation.c_str(), stu.ethnic.c_str(),
              stu.marriage.c_str(),
              stu.education.c_str(), stu.student_type.c_str(), stu.address_study.c_str(), stu.address_home.c_str(),
              stu.family_phone_number.c_str(),
              stu.admisson.c_str());
    ::fclose(fp);
}

//把一所有数据重新全部写入文件
void add_datas_to_file(student stu[]) {
    FILE *fp=::fopen("../students.txt", "w");
    for (int i=1; i<=cnt; i++) {
        ::fprintf(fp, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",
                  stu[i].id.c_str(), stu[i].name.c_str(), stu[i].gender.c_str(), stu[i].id_number.c_str(),
                  stu[i].political.c_str(), stu[i].college.c_str(), stu[i].major.c_str(),
                  stu[i].class_number.c_str(), stu[i].counselor.c_str(), stu[i].study_time.c_str(),
                  stu[i].date_of_birth.c_str(), stu[i].date_of_admission.c_str(), stu[i].nation.c_str(),
                  stu[i].ethnic.c_str(), stu[i].marriage.c_str(),
                  stu[i].education.c_str(), stu[i].student_type.c_str(), stu[i].address_study.c_str(),
                  stu[i].address_home.c_str(), stu[i].family_phone_number.c_str(),
                  stu[i].admisson.c_str());
    }
    ::fclose(fp);
}


//--------------------------查询函数---------------------------------
void find_by_id(student students[]) {
    int find_int=0;
    string id;
    cout<<"请输入要查询的学号:";
    cin>>id;
    for (int i=1; i<=cnt; i++) {
        if (students[i].id==id) {
            find_int++;
            students[i].show_info();
            system("pause");
        }
    }
    if (!find_int) {
        cout<<"对不起，查询不到此信息，请重新尝试！！";
    }
}

void find_by_name(student students[]) {
    int find_int=0;
    string name;
    cout<<"请输入要查询的姓名:";
    cin>>name;
    for (int i=1; i<=cnt; i++) {
        if (students[i].name==name) {
            find_int++;
            students[i].show_info();
            system("pause");
        }
    }
    if (!find_int) {
        cout<<"对不起，查询不到此信息，请重新尝试！！";
    }
}

void find_by_gender(student students[]) {
    int find_int=0;
    string gender;
    string code;
    cout<<"      *                         [1]男                         *"<<endl
        <<"      *                                                       *"<<endl
        <<"      *                         [2]女                         *"<<endl;
    cout<<"请输入要查询的性别代码:";
    cin>>code;
    if (code=="1") {
        gender="男";
    }
    if (code=="2") {
        gender="女";
    }
    for (int i=1; i<=cnt; i++) {
        if (students[i].gender==gender) {
            find_int++;
            students[i].show_info();
            system("pause");
        }
    }
    if (!find_int) {
        cout<<"对不起，查询不到此信息，请重新尝试！！";
    }
}

void find_by_college(student students[]) {
    int find_int=0;
    string code;
    string college;
    show_college();
    cin>>code;
    FILE *fp;
    fp=::fopen("../College.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //不断地一行一行读入字符数组
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==code) {
                //处理掉换行符
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //获取学院的值
                college=string(line).substr(5);
            }
        }
    }
    for (int i=1; i<=cnt; i++) {
        if (students[i].college==college) {
            find_int++;
            students[i].show_info();
            system("pause");
        }
    }
    if (!find_int) {
        cout<<"对不起，查询不到此信息，请重新尝试！！";
    }

}


void find_by_major(student students[]) {
    int find_int=0;
    string major;
    cout<<"请输入要查询的专业:";
    cin>>major;
    for (int i=1; i<=cnt; i++) {
        if (students[i].major==major) {
            find_int++;
            students[i].show_info();
            system("pause");
        }
    }
    if (!find_int) {
        cout<<"对不起，查询不到此信息，请重新尝试！！";
    }
}

void find_by_id_number(student students[]) {
    int find_int=0;
    string id_number;
    cout<<"请输入要查询的身份证号:";
    cin>>id_number;
    for (int i=1; i<=cnt; i++) {
        if (students[i].id_number==id_number) {
            find_int++;
            students[i].show_info();
            system("pause");
        }
    }
    if (!find_int) {
        cout<<"对不起，查询不到此信息，请重新尝试！！";
    }
}

void find_by_marriage(student students[]) {
    int find_int=0;
    string marriage;
    string code;
    show_marriage();
    cout<<"请输入要查询的婚姻状况代码:";
    cin>>code;
    FILE *fp;
    fp=::fopen("../Marriage.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //不断地一行一行读入字符数组
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==code) {
                //处理掉换行符
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //获取学院的值
                marriage=string(line).substr(5);
            }
        }
    }
    for (int i=1; i<=cnt; i++) {
        if (students[i].marriage==marriage) {
            find_int++;
            students[i].show_info();
            system("pause");
        }
    }
    if (!find_int) {
        cout<<"对不起，查询不到此信息，请重新尝试！！";
    }
}


void find_by_political(student students[]) {
    int find_int=0;
    string political;
    string code;
    show_political();
    cout<<"请输入要查询的政治面貌:";
    cin>>code;
    FILE *fp;
    fp=::fopen("../Political.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //不断地一行一行读入字符数组
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==code) {
                //处理掉换行符
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //获取学院的值
                political=string(line).substr(5);
            }
        }
    }
    for (int i=1; i<=cnt; i++) {
        if (students[i].political==political) {
            find_int++;
            students[i].show_info();
            system("pause");
        }
    }
    if (!find_int) {
        cout<<"对不起，查询不到此信息，请重新尝试！！";
    }
}

void find_by_counselor(student students[]) {
    int find_int=0;
    string counselor;
    cout<<"请输入要查询的辅导员:";
    cin>>counselor;
    for (int i=1; i<=cnt; i++) {
        if (students[i].counselor==counselor) {
            find_int++;
            students[i].show_info();
            system("pause");
        }
    }
    if (!find_int) {
        cout<<"对不起，查询不到此信息，请重新尝试！！";
    }
}

//--------------------查询------结束--------------------------------
//--------------------查询------组合信息---------------------------------
void find_by_major_gender(student students[]) {
    int find_int=0;
    string counselor;
    cout<<"请输入要查询的辅导员:";
    cin>>counselor;
    for (int i=1; i<=cnt; i++) {
        if (students[i].counselor==counselor) {
            find_int++;
            students[i].show_info();
            system("pause");
        }
        if (!find_int) {
            cout<<"对不起，查询不到此信息，请重新尝试！！";
        }
    }
}

void find_by_college_political(student students[]) {
    int find_int=0;
    string college, college_code, political, political_code;
    show_college();
    cin>>college_code;
    FILE *fp;
    fp=::fopen("../College.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //不断地一行一行读入字符数组
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==college_code) {
                //处理掉换行符
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //获取学院的值
                college=string(line).substr(5);
            }
        }
    }
    show_political();
    cin>>political_code;
    fp=::fopen("../Political.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //不断地一行一行读入字符数组
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==political_code) {
                //处理掉换行符
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //获取学院的值
                political=string(line).substr(5);
            }
        }
    }

    for (int i=1; i<=cnt; i++) {
        if (students[i].college==college&&students[i].political==political) {
            find_int++;
            students[i].show_info();
            system("pause");
        }
    }
    if (!find_int) {
        cout<<"对不起，查询不到此信息，请重新尝试！！";
    }

}

void find_by_college_gender(student students[]) {
    //查询到的个数
    int find_int=0;
    string gender, college, gender_code, college_code;
    cout<<"      *                         [1]男                         *"<<endl
        <<"      *                                                       *"<<endl
        <<"      *                         [2]女                         *"<<endl;
    cout<<"请输入要查询的性别代码:";
    cin>>gender_code;
    if (gender_code=="1") {
        gender="男";
    }
    if (gender_code=="2") {
        gender="女";
    }
    show_college();
    cin>>college_code;
    FILE *fp;
    fp=::fopen("../College.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //不断地一行一行读入字符数组
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==college_code) {
                //处理掉换行符
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //获取学院的值
                college=string(line).substr(5);
            }
        }
    }
    for (int i=1; i<=cnt; i++) {
        if (students[i].college==college&&students[i].gender==gender) {
            find_int++;
            students[i].show_info();
            system("pause");
        }
    }
    if (!find_int) {
        cout<<"对不起，查询不到此信息，请重新尝试！！";
    }
}

void find_by_college_admisson(student students[]) {
    int find_int=0;
    string college, code_college;
    show_college();
    cin>>code_college;
    FILE *fp;
    fp=::fopen("../College.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //不断地一行一行读入字符数组
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==code_college) {
                //处理掉换行符
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //获取学院的值
                college=string(line).substr(5);
            }
        }
    }
    string admisson;
    cout<<"请输入要查询的入学方式:";
    cin>>admisson;
    for (int i=1; i<=cnt; i++) {
        find_int++;
        if (students[i].college==college&&students[i].admisson==admisson) {
            students[i].show_info();
            system("pause");
        }
    }
    if (!find_int) {
        cout<<"对不起，查询不到此信息，请重新尝试！！";
    }
}

void find_by_college_nation(student students[]) {
    int find_int=0;
    string college, college_code, nation, nation_code;
    show_college();
    cin>>college_code;
    FILE *fp;
    fp=::fopen("../College.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //不断地一行一行读入字符数组
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==college_code) {
                //处理掉换行符
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //获取学院的值
                college=string(line).substr(5);
            }
        }
    }
    show_nation();
    cin>>nation_code;
    fp=::fopen("../Nation.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //不断地一行一行读入字符数组
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==nation_code) {
                //处理掉换行符
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //获取国家的值
                nation=string(line).substr(5);
            }
        }
    }
    for (int i=1; i<=cnt; i++) {
        if (students[i].college==college&&students[i].nation==nation) {
            find_int++;
            students[i].show_info();
            system("pause");
        }
    }
    if (!find_int) {
        cout<<"对不起，查询不到此信息，请重新尝试！！";
    }
}

void find_by_college_education(student students[]) {
    string college, code_college;
    show_college();
    cin>>code_college;
    FILE *fp;
    fp=::fopen("../College.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //不断地一行一行读入字符数组
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==code_college) {
                //处理掉换行符
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //获取学院的值
                college=string(line).substr(5);
            }
        }
    }
    int find_int=0;
    string education;
    cout<<"请输入要查询的教育水平:";
    cin>>education;
    for (int i=1; i<=cnt; i++) {
        if (students[i].college==college&&students[i].education==education) {
            find_int++;
            students[i].show_info();
            system("pause");
        }
    }
    if (!find_int) {
        cout<<"对不起，查询不到此信息，请重新尝试！！";
    }
}

//--------------------查询------组合信息----结束-----------------------------
//--------------------删除---------------------------------
//删除单条学生
void delete_student(student students[]) {
    //根据学号删除
    string id;
    cout<<"请输入要删除的学生的学号:";
    cin>>id;
    for (int i=1; i<=cnt; i++) {
        if (students[i].id==id) {
            //删除第i个学生
            //覆盖，总学生数--
            for (int j=i; j<cnt; j++) {
                students[j]=students[j+1];
            }
            cnt--;
        }
    }
    add_datas_to_file(students);
    cout<<"删除学生："<<id<<"成功!!"<<endl;
}

void delete_students(student students[]) {
    //根据年级和专业删除
    string year;
    cout<<"请输入要删除的学生的年级(例如2022):";
    cin>>year;
    string major;
    cout<<"请输入要删除的学生的专业:";
    cin>>major;
    cout<<"确定删除[Y]yes[N]no";
    string yes_no;
    cin>>yes_no;
    if (yes_no=="Y") {
        for (int i=1; i<=cnt; i++) {
            if (get_date_of_id(students[i].id)==year&&students[i].major==major) {
                //删除第i个学生
                //覆盖，总学生数--
                cout<<get_date_of_id(students[i].id);
                for (int j=i; j<cnt; j++) {
                    students[j]=students[j+1];
                }
                cnt--;
            }
        }
        add_datas_to_file(students);
        cout<<"删除学生"<<year<<"级"<<major<<"学生成功！！"<<endl;
    }else{
        cout<<"删除学生"<<year<<"级"<<major<<"失败！！"<<endl;
    }
}


//--------------------删除--结束-------------------------------

//--------------读取所有数据到对象数组中-------------------
void read_file(student *students) {
    cnt=0;//每次重新读入都把学生总数先置为0
    FILE *fp=::fopen("../students.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //不断地一行一行读入
        while (fgets(line, sizeof(line), fp)) {
            //处理掉换行符
            char *ch=strchr(line, '\n');
            if (ch!=nullptr) { *ch='\0'; }
            string data=string(line);
            istringstream iss(data);
            string token;
            //记录每条数据的第几个数据
            int count=1;
            while (getline(iss, token, ' ')) {
                if (count==1) {
                    cnt++;
                    students[cnt].id=token;
                }
                if (count==2) {
                    students[cnt].name=token;
                }
                if (count==3) {
                    students[cnt].gender=token;
                }
                if (count==4) {
                    students[cnt].id_number=token;
                }
                if (count==5) {
                    students[cnt].political=token;
                }
                if (count==6) {
                    students[cnt].college=token;
                }
                if (count==7) {
                    students[cnt].major=token;
                }
                if (count==8) {
                    students[cnt].class_number=token;
                }
                if (count==9) {
                    students[cnt].counselor=token;
                }
                if (count==10) {
                    students[cnt].study_time=token;
                }
                if (count==11) {
                    students[cnt].date_of_birth=token;
                }
                if (count==12) {
                    students[cnt].date_of_admission=token;
                }
                if (count==13) {
                    students[cnt].nation=token;
                }
                if (count==14) {
                    students[cnt].ethnic=token;
                }
                if (count==15) {
                    students[cnt].marriage=token;
                }
                if (count==16) {
                    students[cnt].education=token;
                }
                if (count==17) {
                    students[cnt].student_type=token;
                }
                if (count==18) {
                    students[cnt].address_home=token;
                }
                if (count==19) {
                    students[cnt].address_study=token;
                }
                if (count==20) {
                    students[cnt].family_phone_number=token;
                }
                if (count==21) {
                    students[cnt].admisson=token;
                    count=0;
                }
                count++;
            }
        }
    }
}

void get_change_information(student students[]) {
    string code;
    cin>>code;
    if (code=="1") {
        int find_int=0;
        cout<<"录入学号：";
        string id;
        cin>>id;
        cout<<"录入成功,学号为："<<id;
        int i=1;
        int j=0;
        for (i=1; i<=cnt; i++) {
            if (students[i].id==id) {
                find_int++;
                j=i;
            }
        }//i-1为查询到学生的序号
        if (!find_int) {
            cout<<"对不起，查询不到此信息，请重新尝试！！";
            system("pause");
            system("cls");
        }
        if (find_int) {
            show_change_information_demos();
            string code_change;
            cin>>code_change;
            if (code_change=="1") {
                students[j].get_id(students);
            }
            if (code_change=="2") {
                students[j].get_name();
            }
            if (code_change=="3") {
                students[j].get_gender();
            }
            if (code_change=="4") {
                students[j].get_id_number();
            }
            if (code_change=="5") {
                students[j].get_political_status();
            }
            if (code_change=="6") {
                students[j].get_college();
            }
            if (code_change=="7") {
                students[j].get_major();
            }
            if (code_change=="8") {
                students[j].get_class_number();
            }
            if (code_change=="9") {
                students[j].get_counselor();
            }
            if (code_change=="10") {
                students[j].get_study_time();
            }
            if (code_change=="11") {
                students[j].get_date_of_birth();
            }
            if (code_change=="12") {
                students[j].get_date_of_admisson();
            }
            if (code_change=="13") {
                students[j].get_nation();
            }
            if (code_change=="14") {
                students[j].get_ethnic();
            }
            if (code_change=="15") {
                students[j].get_education();
            }
            if (code_change=="16") {
                students[j].get_marriage();
            }
            if (code_change=="17") {
                students[j].get_student_type();
            }
            if (code_change=="18") {
                students[j].get_address_home();
            }
            if (code_change=="19") {
                students[j].get_address_study();
            }
            if (code_change=="20") {
                students[j].get_family_phone_number();
            }
            if (code_change=="21") {
                students[j].get_admission();
            }
            add_datas_to_file(students);
            cout<<"修改信息成功！";
        }
    } else if (code=="2") {
        int find_int=0;
        cout<<"录入姓名：";
        string name;
        cin>>name;
        cout<<"录入成功,姓名为："<<name;
        int i=1;
        int j=0;
        for (i=1; i<=cnt; i++) {
            if (students[i].name==name) {
                find_int++;
                j=i;
                students[i].show_info();
            }
        }
        if (!find_int) {
            cout<<"对不起，查询不到此信息，请重新尝试！！";
            system("pause");
            system("cls");
        }
        if (find_int) {
            show_change_information_demos();
            string code_change;
            cin>>code_change;
            if (code_change=="1") {
                students[j].get_id(students);
            }
            if (code_change=="2") {
                students[j].get_name();
            }
            if (code_change=="3") {
                students[j].get_gender();
            }
            if (code_change=="4") {
                students[j].get_id_number();
            }
            if (code_change=="5") {
                students[j].get_political_status();
            }
            if (code_change=="6") {
                students[j].get_college();
            }
            if (code_change=="7") {
                students[j].get_major();
            }
            if (code_change=="8") {
                students[j].get_class_number();
            }
            if (code_change=="9") {
                students[j].get_counselor();
            }
            if (code_change=="10") {
                students[j].get_study_time();
            }
            if (code_change=="11") {
                students[j].get_date_of_birth();
            }
            if (code_change=="12") {
                students[j].get_date_of_admisson();
            }
            if (code_change=="13") {
                students[j].get_nation();
            }
            if (code_change=="14") {
                students[j].get_ethnic();
            }
            if (code_change=="15") {
                students[j].get_education();
            }
            if (code_change=="16") {
                students[j].get_marriage();
            }
            if (code_change=="17") {
                students[j].get_student_type();
            }
            if (code_change=="18") {
                students[j].get_address_home();
            }
            if (code_change=="19") {
                students[j].get_address_study();
            }
            if (code_change=="20") {
                students[j].get_family_phone_number();
            }
            if (code_change=="21") {
                students[j].get_admission();
            }
            add_datas_to_file(students);
            cout<<"修改信息成功！";
        }
    } else if (code=="3") {
        int find_int=0;
        cout<<"录入身份证号：";
        string id_number;
        cin>>id_number;
        cout<<"录入成功,身份证号为："<<id_number;
        int i=1;
        int j=0;
        for (i=1; i<=cnt; i++) {
            if (students[i].id_number==id_number) {
                find_int++;
                j=i;
                students[i].show_info();
            }
        }//i为查询到学生的序号
        i--;
        if (!find_int) {
            cout<<"对不起，查询不到此信息，请重新尝试！！";
            system("pause");
            system("cls");
        }
        if (find_int) {
            show_change_information_demos();
            string code_change;
            cin>>code_change;
            if (code_change=="1") {
                students[j].get_id(students);
            }
            if (code_change=="2") {
                students[j].get_name();
            }
            if (code_change=="3") {
                students[j].get_gender();
            }
            if (code_change=="4") {
                students[j].get_id_number();
            }
            if (code_change=="5") {
                students[j].get_political_status();
            }
            if (code_change=="6") {
                students[j].get_college();
            }
            if (code_change=="7") {
                students[j].get_major();
            }
            if (code_change=="8") {
                students[j].get_class_number();
            }
            if (code_change=="9") {
                students[j].get_counselor();
            }
            if (code_change=="10") {
                students[j].get_study_time();
            }
            if (code_change=="11") {
                students[j].get_date_of_birth();
            }
            if (code_change=="12") {
                students[j].get_date_of_admisson();
            }
            if (code_change=="13") {
                students[j].get_nation();
            }
            if (code_change=="14") {
                students[j].get_ethnic();
            }
            if (code_change=="15") {
                students[j].get_education();
            }
            if (code_change=="16") {
                students[j].get_marriage();
            }
            if (code_change=="17") {
                students[j].get_student_type();
            }
            if (code_change=="18") {
                students[j].get_address_home();
            }
            if (code_change=="19") {
                students[j].get_address_study();
            }
            if (code_change=="20") {
                students[j].get_family_phone_number();
            }
            if (code_change=="21") {
                students[j].get_admission();
            }
            add_datas_to_file(students);
            cout<<"修改信息成功！";
        }
    } else {
        show_switch_error();
    }
}

//-----------------排序--并且保存至文件-----------------------------
void swap_student(student &student1, student &student2) {
    student temp=student1;
    student1=student2;
    student2=temp;
}

void sort_small(student students[]) {
    for (int i=1; i<cnt; i++) {
        for (int j=1; j<cnt-i; j++) {
            //如果str1早于str2,返回true
            if (is_early(students[j].date_of_birth, students[j+1].date_of_birth)) {
                swap(students[j], students[j+1]);
            }
        }
    }
    add_datas_to_file(students);
    cout<<"按照年龄从小到大排序成功！！";
}

void sort_big(student students[]) {
    for (int i=1; i<cnt; i++) {
        for (int j=1; j<cnt-i; j++) {
            //如果str1早于str2,返回true
            if (!is_early(students[j].date_of_birth, students[j+1].date_of_birth)) {
                swap(students[j], students[j+1]);
            }
        }
    }
    add_datas_to_file(students);
    cout<<"按照年龄从大到小排序成功！！";
}

//按照学号从大到小排序
void sort_big_id(student students[]) {
    for (int i=1; i<cnt; i++) {
        for (int j=1; j<cnt-i; j++) {
            if (stoi(students[j].id)<stoi(students[j+1].id)) {
                swap(students[j], students[j+1]);
            }
        }
    }
    add_datas_to_file(students);
    cout<<"按照学号从大到小排序成功！！";
}

//按照学号从小到大排序
void sort_small_id(student students[]) {
    for (int i=1; i<cnt; i++) {
        for (int j=1; j<cnt-i; j++) {
            if (stoi(students[j].id)>stoi(students[j+1].id)) {
                swap(students[j], students[j+1]);
            }
        }
    }
    add_datas_to_file(students);
    cout<<"按照学号从小到大排序成功！！";
}


void statistics_grade_college_political(student students[]) {
    //统计年级和学院和政治面貌
    //最多可以统计15种政治面貌
    int find_int1=0, find_int2=0, find_int3=0, find_int4=0, find_int5=0, find_int6=0, find_int7=0, find_int8=0,
            find_int9=0, find_int10=0, find_int11=0, find_int12=0, find_int13=0, find_int14=0, find_int15=0;
    string college, code_college, grade;
    cout<<"请输入你要统计的年级(例如2023):";
    cin>>grade;

    show_college();
    cin>>code_college;
    FILE *fp;
    fp=::fopen("../College.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //不断地一行一行读入字符数组
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==code_college) {
                //处理掉换行符
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //获取学院的值
                college=string(line).substr(5);
            }
        }
    }
    for (int i=1; i<=cnt; i++) {
        if (students[i].college==college&&get_date_of_id(students[i].id)==grade&&
            students[i].political=="中国共产党党员") {
            find_int1++;
        }
        if (students[i].college==college&&get_date_of_id(students[i].id)==grade&&
            students[i].political=="中国共产党预备党员") {
            find_int2++;
        }
        if (students[i].college==college&&get_date_of_id(students[i].id)==grade&&
            students[i].political=="中国共产主义青年团团员") {
            find_int3++;
        }
        if (students[i].college==college&&get_date_of_id(students[i].id)==grade&&
            students[i].political=="中国国民党革命委员会会员") {
            find_int4++;
        }
        if (students[i].college==college&&get_date_of_id(students[i].id)==grade&&
            students[i].political=="中国民主同盟盟员") {
            find_int5++;
        }
        if (students[i].college==college&&get_date_of_id(students[i].id)==grade&&
            students[i].political=="中国民主建国会会员") {
            find_int6++;
        }
        if (students[i].college==college&&get_date_of_id(students[i].id)==grade&&
            students[i].political=="中国民主促进会会员") {
            find_int7++;
        }
        if (students[i].college==college&&get_date_of_id(students[i].id)==grade&&
            students[i].political=="中国农工民主党党员") {
            find_int8++;
        }
        if (students[i].college==college&&get_date_of_id(students[i].id)==grade&&
            students[i].political=="中国致公党党员") {
            find_int9++;
        }
        if (students[i].college==college&&get_date_of_id(students[i].id)==grade&&
            students[i].political=="九三学社社员") {
            find_int10++;
        }
        if (students[i].college==college&&get_date_of_id(students[i].id)==grade&&
            students[i].political=="台湾民主自治同盟盟员") {
            find_int11++;
        }
        if (students[i].college==college&&get_date_of_id(students[i].id)==grade&&
            students[i].political=="无党派民主人士") {
            find_int12++;
        }
        if (students[i].college==college&&get_date_of_id(students[i].id)==grade&&students[i].political=="群众") {
            find_int13++;
        }
    }
    cout<<endl<<"                 ----------------------------------统计结果------------------------         "<<endl;
    cout<<"                                      "<<grade<<"级"<<college<<endl;
    cout<<"                               政治面貌为中国共产党党员"<<"的"<<"共有["<<find_int1<<"]人"<<endl;
    cout<<"                               政治面貌为中国共产党预备党员"<<"的"<<"共有["<<find_int2<<"]人"<<endl;
    cout<<"                               政治面貌为中国共产主义青年团团员"<<"的"<<"共有["<<find_int3<<"]人"<<endl;
    cout<<"                               政治面貌为中国国民党革命委员会会员"<<"的"<<"共有["<<find_int4<<"]人"<<endl;
    cout<<"                               政治面貌为中国民主同盟盟员"<<"的"<<"共有["<<find_int5<<"]人"<<endl;
    cout<<"                               政治面貌为中国民主建国会会员"<<"的"<<"共有["<<find_int6<<"]人"<<endl;
    cout<<"                               政治面貌为中国民主促进会会员"<<"的"<<"共有["<<find_int7<<"]人"<<endl;
    cout<<"                               政治面貌为中国农工民主党党员"<<"的"<<"共有["<<find_int8<<"]人"<<endl;
    cout<<"                               政治面貌为中国致公党党员"<<"的"<<"共有["<<find_int9<<"]人"<<endl;
    cout<<"                               政治面貌为九三学社社员"<<"的"<<"共有["<<find_int10<<"]人"<<endl;
    cout<<"                               政治面貌为台湾民主自治同盟盟员"<<"的"<<"共有["<<find_int11<<"]人"<<endl;
    cout<<"                               政治面貌为无党派民主人士"<<"的"<<"共有["<<find_int12<<"]人"<<endl;
    cout<<"                               政治面貌为群众"<<"的"<<"共有["<<find_int13<<"]人"<<endl;
}

void statistics_grade_college_gender(student students[]) {
    //统计年级和专业和性别
    //男生
    int find_int1=0;
    //女生
    int find_int2=0;
    string college, code_college, grade;
    cout<<"请输入你要统计的年级(例如2023):";
    cin>>grade;
    show_college();
    cin>>code_college;
    FILE *fp;
    fp=::fopen("../College.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //不断地一行一行读入字符数组
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==code_college) {
                //处理掉换行符
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //获取学院的值
                college=string(line).substr(5);
            }
        }
    }
    cout<<"      *                         [1]男                         *"<<endl
        <<"      *                                                       *"<<endl
        <<"      *                         [2]女                         *"<<endl;
    for (int i=1; i<=cnt; i++) {
        if (students[i].college==college&&get_date_of_id(students[i].id)==grade&&students[i].gender=="男") {
            find_int1++;
        }
        if (students[i].college==college&&get_date_of_id(students[i].id)==grade&&students[i].gender=="女") {
            find_int2++;
        }
    }
    cout<<endl<<"                       ------------------------统计结果------------------------         "<<endl;
    cout<<"                               "<<grade<<"级"<<college<<"性别为男的"<<"共有["<<find_int1<<"]人"<<endl;
    cout<<"                               "<<grade<<"级"<<college<<"性别为女的"<<"共有["<<find_int2<<"]人"<<endl;
}

void statistics_grade_college_education(student students[]) {
    //统计年级和学院和教育水平
    int find_int=0;
    string college, code_college, grade, education_code, education;
    cout<<"请输入你要统计的年级(例如2023):";
    cin>>grade;
    show_college();
    cin>>code_college;
    FILE *fp;
    fp=::fopen("../College.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //不断地一行一行读入字符数组
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==code_college) {
                //处理掉换行符
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //获取学院的值
                college=string(line).substr(5);
            }
        }
    }
    show_education();
    cin>>education_code;
    fp=::fopen("../Education.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //不断地一行一行读入字符数组
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==education_code) {
                //处理掉换行符
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //获取国家的值
                education=string(line).substr(4);
            }
        }
    }
    ::fclose(fp);
    for (int i=1; i<=cnt; i++) {
        if (students[i].college==college&&get_date_of_id(students[i].id)==grade&&students[i].education==education) {
            find_int++;
        }
    }
    cout<<endl<<"                       ------------------------统计结果------------------------         "<<endl;
    cout<<"                               "<<grade<<"级"<<college<<"教育水平为"<<education<<"的"<<"共有["<<find_int
        <<"]人"<<endl;
}


