

#define MAX_NUM_STRLEN 32

int abs(int num)
{
	if (num > 0)
		return num;
	return (~num) + 1;
}

char *inverse(char *str, int len)
{
	char ch;
	int i;

	if (NULL == str)
		return NULL;
	len = len / 2;
	for (i = 0; i < len +1; ++i)
	{
		ch = *str;
		*str = *(str + len - 1 - i);
		*(str + len -1 - i) = ch;
	
	}	
	
}

char *num_to_str(unsigned int num, int model)
{
	char hex[] = "0123456789abcdef";
	char *buf, *tmp;
	
	int remain;
	int integer;
	int i;

	buf = malloc(MAX_NUM_STRLEN);
	tmp = buf;
	if (NULL == buf) {
		return ENMEM;
	}
	do {
		remain = num % model;
		*buf++ = hex[remain];
		integer = num / model;
	} while (integer > 0);
	
	return inverse(tmp, i);
}

int itoa(char *buf, int num)
{
	int len = 0;
	int tmp = 0;
	
	if (NULL == buf)
		return -1;
	
	if (num < 0) {
		num = abs(num);
		*buf++ = '-';
		tmp = 1;
	}
	len = num_to_str(buf, num, 10);

	return (len + tmp);
}

int inline uitoa(char *buf, unsigned int num)
{
	return num_to_str(buf, num, 10);
}

int inline hextoa(char *buf, unsigned int num)
{
	return num_to_str(buf, num, 16);
}

int inline octtoa(char *buf, unsigned int num)
{
	return num_to_str(buf, num, 8);
}

int inline bintoa(char *buf, unsigned int num)
{
	return num_to_str(buf, num, 2);
}

int strlen(char *buf)
{
	int len = 0;
	
	if (buf == NULL)
		return NULL;
	
	while (*buf++) {
		len++;
	}

	return len;
}

char *strcpy(char *des, char *src)
{
	char *tmp = des;
	
	if (des == NULL || src == NULL)
		return NULL;
	
	while ((*des++ = *src++) != '\0');
	return tmp;
}

char *strchr(char *src, char ch)
{
	for(; *src != (char)ch; ++src)
		if (*src == '\0')
			return NULL;

	return (char *)src;
}


