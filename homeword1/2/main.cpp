#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int map[10][10];
int T_N = 1, T_X = 5, T_Y = 3;
int H_N = 2, H_X = 2, H_Y = 5;
int M_N = 3, M_X = 10-2, M_Y = 1;


int main() 
{
for(int i = 0; i < 10; i++) {
    for(int k = 0; k < 10; k++) {
        if (i == H_X and k == H_Y)
           map[i][k] = H_N;
        else if (i == M_X and k == M_Y) 
           map[i][k] = M_N;
        else if (i == T_X and k == T_Y)
           map[i][k] = T_N;
        else 
           map[i][k] = 0;
    }
}

for(int i = 9; i >= 0;i--) {
    for(int k = 0; k < 10; k++) {
        cout << map[k][i];
    }
    cout << endl;
}
int Taxicab = abs(M_X - H_X) + abs(M_Y-H_Y);
float Euclidean = sqrt(pow((M_X - H_X),2)+pow((M_Y-H_Y),2));
int Chebyshev;
if (abs(M_X - H_X) > abs(M_Y - H_Y))
  Chebyshev = abs(M_X - H_X);
else 
  Chebyshev = abs(M_Y - H_Y);

cout << "Taxicab distance = " << Taxicab << endl;
cout << "Euclidean distance = " << Euclidean << endl;
cout << "Chebyshev distance = " << Chebyshev << endl;
}