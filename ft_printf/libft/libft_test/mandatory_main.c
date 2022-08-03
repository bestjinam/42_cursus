/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:48:15 by jinam             #+#    #+#             */
/*   Updated: 2022/07/19 18:48:51 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

void	_static_test(void);

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("!!!\n");
		_static_test();
		(void) argv;
		return (0);
	}
}

char	f1(unsigned int i, char c)
{
	return (i + c);
}

void	f2(unsigned int i, char *str)
{
	printf("%d : %c\n",i,  *str);
}

void	_static_test(void)
{
	printf("#####################################################################################\n");
	printf("----PART1 START----\n");
	printf("\n");
	{
		printf("#################################################################################\n");
		printf("# ft_ctype_classification.c														#\n");
		printf("#################################################################################\n");
		printf("\n");
		printf("\n");
		printf("1. isalpha\n");
		printf("\n");
		printf("char A : ft -> %d // std -> %d (%s)\n", ft_isalpha('A'), isalpha('A'),(ft_isalpha('A') == isalpha('A') ? "OK": "KO") );
		printf("\n");
		printf("char a : ft -> %d // std -> %d (%s)\n", ft_isalpha('a'), isalpha('a'),(ft_isalpha('a') == isalpha('a') ? "OK": "KO") );
		printf("\n");
		printf("char - : ft -> %d // std -> %d (%s)\n", ft_isalpha('-'), isalpha('-'),(ft_isalpha('-') == isalpha('-') ? "OK": "KO") );
		printf("\n");
		printf("2. isdigit\n");
		printf("\n");
		printf("char 1 : ft -> %d // std -> %d (%s)\n", ft_isdigit('0'), isdigit('0'),(ft_isdigit('0') == isdigit('0') ? "OK": "KO") );
		printf("\n");
		printf("char 9 : ft -> %d // std -> %d (%s)\n", ft_isdigit('9'), isdigit('9'),(ft_isdigit('9') == isdigit('9') ? "OK": "KO") );
		printf("\n");
		printf("char - : ft -> %d // std -> %d (%s)\n", ft_isdigit('-'), isdigit('-'),(ft_isdigit('-') == isdigit('-') ? "OK": "KO") );
		printf("\n");
		printf("3. isalnum\n");
		printf("\n");
		printf("char A : ft -> %d // std -> %d (%s)\n", ft_isalnum('A'), isalnum('A'),(ft_isalnum('A') == isalnum('A') ? "OK": "KO") );
		printf("\n");
		printf("\n");
		printf("char 1 : ft -> %d // std -> %d (%s)\n", ft_isalnum('1'), isalnum('1'),(ft_isalnum('1') == isalnum('1') ? "OK": "KO") );
		printf("\n");
		printf("char - : ft -> %d // std -> %d (%s)\n", ft_isalnum('-'), isalnum('-'),(ft_isalnum('-') == isalnum('-') ? "OK": "KO") );
		printf("\n");
		printf("4. isascii\n");
		printf("\n");
		printf("char Z       : ft -> %d // std -> %d (%s)\n", ft_isascii('Z'), isascii('Z'),(ft_isascii('Z') == isascii('A') ? "OK": "KO") );
		printf("\n");
		printf("char ' '     : ft -> %d // std -> %d (%s)\n", ft_isascii(' '), isascii(' '),(ft_isascii(' ') == isascii('1') ? "OK": "KO") );
		printf("\n");
		printf("char Z + 100 : ft -> %d // std -> %d (%s)\n", ft_isascii('Z' + 100), isascii('Z' + 100),(ft_isascii('Z' + 100) == isascii('Z' + 100) ? "OK": "KO") );
		printf("\n");
		printf("5. isaprint\n");
		printf("\n");
		printf("char ~     : ft -> %d // std -> %d (%s)\n", ft_isprint('~'), isprint('~'),(ft_isprint('~') == isprint('~') ? "OK" : "KO") );
		printf("\n");
		printf("char ' '   : ft -> %d // std -> %d (%s)\n", ft_isprint(' '), isprint(' '),(ft_isprint(' ') == isprint(' ') ? "OK" : "KO") );
		printf("\n");
		printf("char ~ + 1 : ft -> %d // std -> %d (%s)\n", ft_isprint('~' + 1), isprint('~' + 1),(ft_isprint('~' + 1) == isprint('~' + 1) ? "OK": "KO") );
		printf("\n");
		printf("#################################################################################\n");
		printf("# ft_ctype_case_mapping.c														#\n");
		printf("#################################################################################\n");
		printf("1. toupper\n");
		printf("char a : ft -> %c // std -> %c (%s)\n", ft_toupper('a'), toupper('a'), (ft_toupper('a') == toupper('a') ? "OK" : "KO"));
		printf("\n");
		printf("char - : ft -> %c // std -> %c (%s)\n", ft_toupper('-'), toupper('-'), (ft_toupper('-') == toupper('-') ? "OK" : "KO"));
		printf("\n");
		printf("2. tolower\n");
		printf("\n");
		printf("char A : ft -> %c // std -> %c (%s)\n", ft_tolower('A'), tolower('A'), (ft_tolower('A') == tolower('A') ? "OK" : "KO"));
		printf("\n");
		printf("char - : ft -> %c // std -> %c (%s)\n", ft_tolower('-'), tolower('-'), (ft_tolower('-') == tolower('-') ? "OK" : "KO"));
		printf("\n");
		printf("#################################################################################\n");
		printf("# ft_string_miscellaneous.c														#\n");
		printf("#################################################################################\n");
		printf("string.h\n");
		printf("\n");
		printf("1. strlen \n");
		printf("\n");
		printf("\n");
		printf("str HELLO WORLD ft-> %lu // std -> %lu (%s)\n", ft_strlen("HELLO WORLD"), strlen("HELLO WORLD"), (ft_strlen("HELLO WORLD")== strlen("HELLO WORLD") ? "OK" : "KO"));

		printf("2. memset\n");
		printf("\n");
		printf("\n");
		char memset_str1[12] = "HELLO WORLD";
		char memset_str2[12] = "HELLO WORLD";
		ft_memset(memset_str1, 'K', 5);
		memset(memset_str2, 'K', 5);
		printf("HELLO WORLD -> KKKKK WORLD ft-> %s // std->%s (%s)\n", memset_str1, memset_str2, (*memset_str1 == *memset_str2) ? "OK" : "KO");

		printf("strings.h : bzero\n");
		char bzero_str1[12] = "HELLO WORLD";
		char bzero_str2[12] = "HELLO WORLD";
		ft_bzero(bzero_str1, 5);
		bzero(bzero_str2, 5);
		printf("HELLO WORLD -> 00000 WORLD\n");
		int i = 0;
		while (i < 11)
		{
			printf("ft: %c std: %c \n", bzero_str1[i], bzero_str2[i]);
			i ++;
		}

		printf("#################################################################################\n");
		printf("# ft_string_copying.c															# \n");
		printf("#################################################################################\n");
		printf("\n");
		printf("\n");
		printf("1. memcpy\n");
		char	memcpy_s1[12];
		char	memcpy_s2[12] = "HELLO WORLD";
		char	ft_memcpy_s1[12];
		char	ft_memcpy_s2[12] = "HELLO WORLD";

		ft_memcpy(ft_memcpy_s1, ft_memcpy_s2, 12);
		memcpy(memcpy_s1, memcpy_s2, 12);
		printf("HELLO WORLD || ft-> %s // std-> %s (%s)\n", ft_memcpy_s1, memcpy_s1, (*ft_memcpy_s1 == *memcpy_s1) ? "OK" : "KO");

		// s1[11] == s2[0];
		char	*backbone;
		char	*bugmemcpy_src;
		char	*bugmemcpy_dst;
		backbone = malloc(sizeof(char) * 23);
		backbone[22] = 0;
		bugmemcpy_dst = &backbone[8];
		bugmemcpy_src = &backbone[0];
		ft_memcpy(bugmemcpy_src, "HELLO WORLD", 12);
		ft_memcpy(bugmemcpy_dst, bugmemcpy_src, 12);
		printf("BACKBONE\n");
		i = -1;
		while (++i < 23)
			printf("%d : %c\n", i, backbone[i]);
		printf("ft_memcpy result: %s\n", bugmemcpy_dst);
		free(backbone);
		printf("\n");

		printf("2. memmove \n");
		char	memmove_s1[12];
		char	memmove_s2[12] = "HELLO WORLD";
		char	ft_memmove_s1[12];
		char	ft_memmove_s2[12] = "HELLO WORLD";

		ft_memmove(ft_memmove_s1, ft_memmove_s2, 12);
		memmove(memmove_s1, memmove_s2, 12);
		printf("HELLO WORLD || ft-> %s // std-> %s (%s)\n", ft_memmove_s1, memmove_s1, (*ft_memmove_s1 == *memmove_s1) ? "OK" : "KO");

		// s1[11] == s2[0];
		char	*backbone_1;
		char	*bugmemmove_src;
		char	*bugmemmove_dst;
		backbone_1 = malloc(sizeof(char) * 23);
		backbone_1[22] = 0;
		bugmemmove_dst = &backbone_1[8];
		bugmemmove_src = &backbone_1[0];
		ft_memmove(bugmemmove_src, "HELLO WORLD", 12);
		ft_memmove(bugmemmove_dst, bugmemmove_src, 12);
		printf("BACKBONE\n");
		i = -1;
		while (++i < 23)
			printf("%d : %c\n", i, backbone_1[i]);
		printf("ft_memmove result: %s\n", bugmemmove_dst);
		free(backbone_1);

		printf("\n");
		printf("3. strlcpy\n");
		char	strlcpy_s1[12];
		char	strlcpy_s2[12] = "HELLO WORLD";
		char	ft_strlcpy_s1[12];
		char	ft_strlcpy_s2[12] = "HELLO WORLD";

		ft_strlcpy(ft_strlcpy_s1, ft_strlcpy_s2, 12);
		strlcpy(strlcpy_s1, strlcpy_s2, 12);
		printf("HELLO WORLD || ft-> %s // std-> %s (%s)\n", ft_strlcpy_s1, strlcpy_s1, (*ft_strlcpy_s1 == *strlcpy_s1) ? "OK" : "KO");
		ft_strlcpy_s1[0] = 0;
		strlcpy_s1[0] = 0;
		printf(" dstsize 0: ft_strlcpy-> %lu, %s // std-> %lu, %s (%s)\n", ft_strlcpy(ft_strlcpy_s1, ft_strlcpy_s2, 0), ft_strlcpy_s1, strlcpy(strlcpy_s1, strlcpy_s2, 0), strlcpy_s1, (*ft_strlcpy_s1 == *strlcpy_s1) ? "OK" : "KO");

		printf(" dstsize 6: ft_strlcpy-> %lu, %s // std-> %lu, %s (%s)\n", ft_strlcpy(ft_strlcpy_s1, ft_strlcpy_s2, 6), ft_strlcpy_s1, strlcpy(strlcpy_s1, strlcpy_s2, 6), strlcpy_s1, (*ft_strlcpy_s1 == *strlcpy_s1) ? "OK" : "KO");

		printf("\n");
		printf("#################################################################################\n");
		printf("#ft_string_concat.c (strlcat)													#\n");
		printf("#################################################################################\n");
		printf("\n");
		printf("\n");

		char	strlcat_dst[12] = "HELLO";
		char	strlcat_src[7] = " WORLD";

		char	ft_strlcat_dst[12] = "HELLO";
		char	ft_strlcat_src[7] = " WORLD";

		ft_strlcat(ft_strlcat_dst, ft_strlcat_src, 12);
		strlcat(strlcat_dst, strlcat_src, 12);
		printf("HELLO + WORLD = ft-> %s // std-> %s \n", ft_strlcat_dst, strlcat_dst);

		printf("\n");
		printf("#################################################################################\n");
		printf("#ft_string_comparison.c															#\n");
		printf("#################################################################################\n");
		printf("\n");
		printf("\n");
		printf("1. memcmp \n");
		char	memcmp_s1[5] = "abcd";
		char	memcmp_s2[5] = "abca";

		printf("s1 : %s s2 : %s ", memcmp_s1, memcmp_s2);
		printf("size 4 ft_memcmp : %d memcmp : %d \n", ft_memcmp(memcmp_s1, memcmp_s2, 4), memcmp(memcmp_s1, memcmp_s2, 4));
		printf("s1 : %s s2 : %s ", memcmp_s1, memcmp_s2);
		printf("size 3 ft_memcmp : %d memcmp : %d \n", ft_memcmp(memcmp_s1, memcmp_s2, 3), memcmp(memcmp_s1, memcmp_s2, 3));

		printf("\n");
		printf("2. strncmp \n");
		char	strncmp_s1[5] = "abcd";
		char	strncmp_s2[5] = "abca";

		printf("s1 : %s s2 : %s ", strncmp_s1, strncmp_s2);
		printf("size 4 ft_strncmp : %d strncmp : %d \n", ft_strncmp(strncmp_s1, strncmp_s2, 4), strncmp(strncmp_s1, strncmp_s2, 4));
		printf("s1 : %s s2 : %s ", strncmp_s1, strncmp_s2);
		printf("size 3 ft_strncmp : %d strncmp : %d \n", ft_strncmp(strncmp_s1, strncmp_s2, 3), strncmp(strncmp_s1, strncmp_s2, 3));

		char	strncmp_s3[5] = "ab";
		char	strncmp_s4[5] = "abca";

		printf("s1 : %s s2 : %s ", strncmp_s3, strncmp_s4);
		printf("size 4 ft_strncmp : %d strncmp : %d \n", ft_strncmp(strncmp_s3, strncmp_s4, 4), strncmp(strncmp_s3, strncmp_s4, 4));

		printf("\n");
		printf("\n");

		printf("#################################################################################\n");
		printf("#ft_string_search.c																#\n");
		printf("#################################################################################\n");
		printf("\n");
		printf("\n");
		printf("1. memchr\n");
		char	memchr_s[5] = "aaaf";
		char	memchr_c = 'f';
		printf("s : %s, c : %c \n", memchr_s, memchr_c);
		printf("size : 4, ft_memchr -> %p // memchr -> %p \n", ft_memchr(memchr_s, memchr_c, 4), memchr(memchr_s, memchr_c, 4));
		printf("size : 2, ft_memchr -> %p // memchr -> %p \n", ft_memchr(memchr_s, memchr_c, 2), memchr(memchr_s, memchr_c, 2));

		printf("\n");
		printf("2. strchr\n");

		char	strchr_s[6] = "afaaf";
		char	strchr_c = 'f';

		printf("s: %s, c: %c \n", strchr_s, strchr_c);
		printf("ft_strchr -> %p // strchr -> %p \n", ft_strchr(strchr_s, strchr_c), strchr(strchr_s, strchr_c));

		printf("\n");
		printf("3. strrchr\n");


		printf("s: %s, c: %c \n", strchr_s, strchr_c);
		printf("ft_strrchr -> %p // strrchr -> %p \n", ft_strrchr(strchr_s, strchr_c), strrchr(strchr_s, strchr_c));

		printf("\n");
		printf("4. strnstr\n");
		char	*haystack = "stringstrongstang";
		char	*needle = "strong";
		printf("case 1: size ftstrlen(haystack)\n s: %s, n: %s\n", haystack, needle);
		printf("ft_strnstr ->  %s // strnstr -> %s ",
			   ft_strnstr(haystack, needle, ft_strlen(haystack)), strnstr(haystack, needle, strlen(haystack)));
		printf("(%s)\n", ft_strnstr(haystack, needle, ft_strlen(haystack)) == strnstr(haystack, needle, strlen(haystack))? "OK" : "KO");
		printf("case 2: size 6\n s: %s, n: %s\n", haystack, needle);
		printf("ft_strnstr ->  %s // strnstr -> %s ",
		ft_strnstr(haystack, needle, 6), strnstr(haystack, needle, 6));
		printf("(%s)\n", ft_strnstr(haystack, needle, 6) == strnstr(haystack, needle, 6) ? "OK" : "KO");
		printf("\n");
		printf("\n");

		printf("#################################################################################\n");
		printf("#ft_string_duplicate.c															#\n");
		printf("#################################################################################\n");
		printf("\n");
		printf("\n");
		char *str_dup;
		char *ft_str_dup;
		char *dup_src = "hello world!";

		str_dup = strdup(dup_src);
		ft_str_dup = ft_strdup(dup_src);
		printf("src : %s\n", dup_src);
		printf("ft_strdup -> %s // std -> %s ", ft_str_dup, str_dup);
		printf("(%s)\n",*ft_str_dup == *str_dup ? "OK" : "KO");
		free(str_dup);
		free(ft_str_dup);
		printf("\n");
		printf("\n");

		printf("#################################################################################\n");
		printf("#ft_stdlib.c																	#\n");
		printf("#################################################################################\n");
		printf("\n");
		printf("\n");

		printf("1. atoi \n");
		printf("2147483647 : ft_atoi -> %d // atoi -> %d \n", ft_atoi("2147483647"), atoi("2147483647"));
		printf("-2147483648 : ft_atoi -> %d // atoi -> %d \n", ft_atoi("-2147483648"), atoi("-2147483648"));
		printf("\n");

		printf("2. calloc\n");
		char	*ft_call;
		char	*call;
		printf("calloc count = 5, size = sizeof(char)\n");
		ft_call = ft_calloc(5, sizeof(char));
		call = calloc(5, sizeof(char));
		i = 0;
		while (i < 5)
		{
			printf("idx = %d ft_call = %d, call = %d \n", i, ft_call[i], call[i]);
			i ++;
		}
		free(ft_call);
		free(call);
		printf("\n");
		printf("\n");
	printf("----PART1 END------\n");
	}

	printf("#################################################################################\n");
	printf("----PART2 START----\n");
	{
		printf("\n");
		printf("\n");
		printf("#################################################################################\n");
		printf("#ft__string.c																	#\n");
		printf("#################################################################################\n");
		printf("\n");
		printf("\n");
		printf("1. substr\n");
		char	*ft_sub_str;

		ft_sub_str = ft_substr("HAHA HELLO WORLD!", 5, 12);
		printf("original string : %s \n", "HAHA HELLO WORLD!");
		printf("1) ft_substr(start : 5, len : 12) : %s \n", ft_sub_str);
		ft_sub_str = ft_substr("HAHA HELLO WORLD!", 17, 12);
		printf("2) ft_substr(start : 17, len : 12) : %s \n", ft_sub_str);
		free(ft_sub_str);
		printf("\n");
		printf("2. strjoin\n");
		char	*join1;
		char	*join2;
		char	*join_result;
		join1 = "HELLO ";
		join2 = "WORLD!";
		join_result = ft_strjoin(join1, join2);
		printf("join s1 : %s, s2 : %s ft_strjoin -> %s \n", join1, join2, join_result);
		free(join_result);
		join1 = "";
		join2 = "GOOD!";
		join_result = ft_strjoin(join1, join2);
		printf("join s1 : %s, s2 : %s ft_strjoin -> %s \n", join1, join2, join_result);
		free(join_result);

		printf("\n");
		printf("3. strtrim\n");
		char	*trim_str;
		char	*trim_char;
		char	*trim_result;

		trim_str = "##########HELLO WORLD?############??";
		trim_char = "#?";
		trim_result = ft_strtrim(trim_str, trim_char);
		printf("trim_string : %s\n", trim_str);
		printf("trim_charset : %s\n", trim_char);
		printf(">> trim_result : %s\n", trim_result);
		free(trim_result);
		trim_str = "##########HELLO##WORLD?############??";
		trim_char = "#?";
		trim_result = ft_strtrim(trim_str, trim_char);
		printf("trim_string : %s\n", trim_str);
		printf("trim_charset : %s\n", trim_char);
		printf(">> trim_result : %s\n", trim_result);
		free(trim_result);
		trim_str = "##########HELLO WORLD";
		trim_char = "#?";
		trim_result = ft_strtrim(trim_str, trim_char);
		printf("trim_string : %s\n", trim_str);
		printf("trim_charset : %s\n", trim_char);
		printf(">> trim_result : %s\n", trim_result);
		free(trim_result);
		trim_str = "##########HELLO##WORLD####!!";
		trim_char = "#?";
		trim_result = ft_strtrim(trim_str, trim_char);
		printf("trim_string : %s\n", trim_str);
		printf("trim_charset : %s\n", trim_char);
		printf(">> trim_result : %s\n", trim_result);
		free(trim_result);
		printf("\n");
		printf("\n");

		printf("#################################################################################\n");
		printf("#ft__string_split.c																#\n");
		printf("#################################################################################\n");
		printf("\n");
		printf("\n");
		char	*split_str;
		char	split_char;
		char	**split_result;
		split_str = "aaa/bbb/ccc";
		split_char = '/';
		printf("split_string : %s, split_char : %c \n", split_str, split_char);
		split_result = ft_split(split_str, split_char);
		int i = -1;
		while (split_result[++i])
			printf("%d, %s\n", i, split_result[i]);
		free(split_result);

		printf("\n");
		printf("\n");
		printf("#################################################################################\n");
		printf("# ft__stdlib.c (itoa)															#\n");
		printf("#################################################################################\n");
		printf("\n");
		printf("\n");
		int		itoa_input;
		char	*itoa_result;
		itoa_input = 2147483647;
		itoa_result = ft_itoa(itoa_input);
		printf("itoa input : %d , itoa result : %s\n", itoa_input, itoa_result);
		free(itoa_result);
		itoa_input = -2147483648;
		itoa_result = ft_itoa(itoa_input);
		printf("itoa input : %d , itoa result : %s\n", itoa_input, itoa_result);
		free(itoa_result);
		printf("\n");
		printf("\n");
		printf("#################################################################################\n");
		printf("#ft__string_function.c															#\n");
		printf("#################################################################################\n");
		printf("\n");
		printf("\n");
		printf("1. strmapi\n");
		char	*mapi_str;
		char	*mapi_result;

		mapi_str = "01234";
		mapi_result = ft_strmapi(mapi_str, f1);
		i = 0;
		printf("strmapi input : %s \n", mapi_str);
		while (mapi_result[i])
		{
			printf("%d. %c\n",i,  mapi_result[i]);
			i ++;
		}
		free(mapi_result);

		printf("2. striteri\n");
		printf("iteri function : printf \n");
		char *striteri_input;

		striteri_input = "COUNT DOWN 54321!";

		printf(">>ft_striteri : \n");
		ft_striteri(striteri_input, f2);

		printf("\n");
		printf("#################################################################################\n");
		printf("#ft__print_functions.c															#\n");
		printf("#################################################################################\n");
		printf("1. ft_putchar_fd \n");
		printf("putchar_fd input = !\n");
		ft_putchar_fd('!', 1);
		ft_putchar_fd('!', 2);
		printf("2. ft_putstr_fd\n");
		printf("putstr_fd input = HELLO WORLD!\n");
		ft_putstr_fd("HELLO WORLD!\n", 1);
		ft_putstr_fd("ERROR WORLD!\n", 2);
		printf("3. ft_putendl_fd\n");
		printf("putendle_fd input = HELLO HELLO!\n");
		ft_putendl_fd("HELLO HELLO!", 1);
		ft_putendl_fd("ERROR ERROR!", 2);
		printf("4. ft_putnbr_fd\n");
		printf("putnbr_fd input = 2147483647\n");
		ft_putnbr_fd(2147483647, 1);
		printf("\n");
		printf("putnbr_fd input = -2147483648\n");
		ft_putnbr_fd(-2147483648, 1);
		printf("\n");
	}
	printf("----PART2 END------\n");
}
