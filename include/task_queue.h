#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>

#define QUEUE_SIZE (4096)

typedef enum {
  TQ_OK,
  TQ_EMPTY,
  TQ_ERR,
} ct_return;

struct queue_data {
  uint64_t fid;
  void* buf;
};

struct task_queue;

void push_task(struct task_queue** queue);
struct queue_data pop_task(struct task_queue** queue);
