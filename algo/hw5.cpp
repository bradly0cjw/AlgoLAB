bool found = false; //modified

void queens(index i) {
    int j;
    if (promising(i)) {
        if (i == n) {
            cout << col[1]
            through col[n];
            found = true; //modified
        } else {
            for (j = 1; j <= n && !found; j++) { //modified
                col[i + 1] = j;
                queens(i + 1);
            }
        }
    }
}

bool promising(index i) {
    int k;
    bool flag;
    flag = true;
    while (k < i && flag) {
        if (col[i] == col[k] || abs(col[i] - col[k]) == i - k)
            flag = false;
        k++;
    }
    return flag;
}

