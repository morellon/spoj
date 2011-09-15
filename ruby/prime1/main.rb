def primes_up_to(number)
  srive = Array.new number, true
  i = 2
  while i**2 < number
    if srive[i]
      j = i**2
      while j <= number
        srive[j] = false
        j += i
      end
    end
    i += 1
  end
  srive
end
