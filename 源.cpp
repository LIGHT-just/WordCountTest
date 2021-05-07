#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int word_same(char* input);
int num_same(char* input);
int main(int argc, char* argv[])
{
	char a[100];

	/*fscanf(file, "%s", a);
	cout << a;*/


	if (strcmp(argv[1], "-c") == 0)
	{
		cout << "字符的个数是：" << word_same(argv[2]);
	}
	else
	{
		cout << "单词的个数是：" << num_same(argv[2]);
	}
}
int word_same(char* input)
{
	int nums = 0;
	char word[100];
	int words[100] = { 0 };
	int rec = 0;
	int i = 0;
	char get = 255;
	FILE* file = NULL;
	file = fopen(input, "r");
	while (1)
	{
		get = fgetc(file);
		if (get == EOF)
			break;
		for (i = 0; i <= rec; i++)
		{
			if (word[i] == get)
			{
				words[i]++;
				break;
			}
		}
		if (i == rec + 1)
		{
			rec++;
			words[i]++;
			word[i] = get;
		}
	}
	nums = rec;
	fclose(file);
	return nums;
}
int num_same(char* input)
{
	char* word;
	char temp[100];
	char words[100][30];
	int nums[100] = { 0 };
	char* p1;
	char* p2;
	int length;
	int rec = 0;
	int f = 0;
	int i = 0;
	int j = 0;
	FILE* fp = NULL;
	fp = fopen(input, "r");
	fseek(fp, 0, SEEK_END);
	length = ftell(fp);
	word = (char*)malloc((length + 1) * sizeof(char));
	rewind(fp);
	length = fread(word, 1, length, fp);
	word[length] = '\0';
	p1 = word;
	while (1)
	{

		if (*(p1) != ' ' && *(p1) != ',' && *(p1) != '\0')
		{
			p2 = p1;
			for (int m = 1;; m++)
			{
				if (*(p2 + m) == ',' || *(p2 + m) == ' ' || *(p2 + m) == '\0')
				{
					strncpy(temp, p1, m);
					*(temp + m) = '\0';
					p2 = p2 + m;
					for (j = 0; j <= rec; j++)
					{
						if (strcmp(words[j], temp) == 0)
						{
							nums[j]++;
							break;
						}
					}
					if (j == rec + 1)
					{
						strcpy(words[rec], temp);
						rec++;
					}
					p1 = p2;
					break;
				}
			}
		}
		if (*p1 == '\0')
			break;
		else
			p1++;
	}
	return rec;
	fclose(fp);
}