#inlucde <iostream>
using namespace std;

void selectSort(int *L, int len) {
	for (int i = 0; i < len - 1; i++) {
		int min = i;
		for (int j = i + 1; j < len; j++) {
			if (L[i] < L[min])
				min = j;
		}
		int temp = L[i];
		L[i] = L[min];
		L[min] = temp;
	}
}

int main() {

	return 0;
}
