#include <iostream>
#include <misc/min.h>

struct cmp {
    int operator()(int a, int b) { return a < b; }
};

int main () {
   int x {3};
   int y {4};
   volatile int z {0};

      for (double i = 1000000000; i-->0; ) z = min( x, y, [] (int x,int y) { return x < y; } );
   std::cout << "min: " << x << ", " << y << ", " << z << std::endl;

   x = 42;
   y = 43;
   // for (double i = 1000000000; i-->0; ) z = min( x, y, cmp() );
   std::cout << "min: " << x << ", " << y << ", " << z << std::endl;

   min( x, y, cmp() ) += 1000;
   std::cout << "min gets 1,000 added: " << x << ", " << y << ", " << std::endl;

   int i = min( 6, 9, [] (int x,int y) { return x < y; } );
   std::cout << "min: " << 6 << ", " << 9 << ", " << i << std::endl;

    return 0;
}
