#include "shell.h"

/**
* checkbuiltinfnc - checks if the command is a builtin
* @arv: array of arguments
* Return: pointer to function that takes arv and returns void
*/
void(*checkbuiltinfnc(char **arv))(char **arv)
{
int i, j;
mybuild T[] = {
{"exit", exitshell},
{"env", print_env},
{"setenv", _setenv},
{"unsetenv", _unsetenv},
{NULL, NULL}
};

for (i = 0; T[i].name; i++)
{
j = 0;
if (T[i].name[j] == arv[0][j])
{
for (j = 0; arv[0][j]; j++)
{
if (T[i].name[j] != arv[0][j])
break;
}
if (!arv[0][j])
return (T[i].func);
}
}
return (0);
}
