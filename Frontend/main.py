import ctypes
import time 
from Project import *
from os import listdir

#time.sleep(6);

class _BackTestingEngine(ctypes.Structure): pass
BackTestingEngine = ctypes.POINTER(_BackTestingEngine) #pointer to ctype.

class _CProject(ctypes.Structure): pass 
BackTestingProject = ctypes.POINTER(_CProject)

interfaceDLL = ctypes.cdll.LoadLibrary(r"C:\Users\Andrew van Rensburg\repos\BacktestingEngine\TradingInteface\Debug\INTERFACE.dll")
#"C:\Users\Andrew van Rensburg\repos\BacktestingEngine\Engine\Debug\ENGINE.dll"
# The DLL returns type CEngine (from C++ code). The below line will allow the type returned to be BackTestingEngine "C:\\Users\\Andrew van Rensburg\\repos\\BacktestingEngine\\TradingInteface\\Debug\\INTERFACE.dll
# Keep in mind that ctypes assumes the default return type is int. 
interfaceDLL.createInterface.restype = BackTestingEngine

interfaceDLL.addHistoricalData.argtypes = [BackTestingEngine, ctypes.c_char_p]
interfaceDLL.addHistoricalData.restype = ctypes.c_uint

class Interface(object):

    _loadedDLL = interfaceDLL
    _handle = None

    def __init__(self):
        self._handle = interfaceDLL.createInterface()

    def addHistoricalData(self, path):
        interfaceDLL.addHistoricalData(self._handle, path)


interface = Interface()
interface.addHistoricalData(b"C:/Users/Andrew van Rensburg/repos/BacktestingEngine/Frontend/aapl.txt")