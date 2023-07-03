#include "push_swap.h"

static char	*join_argv(int argc, char *argv[])
{
	long long i;
	long long j;
	long long len;
	long long idx;
	char *ret;

	i = 1;
	len = 0;
	while (i < argc)
		len += ft_strlen(argv[i++]);
	ret = (char *)malloc(sizeof(char) * (len + argc));
	if (!ret)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			ret[idx++] = argv[i][j++];
		if (i != argc - 1)
			ret[idx++] = ' ';
	}
	ret[idx] = '\0';
	return (ret);
}

static int	get_arg_size(const char *str, char c)
{
	int size;
	int i;

	size = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] != '\0')
			size++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (size);
}

static void	check_overlap(t_info *stacks, int data)
{
	int i;
	int *new_list;

	i = 0;
	while (i < stacks->list_size)
	{
		if (stacks->list[i] - data == 0)
			print_error();
		i++;
	}
	stacks->list_size++;
	new_list = (int *)malloc(sizeof(int) * (stacks->list_size));
	if (!new_int)
		print_error();
	if (stacks->list_size == 1)
		new_list[0] = data;
	else
	{
		i = 0;
		while (i < stacks->list_size)
			new_list[i] = stacks->list[i++];
		new_list[i] = data;
	}
	free(stacks->list);
	stacks->list = new_list;
}

void	validate_arg(int argc, char *argv[], t_info *stacks)
{
	char 	*args;
	char **tmp;
	int 	argv_size;
	int i;
	t_node *new_node;

	args = join_argv(argc, argv);
	argv_size = get_arg_size(args, ' ');
	tmp = ft_split(args, ' ');
	free(args);
	i = 0;
	while (i < argv_size)
	{
		if (!check_valid_atoi(tmp[i]))
			print_error();
		new_node = make_new_node(ps_atoi(tmp[i]));
		free(tmp[i]);
		check_overlap(stacks, new_node->data);
		i++;
		free(new_node);
	}
	free(tmp);
}