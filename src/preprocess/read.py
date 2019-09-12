import pandas as pd
import os


class Read:
    """
    A class used to read in data 

    Methods
    -------
    read_csv(local_path=None)
        Reads in our local csv file as a pandas dataframe
    
    TODO: You will have to write function that can read from the cloud or
          from an arduino serial output
    """

    def read_local_csv(self, local_path):
        # Reads in our local csv file as a pandas dataframe
        data = pd.read_csv(local_path)
        return data



    

