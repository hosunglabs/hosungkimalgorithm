//
//  1701.cpp
//  HosungAlgorithm
//
//  Created by HosungKim on 2017. 1. 12..
//  Copyright © 2017년 HosungKim. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
vector<int> preprocessing(string p) {
    int m = p.size();
    vector<int> next(m);
    next[0] = 0;
    int j = 0;
    for (int i=1; i<m; i++) {
        while (j>0 && p[i] != p[j]) {
            j = next[j-1];
        }
        if (p[i] == p[j]) {
            next[i] = j+1;
            j += 1;
        } else {
            next[i] = 0;
        }
    }
    return next;
}
int main() {
    string s;
    cin >> s;
    reverse(s.begin(),s.end());
    string a;
    int ans = 0;
    for (char c : s) {
        a = c + a;
        vector<int> next = preprocessing(a);
        int m = next.size();
        for (int i=0; i<m; i++) {
            if (ans < next[i]) ans = next[i];
        }
    }
    cout << ans << '\n';
    return 0;
}
