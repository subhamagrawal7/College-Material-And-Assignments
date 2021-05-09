read -a currentRead <<< `top -n1 | grep "Cpu(s)"`
userProcess=${currentRead[1]}
systemProcess=${currentRead[3]}
tUsage=`echo $userProcess + $systemProcess | bc`
echo "TotalCPU_Usage: $tUsage%"

if [ 1 -eq "$(echo "70 < ${tUsage}" | bc)" ]
then
  echo "Overloaded"
elif [ 1 -eq "$(echo "30 < ${tUsage}" | bc)" ]
then
  echo "Moderately-lighted"
else
 echo "Lightly-loaded"
fi
