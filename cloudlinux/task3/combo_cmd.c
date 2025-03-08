#include "combo_cmd.h"

int run_first_command(char **cmd, const char **envp)
{
    int pid, status;
    pid = fork();
    if (pid < 0)
        return 1;
    else if (pid == 0)
    {
        if (execve(cmd[0], (void *)cmd, (void *)envp))
			perror("Execution error!\n");
        exit(1);
    }
    waitpid(0, &status, 0);
    if (WIFEXITED(status) == 0)
        return 1;
    return WEXITSTATUS(status);
}

int run_second_third_commands(char ***cmds, const char **envp)
{
    int pid, file_fd, status;
    int in_out[2];

    if (pipe(&in_out[0]))
        return 1;
    pid = fork();
    if (pid < 0)
    {
        close(in_out[0]);
        close(in_out[1]);
        return 1;
    }
    else if (pid == 0)
    {
        close(in_out[0]);
        dup2(in_out[1], STDOUT_FILENO);
        if (execve(cmds[1][0], (void *)cmds[1], (void *)envp))
			perror("Execution error!\n");
        close(in_out[1]);
        exit(1);
    }

    pid = fork();
    if (pid < 0)
    {
        close(in_out[0]);
        close(in_out[1]);
        return 1;
    }
    else if (pid == 0)
    {
        close(in_out[1]);

        file_fd = open(cmds[3][0], O_WRONLY | O_CREAT | O_TRUNC, 0644);

        if (file_fd != -1)
            dup2(file_fd, STDOUT_FILENO);
        dup2(in_out[0], STDIN_FILENO);

        if (execve(cmds[2][0], (void *)cmds[2], (void *)envp))
            perror("Execution error!\n");

        if (file_fd != -1)
            close(file_fd);
        close(in_out[0]);
        exit(1);
    }
    close(in_out[0]);
    close(in_out[1]);
    waitpid(-1, 0, 0);
    waitpid(-1, &status, 0);
    if (WIFEXITED(status) == 0)
        return 1;
    return WEXITSTATUS(status);    
}

int run_cmds(char ***cmds, const char **envp)
{
    int status;
    
    status = run_first_command(cmds[0], envp);
    if (status != 0)
        return status;

    status = run_second_third_commands(cmds, envp);
    return status;
}

int main(int argc, char const *argv[], char const *envp[])
{
    int     status;
    char    **cmds[4];

    if (argc != 5)
        return 1;

    cmds[0] = split_str(argv[1], " ");
    cmds[1] = split_str(argv[2], " ");
    cmds[2] = split_str(argv[3], " ");
    cmds[3] = split_str(argv[4], " ");

    if (cmds[0] == NULL || cmds[1] == NULL || cmds[2] == NULL || cmds[3] == NULL)
    {
        all_free(cmds, 4);
        return 1;
    }

    status = run_cmds(cmds, envp);

    all_free(cmds, 4);

    return status;
}
