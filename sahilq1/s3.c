//s3 q1
#include <stdio.h>
#include <stdlib.h>
int findLRUPageIndex(int *counter, int n) {
int minIndex = 0;
for (int i = 1; i < n; i++) {
if (counter[i] < counter[minIndex]) {
minIndex = i;
}
}
return minIndex;
}
void simulateDemandPagingLRU(int *referenceString, int referenceStringLength, int n) {
int frames[n];
int counter[n]; 
int pageFaults = 0;
for (int i = 0; i < n; i++) {
frames[i] = -1; 
counter[i] = 0;
}
for (int i = 0; i < referenceStringLength; i++) {
int page = referenceString[i];
int pagePresent = 0;
for (int j = 0; j < n; j++) {
if (frames[j] == page) {
pagePresent = 1;
counter[j]++;
} else {
counter[j] >>= 1; 
}
}
if (!pagePresent) {
int lruIndex = findLRUPageIndex(counter, n);
frames[lruIndex] = page;
counter[lruIndex] = 1; 
pageFaults++;
}
printf("%d ", page);
}
printf("\nTotal Page Faults: %d\n", pageFaults);
}
int main() {
int referenceString[] = {3, 5, 7, 2, 5, 1, 2, 3, 1, 3, 5, 3, 1, 6, 2};
int referenceStringLength = sizeof(referenceString) / sizeof(referenceString[0]);
int n = 3;
simulateDemandPagingLRU(referenceString, referenceStringLength, n);
return 0;
}






//q2

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>
void count(char *cm,char *file){
char cd;
int fn =open(file,O_RDONLY);
int lineCount=0,wordCount=0,charCount=0;
while(read(fn,&cd,1)>0){
if(cd=='\n')
lineCount++;
else if(cd==' ')
wordCount++;
else
charCount++;
File: /home/hpubuntu/Desktop
}
if(strcmp(cm,"c")==0){
printf("The number of characters in the file are %d\n",charCount);
}
if(strcmp(cm,"w")==0){
printf("The number of words in the file are %d\t",wordCount);
}
if(strcmp(cm,"l")==0){
printf("The number of lines in the file are %d\n",lineCount);
}
}
int main(void)
{
char cmd[80],op1[20],op2[20],op3[30];
while(1){
printf("\n MyShell $ ");
scanf("%c",cmd);
int pid=fork();
if(pid==-1){
printf("Error\n");
}
else if(pid > 1){
wait(NULL);
}
else{
int n=sscanf(cmd,"%s %s %s",op1,op2,op3);
if(strcmp(op1,"count")==0){
count(op2,op3);
exit(0);
}
}
}
}
