#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/shared_memory_object.hpp>
#include <cstdlib>
#include <cstring>
#include <string>

int main(int argc, char *argv[]) {
    using namespace boost::interprocess;

    // Remove shared memory on construction and destruction
    struct shm_remove {
        shm_remove() { shared_memory_object::remove("MySharedMemory"); }
        ~shm_remove() { shared_memory_object::remove("MySharedMemory"); }
    } remover;

    // Create a shared memory object.
    shared_memory_object shm(create_only, "MySharedMemory", read_write);

    // Set size
    shm.truncate(1000);

    // Map the whole shared memory in this process
    mapped_region region(shm, read_write);

    // Write all the memory to 1
    std::memset(region.get_address(), 1, region.get_size());

    // Launch child process
    std::string s(argv[0]);
    s += " child ";
    if (0 != std::system(s.c_str())) return 1;

    sleep(10);
    return 0;
}