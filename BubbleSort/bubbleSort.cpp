#include <iostream>
using namespace std;
void bubbleSort(int R[],int n);
void outPutArr(int arr[],int n);


void main(){
	int arr[] = { 68,23,32,0,-33,23,41,999,-1,66 };
	int len = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr,len);
}


/**
ð�������㷨
*/
void bubbleSort(int R[], int n){
	int i,j;
	bool flag;
	int temp;
	for(i = n-1; i > 0; i--){
		flag = false;        //flag������Ǵ��������Ƿ����˽���
		for(j = 1; j <= i; j++){
			if(R[j-1] > R[j]){
				temp = R[j];
				R[j] = R[j-1];
				R[j-1] = temp;
				flag = true;  //���û������������flagΪ0
			}
		}
		if(!flag){      //һ�����������û�з���������֤��ʣ���������򣬲���ð��
			outPutArr(R,n);
			return;
		}
	}
}


/**
��������������
*/
void outPutArr(int arr[],int n){
	cout <<"<���������㷨>\r\n"<<endl;
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
