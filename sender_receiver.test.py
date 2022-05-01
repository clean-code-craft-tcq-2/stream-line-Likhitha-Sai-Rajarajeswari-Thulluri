import random
import sys

for index in range (50):
    sys.stdout.write(str(random.randrange(0,10,3))+','+str(random.randrange(0,10,3))+'\n')
