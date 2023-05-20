#include "student.h"

//-------------------------��ȡ��Ϣ---------------------
void student::show_info() {
    cout<<DIVID;
    cout<<"ѧ��:"<<this->id<<endl;
    cout<<"����:"<<this->name<<endl;
    cout<<"�Ա�:"<<this->gender<<endl;
    cout<<"����:"<<this->ethnic<<endl;
    cout<<"���֤��:"<<this->id_number<<endl;
    cout<<"��������:"<<this->date_of_birth<<endl;
    cout<<"��ѧ����:"<<this->date_of_admission<<endl;
    cout<<"ѧԺ:"<<this->college<<endl;
    cout<<"רҵ:"<<this->major<<endl;
    cout<<"�༶:"<<this->class_number<<endl;
    cout<<"ѧ��:"<<this->study_time<<endl;
    cout<<"����Ա:"<<this->counselor<<endl;
    cout<<"����:"<<this->nation<<endl;
    cout<<"��ͥ��ַ:"<<this->address_home<<endl;
    cout<<"��Դ�ص�ַ:"<<this->address_study<<endl;
    cout<<"�����Լ���ϵ��ʽ:"<<this->family_phone_number<<endl;
    cout<<"������ò:"<<this->political<<endl;
    cout<<"����״��:"<<this->marriage<<endl;
    cout<<"ѧ�����:"<<this->student_type<<endl;
    cout<<"����ˮƽ:"<<this->education<<endl;
    cout<<"��ѧ��ʽ:"<<this->admisson<<endl;
}


bool student::get_date_of_birth() {
    string date_of_birth;
    cout<<"�������������(����2004.07.24):";
    cin>>date_of_birth;
    if (check_date_of_birth(date_of_birth)) {
        this->date_of_birth=date_of_birth;
        cout<<"��������¼��ɹ�"<<endl;
        system("pause");
        return true;
    } else {
        cout<<"��������¼��ʧ��"<<endl;
        return false;
    }

}

bool student::get_name() {
    string name;
    cout<<"����������:"<<endl;
    cin>>name;
    if (check_name(name, this->nation)) {
        this->name=name;
        cout<<"����¼��ɹ�"<<endl;
        system("pause");
        return true;
    } else {
        cout<<endl<<endl;
        cout<<"           ===================================================================="<<endl;
        cout<<"           =================����¼��ʧ�ܣ�������¼��ѧ����Ϣ����============="<<endl;
        cout<<"           ===================================================================="<<endl;
        cout<<endl<<endl;
        system("pause");
        return false;
    }
}

//��ȡѧ��
bool student::get_id(student students[]) {
    string id;
    cout<<"������ѧ��:";
    cin>>id;
    if (check_id(id, students)) {
        this->id=id;
        cout<<"ѧ��¼��ɹ�"<<endl;
        system("pause");
        return true;
    } else {
        cout<<endl<<endl;
        cout<<"           ===================================================================="<<endl;
        cout<<"           =================ѧ��¼��ʧ�ܣ�������¼��ѧ����Ϣ����============="<<endl;
        cout<<"           ===================================================================="<<endl;
        cout<<endl<<endl;
        system("pause");
        return false;
    }
}

bool student::get_gender() {
    string gender;
    cout<<"�������Ա�(��/m/M Ů/f/F):";
    cin>>gender;
    if (check_gender(gender)) {
        if (gender=="f"||gender=="F"||gender=="Ů")
            this->gender="Ů";
        if (gender=="m"||gender=="M"||gender=="��")
            this->gender="��";
        return true;
    } else {
        cout<<"��������ȷ���Ա𣡣���"<<endl;
        return false;
    }
    system("pause");
}

//��ȡ���֤��
bool student::get_id_number() {
    string id_number;
    cout<<"���������֤��:";
    cin>>id_number;
    if (check_id_number(id_number)) {
        if (get_birth_of_id_number(id_number)==this->date_of_birth) {
            if ((check_gender_of_idnumber(id_number)&&this->gender=="��")||
                ((!check_gender_of_idnumber(id_number)&&this->gender=="Ů"))) {
                this->id_number=id_number;
                cout<<"���֤��¼��ɹ�"<<endl;
                return true;
            } else {
                cout<<"��������֤�����������Ա�ƥ�䣡��";
                return false;
            }
        } else {
            cout<<"��������֤����������ĳ������ڲ�ƥ�䣡��";
            return false;
        }
    } else {
        cout<<"���֤��¼��ʧ��"<<endl;
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
        if (ch=='\r') { // ����û�������Enter��
            if (code.empty()) {
                code="CN";
            }
            break; // �˳�ѭ��
        } else {
            code+=ch; // ���ַ�׷�ӵ�code��
        }
    }
    FILE *fp;
    fp=::fopen("../Nation.txt", "r");
    int flag=0;
    if (fp!=nullptr) {
        char line[1024];
        //���ϵ�һ��һ�ж����ַ�����
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(0, 4)=="["+code+"]") {
                flag=1;
                //��������з�
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //��ȡ���ҵ�ֵ
                this->nation=string(line).substr(5);
                ans=true;
                cout<<endl;
                cout<<"����¼��ɹ�"<<"���ѡ��Ϊ:"<<this->nation<<endl;
                break;
            }
        }
    }
    if(!flag){
        cout<<"��������ȷ�Ĺ��Ҵ���"<<endl;
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
        //���ϵ�һ��һ�ж����ַ�����
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(0, 4)=="["+code+"]") {
                //��������з�
                flag=1;
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //��ȡ���ҵ�ֵ
                this->ethnic=string(line).substr(5);
                ans=true;
                cout<<"����¼��ɹ�"<<"���ѡ��Ϊ:"<<this->ethnic;
                break;
            }
        }
    }
    if(!flag){
        cout<<"��������ȷ���������"<<endl;
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
        //���ϵ�һ��һ�ж����ַ�����
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(0, 4)=="["+code+"]") {
                flag=1;
                //��������з�
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //��ȡ���ҵ�ֵ
                this->political=string(line).substr(5);
                ans=true;
                cout<<"������ò¼��ɹ�"<<"���ѡ��Ϊ:"<<this->political<<endl;
                break;
            }
        }
    }
    if(!flag){
        cout<<"��������ȷ��������ò����"<<endl;
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
        //���ϵ�һ��һ�ж����ַ�����
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(0, 4)=="["+code+"]") {
                //��������з�
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //��ȡ���ҵ�ֵ
                this->marriage=string(line).substr(5);
                ans=true;
                cout<<"����״��¼��ɹ�"<<"���ѡ��Ϊ:"<<this->marriage<<endl;
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
        //���ϵ�һ��һ�ж����ַ�����
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(0, 4)=="["+code+"]") {
                //��������з�
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //��ȡѧԺ��ֵ
                this->college=string(line).substr(5);
                ans=true;
                cout<<"ѧԺ¼��ɹ�,"<<"���ѡ��Ϊ:"<<this->college<<endl;
                break;
            }
        }
    }
    ::fclose(fp);
    system("pause");
    return ans;
}

//���ܸ���Ա��ѡ�����ӦѧԺ�ļ�������Ա
string get_counselor_file(string code_college, string code) {
    FILE *fp;
    fp=fopen("../Counselor.txt", "r");
    if (fp==nullptr) { cout<<"Failed to open file.\n"; }
    char line[1024];
    int cnt=0;
    while (fgets(line, sizeof(line), fp)!=nullptr) {
        if (string(line).substr(1, 2)==code_college&&string(line).substr(5, 2)==code) {
            //�ҵ���Ӧ�ĸ���Ա��
            ::fclose(fp);
            return string(string(line).substr(8, 6));
        }
    }
}


bool student::get_counselor() {
    if (this->college=="") {
        cout<<"��������ѧԺ";
        return false;
    }
    if (this->college=="�����������Զ���ѧԺ") {
        show_counselor("01");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("01", code);
        cout<<"���ѡ����"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="��е���̼��Զ���ѧԺ") {
        show_counselor("02");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("02", code);
        cout<<"���ѡ����"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="��ѧ��ͳ��ѧԺ") {
        show_counselor("03");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("03", code);
        cout<<"���ѡ����"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="ʯ�ͻ���ѧԺ") {
        show_counselor("04");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("04", code);
        cout<<"���ѡ����"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="��ľ����ѧԺ") {
        show_counselor("05");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("05", code);
        cout<<"���ѡ����"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="�����밲ȫ����ѧԺ") {
        show_counselor("06");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("06", code);
        cout<<"���ѡ����"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="���������ѧԺ") {
        show_counselor("07");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("07", code);
        cout<<"���ѡ����"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="�����ѧ�빤��ѧԺ") {
        show_counselor("08");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("08", code);
        cout<<"���ѡ����"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="�����ѧԺ") {
        show_counselor("09");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("09", code);
        cout<<"���ѡ����"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="������������ѧԺ") {
        show_counselor("22");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("22", code);
        cout<<"���ѡ����"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="��������Ϣ����ѧԺ��΢����ѧԺ") {
        show_counselor("11");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("11", code);
        cout<<"���ѡ����"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="��ѧѧԺ") {
        show_counselor("13");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("13", code);
        cout<<"���ѡ����"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="���������滮ѧԺ") {
        show_counselor("15");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("15", code);
        cout<<"���ѡ����"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="�Ͻ�������ҵѧԺ") {
        show_counselor("16");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("16", code);
        cout<<"���ѡ����"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="���Ͽ�ѧ�빤��ѧԺ") {
        show_counselor("18");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("18", code);
        cout<<"���ѡ����"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="������������ѧԺ") {
        show_counselor("22");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("22", code);
        cout<<"���ѡ����"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="����ѧԺ") {
        show_counselor("01");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("01", code);
        cout<<"���ѡ����"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="��������ѧѧԺ") {
        show_counselor("29");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("29", code);
        cout<<"���ѡ����"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="÷Ŭ˹���ʹ���ѧԺ") {
        show_counselor("83");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("83", code);
        cout<<"���ѡ����"<<this->counselor<<endl;
        return true;
    }
    if (this->college=="�Ƚ�����ѧԺ") {
        show_counselor("85");
        string code;
        cin>>code;
        this->counselor=get_counselor_file("85", code);
        cout<<"���ѡ����"<<this->counselor<<endl;
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
        //���ϵ�һ��һ�ж����ַ�����
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(0, 3)=="["+code+"]") {
                flag=1;
                //��������з�
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //��ȡ���ҵ�ֵ
                this->student_type=string(line).substr(4);
                ans=true;
                cout<<"��ѧ��ʽ¼��ɹ�"<<"���ѡ��Ϊ:"<<this->student_type;
                break;
            }
        }
    }
    if(!flag){
        cout<<"��������ȷ��ѧ��������"<<endl;
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
        //���ϵ�һ��һ�ж����ַ�����
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==code) {
                flag=1;
                //��������з�
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //��ȡ���ҵ�ֵ
                this->education=string(line).substr(4);
                ans=true;
                cout<<"����ˮƽ¼��ɹ�"<<"���ѡ��Ϊ:"<<this->education<<endl;
                break;
            }
        }
    }
    if(!flag){
        cout<<"����ˮƽ¼��ʧ�ܣ���������ȷ��ѧ��ʽ����"<<endl;
    }
    ::fclose(fp);
    return ans;
}

//������Ӧ���ļ������ô򿪶�Ӧ���ļ�,���Ҵ�ӡ
void file_major(string file_name) {
    FILE *fp;
    fp=fopen(file_name.c_str(), "r");
    if (fp==nullptr) { cout<<"Failed to open file.\n"; }
    char line[1024];
    while (fgets(line, sizeof(line), fp)!=nullptr) {
        char *pos=strchr(line, '\n');
        if (pos!=nullptr) {
            *pos='\0';
        }//ɾ�����з�
        cout<<line<<endl;
    }
    ::fclose(fp);
    cout<<endl<<"��ѡ���Ӧ��רҵ���룺";
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
        //���ϵ�һ��һ�ж����ַ�����
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==code) {
                //��������з�
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //��ȡ���ҵ�ֵ
                this->admisson=string(line).substr(5);
                ans=true;
                cout<<"��ѧ��ʽ¼��ɹ�"<<"���ѡ��Ϊ:"<<this->admisson<<endl;
                break;
            }
        }
    }
    ::fclose(fp);
    return ans;
}


//�༶��
bool student::get_class_number() {
    bool ans=false;
    int flag=0;
    cout<<endl<<"[1]01  "<<"[2]02  "<<"[3]03"<<endl<<"[4]04  "<<"[5]05  "<<"[6]06"<<endl<<"[7]07  "<<"[8]08"<<endl;
    cout<<"��������İ༶���룺";
    string code;
    cin>>code;
    if (code=="1") {
        flag=1;
        ans=true;
        this->class_number="01";
        cout<<endl<<"����ɹ�,���ѡ����"<<this->class_number<<"��"<<endl;
    } else if (code=="2") {
        flag=1;
        ans=true;
        this->class_number="02";
        cout<<endl<<"����ɹ�,���ѡ����"<<this->class_number<<"��"<<endl;
    } else if (code=="3") {
        flag=1;
        ans=true;
        this->class_number="03";
        cout<<endl<<"����ɹ�,���ѡ����"<<this->class_number<<"��"<<endl;
    } else if (code=="4") {
        flag=1;
        ans=true;
        this->class_number="04";
        cout<<endl<<"����ɹ�,���ѡ����"<<this->class_number<<"��"<<endl;
    } else if (code=="5") {
        flag=1;
        ans=true;
        this->class_number="05";
        cout<<endl<<"����ɹ�,���ѡ����"<<this->class_number<<"��"<<endl;
    } else if (code=="6") {
        flag=1;
        ans=true;
        this->class_number="06";
        cout<<endl<<"����ɹ�,���ѡ����"<<this->class_number<<"��"<<endl;
    } else if (code=="7") {
        flag=1;
        ans=true;
        this->class_number="07";
        cout<<endl<<"����ɹ�,���ѡ����"<<this->class_number<<"��"<<endl;
    } else if (code=="8") {
        flag=1;
        ans=true;
        this->class_number="08";
        cout<<endl<<"����ɹ�,���ѡ����"<<this->class_number<<"��"<<endl;
    }
    if(!flag){
        cout<<"��������ȷ�İ༶�Ŷ�Ӧ�Ĵ���"<<endl;
    }
    return ans;
}

//ѧ��
bool student::get_study_time() {
    bool ans=false;
    string code;
    cout<<endl<<"[01]����"<<endl<<"[02]������"<<endl;
    cout<<"���������ѧ�ƴ���(���»س�Ĭ��ֵΪ����)��";
    bool flag=0;
    while (true) {
        char ch=getch();
        cout<<ch;
        if (ch=='\r') { // ����û�������Enter��
            if (code.empty()) {
                code="01";
                flag=1;
            }
            break; // �˳�ѭ��
        } else {
            code+=ch; // ���ַ�׷�ӵ�code��
        }
    }
    if (code=="01") {
        flag=1;
        ans=true;
        this->study_time="����";
        flag=1;
    } else if (code=="02") {
        ans=true;
        this->study_time="����";
    }
    if(!flag){
        cout<<endl<<"����ʧ�ܣ���ѡ����ȷ��ѧ�ƴ���"<<endl;
    }
    cout<<endl<<"����ɹ������ѡ����"<<this->study_time<<endl;
    return ans;
}


//��ѧ����
bool student::get_date_of_admisson() {
    string date_of_admission;
    cout<<"��������ѧ����(����2023.09.24):";
    cin>>date_of_admission;
    //��������Ƿ�Ϸ�����ѧ�·��Ƿ���8-10��������������ʾ
    if (check_date_of_admission(date_of_admission)) {
        //���ڳ����жϺϷ�����  ����ѧ�ź���ѧ�����Ƿ���ϣ���������ϣ���������
        if (get_date_of_id(this->id)!=date_of_admission.substr(0, 4)) {
            cout<<endl<<endl;
            cout<<"           ===================================================================="<<endl;
            cout<<"           =================���棡���������ѧ���ں�ѧ�Ų�����============="<<endl;
            cout<<"           ===================================================================="<<endl;
            cout<<endl<<endl;
        }
        this->date_of_admission=date_of_admission;
        cout<<"��ѧ����¼��ɹ�!!"<<endl;
        return true;
    } else {
        cout<<"��ѧ���ڲ��Ϸ�,�����ԣ���"<<endl;
        cout<<endl<<endl;
        cout<<"           ===================================================================="<<endl;
        cout<<"           =================��ѧ����¼��ʧ�ܣ�������¼��ѧ����Ϣ����============="<<endl;
        cout<<"           ===================================================================="<<endl;
        cout<<endl<<endl;
        return true;
    }
}


//��ͥ��ַ
bool student::get_address_home() {
    bool ans=false;
    string code, detail;
    show_china_address();
    cout<<endl<<"��ѡ���ͥ��ַ��Ӧ�����������룺";
    cin>>code;
    cout<<"������ϸ��ַ:";
    cin>>detail;
    FILE *fp;
    fp=::fopen("../China_address.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //���ϵ�һ��һ�ж����ַ�����
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==code) {
                //��������з�
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                this->address_home=string(line).substr(4)+detail;
                ans=true;
                cout<<"��ͥ��ַ¼��ɹ�"<<"���ѡ��Ϊ:"<<this->address_home<<endl;
                break;
            }
        }
    }
    ::fclose(fp);
    return ans;
}


//��Դ��
bool student::get_address_study() {
    bool ans=false;
    string code, detail;
    show_china_address();
    cout<<endl<<"��ѡ����Դ�ض�Ӧ�����������룺";
    cin>>code;
    cout<<"������ϸ��ַ:";
    cin>>detail;
    FILE *fp;
    fp=::fopen("../China_address.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //���ϵ�һ��һ�ж����ַ�����
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==code) {
                //��������з�
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                this->address_study=string(line).substr(4)+detail;
                ans=true;
                cout<<"��Դ��¼��ɹ�"<<"���ѡ��Ϊ:"<<this->address_study<<endl;
                break;
            }
        }
    }
    ::fclose(fp);
    return ans;
}


//��ͥ��ϵ����Ϣ
bool student::get_family_phone_number() {
    string family;
    string phone_number;
    cout<<"������һ����������:";
    cin>>family;
    cout<<"��˼��˵ĵ绰����:";
    cin>>phone_number;
    string family_phone_number=family+"_"+phone_number;
    this->family_phone_number=family_phone_number;
    return true;
}


bool student::get_major() {
    //���ݲ�ͬ��ѧԺ��ʾ��ͬ��רҵ
    if (this->college=="�����������Զ���ѧԺ") {
        file_major("../dianqi.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../dianqi.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //���ϵ�һ��һ�ж����ַ�����
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //��������з�
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //��ȡ���ҵ�ֵ
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"רҵ¼��ɹ�"<<"���ѡ��Ϊ:"<<this->major<<endl;
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
    if (this->college=="��е���̼��Զ���ѧԺ") {
        file_major("../jixie.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../jixie.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //���ϵ�һ��һ�ж����ַ�����
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //��������з�
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //��ȡ���ҵ�ֵ
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"רҵ¼��ɹ�"<<"���ѡ��Ϊ:"<<this->major<<endl;
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
    if (this->college=="��ѧ��ͳ��ѧԺ") {
        file_major("../shuxeu.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../shuxue.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //���ϵ�һ��һ�ж����ַ�����
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //��������з�
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //��ȡ���ҵ�ֵ
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"רҵ¼��ɹ�"<<"���ѡ��Ϊ:"<<this->major<<endl;
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
    if (this->college=="ʯ�ͻ���ѧԺ") {
        file_major("../shiyou.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../shiyou.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //���ϵ�һ��һ�ж����ַ�����
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //��������з�
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //��ȡ���ҵ�ֵ
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"רҵ¼��ɹ�"<<"���ѡ��Ϊ:"<<this->major<<endl;
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
    if (this->college=="��ľ����ѧԺ") {
        file_major("../tumu.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../tumu.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //���ϵ�һ��һ�ж����ַ�����
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //��������з�
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //��ȡ���ҵ�ֵ
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"רҵ¼��ɹ�"<<"���ѡ��Ϊ:"<<this->major<<endl;
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
    if (this->college=="�����밲ȫ����ѧԺ") {
        file_major("../huanan.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../huanan.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //���ϵ�һ��һ�ж����ַ�����
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //��������з�
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //��ȡ���ҵ�ֵ
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"רҵ¼��ɹ�"<<"���ѡ��Ϊ:"<<this->major<<endl;
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
    if (this->college=="���������ѧԺ") {
        file_major("../jingguan.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../jingguan.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //���ϵ�һ��һ�ж����ַ�����
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //��������з�
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //��ȡ���ҵ�ֵ
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"רҵ¼��ɹ�"<<"���ѡ��Ϊ:"<<this->major<<endl;
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
    if (this->college=="�����ѧ�빤��ѧԺ") {
        file_major("../shengwu.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../shengwu.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //���ϵ�һ��һ�ж����ַ�����
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //��������з�
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //��ȡ���ҵ�ֵ
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"רҵ¼��ɹ�"<<"���ѡ��Ϊ:"<<this->major<<endl;
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
    if (this->college=="�����ѧԺ") {
        file_major("../waiyu.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../waiyu.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //���ϵ�һ��һ�ж����ַ�����
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //��������з�
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //��ȡ���ҵ�ֵ
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"רҵ¼��ɹ�"<<"���ѡ��Ϊ:"<<this->major<<endl;
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
    if (this->college=="������������ѧԺ") {
        file_major("../jisuanji.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../jisuanji.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //���ϵ�һ��һ�ж����ַ�����
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //��������з�
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //��ȡ���ҵ�ֵ
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"רҵ¼��ɹ�"<<"���ѡ��Ϊ:"<<this->major<<endl;
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
    if (this->college=="��������Ϣ����ѧԺ��΢����ѧԺ") {
        file_major("../wuxin.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../wuxin.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //���ϵ�һ��һ�ж����ַ�����
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //��������з�
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //��ȡ���ҵ�ֵ
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"רҵ¼��ɹ�"<<"���ѡ��Ϊ:"<<this->major<<endl;
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
    if (this->college=="��ѧѧԺ") {
        file_major("../huaxue.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../huaxue.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //���ϵ�һ��һ�ж����ַ�����
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //��������з�
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //��ȡ���ҵ�ֵ
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"רҵ¼��ɹ�"<<"���ѡ��Ϊ:"<<this->major<<endl;
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
    if (this->college=="���������滮ѧԺ") {
        file_major("../jianzhu.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../jianzhu.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //���ϵ�һ��һ�ж����ַ�����
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //��������з�
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //��ȡ���ҵ�ֵ
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"רҵ¼��ɹ�"<<"���ѡ��Ϊ:"<<this->major<<endl;
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
    if (this->college=="�Ͻ�������ҵѧԺ") {
        file_major("../zijin.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../zijin.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //���ϵ�һ��һ�ж����ַ�����
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //��������з�
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //��ȡ���ҵ�ֵ
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"רҵ¼��ɹ�"<<"���ѡ��Ϊ:"<<this->major<<endl;
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
    if (this->college=="���Ͽ�ѧ�빤��ѧԺ") {
        file_major("../cailiao.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../cailiao.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //���ϵ�һ��һ�ж����ַ�����
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //��������з�
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //��ȡ���ҵ�ֵ
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"רҵ¼��ɹ�"<<"���ѡ��Ϊ:"<<this->major<<endl;
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
    if (this->college=="��ѧԺ") {
        file_major("../faxue.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../faxue.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //���ϵ�һ��һ�ж����ַ�����
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //��������з�
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //��ȡ���ҵ�ֵ
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"רҵ¼��ɹ�"<<"���ѡ��Ϊ:"<<this->major<<endl;
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
    if (this->college=="������������ѧԺ") {
        file_major("../jisuanji.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../jisuanji.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //���ϵ�һ��һ�ж����ַ�����
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //��������з�
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //��ȡ���ҵ�ֵ
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"רҵ¼��ɹ�"<<"���ѡ��Ϊ:"<<this->major<<endl;
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
    if (this->college=="����ѧԺ") {
//meww
    }
    if (this->college=="��������ѧѧԺ") {

        file_major("../renwen.txt");
        bool ans=false;
        string code;
        cin>>code;
        FILE *fp=fopen("../renwen.txt", "r");
        if (fp!=nullptr) {
            char line[1024];
            //���ϵ�һ��һ�ж����ַ�����
            while (true) {
                if (fgets(line, sizeof(line), fp)!=nullptr) {
                    if (string(line).substr(1, 2)==code) {
                        //��������з�
                        char *ch=strchr(line, '\n');
                        if (ch!=nullptr) {
                            *ch='\0';
                        }
                        //��ȡ���ҵ�ֵ
                        this->major=string(line).substr(5);
                        ans=true;
                        cout<<"רҵ¼��ɹ�"<<"���ѡ��Ϊ:"<<this->major<<endl;
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
    if (this->college=="÷Ŭ˹���ʹ���ѧԺ") {

    }
    if (this->college=="�Ƚ�����ѧԺ") {

    }
}

//-------------------------��ȡ��Ϣ����---------------------
//------------------------��ʾ��Ȩʱ��----------------------
//��ʾʱ����ʾ��Ȩ�Ĳ˵�
void show_copyright() {
    cout<<endl<<"    ---Copyright---(c++) 2023-2023 �ο���(222200231). All Rights Reserved.---    ";
    cout<<endl<<endl<<"                    ���ݴ�ѧ(��У)ѧ����Ϣ����ϵͳ    ";
    cout<<endl;
    show_time();
    cout<<endl;
}

void show_time() {
    string week[7]={"������", "����һ", "���ڶ�", "������", "������", "������", "������"};
    SYSTEMTIME now2;
    GetLocalTime(&now2);
    time_t now=time(0);
    tm *ltm=localtime(&now);
    cout<<endl<<"        ��ǰ���ڡ�ʱ�� :"<<ltm->tm_year+1900<<"."<<1+ltm->tm_mon<<"."<<ltm->tm_mday<<" "<<ltm->tm_hour
        <<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<"("<<week[now2.wDayOfWeek]<<") "<<endl;
}
//----------------------��ʾ��Ȩʱ�����--------------------------


//----------------------��ʾ�˵�--------------
//��ʾ�ܲ˵�
void show_demo() {
    show_copyright();
    cout<<"      *                    A:¼��ѧ����Ϣ                    *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    B:��ѯѧ����Ϣ                    *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    C:ɾ��ѧ����Ϣ                    *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    D:�޸�ѧ����Ϣ                    *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    E:ͳ��ѧ����Ϣ                    *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    F:����ѧ����Ϣ                    *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    Q:�˳�ϵͳ                        *"<<endl;
    cout<<"������ѡ�";
}

//��ʾ����Ĳ˵�
void show_sort_demo() {
    show_copyright();
    cout<<"            *             A:���������С ��С��������              *"<<endl;
    cout<<"            *                                                      *"<<endl;
    cout<<"            *             B:���������С �Ӵ�С����              *"<<endl;
    cout<<"            *                                                      *"<<endl;
    cout<<"            *             C:����ѧ�Ŵ�С ��С��������              *"<<endl;
    cout<<"            *                                                      *"<<endl;
    cout<<"            *             D:����ѧ�Ŵ�С �Ӵ�С����              *"<<endl;
    cout<<"            *                                                      *"<<endl;


    cout<<"            *             Q:������һ���˵�                         *"<<endl;
    cout<<"������ѡ�";


}

//�������Ըĳ��׳��쳣
void show_switch_error() {
    cout<<endl;
    cout<<"       =====�޴�ѡ�������������ѡ���====="<<endl;
    cout<<endl;
    system("pause");
}

//ɾ����Ϣ��ѯ�˵�
void show_delete_demos() {
    show_copyright();
    cout<<"      *                    A:����ѧ��ɾ��                    *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    B:����רҵ���꼶ɾ��              *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    Q:������һ���˵�                  *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"������ѡ�"<<endl;
}


//ɾ���޸Ĳ�ѯ�˵�
void show_change_demos() {
    show_copyright();
    cout<<"               --��¼�������޸ĵ�ͬѧ--"<<endl;
    cout<<"                   *[1]ѧ��     "<<endl;
    cout<<endl;
    cout<<"                   *[2]����     "<<endl;
    cout<<endl;
    cout<<"                   *[3]���֤��  "<<endl;
    cout<<endl;
    cout<<"                   ��������Ҫ¼���ѡ�"<<endl;
}

//ɾ��ͳ�Ʋ�ѯ�˵�
void show_statistics_demos() {
    show_copyright();
    cout<<"                   ---��¼������ͳ�Ƶ���Ϣ--"<<endl;
    cout<<"                   *[A]ͳ���꼶��ѧԺ��������ò     "<<endl;
    cout<<endl;
    cout<<"                   *[B]ͳ���꼶��רҵ���Ա�     "<<endl;
    cout<<endl;
    cout<<"                   *[C]ͳ���꼶��רҵ�ͽ���ˮƽ     "<<endl;
    cout<<endl;
    cout<<"                   *[Q]������һ���˵�     "<<endl;
    cout<<endl;
    cout<<"                   ��������Ҫͳ�Ƶ�ѡ�"<<endl;
}

//�޸ĵ���Ϣ
void show_change_information_demos() {
    show_copyright();
    cout<<"               --��¼�������޸ĵ���Ϣ--"<<endl;
    cout<<"                   *[1]ѧ��     "<<endl;
    cout<<endl;
    cout<<"                   *[2]����     "<<endl;
    cout<<endl;
    cout<<"                   *[3]�Ա�  "<<endl;
    cout<<endl;
    cout<<"                   *[4]���֤��     "<<endl;
    cout<<endl;
    cout<<"                   *[5]������ò     "<<endl;
    cout<<endl;
    cout<<"                   *[6]ѧԺ  "<<endl;
    cout<<endl;
    cout<<"                   *[7]רҵ     "<<endl;
    cout<<endl;
    cout<<"                   *[8]�༶��     "<<endl;
    cout<<endl;
    cout<<"                   *[9]����Ա  "<<endl;
    cout<<endl;
    cout<<"                   *[10]ѧ��     "<<endl;
    cout<<endl;
    cout<<"                   *[11]��������     "<<endl;
    cout<<endl;
    cout<<"                   *[12]��ѧ����  "<<endl;
    cout<<endl;
    cout<<"                   *[13]����  "<<endl;
    cout<<endl;
    cout<<"                   *[14]����  "<<endl;
    cout<<endl;
    cout<<"                   *[15]����ˮƽ "<<endl;
    cout<<endl;
    cout<<"                   *[16]����״�� "<<endl;
    cout<<endl;
    cout<<"                   *[17]ѧ����� "<<endl;
    cout<<endl;
    cout<<"                   *[18]��ͥ��ַ "<<endl;
    cout<<endl;
    cout<<"                   *[19]��Դ�� "<<endl;
    cout<<endl;
    cout<<"                   *[20]��ͥ��ϵ�˼���ϵ��ʽ "<<endl;
    cout<<endl;
    cout<<"                   *[21]��ѧ��ʽ "<<endl;
    cout<<endl;
    cout<<"                   ��������Ҫ�޸ĵ���Ϣ��"<<endl;
}


//�����Ϣ��ѯ�˵�
void show_find_demos() {
    show_copyright();
    cout<<"      *                    A:����רҵ���Ա��ѯ              *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    B:����ѧԺ��������ò��ѯ          *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    C:����ѧԺ���Ա��ѯ              *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    D:����ѧԺ��ѧ��ʽ��ѯ            *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    E:����ѧԺ�͹��Ҳ�ѯ              *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    F:����ѧԺ�ͽ���ˮƽ��ѯ          *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    Q:������һ���˵�                  *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"������ѡ�"<<endl;
}

//ʾ���ҵĲ˵�
void show_find_demo() {
    show_copyright();
    cout<<"      *                    A:����ѧ�Ų�ѯ                    *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    B:����������ѯ                    *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    C:�����Ա��ѯ                    *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    D:����ѧԺ��ѯ                    *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    E:����רҵ��ѯ                    *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    F:�������֤�Ų�ѯ                *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    G:���ݻ���״����ѯ                *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    H:����������ò��ѯ                *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    I:���ݸ���Ա��ѯ                  *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    J:�����Ϣ��ѯ                    *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"      *                    Q:������һ���˵�                  *"<<endl;
    cout<<"      *                                                      *"<<endl;
    cout<<"������ѡ�"<<endl;
}
//----------------------��ʾ�˵�-------------------��-��--------------





//-------------------------------------�ļ�����--------------------------
//��ʾ�����
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
        }//ɾ�����з�
        cout<<line<<"\t";
        cnt++;
        if (cnt%5==0)cout<<endl;
    }
    cout<<endl<<"��ѡ���Ӧ��������룺";
}


//����ѧԺ������ʾ��Ӧ�ĸ���Ա
void show_counselor(string code) {
    FILE *fp;
    fp=fopen("../Counselor.txt", "r");
    if (fp==nullptr) { cout<<"Failed to open file.\n"; }
    char line[1024];
    int cnt=0;
    while (fgets(line, sizeof(line), fp)!=nullptr) {
        if (string(line).substr(1, 2)==code) {
            //�ҵ���Ӧ��ѧԺ��
            char *pos=strchr(line, '\n');
            if (pos!=nullptr) {
                *pos='\0';
            }//ɾ�����з�
            cout<<string(line).substr(4, 10)<<endl;
            cnt++;
        }
    }
    cout<<endl<<"��ѡ���Ӧ�ĸ���Ա���룺";
    ::fclose(fp);
}

//��ʾѧԺ��
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
        }//ɾ�����з�
        cout<<line<<endl;
    }
    cout<<endl<<"��ѡ���Ӧ��ѧԺ���룺";
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
        }//ɾ�����з�
        cout<<line<<endl;
    }
    cout<<endl<<"��ѡ���Ӧ�Ļ���״�����룺";
}

//��ʾ������ò�Ĳ˵�
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
        }//ɾ�����з�
        cout<<line<<endl;
    }
    cout<<endl<<"��ѡ���Ӧ��������ò���룺";
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
        }//ɾ�����з�
        cout<<setw(50)<<left<<line;
        if (cnt%2==0)cout<<endl;
        cnt++;

    }
    cout<<endl<<"��ѡ���Ӧ�Ĺ��Ҵ���(press enter to use default CHINA)��";
}

//��ʾѧ�����
void show_studenttype() {
    FILE *fp;
    fp=fopen("../Studenttype.txt", "r");
    if (fp==nullptr) { cout<<"Failed to open file.\n"; }
    char line[1024];
    while (fgets(line, sizeof(line), fp)!=nullptr) {
        char *pos=strchr(line, '\n');
        if (pos!=nullptr) {
            *pos='\0';
        }//ɾ�����з�
        cout<<line<<endl;
    }
    cout<<endl<<"��ѡ���Ӧ����ѧ��ʽ���룺";
}

//��ʾ����ˮƽ
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
        }//ɾ�����з�
        cout<<setw(30)<<left<<line;
        cnt++;
        if (cnt%3==0)cout<<endl;
    }
    cout<<endl<<"��ѡ���Ӧ�Ľ���ˮƽ���룺";
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
        }//ɾ�����з�
        cout<<line<<endl;
        cnt++;
    }
}

//��ʾ��ѧ��ʽ�Ĳ˵�
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
        }//ɾ�����з�
        cout<<line<<endl;
        cnt++;
    }
    cout<<endl<<"��ѡ���Ӧ����ѧ��ʽˮƽ���룺";
}
//-------------------------------------�ļ���������--------------------------



//-------------------------------------�����������--------------------------
//�����������
bool check_date_of_birth(string date_of_birth) {
    int year, month, day;
    if(check_format_date(date_of_birth))
    {
        get_date_of_int(date_of_birth, year, month, day);
        if (is_valid_date(year, month, day)) {
            if (check_limit_date_of_birth(year)) {
                return true;
            } else {
                cout<<"δ������ѧ���䣬��ѧ������Ҫ��12-62��֮�䣡"<<endl;
                return false;
            }
        } else {
            cout<<"�����ڲ��Ϸ���"<<endl;
            return false;
        }
    }
    else{
        cout<<"�����ڵĸ�ʽ���Ϸ���"<<endl;
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
//��������Ƿ�Ϸ�����ѧ�·��Ƿ���8-10��������������ʾ
bool check_date_of_admission(string date_of_birth) {
    int year, month, day;
    //��ȡ��ǰ��ݣ�����ѧ����������ڣ����Ϸ�
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
                    cout<<"��ѧ���Ӧ�ò����ڽ���!!"<<endl;
                }
            } else {
                cout<<"��ѧ�·�Ӧ��ΪΪ8=<�·�<=10����"<<endl;
            }
        } else {
            cout<<"���ڲ��Ϸ� ! !"<<endl;
            return false;
        }
    }
    else{
        cout<<"���ڸ�ʽ���Ϸ� ! !"<<endl;
        return false;
    }
}

//���������Ƿ�Ϸ�
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


//���str1����str2,����true
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


//����
bool is_leaf(int year) {
    return year%4==0&&(year%100!=0||year%400==0);
}

//��1997��05.19�õ�1997��5��19
void get_date_of_int(string date, int &year, int &month, int &day) {
    year=stoi(date.substr(0, 4));
    month=stoi(date.substr(5, 2));
    day=stoi(date.substr(8, 2));
}

//����Ƿ���������ѧ����
bool check_limit_date_of_birth(int year) {
    auto now=std::chrono::system_clock::now();
    std::time_t current_time=std::chrono::system_clock::to_time_t(now);
    std::tm local_time=*std::localtime(&current_time);
    int current_year=local_time.tm_year+1900;
    //��ѧ������Ҫ��12-62��֮��
    //����2023-12+1=2012��2012-12���������
    if (current_year-62+1<=year&&year<=current_year-12+1)return true;
    else return false;
}


//�����ѧ�����Ƿ�����
bool check_limit_date_of_admission(int year, int month, int day) {
    if (8<=month&&month<=10) {
        return true;
    } else {
        return false;
    }
}

//-------------------------------------����������ڽ���--------------------------
//-------------------------------------����ѧ��--------------------------------
bool check_id(string id, student students[]) {
    if (!check_len_id(id)) {
        cout<<"ѧ�ų������󣡣�Ӧ��Ϊ9λѧ�ţ���"<<endl;
        return false;
    } else if (!check_college_id(id)) {
        cout<<"ѧ��ѧԺ�������󣡣�"<<endl;
        return false;
    } else if (!check_id_repeat(id, students)) {
        //�������ļ���û�ҵ���ͬ�ķ���true���ҵ���ͬ�ķ���false
        cout<<"��ѧ���Ѿ����ڣ���"<<endl;
        return false;
    } else if (!check_id_digit(id)) {
        cout<<"��ѧ�ű��������ֹ��ɣ���"<<endl;
        return false;
    } else if (!check_class_id(id)) {
        cout<<"��ѧ�ŵİ༶�ų��ִ��󣡣�"<<endl;
        return false;
    } else if (!check_back_id(id)) {
        cout<<"��ѧ�ŵ������λ���ִ��󣡣�"<<endl;
        return false;
    } else {
        if (!check_grade_id(id)) {
            cout<<endl<<endl;
            cout<<"           ===================================================================="<<endl;
            cout<<"           =================���棡�������ѧ�ź͵�ǰ��ݲ�����============="<<endl;
            cout<<"           ===================================================================="<<endl;
            cout<<endl<<endl;
        }
        return true;
    }
}

//���ѧ���Ƿ�������
bool check_id_digit(string id) {
    for (int i=0; i<id.length(); i++) {
        //����з����֣�ֱ�ӷ���false
        if (!isdigit(id[i])) {
            return false;
        }
    }
    return true;
}

//���ѧ��λ��
bool check_len_id(string id) {
    if (id.length()==9)return true;
    return false;
}

//���ѧ���еİ༶��
bool check_class_id(string id) {
    string college=(id.substr(0, 2));
    //ѧԺΪ��Щ��ѧ�ţ�222200231��567λΪ�༶��
    if (college=="06"||college=="08"||college=="09"||college=="15"||college=="18"||college=="19"||college=="22"||
        college=="29") {
        string class_id=id.substr(4, 3);
        if (class_id=="001"||class_id=="002"||class_id=="003"||class_id=="004"||class_id=="005"||class_id=="006"||
            class_id=="007"||class_id=="008") {
            //��ȷ
            return true;
        } else {
            return false;
        }
    } else {
//ѧԺΪ��Щ��ѧ�ţ�56λΪ�༶��
        string class_id=id.substr(4, 2);
        if (class_id=="01"||class_id=="02"||class_id=="03"||class_id=="04"||class_id=="05"||class_id=="06"||
            class_id=="07"||class_id=="08") {
            //��ȷ
            return true;
        } else {
            return false;
        }
    }
}

//���ѧ�ź���λ
bool check_back_id(string id) {
    //222200231
    int college=stoi(id.substr(7, 2));
    if (college>80) {
        //�༶�������ᳬ��80��
        return false;
    } else {
        return true;
    }
}

//�������ļ���û�ҵ���ͬ�ķ���true���ҵ���ͬ�ķ���false
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

//���ǰ��λѧԺ
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

//���ǰ����λ�꼶
bool check_grade_id(string id) {
    //��ȡ��ǰ���
    time_t now=time(0);
    tm *ltm=localtime(&now);
    int now_year=ltm->tm_year+1900;
    int year_number=stoi(id.substr(2, 2));
    year_number+=2000;
    if (now_year==year_number)return true;
    return false;
}

//-------------------------------------����ѧ�Ž���-----------------
//-------------------------------------���֤�ŵļ���------------------------
//�������֤��
bool check_id_number(string id_number) {
    if (!check_len_of_idnumber(id_number)) {
        cout<<"���֤�ų��ȴ���"<<endl;
        return false;
    } else if (!check_digit_of_idnumber(id_number)) {
        cout<<"���֤ǰ17λ����"<<endl;
        return false;
    } else if (!check_region_of_idnumber(id_number)) {
        cout<<"���������"<<endl;
        return false;
    } else if (!check_checkcode_of_idnumber(id_number)) {
        cout<<"���֤����У�����"<<endl;
        return false;
    }
    return true;
}

//�������֤�ŵ�˳���룬��������true����,ż������falseŮ��
bool check_gender_of_idnumber(string id_number) {
    int order=stoi(id_number.substr(16, 1));
    if (order%2==0)return false;
    else return true;
}

//�������֤�ŵ�У����
bool check_checkcode_of_idnumber(string id_number) {
    int weight[]={7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char check_code[]={'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    int sum=0;
    //����У����,string[i]�õ������ַ�����
    for (int i=0; i<17; i++) {
        sum+=(id_number[i]-'0')*weight[i];
    }
    int remainder=sum%11;
    //�ж����һλУ�����Ƿ���ȷ
    if (id_number[17]==check_code[remainder]) {
        return true;
    } else {
        return false;
    }
}

//�������֤�ĳ���
bool check_len_of_idnumber(string id_number) {
    if (id_number.length()!=18) {
        cout<<"���֤������������Ӧ��Ϊ18λ"<<endl;
        return false;
    } else return true;
}

//������֤������ĵ�����
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

//�������֤��ǰʮ��λ�Ƿ�������
bool check_digit_of_idnumber(string id_number) {
    for (int i=0; i<17; i++) {
        if (!isdigit(id_number[i])) {
            return false;
        }
    }
    return true;
}

//���֤�ŷ��س�������35062720040724  2004.07.24
string get_birth_of_id_number(string id_number) {
    string date_of_birth=id_number.substr(6, 4)+'.'+id_number.substr(10, 2)+'.'+id_number.substr(12, 2);
    return date_of_birth;
}

//----------------------------------------���֤�ŵļ������------------------------

//��ѧ�Ż�ȡ�꼶
string get_date_of_id(string id) {
    string date_of_admission=id.substr(2, 2);
    return "20"+date_of_admission;
}


//���Ϸ�����false
bool check_name(string name, string nation) {
    int len=name.length();
    //�й��˵��������
    if (nation=="�й�") {
        if (hasNonChinese(name)) {
            cout<<"�й������ֲ��Ϸ�����";
            return false;
        }
        if (len>40||len<4) {
            cout<<"����Ϊ2-20�����֣����ֲ��Ϸ�����";
            return false;
        }
    }
    if (hasChinese(name)&&hasNonChinese(name)) {
        cout<<"ͬʱ�������ĺ����������ֲ��Ϸ�����";
        return false;
    }
    if (has_digit(name)) {
        cout<<"�����������ֲ��Ϸ�����";
        return false;
    }
    //��������
    if (len>40&&nation!="�й�") {
        cout<<"�������Ȳ�����40���ַ������ֲ��Ϸ�����";
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


//�ж��Ƿ�������
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


//�ж��Ƿ��г�������������ַ�
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
    if (gender=="��"||gender=="Ů") {
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
        cout<<endl<<"��ѧ����Ϣ¼��ɹ�����"<<endl;
        students[cnt++]=student;
        add_data_to_file(student);
        //��һ��������д���ļ�
    } else {
        cout<<endl<<"��ѧ����Ϣ�д���������"<<endl;
    }
    system("pause");
    system("cls");
}

//��һ��������д���ļ�
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

//��һ������������ȫ��д���ļ�
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


//--------------------------��ѯ����---------------------------------
void find_by_id(student students[]) {
    int find_int=0;
    string id;
    cout<<"������Ҫ��ѯ��ѧ��:";
    cin>>id;
    for (int i=1; i<=cnt; i++) {
        if (students[i].id==id) {
            find_int++;
            students[i].show_info();
            system("pause");
        }
    }
    if (!find_int) {
        cout<<"�Բ��𣬲�ѯ��������Ϣ�������³��ԣ���";
    }
}

void find_by_name(student students[]) {
    int find_int=0;
    string name;
    cout<<"������Ҫ��ѯ������:";
    cin>>name;
    for (int i=1; i<=cnt; i++) {
        if (students[i].name==name) {
            find_int++;
            students[i].show_info();
            system("pause");
        }
    }
    if (!find_int) {
        cout<<"�Բ��𣬲�ѯ��������Ϣ�������³��ԣ���";
    }
}

void find_by_gender(student students[]) {
    int find_int=0;
    string gender;
    string code;
    cout<<"      *                         [1]��                         *"<<endl
        <<"      *                                                       *"<<endl
        <<"      *                         [2]Ů                         *"<<endl;
    cout<<"������Ҫ��ѯ���Ա����:";
    cin>>code;
    if (code=="1") {
        gender="��";
    }
    if (code=="2") {
        gender="Ů";
    }
    for (int i=1; i<=cnt; i++) {
        if (students[i].gender==gender) {
            find_int++;
            students[i].show_info();
            system("pause");
        }
    }
    if (!find_int) {
        cout<<"�Բ��𣬲�ѯ��������Ϣ�������³��ԣ���";
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
        //���ϵ�һ��һ�ж����ַ�����
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==code) {
                //��������з�
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //��ȡѧԺ��ֵ
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
        cout<<"�Բ��𣬲�ѯ��������Ϣ�������³��ԣ���";
    }

}


void find_by_major(student students[]) {
    int find_int=0;
    string major;
    cout<<"������Ҫ��ѯ��רҵ:";
    cin>>major;
    for (int i=1; i<=cnt; i++) {
        if (students[i].major==major) {
            find_int++;
            students[i].show_info();
            system("pause");
        }
    }
    if (!find_int) {
        cout<<"�Բ��𣬲�ѯ��������Ϣ�������³��ԣ���";
    }
}

void find_by_id_number(student students[]) {
    int find_int=0;
    string id_number;
    cout<<"������Ҫ��ѯ�����֤��:";
    cin>>id_number;
    for (int i=1; i<=cnt; i++) {
        if (students[i].id_number==id_number) {
            find_int++;
            students[i].show_info();
            system("pause");
        }
    }
    if (!find_int) {
        cout<<"�Բ��𣬲�ѯ��������Ϣ�������³��ԣ���";
    }
}

void find_by_marriage(student students[]) {
    int find_int=0;
    string marriage;
    string code;
    show_marriage();
    cout<<"������Ҫ��ѯ�Ļ���״������:";
    cin>>code;
    FILE *fp;
    fp=::fopen("../Marriage.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //���ϵ�һ��һ�ж����ַ�����
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==code) {
                //��������з�
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //��ȡѧԺ��ֵ
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
        cout<<"�Բ��𣬲�ѯ��������Ϣ�������³��ԣ���";
    }
}


void find_by_political(student students[]) {
    int find_int=0;
    string political;
    string code;
    show_political();
    cout<<"������Ҫ��ѯ��������ò:";
    cin>>code;
    FILE *fp;
    fp=::fopen("../Political.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //���ϵ�һ��һ�ж����ַ�����
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==code) {
                //��������з�
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //��ȡѧԺ��ֵ
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
        cout<<"�Բ��𣬲�ѯ��������Ϣ�������³��ԣ���";
    }
}

void find_by_counselor(student students[]) {
    int find_int=0;
    string counselor;
    cout<<"������Ҫ��ѯ�ĸ���Ա:";
    cin>>counselor;
    for (int i=1; i<=cnt; i++) {
        if (students[i].counselor==counselor) {
            find_int++;
            students[i].show_info();
            system("pause");
        }
    }
    if (!find_int) {
        cout<<"�Բ��𣬲�ѯ��������Ϣ�������³��ԣ���";
    }
}

//--------------------��ѯ------����--------------------------------
//--------------------��ѯ------�����Ϣ---------------------------------
void find_by_major_gender(student students[]) {
    int find_int=0;
    string counselor;
    cout<<"������Ҫ��ѯ�ĸ���Ա:";
    cin>>counselor;
    for (int i=1; i<=cnt; i++) {
        if (students[i].counselor==counselor) {
            find_int++;
            students[i].show_info();
            system("pause");
        }
        if (!find_int) {
            cout<<"�Բ��𣬲�ѯ��������Ϣ�������³��ԣ���";
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
        //���ϵ�һ��һ�ж����ַ�����
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==college_code) {
                //��������з�
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //��ȡѧԺ��ֵ
                college=string(line).substr(5);
            }
        }
    }
    show_political();
    cin>>political_code;
    fp=::fopen("../Political.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //���ϵ�һ��һ�ж����ַ�����
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==political_code) {
                //��������з�
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //��ȡѧԺ��ֵ
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
        cout<<"�Բ��𣬲�ѯ��������Ϣ�������³��ԣ���";
    }

}

void find_by_college_gender(student students[]) {
    //��ѯ���ĸ���
    int find_int=0;
    string gender, college, gender_code, college_code;
    cout<<"      *                         [1]��                         *"<<endl
        <<"      *                                                       *"<<endl
        <<"      *                         [2]Ů                         *"<<endl;
    cout<<"������Ҫ��ѯ���Ա����:";
    cin>>gender_code;
    if (gender_code=="1") {
        gender="��";
    }
    if (gender_code=="2") {
        gender="Ů";
    }
    show_college();
    cin>>college_code;
    FILE *fp;
    fp=::fopen("../College.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //���ϵ�һ��һ�ж����ַ�����
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==college_code) {
                //��������з�
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //��ȡѧԺ��ֵ
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
        cout<<"�Բ��𣬲�ѯ��������Ϣ�������³��ԣ���";
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
        //���ϵ�һ��һ�ж����ַ�����
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==code_college) {
                //��������з�
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //��ȡѧԺ��ֵ
                college=string(line).substr(5);
            }
        }
    }
    string admisson;
    cout<<"������Ҫ��ѯ����ѧ��ʽ:";
    cin>>admisson;
    for (int i=1; i<=cnt; i++) {
        find_int++;
        if (students[i].college==college&&students[i].admisson==admisson) {
            students[i].show_info();
            system("pause");
        }
    }
    if (!find_int) {
        cout<<"�Բ��𣬲�ѯ��������Ϣ�������³��ԣ���";
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
        //���ϵ�һ��һ�ж����ַ�����
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==college_code) {
                //��������з�
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //��ȡѧԺ��ֵ
                college=string(line).substr(5);
            }
        }
    }
    show_nation();
    cin>>nation_code;
    fp=::fopen("../Nation.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //���ϵ�һ��һ�ж����ַ�����
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==nation_code) {
                //��������з�
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //��ȡ���ҵ�ֵ
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
        cout<<"�Բ��𣬲�ѯ��������Ϣ�������³��ԣ���";
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
        //���ϵ�һ��һ�ж����ַ�����
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==code_college) {
                //��������з�
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //��ȡѧԺ��ֵ
                college=string(line).substr(5);
            }
        }
    }
    int find_int=0;
    string education;
    cout<<"������Ҫ��ѯ�Ľ���ˮƽ:";
    cin>>education;
    for (int i=1; i<=cnt; i++) {
        if (students[i].college==college&&students[i].education==education) {
            find_int++;
            students[i].show_info();
            system("pause");
        }
    }
    if (!find_int) {
        cout<<"�Բ��𣬲�ѯ��������Ϣ�������³��ԣ���";
    }
}

//--------------------��ѯ------�����Ϣ----����-----------------------------
//--------------------ɾ��---------------------------------
//ɾ������ѧ��
void delete_student(student students[]) {
    //����ѧ��ɾ��
    string id;
    cout<<"������Ҫɾ����ѧ����ѧ��:";
    cin>>id;
    for (int i=1; i<=cnt; i++) {
        if (students[i].id==id) {
            //ɾ����i��ѧ��
            //���ǣ���ѧ����--
            for (int j=i; j<cnt; j++) {
                students[j]=students[j+1];
            }
            cnt--;
        }
    }
    add_datas_to_file(students);
    cout<<"ɾ��ѧ����"<<id<<"�ɹ�!!"<<endl;
}

void delete_students(student students[]) {
    //�����꼶��רҵɾ��
    string year;
    cout<<"������Ҫɾ����ѧ�����꼶(����2022):";
    cin>>year;
    string major;
    cout<<"������Ҫɾ����ѧ����רҵ:";
    cin>>major;
    cout<<"ȷ��ɾ��[Y]yes[N]no";
    string yes_no;
    cin>>yes_no;
    if (yes_no=="Y") {
        for (int i=1; i<=cnt; i++) {
            if (get_date_of_id(students[i].id)==year&&students[i].major==major) {
                //ɾ����i��ѧ��
                //���ǣ���ѧ����--
                cout<<get_date_of_id(students[i].id);
                for (int j=i; j<cnt; j++) {
                    students[j]=students[j+1];
                }
                cnt--;
            }
        }
        add_datas_to_file(students);
        cout<<"ɾ��ѧ��"<<year<<"��"<<major<<"ѧ���ɹ�����"<<endl;
    }else{
        cout<<"ɾ��ѧ��"<<year<<"��"<<major<<"ʧ�ܣ���"<<endl;
    }
}


//--------------------ɾ��--����-------------------------------

//--------------��ȡ�������ݵ�����������-------------------
void read_file(student *students) {
    cnt=0;//ÿ�����¶��붼��ѧ����������Ϊ0
    FILE *fp=::fopen("../students.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //���ϵ�һ��һ�ж���
        while (fgets(line, sizeof(line), fp)) {
            //��������з�
            char *ch=strchr(line, '\n');
            if (ch!=nullptr) { *ch='\0'; }
            string data=string(line);
            istringstream iss(data);
            string token;
            //��¼ÿ�����ݵĵڼ�������
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
        cout<<"¼��ѧ�ţ�";
        string id;
        cin>>id;
        cout<<"¼��ɹ�,ѧ��Ϊ��"<<id;
        int i=1;
        int j=0;
        for (i=1; i<=cnt; i++) {
            if (students[i].id==id) {
                find_int++;
                j=i;
            }
        }//i-1Ϊ��ѯ��ѧ�������
        if (!find_int) {
            cout<<"�Բ��𣬲�ѯ��������Ϣ�������³��ԣ���";
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
            cout<<"�޸���Ϣ�ɹ���";
        }
    } else if (code=="2") {
        int find_int=0;
        cout<<"¼��������";
        string name;
        cin>>name;
        cout<<"¼��ɹ�,����Ϊ��"<<name;
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
            cout<<"�Բ��𣬲�ѯ��������Ϣ�������³��ԣ���";
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
            cout<<"�޸���Ϣ�ɹ���";
        }
    } else if (code=="3") {
        int find_int=0;
        cout<<"¼�����֤�ţ�";
        string id_number;
        cin>>id_number;
        cout<<"¼��ɹ�,���֤��Ϊ��"<<id_number;
        int i=1;
        int j=0;
        for (i=1; i<=cnt; i++) {
            if (students[i].id_number==id_number) {
                find_int++;
                j=i;
                students[i].show_info();
            }
        }//iΪ��ѯ��ѧ�������
        i--;
        if (!find_int) {
            cout<<"�Բ��𣬲�ѯ��������Ϣ�������³��ԣ���";
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
            cout<<"�޸���Ϣ�ɹ���";
        }
    } else {
        show_switch_error();
    }
}

//-----------------����--���ұ������ļ�-----------------------------
void swap_student(student &student1, student &student2) {
    student temp=student1;
    student1=student2;
    student2=temp;
}

void sort_small(student students[]) {
    for (int i=1; i<cnt; i++) {
        for (int j=1; j<cnt-i; j++) {
            //���str1����str2,����true
            if (is_early(students[j].date_of_birth, students[j+1].date_of_birth)) {
                swap(students[j], students[j+1]);
            }
        }
    }
    add_datas_to_file(students);
    cout<<"���������С��������ɹ�����";
}

void sort_big(student students[]) {
    for (int i=1; i<cnt; i++) {
        for (int j=1; j<cnt-i; j++) {
            //���str1����str2,����true
            if (!is_early(students[j].date_of_birth, students[j+1].date_of_birth)) {
                swap(students[j], students[j+1]);
            }
        }
    }
    add_datas_to_file(students);
    cout<<"��������Ӵ�С����ɹ�����";
}

//����ѧ�ŴӴ�С����
void sort_big_id(student students[]) {
    for (int i=1; i<cnt; i++) {
        for (int j=1; j<cnt-i; j++) {
            if (stoi(students[j].id)<stoi(students[j+1].id)) {
                swap(students[j], students[j+1]);
            }
        }
    }
    add_datas_to_file(students);
    cout<<"����ѧ�ŴӴ�С����ɹ�����";
}

//����ѧ�Ŵ�С��������
void sort_small_id(student students[]) {
    for (int i=1; i<cnt; i++) {
        for (int j=1; j<cnt-i; j++) {
            if (stoi(students[j].id)>stoi(students[j+1].id)) {
                swap(students[j], students[j+1]);
            }
        }
    }
    add_datas_to_file(students);
    cout<<"����ѧ�Ŵ�С��������ɹ�����";
}


void statistics_grade_college_political(student students[]) {
    //ͳ���꼶��ѧԺ��������ò
    //������ͳ��15��������ò
    int find_int1=0, find_int2=0, find_int3=0, find_int4=0, find_int5=0, find_int6=0, find_int7=0, find_int8=0,
            find_int9=0, find_int10=0, find_int11=0, find_int12=0, find_int13=0, find_int14=0, find_int15=0;
    string college, code_college, grade;
    cout<<"��������Ҫͳ�Ƶ��꼶(����2023):";
    cin>>grade;

    show_college();
    cin>>code_college;
    FILE *fp;
    fp=::fopen("../College.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //���ϵ�һ��һ�ж����ַ�����
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==code_college) {
                //��������з�
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //��ȡѧԺ��ֵ
                college=string(line).substr(5);
            }
        }
    }
    for (int i=1; i<=cnt; i++) {
        if (students[i].college==college&&get_date_of_id(students[i].id)==grade&&
            students[i].political=="�й���������Ա") {
            find_int1++;
        }
        if (students[i].college==college&&get_date_of_id(students[i].id)==grade&&
            students[i].political=="�й�������Ԥ����Ա") {
            find_int2++;
        }
        if (students[i].college==college&&get_date_of_id(students[i].id)==grade&&
            students[i].political=="�й�����������������Ա") {
            find_int3++;
        }
        if (students[i].college==college&&get_date_of_id(students[i].id)==grade&&
            students[i].political=="�й����񵳸���ίԱ���Ա") {
            find_int4++;
        }
        if (students[i].college==college&&get_date_of_id(students[i].id)==grade&&
            students[i].political=="�й�����ͬ����Ա") {
            find_int5++;
        }
        if (students[i].college==college&&get_date_of_id(students[i].id)==grade&&
            students[i].political=="�й������������Ա") {
            find_int6++;
        }
        if (students[i].college==college&&get_date_of_id(students[i].id)==grade&&
            students[i].political=="�й������ٽ����Ա") {
            find_int7++;
        }
        if (students[i].college==college&&get_date_of_id(students[i].id)==grade&&
            students[i].political=="�й�ũ����������Ա") {
            find_int8++;
        }
        if (students[i].college==college&&get_date_of_id(students[i].id)==grade&&
            students[i].political=="�й��¹�����Ա") {
            find_int9++;
        }
        if (students[i].college==college&&get_date_of_id(students[i].id)==grade&&
            students[i].political=="����ѧ����Ա") {
            find_int10++;
        }
        if (students[i].college==college&&get_date_of_id(students[i].id)==grade&&
            students[i].political=="̨����������ͬ����Ա") {
            find_int11++;
        }
        if (students[i].college==college&&get_date_of_id(students[i].id)==grade&&
            students[i].political=="�޵���������ʿ") {
            find_int12++;
        }
        if (students[i].college==college&&get_date_of_id(students[i].id)==grade&&students[i].political=="Ⱥ��") {
            find_int13++;
        }
    }
    cout<<endl<<"                 ----------------------------------ͳ�ƽ��------------------------         "<<endl;
    cout<<"                                      "<<grade<<"��"<<college<<endl;
    cout<<"                               ������òΪ�й���������Ա"<<"��"<<"����["<<find_int1<<"]��"<<endl;
    cout<<"                               ������òΪ�й�������Ԥ����Ա"<<"��"<<"����["<<find_int2<<"]��"<<endl;
    cout<<"                               ������òΪ�й�����������������Ա"<<"��"<<"����["<<find_int3<<"]��"<<endl;
    cout<<"                               ������òΪ�й����񵳸���ίԱ���Ա"<<"��"<<"����["<<find_int4<<"]��"<<endl;
    cout<<"                               ������òΪ�й�����ͬ����Ա"<<"��"<<"����["<<find_int5<<"]��"<<endl;
    cout<<"                               ������òΪ�й������������Ա"<<"��"<<"����["<<find_int6<<"]��"<<endl;
    cout<<"                               ������òΪ�й������ٽ����Ա"<<"��"<<"����["<<find_int7<<"]��"<<endl;
    cout<<"                               ������òΪ�й�ũ����������Ա"<<"��"<<"����["<<find_int8<<"]��"<<endl;
    cout<<"                               ������òΪ�й��¹�����Ա"<<"��"<<"����["<<find_int9<<"]��"<<endl;
    cout<<"                               ������òΪ����ѧ����Ա"<<"��"<<"����["<<find_int10<<"]��"<<endl;
    cout<<"                               ������òΪ̨����������ͬ����Ա"<<"��"<<"����["<<find_int11<<"]��"<<endl;
    cout<<"                               ������òΪ�޵���������ʿ"<<"��"<<"����["<<find_int12<<"]��"<<endl;
    cout<<"                               ������òΪȺ��"<<"��"<<"����["<<find_int13<<"]��"<<endl;
}

void statistics_grade_college_gender(student students[]) {
    //ͳ���꼶��רҵ���Ա�
    //����
    int find_int1=0;
    //Ů��
    int find_int2=0;
    string college, code_college, grade;
    cout<<"��������Ҫͳ�Ƶ��꼶(����2023):";
    cin>>grade;
    show_college();
    cin>>code_college;
    FILE *fp;
    fp=::fopen("../College.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //���ϵ�һ��һ�ж����ַ�����
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==code_college) {
                //��������з�
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //��ȡѧԺ��ֵ
                college=string(line).substr(5);
            }
        }
    }
    cout<<"      *                         [1]��                         *"<<endl
        <<"      *                                                       *"<<endl
        <<"      *                         [2]Ů                         *"<<endl;
    for (int i=1; i<=cnt; i++) {
        if (students[i].college==college&&get_date_of_id(students[i].id)==grade&&students[i].gender=="��") {
            find_int1++;
        }
        if (students[i].college==college&&get_date_of_id(students[i].id)==grade&&students[i].gender=="Ů") {
            find_int2++;
        }
    }
    cout<<endl<<"                       ------------------------ͳ�ƽ��------------------------         "<<endl;
    cout<<"                               "<<grade<<"��"<<college<<"�Ա�Ϊ�е�"<<"����["<<find_int1<<"]��"<<endl;
    cout<<"                               "<<grade<<"��"<<college<<"�Ա�ΪŮ��"<<"����["<<find_int2<<"]��"<<endl;
}

void statistics_grade_college_education(student students[]) {
    //ͳ���꼶��ѧԺ�ͽ���ˮƽ
    int find_int=0;
    string college, code_college, grade, education_code, education;
    cout<<"��������Ҫͳ�Ƶ��꼶(����2023):";
    cin>>grade;
    show_college();
    cin>>code_college;
    FILE *fp;
    fp=::fopen("../College.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //���ϵ�һ��һ�ж����ַ�����
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==code_college) {
                //��������з�
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //��ȡѧԺ��ֵ
                college=string(line).substr(5);
            }
        }
    }
    show_education();
    cin>>education_code;
    fp=::fopen("../Education.txt", "r");
    if (fp!=nullptr) {
        char line[1024];
        //���ϵ�һ��һ�ж����ַ�����
        while (fgets(line, sizeof(line), fp)) {
            if (string(line).substr(1, 2)==education_code) {
                //��������з�
                char *ch=strchr(line, '\n');
                if (ch!=nullptr) {
                    *ch='\0';
                }
                //��ȡ���ҵ�ֵ
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
    cout<<endl<<"                       ------------------------ͳ�ƽ��------------------------         "<<endl;
    cout<<"                               "<<grade<<"��"<<college<<"����ˮƽΪ"<<education<<"��"<<"����["<<find_int
        <<"]��"<<endl;
}


