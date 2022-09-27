- exit logout
- su username / su -
- systemctl 
	- systemd(system daemon)을 관리하는 명령어
	- systemd 는 unix 시스템이 부팅후 가장 먼저 생성되어 다른 프로세스를 실행하는 init역할을 대체 하는 데몬
- systemctl status 서비스명 : 상태 확인
- systemctl enable 서비스명 : 부팅시 자동 시작
- systemctl start
- systemctl reboot
- systemctl poweroff
- sudo apt list --installed

- cat /etc/os-release : os 정보 확인 
- lsblk : 파티션 확인
- apt --version
- date 

## LVM 관련 명령어 

- lsblk : 블록 스토리지 리스트 확인
- pvdisplay : 생성된 pv 확인
- vgdisplay : 생성된 vg 확인
- lvdisplay : 생성된 lv 확인
- fdisk -l : 알려진 파티션 유형 목록 출력 
