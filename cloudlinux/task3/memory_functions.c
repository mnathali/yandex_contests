#include "combo_cmd.h"

int multi_free(char **set_of_strings)
{
    int i = 0;

    while (set_of_strings[i] != NULL)
    {
        free(set_of_strings[i]);
        ++i;
    }
    return 0;
}

int all_free(char ***cmds, int size)
{
    for (int i = 0; i < size; ++i)
        if (cmds[i] != NULL)
        {
            multi_free(cmds[i]);
            free(cmds[i]);
        }
    return 0;
}