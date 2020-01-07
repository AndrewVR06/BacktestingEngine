import ctypes
import time 
from Project import *
from os import listdir

#time.sleep(6);

class _BackTestingEngine(ctypes.Structure): pass
BackTestingEngine = ctypes.POINTER(_BackTestingEngine) #pointer to ctype.

interfaceDLL = ctypes.cdll.LoadLibrary(r"C:\Users\Andrew van Rensburg\repos\BacktestingEngine\Debug\Interface.dll")

#time.sleep(8);
#"C:\Users\Andrew van Rensburg\repos\BacktestingEngine\Engine\Debug\ENGINE.dll"
# The DLL returns type CEngine (from C++ code). The below line will allow the type returned to be BackTestingEngine "C:\\Users\\Andrew van Rensburg\\repos\\BacktestingEngine\\TradingInteface\\Debug\\INTERFACE.dll
# Keep in mind that ctypes assumes the default return type is int. 

interfaceDLL.CreateInterface.restype = ctypes.c_void_p
interfaceDLL.CreateInterface.restype = BackTestingEngine

interfaceDLL.AddHistoricalData.argtypes = [BackTestingEngine, ctypes.c_char_p]
interfaceDLL.AddHistoricalData.restype = ctypes.c_void_p

interfaceDLL.GetStrategyList.argtypes = [BackTestingEngine]
interfaceDLL.GetStrategyList.restype =  ctypes.POINTER(ctypes.c_char_p)

interfaceDLL.BeginSimulation.argtypes = [BackTestingEngine, ctypes.c_char_p]
interfaceDLL.BeginSimulation.restype = ctypes.c_void_p

class Interface(object):

    _loadedDLL = interfaceDLL
    _handle = None

    def __init__(self):
        self._handle = interfaceDLL.CreateInterface()

    def addHistoricalData(self, path):
        interfaceDLL.AddHistoricalData(self._handle, path)

    def GetStrategyList(self):
        return interfaceDLL.GetStrategyList(self._handle)

    def BeginSimulation(self, name):
        interfaceDLL.BeginSimulation(self._handle, name)

interface = Interface()
#interface.addHistoricalData(b"C:/Users/Andrew van Rensburg/repos/BacktestingEngine/Frontend/aapl.txt")

stringlist = interface.GetStrategyList()

for i in stringlist:
    if ( i == b"end"):
        break
    print (i.decode("utf-8"))

interface.BeginSimulation(b"SMA5_over_SMA15")