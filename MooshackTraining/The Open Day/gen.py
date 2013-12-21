import random
import io
def gen(n,m):

	f = open("input"+str(n)+"_"+str(m), 'w')
	f.write(str(n)+" "+str(m)+"\n")
	for i in range(0,m):
		value=random.randint(0,n-1)
		value2=random.randint(0,n-1)
		if value==value2 and value<30:
			value2+=1
		elif value==value2 and value>0:
			value2-=1

		f.write(str(value)+" "+str(value2)+"\n")
	f.close()

if __name__ == '__main__':

	
	gen(30,435)
	
