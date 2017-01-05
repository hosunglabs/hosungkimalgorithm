//
//  main.cpp
//  HosungAlgorithm
//
//  Created by HosungKim on 2017. 1. 5..
//  Copyright © 2017년 HosungKim. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
int C,D,dd;
int d[222][111][111][2][2];
int n,m;
int a[111];
int b[111];
int go(int day, int x, int y, int sx, int sy) {
    if (x==n && y==m) return 0;
    if (day>=210) return 1000000;
    if (d[day][x][y][sx][sy] != -1)
        return d[day][x][y][sx][sy];
    int &ans = d[day][x][y][sx][sy];
    if (x<n && y<m) {
        int temp = C;
        if (a[x] != b[y])
            temp += C;
        if (ans == -1 || ans > temp + go(day+1,x+1,y+1,0,0))
            ans = temp + go(day+1,x+1,y+1,0,0);
    }
    if (x<n) {
        int temp = C;
        temp += dd;
        if (sy == 0)
            temp += D;
        if (ans == -1 || ans > temp + go(day+1,x+1,y,0,1))
            ans = temp+go(day+1,x+1,y,0,1);
    }
    if (y<m) {
        int temp = C;
        temp += dd;
        if (sx == 0)
            temp += D;
        if (ans == -1 || ans > temp + go(day+1,x,y+1,1,0))
            ans = temp + go(day+1,x,y+1,1,0);
    }
    int temp = 0;
    temp += dd;
    temp += dd;
    if (sx== 0) temp += D;
    if (sy == 0) temp += D;
    if (ans == -1 || ans > temp + go(day+1,x,y,1,1))
        ans = temp+go(day+1,x,y,1,1);
    return ans;
}
int main() {
    int t;
    scanf("%d\n",&t);
    while(t--) {
        scanf("%d %d %d\n",&C,&D,&dd);
        n=0;
        m=0;
        while(true){
            int temp;
            scanf("%d",&temp);
            if (temp==0)
                break;
            a[n++]= temp;
        }
        while(true){
            int temp;
            scanf("%d",&temp);
            if (temp==0)
                break;
            b[m++] = temp;
        }
        memset(d,-1,sizeof(d));
        printf("%d\n", go(0,0,0,0,0));
    }
}
