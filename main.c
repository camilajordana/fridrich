/* 
 * File:   main.c
 * Author: camila
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 1º passo: fazer a cruz branca  (OK)
 */

struct Face {
    int face[3][3];
};

typedef struct Cubo {
    struct Face front;
    struct Face top;
    struct Face bottom;
    struct Face right;
    struct Face left;
    struct Face back;
};

char historyMoviments[1000000];

int montando = 0;

int top_1[3];
int top_2[3];

int topI_1[3];
int topI_2[3];

int bottom_1[3];
int bottom_2[3];

int bottomI_1[3];
int bottomI_2[3];


int left_1[3];
int left_2[3];

int leftI_1[3];
int leftI_2[3];

int right_1[3];
int right_2[3];

int rightI_1[3];
int rightI_2[3];

void turnClock(int face[][3]) {
    int aux1, aux2;
    //girando os elementos das pontas
    aux1 = face[0][0];
    aux2 = face[0][2];
    face[0][2] = aux1;
    aux1 = face[2][2];
    face[2][2] = aux2;
    aux2 = face[2][0];
    face[2][0] = aux1;
    face[0][0] = aux2;
    //girando os elementos do meio
    aux1 = face[0][1];
    aux2 = face[1][2];
    face[1][2] = aux1;
    aux1 = face[2][1];
    face[2][1] = aux2;
    aux2 = face[1][0];
    face[1][0] = aux1;
    face[0][1] = aux2;
}

void turnClock180(int face[][3]) {
    turnClock(face);
    turnClock(face);
}

void turnIClock(int face[][3]) {
    turnClock(face);
    turnClock(face);
    turnClock(face);
}

void getTop(int face[][3], int v) {
    if (v == 1) {
        top_1[0] = face[0][0];
        top_1[1] = face[0][1];
        top_1[2] = face[0][2];
    } else {
        top_2[0] = face[0][0];
        top_2[1] = face[0][1];
        top_2[2] = face[0][2];
    }
}

void getTopI(int face[][3], int v) {
    if (v == 1) {
        topI_1[0] = face[0][2];
        topI_1[1] = face[0][1];
        topI_1[2] = face[0][0];
    } else {
        topI_2[0] = face[0][2];
        topI_2[1] = face[0][1];
        topI_2[2] = face[0][0];
    }
}

void setTop(int face[][3], int t[]) {
    face[0][0] = t[0];
    face[0][1] = t[1];
    face[0][2] = t[2];
}

void getBottom(int face[][3], int v) {
    if (v == 1) {
        bottom_1[0] = face[2][0];
        bottom_1[1] = face[2][1];
        bottom_1[2] = face[2][2];
    } else {
        bottom_2[0] = face[2][0];
        bottom_2[1] = face[2][1];
        bottom_2[2] = face[2][2];
    }
}

void getBottomI(int face[][3], int v) {
    if (v == 1) {
        bottomI_1[0] = face[2][2];
        bottomI_1[1] = face[2][1];
        bottomI_1[2] = face[2][0];
    } else {
        bottomI_2[0] = face[2][2];
        bottomI_2[1] = face[2][1];
        bottomI_2[2] = face[2][0];
    }
}

void setBottom(int face[][3], int b[]) {
    face[2][0] = b[0];
    face[2][1] = b[1];
    face[2][2] = b[2];
}

void getLeft(int face[][3], int v) {
    if (v == 1) {
        left_1[0] = face[0][0];
        left_1[1] = face[1][0];
        left_1[2] = face[2][0];
    } else {
        left_2[0] = face[0][0];
        left_2[1] = face[1][0];
        left_2[2] = face[2][0];
    }
}

void getLeftI(int face[][3], int v) {
    if (v == 1) {
        leftI_1[0] = face[2][0];
        leftI_1[1] = face[1][0];
        leftI_1[2] = face[0][0];
    } else {
        leftI_2[0] = face[2][0];
        leftI_2[1] = face[1][0];
        leftI_2[2] = face[0][0];
    }
}

void setLeft(int face[][3], int l[]) {
    face[0][0] = l[0];
    face[1][0] = l[1];
    face[2][0] = l[2];
}

void getRight(int face[][3], int v) {
    if (v == 1) {
        right_1[0] = face[0][2];
        right_1[1] = face[1][2];
        right_1[2] = face[2][2];
    } else {
        right_2[0] = face[0][2];
        right_2[1] = face[1][2];
        right_2[2] = face[2][2];
    }
}

void getRightI(int face[][3], int v) {
    if (v == 1) {
        rightI_1[0] = face[2][2];
        rightI_1[1] = face[1][2];
        rightI_1[2] = face[0][2];
    } else {
        rightI_2[0] = face[2][2];
        rightI_2[1] = face[1][2];
        rightI_2[2] = face[0][2];
    }
}

void setRight(int face[][3], int r[]) {
    face[0][2] = r[0];
    face[1][2] = r[1];
    face[2][2] = r[2];
}

//MÉTODOS DA CLASSE CUBO

void frontClock(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {

    turnClock(front_f);
    getBottom(top_f, 1);
    getLeftI(right_f, 1);
    getTop(bottom_f, 1);
    getRightI(left_f, 1);
    setBottom(top_f, rightI_1);
    setLeft(right_f, bottom_1);
    setTop(bottom_f, leftI_1);
    setRight(left_f, top_1);
    if (montando == 1) {
        strcat(historyMoviments, "frontClock\n");
    }

}

void frontClock180(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {
    frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);

}

void frontIClock(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {
    frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
}

void rightClock(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {
    turnClock(right_f);
    getRightI(top_f, 1);
    getRightI(back_f, 2);
    getRight(bottom_f, 1);
    getRight(front_f, 2);
    setRight(top_f, right_2);
    setRight(back_f, rightI_1);
    setRight(bottom_f, rightI_2);
    setRight(front_f, right_1);
    if (montando == 1) {
        strcat(historyMoviments, "rightClock\n");
    }
}

void rightClock180(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {
    rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
}

void rightIClock(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {
    rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    //historyMoviments += "rightIClock\n";
}

void leftClock(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {
    turnClock(left_f);
    getLeft(top_f, 1);
    getLeft(front_f, 2);
    getLeftI(bottom_f, 1);
    getLeftI(back_f, 2);
    setLeft(top_f, leftI_2);
    setLeft(front_f, left_1);
    setLeft(bottom_f, left_2);
    setLeft(back_f, leftI_1);
    if (montando == 1) {
        strcat(historyMoviments, "leftClock\n");

    }
}

void leftClock180(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {
    leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    //historyMoviments += "leftClock180\n";
}

void leftIClock(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {
    leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    //historyMoviments += "leftIClock\n";
}

void bottomIClock(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {
    turnIClock(bottom_f);
    getBottom(right_f, 1);
    getBottom(front_f, 2);
    getBottomI(left_f, 1);
    getBottomI(back_f, 2);
    setBottom(right_f, bottomI_2);
    setBottom(front_f, bottom_1);
    setBottom(left_f, bottom_2);
    setBottom(back_f, bottomI_1);
    if (montando == 1) {
        strcat(historyMoviments, "bottomIClock\n");
    }

}

void bottomClock180(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {
    bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    //historyMoviments += "bottomClock180\n";
}

void bottomClock(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {
    bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    //historyMoviments += "bottomClock\n";
}

void backIClock(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {
    turnClock(back_f);
    getTop(top_f, 1);
    getRightI(right_f, 1);
    getBottom(bottom_f, 1);
    getLeftI(left_f, 1);
    setTop(top_f, leftI_1);
    setRight(right_f, top_1);
    setBottom(bottom_f, rightI_1);
    setLeft(left_f, bottom_1);
    if (montando == 1) {
        strcat(historyMoviments, "backIClock\n");
    }

}

void backClock180(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {
    backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    //historyMoviments += "backClock180\n";
}

void backClock(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {
    backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    //historyMoviments += "backClock\n";

}

void topClock(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {
    turnClock(top_f);
    getTop(right_f, 1);
    getTop(front_f, 2);
    getTopI(left_f, 1);
    getTopI(back_f, 2);
    setTop(right_f, topI_2);
    setTop(front_f, top_1);
    setTop(left_f, top_2);
    setTop(back_f, topI_1);
    if (montando == 1) {
        strcat(historyMoviments, "topClock\n");
    }

}

void topClock180(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {
    topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    //historyMoviments += "topClock180\n";
}

void topIClock(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {
    topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    //historyMoviments += "topIClock\n";
}

void cruz(int left_f[][3], int front_f[][3], int right_f[][3], int top_f[][3], int bottom_f[][3], int back_f[][3]) {

    //(1,3)
    if (bottom_f[1][2] == 1 && right_f[2][1] == 3) {
        bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (bottom_f[2][1] == 1 && back_f[2][1] == 3) {
        bottomClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (bottom_f[1][0] == 1 && left_f[2][1] == 3) {
        bottomClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[2][1] == 1 && bottom_f[0][1] == 3) {
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][2] == 1 && right_f[1][0] == 3) {
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][1] == 1 && top_f[2][1] == 3) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][0] == 1 && left_f[1][2] == 3) {
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][2] == 1 && front_f[1][0] == 3) {
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[2][1] == 1 && bottom_f[1][0] == 3) {
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][1] == 1 && top_f[1][0] == 3) {
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][0] == 1 && back_f[1][0] == 3) {
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][0] == 1 && front_f[1][2] == 3) {
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[2][1] == 1 && bottom_f[1][2] == 3) {
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 1 && back_f[1][2] == 3) {
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][1] == 1 && top_f[1][2] == 3) {
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][1] == 1 && front_f[0][1] == 3) {
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[1][0] == 1 && left_f[0][1] == 3) {
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[1][2] == 1 && right_f[0][1] == 3) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][1] == 1 && back_f[0][1] == 3) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][1] == 1 && top_f[0][1] == 3) {
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][0] == 1 && left_f[1][0] == 3) {
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][2] == 1 && right_f[1][2] == 3) {
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[2][1] == 1 && bottom_f[2][1] == 3) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        bottomClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    //(1,6)
    if (bottom_f[2][1] == 1 && back_f[2][1] == 6) {
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (bottom_f[1][2] == 1 && right_f[2][1] == 6) {
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[2][1] == 1 && bottom_f[1][0] == 6) {
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][2] == 1 && front_f[1][0] == 6) {
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][1] == 1 && top_f[1][0] == 6) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][0] == 1 && back_f[1][0] == 6) {
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][0] == 1 && front_f[1][2] == 6) {
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][1] == 1 && top_f[1][2] == 6) {
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 1 && back_f[1][2] == 6) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[2][1] == 1 && bottom_f[1][2] == 6) {
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][0] == 1 && left_f[1][2] == 6) {
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][1] == 1 && top_f[2][1] == 6) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][2] == 1 && right_f[1][0] == 6) {
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][1] == 1 && front_f[0][1] == 6) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[1][0] == 1 && left_f[0][1] == 6) {
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][1] == 1 && back_f[0][1] == 6) {
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[1][2] == 1 && right_f[0][1] == 6) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[2][1] == 1 && bottom_f[2][1] == 6) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][0] == 1 && left_f[1][0] == 6) {
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][2] == 1 && right_f[1][2] == 6) {
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][1] == 1 && top_f[0][1] == 6) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

    //(1,5)
    if (bottom_f[1][2] == 1 && right_f[2][1] == 5) {
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][0] == 1 && back_f[1][0] == 5) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][2] == 1 && front_f[1][0] == 5) {
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][1] == 1 && top_f[1][0] == 5) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][0] == 1 && front_f[1][2] == 5) {
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][1] == 1 && top_f[1][2] == 5) {
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 1 && back_f[1][2] == 5) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[2][1] == 1 && bottom_f[1][2] == 5) {
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][0] == 1 && left_f[1][2] == 5) {
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][2] == 1 && right_f[1][0] == 5) {
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][1] == 1 && top_f[2][1] == 5) {
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][1] == 1 && front_f[0][1] == 5) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[1][0] == 1 && left_f[0][1] == 5) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[1][2] == 1 && right_f[0][1] == 5) {
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][1] == 1 && back_f[0][1] == 5) {
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][1] == 1 && top_f[0][1] == 5) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][0] == 1 && left_f[1][0] == 5) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][2] == 1 && right_f[1][2] == 5) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[2][1] == 1 && bottom_f[2][1] == 5) {
        backClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }


    //(1,4)
    if (right_f[2][1] == 1 && bottom_f[1][2] == 4) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][0] == 1 && front_f[1][2] == 4) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[0][1] == 1 && top_f[1][2] == 4) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (right_f[1][2] == 1 && back_f[1][2] == 4) {
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][0] == 1 && left_f[1][2] == 4) {
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[1][2] == 1 && right_f[1][0] == 4) {
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (front_f[0][1] == 1 && top_f[2][1] == 4) {
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[0][1] == 1 && top_f[1][0] == 4) {
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][2] == 1 && front_f[1][0] == 4) {
        frontClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        frontIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (left_f[1][0] == 1 && back_f[1][0] == 4) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[2][1] == 1 && front_f[0][1] == 4) {
        topIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[1][2] == 1 && right_f[0][1] == 4) {
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[1][0] == 1 && left_f[0][1] == 4) {
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (top_f[0][1] == 1 && back_f[0][1] == 4) {
        topClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][2] == 1 && right_f[1][2] == 4) {
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[1][0] == 1 && left_f[1][0] == 4) {
        leftClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        topClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock180(left_f, front_f, right_f, top_f, bottom_f, back_f);
        leftIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    } else if (back_f[0][1] == 1 && top_f[0][1] == 4) {
        backIClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        rightClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
        backClock(left_f, front_f, right_f, top_f, bottom_f, back_f);
    }

}

void imprimirCubo(struct Cubo cubo) {
    int i, j;
    int matriz_front[3][3];
    int matriz_left[3][3];
    int matriz_right[3][3];
    int matriz_top[3][3];
    int matriz_back[3][3];
    int matriz_bottom[3][3];

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matriz_back[i][j] = cubo.back.face[i][j];
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matriz_front[i][j] = cubo.front.face[i][j];
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matriz_left[i][j] = cubo.left.face[i][j];
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matriz_right[i][j] = cubo.right.face[i][j];
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matriz_top[i][j] = cubo.top.face[i][j];
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matriz_bottom[i][j] = cubo.bottom.face[i][j];
        }
    }

    printf("        ");
    printf("%d %d %d\n", matriz_top[0][0], matriz_top[0][1], matriz_top[0][2]);
    printf("        ");
    printf("%d %d %d\n", matriz_top[1][0], matriz_top[1][1], matriz_top[1][2]);
    printf("        ");
    printf("%d %d %d\n", matriz_top[2][0], matriz_top[2][1], matriz_top[2][2]);
    printf("%d %d %d   %d %d %d   %d %d %d   %d %d %d\n", matriz_left[0][0], matriz_left[0][1], matriz_left[0][2], matriz_front[0][0], matriz_front[0][1], matriz_front[0][2], matriz_right[0][0], matriz_right[0][1], matriz_right[0][2], matriz_back[0][2], matriz_back[0][1], matriz_back[0][0]);
    printf("%d %d %d   %d %d %d   %d %d %d   %d %d %d\n", matriz_left[1][0], matriz_left[1][1], matriz_left[1][2], matriz_front[1][0], matriz_front[1][1], matriz_front[1][2], matriz_right[1][0], matriz_right[1][1], matriz_right[1][2], matriz_back[1][2], matriz_back[1][1], matriz_back[1][0]);
    printf("%d %d %d   %d %d %d   %d %d %d   %d %d %d\n", matriz_left[2][0], matriz_left[2][1], matriz_left[2][2], matriz_front[2][0], matriz_front[2][1], matriz_front[2][2], matriz_right[2][0], matriz_right[2][1], matriz_right[2][2], matriz_back[2][2], matriz_back[2][1], matriz_back[2][0]);
    printf("        ");
    printf("%d %d %d\n", matriz_bottom[0][0], matriz_bottom[0][1], matriz_bottom[0][2]);
    printf("        ");
    printf("%d %d %d\n", matriz_bottom[1][0], matriz_bottom[1][1], matriz_bottom[1][2]);
    printf("        ");
    printf("%d %d %d\n", matriz_bottom[2][0], matriz_bottom[2][1], matriz_bottom[2][2]);
}

int main(int argc, char** argv) {

    /*
       Branco(Bottom): 1
       Amarelo(Top): 2
       Verde(Front): 3
       Laranja(Right): 4
       Azul(Back): 5
       Vermelho(Left): 6
     */

    int i = 0, j = 0;
    struct Cubo cubo;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cubo.bottom.face[i][j] = 1;
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cubo.top.face[i][j] = 2;
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cubo.front.face[i][j] = 3;
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cubo.right.face[i][j] = 4;
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cubo.back.face[i][j] = 5;
        }
    }


    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cubo.left.face[i][j] = 6;
        }
    }


    frontClock180(cubo.left.face, cubo.front.face, cubo.right.face, cubo.top.face, cubo.bottom.face, cubo.back.face);
    topClock(cubo.left.face, cubo.front.face, cubo.right.face, cubo.top.face, cubo.bottom.face, cubo.back.face);
    leftClock(cubo.left.face, cubo.front.face, cubo.right.face, cubo.top.face, cubo.bottom.face, cubo.back.face);
    rightIClock(cubo.left.face, cubo.front.face, cubo.right.face, cubo.top.face, cubo.bottom.face, cubo.back.face);
    frontClock(cubo.left.face, cubo.front.face, cubo.right.face, cubo.top.face, cubo.bottom.face, cubo.back.face);
    bottomIClock(cubo.left.face, cubo.front.face, cubo.right.face, cubo.top.face, cubo.bottom.face, cubo.back.face);

    montando = 1;

    imprimirCubo(cubo);

    printf("\n\n");

    cruz(cubo.left.face, cubo.front.face, cubo.right.face, cubo.top.face, cubo.bottom.face, cubo.back.face);

    imprimirCubo(cubo);

    printf("%s", historyMoviments);

    return 0;
}

