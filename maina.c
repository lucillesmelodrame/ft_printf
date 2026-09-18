#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*s;
	int		result;
	char	*ptr;
	int		expected;

	s = NULL;
	result = ft_printf("hello world\n");
	printf("len: %d\n", result);
	result = ft_printf("%s\n", s);
	printf("len: %d\n", result);
	result = ft_printf("%d\n", 2147483647);
	printf("len: %d\n", result);
	result = ft_printf("%d\n", -2147483648);
	printf("len: %d\n", result);
	result = ft_printf("%x\n", 42);
	printf("len: %d\n", result);
	result = ft_printf("%c\n", 'a');
	printf("len: %d\n", result);
	result = ft_printf("%i\n", 42);
	printf("len: %d\n", result);
	result = ft_printf("%u\n", 2147483649);
	printf("len: %d\n", result);
	result = ft_printf("%X\n", 42);
	printf("len: %d\n", result);

	printf("============%%p test============\n");
	ptr = "aiueo";
	printf("result: \n");
	result = ft_printf("%p\n", ptr);
	printf("len: %d\n", result);

	printf("expected: \n");
	expected = printf("%p\n", ptr);
	printf("len: %d\n", expected);
	printf("============%% test============\n");
	// edge case
	result = ft_printf("%");
	printf("\n");
	printf("len: %d\n", result);

	// printf("%");
	// same do segv
	// printf(0);
	// ft_printf(0);
	//
	// error case
	result = ft_printf("%%");
	printf("\n");
	expected = printf("%%");
	printf("\n");
	printf("result: %d, expected: %d\n", result, expected);
	return (0);
}
