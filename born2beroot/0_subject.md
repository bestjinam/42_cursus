# subject 요약 정리 

# 서문 

밥아조씨 : 참 쉽죠? 

# Chapter 2 

## introduction

이 과제는 가상화(virtualization) 의 세계를 소개하는 과제 입니다. 
구체적인 지시에 따라 virtualbox 에서 생애 첫 머신을 만들어볼거에요. 
이 과제를 끝마치면 엄격한 룰들이 적용되는 당신만의 운영체제를 세팅할 수 있게 될 것임

# chapter 3

## General guidelines 

- virtualbox를 이용하는 것이 기본? 
- 레포지토리의 root 폴더에 signature.txt file 만 넣어야함. 
- 당신의 가상 디스크 서명을 복사해 넣어야함(signature.txt 에?)
  - 디스크 서명을 4바이트, MBR의 파티션 테이블이 처음 생성, 저장 될 때 랜덤하게 생성됨

# chapter 4
## Mandatory part
1. graphic interface ㄴㄴ 
  - 당신은 필요 최소한의 서비스만 세팅 해야함, graphical interface는 필요 없음,x.org 등도 ㄴㄴ
  - x.org : x 윈도 시스템 용 디스플레이 서버 구현체
2. latest stable version 리눅스 (cent os or debian) 설치
  - 서버 운영을 한적없는 뉴비라면 debian 강력 추천 (왜?)
  - cent os 세팅은 매우 복잡하다, 그래서 KDump를 셋업할 필요는 없다.
    - kdump(The kexec-based Crash Dumping Solution)는 커널 패닉(OS 행)이 발생한 당시에 시스템의 메모리 상태를 vmcore 파일로 생성하는 작업을 해줍니다.
  - 하지만 SELinux는 서버 시작할때 작동되어야하며, 프로젝트의 요구사항에 따라 설정 완료 되어야함. 
  - debian의 경우에는 AppArmor가 설정, 작동 되어야 한다. 
3. 최소한 2개 이상의 partition을 암호화 하여 세팅해야함(LVM 사용).
  - LVM (Logical Volume Manager)
    - logical volume을 효율적이고 유연하게 관리 하기 위한 커널의 한 부분이자 프로그램
    - Lvm이 만든 가상 블록장치에 읽고 쓰게 됨
    - 장점 : 유연성 제공
      - 용량 조절, 크기 조정, 편의에 따른 장치 이름 지정, 디스크 스트라이핑, 미러 볼륨 등
4. ssh service 는 4242 port만 열리도록 해야함. 보안을 위해서 ssh 로 직접 root로 연결하는 것은 금지 되어야함.
  - ssh 사용에 대한 평가를 할 때 새로운 계정을 셋업하는 과정을 해볼 것임. 이 방법들을 알아야함
5. UFW firewall을 설정 해야 하며, 4242 port만 열려있도록 해야함
  - UFW (uncomplicated firewall)
    - firewall : 컴퓨터들 간 들어오고 나가는 트래픽(네트워크 장치에서 일정 시간 내에 흐르는 데이터의 양)은 포트에 따라 필터링 됨, 네트워크트래픽을 모니터링 하고, 
    제어하는 네트워크 보안 시스템을 방화벽이라고 함. 
    -  iptables 와 netfilter 
      - netfilter(Kernel space) 는 리눅스 커널 모듈로, 네트워크 패킷을 처리하기 위한 프레임워크 로 다음과 같은 기능을 제공
        - NAT (Network address translation) : 사설 IP 와 공인 IP 를 변환 해주거나 포트 변환 등 
        - Packet filtering : 특정 패킷 차단, 허용, 서버의 접근 제어 또는 방화벽 기능 구현 
        - Packet mangling : 필요시 패킷 헤더의 값을 변경
      - iptables : net filter에 내가 원하는 접근 통제할 수 있도록 룰을 넣는 실행 프로그램(user space)
    - UFW : iptables를 위한 front-end 단으로, iptables의 작업을 간편화 해줌
  - firewall은 당신의 가상머신을 시작할때 반드시 활성화 되야함
6. host name 은 당신의 intra name + 42, 평가 중 host name을 변경할 수 있어야함 
7. 아주 강한 비밀번호 정책을 적용해야함
8. 아주 엄격한 규칙에 따라 sudo를 설치하고 설정 해야함
9. root user 에 더해 활성화된 user가 존재 해야함(intra name?)
10. 위 유저는 user42 와 sudo 그룹에 속해 있어야함.
11. 평가 중 새로운 유저를 생성하고 이 유저를 그룹에 넣을 수 있어야 함 
12. 강한 비밀번호 정책을 셋팅하기 위해 아래와 같은 요구사항에 따라야함
  - 비밀번호는 30일 후 기한 만료됨
  - 비밀번호를 다시 수정하려면 최소 2일 걸림
  - 비밀번호 만료 7일전에 경고 메시지를 보내야함
  - 비밀번호의 최소 길이는 10자 이상이어야 하며, 대문자와 숫자 하나씩은 포함 해야함. 또한 비밀번호에는 3글자 이상 연속된 글자가 포함 될 수 없다. 
  - 유저 이름은 비밀번호에 포함 될 수 없다. 
  - (이 룰은 root 비번에는 포함 안됨) : 비밀번호는 이전 비밀번호와 적어도 7자 이상 달라야함
  - 바로 이전 룰 외에는 모든 규칙이 root 비번 규칙에도 적용 되야함
  - 비밀번호 정책 설정 이후에는 현재 가상머신에 존재하는 모든 계정에 대한 비밀번호를 변경 해야함(root 포함).
13. sudo group 설정 규칙 
  - sudo 인증할 때 잘못된 비밀번호 입력시 3번의 기회 까지로 제한 
  - sudo 사용할 때 잘못된 비밀번호로 된 에러 발생시 당신이 정한 에러메시지가 보여져야함 
  - sudo 를 사용하는 모든 액션 들은 입출력 모두 저장 되야 하며, /var/log/sudo folder에 logfile이 저장 되야 함.
  - 보안을 위해 tty mode 를 사용될 수 있어야 함
  - 보안을 위해 sudo 를 사용할 수 있는 path 들은 매우 엄격하게 제한 되어야함 
    - example : /usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin
14. monitering.sh 생성
  - 위 스크립트는 server 시작한 후 모든 터미널에 매 10분 마다 몇 가지 정보를 알려줌 
  - 보여줘야 하는 정보 
    1. 운영 체제의 architecture 와 kernel version
    2. 물리 cpu 개수 
    3. 가상 cpu 개수 
    4. 현재 서버에서 사용 가능한 ram 과 percent로 표현된 가동률 
    5. 현재 서버에서 사용 가능한 memory 와 percent 로 표현된 가동률 
    6. 프로세서 가동률 
    7. 마지막 리붓한 날짜와 시간
    8. LVM의 활성 / 비활성화 여부
    9. 활성화된 연결의 수 
    10. 서버를 사용하는 유저 수 
    11. IPv4 주소와 MAC 주소
    12. sudo 로 실행한 명령 개수
  - 평가 중에 이 스크립트가 어떻게 작동하는지 설명 할 수 있어야 하고, 위의 스크립트를 변경하지 않고 작동을 일시정지 할 수도 있어야함
  

# Chapter 5
## Bonus part
1. partitions setting
  - sda1
  - sda2 
  - sda5
    - sda5_crypt(LVMGroup)
      - root
      - swap
      - home
      - var
      - srv
      - tmp
      - var--log
2. WordPress 를 설치 해야하는데 lighthttpd, MariaDB PHP 서비스가 연동 되야함
3. NGINX / Apache2 제외하고 니가 생각했을때 유용해보이는 서비스 하나 골라서 설치 해라. 필요성에 대해 설명할 수 있어야함

