/*
    Hello!
    This is 2048 Game,written by SkyerWalkery ,as an exercise.
    If you find any bug, or sth that can be optimized, contact me and point out,and I'll be more than grateful.
    :)

    Act():a function which takes in your action, and operates on the table as you want.
    Is_gaming():to judge whether you get a 2048, or lose beacuse you cannot act any more >after< new number(s) are placed.
    Add_num():to place new numbers after you act every time, also to judge(use game_over) whether you lose because there are not enough 
places for new numbers to be placed.
    **Pay attention to the two ways of losing above, one after new numbers are placed, one before.
    Display():to print the table.
    init():to initialize the table with random numbers in random places.
    game_over:a global variable to, well, be used in Add_num().
*/


#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 3;//the size of the table, for example,when N=3, it's a 3*3 table

extern void Act(char ,int [][N]);
extern bool Is_gaming(int[][N]);
extern void Add_num(int[][N], int );
extern void Display(int[][N]);
extern void init(int [][N]);
bool game_over = false;


int main() {
    int table[N][N] = { 0 };
    Display(table);

    while (Is_gaming(table) && !game_over){
        cout << "Please input." << endl;
        char action;
        cin >> action;
        Act(action, table);
        Display(table);
    }
    cin.get();
    cin.get();
    return 0;
}


void Act(char action,int table[][N]) {
    /*
    How I think:
    1.Put all non-zero numbers in tmp_arr2[]
    2.Add the same, and transmit into tmp_arr1[]
    3.Back into table in order
    */
    if (action == 'w') {
        for (int j = 0; j < N; j++) {//operate by column
            int tmp_arr1[N] = { 0 };
            int no1_ = 0;
            int tmp_arr2[N] = { 0 };
            int no2_ = 0;
            for (int i = 0; i < N; i++) {
                if (table[i][j] != 0) {
                    tmp_arr2[no2_] = table[i][j];
                    no2_++;//mean one more number is in tmp_arr2[]
                }
            }
            for (int i = 0; i < N - 1; i++) {
                if (tmp_arr2[i] != 0 && tmp_arr2[i] == tmp_arr2[i + 1]) {
                    tmp_arr1[no1_] = tmp_arr2[i] * 2;
                    tmp_arr2[i + 1] = 0;
                    //Note: Don't forget to set tmp_arr2[i+1] 0! 
                    //Hint: Use 8 4 2 2 as a trial.
                    i++;
                    no1_++;
                }
                else if (tmp_arr2[i] != 0) {
                    tmp_arr1[no1_] = tmp_arr2[i];
                    no1_++;
                }
            }
            tmp_arr1[no1_] = tmp_arr2[N - 1];
            for (int i = 0; i < N; i++)
                table[i][j] = tmp_arr1[i];
        }
    }

    //Just copy, and paste.
    else if (action == 's') {
        for (int j = 0; j < N; j++) {
            int tmp_arr1[N] = { 0 };
            int no1_ = N - 1;
            int tmp_arr2[N] = { 0 };
            int no2_ = N - 1;
            for (int i = N - 1; i >=0; i--) {
                if (table[i][j] != 0) {
                    tmp_arr2[no2_] = table[i][j];
                    no2_--;
                }
            }
            for (int i = N - 1; i >= 1; i--) {
                if (tmp_arr2[i] != 0 && tmp_arr2[i] == tmp_arr2[i - 1]) {
                    tmp_arr1[no1_] = tmp_arr2[i] * 2;
                    tmp_arr2[i - 1] = 0;
                    i--;
                    no1_--;
                }
                else if (tmp_arr2[i] != 0) {
                    tmp_arr1[no1_] = tmp_arr2[i];
                    no1_--;
                }
            }
            tmp_arr1[no1_] = tmp_arr2[0];
            for (int i = N - 1; i >= 0; i--)
                table[i][j] = tmp_arr1[i];
        }
    }

    else if (action == 'a') {
        for (int i = 0; i < N; i++) {
            int tmp_arr1[N] = { 0 };
            int no1_ = 0;
            int tmp_arr2[N] = { 0 };
            int no2_ = 0;
            for (int j = 0; j < N; j++) {
                if (table[i][j] != 0) {
                    tmp_arr2[no2_] = table[i][j];
                    no2_++;
                }
            }
            for (int j = 0; j < N - 1; j++) {
                if (tmp_arr2[j] != 0 && tmp_arr2[j] == tmp_arr2[j + 1]) {
                    tmp_arr1[no1_] = tmp_arr2[j] * 2;
                    tmp_arr2[j + 1] = 0;
                    j++;
                    no1_++;
                }
                else if (tmp_arr2[j] != 0) {
                    tmp_arr1[no1_] = tmp_arr2[j];
                    no1_++;
                }
            }
            tmp_arr1[no1_] = tmp_arr2[N - 1];
            for (int j = 0; j < N; j++)
                table[i][j] = tmp_arr1[j];
        }
    }

    else if (action == 'd') {
        for (int i = 0; i < N; i++) {
            int tmp_arr1[N] = { 0 };
            int no1_ = N - 1;
            int tmp_arr2[N] = { 0 };
            int no2_ = N - 1;
            for (int j = N - 1; j >= 0; j--) {
                if (table[i][j] != 0) {
                    tmp_arr2[no2_] = table[i][j];
                    no2_--;
                }
            }
            for (int j = N - 1; j >= 1; j--) {
                if (tmp_arr2[j] != 0 && tmp_arr2[j] == tmp_arr2[j - 1]) {
                    tmp_arr1[no1_] = tmp_arr2[j] * 2;
                    tmp_arr2[j - 1] = 0;
                    j--;
                    no1_--;
                }
                else if (tmp_arr2[j] != 0) {
                    tmp_arr1[no1_] = tmp_arr2[j];
                    no1_--;
                }
            }
            tmp_arr1[no1_] = tmp_arr2[0];
            for (int j = N - 1; j >= 0; j--)
                table[i][j] = tmp_arr1[j];
        }
    }

    //A Easter egg. En...'c' doesn't stand for "cheat", trust me.
    else if (action == 'c') {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                table[i][j] *= 2;
        }
    }

    else{
        cout << "You can only input w,a,s,d !" << endl;
        return;
    }

    Add_num(table, 2);//add two new nums by default
}


bool Is_gaming(int table[][N]) {
    int zero_num = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (table[i][j] == 2048) {
                cout << "Congratulations! You Win!" << endl;
                return false;
            }
            if (table[i][j] == 0) {
                zero_num++;
            }
        }
    }

    int neigh_dif = 0;
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            if (table[i][j] != table[i + 1][j] && table[i][j] != table[i - 1][j] && table[i][j] != table[i][j + 1] && table[i][j] != table[i][j - 1])
                neigh_dif += 1;
        }
    }
    if (zero_num <= 1 && neigh_dif == (N - 2) * (N - 2)) {
        cout << "You can do nothing now. You Lose!" << endl;
        game_over = true;
        return false;
    }//judge if you can continue do more
    return true;
}


void Add_num(int table[][N], int num) {
    int zero_place[N * N][2] = { -1 };
    int zero_num = 0;
    int place_alter[10][2] = { -1 };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (table[i][j] == 0) {
                zero_place[zero_num][0] = i;
                zero_place[zero_num][1] = j;
                zero_num++;
            }
        }
    }//store the location of '0', as well as the amount

    if (zero_num < num) {
        game_over = true;
        cout << "No more place for adding.You Lose!" << endl;
        return;
    }

    for (int i = 0; i < num; i++) {
        int tmp = rand() % zero_num;
        place_alter[i][0] = zero_place[tmp][0];
        place_alter[i][1] = zero_place[tmp][1];
    }//To Be Debug:There may be same tmp!

    for (int i = 0; i < num; i++) {
        table[place_alter[i][0]][place_alter[i][1]]= (1 + rand() % 2) * 2;
    }
}


void Display(int table[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << table[i][j] << "\t ";
        cout << endl << endl;
    }
}


void init(int table[][N]) {
    srand((unsigned)time(NULL));
    rand();//make it more random
    int start_x = rand() % N;
    int start_y = rand() % N;
    table[start_x][start_y] = (1 + rand() % 2) * 2;
}