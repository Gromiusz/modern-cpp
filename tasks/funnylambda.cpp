#include <iostream>


auto lambda = [c{'a'}, changed = false]() mutable -> char { if(c < ('z'+1) && c > ('Z'+1)) 
                                                                return c++;
                                                            else if(c != ('Z'+1)) {
                                                                if(!changed) {
                                                                    c = 'A';
                                                                    changed = true;
                                                                }
                                                                    return c++; }
                                                            else{
                                                                changed = false;
                                                                return c = 'a'; }
                                                            };
                                                                

int main()
{
    for(int i = 0; i < 80; i++)
    {
        std::cout << lambda() << std::endl;
    }
}