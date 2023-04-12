# Push_Swap

Push_Swap is a proyect whose objective is to sort a stack 'A' of numbers using only some kind of instructions and an auxiliar stack 'B' with the least number of movements. For this we will use some sorting algorithms (explained later).

## Movements

- **sa** - swap the two first elements in stack A.
- **sb** - swap the two first elements in stack B.
- **ss** - swap the two first elements in both stacks.
- **pa** - take the first element in stack B and put it on top of stack A. Does nothing if B is empty.
- **pb** - take the first element in stack A and put it on top of stack B. Does nothing if A is empty.
- **ra** - move every element in A one position up. The first element becomes the last one.
- **rb** - move every element in B one position up. The first element becomes the last one.
- **rr** - move every element in both stacks one position up. The first element becomes the last one.
- **rra** - move every element in A one position down. The last element becomes the first one.
- **rrb** - move every element in B one position down. The last element becomes the first one.
- **rrr** - move every element in both stacks one position down. The last element becomes the first one.

## Rules

- We cannot use global variables.
- We must not have any memory leaks.
- We can have only 2 stacks.
- At the beginning stack A will have positive or negative numbers, not duplicated.
- At the beginning stack B will be empty.
- At the end stack A must have numbers in ascendent order.
- At the end stack B will be empty.
- We can only use the movements explained before.

## How it works

- Our program will receive a list of int numbers. The first argument must be on top of the stack.
- The program must show the shorter list of movements which sort stack A, where the lowest number is on top.
- The movements will be separated by `\n`.
- The goal is to sort the stack using the lowest number of movements.
- The program must not show a too long list or an incorrect list of movements.
- If there are not parameters specified the program must not show anything and end.
- In case of error it must show `Error\n` in standar error output. Some errors are: not int numbers, arguments greater than an int or duplicated numbers.
