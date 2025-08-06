#include <iostream>
#include <string>
#include <algorithm>
#include<vector>
#include<fstream>
#include <sstream>
using namespace std;

const int MAX = 100;

struct Student {
    string id;
    string name;
    double chinese;
    double math;
    double english;
    double total;
};

class StudentManager {
private:
	vector<Student> students;
public:
    StudentManager() {

    }

    void addStudent() {
        Student temp;
        cout << "请输入学生id，姓名，语文，数学，英语成绩：" << endl;
        cin >> temp.id >> temp.name >> temp.chinese >> temp.math >> temp.english;
        temp.total = temp.chinese + temp.math + temp.english;
		students.push_back(temp);
        cout << "添加成功！当前总人数：" << students.size() << endl;
    }

    void showAllStudents() const {
        if (students.size() == 0) {
            cout << "当前没有学生信息。" << endl;
            return;
        }
        for (auto& student:students) {
            cout << "ID: " << student.id
                << ", 姓名: " << student.name
                << ", 语文: " << student.chinese
                << ", 数学: " << student.math
                << ", 英语: " << student.english
                << ", 总分: " << student.total << endl;
        }
    }

    void sortByTotal() {
       sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.total > b.total;
		   });
        cout << "已按总分降序排序。" << endl;
    }

    void searchStudent() const {
        string id;
        cout << "请输入要查找的学生id：" << endl;
        cin >> id;
        for (auto& student : students) {
            if (student.id == id) {
                cout << "找到学生信息：" << endl;
                cout << "ID: " << student.id
                    << ", 姓名: " << student.name
                    << ", 语文: " << student.chinese
                    << ", 数学: " << student.math
                    << ", 英语: " << student.english
                    << ", 总分: " << student.total << endl;
				return;
            }
        }
        cout << "查无此人！" << endl;
    }
    void saveToFile(const string& filename) const {
        ofstream fout(filename);
        for (auto& s : students) {
            fout << s.id << " "
                 << s.name << " "
                 << s.chinese << " "
                 << s.math << " "
                 << s.english << endl;
        }
		fout.close();
    }
    void loadFromFile(const string& filename) {
		ifstream fin(filename);
        if (!fin) {
            cout << "无法打开文件！" << endl;
            return;
        }
        students.clear();
        string line;
        while (getline(fin, line)) {
            istringstream iss(line);
			Student temp;
            iss >> temp.id >> temp.name >> temp.chinese >> temp.math >> temp.english;
            temp.total = temp.chinese + temp.math + temp.english;
			students.push_back(temp);
        }
        fin.close();
		cout << "数据加载成功！当前总人数：" << students.size() << endl;
    }
};
int main() {
    StudentManager manager;
    int choice;

    while (true) {
        cout << "\n==== 学生成绩管理系统 ====" << endl;
        cout << "1. 添加学生信息" << endl;
        cout << "2. 显示所有学生信息" << endl;
        cout << "3. 按总分排序" << endl;
        cout << "4. 查询学生（按学号）" << endl;
        cout << "5. 保存学生信息到文件" << endl;
        cout << "6. 从文件加载学生信息" << endl;
        cout << "7. 退出系统" << endl;
        cout << "请输入你的选择：";
        cin >> choice;

        switch (choice) {
        case 1: manager.addStudent(); break;
        case 2: manager.showAllStudents(); break;
        case 3: manager.sortByTotal(); break;
        case 4: manager.searchStudent(); break;
		case 5: manager.saveToFile("students.txt"); break;
		case 6: manager.loadFromFile("students.txt"); break;
        case 7: cout << "退出成功，感谢使用！" << endl; return 0;
        default: cout << "无效选项，请重新输入！" << endl;
        }
    }

    return 0;
}
