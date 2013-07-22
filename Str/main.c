/*************************************************************************
	> File Name: main.cpp
# Author: rsq
# mail: rsqmail@163.com
	> Created Time: 2013年07月20日 星期六 10时34分45秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#include <algo.h>
#define MAX_TEXT_LENGTH 10240
#define MAX_PATTERN_LENGTH 1024

int main()
{
	char text[MAX_TEXT_LENGTH], pattern[MAX_PATTERN_LENGTH];

	printf("input the text:\n");
	scanf("%s", text);
	printf("input the pattern:\n");
	scanf("%s", pattern);

	NaiveStringMatcher(text, pattern, strlen(text), strlen(pattern));
	//RobinKarpMatcher(text, pattern, strlen(text), strlen(pattern), 10, 13);
	KMPMatcher(text, pattern, strlen(text), strlen(pattern));
}
