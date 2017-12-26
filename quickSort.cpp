#include<iostream>
using namespace std;

//�����㷨������һ�������ҵ�������������е�λ�ã�ʹ��ǰ�����
//����С�����������������
int partition(int A[],int first,int last){

	int low = first;
	int high = last;

	int pivot;
	pivot = A[low];//����Ĭ�ϴӵ�һλ��ʼ�ұ�־λ
	
	while (low < high) {//��ʼѰ������

		    //�ȴӺ���ǰ�ң�һ��һ����
		    while (low < high && A[high] > pivot) high--;
		    A[low] = A[high];
			//��ǰ������
			while (low < high && A[low] < pivot) low++;
			A[high] = A[low];
	}
	
	A[low] = pivot;//�ҵ�A[low]��λ��

	return low;//�����λ����Ϊ�������أ��Ա���quick_sort()����л���
}

void quick_sort(int A[],int low,int high){
      
	if (low > high) return;//���low<high,�ͷ���

	int mid = partition(A, low, high);

	quick_sort(A,low,mid-1);//����ǰ�벿�֣�
	quick_sort(A, mid + 1, high);//���ֺ�벿��

}

void output(int *ptr) {
	cout << endl;
	for (int i = 0;i < 10;i++)cout << ptr[i] << '\t';
	cout << endl;
}

int main() {

	int A[10] = { 3,1,5,6,7,9,0,2,4,8 };

	output(A);
	quick_sort(A, 0, 9);//�������򷽷���������
	output(A);
	
	system("PAUSE");
	return 0;
}