#include <iostream>
#include <math.h>
using namespace std;

int size = 31622;
bool* sieve = new bool[size];
int* primes = new int[size];
int prime_size = 0;

void populate() {
  int i, j;
  for(i=2; i < size; i=i++) {
    if(!sieve[i]) {
      primes[prime_size] = i;
      prime_size++;
      for(j=i*i; j <= size; j=j+i) {
        sieve[j] = true;
      }
    }
  }
}

bool is_prime(int number) {
  if(number < size) {
    return !sieve[number];
  }
  else {
    for(int i=0; i < prime_size; i=i++) {
      if(number % primes[i] == 0)
        return false;
    }
    return true;
  }
}


int main () {
  int tests;
  int first, last;
  populate();
  cin >> tests;

  for(int i=0; i<tests;i++){
    cin >> first >> last;
    for(int j=first; j<=last; j++) {
      if(is_prime(j))
        cout << j << "\n";
    }
    cout << "\n";
  }
  return 0;
}