#include <iostream>
using namespace std;

int square(int n) {
        int sum = 0;
        while(n > 0) {
            int digit = n%10;
            n/= 10;
            sum = sum + (digit*digit);
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        while(fast != 1) {
            slow = square(slow);
            fast = square(square(fast));

            if(slow == fast && fast != 1) {
                return false;
            }
        }
        return true;
    }

int main() {
    int n = 19;
    isHappy(n);
    cout<<(isHappy? "yes, n is a happy number":"no, n is not a happy number");
    return 0;
}