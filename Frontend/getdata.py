import os
import pandas_datareader as web 
import datetime

f = web.DataReader("AAPL", "av-daily", start=datetime.datetime(2018,12,1), end=datetime.datetime(2019,12,1), api_key=os.getenv("ALPHAVANTAGE_API_KEY"))
#f = web.av.forex.AVForexReader(symbols="EUR/USD")

f.to_csv(r"C:\Users\Andrew van Rensburg\repos\BacktestingEngine\Frontend\aapl4.txt", sep=',', date_format="%Y-%m-%d")
print (f.info())






