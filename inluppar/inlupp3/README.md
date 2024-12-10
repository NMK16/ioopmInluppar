How to build the program:
Go to "inlupp3" directory (already here), open a terminal and type:
> make all

Then to run the program after, type this in the terminal:
> make run

Program should now run.

When you run the program you will be presented with the text
"Enter expression to evaluate:" where you just type whatever
expression you would want the calculator to evaluate.
E.g. 2+2, 2=x, 2*x e.t.c.

After typing an expression you will be either prompted with a result
or with an error stating what went wrong.

Some variables cannot be assigned a value to since they are named constants.

This program has the following named constants:
- pi
- e
- Answer
- L

On top of that the program supports a few basic commands:
- Quit
- Vars
- Clear

Quit: Ends the program and prompts you with some statistics acquired from the run.

Vars: Prints out all currently assigned variables e.g. [x=2]

Clear: Clears and resets all assigned variables (except for the named constants).

In our "Exception" errors we have decided to use "RuntimeException"
instead of "Exception" as we found it to be more useful and convenient
as opposed to having to change the program when using "Exception".