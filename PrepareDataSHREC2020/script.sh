!#/bin/bash

#Transformar PLY
#for i in $(ls *.ply);
#do
#	len=${#i}
#	len=`expr $len - 4`
#	output=${i:0:$len}
#	meshlab.meshlabserver -i $i -o $output.off
#done

#Crear dataset
for i in $(ls *.off);
do
	echo "Processing "$i
	PrepareDataset $i
done
