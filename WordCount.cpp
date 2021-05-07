#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void CharCount(char path[]);  //字符统计函数
void WordCount(char path[]);  //单词统计函数

int main(int argc, char* argv[])
{
    if(strcmp(argv[1],"-c")==0){		
    	CharCount(argv[2]);
	}
	else if(strcmp(argv[1],"-w")==0){
		WordCount(argv[2]);
	}
//    system("pause");
    return 0;
}

void CharCount(char path[]) //字符统计函数
{
    FILE *fp=NULL;
    int c = 0;
    char ch;
    char *path3 = path;
    int k = strlen(path);
    *(path3 + k) = '\0';
    if ((fp = fopen(path3 , "r")) == NULL)
    {
        printf("文件读取失败\n\n");
        exit(0);
    }
    ch = fgetc(fp);
    while (ch != EOF)
    {
        c++;
        ch = fgetc(fp);
    }
    printf("字符数为（含标点与空格）：%d.\n\n", c);
    fclose(fp);
}

void WordCount(char path[]) //单词统计函数
{
    FILE *fp;
    int w = 0;
    char ch;
    char *path3 = path;
    int k = strlen(path);
    *(path3 + k ) = '\0';
    if ((fp = fopen(path3, "r")) == NULL)
    {
        printf("文件读取失败\n\n");
        exit(0);
    }
    ch = fgetc(fp);
    while (ch != EOF)
    {
        if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || (ch >= '0'&&ch <= '9'))
        {
            while ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || (ch >= '0'&&ch <= '9') || ch == '_')
            {
                ch = fgetc(fp);
            }
            w++;
            ch = fgetc(fp);
        }
        else
        {
            ch = fgetc(fp);
        }
    }
    printf("单词数为：%d.\n\n", w);
    fclose(fp);
}


