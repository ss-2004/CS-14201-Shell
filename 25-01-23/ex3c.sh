n=0
file="/Users/ShresthS/Desktop/CSE/ASSGN/SEM4/shll/25-01-23/ex3in.txt"
while IFS= read -r line
do
    n=$line 
done < "$file"

for (( i=1; i<=10; i++ ))
do
    echo $n "x" $i "=" $(( n * i ))
done

