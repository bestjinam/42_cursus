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


