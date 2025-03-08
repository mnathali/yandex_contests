#include "combo_cmd.h"

int char_count(const char *str, char* sub_str)
{
    int n = 0, i = 0, j;
    if (str == NULL || sub_str == NULL)
        return 0;
    while (str[i] != '\0')
    {
        j = 0;
        if (str[i] == sub_str[j])
        {
            while (sub_str[j] == str[i+j] && sub_str[j] != '\0')
                ++j;
            if (sub_str[j] == '\0')
                ++n;
        }
        ++i;
    }
    return n;
}

char **split_str(const char *str, char *delim)
{
    int i = 0;
    char *sub_str;
    char *copy_str;
    char **set_of_strings;
    int n = char_count(str, delim);

    set_of_strings = (char **)calloc(1, (n + 2) * sizeof(char *));
    if (set_of_strings == NULL)
        return NULL;

    copy_str = strdup(str);
    if (copy_str == NULL)
    {
        free(set_of_strings);
        return NULL;
    }

    sub_str = strtok(copy_str, delim);
    while (sub_str != NULL) {
        sub_str = strdup(sub_str);
        if (sub_str == NULL)
        {
            multi_free(set_of_strings);
            free(set_of_strings);
            break;
        }
        set_of_strings[i] = sub_str;
        sub_str = strtok(NULL, delim);
        ++i;
    }

    free(copy_str);
    return set_of_strings;
}

