# Data Processing and Storage Assignment
## How to run the code:
Clone the code.
   
` git clone https://github.com/evaeia/DataProcessingAndStorage.git `
   
Change directories into the `DataProcessingAndStorage` directory.

Type `make` and then `./main` to run the code.

The results of the commands in the assignment page example will be run and their outputs will be displayed on the console.

To modify and use other commands, go to `main.cpp`.
   
The in-memory key-value database supports the following functions:
- begin_transaction()
- put(key, value)
- get(key)
- commit()
- rollback()

## How the assignment could be modified:
To make this an "official" assignment, the instructions for the assignment should be modified to include a menu. Instead of just implementing the functions
and calling them from main.cpp, a UI should be created in the console with a menu to use the database. For example, it should prompt the user in the console
to type a command like "get", and then prompt for the key. Then, the output should be printed to the console and the user should be asked again which command
they would like to input.
