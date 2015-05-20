#find median
#https://www.hackerrank.com/challenges/find-median


def QSelect(arr,stidx,endidx,med):
	if(stidx>=endidx):
		return -1
	pivot = partition(arr,stidx,endidx)
	if(pivot != med)
	{
		ret = QSelect(arr,stidx,pivot-1,med)
		if(ret == -1):
			ret = QSelect(arr,pivot+1,endidx.med)
		if(ret != -1):
			return ret;
	}
	else
	{
		return pivot
	}
	return -1




num = int(raw_input())
arr=map(int,raw_input().split(" "))
med = QSelect(arr,0,num-1,num/2)
