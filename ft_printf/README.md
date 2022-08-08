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

<img width="1282" alt="ft_printf (bonus)" src="https://user-images.githubusercontent.com/107545007/183358609-975552d1-638d-4ecc-8c84-972611557ed4.png">

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
	
	c	O	O	사용안함	사용안함	사용안함

	s	O	사용안함	사용안함	사용안함	사용안함

	p	O	사용안함	사용안함	사용안함	사용안함

	d	O	O	사용안함	O	O

	i	O	O	사용안함	O	O

	u	O	O	사용안함	사용안함	사용안함

	x	O	O	O	사용안함	사용안함

	X	O	O	O	사용안함	사용안함

	%	O	O	사용안함	사용안함	사용안함

## - flag
'-' flag 는 공백과 0 플래그를 무효화 한다. 

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
3. %05d -> **00006**
4. %05.3d -> ** 006**

### string 
printf("[%2s]\n", BLURB);   [Authentic imitation!]

printf("[%24s]\n", BLURB);  [ Authentic imitation!]

printf("[%24.5s]\n", BLURB);[               Authe]

printf("[%-24.5s]\n", BLURB);[Authe              ]


