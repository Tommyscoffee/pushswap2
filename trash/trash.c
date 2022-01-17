/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:15:17 by atomizaw          #+#    #+#             */
/*   Updated: 2022/01/17 17:15:27 by atomizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_slice_str(const char *cmd_arg, char point)
{
	char	*ans;
	int		i;
	int		j;

	i = 0;
	j = 0;
	// printf("cmd_arg = %s\n", cmd_arg);
	while (cmd_arg[i] && cmd_arg[i] != point)
		i++;
	ans = (char *)malloc(sizeof(char) * (i + 1));
	if (!ans)
	{
		printf("malloc失敗\n");
		exit(1);
	}
	i = 0;
	while (cmd_arg[i] && cmd_arg[i] != point)
	{
		ans[i] = cmd_arg[i];
		// printf("cmd_arg[%d] = %c\n",i , ans[i]);
		i++;
	}
	ans[i] = '\0';
	return (ans);
}