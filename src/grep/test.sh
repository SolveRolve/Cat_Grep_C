#!/bin/bash
COUNTER_SUCCESS=0
COUNTER_FAIL=0
DIFF_RES=""
TEST_FILE="some.txt"
echo "you bags or miss " > log.txt
echo " " >> log.txt
echo "__________________________" >> log.txt
echo "one flags -e -i -v -c -l -n -h -s -o " >> log.txt
echo "__________________________" >> log.txt
echo " " >> log.txt

for var in -e -i -v -c -l -n -h -s -o #-E -T --number-nonblank --number --squeeze-blank
do
          TEST1="$var 1 $TEST_FILE"
          
          ./s21_grep $TEST1 > s21_grep.txt
          grep $TEST1 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
            echo "success->$COUNTER_SUCCESS $TEST1"
              (( COUNTER_SUCCESS++ ))
              
            else
              echo "grep $TEST1 " >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
done 
echo " " >> log.txt
echo "__________________________" >> log.txt
echo "one flags with two files" >> log.txt
echo "__________________________" >> log.txt
echo " " >> log.txt

for var in -e -i -v -c -l -n -h -s -o #-E -T --number-nonblank --number --squeeze-blank
do
          TEST1="$var I $TEST_FILE $TEST_FILE"
          
          ./s21_grep $TEST1 > s21_grep.txt
          grep $TEST1 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
            echo "success->$COUNTER_SUCCESS $TEST1"
              (( COUNTER_SUCCESS++ ))
              
            else
              echo "$TEST1" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
done
echo " " >> log.txt
echo "__________________________" >> log.txt
echo "two flags with one file" >> log.txt
echo "__________________________" >> log.txt
echo " " >> log.txt


for var in  e i v c l n h s o #-E -T --number-nonblank --number --squeeze-blank
do
  for var2 in  e i v c l n h s o #-E -T --number-nonblank --number --squeeze-blank
  do
        if [ $var != $var2 ]
        then
          TEST1="-$var$var2 qwe $TEST_FILE"
          
          ./s21_grep $TEST1 > s21_grep.txt
          grep $TEST1 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
              echo "success->$COUNTER_SUCCESS $TEST1"
              (( COUNTER_SUCCESS++ ))
            else
              echo "$TEST1" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
        fi
  done
done
for var in  e i v c l n h s o #-E -T --number-nonblank --number --squeeze-blank
do
  for var2 in  f #-E -T --number-nonblank --number --squeeze-blank
  do
        if [ $var != $var2 ]
        then
          TEST1="-$var$var2 t.txt $TEST_FILE"
          
          ./s21_grep $TEST1 > s21_grep.txt
          grep $TEST1 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
              echo "success->$COUNTER_SUCCESS $TEST1"
              (( COUNTER_SUCCESS++ ))
            else
              echo "$TEST1" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
        fi
  done
done
echo " " >> log.txt
echo "__________________________" >> log.txt
echo "two flags with two files" >> log.txt
echo "__________________________" >> log.txt
echo " " >> log.txt

for var in  e i v c l n h s o #-E -T --number-nonblank --number --squeeze-blank
do
  for var2 in  e i v c l n h s o #-E -T --number-nonblank --number --squeeze-blank
  do
        if [ $var != $var2 ]
        then
          TEST1="-$var$var2 qwe $TEST_FILE $TEST_FILE"
          
          ./s21_grep $TEST1 > s21_grep.txt
          grep $TEST1 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
              echo "success->$COUNTER_SUCCESS $TEST1 done"
              (( COUNTER_SUCCESS++ ))
            else
              echo "$TEST1" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
        fi
  done
done

echo " " >> log.txt
echo "__________________________" >> log.txt
echo "three flags with " >> log.txt
echo "__________________________" >> log.txt
echo " " >> log.txt

for var in i v c l n h s o
do
  for var2 in  i v c l n h s o
  do
    for var3 in i v c l n h s o 
    do
        if [ $var2 != $var ]
        then
          
          TEST1="-$var$var2$var3 qwe $TEST_FILE"
          ./s21_grep $TEST1 > s21_grep.txt
          grep $TEST1 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
              echo "success->$COUNTER_SUCCESS $TEST1 Done"
              (( COUNTER_SUCCESS++ ))
            else
              echo "grep $TEST1" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
        fi
    done
  done
done
echo " " >> log.txt
echo "__________________________" >> log.txt
echo "four flags with one file" >> log.txt
echo "__________________________" >> log.txt
echo " " >> log.txt
for var in e i v c n h s o
do
  for var2 in  e i v c l n h s o
  do
    for var3 in   i v c l n h s o
    do
      for var4 in e i v c l n h s o
      do
         if [ $var3 != $var4 ]
          then
            TEST1="-$var$var2$var3$var4 qwe $TEST_FILE"
            
            ./s21_grep $TEST1 > s21_grep.txt
            grep $TEST1 > grep.txt
            DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
            if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
              then
              echo "success->$COUNTER_SUCCESS  $TEST1 Done"
                (( COUNTER_SUCCESS++ ))
              else
                echo "$TEST1" >> log.txt
                (( COUNTER_FAIL++ ))
            fi
            rm s21_grep.txt grep.txt
          fi
      done
    done
  done
done
for var in e i v c n h s o
do
  for var2 in  e i v c l n h s o
  do
    for var3 in  i v c l n h s o
    do
      for var4 in f
      do
         if [ $var2 != $var2 ]
          then
            TEST1="-$var$var2$var3$var4 qwe $TEST_FILE"
            
            ./s21_grep $TEST1 > s21_grep.txt
            grep $TEST1 > grep.txt
            DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
            if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
              then
              echo "success->$COUNTER_SUCCESS  $TEST1 Done"
                (( COUNTER_SUCCESS++ ))
              else
                echo "$TEST1" >> log.txt
                (( COUNTER_FAIL++ ))
            fi
            rm s21_grep.txt grep.txt
          fi
      done
    done
  done
done
clear
echo "SUCCESS: $COUNTER_SUCCESS"
echo "FAIL: $COUNTER_FAIL look you mistakes in log.txt "
