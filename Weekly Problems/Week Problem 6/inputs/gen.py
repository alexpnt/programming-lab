import random
import io

def gen(n,m):

	f = open("input_unitario"+str(n)+"_"+str(m), 'w')
	f.write(str(n)+" "+str(m)+"\n")

	for i in range(0,m):
		value=random.randint(1,100)
		f.write(str(value)+" ")
		value=random.randint(1,100)
		if(value<70):
			value=1
		else:
			value=random.randint(2,3)
		for j in range(1,value+1):
			value2=random.randint(1,n)
			value2*=random.choice([1,-1])
			f.write(str(value2)+" ")
		f.write("0")
		f.write("\n")
	f.close()

if __name__ == '__main__':
	gen(20,2000)
