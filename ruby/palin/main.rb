def next_palindrome(number)
  if number =~ /^9+$/
    "1"+("0" * (number.size-1))+"1"
  elsif number.size % 2 == 0
    even_palindrome(number)
  else
    odd_palindrome(number)
  end
end

def even_palindrome(number)
  half_number = number.size / 2 - 1
  first_digits = number[0..half_number]
  result = first_digits + first_digits.reverse
  result > number ? result : (first_digits.next! + first_digits.reverse)
end

def odd_palindrome(number)
  half_number = (number.size - 1) / 2 - 1
  first_digits = number[0..half_number]
  middle_digit = number[half_number+1..half_number+1]
  result = first_digits + middle_digit + first_digits.reverse
  if result > number
    result
  elsif middle_digit != "9"
    first_digits + middle_digit.next + first_digits.reverse
  else
    first_digits.next! + "0" + first_digits.reverse
  end
end

tests = gets.chomp.to_i
tests.times do
  puts next_palindrome(gets.chomp)
end
