#include<iostream>
using namespace std;

void outPutArr(int arr[],int n);
void sift(int R[] ,int low,int high);
void heapSort(int R[], int n);

void main(){
	int arr[] = { 68,23,32,0,-33,23,41,999,-1,66 };
	int length = sizeof(arr) / sizeof(arr[0]);
	heapSort(arr,length);
}


/**
�������㷨������
*/
void heapSort(int R[], int n){
	int i;
	int temp;
	for(i = n/2 - 1; i >= 0; i--){      //������ʼ��
		sift(R, i, n-1);
	}
	for(i = n-1; i > 0; i--){        //����n-1��ѭ������ɶ�����
		temp = R[0];             //һ��3�任�����ڵ�Ĺؼ��֣������������λ��
		R[0] = R[i];
		R[i] = temp;
		sift(R, 0, i-1);           //�ڼ�����һ���ؼ��ֵ����������е���
	}
	outPutArr(R, n);
}



/**
�ѵľֲ���������
*/
void sift(int R[] ,int low, int high){      //�ؼ����趨�±��0��ʼ
	int i = low,j = 2*i + 1;                 //R[j]��R[i]�����ӽڵ�
	int temp = R[i];
	while(j <= high){
		if(j < high && R[j] < R[j+1]){         //���Һ��ӽϴ���jָ���Һ���
			j++;                           //j��Ϊ2*i+2
		}
		if(temp < R[j]){
			R[i] = R[j];                  //��R[j]������˫�׽ڵ��λ��
			i = j;                        //�޸�i��j��ֵ���������µ���
			j = 2*i + 1;
		}else{
			break;                       //��������
		}
	}
	R[i] = temp;                         //�������ڵ��������λ��
}




/**
��������������
*/
void outPutArr(int arr[],int n){
	cout <<"<�������㷨>\r\n"<<endl;
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