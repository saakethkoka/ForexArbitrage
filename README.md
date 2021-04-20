# ForexArbitrage (CSE 2353 Final Project)
This project serves as a proof of concept for an automated Forex Arbitrage machine.
The project takes a command line input of a csv files which represent a currency matrix and following a prompt to the user for a starting account balance, outputs a series of trades which result in an ending account balance and the profit made.
The program utilizes recursive backtracking to identify the chain of transactions which results in the highest return for each currency matrix and proceeds to simulate the execution of each of those matrices once.

###Setup
As a precondition, ensure that your system has C++ and is able to execute CLion files. To check this type:
```
cmake --version
```
Next, you need to download the repository from Github. This can be done by entering:
```
git clone https://github.com/saakethkoka/ForexArbitrage.git
```
Following this, you will need to run the program. 
```
cd ForexArbitrage
mkdir executable
cd executable
cmake ..
make
./ForexArbitrage excelFile3.csv
```

###More Information
https://en.wikipedia.org/wiki/Triangular_arbitrage
https://www.investopedia.com/terms/forex/f/forex-arbritrage.asp

