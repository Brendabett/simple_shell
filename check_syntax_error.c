#include "main.h"

/**
 * char_repeated - counts the repetitions of a char
 *
 * @inp: inp string
 * @i: index
 * Return: repetitions
 */
int char_repeated(char *inp, int i)
{
if (*(inp - 1) == *inp)
return (char_repeated(inp - 1, i + 1));

return (i);
}

/**
 * err_sep - finds syntax errors
 *
 * @inp: inp string
 * @i: index
 * @last: last char read
 * Return: index of error. 0 when there are no
 * errors
 */
int err_sep(char *inp, int i, char last)
{
int count;

count = 0;
if (*inp == '\0')
return (0);

if (*inp == ' ' || *inp == '\t')
return (err_sep(inp + 1, i + 1, last));

if (*inp == ';')
if (last == '|' || last == '&' || last == ';')
return (i);

if (*inp == '|')
{
if (last == ';' || last == '&')
return (i);

if (last == '|')
{
count = char_repeated(inp, 0);
if (count == 0 || count > 1)
return (i);
}
}

if (*inp == '&')
{
if (last == ';' || last == '|')
return (i);

if (last == '&')
{
count = char_repeated(inp, 0);
if (count == 0 || count > 1)
return (i);
}
}

return (err_sep(inp + 1, i + 1, *inp));
}

/**
 * first_char - finds index of the first char
 *
 * @inp: inp string
 * @i: index
 * Return: 1 if there is an error. 0 in other case.
 */
int first_char(char *inp, int *i)
{

for (*i = 0; inp[*i]; *i += 1)
{
if (inp[*i] == ' ' || inp[*i] == '\t')
continue;

if (inp[*i] == ';' || inp[*i] == '|' || inp[*i] == '&')
return (-1);

break;
}

return (0);
}

