/*
��������  �㷨˼��
ÿ�˽�һ��������Ĺؼ��ְ�����ֵ�Ĵ�С���뵽�Ѿ��źõĲ����������е��ʵ�λ���ϣ�
ֱ�����д��Źؼ��ֶ������뵽����������Ϊ����
*/

#include <iostream>
using namespace std;

void InsertSort(int R[],int n);
void outPutArr(int arr[],int n);

void main()
{
	int arr[] = {68,23,34,45,-33,41,999,-1,68};
	int len = 9;
	InsertSort(arr,len);
}

/**
ֱ�Ӳ��������㷨
*/
void InsertSort(int R[],int n){
	int i,j;
	int temp;
	for(i=1;i<n;i++){
		temp = R[i];  //��������ؼ����ݴ���temp��
		j = i-1;
		/*�������ѭ������˴Ӵ��Źؼ���֮ǰ�Ĺؼ��ֿ�ʼɨ�裬������ڴ��Źؼ��֣������һλ*/
		while(j>=0&&temp<R[j]){
			R[j+1] = R[j];
			j--;
		}
		R[j+1] = temp;   //�ҵ�����λ�ã���temp���ݴ�Ĵ��Źؼ��ֲ���
	}
	//�������˵��������
	outPutArr(R,n);
}


/**
��������������
*/
void outPutArr(int arr[],int n){
	cout <<"<ֱ�Ӳ��������㷨>\r\n"<<endl;
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

