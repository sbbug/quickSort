#include<iostream>
using namespace std;

//划分算法，给定一个数，找到这个数最数组中的位置，使它前面的数
//比它小，后面的数都比它大。
int partition(int A[],int first,int last){

	int low = first;
	int high = last;

	int pivot;
	pivot = A[low];//这里默认从第一位开始找标志位
	
	while (low < high) {//开始寻找数据

		    //先从后往前找，一个一个找
		    while (low < high && A[high] > pivot) high--;
		    A[low] = A[high];
			//从前往后找
			while (low < high && A[low] < pivot) low++;
			A[high] = A[low];
	}
	
	A[low] = pivot;//找到A[low]的位置

	return low;//将这个位置作为参数返回，以便在quick_sort()里进行划分
}

void quick_sort(int A[],int low,int high){
      
	if (low > high) return;//如果low<high,就返回

	int mid = partition(A, low, high);

	quick_sort(A,low,mid-1);//划分前半部分，
	quick_sort(A, mid + 1, high);//划分后半部分

}

void output(int *ptr) {
	cout << endl;
	for (int i = 0;i < 10;i++)cout << ptr[i] << '\t';
	cout << endl;
}

int main() {

	int A[10] = { 3,1,5,6,7,9,0,2,4,8 };

	output(A);
	quick_sort(A, 0, 9);//调用排序方法进行排序
	output(A);
	
	system("PAUSE");
	return 0;
}