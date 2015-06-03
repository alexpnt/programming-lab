import random
import io
def gen(n):

	f = open("input"+str(n), 'w')
	f.write(str(n)+"\n")
	for i in range(1,n):
		value=random.randint(1,100)
		f.write(str(value)+" ")
	
	value=random.randint(1,100)
	f.write(str(value)+"\n")
	f.close()
if __name__ == '__main__':

	gen(5000)
	
