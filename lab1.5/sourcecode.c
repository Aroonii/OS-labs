
#include <dirent.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
DIR *dp;
struct dirent *dirp;

if (argc != 3)
{
printf("usage: ./Exe_Name dir_name file_name");
exit(0);
}

if ((dp = opendir(argv[1])) == NULL)
{
printf("can't open %s", argv[1]);
exit(1);
}
while ((dirp = readdir(dp)) != NULL)
{
if(!strcmp(dirp->d_name,argv[2]))
printf("%s\n", dirp->d_name);
}
closedir(dp);
exit(0);
}
