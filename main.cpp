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
		cout << "\n==== ѧ���ɼ�����ϵͳ ====" << endl;
		cout << "1. ���ѧ����Ϣ" << endl;
		cout << "2. ��ʾ����ѧ����Ϣ" << endl;
		cout << "3. ���ܷ�����" << endl;
		cout << "4. ��ѯѧ������ѧ�ţ�" << endl;
		cout << "5. �˳�ϵͳ" << endl;
		cout << "���������ѡ��";
		cin >> choice;

		switch (choice) {
		case 1: addStudent(students, count); break;
		case 2: showAllStudents(students, count); break;
		case 3: sortByTotal(students, count); break;
		case 4: searchStudent(students, count); break;
		case 5: cout << "�˳��ɹ�����лʹ�ã�" << endl; return 0;
		default: cout << "��Чѡ����������룡" << endl;
		}
	}

	return 0;
}
void addStudent(Student student[], int& count) {
	Student temp;
	cout << "������ѧ��id������������Ӣ���Ƴɼ�" << endl;
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
	cout << "������Ҫ���ҵ�ѧ��id" << endl;
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
	cout << "δ�ҵ�ѧ��Ϊ " << id << " ��ѧ����Ϣ��" << endl;
}