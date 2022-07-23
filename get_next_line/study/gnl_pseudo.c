/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_pseudo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:00:37 by jinam             #+#    #+#             */
/*   Updated: 2022/07/23 19:11:48 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	char		*buf : read 함수로 버퍼사이즈 만큼 읽어올때 저장되는 스트림
	static char	*backup; 개행을 만나기 전까지의 문자열을 합치면서 저장할 포인터
	int			fd; : 파일 디스크립터 테이블의 인덱스 값
	int			read_size; read 함수로 읽어온 바이트의 양
*/
int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*backup;
	int			fd;
	int			read_size;

	if (fd 불가능 조건 || line 이 들어오지 않았을 때 || 버퍼사이즈 불가능 조건 
		|| 버퍼 저장할 문자열 malloc 에러 처리)
		return (-1);
	while ( read_size = read(fd, buffer, BUFFER_SIZE))
	{
		//읽어온 buffer 마지막에 0 추가하기 
		//backup = 문자열 합치기 (backup, buf)
		if (backup 에 개행이 잇으면?)
		{
			// 개행이 발견된 인덱스의 값을 0으로 바꿔준다. 
			//-> strlen, strdup 등 문자열 관련 함수를 사용할 때 해당 위치가 0 이면 문자열 끝으로 인식
			/*
			 * function strslice()
			 * 1. 에러가 발생한경우 return -1
			 * 2. 이전 단계에서 합쳐진 문자열 backup 에서 개행이 발견된 경우 
			 * - 개행 앞부분은 line 에 할당 
			 *   개행 뒷부분은 backup에 저장 
			 *   return 0
			 */
		}
		return (문자열 처리 및 return value 처리)
	}
	/*function return_check() 에서 고려할 내용 
	 read 로 읽어온 사이즈가 0 으로 나왔을 경우 처리할 조건들 
	 1. read_size = -1 
		오류가 발생했으므로 return -1
	 2. read_size = 0, backup = null
		라인에 빈 문자열을 할당해주고 return 0
	 3. read_size = 0, backup 이 남아있을 때 
	 backup에 저장한 문자열을 line에 넣고 return 0
	*/

}
