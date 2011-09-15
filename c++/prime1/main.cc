#include <iostream>
using namespace std;

int size = 31622;
bool* sieve = new bool[size];
int* primes = new int[size];
int prime_size = 0;

void populate_sieve() {
  for(int i=2; i < size; i=i++) {
    if(!sieve[i]) {
      primes[prime_size] = i;
      prime_size++;
      for(int j=i*i; j <= size; j=j+i) {
        sieve[j] = true;
      }
    }
  }
}

void populate_interval(int min, int max) {
   int range = max-min+1;
   bool* interval = new bool[range];
   int current_prime, next_multiple_offset, index, mod, num;

   for(int i=0; i<prime_size; i++) {
      current_prime = primes[i];
      mod = min % current_prime;

      if(!interval[0])
         interval[0] = (mod == 0) && min > current_prime;

      next_multiple_offset = current_prime - mod;
      for(int j=next_multiple_offset;j<range;j+=current_prime){
         interval[j] = min + j > current_prime;
      }
   }

   for(int i=0; i<range;i++) {
      num = min + i;
      if(!interval[i] && num != 1)
         cout << num << "\n";
   }
}

int main () {
  int tests;
  int first, last;
  populate_sieve();
  cin >> tests;

  for(int i=0; i<tests;i++){
    cin >> first >> last;
    populate_interval(first, last);
    cout << "\n";
  }
  return 0;
}