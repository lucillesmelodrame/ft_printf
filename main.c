#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "ft_printf.h"

int	main(void)
{
	char *nullstr = NULL;
	// 1. INT_MIN — the classic negation trap
	ft_printf("[%d]\n", INT_MIN);
	printf("[%d]\n", INT_MIN);

	// 2. Zero, for every numeric conversion
	ft_printf("[%d][%u][%x][%X]\n", 0, 0, 0, 0);
	printf("[%d][%u][%x][%X]\n", 0, 0, 0, 0);

	// 3. NULL string — the one we flagged earlier
	ft_printf("[%s]\n", (char *)NULL);
	printf("[%s]\n", nullstr);

	// 4. Empty string (different from NULL!)
	ft_printf("[%s]\n", "");
	printf("[%s]\n", "");

	// 5. %u with a value too big for a signed int
	ft_printf("[%u]\n", 4000000000u);
	printf("[%u]\n", 4000000000u);

	// 6. Multiple conversions packed together, no separators
	ft_printf("%d%s%c%d\n", 5, "abc", '!', -5);
	printf("%d%s%c%d\n", 5, "abc", '!', -5);

	// 7. Return value itself
	int a = ft_printf("[%s]\n", (char *)NULL);
	int b = printf("[%s]\n", nullstr);
	printf("ft_printf returned %d, printf returned %d\n", a, b);

	int x = 5;
	ft_printf("%p\n", &x);
	printf("%p\n", &x);

	ft_printf("[%c]\n", '\0');
	printf("[%c]\n", '\0');

	ft_printf("[%d][%d][%i][%i]\n", -1, -100, -1, -100);
	printf("[%d][%d][%i][%i]\n", -1, -100, -1, -100);

	char	long_str[301];
	memset(long_str, 'a', 300);
	long_str[300] = '\0';
	int	y = ft_printf("[%s]\n", long_str);
	int z = printf("[%s]\n", long_str);
	printf("ft_printf returned %d, printf returned %d\n", y, z);

	return (0);
}
