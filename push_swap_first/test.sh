ko_cnt=0
ok_cnt=0
os=`uname`
for ((i=1; i<=10000; i++)); do
	if [ $os == Linux ]; then
		ARG=`shuf -i 0-10000 -n $i | tr '\n' ' '`;
		ok=`./push_swap $ARG | ./checker_linux $ARG`;
	else
		ARG=`ruby -e "puts (1..$i).to_a.shuffle.join(' ')"`;
		ok=`./push_swap $ARG | ./checker_Mac $ARG`;
	fi
	if [ $ok == OK ]; then
		((ok_cnt++));
	else
		((ko_cnt++));
	fi
	echo "n :" $i "--> ok_cnt" $ok_cnt "ko_cnt" $ko_cnt;
done
