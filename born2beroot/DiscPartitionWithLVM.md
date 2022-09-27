# 여러 파티션으로 나누는 이유 ? 

주식 분산 투자로 위험을 낮추는 것과 같이 같은 바구니에 모든 달걀을 넣어 두는 것보다는 
어떤 규칙에 따라 다른 파티션으로 나눠두는 것이 안전 하다.

# born2beroot 에서 정한 규칙 

- boot : boot loader의 정적 파일들 
	- boot loader ?  운영체제가 시동되기 전에 미리 실행 되면서 커널이 올바르게 시동되기 위해 필요한 모든 작업을 하는 프로그램
- root : root 유저의 홈 디렉토리 
- home : 유저들의 홈 디렉토리 
- swap : 운영체제가 작업을 하기 위한 파티션으로, RAM overflow가 났을 때 이 공간을 램 대신 사용하여 시스템의 효율을 높임. 
- var : 다양한 잡다한 데이터들을 모음 (자주 바뀌는 데이터들 ..)
	- var/log
- srv : system 에 의해 제공되는 service 들의 데이터 

# LVM (Logical Volume Manager)

리눅스 하드 디스크 메모리를 관리하기 위한 유연하고 동적인 관리 시스템이다. 
가상 파티션을 만드는 프로그램으로, 서버를 운영할 때 유용한 프로그램이며, 메모리 자원의 관리를 안정적이며 빠르게 할 수 있도록 해준다. 
사용자가 필요로 하는 만큼 많은 파티션을 나눌 수 있도록 하며, 물리장치를 재시작하지 않고도 파티션의 크기를 조절 하거나 옮기거나 파티션을 동결(?) 시킬 수 있다.

LVM 을 사용하면 하나의 물리 하드디스크 파티션을 여러개의 Logical volume 으로 나누어 분리 할 수 있다. 

pisical volume -> physical extent -> volume group -> logical volume 

## 관련 명령어 

- lsblk : 블록 스토리지 리스트 확인
- pvdisplay : 생성된 pv 확인
- vgdisplay : 생성된 vg 확인
- lvdisplay : 생성된 lv 확인
- fdisk -l : 알려진 파티션 유형 목록 출력 

