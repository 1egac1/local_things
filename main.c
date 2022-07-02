#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

#define DIR_PATH "/home/q/Downloads"
#define MODULE_PATH "/home/q/educ/cxx/local_things/modele.out"

#define SIZE_OF_PATH_TO_EXE 200

void check_date(struct stat *date, time_t *l_chs);

int main (){
	struct stat dates;
	time_t last_changes;
	time(&last_changes);

	if (stat(DIR_PATH, &dates) == 0) 
	{
		check_date(&dates, &last_changes);
	}
	else
	{
		printf("Incorrect direcory path \"%s\"", DIR_PATH);
	}

	return 0;
}

void check_date(struct stat *date, time_t *l_chs)
{
	if (date->st_ctime > *l_chs)
	{
		*l_chs = date->st_ctime;
		char cdir[SIZE_OF_PATH_TO_EXE];
		getcwd(cdir, SIZE_OF_PATH_TO_EXE);
		execl(MODULE_PATH, MODULE_PATH, DIR_PATH, NULL);
	}
	else
	{
		return;
	}
}
