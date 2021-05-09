// Copyright 2021 NNTU-CS

int countPairs1(int* arr, int len, int value) {
int n = 0;
for (int i = 0; i < len - 1; i++) {
for (int j = i + 1; j < len; j++) {
if (arr[i] + arr[j] == value)
n++;
}
}
return n;
}

int countPairs2(int* arr, int len, int value) {
int n = 0, l = 0, r = len - 1;
for (r; arr[r] > value; r--) {}
for (r; r > 0; r--) {
for (l; l < r; l++)
if (arr[l] + arr[r] == value)
n++;
l = 0;
}
return n;
}

int countPairs3(int* arr, int len, int value) {
int n = 0;
for (int i = 0; i < len - 1; i++) {
int l = i + 1, r = len, x = value - arr[i];
for (; l < r;) {
int mid = l + (r - l) / 2;
if (arr[mid] == x) {
for (; arr[mid - 1] == x && mid > l; mid--) {}
for (; arr[mid] == x; mid++, n++) {}
break;
} else if (arr[mid] < x) {
l = mid + 1;
} else {
r = mid;
}
}
}
return n;
}
