// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value)
{
    int c = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                c++;
            }
        }
    }
    return c;
}

int countPairs2(int* arr, int len, int value)
{
    int c = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        if (arr[left] + arr[right] == value) {
            c++;
            left++;
            right--;
        }
        else if (arr[left] + arr[right] < value) {
            left++;
        }
        else {
            right--;
        }
    }
    return c;
}

int binarySearch(int* arr, int l, int r, int x)
{
    while (l <= r) {
        int middle = l + (r - l) / 2;
        if (arr[middle] == x) {
            return middle;
        }
        else if (arr[middle] < x) {
            l = middle + 1;
        }
        else {
            r = middle - 1;
        }
    }
    return -1;
}

int countPairs3(int* arr, int len, int value)
{
    int c = 0;
    for (int i = 0; i < len; i++) {
        int index = binarySearch(arr, i + 1, len - 1, value - arr[i]);
        if (index != -1 && arr[index] != arr[i]) {
            c++;
        }
    }
    return c;
}
