#pragma once
#include "linked_list.h"
#include <mutex>
#include <iostream>



class Cache{
    private:
        std::mutex block;
        
};