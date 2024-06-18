//
// Created by LINBEI on 6/18/2024.
//
int ternarySearch(vector<int> &arr, int x) {
    int left = 0;
    int right = arr.size() - 1;
    while (right >= left) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;
        if (arr[mid1] == x) {
            return mid1;
        }
        if (arr[mid2] == x) {
            return mid2;
        }
        if (x < arr[mid1]) {
            right = mid1 - 1;
        } else if (x > arr[mid2]) {
            left = mid2 + 1;
        } else {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }
    return -1; // target value not found
}

void merge(vector<int> &arr, int start, int mid1, int mid2, int end, vector<int> &temp) {
    int i = start, j = mid1, k = mid2, l = start;

    while ((i < mid1) && (j < mid2) && (k < end)) {
        if (arr[i] < arr[j]) {
            if (arr[i] < arr[k]) {
                temp[l++] = arr[i++];
            } else {
                temp[l++] = arr[k++];
            }
        } else {
            if (arr[j] < arr[k]) {
                temp[l++] = arr[j++];
            } else {
                temp[l++] = arr[k++];
            }
        }
    }

    while ((i < mid1) && (j < mid2)) {
        if (arr[i] < arr[j]) {
            temp[l++] = arr[i++];
        } else {
            temp[l++] = arr[j++];
        }
    }

    while ((j < mid2) && (k < end)) {
        if (arr[j] < arr[k]) {
            temp[l++] = arr[j++];
        } else {
            temp[l++] = arr[k++];
        }
    }

    while ((i < mid1) && (k < end)) {
        if (arr[i] < arr[k]) {
            temp[l++] = arr[i++];
        } else {
            temp[l++] = arr[k++];
        }
    }

    while (i < mid1)
        temp[l++] = arr[i++];

    while (j < mid2)
        temp[l++] = arr[j++];

    while (k < end)
        temp[l++] = arr[k++];

    for (i = start; i < end; i++) {
        arr[i] = temp[i];
    }
}

void threeWayMergeSort(vector<int> &arr, int start, int end, vector<int> &temp) {
    if (end - start < 2)
        return;

    int mid1 = start + (end - start) / 3;
    int mid2 = start + 2 * (end - start) / 3 + 1;

    threeWayMergeSort(arr, start, mid1, temp);
    threeWayMergeSort(arr, mid1, mid2, temp);
    threeWayMergeSort(arr, mid2, end, temp);

    merge(arr, start, mid1, mid2, end, temp);
}

void threeWayMergeSort(vector<int> &arr) {
    vector<int> temp(arr.size());
    threeWayMergeSort(arr, 0, arr.size(), temp);
}