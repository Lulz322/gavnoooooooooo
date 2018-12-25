//
// Created by bender on 12/20/18.
//

#include "../includes/ft_printf.h"

void print_string(va_list argptr) {
	char str[g_cvars.prec + g_cvars.width + 1];
	char *str_s;
	char *tmp;
	int i;

	i = 0;
	tmp = va_arg(argptr, char *);
	if (tmp == NULL)
		str_s = "(null)";
	else {
		str_s = ft_strdup(tmp);
		str_s[ft_strlen(tmp)] = '\0';
	}
	if (g_cvars.prec) {
		if (g_cvars.prec > ft_strlen(str_s))
			str_s = prec_helper(str, str_s);
		else {
			str_s[g_cvars.prec] = '\0';
		}
	}
	if (g_cvars.width)
		str_s = width_helper(str_s, 1);
	print_number_h(str_s);
	if (g_cvars.flag[3] != '-')
		ft_putstr(str_s);
	if (g_cvars.width && g_cvars.prec)
		free(str_s);
	clean();
}

void print_char(va_list argptr) {
	char str[g_cvars.prec + g_cvars.width + 1];
	char *str_s;
	unsigned int sign;

	str_s = (char *)malloc(sizeof(char) * 2);
	str_s[0] = (unsigned int)va_arg(argptr, unsigned int);
	str_s[1] = '\0';
	if (str_s[0] == '\0') {
		if (g_cvars.width)
			ft_putchar(' ');
		symbols--;
		str_s = "^@";
	}
	if (g_cvars.prec)
		str_s = prec_helper(str, str_s);
	if (g_cvars.width)
		str_s = width_helper(str_s, sign);
	print_number_h(str_s);
	if (g_cvars.flag[3] != '-')
		ft_putstr(str_s);
	clean();
}