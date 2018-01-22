#!/bin/bash


for i in `seq 1 1000`
do
	curl -X GET http://admin:admin@10.244.0.3:5984/_all_dbs
done

