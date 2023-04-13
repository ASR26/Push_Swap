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
- If they are not sorted we will have to do it ourselves, so first at all we will save the size of the list in `v->len` using `list_size` function.
- Now we will free our list since we have the numbers in the stack and we will not need it anymore using our `free_list` function.
- If our stack is smaller than 11 we will use our `sort_short` function which has an algorithm for small stacks. If it is bigger we will use our `sort_big` function which has a better algorithm for big stacks, [quicksort](https://es.wikipedia.org/wiki/Quicksort).
- In case we have has to split our argument we will free it after sorting. Lastly we will close our file descriptor.

## Short algorithm

- We will create a temporal `t_list` variable which we will use later.
- If len is 2 (there are 2 numbers) and they are not in order we will use `pick_case` function telling it to use `sa` movement to sort them.
- If len is 3 (there are 3 numbers) and they are not in order we will use `case_with_3` function so it will do the best list of movements to sort them. They must be 2 max.
- If len is greater than 3 (there are more than 3 numbers) and they are not in order we will use `case_with_10`.
- `case_with_10` will move the lowest number to stack B until there are only 3 in stack A, so we will end with these numbers in descendent order in stack B. To do this with the lowest ammount of movements we will find the lowest value, then we will check if it is faster to move it to the top using `ra` or `rra` and will move it, then push it to B and so on.
- Once we have only 3 numbers in A we will use `case_with_3` to sort them and bring back stack B numbers so we have a full sorted stack
-  Since we are using stack B we free stacks A and B because we have the orders already.
## Big algorithm
