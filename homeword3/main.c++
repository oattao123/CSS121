#include <bits/stdc++.h>

using namespace std;

struct Scoreboard {
    string name;
    double score;
    Scoreboard* prev;
    Scoreboard* next;
};

class ScoreboardList {
    Scoreboard* head;
    Scoreboard* tail;
    int size;
public:
    ScoreboardList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void add(string name, double score) {
        Scoreboard* newScoreboard = new Scoreboard;
        newScoreboard->name = name;
        newScoreboard->score = score;
        newScoreboard->prev = NULL;
        newScoreboard->next = NULL;
        if (head == NULL) {
            head = newScoreboard;
            tail = newScoreboard;
        } else {
            tail->next = newScoreboard;
            newScoreboard->prev = tail;
            tail = newScoreboard;
        }
        size++;
    }
    Scoreboard* get(string name) {
        Scoreboard* current = head;
        while (current != NULL) {
            if (current->name == name) {
                return current;
            }
            current = current->next;
        }
        return NULL;
    }
    Scoreboard* get(int index) {
        Scoreboard* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current;
    }
    int getSize() {
        return size;
    }
    void sort() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size - 1; j++) {
                if (get(j)->score > get(j + 1)->score) {
                    double tempScore = get(j)->score;
                    string tempName = get(j)->name;
                    get(j)->score = get(j + 1)->score;
                    get(j)->name = get(j + 1)->name;
                    get(j + 1)->score = tempScore;
                    get(j + 1)->name = tempName;
                }           
            }
        }
    }
    void print() {
        Scoreboard* current = head;
        while (current != NULL) {
            cout << current->name << " " << current->score << endl;
            current = current->next;
        }
    }
};


void printScoreboardList(ScoreboardList scoreboardList) {
    for (int i = 0; i < scoreboardList.getSize(); i++) {
        cout << scoreboardList.get(i)->name << " " << scoreboardList.get(i)->score << endl;
    }
}
string newname;
double newscore;

int main() {
    ScoreboardList scoreboardList;
    scoreboardList.add("A", 40);
    scoreboardList.add("B", 100);
    scoreboardList.add("C", 60);
    scoreboardList.add("D", 80);
    scoreboardList.add("E", 20);
    scoreboardList.add("F", 10);
    scoreboardList.add("G", 70);
    scoreboardList.add("H", 90);
    scoreboardList.add("I", 30);
    scoreboardList.add("J", 50);
    cout << endl;
    scoreboardList.sort();
    scoreboardList.print();
    cout <<"Enter new name and score \n";
    cin >> newname;
    cin >> newscore;
    scoreboardList.add(newname, newscore);
    cout << "\n";
    scoreboardList.sort();
    scoreboardList.print();
    cout << endl;

}