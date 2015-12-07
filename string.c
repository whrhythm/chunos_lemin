
int num_to_str(char *buf, unsigned int num, int ratio)
{
	char hex[] = "0123456789abcdef";
	char tmp[32];

	do {
		m = num % ratio;
		num = num / ratio;
		*tmp++ = hex[m];
	} while (num >= ratio);
	if (num != 0)
		*tmp++ = hex[num];
	
	res = len	
	
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
