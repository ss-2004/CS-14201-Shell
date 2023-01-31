dirname=${1}
mkdir $dirname
i=2

for i in $@
do
	filename=$i
	cp $filename $dirname
done
