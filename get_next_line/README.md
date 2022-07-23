# 할일
1. fd? 
2. read 함수?
3. gnl의 함수 원형?
	- 매개변수 
	- 반환형
	- 명세
4. 구현을 위해 어떤 함수(기능들이)들이 필요할까? 
5. 아무 생각도 나지 않는다 으앜! 살려줘

# fd
- 컴퓨터 하드웨어 ------- (운영체제) ----- (커널) ----- (프로그램) ----- 나
	- 하드웨어 리소스를 운영체제가 관리 하는데,
	- 운영체제 역시 소프트웨어로서 메모리에 올라간다. 
	- (메모리 : 하드웨어에 존재 하는 모든 소프트웨어들은 프로세서를 거쳐서 사용자가 원하는 작업을 수행 한다. 메모리는 프로세서가 처리해야할 데이터나 명령어가 임시로 저장되는 곳으로서 작업 공간의 역할을 한다. 하드디스크의 데이터를 먼저 메모리로 옮겨 담고 프로세서가 메모리에 접근하여 작업을 수행한다. 컴퓨터는 모든 문서와 작업 수행에 필요한 도구가 모두 모여있는 방이라고 한다면 메모리는 어떤 작업을 수행할 수 있는 책상과 같다고 불수 있다 ?????? 아마도?)
	- 아무튼, 운영체제 역시 소프트웨어로 컴퓨터 전원이 켜지면 메모리 위에 있게 되는데, 항상 메모리위에올라와있어야 하는 부분을 제외 하고는 사용자의 요청에 따라 메모리에 올라왔다가 사용이 끝나면 내려간다. 
	- 메모리에 항상 올라와있어야하는 운영체제의 핵심 부분을 커널이라고 한다. 
- 파일 입출력
	- 운영체제는 여러가지 역할과 책임을 담당한믄데 그중에서도 파일 관리와 입출력을 관리 한다. 
	- system call? 무엇? 
	- 프로그램이 커널에 파일 오픈을 요청 하면
		- 접근 승인 
		- global file table에 entry 를만듬! 
		- 프로그램에 entry 위치정보 제공
		- entry 위치 정보 == file descriptor 
	- 그니까... 
		- 각 파일은 고유한 inode 를 가지고 있고, inode - file 을 관리하는 inode table 이 있다. 
		- 소프트웨어가 파일에 접근하려고 하면 global file table 에 엔트리가 생김. 그니까 여러 프로세스 에서 요청 하면 한 파일에 대해서도 여러 entry가 생김 
		- global file table에서 위치정보를 소프트웨어에 반환하고, 
		- 이 반환 값인 fd 를 통해 프로세스에서 파일에 접근 한다. 
- stdin / stdout / stderr 
	- unix like 운영체제에서는 global file table에 위 세가지 입출력은 고정적으로 배정 해둔다. 
	- stdin - 0: keyboard input 등 default data stream 
	- stdiout - 1 : userscreen, default output data stream
	- stderr - 2 :  userscreen, default output data stream
- fd 의 최댓값 
	- fd 는 양수의 값이다. 
	- 0 ~ OPEN_MAX 의 값까지 들어갈 수 있다. 
	- OPEN_MAX는 운영체제 마다 다르다. 
- fd 얻기 
	- C 에서는 open() 함수를 사용하면 된다. 
	- int open(const char **path, int oflag, ...);
	- 이렇게 open 함수를 호출 하면, 
		- global file table 에 entry가 생기는데  mode, innode table pointer offset 이 들어감.
- fd 변경
	- dup() 함수 : fd 복제 함수 
	- 복제 해오면 새로운 fd 값이 할당됨

# read()
- 함수 원형
	- ssize_t	read(int fd, void \*buff*, size_t nbytes);
	- size_t:
		- 32bit : 부호 없는 32bit 정수( == unsigned int)
		- 64bit : 부호 없는 64bit 정수 ( == unsigned long long)
	- ssize_t: signed size type :
		- 32 : int
		- 64 : long long

# 문제
- get next line 함수 호출 -> \n 또는 eof 까지 출력 
- 개행 기준으로 한줄씩 읽어서 malloc  + (realloc) 으로 문자열 만들어서 매개변수 char * 값 바꾸기 
- return 은 성공 / 실패 

## 문제 이해 

- BUFFER_SIZE = 3, file = "hello\nworld\nkakak"

- buf -> hel 저장 (BUFFER_SIZE만큼)
- backup이 비어있는지 확인
	- 비어있으면 buf -> backup 으로 copy
	- 비어있지 않으면 backup = backup + buf
- backup 에 \n 이 있는지확인 -> \n 개수 셈 + 첫번째 \n 인덱스 확인 ? 
- \n(또는 eof)가 있으니까 
- backup의 \n의 위치만큼 잘라서 리턴 준비 
- 자른 위치만큼 backup인덱스 땡겨 넣기 
- backup 비었으면 null 로 변경

두 번째 호출
- buf -> wor 저장
- backup 비어있는지 확인
	- 비어있으면 buf -> backup 으로 저장 
	- 안비어있으면 backup 가장 뒤에 붙이기
- backup에 \n 있는지 확인
	- 없으니까 read -> buf(ld\n)
	- backup 비어있는지 확인 -> 안비어있으니까 backup 뒤에 붙여넣기 
	- backup 에 \n이 있는지 확인
	- backup 에 \n 있으니까 -> \n 위치만큼 잘라서 리턴 준비
	- 자른 위치 만큼 인덱스 땡겨넣기 
	- backup 비었으면 null 로 변경
	- 안비어있으면 그대로

fd -> node 

node 
{
	char	buf[BUFFER_SIZE];
	char	*backup;
	size_t	backup_top; 
	node	*next;
}
