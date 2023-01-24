/*
65090500415 Dollatham Charoethammkit 
date of birth is monday

*/

#include <math.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    vector<vector<int> > matrix(11, vector<int>(11));
    int r = rand() % 10 + 1;
    int day = 2, first = 1,last = 5;
    for (int x = 1; x < 11; x++)
    {
        for (int y = 10; y > 0; y--)
        {
            matrix[x][y] = 0;
        };
    }
    
    matrix[r][r] = 1; // tree
    matrix[day][last] = 2; // hero
    matrix[10-day][first] = 3; // tree
    for (int x = 1; x < 11; x++)
    {
        for (int y = 10; y > 0; y--)
        {
            cout << matrix[x][y] << " ";
        }
        cout << endl;
    }
   int hero = last - day;
   int tree = first - (10 - day);
   cout << "Taxicab = " << abs(hero) + abs(tree) << endl;
   cout << "Euclidean = " << sqrt(pow(hero, 2) + pow(tree, 2)) << endl;
   cout << "Chebyshev = " << max(abs(hero), abs(tree)) << endl;
   return 0; 

}
