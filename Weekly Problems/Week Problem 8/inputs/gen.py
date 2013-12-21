import random
import io
def gen(n,m):

	f = open("input_"+str(n)+"_"+str(m), 'w')
	f.write(str(n)+" "+str(m)+"\n")
	for i in range(1,m+1):
		value=random.randint(0,n-1)
		f.write(str(value))
		f.write(" ")
		value2=random.randint(0,n-1)
		if(value2==value):
			if(value2+1>=n):
				value2=value-1
			else:
				value2=value+1
		f.write(str(value2)+"\n")
	f.close()

if __name__ == '__main__':
		gen(1000,91000)
	
