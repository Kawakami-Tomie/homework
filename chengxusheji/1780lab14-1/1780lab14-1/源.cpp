/*

1. Teacher�ࣺ���ڽ�ʦ��ݵĲ���������������֤���޸����롢¼��γ���Ϣ��¼��������Ŀ��¼��ѧ���ɼ�����Ϣ��ʾ����Ϣͳ�Ƶȡ�

2. Student�ࣺ����ѧ����ݵĲ�����������Ϣ��ʾ����Ϣͳ�ƺ���Ϣ��ѯ�ȡ�

3. Course�ࣺ���ڴ洢�γ���Ϣ�������γ̱�źͿγ����ơ�

4. Item�ࣺ���ڴ洢������Ŀ��Ϣ��������Ŀ���ƺ���ռ������

5. Grade�ࣺ���ڴ洢ѧ���ɼ���Ϣ������ѧ�š������͸�������ɼ���

Ȼ��������Ҫ����������ʵ��������Ĺ��ܣ����������ϡ����岽�����£�

1. ��Teacher���У�ʵ��������֤���޸����롢¼��γ���Ϣ��¼��������Ŀ��¼��ѧ���ɼ�����Ϣ��ʾ����Ϣͳ�Ƶȹ��ܡ�

2. ��Student���У�ʵ����Ϣ��ʾ����Ϣͳ�ƺ���Ϣ��ѯ�ȹ��ܡ�

3. ��Course���У�ʵ�ִ洢�γ̱�źͿγ����ƵĹ��ܡ�

4. ��Item���У�ʵ�ִ洢������Ŀ���ƺ���ռ�����Ĺ��ܡ�

5. ��Grade���У�ʵ�ִ洢ѧ���ɼ���Ϣ�Ĺ��ܣ�������������Ŀ�ı��������ܳɼ���

6. ���������У�ʵ���û����ѡ��������֤�������޸ġ��ļ���ȡ�ʹ洢�ȹ��ܣ����������ϡ�
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <conio.h>

using namespace std;

// ������Ŀ�ṹ��
struct Item {
    string name;  // ��Ŀ����
    double rate;  // ��ռ����
};

// ѧ���ṹ��
struct Student {
    int id;  // ѧ��
    string name;  // ����
    vector<double> scores;  // �ɼ�
    double total;  // �ܳɼ�
    int rank;  // ����
};

// �γ���
class Course {
public:
    Course() {}
    Course(string code, string name) : code_(code), name_(name) {}

    // ����/��ȡ�γ̱��
    void setCode(string code) { code_ = code; }
    string getCode() const { return code_; }

    // ����/��ȡ�γ�����
    void setName(string name) { name_ = name; }
    string getName() const { return name_; }

    // ���/��ȡ������Ŀ
    void addItem(string name, double rate) { items_.push_back({ name, rate }); }
    vector<Item> getItems() const { return items_; }

    // ����/��ȡ�ɼ�����
    void saveData() const;
    void loadData();

    // ���/�޸�/ɾ��ѧ��
    void addStudent(int id, string name);
    void modifyStudent(int id, string name);
    void deleteStudent(int id);

    // ���/�޸ĳɼ�
    void addScore(int id, string name, vector<double> scores);
    void modifyScore(int id, string name, vector<double> scores);

    // ��ʾ��Ϣ
    void displayInfo() const;
    void displayStat() const;
    void displayScore(int id) const;

private:
    string code_;  // �γ̱��
    string name_;  // �γ�����
    vector<Item> items_;  // ������Ŀ
    vector<Student> students_;  // ѧ����Ϣ

    // �����ܳɼ�������
    void calculateTotal();
    void calculateRank();
};

// ����ɼ����ݵ��ļ�
void Course::saveData() const {
    string filename = getCode() + ".dat";
    ofstream fout(filename, ios::binary);
    if (!fout) {
        cerr << "Error: Cannot open file " << filename << " for writing." << endl;
        return;
    }
    fout.write(reinterpret_cast<const char*>(&students_[0]), students_.size() * sizeof(Student));
    fout.close();
    cout << "Data saved to file " << filename << "." << endl;
}

// ���ļ��ж�ȡ�ɼ�����
void Course::loadData() {
    string filename = getCode() + ".dat";
    ifstream fin(filename, ios::binary);
    if (!fin) {
        cerr << "Error: Cannot open file " << filename << " for reading." << endl;
        return;
    }
    students_.clear();
    fin.seekg(0, ios::end);
    int size = fin.tellg() / sizeof(Student);
    fin.seekg(0, ios::beg);
    for (int i = 0; i < size; i++) {
        Student s;
        fin.read(reinterpret_cast<char*>(&s), sizeof(Student));
        students_.push_back(s);
    }
    fin.close();
    cout << "Data loaded from file " << filename << "." << endl;
}

// ���ѧ��
void Course::addStudent(int id, string name) {
    for (const auto& s : students_) {
        if (s.id == id) {
            cerr << "Error: Student with ID " << id << " already exists." << endl;
            return;
        }
    }
    students_.push_back({ id, name });
    cout << "Student " << id << " added." << endl;
}

// �޸�ѧ��
void Course::modifyStudent(int id, string name) {
    for (auto& s : students_) {
        if (s.id == id) {
            s.name = name;
            cout << "Student " << id << " modified." << endl;
            return;
        }
    }
    cerr << "Error: Student with ID " << id << " not found." << endl;
}

// ɾ��ѧ��
void Course::deleteStudent(int id) {
    for (auto it = students_.begin(); it != students_.end(); it++) {
        if (it->id == id) {
            students_.erase(it);
            cout << "Student " << id << " deleted." << endl;
            return;
        }
    }
    cerr << "Error: Student with ID " << id << " not found." << endl;
}

// ��ӳɼ�
void Course::addScore(int id, string name, vector<double> scores) {
    for (auto& s : students_) {
        if (s.id == id) {
            if (!s.scores.empty()) {
                cerr << "Error: Scores for student " << id << " already exist." << endl;
                return;
            }
            if (scores.size() != items_.size()) {
                cerr << "Error: Invalid number of scores." << endl;
                return;
            }
            s.scores = scores;
            calculateTotal();
            calculateRank();
            cout << "Scores for student " << id << " added." << endl;
            return;
        }
    }
    cerr << "Error: Student with ID " << id << " not found." << endl;
}

// �޸ĳɼ�
void Course::modifyScore(int id, string name, vector<double> scores) {
    for (auto& s : students_) {
        if (s.id == id) {
            if (s.scores.empty()) {
                cerr << "Error: Scores for student " << id << " do not exist." << endl;
                return;
            }
            if (scores.size() != items_.size()) {
                cerr << "Error: Invalid number of scores." << endl;
                return;
            }
            s.scores = scores;
            calculateTotal();
            calculateRank();
            cout << "Scores for student " << id << " modified." << endl;
            return;
        }
    }
    cerr << "Error: Student with ID " << id << " not found." << endl;
}

// ��ʾ�γ���Ϣ
void Course::displayInfo() const {
    cout << "Course Code: " << getCode() << endl;
    cout << "Course Name: " << getName() << endl;
    cout << "Evaluation Items:" << endl;
    for (const auto& item : items_) {
        cout << setw(10) << item.name << setw(10) << item.rate << "%" << endl;
    }
}

// ��ʾ�ɼ�ͳ����Ϣ
void Course::displayStat() const {
    int n = students_.size();
    double total = 0;
    double max_total = 0;
    double min_total = 100;
    vector<double> item_totals(items_.size(), 0);
    vector<double> item_maxs(items_.size(), 0);
    vector<double> item_mins(items_.size(), 100);
    vector<int> item_counts(items_.size(), 0);
    vector<int> score_counts(11, 0);
    for (const auto& s : students_) {
        total += s.total;
        max_total = max(max_total, s.total);
        min_total = min(min_total, s.total);
        for (int i = 0; i < items_.size(); i++) {
            item_totals[i] += s.scores[i] * items_[i].rate / 100;
            item_maxs[i] = max(item_maxs[i], s.scores[i]);
            item_mins[i] = min(item_mins[i], s.scores[i]);
            item_counts[i]++;
        }
        score_counts[static_cast<int>(s.total / 10)]++;
    }
    cout << "Total Number of Students: " << n << endl;
    cout << "Average Total Score: " << fixed << setprecision(2) << total / n << endl;
    cout << "Max Total Score: " << fixed << setprecision(2) << max_total << endl;
    cout << "Min Total Score: " << fixed << setprecision(2) << min_total << endl;
    cout << "Evaluation Item Statistics:" << endl;
    for (int i = 0; i < items_.size(); i++) {
        cout << setw(10) << items_[i].name << setw(10) << item_totals[i] / n << setw(10) << item_maxs[i] << setw(10) << item_mins[i] << endl;
    }
    cout << "Score Distribution:" << endl;
    for (int i = 0; i < 11; i++) {
        cout << setw(3) << i * 10 << "-" << setw(3) << i * 10 + 9 << ": " << score_counts[i] << endl;
    }
}

// ��ʾѧ���ɼ���
void Course::displayScore(int id) const {
    for (const auto& s : students_) {
        if (s.id == id) {
            cout << "Student ID: " << id << endl;
            cout << "Student Name: " << s.name << endl;
            cout << "Evaluation Items:" << endl;
            for (int i = 0; i < items_.size(); i++) {
                cout << setw(10) << items_[i].name << setw(10) << s.scores[i] << endl;
            }
            cout << "Total Score: " << fixed << setprecision(2) << s.total << endl;
            cout << "Rank: " << s.rank << endl;
            return;
        }
    }
    cerr << "Error: Student with ID " << id << " not found." << endl;
}

// �����ܳɼ�������
void Course::calculateTotal() {
    for (auto& s : students_) {
        double total = 0;
        for (int i = 0; i < items_.size(); i++) {
            total += s.scores[i] * items_[i].rate / 100;
        }
        s.total = total;
    }
}

void Course::calculateRank() {
    vector<Student> temp(students_);
    sort(temp.begin(), temp.end(), [](const Student& a, const Student& b) { return a.total > b.total; });
    for (int i = 0; i < temp.size(); i++) {
        temp[i].rank = i + 1;
    }
    for (auto& s : students_) {
        for (const auto& t : temp) {
            if (s.id == t.id) {
                s.rank = t.rank;
                break;
            }
        }
    }
}

// ��������
string encryptPassword(string password) {
    string encrypted;
    for (char c : password) {
        encrypted += c ^ 0x5a;
    }
    return encrypted;
}

// ��������
string decryptPassword(string encrypted) {
    string password;
    for (char c : encrypted) {
        password += c ^ 0x5a;
    }
    return password;
}

int main() {
    Course course;
    string code, name;
    vector<Item> items;
    string password = encryptPassword("123456");

    // ��¼
    int identity;
    string input_password;
    do {
        cout << "Please select identity:" << endl;
        cout << "1. Teacher" << endl;
        cout << "2. Student" << endl;
        cin >> identity;
        if (identity == 1) {
            cout << "Please enter password: ";
            input_password = "";
            char c;
            while ((c = _getch()) != '\r') {
                if (c == '\b') {
                    if (!input_password.empty()) {
                        input_password.pop_back();
                        cout << "\b \b";
                    }
                }
                else