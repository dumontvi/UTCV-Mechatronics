from preprocess.read import Read
import pandas as pd
import os

def main():
  data_reader = Read()
  data = data_reader.read_local_csv("src/datasets/housing_prices/train.csv")
   
if __name__== "__main__":
  main()