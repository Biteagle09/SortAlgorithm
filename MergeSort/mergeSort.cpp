#include<iostream>
using namespace std;

void mergeSort(int R[],int low,int high);
void merge(int R[],int low,int mid, int high);
void outPutArr(int arr[],int n);

void main(){
	int arr[] = { 68,23,32,0,-33,23,41,999,-1,66 };
	int length = sizeof(arr) / sizeof(arr[0]);
	mergeSort(arr,0,length-1);
	outPutArr(arr,length);
}



/**
�鲢����
*/
void mergeSort(int R[], int low, int high){
	if(low < high){
		int mid = (low + high) / 2;
		mergeSort(R, low, mid);       //�鲢����ǰ���
		mergeSort(R, mid+1, high);    //�鲢�������
		merge(R, low, mid, high);    //��R������low~mid,mid~high�������й鲢Ϊһ������
	}
}



/**
���������й鲢Ϊһ����������
*/
void merge(int R[], int low, int mid, int high){
	int i, j, k;
	int n1 = mid - low + 1;
	int n2 = high - mid;
	int left[n1], right[n2];    //�˴���C++��C����б�����󣬽���취�ǽ������������߼��ṹ��Ϊһ�����Ա�
	for(i = 0; i < n1; i++){
		left[i] = R[low + i];
	}
	for(j = 0; j < n2; j++){
		right[j] = R[mid + 1 + j];
	}
	i = 0; j = 0; k = low;
	while(i < n1 && j < n2){
		if(left[i] <= right[j]){
			R[k] = left[i++];
		}else{
			R[k] = right[j++];
		}
		k++;
	}
	while(i<n1){
		R[k++] = left[i++];
	}
	while(j<n2){
		R[k++] = right[j++];
	}
}

/**
��������������
*/
void outPutArr(int arr[],int n){
	cout <<"<�鲢�����㷨>\r\n"<<endl;
	cout <<"���鳤�ȣ�"<<n<<"\r\n"<<endl;
	cout <<"�������У�{";
	for(int i=0;i<n;i++){
		if(i<n-1){
			cout << arr[i] << " , ";
		}else{
			cout << arr[i] <<"};\r\n"<<endl;
		}
	}
}