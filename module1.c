#include <stddef.h>
#include <stdio.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

int name_check(char *string);

void register_normalize(char *string);

int main(int argc, char *argv[])
{
	DIR *d;
	struct dirent *dir;
	d = opendir(argv[1]);

	while((dir = readdir(d)) != NULL)
	{
		if(name_check(dir->d_name))
			printf("%s\n", dir->d_name);
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
