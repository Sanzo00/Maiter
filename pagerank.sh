ALGORITHM=Pagerank
WORKERS=2
GRAPH=input/
RESULT=result/
NODES=1000000
SNAPSHOT=10
TERMTHRESH=0.00001
BUFMSG=500
PORTION=1

./example-dsm --runner=$ALGORITHM --workers=$WORKERS --graph_dir=$GRAPH --result_dir=$RESULT --num_nodes=$NODES --snapshot_interval=$SNAPSHOT --portion=$PORTION --termcheck_threshold=$TERMTHRESH --bufmsg=$BUFMSG --v=1 > log
