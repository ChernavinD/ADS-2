// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int n = 0;
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (arr[i] + arr[j] == value) {
				n++;
			}
		}
	}
	return n;
}

int countPairs2(int *arr, int len, int value) {
  int n = 0, l = 0, r = len - 1;
	while (l < r) {
		if (arr[l] + arr[r] > value)
			r--;
		else if (arr[l] + arr[r] < value)
			l++;
		else {
			n++;
			if (arr[r] == arr[r - 1])
				r--;
			else
				l++;
		}
	}
	return n;
}

int countPairs3(int *arr, int len, int value) {
  int i = 0, n = 0, l = 0, r = len - 1;
	bool flag = false;
	while (l < r) {
		int m = l + (r - l) / 2;
		if (arr[i] + arr[m] == value) {
			while (arr[i] + arr[m] == value)
				m--;
			m++;
			while (arr[i] + arr[m] == value) {
				n++;
				m++;
			}
			i++;
			flag = true;
		} else if (arr[i] + arr[m] > value) {
			r = m;
		} else {
			l = m + 1;
		}
		if (flag == true) {
			l = i;
			r = len - 1;
			flag = false;
		}
	}
	return n;
}
