# FOS Operating System Project

A comprehensive operating system implementation featuring core kernel functionality, memory management, process scheduling, and system calls.

## 🚀 Project Overview

This project implements a full-featured operating system with the following major components:

- **Kernel Memory Management** - Dynamic allocation with first-fit algorithms
- **Process Management** - Command processing and system call interface
- **Memory Protection** - Fault handling and page management
- **Shared Memory** - Inter-process communication mechanisms
- **User Space** - Heap management and memory allocation
- **Concurrency** - Semaphores and process synchronization
- **Scheduling** - Priority-based round-robin scheduler

## 📋 Features

### Core System Components

#### Memory Management
- **Dynamic Allocator**
  - Block allocation with first-fit algorithm
  - Memory reallocation and deallocation
  - Kernel heap management with virtual/physical address translation
  - Fast page allocator for performance optimization

#### System Interface
- **Command Processing** - Interactive command prompt
- **System Calls** - Complete syscall interface with parameter validation
- **Sleep/Wakeup Mechanisms** - Process synchronization primitives

#### Memory Protection
- **Fault Handler** - Invalid pointer detection and page fault handling
- **Process Isolation** - Kernel dynamic allocation for process management

#### Shared Memory
- **Object Management** - Creation, search, and deletion of shared objects
- **Memory Allocation** - First-fit allocation for shared resources
- **Cross-Process Communication** - Safe memory sharing between processes

#### User Space
- **Heap Management** - User-level memory allocation
- **System Integration** - Seamless kernel-user space interaction

#### Concurrency
- **Semaphores** - Complete semaphore implementation
- **Process Synchronization** - Wait/signal operations

#### Scheduling
- **Priority Scheduler** - Multi-level priority management
- **Round-Robin Algorithm** - Fair CPU time distribution
- **Timer Integration** - Preemptive scheduling support

### Advanced Features
- **Fault Handler II** - Enhanced fault detection with clock replacement algorithm
- **Performance Optimization** - Fast allocators and efficient data structures
- **Comprehensive Testing** - Extensive test suite with automated validation

## 🛠️ Technical Implementation

### File Structure
```
kern/
├── mem/
│   ├── kheap.c/.h          # Kernel heap management
│   ├── shared_memory_manager.c  # Shared memory implementation
│   └── chunk_operations.c   # Memory chunk operations
├── trap/
│   ├── fault_handler.c     # Page fault handling
│   ├── trap.c              # Trap handling
│   └── syscall.c/.h        # System call interface
├── sched/
│   └── sched.c             # Process scheduler
├── cpu/
│   └── sched_helpers.c     # Scheduling utilities
├── cmd/
│   ├── commands.c          # Command processing
│   └── command_prompt.c    # Interactive shell
├── conc/
│   ├── channel.c           # Communication channels
│   └── sleeplock.c         # Sleep locks
├── proc/
│   ├── user_environment.c  # Process environment
│   └── working_set_manager.c # Memory working set
└── tests/
    └── test_dynamic_allocator.c # Comprehensive testing
```

### User Space Libraries
```
lib/
├── uheap.c                 # User heap implementation
├── semaphore.c             # Semaphore library
├── syscall.c               # System call wrappers
└── dynamic_allocator.c     # Dynamic memory allocation
```

## 🧪 Testing

The project includes comprehensive testing with multiple difficulty levels:

- **Automated Testing**: Each module includes automated test scenarios
- **Integration Tests**: Cross-module functionality validation  
- **Performance Tests**: Timing and efficiency benchmarks
- **Stress Tests**: High-load and edge case validation

### Test Categories
- **SEEN Tests**: Pre-validated test cases
- **UNSEEN Tests**: Hidden test scenarios for comprehensive evaluation
- **Performance Benchmarks**: Speed and efficiency measurements

## 📊 Project Status

- **Total Functions Implemented**: 21
- **Success Rate**: All tests passing with congratulations message
- **Performance**: Optimized for speed and memory efficiency
- **Stability**: No error messages or panics in testing

## 📈 Performance Metrics

- **Fast Page Allocator**: Sub-5 second execution time
- **Memory Efficiency**: Optimized first-fit algorithms
- **Scheduling Latency**: Low-latency process switching
- **System Call Overhead**: Minimal kernel-user transitions

## Collaborators
- [Yahia Aldeeb](https://github.com/YahiaAldeeb)
- [Hana Omar](https://github.com/HanaOmar1)
- [Abdelrahman Maamoun](https://github.com/amaamoun99)
- [Manar Sayed](https://github.com/Manarsayedd)
- [Yasmeen Ahmed](https://github.com/yassmeenahmedd)
- [Farida Ali](https://github.com/farridaali)

## 🤝 Contributing

This project demonstrates advanced operating system concepts and implementations. The modular design allows for easy extension and modification of individual components.

## 📄 License

This project is part of an academic operating systems course and follows educational use guidelines.

---

**Note**: This operating system is designed for educational purposes and demonstrates core OS concepts including memory management, process scheduling, system calls, and inter-process communication.
