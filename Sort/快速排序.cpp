#include <stdio.h>

#define Max 20

// 交换数组中两个元素的值
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 分割数组，并返回分割点下标
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // 选取最后一个元素作为基准
    int i = low - 1; // 记录小于基准的元素的位置

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// 快速排序算法
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // 划分
        int partitionIndex = partition(arr, low, high);

        // 递归排序划分的两部分
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

// 打印数组
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int a[Max];
	int n, k;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &k);

    printf("Original array: ");
    printArray(a, n);

    quickSort(a, 0, n - 1);

    printf("Sorted array: ");
    printArray(a, n);
    printf("\n%d", a[k - 1]);

    return 0;
}

