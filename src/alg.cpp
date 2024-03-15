// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int c = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                c++;
            }
        }
    }
    return c;
}
int countPairs2(int* arr, int len, int value) {
    int c = 0;
    for (int left = 0; left < len - 1; left++) {
        for (int right = left + 1; right < len; right++) {
            if (arr[left] + arr[right] == value) {
                c++;
            }
        }
    }
    return c;
}
int binarySearch(int* arr, int l, int r, int x) {
    while (l <= r) {
        int middle = l + (r - l) / 2;
        if (arr[middle] == x) {
            return middle;
        } else if (arr[middle] < x) {
            l = middle + 1;
        } else {
            r = middle - 1;
        }
    }
    return -1;
}
int countPairs3(int* arr, int len, int value) {
    int c = 0;
    for (int i = 0; i < len - 1; i++) {
        int index = binarySearch(arr, i + 1, len - 1, value - arr[i]);
        if (index != -1) {
            c++;
        }
    }
    return c;
}
