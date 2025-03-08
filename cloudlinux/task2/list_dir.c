#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/resource.h>

int ls_directory(const char *dir, int dir_name_len, int ident, int depth)
{
    DIR *directory = opendir(dir);
    if (directory == NULL)
        return 1;
    struct dirent *dir_entity = readdir(directory);

    while (dir_entity)
    {
        if (dir_entity->d_name[0] != '.')
        {
            printf("%*s%s", ident + 5, "", dir_entity->d_name);
            if (dir_entity->d_type == DT_DIR)
            {
                printf("/\n");
                int len_inner_dir_name = dir_name_len + strlen(dir_entity->d_name) + 1;
                char *inner_dir = (char *)calloc(1, (len_inner_dir_name + 1) * sizeof(char));
                if (inner_dir != NULL)
                {
                    strcat(inner_dir, dir);
                    strcat(inner_dir, "/");
                    strcat(inner_dir, dir_entity->d_name);
                    if ((ident + 5) / 5 < depth)
                        ls_directory(inner_dir, len_inner_dir_name, ident + 5, depth);
                    free(inner_dir);
                }
            }
            else
                printf("\n");
        }
        dir_entity = readdir(directory);
    }
    closedir(directory);
    return 0;
}

int main(int argc, char const *argv[])
{
    if (argc < 2)
        return 1;

    struct rlimit limit;
    if (getrlimit(RLIMIT_STACK, &limit))
        return 1;
    int depth = limit.rlim_cur / 160;
    printf("%s/\n", argv[1]);
    ls_directory(argv[1], strlen(argv[1]), 0, depth);
    return 0;
}
