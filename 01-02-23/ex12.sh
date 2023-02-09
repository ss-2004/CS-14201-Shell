read -p "Enter rows : " r
read -p "Enter columns : " c
i=0
echo "Enter elements : "
while [ $i -lt $(( r*c )) ]
do
	read a[$i]
	i=$(( i+1 ))
done

i=0
k=0
echo "Transpose of a Matrix : "
while [ $i -lt $c ]
do
	j=0
	while [ $j -lt $r ]
	do
		n=$(( j*c ))
		m=$(( n+i ))
		b[$k] = ${a[$m]}
		echo "${b[$k]} \t"
		k=$(( k+1 ))
		j=$(( j+1 ))
	done
	i=$(( i+1 ))
	echo "\n"
done
