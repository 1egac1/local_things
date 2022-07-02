#include <stddef.h>
#include <stdio.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

int name_check(char*);

void register_normalize(char*);

void renamer_func(char*, char*);

int main(int argc, char *argv[])
{
	DIR *d;
	struct dirent *dir;
	d = opendir(argv[1]);

	while((dir = readdir(d)) != NULL)
	{
		if(name_check(dir->d_name))
			renamer_func(dir->d_name, argv[1]);
	}
	closedir(d);

	return 0;
}

int name_check(char *string)
{
	size_t str_len = strlen(string);
	char *string_end = string - 1 + str_len;

	while (*string_end != '.' && string_end != string)
	{
		if(isupper(*string_end))
			return 1;
		--string_end;
	}
	return 0;
}

void register_normalize(char *string)
{
	size_t str_len = strlen(string);
	char *string_end = string - 1 + str_len;

	while (*string_end != '.' && string_end > string)
	{
		*string_end = tolower(*string_end);
		--string_end;
	}

	printf("%s\n", string);

	return;
}

void renamer_func(char *string, char *path){
	size_t new_name_len = strlen(string) + strlen(path);
	char new_name[new_name_len];
	char old_name[new_name_len];

	strcpy(old_name, path);
	strcpy(new_name, path);
	strcat(old_name, "/");
	strcat(new_name, "/");
	

	strcat(old_name, string);

	register_normalize(string);

	strcat(new_name, string);
	printf("OLD PATH:\t%s\n"
			"NEW PATH:\t%s\n",
			old_name, new_name);

	rename(old_name, new_name);
}
