# Report for Data Structure Speed Comparison Homework

Make sure to answer every question in this homework. You should not bullet point your answers, but
instead write them as a full report format. This doesn't mean you have to be wordy, as concise is good,
but it does mean you need to use proper grammar, spelling, and be complete. For question that just
ask for a short answer, answer accordingly. Make sure to include references where appropriate.

## Algorithmic Analysis - Big $O$

Complete the Big O table below for the following functions. You may use any resource you like, but
for the SortedVector and SortedList, you should use the Big O for the functions you wrote in the
the homework. Both Single and Double Linked List you can assume head and tail pointers are available. 
Don't forget to use latex math notation (example in the table).

### Big $O$ Table

| -                         | Add/Insert |   Remove   | Search/Find |     Sort     | Add Front |    Add Back     | Remove Front | Remove Back | Get by Index |
| ------------------------- |:----------:|:----------:|:-----------:|:------------:|:---------:|:---------------:|:------------:|:-----------:|:------------:|
| Vector                    |   $O(n)$   |   $O(n)$   |   $O(n)$    | $O(n log n)$ |  $O(n)$   | $O(1)amortized$ |    $O(n)$    |   $O(1)$    |    $O(1)$    |
| Single Linked List        |   $O(1)$   |   $O(n)$   |   $O(n)$    | $O(n log n)$ |  $O(1)$   |     $O(1)$      |    $O(1)$    |   $O(n)$    |    $O(n)$    |
| Double Linked List        |   $O(1)$   |   $O(n)$   |   $O(n)$    | $O(n log n)$ |  $O(1)$   |     $O(1)$      |    $O(1)$    |   $O(1)$    |    $O(n)$    |
| Sorted Vector             |  $O(n) $   |   $O(n)$   | $O(log n)$  |    $O(1)$    |    ---    |       ---       |     ---      |     ---     |     ---      |
| Sorted Single Linked List |   $O(n)$   |   $O(n)$   |   $O(n)$    |    $O(1)$    |    ---    |       ---       |     ---      |     ---     |     ---      |
| Sorted Double Linked List |   $O(n)$   |   $O(n)$   |   $O(n)$    |    $O(1)$    |    ---    |       ---       |     ---      |     ---     |     ---      |
| Binary Search Tree        | $O(log n)$ | $O(log n)$ | $O(log n)$  |    $O(n)$    |    ---    |       ---       |     ---      |     ---     |     ---      |

For Sort, we are asking for the Big $O$ for taking the current data structure and writing it 'sorted' to a file. However, not the file writes. For example, if you have a vector of 1000 elements, and you want to write it to a file, you would need to sort it first. So, the Big $O$ for this would be the Big $O$ for sorting. For BST, you have to convert the tree to a sequential structure, so the cost of doing that.  

### Assumptions with Sort

Since the worst case can change considerably based on what sort you use for sorting (if any), list each algorithm below, and specify the algorithm used in your assumption.  For BST, write which method of traversal you would use to sort it.  

* Vector - merge sort 
* Single Linked List - merge sort
* Double Linked List - merge sort
* Sorted Vector - already sorted
* Sorted Single Linked List - already sorted
* Sorted Double Linked List - already sorted
* Binary Search Tree - in-order traversal

### Worst Case vs. Average Case

There are a few functions whose worse case is very different than the average case. Name at least two of them, and explain why the worse case is so much worse than the average case. 

1. Binary search tree operations. The average case is O(log n) for a balanced tree. 
But the worst case would be an unbalanced tree, as then finding a certain node would be O(n),
as you'd just go down one side.
2. Adding to a vector. Best case is O(n). But in worst case, you'd have to do amortized resizing of the array.
Worst case happens when you've maxed out the capacity of the vector, and need to create a vector of a larger size,
initializing a new vector and copying over all previous values.

## Empirical Analysis - Speed Comparison

For this section, you will need to have run the speed compare program and generated the output into a CSV file.

### Empirical Results Table

Add a link from this document to the CSV file you generated. The CSV file must have at least 15 different N values, but
often can have a lot more depending on what you ran.  

### Analysis

Create *at least three* graphics that each visually explain an aspect of your data related to an operation or data structure. Under each one, explain what the graphic is showing, and what you can conclude from it/what you find interesting about it.

> [!IMPORTANT]
> 
> Make sure you are comparing apples to apples and not apples to oranges when choosing what to put in the same graph. 
> 
> **:x: different data structures *and* different operations**
> 
> - Vector Add Front versus BST Add
> 
> **:white_check_mark: different operations *but* same data structure**
> 
> - BST Add versus Remove, and Search for BST
> 
> **:white_check_mark: different data structures *but* same operation**
> 
> - BST Add versus Add for Sorted Vector, and Sorted Single/Double Linked List
> 
> - Vector Add Front versus Add Front for Single/Double Linked List

> [!TIP]
> 
> To create the graphics you can use a third party program like Microsoft Excel or Google Sheets. (Completely optional if you want extra coding: you can use python libraries such as matplotlib, seaborn, or plotly)
> 
> Make sure you can see the image embedded in the Report.md using [image markdown] when you upload it to github, and get help if it doesn't show! 

#### Graphic 1: Linked List - Add vs Remove

![LinkedList - Add vs Remove]("./graphs/linkedlist_add_remove.png");

> Insert your comments/observations about the graphic here
> This graph shows that removing an element from the back of a linked list
> is O(n), while adding an element to the back of a linked list is O(1).
> While this makes sense logically after you think through it, it is interesting to me 
> as you would expect both to be O(1). The reason that removing from the back of a linked list,
> even if you have access to the tail is O(n), is because, you simply can't just set the tail to null.
> The correct way to approach this problem is to set the 'next' of the node that comes right before the tail to null,
> and then to set the tail to be that node that came before the tail (unless you only have one node in the list).
> I also was surprised to see such spikes for the linked list remove back timings. 

#### Graphic 2: Remove - Sorted Vector, Linked List, & BST

![Remove - Sorted Vector, Linked List, & BST]("./graphs/remove.png");

> Insert your comments/observations about the graphic here
> I was surprised to see the Linked List to perform that much worst than the other two data structures,
> and I was also surprised that the BST performs that much better.
> While finding and removing a value from both a sorted linked list and sorted vector would be O(n),
> the sorted vector performs much better. For the sorted vector, we could find the value with merge sort, 
> which is O(log n), and then we would have to shift everything that came after to the left, which is O(n).
> With the linked list, we would find the value with O(n) time, and then removing would be O(1) time. 
> The reason it performs so much worse, would be rotating pointers takes more time than shifting elements in a vector.
> Also, the free function could make some difference. 
> The BST performs better as it is O(log n) time complexity. I was expecting it to not perform as well as it did though,
> as removing the node would take also O(log n), rather than just finding it. 
> But, I suppose O(log n) is more powerful than I thought.
> This also shows in the graph of Linked List Search, Vector Search, and BST Search, 
> where the vector and the bst significantly outperform the linked list, as they require O(log n) time to search,
> and searching a linked list takes O(n) time. 

#### Graphic 3: Add - Sorted Vector, Linked List, & BST

![Add - Sorted Vector, Linked List, & BST]("./graphs/add.png");

> Insert your comments/observations about the graphic here
> This graph is interesting, as the timings for adding to a sorted vector and linked list are very similar,
> in contrast to removing elements in our previous graph. This is because the vector here is expanding,
> so during certain additions (aka when the elements in our vector have reached its capacity),
> the vector size would need to increase, adding amortized time. 
> The BST, not surprisingly, outperforms both here again with its O(log n) time. 

## Critical Thought

### Data Evaluation

Answer the questions below. Make sure to answer each question fully, and explain your reasoning. Indent your answers immediately below the question, for it to line up with the bullet point.

For example:

```markdown
1. What is the most surprising result from the data? Why is it surprising?
   Answer here
```

1. What is the most surprising result from the data? Why is it surprising?
Though I did not include this in my graphs I've talked about here, 
I found the most surprising and difficult to explain result from the data to be how adding to a sorted list has less growth 
than removing from a sorted list. I think this could be because the free function takes up some time,
but also it could be because removing means finding an element, which might not always be there, 
so often we'd just traverse the whole list linearly, without actually decreasing its size. 

2. What data structure is the fast at adding elements (sorted)? Why do you think that is?
The BST is by far the fastest, as it would take O(log n) time to find where to add the element.
The other two data structures add using O(n) time. The linked list takes up O(n) to find where to add the element.
The sorted vector needs O(log n) time to find where to add the element, and the takes O(n) time to shift elements,
and also occasionally (but rarely) needs to resize the vector, which is also O(n) time.

3. What data structure is the fastest at removing elements (sorted)? Why do you think that is?
The BST is the fastest at removing elements in a sorted data structure, for the same reason
it is fastest at adding elements. O(log n) time is normally more efficient than O(n) time. 
Though your can find the element to remove in the sorted vector with O(log n) time, you would still need to 
shift down the elements that come after it, taking up O(n) time.

4. What data structure is the fastest at searching? Why do you think that is?
The sorted vector is fastest at searching, but BST comes right after it. 
The sorted vector would take up O(log n) time to search for an element. 
For just searching and not adding or removing, no shifting would need to take place.
While the BST also searches with the same time complexity, the vector is faster as the BST requires dealing with 
pointers to nodes, which takes up a bit more time. 

5. What data structure is the fastest for adding elements to the front? Why do you think that is?
The linked list is fastest at adding to the front. This is because it is O(1) time. 
the vector would require shifting all the other elements right, and the very occasional resizing of the array, 
which both take O(n) time. 
It doesn't make sense to add elements to the front of the BST, so this was not included in the data. 

6. What data structure is the fastest for adding elements to the back? Why do you think that is?
The vector is the fastest for adding elements to the back (unless your linked list has a tail). 
This is because it usually takes O(1) time to add to the back of a vector,
and occasionally takes O(n) if the vector needs to be resized. 
So the time complexity for adding elements to the back of a vector is O(1)amortized. 
The time complexity of adding to the back of a linked list depends on whether or not you have access to the tail.
If you don't, you need to traverse the list to reach its tail. If you do, you add a next node to the tail and make the tail
point to that node. This saves a lot of time for adding to the back. 

7. What data structure is the fastest for removing elements from the front? Why do you think that is?
The linked list is the fastest for removing elements from the front. This is because it takes O(1) time.
Removing from the front of the vector takes O(n) time, as you need to shift the rest of the elements down by 1. 
The list does not require that, it only requires updating the head and freeing the previous head node. 

8. What data structure is the fastest for removing elements from the back? Why do you think that is? 
The vector is the fastest for removing elements from the back. This is because removing elements from the back of the vector
is O(1) time, as you already have access to the last element of the vector. 
The single linked list takes O(n) time, even when you have access to its tail. 
This is because you don't just need to free the tail - you also need access to the previous node before the tail,
in order to set its next node to null, and set the tail pointer to that previous node. 
This changes if you're dealing with a double linked list, as you can get access to the node that comes before the tail,
by accessing the tail's previous node. 


### Deeper Thinking

#### Double Linked List vs Single Linked List

1. If you wrote your linked list as a single linked list, removing from the back was expensive. If you wrote it as a double linked list, removing from the back was cheap. Why do you think that is?
To remove from the back of a linked list, you not only need to free the current tail, but, 
if there is not only 1 node in the list (in which case you'd set the head and the tail to NULL), 
you need to update the 'next' pointer of the previous node, and reset the tail to that node that came before the tail.
This mean you need access to the node that points to the tail. In a double linked list, you can find that node by accessing
the 'previous' node of the tail, but in a single linked list, you have to traverse the list to find this node, which takes O(n) time.

2. When running most functions, at least ~30% of the tests were worse case scenarios. Why do you think that is? 
Around 30% of the time, we cannot find the element that we were looking for. 
This contributed to the remove element performing worse than the add element for linked lists, as remove an element requires finding it first,
and since finding an element in a linked list requires traversing linearly (O(n) time), the whole list would get traversed 
for finding elements that don't exist in the data set. 

3. What was done in the code to encourage that? 
In speed_compare_app/tests.h, they define a SAMPLE_SPLIT of .7, which makes 70% of movies that we try to find exist in the data structure.
This means that 30% of the movies aren't put into the data sets.

4. How did this particularly influence the linked list searches?
Linked list searches are of O(n) time, so for elements that are not found, we go through/look at every element in the list. 


#### Test Bias

1. The tests were inherently biased towards the BST to perform better due the setup of the experiment. Explain why this is the case.  (hint: think about the randomization of the data, and the worst case scenario for BST).
Randomizing the data helps the BST be balanced. It is unlikely for the data to be sorted before adding it to a BST, if we are getting these values at random.
This helps the BST search remain O(log n).


2. What would generate the worst case scenery for a BST?
The worst case scenario for searching a BST is if its nodes are already sorted, as it would be unbalanced. This way,
searching the BST would not be O(log n), but rather would be O(n) time, as we'd have to traverse left linearly,
or traverse right linearly if it is sorted descending. 

3. Researching beyond the module, how would one fix a BST so the worst case scenario matches (or at least i closer to) the average case.[^1^]
There are ways to write 'self-balancing' binary search trees. These self-balancing trees are called AVL trees and Red Black Trees. [^2^]

## Scenario

Fill out the table below. This is a common technical interview topic!

| Structure          | Good to use when                                                                     | Bad to use when                                                                                                  |
| ------------------ |--------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------|
| Vector             | You need access to random indexes, and you insert mostly to the back of the vector   | You often need to do insertions to the front of the vector or even in the middle                                 |
| Linked List        | Good for stacks with frequent front only access                                      | You need to do a lot of searches and often need access to elements that aren't in the front or beginning of the list |
| Sorted Vector      | When values coming in are already mostly sorted and we need quick search access.     | When space is limited and the dataset is extremely large causing memory to swap.                                 |
| Sorted Linked List | You often need to traverse the data set sequentially anyway and rarely do insertions | You need to do a lot of insertions, or if you need to do a lot of searches for certain values                    |
| BST                | Data is not presorted and you need to remove, search, and add elements often         | data is presorted                                                                                                |

## Conclusion

Summarize your findings. Where there any surprises?  What did you end up learning by comparing speeds?

BST performed quite well for adding and removing movies. The sorted vector did slightly outperform BST for searching.
Linked list searching, adding, and removing are costly, but removing or adding to the front is very efficient. 
Vectors are inefficient for adding or removing from the beginning, but efficient for adding to the end, as that doesn't require any shifts, 
just the resizing in a few cases.
Adding to a sorted vector was similar to adding to a linked list in performance, as the occasional resizing of the vector and 
the O(n) shift result in it being only as sufficient in time as the O(n) time that adding to a linked list requires. 
However, removing from a sorted vector was more efficient than removing from a linked list. 
This point did surprise me as technically both these operations are O(n).
I figured it is partly because removing from a sorted vector doesn't include any resizing, 
so removing from a sorted vector performs better than adding to it. 
Another reason, and something else that surprised me, is that the linked list performed worse for removing values rather than adding them.
This does make sense, though, if you consider the SAMPLE_SPLIT being set to 0.7. 
This way, 30% of the time we won't find the value we're trying to remove and will have to linearly traverse the whole list. 
I was reminded that the performance and comparisons on different data structures also depend on how the tests are written. 

## Technical Interview Practice Questions

For both these questions, are you are free to use what you did as the last section on the team activities/answered as a group, or you can use a different question.

1. Select one technical interview question (this module or previous) from the [technical interview list](https://github.com/CS5008-khoury/Resources/blob/main/TechInterviewQuestions.md) below and answer it in a few sentences. You can use any resource you like to answer the question.

Explain LIFO and provide examples of real world applications of LIFO.

LIFO means 'last in first out.' The concept is similar to a stack of plates - you know that the last plate you put on the stack 
will be the first to get popped off. The call stack is based off of LIFO. 
LIFO is useful in programs that have command Z, such as the one I'm using now - Rider. The last change I make is the one that will get undone want to undo.

2. Select one coding question (this module or previous) from the [coding practice repository](https://github.com/CS5008-khoury/Resources/blob/main/LeetCodePractice.md) and include a c file with that code with your submission. Make sure to add comments on what you learned, and if you compared your solution with others. 

I included the file ./bstMaximumDepth.c. I compared my solution to other solutions on leetcode. 
The solutions I saw look a bit differently than mine, as it is possible to solve this without a helper function. 
However, the logic of the solutions are similar. 

I practiced thinking recursively. 

## References

Add your references here. A good reference includes an inline citation, such as [1] , and then down in your references section, you include the full details of the reference. Computer Science research often uses [IEEE] or [ACM Reference format].

harendrakumar123. (2025, September 24). Binary search tree. GeeksforGeeks. https://www.geeksforgeeks.org/dsa/binary-search-tree-data-structure/
Kumar, M. (2025, September 17). Best 12 stack examples in real life in simple explanation. upGrad blog. https://www.upgrad.com/blog/stack-example-in-real-life/

[1] Reference info, date, etc.

[^1^]: Implementing a BST with a self-balancing algorithm, such as AVL or Red-Black Trees is a great research paper topic!

<!-- links moved to bottom for easier reading in plain text (btw, this a comment that doesn't show in the webpage generated-->

[image markdown]: https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax#images

[ACM Reference Format]: https://www.acm.org/publications/authors/reference-formatting
[IEEE]: https://www.ieee.org/content/dam/ieee-org/ieee/web/org/conferences/style_references_manual.pdf
