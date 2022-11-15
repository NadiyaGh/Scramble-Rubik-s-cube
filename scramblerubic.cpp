#include <iostream>
#include <cstdlib>
#include <ctime>

#define F1 0
#define B1 1
#define R1 2
#define L1 3
#define D1 4
#define U1 5
#define F2 6
#define B2 7
#define R2 8
#define L2 9
#define D2 10
#define U2 11
using namespace std;
char* R[6][20];
char rubic[6][9];
void init();
void action(int);
void print();
int main()
{
    int i, it, act;
    init();
    srand((unsigned)time(0));
    it = rand() % 90 + 10;
    for (i = 0; i < it; i++)
    {
        act = rand() % 12;
        action(act);
    }
    print();
    return 0;
}
void init()
{
    for (int i = 0; i < 9; i++)
    {
        rubic[0][i] = 'G';
        rubic[1][i] = 'B';
        rubic[2][i] = 'R';
        rubic[3][i] = 'O';
        rubic[4][i] = 'Y';
        rubic[5][i] = 'W';
    }
    R[0][0] = &(rubic[3][6]);
    R[0][1] = &(rubic[3][7]);
    R[0][2] = &(rubic[3][8]);
    R[0][3] = &(rubic[5][0]);
    R[0][4] = &(rubic[5][3]);
    R[0][5] = &(rubic[5][6]);
    R[0][6] = &(rubic[2][2]);
    R[0][7] = &(rubic[2][1]);
    R[0][8] = &(rubic[2][0]);
    R[0][9] = &(rubic[4][8]);
    R[0][10] = &(rubic[4][5]);
    R[0][11] = &(rubic[4][2]);

    R[1][0] = &(rubic[2][6]);
    R[1][1] = &(rubic[2][7]);
    R[1][2] = &(rubic[2][8]);
    R[1][3] = &(rubic[5][8]);
    R[1][4] = &(rubic[5][5]);
    R[1][5] = &(rubic[5][2]);
    R[1][6] = &(rubic[3][2]);
    R[1][7] = &(rubic[3][1]);
    R[1][8] = &(rubic[3][0]);
    R[1][9] = &(rubic[4][0]);
    R[1][10] = &(rubic[4][3]);
    R[1][11] = &(rubic[4][6]);

    R[2][0] = &(rubic[0][6]);
    R[2][1] = &(rubic[0][7]);
    R[2][2] = &(rubic[0][8]);
    R[2][3] = &(rubic[5][6]);
    R[2][4] = &(rubic[5][7]);
    R[2][5] = &(rubic[5][8]);
    R[2][6] = &(rubic[1][2]);
    R[2][7] = &(rubic[1][1]);
    R[2][8] = &(rubic[1][0]);
    R[2][9] = &(rubic[4][6]);
    R[2][10] = &(rubic[4][7]);
    R[2][11] = &(rubic[4][8]);

    R[3][0] = &(rubic[1][6]);
    R[3][1] = &(rubic[1][7]);
    R[3][2] = &(rubic[1][8]);
    R[3][3] = &(rubic[5][2]);
    R[3][4] = &(rubic[5][1]);
    R[3][5] = &(rubic[5][0]);
    R[3][6] = &(rubic[0][2]);
    R[3][7] = &(rubic[0][1]);
    R[3][8] = &(rubic[0][0]);
    R[3][9] = &(rubic[4][2]);
    R[3][10] = &(rubic[4][1]);
    R[3][11] = &(rubic[4][0]);

    R[4][0] = &(rubic[3][0]);
    R[4][1] = &(rubic[3][3]);
    R[4][2] = &(rubic[3][6]);
    R[4][3] = &(rubic[0][0]);
    R[4][4] = &(rubic[0][3]);
    R[4][5] = &(rubic[0][6]);
    R[4][6] = &(rubic[2][0]);
    R[4][7] = &(rubic[2][3]);
    R[4][8] = &(rubic[2][6]);
    R[4][9] = &(rubic[1][0]);
    R[4][10] = &(rubic[1][3]);
    R[4][11] = &(rubic[1][6]);

    R[5][0] = &(rubic[3][8]);
    R[5][1] = &(rubic[3][5]);
    R[5][2] = &(rubic[3][2]);
    R[5][3] = &(rubic[1][8]);
    R[5][4] = &(rubic[1][5]);
    R[5][5] = &(rubic[1][2]);
    R[5][6] = &(rubic[2][8]);
    R[5][7] = &(rubic[2][5]);
    R[5][8] = &(rubic[2][2]);
    R[5][9] = &(rubic[0][8]);
    R[5][10] = &(rubic[0][5]);
    R[5][11] = &(rubic[0][2]);

}

void action(int act)
{
    char temp;
    if (act < 6)
    {
        temp = rubic[act][0];
        rubic[act][0] = rubic[act][6];
        rubic[act][6] = rubic[act][8];
        rubic[act][8] = rubic[act][2];
        rubic[act][2] = temp;

        temp = rubic[act][1];
        rubic[act][1] = rubic[act][3];
        rubic[act][3] = rubic[act][7];
        rubic[act][7] = rubic[act][5];
        rubic[act][5] = temp;

        temp = *(R[act][0]);
        *(R[act][0]) = *(R[act][9]);
        *(R[act][9]) = *(R[act][6]);
        *(R[act][6]) = *(R[act][3]);
        *(R[act][3]) = temp;

        temp = *(R[act][1]);
        *(R[act][1]) = *(R[act][10]);
        *(R[act][10]) = *(R[act][7]);
        *(R[act][7]) = *(R[act][4]);
        *(R[act][4]) = temp;

        temp = *(R[act][2]);
        *(R[act][2]) = *(R[act][11]);
        *(R[act][11]) = *(R[act][8]);
        *(R[act][8]) = *(R[act][5]);
        *(R[act][5]) = temp;
    }
    else
    {
        act -= 6;
        temp = rubic[act][0];
        rubic[act][0] = rubic[act][2];
        rubic[act][2] = rubic[act][8];
        rubic[act][8] = rubic[act][6];
        rubic[act][6] = temp;

        temp = rubic[act][1];
        rubic[act][1] = rubic[act][5];
        rubic[act][5] = rubic[act][7];
        rubic[act][7] = rubic[act][3];
        rubic[act][3] = temp;

        temp = *(R[act][0]);
        *(R[act][0]) = *(R[act][3]);
        *(R[act][3]) = *(R[act][6]);
        *(R[act][6]) = *(R[act][9]);
        *(R[act][9]) = temp;

        temp = *(R[act][1]);
        *(R[act][1]) = *(R[act][4]);
        *(R[act][4]) = *(R[act][7]);
        *(R[act][7]) = *(R[act][10]);
        *(R[act][10]) = temp;

        temp = *(R[act][2]);
        *(R[act][2]) = *(R[act][5]);
        *(R[act][5]) = *(R[act][8]);
        *(R[act][8]) = *(R[act][11]);
        *(R[act][11]) = temp;
    }
}
void print()
{
    int i, j, k;
    for (j = 0; j < 9; j++)
    {
        if (j % 3 == 0)
            cout << "\n\n\t\t\t";
        cout << rubic[3][j] << "\t";

    }
    cout << endl << endl;
    for (j = 0; j < 9; j += 3)
    {
        cout << "\n\n";

        cout << rubic[4][j] << "\t";
        cout << rubic[4][j + 1] << "\t";
        cout << rubic[4][j + 2] << "\t";
        cout << rubic[0][j] << "\t";
        cout << rubic[0][j + 1] << "\t";
        cout << rubic[0][j + 2] << "\t";
        cout << rubic[5][j] << "\t";
        cout << rubic[5][j + 1] << "\t";
        cout << rubic[5][j + 2] << "\t";
    }
    cout << endl << endl;
    for (j = 0; j < 9; j++)
    {
        if (j % 3 == 0)
            cout << "\n\n\t\t\t";
        cout << rubic[2][j] << "\t";

    }
    cout << "\n\n";
    for (j = 0; j < 9; j++)
    {
        if (j % 3 == 0)
            cout << "\n\n\t\t\t";
        cout << rubic[1][j] << "\t";
    }
    cout << "\n\n";
}
