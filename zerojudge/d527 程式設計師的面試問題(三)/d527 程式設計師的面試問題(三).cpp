/*#include <bits/stdc++.h>
using namespace std;

bool flag = false;
int test[5][5];

/*
"House     Color    Nation     Drink Cigarette       Pet"

"        H1         9        <>        <>        <>        <>"

"        H2        <>        <>        <>        <>        <>"

"        H3        <>        <>        <>        <>        <>"

"        H4        <>        <>        <>        <>        <>"

"        H5        <>        <>        <>        <>        <>"
*/
/*
bool check() {
    if(test[1][0] != 9) return false;
    for(int i = 0; i < 5; i++) {
        if(test[1][i] == 6) {
            if(test[0][i] != 1)
                return false;
            else
                break;
        }
    }
    for(int i = 0; i < 5; i++) {
        if(test[1][i] == 7) {
            if(test[4][i] != 21)
                return false;
            else
                break;
        }
    }
    for(int i = 0; i < 5; i++) {
        if(test[1][i] == 8) {
            if(test[2][i] != 11)
                return false;
            else
                break;
        }
    }
    for(int i = 0; i < 5; i++) {
        if(test[0][i] == 3) {
            if(i == 0 || test[0][i - 1] != 2)
                return false;
            else
                break;
        }
    }
    for(int i = 0; i < 5; i++) {
        if(test[0][i] == 2) {
            if(test[2][i] != 12)
                return false;
            else
                break;
        }
    }
    for(int i = 0; i < 5; i++) {
        if(test[3][i] == 16) {
            if(test[4][i] != 22)
                return false;
            else
                break;
        }
    }
    for(int i = 0; i < 5; i++) {
        if(test[0][i] == 4) {
            if(test[3][i] != 20)
                return false;
            else
                break;
        }
    }
    if(test[2][2] != 13) return false;
    for(int i = 0; i < 5; i++) {
        if(test[3][i] == 17) {
            if(i == 0 && test[4][1] != 23)
                return false;
            else if(i == 4 && test[4][3] != 23)
                return false;
            else if(test[4][i - 1] != 23 && test[4][i + 1] != 23)
                return false;
            else
                break;
        }
    }
    for(int i = 0; i < 5; i++) {
        if(test[4][i] == 24) {
            if(i == 0 && test[3][1] != 20)
                return false;
            else if(i == 4 && test[3][3] != 20)
                return false;
            else if(test[3][i - 1] != 20 && test[3][i + 1] != 20)
                return false;
            else
                break;
        }
    }
    for(int i = 0; i < 5; i++) {
        if(test[3][i] == 18) {
            if(test[2][i] != 14)
                return false;
            else
                break;
        }
    }
    for(int i = 0; i < 5; i++) {
        if(test[1][i] == 10) {
            if(test[3][i] != 19)
                return false;
            else
                break;
        }
    }
    for(int i = 0; i < 5; i++) {
        if(test[1][i] == 9) {
            if(i == 0 && test[0][1] != 5)
                return false;
            else if(i == 4 && test[0][3] != 5)
                return false;
            else if(test[0][i - 1] != 5 && test[0][i + 1] != 5)
                return false;
            else
                break;
        }
    }
    for(int i = 0; i < 5; i++) {
        if(test[3][i] == 17) {
            if(i == 0 && test[2][1] != 15)
                return false;
            else if(i == 4 && test[2][3] != 15)
                return false;
            else if(test[2][i - 1] != 15 && test[2][i + 1] != 15)
                return false;
            else
                break;
        }
    }
    return true;
}



void dfs(int dep) {
    if(dep == 5) {
        if(check()) {
            printf("House     Color    Nation     Drink Cigarette       Pet\n");
            printf("        H1         %2d        %2d        %2d        %2d        %2d\n", test[0][0], test[1][0],  test[2][0],  test[3][0], test[4][0]);
            printf("        H2         %2d        %2d        %2d        %2d        %2d\n", test[0][1], test[1][1],  test[2][1], test[3][1], test[4][1]);
            printf("        H3         %2d        %2d        %2d        %2d        %2d\n", test[0][2], test[1][2],  test[2][2], test[3][2], test[4][2]);
            printf("        H4         %2d        %2d        %2d        %2d        %2d\n", test[0][3], test[1][3],  test[2][3], test[3][3], test[4][3]);
            printf("        H5         %2d        %2d        %2d        %2d        %2d\n", test[0][4], test[1][4],  test[2][4], test[3][4], test[4][4]);
            flag = true;
        }
        return;
    }
    do {

        dfs(dep + 1);
        if(flag) return;

    } while(next_permutation(test[dep], test[dep] + 5));
}

int main() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            test[i][j] = i * 5 + j + 1;
            printf("%d%c", test[i][j], " \n"[j == 4]);
        }
    }
    dfs(0);
    system("PAUSE");
    system("PAUSE");
    system("PAUSE");
    system("PAUSE");
    return 0;
}

*/

/*

House Color      Nation    Drink     Cigarette     Pet

      red        UK


                 RD                                 dog


                 DM        Tea




*/
#include <stdio.h>

int main() {
    puts("House     Color    Nation     Drink Cigarette       Pet");
    puts("H1         4         9        15        20        23");
    puts("H2         5         8        11        17        24");
    puts("H3         1         6        13        16        22");
    puts("H4         2        10        12        19        25");
    puts("H5         3         7        14        18        21");
    return 0;
}
