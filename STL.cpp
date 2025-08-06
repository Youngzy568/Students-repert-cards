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
        cout << "������ѧ��id�����������ģ���ѧ��Ӣ��ɼ���" << endl;
        cin >> temp.id >> temp.name >> temp.chinese >> temp.math >> temp.english;
        temp.total = temp.chinese + temp.math + temp.english;
		students.push_back(temp);
        cout << "��ӳɹ�����ǰ��������" << students.size() << endl;
    }

    void showAllStudents() const {
        if (students.size() == 0) {
            cout << "��ǰû��ѧ����Ϣ��" << endl;
            return;
        }
        for (auto& student:students) {
            cout << "ID: " << student.id
                << ", ����: " << student.name
                << ", ����: " << student.chinese
                << ", ��ѧ: " << student.math
                << ", Ӣ��: " << student.english
                << ", �ܷ�: " << student.total << endl;
        }
    }

    void sortByTotal() {
       sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.total > b.total;
		   });
        cout << "�Ѱ��ֽܷ�������" << endl;
    }

    void searchStudent() const {
        string id;
        cout << "������Ҫ���ҵ�ѧ��id��" << endl;
        cin >> id;
        for (auto& student : students) {
            if (student.id == id) {
                cout << "�ҵ�ѧ����Ϣ��" << endl;
                cout << "ID: " << student.id
                    << ", ����: " << student.name
                    << ", ����: " << student.chinese
                    << ", ��ѧ: " << student.math
                    << ", Ӣ��: " << student.english
                    << ", �ܷ�: " << student.total << endl;
				return;
            }
        }
        cout << "���޴��ˣ�" << endl;
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
            cout << "�޷����ļ���" << endl;
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
		cout << "���ݼ��سɹ�����ǰ��������" << students.size() << endl;
    }
};
int main() {
    StudentManager manager;
    int choice;

    while (true) {
        cout << "\n==== ѧ���ɼ�����ϵͳ ====" << endl;
        cout << "1. ���ѧ����Ϣ" << endl;
        cout << "2. ��ʾ����ѧ����Ϣ" << endl;
        cout << "3. ���ܷ�����" << endl;
        cout << "4. ��ѯѧ������ѧ�ţ�" << endl;
        cout << "5. ����ѧ����Ϣ���ļ�" << endl;
        cout << "6. ���ļ�����ѧ����Ϣ" << endl;
        cout << "7. �˳�ϵͳ" << endl;
        cout << "���������ѡ��";
        cin >> choice;

        switch (choice) {
        case 1: manager.addStudent(); break;
        case 2: manager.showAllStudents(); break;
        case 3: manager.sortByTotal(); break;
        case 4: manager.searchStudent(); break;
		case 5: manager.saveToFile("students.txt"); break;
		case 6: manager.loadFromFile("students.txt"); break;
        case 7: cout << "�˳��ɹ�����лʹ�ã�" << endl; return 0;
        default: cout << "��Чѡ����������룡" << endl;
        }
    }

    return 0;
}
