#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "DynamicArray.h"

/*
测试动态数组
*/
void test01_dynamic_array()
{
    // init dynamic array
    DA::Dynamic_Array *my_array = DA::init_dynamic_array();

    // data
    for (int i = 0; i < 30; i++)
    {
        DA::push_back_dynamic_array(my_array, i);
    }

    // print
    DA::print_dynamic_array(my_array);

    // capacity, size
    std::cout << DA::getCapacity_dynamic_array(my_array) << std::endl;
    std::cout << DA::getSize_dynamic_array(my_array) << std::endl;

    // remove
    DA::removeByPos_dynamic_array(my_array, 0);
    DA::print_dynamic_array(my_array);
    DA::removeByVal_dynamic_array(my_array, 27);
    DA::print_dynamic_array(my_array);

    // find
    int pos = DA::find_dynamic_array(my_array, 5);
    std::cout << "find " << DA::at_dynamic_array(my_array, pos) << " at pos " << pos << std::endl;

    // clear
    DA::clear_dynamic_array(my_array);
    DA::print_dynamic_array(my_array);

    // free
    DA::freespace_dynamic_array(my_array);
}

int main()
{
    test01_dynamic_array();
}
