import random
import io
def gen(n,m):

	f = open("input"+str(m), 'w')
	f.write(str(n)+"\n")
	f.write(str(m)+"\n")
	for i in range(1,m):
		value=random.randint(1,m)
		f.write(str(value)+" ")

		value=random.randint(1,m)
		f.write(str(value)+"\n")
	
	value=random.randint(1,m)
	f.write(str(value)+" ")

	value=random.randint(1,m)
	f.write(str(value)+"\n")
	f.close()
if __name__ == '__main__':

	gen(500,500)
	
