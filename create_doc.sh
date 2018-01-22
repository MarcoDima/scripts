#!/bin/bash

INCREM=100
END=$(($INCREM+500))

for i in `seq $INCREM $END`
do
	curl -X PUT http://admin:admin@10.244.0.3:5984/db/$i -d '{"a":"b"}'
done
