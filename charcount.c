#include<stdio.h>
int * ncharnline(FILE *);
int main(){
	FILE * f;
	f = fopen("in.txt", "r");
	printf("Characters : %d or %d\n", nchar(f), *ncharnline(f));
	printf("Lines : %d or %d\n", nline(f), *(ncharnline(f)+1));
	return 0;
}

int * ncharnline(FILE * f){
	rewind(f);
	char c;
	int count = 0, l = 0, a[2];
	while((c=getc(f))!=EOF){
		//for comment removing
		if(c=='/')
			if(getc(f)=='/'){
				while((c=getc(f)) != '\n') continue;
				l-=2;
			}else fseek(f, -1, SEEK_CUR);
		//for space removing
		if(c==' ') continue;
		//for line count
		if(c=='\n'){
			l++;
			continue;	
		}
		count++;
	}
	a[0] = count; a[1] = l;
	return a;	
}

int nchar(FILE * f){
	rewind(f);
	char c;
	int count = 0;
	while((c=getc(f))!=EOF){
		//for comment removing
		if(c=='/')
			if(getc(f)=='/')
				while((c=getc(f)) != '\n') continue;
			else fseek(f, -1, SEEK_CUR);
		//for space and line removing
		if(c==' ' || c=='\n') continue;
		count++;
	}
	return count;	
}

int nline(FILE * f){
	rewind(f);
	char c;
	int l = 0;
	while((c=getc(f))!=EOF){
		//for comment removing
		if(c=='/')
			if(getc(f)=='/'){
				while((c=getc(f)) != '\n') continue;
				l-=2;
			}else fseek(f, -1, SEEK_CUR);
		//for space removing
		if(c==' ') continue;
		//for line count and removing
		if(c=='\n'){
			l++;
			continue;	
		}
	}
	return l;	
}





