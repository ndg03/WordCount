#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char* argv[])//argc��ʾ�����в�������������������������Ͳ�����argv��һ���ַ������飬���ڴ洢�����в����ľ������ݡ�
{
	int count = 0;
	FILE* file;//ͨ��fopen()�������ļ��������ļ�ָ�� 
	file = fopen(argv[2],"r");
	if(file == NULL){
		printf("file ERROR!!!");
		return 0;
	} 
	if(argv[1][1] == 'w'){
		char str[1024];//Ҫ��һ���ַ������1024 
		while(fscanf(file,"%s",str) != EOF){
			//�����ڶ�ȡ�Կո���з��ָ��ĵ��ʻ���
			count ++;
			for(int i = 0; i < strlen(str) - 1 ;i++){
				if(str[i] == ',' && str[i-1] != ',' && str[i+1] != ','){//����� �� ��  ��ָ�  �ַ��� 
					count ++;
				}
			}
		}
		printf("��������%d",count);
	}else if(argv[1][1] == 'c'){
		char c;
		while((c = fgetc(file)) != EOF){//fgetc()�����Ĳ������ļ�ָ�룬����ֵ����һ���ַ���ASCII��ֵ 
			count ++;
		}
		printf("�ַ�����%d",count);
	}else{
		printf("input Error!!");
	}
	fclose(file);
	return 0;
}

