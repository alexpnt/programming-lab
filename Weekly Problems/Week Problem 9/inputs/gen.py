import random
import io
def gen(n):

	f = open("input_"+str(n), 'w')
	for i in range(1,n+1):
		for j in range(1,5):
			value=random.randint(0,n-1)
			f.write(str(value))
			f.write(" ")
		f.write("\n")
	f.close()

if __name__ == '__main__':
		gen(1000)
	
