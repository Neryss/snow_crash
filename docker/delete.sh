OUTPUT=$( docker container ps -aq)
if [ "$OUTPUT" != "" ]
then
	 docker stop ${OUTPUT}
fi

 docker system prune -a -f

OUTPUT=$( docker images -aq)
if [ "$OUTPUT" != "" ]
then
	 docker rmi --force ${OUTPUT}
fi

OP=$( docker volume ls -q)
if [ "$OP" != "" ]
then
	 docker volume rm ${OP}
fi

docker builder prune
