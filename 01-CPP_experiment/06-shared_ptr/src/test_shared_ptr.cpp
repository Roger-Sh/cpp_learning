#include <cassert>
#include <iostream>
#include <memory>

std::shared_ptr<int> sptr;

void test01() {
    // 没有分配内存前，引用数为0
    std::cout << "sptr.use_count(): " << sptr.use_count() << std::endl;

    sptr = std::make_shared<int>(200);

    // 此时引用计数为 1
    assert(sptr.use_count() == 1);  
    std::cout << "sptr.use_count(): " << sptr.use_count() << std::endl;

    // local code block
    {
        // sptr 和 sptr1 共享资源，引用计数为 2
        std::shared_ptr<int> sptr1 = sptr;
        assert(sptr.get() == sptr1.get());
        assert(sptr.use_count() == 2);  
        std::cout << "sptr.use_count(): " << sptr.use_count() << std::endl;
        std::cout << "sptr1.use_count(): " << sptr1.use_count() << std::endl;

        // sptr 和 sptr1, sptr2 共享资源，引用计数为 3
        std::shared_ptr<int> sptr2 = sptr1;
        assert(sptr.get() == sptr2.get());
        assert(sptr.use_count() == 3);  
        std::cout << "sptr.use_count(): " << sptr.use_count() << std::endl;
        std::cout << "sptr1.use_count(): " << sptr1.use_count() << std::endl;
        std::cout << "sptr2.use_count(): " << sptr2.use_count() << std::endl;
    }

    // sptr1, sptr2 已经释放
    // assert(sptr.use_count() == 2);  
    std::cout << "sptr.use_count(): " << sptr.use_count() << std::endl;


}

int main(int argc, char const *argv[]) {
    test01();
    std::cout << "sptr.use_count(): " << sptr.use_count() << std::endl;

    return 0;
}
