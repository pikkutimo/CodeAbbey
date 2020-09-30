[Sweet Harvest](https://www.codeabbey.com/index/task_view/sweet-harvest)

The Rabbit is going to cross the river. There is a straight chain of tiny isles across the flow and the animal should jump from one to another because it surely could not swim.

At each of the isles there are some candies. When the Rabbit arrives to the new isle, it collects all the candies here.

However, the Rabbit could not jump directly to the next isle in the chain - it just is too strong to make short jumps. So, instead, it can jump over the one or two isles (i.e. from the 1st for example to 3rd or 4th but not to 2nd or 5th and further). Also the Rabbit could not jump back.

You can see the sample of the Rabbit's path on the drawing above. It visits 1st, 3rd, 6th and 8th isles and collects:

11 + 3 + 13 + 7 = 34
the amount of 34 candies. Obviously he could do better if the path is chosen more wisely.

Your task is to choose the best path for Rabbit over the given chain of isles - i.e. to maximize the amount of the candies collected. Note that Rabbit starts from 1st isle and finishes either on the Nth or (N-1)th where N is the total number of isles (because from these two it will necessarily jump immediately to the other bank).

Input data will contain the number of test-cases in the first line.
Next lines contain one test-case each - i.e. one chain of isles, described by the array of numbers - amounts of candies at each isle.
Answer should contain the maximum possible amount of candies gathered for each test case.