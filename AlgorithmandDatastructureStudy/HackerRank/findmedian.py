#find median
#https://www.hackerrank.com/challenges/find-median
import sys
def swap(a,b):
	t = a
	a = b
	b = t
	return a,b

def partition(arr,stidx,endidx):
	pivot = endidx
	indx = 0
	mapidx =0

	while(indx < pivot):
		print len(arr)
		print "startindex and endidx  and pivot and idx,mapidx are ",stidx,endidx,pivot,indx,mapidx
		if(arr[indx] > arr[pivot]):
				arr[indx],arr[mapidx]=swap(arr[indx],arr[mapidx])
				mapidx += 1
		indx+=1
	arr[mapidx],arr[pivot]=swap(arr[mapidx],arr[pivot])
	return mapidx

def QSelect(arr,stidx,endidx,med):
	if(stidx>=endidx or stidx<0 or endidx<0):
		return -1
	pivot = partition(arr,stidx,endidx)
	print arr
	if(pivot != med):

		ret = QSelect(arr,stidx,pivot-1,med)
		if(ret == -1):
			ret = QSelect(arr,pivot+1,endidx.med)
		if(ret != -1):
			return ret;
	else:
		return pivot

	return -1




num = int(raw_input())

arr=[]
numbersInput=raw_input()
for x in numbersInput.split():
    arr.append(int(x))

print num
print "length of array =",len(arr)
print arr
med = QSelect(arr,0,num-1,int(num/2))
print med
