#include<iostream>
#include<string>
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
void Swap(Student& a, Student& b) {
	Student temp = a;
	a = b;
	b = temp;
}
void addStudent(Student student[], int& count);
void showAllStudents(const Student students[], int count);
void sortByTotal(Student students[], int count);
void searchStudent(const Student students[], int count);
int main() {
	Student students[MAX];
	int count = 0;
	int choice;

	while (true) {
		cout << "\n==== 学生成绩管理系统 ====" << endl;
		cout << "1. 添加学生信息" << endl;
		cout << "2. 显示所有学生信息" << endl;
		cout << "3. 按总分排序" << endl;
		cout << "4. 查询学生（按学号）" << endl;
		cout << "5. 退出系统" << endl;
		cout << "请输入你的选择：";
		cin >> choice;

		switch (choice) {
		case 1: addStudent(students, count); break;
		case 2: showAllStudents(students, count); break;
		case 3: sortByTotal(students, count); break;
		case 4: searchStudent(students, count); break;
		case 5: cout << "退出成功，感谢使用！" << endl; return 0;
		default: cout << "无效选项，请重新输入！" << endl;
		}
	}

	return 0;
}
void addStudent(Student student[], int& count) {
	Student temp;
	cout << "请输入学生id，姓名，语数英三科成绩" << endl;
	cin >> temp.id >> temp.name >> temp.chinese >> temp.math >> temp.english;
	temp.total = temp.chinese + temp.math + temp.english;
	student[count++] = temp;
}
void showAllStudents(const Student students[], int count) {
	for (int i = 0; i < count; i++) {
		cout << "ID: " << students[i].id << ", Name: " << students[i].name
			 << ", Chinese: " << students[i].chinese
			 << ", Math: " << students[i].math
			 << ", English: " << students[i].english
			 << ", Total: " << students[i].total << endl;
	}
}
void sortByTotal(Student students[], int count) {
	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			if (students[j].total < students[j + 1].total) {
				Swap(students[j], students[j + 1]);
			}
		}
	}
}
void searchStudent(const Student students[], int count) {
	string id;
	cout << "请输入要查找的学生id" << endl;
	cin >> id;
	for (int i = 0; i < count; i++) {
		if (students[i].id == id) {
			cout << "ID: " << students[i].id << ", Name: " << students[i].name
				 << ", Chinese: " << students[i].chinese
				 << ", Math: " << students[i].math
				 << ", English: " << students[i].english
				 << ", Total: " << students[i].total << endl;
			return;
		}
	}
	cout << "未找到学号为 " << id << " 的学生信息。" << endl;
}