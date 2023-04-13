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

## Workflow

- Our program will start at main function, which will receive the arguments. There we will create a `t_var` variable which will hold all the values needed for the program. If we do not receive any argument we exit with an error code (1). If we receive at least one argument the program start. We will initialize our variable using `ft_init_var` function and then we will send it to the `push_swap` function with our argc and argv. After `push_swap` function has finished we will free our variable, set it to NULL and end the program.
- `ft_init_var` will allocate the necessary memory for the variable to hold every value needed and will set them all as default, with values 0 and NULL.
- `push_swap` is the function where everything will happen, first we will save the values taken as arguments in `v->split` using our `fill_args` function to parse them.
- `fill_args` will check if there is 1 or more arguments given, in case there is 1 the format is `./push_swap "1 3 5 2 4"` so it will use our function `ft_split` to parse these numbers. In case we have more than one it means the format is `./push_swap 1 3 5 2 4` so we will take `argv[1]` direction, this way we will have `char **argv` but skipping the executable name which we do not need.
- Once we have our numbers parsed we will check if they are duplicated and if all of them are numbers, using our functions `check_dup` and `check_digits` respectively.
- At this point, if the program continues working it means our arguments are correct so we will put them into `v->a` using our function `fill_list`.
- `fill_list` will allocate memory for every number and will save them into `v->a`.
- Now, we have our stack A filled with numbers, so we will check if they are sorted with `check_sort` function. In case they are we will exit with success code (0).
