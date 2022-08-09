# printf? 
- 다양한 자료형을 문자열의 일부로 받아(서식문자?) 문자열을 standard output stream으로 출력? 
- 가변 인자
	- 함수에 들어가는 인수의 개수가 변하는 것
	- 함수 
		- 반환값 자료형 함수이름(자료형 고정매개변수, ...)
	- 가변인자 사용하기 위한 매크로
		- va_list : 가변 인자 목록, 가변인자의 메모리 주소 저장하는 포인터
		- va_start : 가변인자를 가져올 수 있도록 포인터 설정 
		- va_arg : 가변인자 포인터에서 특정 자료형 크기 만큼 값을 가져옴
		- va_end : 가변 인자 처리가 끝났을 때 포인터를 null 로 초기화함 
	- 가변인자 자료형 약칭
		- 정수 : i
		- 실수 : d
		- 문자 : c
		- 문자열 : s
- study 폴더
	- 기본 사용
		- variable_argument.c
		- variable_argument_print_numbers.c
	- 자료형이 다른 가변인자 함수
		- variable_argument_multiple_types.c

# printf mandatory
<img width="1094" alt="ft_printf (mandatory)" src="https://user-images.githubusercontent.com/107545007/183350417-c8fb6246-988c-4d50-aea3-e7a1d5516b19.png">

## ft_printf 함수
- 가변인자 받기, 끝내기 
- string 하나씩 읽으면서 %가 나오는지 확인
 - % 가 아니면 : 그대로 출력 + 출력 값을 저장하기
 - % 면 : 다음 문자를 specifier 로 인식 하고 va_printf 호출, 
 - va_printf 리턴 값 확인 (-1 인 경우와 정상 출력된 경우) + 리턴 값 저장
- 함수 호출 끝 

## _va_printf 
- 매개변수에 맞는 함수 포인터 찾아서 호출 + 리턴 값 넘기기
	- 함수 포인터 배열 선언 
	- 맞는 인덱스 찾기
 	- 인자 넣어서 함수 호출 및 리턴

## 출력 함수 
- convert_base
	- d, p, i u, x, xx 함수에서 모두 사용 
	- ft_itoa_base 호출 하여 문자열을 10진수로 인지 하고 -> 원하는 진법으로 변환 출력


# printf bonus (bonus branch)

![image](https://user-images.githubusercontent.com/107545007/183407736-8fea52d8-a713-4fd9-8724-8494034387d5.png)


## parsing ? 

- %[flags][width][.precision][length]specifier
	- flags
		- (-) : Left-justify within the given field width; Right justification is the default (see width sub-specifier).
		- (+) : Forces to preceed the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a - sign.
		- (space) : If no sign is going to be written, a blank space is inserted before the value.
		- (#) : Used with o, x or X specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero.
		- (0) : Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).
	- width 
		- (number)	Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger.
	- precision 
		- (.number)	For integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0.

## specifier and flags

		‘-’	‘0’	‘#’	‘ ’	‘+’
	
	c	O	사용안함	사용안함	사용안함	사용안함

	s	O	사용안함	사용안함	사용안함	사용안함

	p	O	사용안함	사용안함	사용안함	사용안함

	d	O	O	사용안함	O	O

	i	O	O	사용안함	O	O

	u	O	O	사용안함	사용안함	사용안함

	x	O	O	O	사용안함	사용안함

	X	O	O	O	사용안함	사용안함

	%	O	O	사용안함	사용안함	사용안함

## - flag
'-' flag 는 0 플래그를 무효화 한다. 

## + flag
'+' flag 는 공백 플래그를 무효화 한다. 

## precision 
s에서는 문자열의 길이 보다 precision 이 작을 경우 문자열을 precision만큼만 출력한다.

숫자 출력( d, i, u, x, X)에서는 자릿수 보다 precision이 작을 경우 무시되고, precision이 클 경우에는 앞에 0이 붙는다. 

부호 와 0x는 precision에 포함 되지 않는다. 

## 0 flag
0 flag는 -와 precision에 무효화 된다.  

## examples 

### width 
printf("*%d*\n", PAGES);    \*959\*

printf("*%2d*\n", PAGES);   \*959\*

printf("*%10d*\n", PAGES);  \* 959\*

printf("*%-10d*\n", PAGES); \*959 \*

### x/X + '#'

printf("%x %X %#x\n", 31, 31, 31); 1f 1F 0x1f

### d width / width + precision / 0 + width / 0 + width + precision 

printf("**%5d**%5.3d**%05d**%05.3d**\n", 6, 6, 6, 6);
1. %5d -> ** 6**
2. %5.3d -> ** 006**
3. %05d -> ** 00006 **
4. %05.3d -> ** 006**

### string 
printf("[%2s]\n", BLURB);   [Authentic imitation!]

printf("[%24s]\n", BLURB);  [ Authentic imitation!]

printf("[%24.5s]\n", BLURB);[               Authe]

printf("[%-24.5s]\n", BLURB);[Authe              ]


# FUNCTIONS 

## ft_printf.c

### int	ft_printf(const char *str, ...);

- 가변인자를 처리하기 위한 처리 
- processing_printf 호출 및 리턴

### static int	_processing_printf(va_list ap, const char *str);
- ft_printf의 고정 매개변수인 str 을 한 글자씩 읽고 확인 
- % 라면
	- _parsing_flags호출 하여 % 다음 문자부터 파싱하여 구조체 정리 => specifier 가 나온 후 인덱스 반환받아 i 갱신
	- _bit_mod_flags 를 호출 하여 flags 간의 관계 정리 
	- _va_printf 호출 하여 프린트 함수 실행
- % 아니면 
	- 그대로 출력 
	- 출력 리턴 값 확인 

### static int	_va_printf(va_list ap, t_format *format);
- typedef int	(*t_funcptr)(t_format *, va_list); 로 선언된 함수들의 함수 포인터 배열을 사용
- *options = "cspdiuxX%"; 문자열 배열을 사용하여 specifier를 처리 하는 함수를 찾아내고 해당 함수를 호출

## ft_printf_bonus.c

### int	_parsing_flags(const char *str, t_format *format);
- % 이후의 문자 부터 specifier 까지의 문자들을 모두 파싱 하여 구조체에 담는 함수
- flags 파싱 (+- #0.)
	- 해당 문자가 숫자가 아닌경우 -> _make_flags 를 호출 하여 flag로 처리 
	- 해당 문자가 0인데 문자열의 첫번째에 위치하거나 해당 문자의 앞의 문자가 '.'이 아닌 경우에도(0) -> _make_flags 를 호출 
- 그 외의 경우 
	- 첫 문자가 아니고, 해당 문자의 앞 문자가 '.' -> precision 
	- 그 외의 경우 -> width
-  spercifier 저장 
### static void	_make_flags(t_format *format, char c)
- flags =  "+- #0." (1 2 4 8 16 32 | 01 02 04 010 020 040)
- 

### void	_bit_mod_flags(t_format *format)

### int	_init_str(t_format *format, int size)

