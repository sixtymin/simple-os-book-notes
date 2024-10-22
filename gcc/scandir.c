
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

void printfdir(char *dir, int depth){
	
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;

	if((dp = opendir(dir)) == NULL){
		fprintf(stderr, "can't open directory: %s\n", dir);
		return ;
	}

	chdir(dir);
	while((entry = readdir(dp)) != NULL){
		lstat(entry->d_name, &statbuf);
		if(S_ISDIR(statbuf.st_mode)) {
			/*Found  a directory, but ignore . and .. */
			if(strcmp(".", entry->d_name) == 0 ||
				strcmp("..", entry->d_name) == 0) {
				continue;
			}

			printf("%*s%s/\n", depth, " ", entry->d_name);
			printfdir(entry->d_name, depth + 4);
		}
		else
			printf("%*s%s\n", depth, " ", entry->d_name);
	}

	chdir("..");
	closedir(dp);
}

int main() {
	printf("Directroy scan of /home:\n");
	printfdir("/home", 0);
	printf("done.\n");
	return 0;
}
