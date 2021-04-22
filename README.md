# ForexArbitrage (CSE 2353 Final Project)
This project serves as a proof of concept for an automated Forex Arbitrage machine.
The project takes a command line input of a csv files which represent a currency matrix and following a prompt to the user for a starting account balance, outputs a series of trades which result in an ending account balance and the profit made.
The program utilizes recursive backtracking to identify the chain of transactions which results in the highest return for each currency matrix and proceeds to simulate the execution of each of those matrices once.

### Setup
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
```

Alternativly, you can use the g++ compiler to compile the program.
```
g++ -o ForexArbitrage main.cpp Runner.cpp Currency.cpp DocumentParser.cpp Pathfinder.cpp
```

Finally to execute the program you will need to execute the executable with a command line argument for a properly formatted csv file. An example of this is given below. (Please note that for users of the Linux operating system an absolute path to the file is needed).
```
./ForexArbitrage excelFile3.csv
```
After entering these commands into the terminal, you will be prompted to enter a value to invest. Enter an integer quantity. 

### More Information:

https://en.wikipedia.org/wiki/Triangular_arbitrage

https://www.investopedia.com/terms/forex/f/forex-arbritrage.asp

