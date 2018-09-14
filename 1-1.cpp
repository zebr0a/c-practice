#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int getPosition(int arr[],int low, int high, int value);
void quickSort(int arr[], int low, int high);

int main()
{
	int arr[MAX_SIZE];
	memset(arr, 0, MAX_SIZE);
	int n;
	printf("确定数组长度: ");
	scanf("%d", &n);
	printf("依次输入数据: ");

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int k;
	printf("确定要获取的第k个数: ");
	scanf("%d", &k);
	quickSort(arr, 0, k-1);

	for (int i = k; i < n; i++) {
		if (arr[i] <= arr[k - 1]) {
			continue;
		}
		int low = 0;
		int high = k - 1;
		int middle;

		while (low <= high) {
			middle = (low + high) / 2;
			if (arr[i] > arr[middle]) {
				high = middle - 1;
			} else if (arr[i] < arr[middle]) {
				low = middle + 1;
			}
		}

		if (low < (2 * i - n - 1)) {
			low = 2 * i - n - 2;
		}

		for (int j = k-1; j > low; j--) {
			arr[j] = arr[j - 1];
		}
		arr[low] = arr[i];
	}

	printf("第k个数字为: %d/n", arr[k - 1]);
}

int getPosition(int arr[], int low, int high, int value)
{
	int middle = (low + high) / 2;
	if (low > high) {
		return low;
	}
	if (arr[middle] < value) {
		return getPosition(arr, low, middle - 1, value);
	}
	else if (arr[middle] > value) {
		return getPosition(arr, middle + 1, high, value);
	}
}

void quickSort(int arr[], int low, int high)
{
	if (low >= high) {
		return;
	}
	int right = high;
	int left = low;
	int niddle = arr[left];
	while (left != right) {
		while (left != right && niddle > arr[right]) { right--; }
		arr[left] = arr[right];
		while (left != right && arr[left] > niddle) { left++; }
		arr[right] = arr[left];
	}
	arr[left] = niddle;
	quickSort(arr, low, left-1);
	quickSort(arr, left + 1, high);

}