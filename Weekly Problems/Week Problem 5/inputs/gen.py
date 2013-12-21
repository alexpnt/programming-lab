import random
import io
def gen(n,j):

	f = open("teste"+str(j), 'w')
	f.write(str(n)+"\n")
	for i in range(1,n+1):
		value=random.randint(1,100)
		f.write(str(value))
		f.write(" ")
		value2=random.randint(1,100)
		if(value2<=value):
			value2=value+1
		f.write(str(value2)+"\n")
	f.close()

if __name__ == '__main__':

	for i in range(1,6):
		gen(10,i)
	for i in range(6,11):
		gen(100,i)
	for i in range(11,16):
		gen(1000,i)
	for i in range(16,21):
		gen(10000,i)
	for i in range(21,26):
		gen(100000,i)
	for i in range(26,31):
		gen(150000,i)
