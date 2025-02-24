[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)

addWaypoint to Beginning Method: 
    takes a Type pointer as a parameter
    returns void
    adds a waypoint to the beginning of the space route
    Runtime: O(1)
        uses no loops, code is not reliant on size of list

addWaypoint at End method:
    takes a Type pointer as a parameter
    returns void
    adds a waypoint to the end of the space route
    Runtime: O(1)
        uses no loops, code is not reliant on size of list

addWaypoint at Index Method
    takes a Type pointer and an int variable as a parameter
    returns nothing
    adds a waypoint at the index provided
    Runtime: O(n) 
        dependent on length of space route
        worst case is if the index given is right before the tail (length - 2)

removeWaypoint at Beginning method:
    no parameters
    removes waypoint at the beginning of space route
    returns nothing
    Runtime: O(1)
        uses no loops, code is not reliant on size of the list

removeWaypoint at End method
    no parameters
    removes waypoint at beginning of space route
    returns nothing
    Runtime: O(1)
        uses no loops, code is not reliant on size of the list

removeWaypoint at index method
    takes an int value as a parameter (represents index at which to remove)
    removes waypoint at provided index
    Runtime: O(n)
        dependent on the index given and size of the list (represented by n)
        worst case is if the index is right before the tail (length - 2)

traverseForward method
    no parameters
    prints the list from beginning to end
    Runtime: O(n)
        dependent on size of the list (n)

traverseBackward method
    no parameters
    prints list from end to beginning   
    Runtime: O(n)
        dependent on size of the list (n)

getWaypoint method:
    takes an int variable as a parameter(represents index of interest)
    retrieves a waypoint at a given index 
    returns a Node<T>
    Runtime: O(n)
        dependent on the index given (represented by n)
        worst case is if the index is right before the tail (length - 2)

setWaypoint method:
    takes an int variable as a parameter(represents index to set)
    allows user to assign a value at a specific index 
    returns void
    Runtime: O(n)
        dependent on index given (represented by n)
        worst case is if the index given is right before the tail (length - 2)

print method:
    prints list from beginning to end
    Runtime: O(n)
        dependent on size of the given list 
