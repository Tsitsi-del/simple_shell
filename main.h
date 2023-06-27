#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdbool.h>

#define BUF 1024

int my_strlen(const char *str);
char *my_strdup(const char *str);
char *my_strcat(char *dest, const char *src);
char *my_strcpy(char *dest, const char *src);
int my_strcmp(const char *str_1, const char *str_2, size_t n);
int my_cmp_Str(const char *str_1, const char *str_2);
char *my_strchr(const char *s, int c);

void cmd_not_found(const char *cmd);

char *_strtok(char *str, const char *delim);

extern char **environ;

void display_env(void);
char **token(char *cmd, const char *delim);
int execmd(char **av);
char *rdcmd();
void *my_realloc(void *ptr, size_t o_size, size_t nw_size);
char *increase_buf(char *buf, size_t len);
char **tokenize(char *cmd, const char *delim);
size_t num_tokens(char *cmd, const char *delim);
char *my_getenv(const char *env_name);
size_t num_tokens(char *cmd, const char  *delim);
char *crt_path(char *dir, char *cmd);
char *get_path(char *cmd);

#endif
