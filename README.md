# push_swap-42-
## My hive (42) school project for push_swap

In this project we got tasked to create a sorting algorithm. It needed to sort any size of valid integers in ascending order.

For the algorithm I didn't use any conventional sorting method, instead I followed this logic pattern: https://medium.com/@ayogun/push-swap-c1f5d2d41e97. Much thanks to the guy who wrote it. This logic went through every option that we would take and calculated the needed instructions. Oh, and there was limited amount of instructions allowd to pass this project. What are instructions? Imagine two stacks. When the program starts, stack A has all the values that we user defined as arguments to the program. When we start sorting this stack, we need to push values to another stack; stack B. We can also rotate stack A or stack B, and bunch of other operations/instructions. 

My implementation passed this project with full scores, although, noted by my peers, it isn't very portable. It is just optimized very well to this particular task of number sorting.

Bonus included a checker program for checking if the numbers are actually sorted after reading the instructions printed by push_swap from the standard output.

The subject of the project is included as always.

Some scores using a tester found online:

<img width="546" alt="Screen Shot 2023-05-13 at 8 14 38 PM" src="https://github.com/kenlies/push_swap-42-/assets/97135325/feb6a379-3553-4667-b211-6f2b0050d1cc">

<img width="546" alt="Screen Shot 2023-05-13 at 8 15 14 PM" src="https://github.com/kenlies/push_swap-42-/assets/97135325/5142b6a9-17ad-4121-844e-0d5ecdb2e0ab">

<img width="637" alt="Screen Shot 2023-05-13 at 7 10 01 PM" src="https://github.com/kenlies/push_swap-42-/assets/97135325/af6b950a-ee7c-4e96-8ac7-dbe089c2c87c">
