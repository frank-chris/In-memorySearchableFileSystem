#!/bin/bash

csv_path=../ondisk_1.csv

cd comparison/disk

touch $csv_path

printf "command,time\n" >> $csv_path

# mkdir

start_time=`date +%s%N`
echo $start_time

for ((i=1;i<=10000;i++)); 
do 
   mkdir $i
done

end_time=`date +%s%N`
elapsed_time=`expr $end_time - $start_time`
echo $elapsed_time

printf "mkdir,$elapsed_time\n" >> $csv_path

# touch

start_time=`date +%s%N`
echo $start_time

for ((i=1;i<=10000;i++)); 
do 
   touch $i/$i.txt
done

end_time=`date +%s%N`
elapsed_time=`expr $end_time - $start_time`
echo $elapsed_time

printf "touch,$elapsed_time\n" >> $csv_path

# writing data in the files

for ((i=1;i<=10000;i++)); 
do 
   printf "abcdefgh" >> $i/$i.txt
done

# ls

start_time=`date +%s%N`
echo $start_time

for ((i=1;i<=10000;i++)); 
do 
   ls $i
done

end_time=`date +%s%N`
elapsed_time=`expr $end_time - $start_time`
echo $elapsed_time

printf "ls,$elapsed_time\n" >> $csv_path

# stat

start_time=`date +%s%N`
echo $start_time

for ((i=1;i<=10000;i++)); 
do 
   stat $i/$i.txt
done

end_time=`date +%s%N`
elapsed_time=`expr $end_time - $start_time`
echo $elapsed_time

printf "stat,$elapsed_time\n" >> $csv_path

# cp

start_time=`date +%s%N`
echo $start_time

for ((i=1;i<=10000;i++)); 
do 
   cp ../sample $i/sample
done

end_time=`date +%s%N`
elapsed_time=`expr $end_time - $start_time`
echo $elapsed_time

printf "cp,$elapsed_time\n" >> $csv_path

# mv

start_time=`date +%s%N`
echo $start_time

for ((i=1;i<=10000;i++)); 
do 
   mv $i/sample $i/temp
done

end_time=`date +%s%N`
elapsed_time=`expr $end_time - $start_time`
echo $elapsed_time

printf "mv,$elapsed_time\n" >> $csv_path

# cat

start_time=`date +%s%N`
echo $start_time

for ((i=1;i<=10000;i++)); 
do 
   cat $i/$i.txt
done

end_time=`date +%s%N`
elapsed_time=`expr $end_time - $start_time`
echo $elapsed_time

printf "cat,$elapsed_time\n" >> $csv_path

# rm

start_time=`date +%s%N`
echo $start_time

for ((i=1;i<=10000;i++)); 
do 
   rm $i/*
done

end_time=`date +%s%N`
elapsed_time=`expr $end_time - $start_time`
echo $elapsed_time

printf "rm,$elapsed_time\n" >> $csv_path

# rmdir

start_time=`date +%s%N`
echo $start_time

for ((i=1;i<=10000;i++)); 
do 
   rmdir $i
done

end_time=`date +%s%N`
elapsed_time=`expr $end_time - $start_time`
echo $elapsed_time

printf "rmdir,$elapsed_time\n" >> $csv_path