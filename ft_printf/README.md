#printf? 
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
