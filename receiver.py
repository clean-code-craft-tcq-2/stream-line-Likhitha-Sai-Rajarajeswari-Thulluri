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
            list_simpleMovingAverage.append(round(sum(list_reading_values[index-number_of_points+1:index+1])/number_of_points, 2))
        return list_simpleMovingAverage

class Receiver: 
    def getRawValuesFromConsole(self):
        self.temperatureReadValues = []
        self.PressureReadValues = []
        incomingStreamLines = sys.stdin.readlines()
        for streamValue in incomingStreamLines:
            streamValue = streamValue.strip()
            if streamValue == '\n':
                continue
            self.temperatureReadValues.append(streamValue.split(',')[0])
            self.PressureReadValues.append(streamValue.split(',')[1])
        #print('self.temperatureReadValues',self.temperatureReadValues)
        #print('self.PressureReadValues',self.PressureReadValues)
        
    def print_data_to_console(self,data_to_write):
        print(data_to_write)
        return data_to_write

    def process_infer_data(self):
        obj_Compute_Statistics = Compute_Statistics()
        self.print_data_to_console("The maximum temperature value is ",obj_Compute_Statistics.getMaximumValue(self.temperatureReadValues))
        self.print_data_to_console("The maximum pressure value is ",obj_Compute_Statistics.getMaximumValue(self.PressureReadValues))

        self.print_data_to_console("The minimum temperature value is ",obj_Compute_Statistics.getMinimumValue(self.temperatureReadValues))
        self.print_data_to_console("The minimum pressure value is ",obj_Compute_Statistics.getMinimumValue(self.PressureReadValues))

        self.print_data_to_console("The 5 point moving average for temperature values is :\n",obj_Compute_Statistics.get_SimpleMovingAverage(self.temperatureReadValues))
        self.print_data_to_console("The 5 point moving average for pressure values is :\n",obj_Compute_Statistics.get_SimpleMovingAverage(self.PressureReadValues))
            
    


    
    
    