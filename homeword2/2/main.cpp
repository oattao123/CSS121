#include <bits/stdc++.h>

using namespace std;

struct Student {
    string name;
    int score;
};

vector <Student> students;

Student MaxStident() {
    Student maxStudent = students[0];
    for (int i = 1; i < students.size(); i++) {
        if (students[i].score > maxStudent.score) {
            maxStudent = students[i];
        }
    }
    return maxStudent;
}

Student MinStudent() {
    Student minStudent = students[0];
    for (int i = 1; i < students.size(); i++) {
        if (students[i].score < minStudent.score) {
            minStudent = students[i];
        }
    }
    return minStudent;
}

int AvrScore() {
    int sum = 0;
    for (int i = 0; i < students.size(); i++) {
        sum += students[i].score;
    }
    return sum / students.size();
}

int ModeScore() {
    int mode = 0;
    int maxCount = 0;
    for (int i = 0; i < students.size(); i++) {
        int count = 0;
        for (int j = 0; j < students.size(); j++) {
            if (students[i].score == students[j].score) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mode = students[i].score;
        }
    }
    return mode;
}

int MedianScore() {
    vector <int> scores;
    for (int i = 0; i < students.size(); i++) {
        scores.push_back(students[i].score);
    }
    sort(scores.begin(), scores.end());
    return scores[scores.size() / 2];
}

double SDScore() {
    double sum = 0;
    for (int i = 0; i < students.size(); i++) {
        sum += pow(students[i].score - AvrScore(), 2);
    }
    return sqrt(sum / students.size());
}

char Grade(int score) {
    int avr = AvrScore();
    double sd = SDScore();
    if (score >= avr + 2 * sd) {
        return 'A';
    } else if (score >= avr + sd) {
        return 'B';
    } else if (score >= avr) {
        return 'C';
    } else if (score >= avr - sd) {
        return 'D';
    } else {
        return 'F';
    }
}


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        Student student;
        cin >> student.name >> student.score;
        students.push_back(student);
    }
    cout << "Max: " << MaxStident().name << " " << MaxStident().score << endl;
    cout << "Min: " << MinStudent().name << " " << MinStudent().score << endl;
    cout << "Avr: " << AvrScore() << endl;
    cout << "Mode: " << ModeScore() << endl;
    cout << "Median: " << MedianScore() << endl;
    cout << "SD: " << SDScore() << endl;
    cout << "Grade: " << endl;
    for (int i = 0; i < students.size(); i++) {
        cout << students[i].name << " " << Grade(students[i].score) << endl;
    }
    return 0;
}