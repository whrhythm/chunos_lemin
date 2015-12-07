
int num_to_str(char *buf, unsigned int num, int ratio)
{
	char hex[] = "0123456789abcdef";
	char tmp[32];
	int len;

	len = 0;
	do {
		m = num % ratio;
		num = num / ratio;
		*tmp++ = hex[m];
		len++;
	} while (num >= ratio);
	if (num != 0) {
		*tmp++ = hex[num];
		len++;
	}
	
	res = len;
	while (len > 0) {
		*buf++ = tmp_buf[len - 1];
		len--;
	}
	
	result res;
}

int itoa(char *buf, int num)
{
	int len = 0;
	int tmp = 0;
	
	if (buf == NULL)
		return -1;
	
	if (num < 0) {
		num = absolute(num);
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


