#include <iostream>
using namespace std;
void selectSort(int R[],int n);
void outPutArr(int arr[],int n);

void main(){
	int arr[] = { 68,23,32,0,-33,23,41,999,-1,66 };
	int len = sizeof(arr) / sizeof(arr[0]);
	selectSort(arr,len);
}

/**
��ѡ�������㷨
*/
void selectSort(int R[], int n){
	int i, j, k;
	int temp;
	for(i = 0; i < n; i++){
		k = i;
		/*�������ѭ�����㷨�Ĺؼ���������������������һ����С�Ĺؼ���*/
		for(j = i + 1; j < n; j++){
			if(R[k] > R[j]){
				k = j;
			}
		}
		/*���������������С�ؼ������������е�һ���ؼ��ֵĽ���*/
		temp = R[i];
		R[i] = R[k];
		R[k] = temp;
	}
	outPutArr(R,n);
}


/**
����������
*/
void outPutArr(int arr[],int n){
	cout <<"<��ѡ�������㷨>\r\n"<<endl;
	cout <<"���鳤�ȣ�"<<n<<"\r\n"<<endl;
	cout <<"�������У�";
	for(int i=0;i<n;i++){
		if(i<n-1){
			cout << arr[i] << " , ";
		}else{
			cout << arr[i] <<";\r\n"<<endl;
		}
	}
}

