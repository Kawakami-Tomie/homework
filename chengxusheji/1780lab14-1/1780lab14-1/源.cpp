/*

1. Teacher类：用于教师身份的操作，包括密码验证、修改密码、录入课程信息、录入评分项目、录入学生成绩、信息显示和信息统计等。

2. Student类：用于学生身份的操作，包括信息显示、信息统计和信息查询等。

3. Course类：用于存储课程信息，包括课程编号和课程名称。

4. Item类：用于存储评分项目信息，包括项目名称和所占比例。

5. Grade类：用于存储学生成绩信息，包括学号、姓名和各评分项成绩。

然后，我们需要在主函数中实现以上类的功能，并进行整合。具体步骤如下：

1. 在Teacher类中，实现密码验证、修改密码、录入课程信息、录入评分项目、录入学生成绩、信息显示和信息统计等功能。

2. 在Student类中，实现信息显示、信息统计和信息查询等功能。

3. 在Course类中，实现存储课程编号和课程名称的功能。

4. 在Item类中，实现存储评分项目名称和所占比例的功能。

5. 在Grade类中，实现存储学生成绩信息的功能，并根据评分项目的比例计算总成绩。

6. 在主函数中，实现用户身份选择、密码验证、密码修改、文件读取和存储等功能，并进行整合。
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <conio.h>

using namespace std;

// 评分项目结构体
struct Item {
    string name;  // 项目名称
    double rate;  // 所占比例
};

// 学生结构体
struct Student {
    int id;  // 学号
    string name;  // 姓名
    vector<double> scores;  // 成绩
    double total;  // 总成绩
    int rank;  // 排名
};

// 课程类
class Course {
public:
    Course() {}
    Course(string code, string name) : code_(code), name_(name) {}

    // 设置/获取课程编号
    void setCode(string code) { code_ = code; }
    string getCode() const { return code_; }

    // 设置/获取课程名称
    void setName(string name) { name_ = name; }
    string getName() const { return name_; }

    // 添加/获取评分项目
    void addItem(string name, double rate) { items_.push_back({ name, rate }); }
    vector<Item> getItems() const { return items_; }

    // 保存/读取成绩数据
    void saveData() const;
    void loadData();

    // 添加/修改/删除学生
    void addStudent(int id, string name);
    void modifyStudent(int id, string name);
    void deleteStudent(int id);

    // 添加/修改成绩
    void addScore(int id, string name, vector<double> scores);
    void modifyScore(int id, string name, vector<double> scores);

    // 显示信息
    void displayInfo() const;
    void displayStat() const;
    void displayScore(int id) const;

private:
    string code_;  // 课程编号
    string name_;  // 课程名称
    vector<Item> items_;  // 评分项目
    vector<Student> students_;  // 学生信息

    // 计算总成绩和排名
    void calculateTotal();
    void calculateRank();
};

// 保存成绩数据到文件
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

// 从文件中读取成绩数据
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

// 添加学生
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

// 修改学生
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

// 删除学生
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

// 添加成绩
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

// 修改成绩
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

// 显示课程信息
void Course::displayInfo() const {
    cout << "Course Code: " << getCode() << endl;
    cout << "Course Name: " << getName() << endl;
    cout << "Evaluation Items:" << endl;
    for (const auto& item : items_) {
        cout << setw(10) << item.name << setw(10) << item.rate << "%" << endl;
    }
}

// 显示成绩统计信息
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

// 显示学生成绩单
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

// 计算总成绩和排名
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

// 加密密码
string encryptPassword(string password) {
    string encrypted;
    for (char c : password) {
        encrypted += c ^ 0x5a;
    }
    return encrypted;
}

// 解密密码
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

    // 登录
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