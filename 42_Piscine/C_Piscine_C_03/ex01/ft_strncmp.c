/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 03:58:43 by andrefil          #+#    #+#             */
/*   Updated: 2023/09/06 12:51:44 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && (i < n))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int	main(int argc, char **argv)
// {
// 	printf("%d\n", ft_strncmp(argv[1], argv[2], 5));
// 	printf("%d\n", strncmp(argv[1], argv[2], 5));
// 	return (0);
// }

// int main()
// {
//     char str1[] = "Hello";
//     char str2[] = "Hellp";
//     char str3[] = "Hello";
//     char str4[] = "World";
//     char str5[] = "H";
//     char str6[] = "Hello";
//     int result1 = ft_strncmp(str1, str2, 5);
//     int result2 = ft_strncmp(str1, str3, 5);
//     int result3 = ft_strncmp(str1, str4, 5);
//     int result4 = ft_strncmp(str1, str5, 1);
//     int result5 = ft_strncmp(str1, str6, 6);
// 	int result6 = strncmp(str1, str2, 5);
//     int result7 = strncmp(str1, str3, 5);
//     int result8 = strncmp(str1, str4, 5);
//     int result9 = strncmp(str1, str5, 1);
//     int result10 = strncmp(str1, str6, 6);

//     printf("Result1: %d\n", result1);
//     printf("Result2: %d\n", result2);
//     printf("Result3: %d\n", result3);
//     printf("Result4: %d\n", result4);
//     printf("Result5: %d\n", result5);
// 	printf("Result6: %d\n", result6);
//     printf("Result7: %d\n", result7);
//     printf("Result8: %d\n", result8);
//     printf("Result9: %d\n", result9);
//     printf("Result10: %d\n", result10);
//     return 0;
// }
