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
        Receiver_object.incomingStreamLines = ['1,1','2,2','3,3','4,4','5,5']
        Receiver_object.process_stream_data()
        Receiver_object.process_infer_data()
        self.assertEqual(Receiver_object.max_temp,5)
        self.assertEqual(Receiver_object.max_pr,5)
        self.assertEqual(Receiver_object.min_temp,1)
        self.assertEqual(Receiver_object.min_pr,1)
        self.assertEqual(Receiver_object.mov_avg_temp,['-', '-', '-', '-', 3.0])
        self.assertEqual(Receiver_object.mov_avg_pr,['-', '-', '-', '-', 3.0])
        
        
    #Tests for receiver
    def test_send_data_to_console(self):
        Receiver_object = Receiver()
        self.assertEqual(Receiver_object.print_data_to_console("All is well!"), "All is well!")
unittest.main()
