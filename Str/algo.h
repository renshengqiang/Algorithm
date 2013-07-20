/*************************************************************************
	> File Name: algo.h
# Author: rsq
# mail: rsqmail@163.com
	> Created Time: 2013年07月20日 星期六 10时27分34秒
 ************************************************************************/
#define TRUE 1
#define FALSE 0


void NaiveStringMatcher(const char *text, const char *pattern, int textLength, int patternLength);
void RobinKarpMatcher(const char *text, const char *pattern, int textLength, int patternLength, int d, int q);
void KMPMatcher(const char *text, const char *pattern, int textLength, int patternLength);
