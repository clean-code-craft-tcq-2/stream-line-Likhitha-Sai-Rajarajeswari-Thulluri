import unittest
import random
from receiver import *

class tdd_sender_test(unittest.TestCase):
    #Tests for Compute Statistics
    def test_Compute_Statistics_minimumvalue(self):
        obj_Compute_Statistics = Compute_Statistics()
        self.assertEqual(obj_Compute_Statistics.getMinimumValue([1,2,3,4,-5,0]),-5)

    def test_Compute_Statistics_maximumvalue(self):
        obj_Compute_Statistics = Compute_Statistics()
        self.assertEqual(obj_Compute_Statistics.getMaximumValue([1,2,3,4,-5,0]),4)

    def test_Compute_Statistics_movingaverage(self):
        obj_Compute_Statistics = Compute_Statistics()
        self.assertEqual(obj_Compute_Statistics.get_SimpleMovingAverage([1,2,3,4,-5,0],3),['-', '-', 2.0, 3.0, 0.67, -0.33])
    
    #Tests for reading data and processing result
    def test_read_data_process_result(self):
        Receiver_object = Receiver()
        for index in range (10):
            sys.stdout.write(str(random.randrange(0,10,3))+','+str(random.randrange(0,10,3)))
        Receiver_object.getRawValuesFromConsole()
        
        
    #Tests for receiver
    def test_send_data_to_console(self):
        Receiver_object = Receiver()
        self.assertEqual(Receiver_object.print_data_to_console("All is well!"), "All is well!")
unittest.main()
