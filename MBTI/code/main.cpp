#include <bits/stdc++.h>
using namespace std;

struct Data {
    string Name,Sex,Type;
    float No, Ne, Ni, Te, Ti, Se, Si, Fe, Fi, distance;
};

vector<Data> read_data(string file_path) {
    vector<Data> people;
    ifstream file(file_path);
    string line;
    getline(file, line);
    while (getline(file, line)) {
        stringstream ss(line);
        string item;
        Data p;
        getline(ss, item, ',');
        p.No = stof(item);
        getline(ss, p.Name, ',');
        getline(ss, p.Sex, ',');
        getline(ss, item, ',');
        p.Ne = stof(item);
        getline(ss, item, ',');
        p.Ni = stof(item);
        getline(ss, item, ',');
        p.Te = stof(item);
        
        getline(ss, item, ',');
        p.Ti = stof(item);
        getline(ss, item, ',');
        p.Se = stof(item);
        getline(ss, item, ',');
        p.Si = stof(item);
        getline(ss, item, ',');
        p.Fe = stof(item);
        getline(ss, item, ',');
        p.Fi = stof(item);
        getline(ss, p.Type, ',');
        people.push_back(p);
    }
    file.close();
    return people;
}

void distance(vector<Data>& people, const Data& q , int n) {
    for (int i = 0; i < people.size(); i++) {
        float distance = sqrt(pow(people[i].Ne - q.Ne, 2) + pow(people[i].Ni - q.Ni, 2) + pow(people[i].Te - q.Te, 2) + pow(people[i].Ti - q.Ti, 2) + pow(people[i].Se - q.Se, 2) + pow(people[i].Si - q.Si, 2) + pow(people[i].Fe - q.Fe, 2) + pow(people[i].Fi - q.Fi, 2));
        people[i].distance = distance;
    }
}


string findMBTI (vector<Data>& people, int n) {
    int E = 0, I = 0, S = 0, N = 0, T = 0, F = 0, J = 0, P = 0;
    for (int i = 0; i < n; i++) {
        if (people[i].Type[0] == 'E') {
            E++;
        } else {
            I++;
        }
        if (people[i].Type[1] == 'S') {
            S++;
        } else {
            N++;
        }
        if (people[i].Type[2] == 'T') {
            T++;
        } else {
            F++;
        }
        if (people[i].Type[3] == 'J') {
            J++;
        } else {
            P++;
        }
    }
    string result = "";
    if (E > I) {
        result += "E";
    } else {
        result += "I";
    }
    if (S > N) {
        result += "S";
    } else {
        result += "N";
    }
    if (T > F) {
        result += "T";
    } else {
        result += "F";
    }
    if (J > P) {
        result += "J";
    } else {
        result += "P";
    }
    return result;
}


int main() {
    vector<Data> people = read_data("data.csv");
    Data q;
    q.Ne = 37,q.Ni = 47.8,q.Te = 43,q.Ti = 47,q.Se = 47,q.Si = 45,q.Fe = 37,q.Fi = 43;
    distance(people, q, people.size());
    Data lowest[9];
    for (int i = 0; i < 9; i++) {
        lowest[i] = people[i];
    }

    for (int i = 0; i < 9; i++) {
        cout << lowest[i].Name << ", Distance: " << lowest[i].distance << ", MBTI: " << lowest[i].Type << endl;
    }

    cout << endl;
    string MBTI = findMBTI(people, 9);
    cout << "Dollatham Charoethammkic is " << MBTI << endl;
    return 0;
}
