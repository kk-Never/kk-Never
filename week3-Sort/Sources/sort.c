#include"sort.h"

int main()
{
	int Max;
	
	while (1) {
		menu();//�˵�����
		printf("�������鳤��:");
		scanf("%d", &Max); getchar();
		printf("����һ���������飺");
		int input[200];
		for (int i = 0; i < Max; i++) {
			scanf("%d", &input[i]);
			//getchar();
		}

		int max = input[0];
		int* temp = (int*)malloc(Max * sizeof(int));

		printf("ѡ������ʽ��");
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
	printf("1.���������㷨\n");
	printf("2.�鲢����\n");
	printf("3.�������򣨵ݹ�棩\n");
	printf("4.�������򣨷ǵݹ�棩\n");
	printf("5.��������\n");
	printf("6.������������\n");
	printf("7.��ɫ����\n");
}

// �������������ڴ�ӡ����
void PrintArray(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

// ���������㷨
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
	//�����Ϣ
	for (int i = 0; i < n; i++,p++) {
		printf("%d ",*p );
	}
	printf("\n");
	
}

//�鲢���򣨺ϲ����飩
void MergeArray(int* a, int begin, int mid, int end, int* temp) {
	int i = begin;       // ����������еĳ�ʼ����
	int j = mid + 1;     // �ұ��������еĳ�ʼ����
	int k = 0;           // ��ʱ����ĳ�ʼ����

	// ���������кϲ���temp������
	while (i <= mid && j <= end) {
		if (a[i] <= a[j]) 
			temp[k++] = a[i++];
		else 
			temp[k++] = a[j++];
	}

	// �����ʣ���Ԫ������temp��
	while (i <= mid) {
		temp[k++] = a[i++];
	}

	// ���ұ�ʣ���Ԫ������temp��
	while (j <= end) {
		temp[k++] = a[j++];
	}
		
	// ��temp�����Ԫ�ؿ�����ԭ����
	for (i = 0; i < k; i++) 
		a[begin + i] = temp[i];
}

// �鲢����
void MergeSort(int* a, int begin, int end, int* temp) {
	if (begin < end) {
		int mid = (begin + end) / 2;
		MergeSort(a, begin, mid, temp);      // ����������
		MergeSort(a, mid + 1, end, temp);    // ���Ұ������
		MergeArray(a, begin, mid, end, temp); // �ϲ���������
	}
	
}

//�������򣨵ݹ�棩
void QuickSort_Recursion(int* a, int begin, int end) {
	if (begin < end) {
		// ������������û�׼��λ��
		int partitionIndex = Partition(a, begin, end);

		// �ݹ�ضԻ�׼������������п�������
		QuickSort_Recursion(a, begin, partitionIndex - 1);

		// �ݹ�ضԻ�׼�Ҳ����������п�������
		QuickSort_Recursion(a, partitionIndex + 1, end);
	}
	
}

// ��������Ԫ�ص�ֵ
void Swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// ��������ķ�������,�������������ţ�
int Partition(int* a, int begin, int end) {
	int pivot = a[end]; // ѡ�����һ��Ԫ����Ϊ��׼
	int i = (begin - 1); // ָ��Ȼ�׼С��Ԫ�ص����һ��λ��

	for (int j = begin; j <= end - 1; j++) {
		// �����ǰԪ��С�ڻ���ڻ�׼
		if (a[j] <= pivot) {
			i++; // �ƶ�����һ��λ��
			Swap(&a[i], &a[j]); // ��������ȷ�ķ���
		}
	}
	Swap(&a[i + 1], &a[end]); // ����׼�ŵ���ȷ��λ��
	return (i + 1); // ���ػ�׼��λ��
}

//�������򣨷ǵݹ�棩
void QuickSort(int* a, int size) {
	// ʹ��ջ��ģ��ݹ����
	int stack[100];
	int top = -1;

	// ����ʼ��begin��endѹ��ջ��
	stack[++top] = 0;
	stack[++top] = size - 1;

	// ��ջ��Ϊ��ʱ��ѭ������
	while (top >= 0) {
		// ����ջ����end��begin
		int end = stack[top--];
		int begin = stack[top--];

		// ������������û�׼��λ��
		int pivotIndex = Partition(a, begin, end);

		// ����ߵ��������begin��endѹ��ջ��
		if (pivotIndex - 1 > begin) {
			stack[++top] = begin;
			stack[++top] = pivotIndex - 1;
		}

		// ���ұߵ��������begin��endѹ��ջ��
		if (pivotIndex + 1 < end) {
			stack[++top] = pivotIndex + 1;
			stack[++top] = end;
		}
	}

}


//��������
void CountSort(int* a, int size, int max) {
	int* count = (int*)calloc(max + 1, sizeof(int));
	/*if (count == NULL) {
		fprintf(stderr, "Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}*/

	// ����ÿ��Ԫ�ص�Ƶ��
	for (int i = 0; i < size; i++) {
		count[a[i]]++;
	}

	// �������ԭ����
	int index = 0;
	for (int i = 0; i <= max; i++) {
		while (count[i] > 0) {
			a[index++] = i;
			count[i]--;
		}
	}

	// �ͷż��������ڴ�
	free(count);

}

//������������
void RadixCountSort(int* a, int size) {
	int maxDigits = getMaxDigits(a, size);
	int exp = 1; // λ����Ȩ�أ���λΪ1��ʮλΪ10����λΪ100���Դ�����

	// �����������飬����ʼ��Ϊ0
	int count[10] = { 0 }; // ��Ϊ��������������ֻ��Ҫ0-9�ļ�����
	int* result = (int*)malloc(size * sizeof(int));

	for (int i = 0; i < maxDigits; i++) {
		// �����������
		for (int j = 0; j < 10; j++) {
			count[j] = 0;
		}

		// ����ÿ��Ԫ�ص�Ƶ��
		for (int j = 0; j < size; j++) {
			count[(a[j] / exp) % 10]++;
		}

		// ����������ת��Ϊ�ۼ�����
		for (int j = 1; j < 10; j++) {
			count[j] += count[j - 1];
		}

		// �Ӻ���ǰ�������������
		for (int j = size - 1; j >= 0; j--) {
			result[count[(a[j] / exp) % 10] - 1] = a[j];
			count[(a[j] / exp) % 10]--;
		}

		// �����������鿽����ԭ����
		for (int j = 0; j < size; j++) {
			a[j] = result[j];
		}

		// λ����Ȩ�����ӵ���һ��λ��
		exp *= 10;
	}

	// �ͷ���ʱ�����ڴ�
	free(result);

}

// ��ȡ�������λ��
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


//��ɫ����, ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
void ColorSort(int* a, int size) {
	int low = 0; // lowָ����߶���0
	int mid = 0; // midָ����߶���0��1
	int high = size - 1; // highָ����߶���0��1��2

	while (mid <= high) {
		switch (a[mid]) {
		case 0:
			// �����0������lowָ����ָ��Ԫ�ؽ���������low��midָ������
			a[mid] = a[low];
			a[low] = 0;
			low++;
			mid++;
			break;
		case 1:
			// �����1����midָ������
			mid++;
			break;
		case 2:
			// �����2������highָ����ָ��Ԫ�ؽ���������highָ������
			a[mid] = a[high];
			a[high] = 2;
			high--;
			break;
		}
	}

}