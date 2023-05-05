#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char* argv[])//argc表示命令行参数的数量，包括程序名本身和参数，argv是一个字符串数组，用于存储命令行参数的具体内容。
{
	int count = 0;
	FILE* file;//通过fopen()函数打开文件并返回文件指针 
	file = fopen(argv[2],"r");
	if(file == NULL){
		printf("file ERROR!!!");
		return 0;
	} 
	if(argv[1][1] == 'w'){
		char str[1024];//要求一个字符串最多1024 
		while(fscanf(file,"%s",str) != EOF){
			//适用于读取以空格或换行符分隔的单词或行
			count ++;
			for(int i = 0; i < strlen(str) - 1 ;i++){
				if(str[i] == ',' && str[i-1] != ',' && str[i+1] != ','){//如果有 ， 号  则分割  字符串 
					count ++;
				}
			}
		}
		printf("单词数：%d",count);
	}else if(argv[1][1] == 'c'){
		char c;
		while((c = fgetc(file)) != EOF){//fgetc()函数的参数是文件指针，返回值是下一个字符的ASCII码值 
			count ++;
		}
		printf("字符数：%d",count);
	}else{
		printf("input Error!!");
	}
	fclose(file);
	return 0;
}

