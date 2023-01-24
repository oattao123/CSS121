#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
void printStudent(struct Students student);

struct Students
{
    char name[50];
    int score;

};

void Maxstudent(struct Students student[10])
{
    int max = 0;
    for (int i = 0; i < 10; i++)
    {
        if (student[i].score > max)
        {
            max = student[i].score;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (student[i].score == max)
        {
            cout << "Max score is " << student[i].score << " and name is " << student[i].name << endl;
        }
    }
}
// create function grade use avrscore and sdscore
void Grade(struct Students student[10])
{
    int sum = 0;
    int avr = sum / 10;
    for (int i = 0; i < 10; i++)
    {
        sum += student[i].score;
    }
    int sum2 = 0;
    for (int i = 0; i < 10; i++)
    {
        sum2 += pow(student[i].score - avr, 2);
    }
    int sd = sqrt(sum2 / 10);
    for (int i = 0; i < 10; i++)
    {
        if (student[i].score >= avr + 2*sd)
        {
            cout << "Grade A is " << student[i].name << endl;
        }
        else if (student[i].score >= avr + sd)
        {
            cout << "Grade B is " << student[i].name << endl;
        }
        else if (student[i].score >= avr )
        {
            cout << "Grade C is " << student[i].name << endl;
        }

        else if (student[i].score >= avr - sd)
        {
            cout << "Grade D is " << student[i].name << endl;
        }
        else
        {
            cout << "Grade F is " << student[i].name << endl;
        }
    }
}

void Minstudent(struct Students student[10])
{
    int min = 100;
    for (int i = 0; i < 10; i++)
    {
        if (student[i].score < min)
        {
            min = student[i].score;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (student[i].score == min)
        {
            cout << "Min score is " << student[i].score << " and name is " << student[i].name << endl;
        }
    }
}

void AvrScore(struct Students student[10])
{
    int sum = 0;
    int avr = sum/10;
    for (int i = 0; i < 10; i++)
    {
        sum += student[i].score;
    }
    cout << "Average score is " << avr << endl;
}

void ModeScore(struct Students student[10])
{
    int count[10] = {0};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (student[i].score == student[j].score)
            {
                count[i]++;
            }
        }
    }
    int max = 0;
    for (int i = 0; i < 10; i++)
    {
        if (count[i] > max)
        {
            max = count[i];
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (count[i] == max)
        {
            cout << "Mode score is " << student[i].score << " and name is " << student[i].name << endl;
        }
    }
}

void MedianScore(struct Students student[10])
{
    int temp;
    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (student[i].score > student[j].score)
            {
                temp = student[i].score;
                student[i].score = student[j].score;
                student[j].score = temp;
            }
        }
    }
    if (10 % 2 == 0)
    {
        cout << "Median score is " << (student[4].score + student[5].score) / 2 << endl;
    }
    else
    {
        cout << "Median score is " << student[4].score << endl;
    }
}

void SDScore (struct Students student[10])
{
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += student[i].score;
    }
    int avr = sum / 10;
    int sum2 = 0;
    for (int i = 0; i < 10; i++)
    {
        sum2 += pow(student[i].score - avr, 2);
    }
    cout << "Standard deviation is " << sqrt(sum2 / 10) << endl;
}

int main()
{
    struct Students student[10];
    strcpy(student[0].name, "A");
    student[0].score = 42;
    strcpy(student[1].name, "B");
    student[1].score = 42;
    strcpy(student[2].name, "C");
    student[2].score = 84;
    strcpy(student[3].name, "D");
    student[3].score = 12;
    strcpy(student[4].name, "E");
    student[4].score = 77;
    strcpy(student[5].name, "F");
    student[5].score = 26;
    strcpy(student[6].name, "G");
    student[6].score = 53;
    strcpy(student[7].name, "H");
    student[7].score = 93;
    strcpy(student[8].name, "I");
    student[8].score = 34;
    strcpy(student[9].name, "J");
    student[9].score = 65;

    Maxstudent(student);
    Minstudent(student);
    AvrScore(student);
    ModeScore(student);
    MedianScore(student);
    SDScore(student);
    Grade(student);
}
