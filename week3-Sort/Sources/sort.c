#include"sort.h"

int main()
{
	int Max;
	
	while (1) {
		menu();//菜单函数
		printf("输入数组长度:");
		scanf("%d", &Max); getchar();
		printf("输入一个整型数组：");
		int input[200];
		for (int i = 0; i < Max; i++) {
			scanf("%d", &input[i]);
			//getchar();
		}

		int max = input[0];
		int* temp = (int*)malloc(Max * sizeof(int));

		printf("选择排序方式：");
		int choose;
		scanf("%d", &choose);
		getchar();
		switch (choose)
		{
		case 1:
			insertSort(input,Max);
			system("pause");
			system("cls");
			break;
		case 2:
			MergeSort(input, 0, Max-1, temp);
			PrintArray(input, Max);
			system("pause");
			system("cls");
			break;
		case 3:
			QuickSort_Recursion(input, 0,Max-1);
			PrintArray(input, Max);
			system("pause");
			system("cls");
			break;
		case 4:
			QuickSort(input, Max);
			PrintArray(input, Max);
			system("pause");
			system("cls");
			break;
		case 5:
			for (int i = 1; i < Max; i++) {
				if (max < input[i])
					max = input[i];
			}
			CountSort(input, Max, max);
			PrintArray(input, Max);
			system("pause");
			system("cls");
			break;
		case 6:
			RadixCountSort(input, Max);
			PrintArray(input, Max);
			system("pause");
			system("cls");
			break;
		case 7:
			ColorSort(input,Max);
			PrintArray(input, Max);
			system("pause");
			system("cls");
			break;
		default:
			printf("ERROR!");
			break;
		}
	}
	
}

void menu()
{
	printf("1.插入排序算法\n");
	printf("2.归并排序\n");
	printf("3.快速排序（递归版）\n");
	printf("4.快速排序（非递归版）\n");
	printf("5.计数排序\n");
	printf("6.基数计数排序\n");
	printf("7.颜色排序\n");
}

// 辅助函数，用于打印数组
void PrintArray(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

// 插入排序算法
void insertSort(int* a, int n) {
	int key, i,j;
	int* p = a;
	for (i = 1; i < n; i++) {
		key =a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
	//输出信息
	for (int i = 0; i < n; i++,p++) {
		printf("%d ",*p );
	}
	printf("\n");
	
}

//归并排序（合并数组）
void MergeArray(int* a, int begin, int mid, int end, int* temp) {
	int i = begin;       // 左边有序序列的初始索引
	int j = mid + 1;     // 右边有序序列的初始索引
	int k = 0;           // 临时数组的初始索引

	// 将有序序列合并到temp数组中
	while (i <= mid && j <= end) {
		if (a[i] <= a[j]) 
			temp[k++] = a[i++];
		else 
			temp[k++] = a[j++];
	}

	// 将左边剩余的元素填充进temp中
	while (i <= mid) {
		temp[k++] = a[i++];
	}

	// 将右边剩余的元素填充进temp中
	while (j <= end) {
		temp[k++] = a[j++];
	}
		
	// 将temp数组的元素拷贝回原数组
	for (i = 0; i < k; i++) 
		a[begin + i] = temp[i];
}

// 归并排序
void MergeSort(int* a, int begin, int end, int* temp) {
	if (begin < end) {
		int mid = (begin + end) / 2;
		MergeSort(a, begin, mid, temp);      // 将左半边排序
		MergeSort(a, mid + 1, end, temp);    // 将右半边排序
		MergeArray(a, begin, mid, end, temp); // 合并有序数组
	}
	
}

//快速排序（递归版）
void QuickSort_Recursion(int* a, int begin, int end) {
	if (begin < end) {
		// 分区操作，获得基准的位置
		int partitionIndex = Partition(a, begin, end);

		// 递归地对基准左侧的子数组进行快速排序
		QuickSort_Recursion(a, begin, partitionIndex - 1);

		// 递归地对基准右侧的子数组进行快速排序
		QuickSort_Recursion(a, partitionIndex + 1, end);
	}
	
}

// 交换两个元素的值
void Swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// 快速排序的分区函数,快速排序（枢轴存放）
int Partition(int* a, int begin, int end) {
	int pivot = a[end]; // 选择最后一个元素作为基准
	int i = (begin - 1); // 指向比基准小的元素的最后一个位置

	for (int j = begin; j <= end - 1; j++) {
		// 如果当前元素小于或等于基准
		if (a[j] <= pivot) {
			i++; // 移动到下一个位置
			Swap(&a[i], &a[j]); // 交换到正确的分区
		}
	}
	Swap(&a[i + 1], &a[end]); // 将基准放到正确的位置
	return (i + 1); // 返回基准的位置
}

//快速排序（非递归版）
void QuickSort(int* a, int size) {
	// 使用栈来模拟递归过程
	int stack[100];
	int top = -1;

	// 将初始的begin和end压入栈中
	stack[++top] = 0;
	stack[++top] = size - 1;

	// 当栈不为空时，循环继续
	while (top >= 0) {
		// 弹出栈顶的end和begin
		int end = stack[top--];
		int begin = stack[top--];

		// 分区操作，获得基准的位置
		int pivotIndex = Partition(a, begin, end);

		// 将左边的子数组的begin和end压入栈中
		if (pivotIndex - 1 > begin) {
			stack[++top] = begin;
			stack[++top] = pivotIndex - 1;
		}

		// 将右边的子数组的begin和end压入栈中
		if (pivotIndex + 1 < end) {
			stack[++top] = pivotIndex + 1;
			stack[++top] = end;
		}
	}

}


//计数排序
void CountSort(int* a, int size, int max) {
	int* count = (int*)calloc(max + 1, sizeof(int));
	/*if (count == NULL) {
		fprintf(stderr, "Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}*/

	// 计算每个元素的频率
	for (int i = 0; i < size; i++) {
		count[a[i]]++;
	}

	// 重新填充原数组
	int index = 0;
	for (int i = 0; i <= max; i++) {
		while (count[i] > 0) {
			a[index++] = i;
			count[i]--;
		}
	}

	// 释放计数数组内存
	free(count);

}

//基数计数排序
void RadixCountSort(int* a, int size) {
	int maxDigits = getMaxDigits(a, size);
	int exp = 1; // 位数的权重，个位为1，十位为10，百位为100，以此类推

	// 创建计数数组，并初始化为0
	int count[10] = { 0 }; // 因为是整数排序，所以只需要0-9的计数器
	int* result = (int*)malloc(size * sizeof(int));

	for (int i = 0; i < maxDigits; i++) {
		// 清零计数数组
		for (int j = 0; j < 10; j++) {
			count[j] = 0;
		}

		// 计算每个元素的频率
		for (int j = 0; j < size; j++) {
			count[(a[j] / exp) % 10]++;
		}

		// 将计数数组转换为累加数组
		for (int j = 1; j < 10; j++) {
			count[j] += count[j - 1];
		}

		// 从后向前填充排序后的数组
		for (int j = size - 1; j >= 0; j--) {
			result[count[(a[j] / exp) % 10] - 1] = a[j];
			count[(a[j] / exp) % 10]--;
		}

		// 将排序后的数组拷贝回原数组
		for (int j = 0; j < size; j++) {
			a[j] = result[j];
		}

		// 位数的权重增加到下一个位数
		exp *= 10;
	}

	// 释放临时数组内存
	free(result);

}

// 获取最大数的位数
int getMaxDigits(int* a, int size) {
	int max = INT_MIN;
	for (int i = 0; i < size; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	int digits = 0;
	while (max != 0) {
		digits++;
		max /= 10;
	}
	return digits;
}


//颜色排序, 数组指针a（只含0，1，2元素），数组长度size
void ColorSort(int* a, int size) {
	int low = 0; // low指针左边都是0
	int mid = 0; // mid指针左边都是0和1
	int high = size - 1; // high指针左边都是0、1和2

	while (mid <= high) {
		switch (a[mid]) {
		case 0:
			// 如果是0，则与low指针所指的元素交换，并将low和mid指针右移
			a[mid] = a[low];
			a[low] = 0;
			low++;
			mid++;
			break;
		case 1:
			// 如果是1，则mid指针右移
			mid++;
			break;
		case 2:
			// 如果是2，则与high指针所指的元素交换，并将high指针左移
			a[mid] = a[high];
			a[high] = 2;
			high--;
			break;
		}
	}

}