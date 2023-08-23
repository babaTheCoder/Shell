#include "shell.h"

/**
* custom_atoi - Custom implementation of the atoi function
* @str: The string to convert to an integer
*
* Return: The converted integer value
*/
int custom_atoi(const char *str)
{
int result = 0;
int sign = 1;
int i = 0;

/* Check for a sign (+/-) */
if (str[0] == '-')
{
sign = -1;
i++;
}
else if (str[0] == '+')
{
i++;
}

/* Process digits */
while (str[i] != '\0')
{
/* Check if the character is a digit */
if (str[i] >= '0' && str[i] <= '9')
{
/* Convert the digit to an integer and update the result */
result = result * 10 + (str[i] - '0');
i++;
}
else
{
/* Invalid character found, break out of the loop */
break;
}
}

return (result *sign);
}
