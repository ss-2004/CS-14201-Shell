num=0
c=0
i=0
read -p "Enter a number : " num

for (( i=2; i<num/2; i++ ))
do
	if [ $((num%i)) == 0 ]; then
		((c++))
	fi
done

if [ $c == 0 ]; then
	echo "PRIME"
else
	echo "NOT PRIME"
fi
