int	ft_atoi(const char *nptr)
{
	int		sign;
	long	result;

	sign = 1;
	while (*nptr && ((*nptr >= 9 && *nptr <= 13) || *nptr == 32))
		nptr++;
	if (*nptr && (*nptr == 45 || *nptr == 43))
	{
		if (*nptr == 45)
		{
			sign *= -1;
		}
		nptr++;
	}
	result = 0;
	while (*nptr >= 48 && *nptr <= 57)
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}
