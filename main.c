#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdbool.h>

#define DIR_PATH "/home/q/Downloads"

bool check_date(struct stat *date);

int main (){
	struct stat dates;

	if (stat(DIR_PATH, &dates) == 0) 
	{
		check_date(&dates);
	}
	else
	{
		printf("Incorrect direcory path \"%s\"", DIR_PATH);
	}

	return 0;
}
