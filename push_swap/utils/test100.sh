ko_cnt=0
ok_cnt=0
max=0
min=999999999
os=`uname`
for ((i=1; i<=10000; i++)); do
	if [ $os == Linux ]; then
		ARG=`shuf -i 0-10000 -n 100 | tr '\n' ' '`;
		ok=`./push_swap $ARG | ./checker_linux $ARG`;
	else
		ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`;
		ok=`./push_swap $ARG | ./checker_Mac $ARG`;
	fi
	cnt=`./push_swap $ARG | wc -l`;
	if [ $ok == OK ]; then
		((ok_cnt++));
	else
		((ko_cnt++));
	fi
	if [ $cnt -gt $max ]; then
		max=$cnt
	fi
	if [ $cnt -lt $min ]; then
		min=$cnt
	fi
	echo $i "--> operation:" $cnt "ok_cnt" $ok_cnt "max num" $max "min num" $min;
done
