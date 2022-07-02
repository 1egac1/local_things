#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <time.h>

#define DIR_PATH "/home/q/Downloads"
#define MODULE_PATH "/home/q/educ/cxx/local_things/model.out"

void check_date(struct stat *date, time_t *l_chs);

int main ()
{
	struct stat dates;
	time_t last_changes;
	time(&last_changes);

	while(true)
	{
		if (stat(DIR_PATH, &dates) == 0) 
		{
			check_date(&dates, &last_changes);
			sleep(10);
		}
		else
		{
			printf("Incorrect direcory path \"%s\"", DIR_PATH);
		}

		return 0;
	}
}

void check_date(struct stat *date, time_t *l_chs)
{
	if (date->st_ctime > *l_chs)
	{
		*l_chs = date->st_ctime;
		int pid_status;
		pid_t pid = fork();
		if(!pid)
			execl(MODULE_PATH, MODULE_PATH, DIR_PATH, NULL);
		else
			waitpid(pid, &pid_status, 0);
	}
	else
	{
		return;
	}
}
