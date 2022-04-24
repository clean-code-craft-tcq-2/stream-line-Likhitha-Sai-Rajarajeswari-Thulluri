import sys

class Compute_Statistics:

    def getMinimumValue(self, list_reading_values):
        return min(list_reading_values)

    def getMaximumValue(self, list_reading_values):
        return max(list_reading_values)

    def get_SimpleMovingAverage(self, list_reading_values, number_of_points):
        list_simpleMovingAverage = []
        #Add '-' for starting where we cannot compute moving average
        list_simpleMovingAverage.extend((number_of_points-1)*'-')
        for index in range(number_of_points-1,len(list_reading_values)):
            list_simpleMovingAverage.append(round(sum(list(map(float,list_reading_values[index-number_of_points+1:index+1])))/number_of_points, 2))
        return list_simpleMovingAverage

class Receiver:
    def __init__(self):
        self.temperatureReadValues = []
        self.PressureReadValues = []
    
    def getRawValuesFromConsole(self):
        self.incomingStreamLines = sys.stdin.readlines()

    def process_stream_data(self):
        for streamValue in self.incomingStreamLines:
            streamValue = streamValue.strip()
            if streamValue == '\n':
                continue
            self.temperatureReadValues.append(float(streamValue.split(',')[0]))
            self.PressureReadValues.append(float(streamValue.split(',')[1]))
        
    def print_data_to_console(self,data_to_write):
        print(data_to_write)
        return data_to_write

    def process_infer_data(self):
        obj_Compute_Statistics = Compute_Statistics()
        self.max_temp = obj_Compute_Statistics.getMaximumValue(self.temperatureReadValues)
        self.max_pr = obj_Compute_Statistics.getMaximumValue(self.PressureReadValues)
        self.min_temp = obj_Compute_Statistics.getMinimumValue(self.temperatureReadValues)
        self.min_pr = obj_Compute_Statistics.getMinimumValue(self.PressureReadValues)
        self.mov_avg_temp = obj_Compute_Statistics.get_SimpleMovingAverage(self.temperatureReadValues, 5)
        self.mov_avg_pr = obj_Compute_Statistics.get_SimpleMovingAverage(self.PressureReadValues, 5)
        self.print_data_to_console(f"The maximum temperature value is {self.max_temp}")
        self.print_data_to_console(f"The maximum pressure value is {self.max_pr}")

        self.print_data_to_console(f"The minimum temperature value is {self.min_temp}")
        self.print_data_to_console(f"The minimum pressure value is {self.min_pr}")

        self.print_data_to_console(f"The 5 point moving average for temperature values is :{self.mov_avg_temp}\n")
        self.print_data_to_console(f"The 5 point moving average for pressure values is :{self.mov_avg_pr}\n")
            
    


    
    
    
