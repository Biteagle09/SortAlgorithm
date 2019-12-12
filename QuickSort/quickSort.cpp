#include<iostream>
using namespace std;

void outPutArr(int arr[],int n);
void quickSort(int R[] ,int low,int high);

void main(){
	int arr[] = {68,23,34,45,-33,41,999,-1,68};
	int length = 9;
	quickSort(arr,0,length-1);
	outPutArr(arr,length);
}



void quickSort(int R[] ,int low,int high){
	int temp;
	int i = low, j = high;
	if(low<high){
		temp = R[low];
		while(i<j){   //��������С��temp�ķ�����ߣ�����temp�ķ����ұ�
			while(j>i && R[j]>=temp){   //��������ɨ�裬�ҵ�һ��С��temp�Ĺؼ���
				j--;
			}
			if(i<j){
				R[i] = R[j];         //����temp���
				i++;                 //����һλ
			}
			while(i<j && R[i]<temp){    //��������ɨ�裬�ҵ�һ������temp�Ĺؼ���
				i++;
			}
			if(i<j){
				R[j] = R[i];        //����temp�ұ�
				j--;                //����һλ
			}
		}
		R[i] = temp;                //��temp��������λ��
		quickSort(R,low,i-1);       //�ݹ�Ķ�temp��ߵĹؼ�������
		quickSort(R,i+1,high);      //�ݹ�Ķ�temp�ұߵĹؼ�������
	}
}



/**
��������������
*/
void outPutArr(int arr[],int n){
	cout <<"<���������㷨>\r\n"<<endl;
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