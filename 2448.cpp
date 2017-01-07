//
//  2448.cpp
//  HosungAlgorithm
//
//  Created by HosungKim on 2017. 1. 8..
//  Copyright © 2017년 HosungKim. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define BLANK 0
#define STAR 1
void go(char **a, int x, int y, int n, int color) {
    int i,j,k;
    if (color == BLANK) {
        k=2*n-1;
        for (i=x; i<x+n; i++) {
            for (j=0; j<k; j++) {
                a[i][j+i-x+y] = ' ';
            }
            k-=2;
        }
    } else if (color == STAR) {
        if (n != 1) {
            int m = n/2;
            go(a,x,y,m,STAR);
            go(a,x+m,y-m,m,STAR);
            go(a,x+m,y+m,m,STAR);
            if (n == 3) {
                go(a,x+1,y,1,BLANK);
            } else {
                go(a,x+m,y-m+1,m,BLANK);
            }
        }
    }
}
int main() {
    int n;
    int i,j;
    char **a;
    scanf("%d",&n);
    a = (char **)malloc(sizeof(char *)*n);
    for (i=0; i<n; i++) {
        a[i] = (char *)malloc(sizeof(char)*(2*n+1));
    }
    for (i=0; i<n; i++) {
        for (j=0; j<2*n; j++) {
            a[i][j] = '*';
        }
        a[i][2*n] = 0;
    }
    go(a,0,n-1,n,STAR);
    for (i=0; i<n; i++) {
        for (j=0; j<n-i-1; j++) {
            a[i][j] = ' ';
            a[i][2*n-j-2] = ' ';
        }
        a[i][2*n-1]=' ';
    }
    for (i=0; i<n; i++) {
        printf("%s\n",a[i]);
    }
    return 0;
}
