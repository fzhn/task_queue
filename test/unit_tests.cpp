#define CATCH_CONFIG_MAIN
#define UNIT_TESTING

#include "../include/catch.hpp"
#include "../include/task_queue.h"
#include "../src/task_queue.cpp"
#include <memory>


TEST_CASE( "Test c interface", "[struct task_queue]" ) {
    
    struct task_queue tq;
}

TEST_CASE( "Testing TaskQueueClass", "[TaskQueueClass]" ) {
    TaskQueue<int, 10> queue;
    REQUIRE(queue.isLockFree() == true);
    REQUIRE(queue.pop() == 0);

    for (int i = 0; i < 16; i++){
        queue.push(i+1);
    }
    REQUIRE(queue.pop() == 1);
    REQUIRE(queue.pop() == 2);
    queue.push(1);
    queue.push(1);
    REQUIRE_THROWS_AS(queue.push(2), std::runtime_error);

}