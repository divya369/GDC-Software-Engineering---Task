//
// Created by Divya Patel on 25/12/21.
//

void help() {
    std::cout<<"Usage :-\n";
    std::cout<<"$ ./task add 2 hello world    # Add a new item with priority 2 and text \"hello world\" to the list\n";
    std::cout<<"$ ./task ls                   # Show incomplete priority list items sorted by priority in ascending order\n";
    std::cout<<"$ ./task del INDEX            # Delete the incomplete item with the given index\n";
    std::cout<<"$ ./task done INDEX           # Mark the incomplete item with the given index as complete\n";
    std::cout<<"$ ./task help                 # Show usage\n";
    std::cout<<"$ ./task report               # Statistics";
}